//
// Copyright (C) 2016 David Eckhoff <eckhoff@cs.fau.de>
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

#pragma once

#include <map>

#include "veins/base/modules/BaseApplLayer.h"
#include "veins/modules/utility/Consts80211p.h"
#include "veins/modules/messages/BaseFrame1609_4_m.h"
#include "veins/modules/messages/DemoServiceAdvertisement_m.h"
#include "veins/modules/messages/DemoSafetyMessage_m.h"
#include "veins/base/connectionManager/ChannelAccess.h"
#include "veins/modules/mac/ieee80211p/DemoBaseApplLayerToMac1609_4Interface.h"
#include "veins/modules/mobility/traci/TraCIMobility.h"
#include "veins/modules/mobility/traci/TraCICommandInterface.h"
#include "veins/modules/mac/ieee80211p/Mac1609_4.h"

#include "/usr/include/crypto++/eccrypto.h"
#include "/usr/include/crypto++/osrng.h"
#include "/usr/include/crypto++/oids.h"
#include "/usr/include/crypto++/files.h"
#include "/usr/include/crypto++/hex.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "../proto/vanet_block.grpc.pb.h"
#include "../proto/vanet_block.pb.h"
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using vanet_block::block_data;
using vanet_block::response;
using vanet_block::BlockchainVanet;
using vanet_block::psuedoid;

using namespace std::chrono;

using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::AutoSeededRandomPool;
using namespace std;

namespace veins {

using veins::AnnotationManager;
using veins::AnnotationManagerAccess;
using veins::TraCICommandInterface;
using veins::TraCIMobility;
using veins::TraCIMobilityAccess;

/**
 * @brief
 * Demo application layer base class.
 *
 * @author David Eckhoff
 *
 * @ingroup applLayer
 *
 * @see DemoBaseApplLayer
 * @see Mac1609_4
 * @see PhyLayer80211p
 * @see Decider80211p
 */
class blockchain {
public:
    blockchain(std::shared_ptr<grpc::Channel> channel) : stub_(BlockchainVanet::NewStub(channel)) {}
    /*std::string reg_vehicle(const std::string& vin,
                           const std::string& pid,
                           const std::string& pk,
                           const std::string& status);*/
    vanet_block::block_data queryBlock(const std::string pnm);
private:
  std::unique_ptr<BlockchainVanet::Stub> stub_;
};

class VEINS_API DemoBaseApplLayer : public BaseApplLayer {

public:
    ~DemoBaseApplLayer() override;
    void initialize(int stage) override;
    void finish() override;

    void receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj, cObject* details) override;

    enum DemoApplMessageKinds {
        SEND_BEACON_EVT,
        SEND_WSA_EVT
    };

protected:
    /** @brief handle messages from below and calls the onWSM, onBSM, and onWSA functions accordingly */
    void handleLowerMsg(cMessage* msg) override;

    /** @brief handle self messages */
    void handleSelfMsg(cMessage* msg) override;

    /** @brief sets all the necessary fields in the WSM, BSM, or WSA. */
    virtual void populateWSM(BaseFrame1609_4* wsm, LAddress::L2Type rcvId = LAddress::L2BROADCAST(), int serial = 0);

    /** @brief this function is called upon receiving a BaseFrame1609_4 */
    virtual void onWSM(BaseFrame1609_4* wsm){};

    /** @brief this function is called upon receiving a DemoSafetyMessage, also referred to as a beacon  */
    virtual void onBSM(DemoSafetyMessage* bsm){};

    /** @brief this function is called upon receiving a DemoServiceAdvertisement */
    virtual void onWSA(DemoServiceAdvertisment* wsa){};

    /** @brief this function is called every time the vehicle receives a position update signal */
    virtual void handlePositionUpdate(cObject* obj);

    /** @brief this function is called every time the vehicle parks or starts moving again */
    virtual void handleParkingUpdate(cObject* obj);

    /** @brief This will start the periodic advertising of the new service on the CCH
     *
     *  @param channel the channel on which the service is provided
     *  @param serviceId a service ID to be used with the service
     *  @param serviceDescription a literal description of the service
     */
    virtual void startService(Channel channel, int serviceId, std::string serviceDescription);

    /** @brief stopping the service and advertising for it */
    virtual void stopService();

    /** @brief compute a point in time that is guaranteed to be in the correct channel interval plus a random offset
     *
     * @param interval the interval length of the periodic message
     * @param chantype the type of channel, either type_CCH or type_SCH
     */
    virtual simtime_t computeAsynchronousSendingTime(simtime_t interval, ChannelType chantype);

    /**
     * @brief overloaded for error handling and stats recording purposes
     *
     * @param msg the message to be sent. Must be a WSM/BSM/WSA
     */
    virtual void sendDown(cMessage* msg);

    /**
     * @brief overloaded for error handling and stats recording purposes
     *
     * @param msg the message to be sent. Must be a WSM/BSM/WSA
     * @param delay the delay for the message
     */
    virtual void sendDelayedDown(cMessage* msg, simtime_t delay);

    /**
     * @brief helper function for error handling and stats recording purposes
     *
     * @param msg the message to be checked and tracked
     */
    virtual void checkAndTrackPacket(cMessage* msg);

protected:
    /* pointers ill be set when used with TraCIMobility */
    TraCIMobility* mobility;
    TraCICommandInterface* traci;
    TraCICommandInterface::Vehicle* traciVehicle;

    AnnotationManager* annotations;
    //DemoBaseApplLayerToMac1609_4Interface* mac;
    Mac1609_4* mac;

    /* support for parking currently only works with TraCI */
    bool isParked;

    /* BSM (beacon) settings */
    uint32_t beaconLengthBits;
    uint32_t beaconUserPriority;
    simtime_t beaconInterval;
    bool sendBeacons;

    /* WSM (data) settings */
    uint32_t dataLengthBits;
    uint32_t dataUserPriority;
    bool dataOnSch;

    /* WSA settings */
    int currentOfferedServiceId;
    std::string currentServiceDescription;
    Channel currentServiceChannel;
    simtime_t wsaInterval;

    /* state of the vehicle */
    Coord curPosition;
    Coord curSpeed;
    LAddress::L2Type myId = 0;
    int mySCH;
    AutoSeededRandomPool prng;
    CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PrivateKey skey;
    CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PublicKey pkey;
    std::vector<CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PrivateKey> skeyV;
    std::vector<CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PublicKey> pkeyV;
    static int counter;
    static int startPSID;
    struct PID_List{
        LAddress::L2Type PID;
        std::string pkey;
        time_t expiry;
    };
    std::vector<PID_List> valid_PID;


    //std::string buffer;
    //std::vector<string> veins::DemoBaseApplLayer::pkvii;
    DemoBaseApplLayer(){
        ///*CryptoPP::FileSink fs( "/home/aditya/private.ec.der", true /*binary*/ );
        //CryptoPP::FileSink fp( "/home/aditya/public.ec.der", true /*binary*/ );
        /*for (int i=0; i<55;i++){
        AutoSeededRandomPool prngo;
        CryptoPP::ECDSA<ECP, SHA256>::PrivateKey privateKey;
        CryptoPP::ECDSA<ECP, SHA256>::PublicKey publickey;
        privateKey.Initialize( prngo, CryptoPP::ASN1::secp256k1());
        bool result = privateKey.Validate( prngo, 3 );
        if(result)
            {
            //CryptoPP::FileSink fs( "/home/aditya/private.ec.der", true /*binary/ );
            privateKey.Save( fs );
            std::cout<<"Key Generated"<<i<<endl;
            const CryptoPP::Integer& q = privateKey.GetPrivateExponent();
            privateKey.MakePublicKey(publickey);
            bool result = publickey.Validate( prngo, 3 );
            if(result){
                std::cout<<"PK Genrated"<<i<<endl;
                publickey.Save( fp );
                const ECP::Point& q = publickey.GetPublicElement();
                const CryptoPP::Integer& qx = q.x;
                const CryptoPP::Integer& qy = q.y;
                std::stringstream pp;
                pp<<std::hex<<qx<<qy;
                std::string pk = pp.str();
                std::cout<<pk<<endl;
            }
            //const CryptoPP::Integer& qx = q.x;
            //const CryptoPP::Integer& qy = q.y;
            std::stringstream ss ;
            ss<<std::hex<<q;
            std::string pk = ss.str();
            std::cout<<pk<<endl;
            }
        }*/
        //std::vector<string> veins::DemoBaseApplLayer::pkvii;
        //pkvii.push_back("Dummy");
        if(skeyV.empty()){
            CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PrivateKey k;
            CryptoPP::FileSource fs1( "/home/aditya/private.ec.der", true /*pump all*/ );
            for (int i=0; i<55;i++){
                k.Load( fs1 );
                skeyV.push_back(k);
            }
        }
        if(pkeyV.empty()){
            CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PublicKey publicKey;
            CryptoPP::FileSource fs2( "/home/aditya/public.ec.der", true /*pump all*/ );
            for (int i=0; i<55;i++){
                publicKey.Load( fs2 );
                pkeyV.push_back(publicKey);
            }
        }
    }
    virtual bool verifyPKSignature(DemoSafetyMessage* bsm);
    virtual void printStat();
    virtual bool isChannelIdle();

    /* stats */
    uint32_t generatedWSMs;
    uint32_t generatedWSAs;
    uint32_t generatedBSMs;
    uint32_t receivedWSMs;
    uint32_t receivedWSAs;
    uint32_t receivedBSMs;

    static double totalDuration;
    static int totalBSMs;

    /* messages for periodic events such as beacon and WSA transmissions */
    cMessage* sendBeaconEvt;
    cMessage* sendWSAEvt;
};

} // namespace veins
