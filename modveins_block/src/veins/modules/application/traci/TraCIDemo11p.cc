//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
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

#include "veins/modules/application/traci/TraCIDemo11p.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"

using namespace veins;

Define_Module(veins::TraCIDemo11p);

void TraCIDemo11p::initialize(int stage)
{
    //std::cout<<"Inside traci demo11"<<stage<<endl;
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        sentMessage = false;
        lastDroveAt = simTime();
        currentSubscribedServiceId = -1;
    }
    //std::cout<<"Executed this 1";
    //blockchain blo(
      //              grpc::CreateChannel("0.0.0.0:50052",grpc::InsecureChannelCredentials()));

    //PID_List p;
    //std::cout<<p.PID;
    //std::string pid = to_string(pPID);
    //static int i;
    //DemoSafetyMessage* bsm;
    //if(i>3)
    //bsm->getSenderPK();
    //i++;
    //DemoServiceAdvertisment *wsa;
    //std::cout<<wsa->getValidPID();
    //cryp cd = bsm->getSenderPK();
    //std::string pke = std::to_string(cd);
    //std::string a = "ab";//      std::string b = "bc";//    std::string c = "cd"; //  std::string d = "de";
    //blo.reg_vehicle("kuch bhi", "hey maa", "DemoPk", "Good");

}

void TraCIDemo11p::onWSA(DemoServiceAdvertisment* wsa)
{
    /*if (currentSubscribedServiceId == -1) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
        currentSubscribedServiceId = wsa->getPsid();
        if (currentOfferedServiceId != wsa->getPsid()) {
            stopService();
            startService(static_cast<Channel>(wsa->getTargetChannel()), wsa->getPsid(), "Mirrored Traffic Service");
        }
    }*/
    int pnm = wsa->getValidPID();
    std::string pubKey = wsa->getValidPK();
    this->cancelEvent(wsa);
    //std::cout<<"Cancelled the WSA Event."<<std::endl;
    for(std::vector<PID_List>::iterator i = valid_PID.begin() ; i != valid_PID.end(); ++i){
        if(i->PID == pnm){
            return;
        }
    }
    valid_PID.push_back({pnm, pubKey, system_clock::to_time_t(system_clock::now())});
}

void TraCIDemo11p::onBSM(DemoSafetyMessage* bsm) {
    //Your application has received a beacon message from another car or RSU
    //code for handling the message goes here]
    std::clock_t start;
    double duration;
    start = std::clock();
    CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PublicKey publicKey = bsm->getSenderPK();
    const CryptoPP::ECP::Point& q = publicKey.GetPublicElement();
    const CryptoPP::Integer& qx = q.x;
    const CryptoPP::Integer& qy = q.y;
    std::stringstream ss ;
    ss<<std::hex<<q.x<<q.y;
    std::string pk = ss.str();
    //std::cout<<pk<<endl;
    //DemoServiceAdvertisment *wsa;
    //std::cout<<wsa->getValidPID();
    //std::cout<<valid_PID.size()<<endl;
    for(std::vector<PID_List>::iterator i = valid_PID.begin() ; i != valid_PID.end(); ++i){
        //std::cout<<"Executing BSM";
        //PID_List p;
        //int q = p.PID;
        //std::cout<<"PID -->"<<q;
        if((system_clock::to_time_t(system_clock::now()) - i->expiry) > 60)
        {
            valid_PID.erase(i);
            std::cout<<"Expired and deleted"<<std::endl;
        }
    }

    for(std::vector<PID_List>::iterator it = valid_PID.begin() ; it != valid_PID.end(); ++it){
        //std::cout<<"Executing BSM";
        if(it->PID == bsm->getSenderAddress() && it->pkey == pk){
            //std::cout<<"valid bsm"<<std::endl;
            goto end;
        }
    }
    //std::cout<<"Ecuu";
    if(this->isChannelIdle()){
        this->mac->setChannelIdle(false);
        //std::cout<<"Inside is channel idle";
        bool bar = this->verifyPID(bsm->getSenderAddress(), pk);
        //std::cout<<bar<<endl;
        if(bar){
            //std::cout<<"Pushing values in validppid";
            valid_PID.push_back({bsm->getSenderAddress(), pk, system_clock::to_time_t(system_clock::now())});
            //std::vector<PID_List>::iterator iko = valid_PID.end();
            //std::cout<<iko->PID<<iko->pkey;
           //std::cout<<"Channel is not congested"<<std::endl;
        }
        this->mac->setChannelIdle(true);
    }
    else {
        scheduleAt(simTime()+dblrand()*0.1, bsm);
        //std::cout<<"Channel is congested, waiting for sometime"<<std::endl;
        this->handleSelfMsg(bsm);
        cancelEvent(bsm);
        //std::cout<<"Channel is congested, waited for sometime"<<std::endl;
    }
    end:
    if(this->verifyPKSignature(bsm)) {
    }
    duration = (std::clock()-start)/(double)CLOCKS_PER_SEC*1000;
    fstream bsmfile;
    bsmfile.open("/home/aditya/durafile.txt", ios::app);
    totalDuration += duration;
    bsmfile<<duration<<endl;
    bsmfile.close();
   bsmfile.open("/home/aditya/bsmfile.txt", ios::app);
    bsmfile<<totalBSMs++<<endl;
    //totalBSMs++;
    bsmfile.close();
    //static int i;
    //std::cout<<++i<<std::endl;
    std::cout<<"total bs, -->"<<totalBSMs<<endl;
}

void TraCIDemo11p::onWSM(BaseFrame1609_4* frame)
{
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);

    findHost()->getDisplayString().setTagArg("i", 1, "green");

    if (mobility->getRoadId()[0] != ':') traciVehicle->changeRoute(wsm->getDemoData(), 9999);
    if (!sentMessage) {
        sentMessage = true;
        // repeat the received traffic update once in 2 seconds plus some random delay
        wsm->setSenderAddress(myId);
        wsm->setSerial(3);
        scheduleAt(simTime() + 2 + uniform(0.01, 0.2), wsm->dup());
    }
}

void TraCIDemo11p::handleSelfMsg(cMessage* msg)
{
    if(DemoSafetyMessage* bsm = dynamic_cast<DemoSafetyMessage*>(msg))
    if(bsm->isSelfMessage()){
        const ECP::Point& q = bsm->getSenderPK().GetPublicElement();
        const CryptoPP::Integer& qx = q.x;
        const CryptoPP::Integer& qy = q.y;

        std::stringstream ss ;
        ss<<std::hex<<q.x<<q.y;
        std::string pk = ss.str();
        if(this->verifyPID(bsm->getSenderAddress(), pk)) {
            valid_PID.push_back({bsm->getSenderAddress(), pk, system_clock::to_time_t(system_clock::now())});
            //std::cout<<"Handle Self Msg called and verified PID"<<std::endl;
        }
        if(this->verifyPKSignature(bsm)) {
            //std::cout<<"Verified Message Signature"<<std::endl;
        }
        cancelEvent(bsm);
    }
    if (TraCIDemo11pMessage* wsm = dynamic_cast<TraCIDemo11pMessage*>(msg)) {
        // send this message on the service channel until the counter is 3 or higher.
        // this code only runs when channel switching is enabled
        sendDown(wsm->dup());
        wsm->setSerial(wsm->getSerial() + 1);
        if (wsm->getSerial() >= 3) {
            // stop service advertisements
            stopService();
            delete (wsm);
        }
        else {
            scheduleAt(simTime() + 1, wsm);
        }
    }
    else {
        DemoBaseApplLayer::handleSelfMsg(msg);
    }
}

void TraCIDemo11p::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);

    // stopped for for at least 10s?
    if (mobility->getSpeed() < 1) {
        if (simTime() - lastDroveAt >= 10 && sentMessage == false) {
            findHost()->getDisplayString().setTagArg("i", 1, "red");
            sentMessage = true;

            TraCIDemo11pMessage* wsm = new TraCIDemo11pMessage();
            populateWSM(wsm);
            wsm->setDemoData(mobility->getRoadId().c_str());

            // host is standing still due to crash
            if (dataOnSch) {
                startService(Channel::sch2, 42, "Traffic Information Service");
                // started service and server advertising, schedule message to self to send later
                scheduleAt(computeAsynchronousSendingTime(1, ChannelType::service), wsm);
            }
            else {
                // send right away on CCH, because channel switching is disabled
                sendDown(wsm);
            }
        }
    }
    else {
        lastDroveAt = simTime();
    }
}
void TraCIDemo11p::finish(){
    DemoBaseApplLayer::finish();
    DemoBaseApplLayer::printStat();
    printValues();
}
