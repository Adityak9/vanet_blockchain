//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
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

#include "veins/modules/application/traci/TraCIDemoRSU11p.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"

int veins::TraCIDemoRSU11p::lastPID = 0;
long veins::TraCIDemoRSU11p::totalRSURequests = 0;
long veins::TraCIDemoRSU11p::totalWSAs = 0;

using namespace veins;

Define_Module(veins::TraCIDemoRSU11p);

void TraCIDemoRSU11p::onWSA(DemoServiceAdvertisment* wsa)
{
    // if this RSU receives a WSA for service 42, it will tune to the chan
    if (wsa->getPsid() == 42) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
    }
}

void TraCIDemoRSU11p::onWSM(BaseFrame1609_4* frame)
{
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);

    // this rsu repeats the received traffic update in 2 seconds plus some random delay
    sendDelayedDown(wsm->dup(), 2 + uniform(0.01, 0.2));
}

bool TraCIDemoRSU11p::verifyPID(LAddress::L2Type senderPID, std::string pk) {
    //std::cout<<"set verify Pid called"<<std::endl;
    this->totalRSURequests++;
    std::cout<<"RSU REQU-->"<<totalRSURequests<<endl;
    if(senderPID == this->lastPID) {
        //std::cout<<"Previously validated this vehicle's PID and send WSA. Returned"<<std::endl;
        return true;
    }
    std::string pnm = to_string(senderPID);
    //http_client client(std::string("http://localhost:3000/api/queries/selectAllValidVehicles?PIDParam=")+pnm);
    //http_response response = client.request(methods::GET).get();
    blockchain blo(
                    grpc::CreateChannel("0.0.0.0:50052",grpc::InsecureChannelCredentials()));
    vanet_block::block_data rsp = blo.queryBlock(pnm);
    //std::cout<<"PID of vehicle is ------>"<<rsp.pid()<<" and "<<pnm<<endl;
    if(!rsp.pid().empty()){
        if(pnm.compare(rsp.pid())==0 && pk.compare(rsp.pk())==0){
            /*DemoServiceAdvertisment* wsa = new DemoServiceAdvertisment();
            this->populateWSM(wsa);
            wsa->setValidPID(senderPID);
            wsa->setValidPK(pk);
            //this->handleSelfMsg(wsa);
            //sendDown(wsa);
            this->totalWSAs++;
            std::cout<<"sending wsa"<<endl;
            scheduleAt(simTime(), wsa);
            cancelEvent(wsa);*/
            this->lastPID = senderPID;
            //std::cout<<"Returning True"<<endl;
            return true;
        }
    }
    return false;

 }
    /*if(response.status_code() == status_codes::OK)
    {
        utility::string_t body = response.extract_string().get();
        if(body.compare("[]")==0)
            //std::cout<<std::endl<<"Got Empty Value"<<std::endl;
            return false;
        string_t value1 = body.substr(49, 8);
        string_t value2 = body.substr(64, 130);
        if(pnm.compare(value1)==0 && pk.compare(value2)){
            //std::cout<<"Verified PK: "<<value2<<std::endl;
            WaveServiceAdvertisment* wsa = new WaveServiceAdvertisment();
            this->populateWSM(wsa);
            wsa->setValidPID(senderPID);
            wsa->setValidPK(pk);
            //this->handleSelfMsg(wsa);
            //sendDown(wsa);
            this->totalWSAs++;
            scheduleAt(simTime(), wsa);
            //std::cout<<"Created and send WSA for: "<<pnm<<std::endl;
            this->lastPID = senderPID;
            return true;
        }

    }*/
    //return false;
//}

vanet_block::block_data blockchain::queryBlock(std::string pnm){
    psuedoid request;
    request.set_pid(pnm);
    ClientContext context;
    block_data resp;
    grpc::Status statuss = stub_->qurery_Block(&context, request, &resp);
    if (!statuss.ok()) {
        //std::cout<<"call unsuccessfull";
        return resp;
    }
    //std::cout<<"successfull"<<endl;
    return resp;
}

void TraCIDemoRSU11p::printValues() {
    std::cout<<"Total WSAs: "<<this->totalWSAs<<std::endl;
    std::cout<<"Total RSU Requests: "<<this->totalRSURequests<<std::endl;
}

