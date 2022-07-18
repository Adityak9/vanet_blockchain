//
// Copyright (C) 2011 David Eckhoff <eckhoff@cs.fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"

int veins::DemoBaseApplLayer::counter = 1;
int veins::DemoBaseApplLayer::startPSID = 21000000;
double veins::DemoBaseApplLayer::totalDuration = 0.0;
int veins::DemoBaseApplLayer::totalBSMs = 0;

using namespace veins;

void DemoBaseApplLayer::initialize(int stage)
{
    //std::cout<<"Inside Demo Appl Layer"<<stage<<endl;
    BaseApplLayer::initialize(stage);

    if (stage == 0) {

        // initialize pointers to other modules
        if (FindModule<TraCIMobility*>::findSubModule(getParentModule())) {
            mobility = TraCIMobilityAccess().get(getParentModule());
            traci = mobility->getCommandInterface();
            traciVehicle = mobility->getVehicleCommandInterface();
        }
        else {
            traci = nullptr;
            mobility = nullptr;
            traciVehicle = nullptr;
        }

        annotations = AnnotationManagerAccess().getIfExists();
        ASSERT(annotations);

        /*mac = FindModule<DemoBaseApplLayerToMac1609_4Interface*>::findSubModule(getParentModule());
        ASSERT(mac);*/

        mac = FindModule<Mac1609_4*>::findSubModule(
            getParentModule());
        assert(mac);

        myId = ++startPSID;//getParentModule()->getId();

        //set PK and SK for each vehicle
        CryptoPP::AutoSeededRandomPool prng;
        int i = counter++;
        do{
        //std::cout<<"counter is: "<<i<<std::endl;
        skey = skeyV.at(i);
        pkey = pkeyV.at(i);
        }while(false);


        // read parameters
        headerLength = par("headerLength");
        sendBeacons = par("sendBeacons").boolValue();
        beaconLengthBits = par("beaconLengthBits");
        beaconUserPriority = par("beaconUserPriority");
        beaconInterval = par("beaconInterval");

        dataLengthBits = par("dataLengthBits");
        dataOnSch = par("dataOnSch").boolValue();
        dataUserPriority = par("dataUserPriority");

        wsaInterval = par("wsaInterval").doubleValue();
        currentOfferedServiceId = -1;

        isParked = false;

        findHost()->subscribe(BaseMobility::mobilityStateChangedSignal, this);
        findHost()->subscribe(TraCIMobility::parkingStateChangedSignal, this);

        sendBeaconEvt = new cMessage("beacon evt", SEND_BEACON_EVT);
        sendWSAEvt = new cMessage("wsa evt", SEND_WSA_EVT);

        generatedBSMs = 0;
        generatedWSAs = 0;
        generatedWSMs = 0;
        receivedBSMs = 0;
        receivedWSAs = 0;
        receivedWSMs = 0;
    }
    else if (stage == 1) {

        // store MAC address for quick access
        //myId = mac->getMACAddress();

        // simulate asynchronous channel access

        if (dataOnSch == true && !mac->isChannelSwitchingActive()) {
            dataOnSch = false;
            EV_ERROR << "App wants to send data on SCH but MAC doesn't use any SCH. Sending all data on CCH" << std::endl;
        }
        simtime_t firstBeacon = simTime();

        if (par("avoidBeaconSynchronization").boolValue() == true) {

            simtime_t randomOffset = dblrand() * beaconInterval;
            firstBeacon = simTime() + randomOffset;

            if (mac->isChannelSwitchingActive() == true) {
                if (beaconInterval.raw() % (mac->getSwitchingInterval().raw() * 2)) {
                    EV_ERROR << "The beacon interval (" << beaconInterval << ") is smaller than or not a multiple of  one synchronization interval (" << 2 * mac->getSwitchingInterval() << "). This means that beacons are generated during SCH intervals" << std::endl;
                }
                firstBeacon = computeAsynchronousSendingTime(beaconInterval, ChannelType::control);
            }

            if (sendBeacons) {
                scheduleAt(firstBeacon, sendBeaconEvt);
            }
        }
    }
}

simtime_t DemoBaseApplLayer::computeAsynchronousSendingTime(simtime_t interval, ChannelType chan)
{

    /*
     * avoid that periodic messages for one channel type are scheduled in the other channel interval
     * when alternate access is enabled in the MAC
     */

    simtime_t randomOffset = dblrand() * interval;
    simtime_t firstEvent;
    simtime_t switchingInterval = mac->getSwitchingInterval(); // usually 0.050s
    simtime_t nextCCH;

    /*
     * start event earliest in next CCH (or SCH) interval. For alignment, first find the next CCH interval
     * To find out next CCH, go back to start of current interval and add two or one intervals
     * depending on type of current interval
     */

    if (mac->isCurrentChannelCCH()) {
        nextCCH = simTime() - SimTime().setRaw(simTime().raw() % switchingInterval.raw()) + switchingInterval * 2;
    }
    else {
        nextCCH = simTime() - SimTime().setRaw(simTime().raw() % switchingInterval.raw()) + switchingInterval;
    }

    firstEvent = nextCCH + randomOffset;

    // check if firstEvent lies within the correct interval and, if not, move to previous interval

    if (firstEvent.raw() % (2 * switchingInterval.raw()) > switchingInterval.raw()) {
        // firstEvent is within a sch interval
        if (chan == ChannelType::control) firstEvent -= switchingInterval;
    }
    else {
        // firstEvent is within a cch interval, so adjust for SCH messages
        if (chan == ChannelType::service) firstEvent += switchingInterval;
    }

    return firstEvent;
}

void DemoBaseApplLayer::populateWSM(BaseFrame1609_4* wsm, LAddress::L2Type rcvId, int serial)
{
    wsm->setRecipientAddress(rcvId);
    wsm->setSenderAddress(myId);
    //wsm->setSerial(serial);
    wsm->setBitLength(headerLength);

    if (DemoSafetyMessage* bsm = dynamic_cast<DemoSafetyMessage*>(wsm)) {
        bsm->setSenderPos(curPosition);
        bsm->setSenderSpeed(curSpeed);
        bsm->setPsid(-1);
        bsm->setChannelNumber(static_cast<int>(Channel::cch));
        bsm->addBitLength(beaconLengthBits);
        //std::cout<<"Setting Public Key"<<endl;
        bsm->setSenderPK(pkey);
        std::cout<<"Size of PublicKey -->"<<sizeof(pkey)<<endl;
        //CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PublicKey publicKey = bsm->getSenderPK();
        //const CryptoPP::ECP::Point& q = publicKey.GetPublicElement();
        //const CryptoPP::Integer& qx = q.x;
        //const CryptoPP::Integer& qy = q.y;
        //std::stringstream ss ;
        //ss<<std::hex<<q.x<<q.y;
        //std::string pk = ss.str();
        //std::cout<<pk<<endl;*/
        //const std::vector<string> veins::DemoBaseApplLayer::pkvii = {"Dummy"};
        //static std::vector<string> pkv = {"Dummy"};
        //pkvii.push_back("Dummy");
        //blockchain blo(
        /*        grpc::CreateChannel("0.0.0.0:50052",grpc::InsecureChannelCredentials()));
        int flag = 0;
        //std::cout<<"Array";
        int k=0;
        for(std::vector<string>::iterator i = pkv.begin(); i != pkv.end(); ++i){
            if(pk != *i)
                flag = 1;
            else{
                flag = 0;
                break;}
            k++;
            //std::cout<<k<<"KEy is"<<*i<<endl;

        }
        if (flag == 1)
        {
            //std::cout<<endl<<getParentModule()->getId()<<endl;
            pkv.push_back(pk);
            blo.reg_vehicle(to_string(getParentModule()->getId()), to_string(this->myId), pk , "Good");

        }*/
        wsm->setUserPriority(beaconUserPriority);

        AutoSeededRandomPool prng;
        CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::Signer signer(skey);
        CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::Verifier verifier(pkey);
        size_t siglen = signer.MaxSignatureLength();
        std::string msg = bsm->getWsmData();
        std::string timestamp = bsm->getTimestamp().str();
        msg.append(timestamp);
        std::string signature(siglen, 0x00);
        siglen = signer.SignMessage( prng, (const byte*)&msg[0], msg.size(), (byte*)&signature[0] );
        signature.resize(siglen);
        bsm->setMsgSignature(signature);
        std::cout<<"Size of MsgSignature -->"<<sizeof(pkey)<<endl;
    }
    else if (DemoServiceAdvertisment* wsa = dynamic_cast<DemoServiceAdvertisment*>(wsm)) {
        wsa->setChannelNumber(static_cast<int>(Channel::cch));
        wsa->setTargetChannel(static_cast<int>(currentServiceChannel));
        wsa->setPsid(currentOfferedServiceId);
        wsa->setServiceDescription(currentServiceDescription.c_str());
        wsa->setValidPID(this->myId);
    }
    else {
        if (dataOnSch)
            wsm->setChannelNumber(static_cast<int>(Channel::sch1)); // will be rewritten at Mac1609_4 to actual Service Channel. This is just so no controlInfo is needed
        else
            wsm->setChannelNumber(static_cast<int>(Channel::cch));
        wsm->addBitLength(dataLengthBits);
        wsm->setUserPriority(dataUserPriority);
    }
}

void DemoBaseApplLayer::receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj, cObject* details)
{
    Enter_Method_Silent();
    if (signalID == BaseMobility::mobilityStateChangedSignal) {
        handlePositionUpdate(obj);
    }
    else if (signalID == TraCIMobility::parkingStateChangedSignal) {
        handleParkingUpdate(obj);
    }
}

/*std::string blockchain::reg_vehicle(const std::string& vin,
                                    const std::string& pid,
                                    const std::string& pk,
                                    const std::string& status)
{
    block_data request;
    request.set_pid(pid);
    request.set_pk(pk);
    request.set_vin(vin);
    request.set_status(status);
    ClientContext context;
    response resp;
    grpc::Status statuss = stub_->reg_vehicle(&context, request, &resp);
    if (!statuss.ok()) {
        //std::cout<<"call unsuccessfull";
        return "unsuccessfull";
    }
    return "successfull";
}*/

void DemoBaseApplLayer::handlePositionUpdate(cObject* obj)
{
    ChannelMobilityPtrType const mobility = check_and_cast<ChannelMobilityPtrType>(obj);
    curPosition = mobility->getPositionAt(simTime());
    curSpeed = mobility->getCurrentSpeed();
}

void DemoBaseApplLayer::handleParkingUpdate(cObject* obj)
{
    isParked = mobility->getParkingState();
}

void DemoBaseApplLayer::handleLowerMsg(cMessage* msg)
{

    BaseFrame1609_4* wsm = dynamic_cast<BaseFrame1609_4*>(msg);
    ASSERT(wsm);

    if (DemoSafetyMessage* bsm = dynamic_cast<DemoSafetyMessage*>(wsm)) {
        receivedBSMs++;
        onBSM(bsm);
    }
    else if (DemoServiceAdvertisment* wsa = dynamic_cast<DemoServiceAdvertisment*>(wsm)) {
        receivedWSAs++;
        onWSA(wsa);
    }
    else {
        receivedWSMs++;
        onWSM(wsm);
    }

    delete (msg);
}

void DemoBaseApplLayer::handleSelfMsg(cMessage* msg)
{
    switch (msg->getKind()) {
    case SEND_BEACON_EVT: {
        DemoSafetyMessage* bsm = new DemoSafetyMessage();
        populateWSM(bsm);
        sendDown(bsm);
        scheduleAt(simTime() + beaconInterval, sendBeaconEvt);
        break;
    }
    case SEND_WSA_EVT: {
        DemoServiceAdvertisment* wsa = new DemoServiceAdvertisment();
        populateWSM(wsa);
        sendDown(wsa);
        scheduleAt(simTime() + wsaInterval, sendWSAEvt);
        break;
    }
    default: {
        if (msg) EV_WARN << "APP: Error: Got Self Message of unknown kind! Name: " << msg->getName() << endl;
        break;
    }
    }
}

void DemoBaseApplLayer::finish()
{
    recordScalar("generatedWSMs", generatedWSMs);
    recordScalar("receivedWSMs", receivedWSMs);

    recordScalar("generatedBSMs", generatedBSMs);
    recordScalar("receivedBSMs", receivedBSMs);

    recordScalar("generatedWSAs", generatedWSAs);
    recordScalar("receivedWSAs", receivedWSAs);
}

DemoBaseApplLayer::~DemoBaseApplLayer()
{
    cancelAndDelete(sendBeaconEvt);
    cancelAndDelete(sendWSAEvt);
    findHost()->unsubscribe(BaseMobility::mobilityStateChangedSignal, this);
}

void DemoBaseApplLayer::startService(Channel channel, int serviceId, std::string serviceDescription)
{
    if (sendWSAEvt->isScheduled()) {
        throw cRuntimeError("Starting service although another service was already started");
    }

    mac->changeServiceChannel(channel);
    currentOfferedServiceId = serviceId;
    currentServiceChannel = channel;
    currentServiceDescription = serviceDescription;

    simtime_t wsaTime = computeAsynchronousSendingTime(wsaInterval, ChannelType::control);
    scheduleAt(wsaTime, sendWSAEvt);
}

void DemoBaseApplLayer::stopService()
{
    cancelEvent(sendWSAEvt);
    currentOfferedServiceId = -1;
}

void DemoBaseApplLayer::sendDown(cMessage* msg)
{
    checkAndTrackPacket(msg);
    BaseApplLayer::sendDown(msg);
}

void DemoBaseApplLayer::sendDelayedDown(cMessage* msg, simtime_t delay)
{
    checkAndTrackPacket(msg);
    BaseApplLayer::sendDelayedDown(msg, delay);
}

void DemoBaseApplLayer::checkAndTrackPacket(cMessage* msg)
{
    if (dynamic_cast<DemoSafetyMessage*>(msg)) {
        EV_TRACE << "sending down a BSM" << std::endl;
        generatedBSMs++;
    }
    else if (dynamic_cast<DemoServiceAdvertisment*>(msg)) {
        EV_TRACE << "sending down a WSA" << std::endl;
        generatedWSAs++;
    }
    else if (dynamic_cast<BaseFrame1609_4*>(msg)) {
        EV_TRACE << "sending down a wsm" << std::endl;
        generatedWSMs++;
    }
}

bool DemoBaseApplLayer::verifyPKSignature(DemoSafetyMessage* bsm) {
    //std::cout<<"Verifying PK signature";
    //std::clock_t start;
    //double duration;
    //start = std::clock();
    CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PublicKey publicKey = bsm->getSenderPK();
    CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::Verifier verifier(publicKey);
    std::string msg = bsm->getWsmData();
    std::string timestamp = bsm->getTimestamp().str();
    msg = msg.append(timestamp);
    bool result = verifier.VerifyMessage( (const byte*)&msg[0], msg.size(), (const byte*)&bsm->getMsgSignature()[0], bsm->getMsgSignature().size() );
    //duration = (std::clock()-start)/(double)CLOCKS_PER_SEC*1000;
    //fstream bsmfile;
    //bsmfile.open("/home/aditya/durafile.txt", ios::app);
    //bsmfile<<duration<<endl;
    //totalDuration += duration;
    //totalBSMs++;
    return result;
}

void DemoBaseApplLayer::printStat(){
    //static int i;
    //++i;
    //std::cout<<"print channel stat called";
    std::cout<<"Total Duration is: "<<totalDuration<<std::endl;
    std::cout<<"Total BSMs are: "<<totalBSMs<<std::endl;
}

bool DemoBaseApplLayer::isChannelIdle() {
    return mac->isChannelIdle();
}
