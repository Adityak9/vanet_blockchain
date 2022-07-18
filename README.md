# vanet_blockchain
This Repo is a project of integrating HLF(Blockchain) with the Veins(VANET)

# Pre-Requisites:
1. Download and Install [HLF v2.4](https://www.hyperledger.org/use/fabric) and [Hyperledger Explorer](https://www.hyperledger.org/use/explorer).
2. Download and Install [Omnet++ v5.7](https://omnetpp.org/).
3. Download and Install [SUMO v1.14](https://www.eclipse.org/sumo/)
4. Download and Install [gRPC](https://grpc.io/)

# Steps to Use:

1. After installing the HLF and Explorer replace the chaincode-go and application-gateway-go in the fabric-samples directory created during HLF installation.
2. After that you have to build the application-gateway-go using go build command.
3. After that you can start the network following the HLF wiki.
4. After starting the network deploy the replaced chaincode on the channel.
5. Now start the Omnetpp and import the veins-master project.
6. Now you just have to build the project after importing it.
7. Run the project and enjoy.
