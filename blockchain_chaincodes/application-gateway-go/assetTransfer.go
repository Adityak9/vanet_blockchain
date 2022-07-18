/*
Copyright 2021 IBM All Rights Reserved.

SPDX-License-Identifier: Apache-2.0
*/

package main

import (
	"bytes"
	"context"
	"crypto/x509"
	"encoding/json"
	"errors"
	"fmt"
	"io/ioutil"
	"log"
	"net"
	"path"
	"time"

	pb "github.com/Adityak9/fabric-samples/asset-transfer-basic/application-gateway-go/proto"
	"github.com/hyperledger/fabric-gateway/pkg/client"
	"github.com/hyperledger/fabric-gateway/pkg/identity"
	gwproto "github.com/hyperledger/fabric-protos-go/gateway"
	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials"
	"google.golang.org/grpc/status"
)

const (
	mspID         = "Org1MSP"
	cryptoPath    = "../../test-network/organizations/peerOrganizations/org1.example.com"
	certPath      = cryptoPath + "/users/User1@org1.example.com/msp/signcerts/User1@org1.example.com-cert.pem"
	keyPath       = cryptoPath + "/users/User1@org1.example.com/msp/keystore/"
	tlsCertPath   = cryptoPath + "/peers/peer0.org1.example.com/tls/ca.crt"
	peerEndpoint  = "localhost:7051"
	gatewayPeer   = "peer0.org1.example.com"
	channelName   = "mychannel"
	chaincodeName = "basic"
)

var now = time.Now()
var id = fmt.Sprintf("asset with PusedoID%d", now.Unix()*1e3+int64(now.Nanosecond())/1e6)

var ad string = "0.0.0.0:50052"

type Ser struct {
	pb.BlockchainVanetServer
}

var contract *client.Contract

// Asset describes basic details of what makes up a simple asset
//Insert struct field in alphabetic order => to achieve determinism across languages
// golang keeps the order when marshal to json but doesn't order automatically
type Asset struct {
	VIN         string `json:"VIN"`
	PublicKey   string `json:"PublicKey"`
	PsuedoID    string `json:"PsuedoID"`
	StatusOfVeh string `json:"StatusOfVeh"`
	//Size           int    `json:"Size"`
}

func (s *Ser) RegVehicle(ctx context.Context, in *pb.BlockData) (*pb.Response, error) {

	log.Println("Register Vehicle Function Invoked")
	// The gRPC client connection should be shared by all Gateway connections to this endpoint
	clientConnection := newGrpcConnection()
	defer clientConnection.Close()

	id := newIdentity()
	sign := newSign()

	// Create a Gateway connection for a specific client identity
	gateway, err := client.Connect(
		id,
		client.WithSign(sign),
		client.WithClientConnection(clientConnection),
		// Default timeouts for different gRPC calls
		client.WithEvaluateTimeout(5*time.Second),
		client.WithEndorseTimeout(15*time.Second),
		client.WithSubmitTimeout(5*time.Second),
		client.WithCommitStatusTimeout(1*time.Minute),
	)
	if err != nil {
		panic(err)
	}
	defer gateway.Close()

	network := gateway.GetNetwork(channelName)
	contract := network.GetContract(chaincodeName)
	//initLedger(contract)
	createAsset(contract, in.Pid, in.Vin, in.Pk, in.Status)
	//createAsset(contract)
	//fmt.Println(in.Pid)
	//fmt.Println(in.Status)
	//fmt.Println(in.Pk)
	//fmt.Println(in.Vin)
	//getAllAssets(contract)
	return &pb.Response{Status: 1}, nil
}

func (s *Ser) Qurery_Block(ctx context.Context, in *pb.Psuedoid) (*pb.BlockData, error) {
	log.Println("Returns the block data")
	clientConnection := newGrpcConnection()
	defer clientConnection.Close()

	id := newIdentity()
	sign := newSign()

	// Create a Gateway connection for a specific client identity
	gateway, err := client.Connect(
		id,
		client.WithSign(sign),
		client.WithClientConnection(clientConnection),
		// Default timeouts for different gRPC calls
		client.WithEvaluateTimeout(5*time.Second),
		client.WithEndorseTimeout(15*time.Second),
		client.WithSubmitTimeout(5*time.Second),
		client.WithCommitStatusTimeout(1*time.Minute),
	)
	if err != nil {
		panic(err)
	}
	defer gateway.Close()

	network := gateway.GetNetwork(channelName)
	contract := network.GetContract(chaincodeName)
	var asset Asset
	asset, err = readAssetByID(contract, in.Pid)
	if err != nil {
		panic(err)
	}
	//initLedger(contract)
	//fmt.Println(asset.PsuedoID, asset.PublicKey, asset.StatusOfVeh, asset)
	return &pb.BlockData{Vin: asset.VIN, Pid: asset.PsuedoID, Pk: asset.PublicKey, Status: asset.StatusOfVeh}, nil

}
func (s *Ser) update_pid(ctx context.Context, in *pb.BlockData) (*pb.Response, error) {

	log.Println("Update_pid Function Invoked")
	// The gRPC client connection should be shared by all Gateway connections to this endpoint
	clientConnection := newGrpcConnection()
	defer clientConnection.Close()

	id := newIdentity()
	sign := newSign()

	// Create a Gateway connection for a specific client identity
	gateway, err := client.Connect(
		id,
		client.WithSign(sign),
		client.WithClientConnection(clientConnection),
		// Default timeouts for different gRPC calls
		client.WithEvaluateTimeout(5*time.Second),
		client.WithEndorseTimeout(15*time.Second),
		client.WithSubmitTimeout(5*time.Second),
		client.WithCommitStatusTimeout(1*time.Minute),
	)
	if err != nil {
		panic(err)
	}
	defer gateway.Close()

	network := gateway.GetNetwork(channelName)
	contract := network.GetContract(chaincodeName)
	createAsset(contract, in.Pid, in.Vin, in.Pk, in.Status)
	return &pb.Response{Status: 1}, nil
}

func main() {
	log.Println("============ application-golang starts ============")

	// The gRPC client connection should be shared by all Gateway connections to this endpoint
	clientConnection := newGrpcConnection()
	defer clientConnection.Close()

	id := newIdentity()
	sign := newSign()

	// Create a Gateway connection for a specific client identity
	gateway, err := client.Connect(
		id,
		client.WithSign(sign),
		client.WithClientConnection(clientConnection),
		// Default timeouts for different gRPC calls
		client.WithEvaluateTimeout(5*time.Second),
		client.WithEndorseTimeout(15*time.Second),
		client.WithSubmitTimeout(5*time.Second),
		client.WithCommitStatusTimeout(1*time.Minute),
	)
	if err != nil {
		panic(err)
	}
	defer gateway.Close()

	network := gateway.GetNetwork(channelName)
	contract := network.GetContract(chaincodeName)

	fmt.Println("Initializing the Ledger with dummy values:")
	initLedger(contract)

	//readAssetByID(contract, "Dummy1")

	lis, err := net.Listen("tcp", ad)
	if err != nil {
		log.Fatalf("Failed to listen")
	}

	s := grpc.NewServer()
	//if err != nil {
	//		log.Fatalf("something went wrong %v", err)
	//	}
	pb.RegisterBlockchainVanetServer(s, &Ser{})
	log.Printf("Listening on%s", ad)
	if err = s.Serve(lis); err != nil {
		log.Fatalf("Faied to serve: %v", err)
	}

	fmt.Println("initLedger:")
	initLedger(contract)

	fmt.Println("getAllAssets:")
	//getAllAssets(contract)

	fmt.Println("createAsset:")
	//createAsset(contract)

	fmt.Println("readAssetByID:")
	//readAssetByID(contract)

	fmt.Println("transferAssetAsync:")
	//transferAssetAsync(contract)

	fmt.Println("exampleErrorHandling:")
	//exampleErrorHandling(contract)

	log.Println("============ application-golang ends ============")
}

// newGrpcConnection creates a gRPC connection to the Gateway server.
func newGrpcConnection() *grpc.ClientConn {
	certificate, err := loadCertificate(tlsCertPath)
	if err != nil {
		panic(err)
	}

	certPool := x509.NewCertPool()
	certPool.AddCert(certificate)
	transportCredentials := credentials.NewClientTLSFromCert(certPool, gatewayPeer)

	connection, err := grpc.Dial(peerEndpoint, grpc.WithTransportCredentials(transportCredentials))
	if err != nil {
		panic(fmt.Errorf("failed to create gRPC connection: %w", err))
	}

	return connection
}

// newIdentity creates a client identity for this Gateway connection using an X.509 certificate.
func newIdentity() *identity.X509Identity {
	certificate, err := loadCertificate(certPath)
	if err != nil {
		panic(err)
	}

	id, err := identity.NewX509Identity(mspID, certificate)
	if err != nil {
		panic(err)
	}

	return id
}

func loadCertificate(filename string) (*x509.Certificate, error) {
	certificatePEM, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, fmt.Errorf("failed to read certificate file: %w", err)
	}
	return identity.CertificateFromPEM(certificatePEM)
}

// newSign creates a function that generates a digital signature from a message digest using a private key.
func newSign() identity.Sign {
	files, err := ioutil.ReadDir(keyPath)
	if err != nil {
		panic(fmt.Errorf("failed to read private key directory: %w", err))
	}
	privateKeyPEM, err := ioutil.ReadFile(path.Join(keyPath, files[0].Name()))

	if err != nil {
		panic(fmt.Errorf("failed to read private key file: %w", err))
	}

	privateKey, err := identity.PrivateKeyFromPEM(privateKeyPEM)
	if err != nil {
		panic(err)
	}

	sign, err := identity.NewPrivateKeySign(privateKey)
	if err != nil {
		panic(err)
	}

	return sign
}

/*
 This type of transaction would typically only be run once by an application the first time it was started after its
 initial deployment. A new version of the chaincode deployed later would likely not need to run an "init" function.
*/
func initLedger(contract *client.Contract) {
	fmt.Printf("Submit Transaction: InitLedger, function creates the initial set of assets on the ledger \n")

	_, err := contract.SubmitTransaction("InitLedger")
	if err != nil {
		panic(fmt.Errorf("failed to submit transaction: %w", err))
	}

	fmt.Printf("*** Transaction committed successfully\n")
}

// Evaluate a transaction to query ledger state.
func getAllAssets(contract *client.Contract) {
	fmt.Println("Evaluate Transaction: GetAllAssets, function returns all the current assets on the ledger")

	evaluateResult, err := contract.EvaluateTransaction("GetAllAssets")
	if err != nil {
		panic(fmt.Errorf("failed to evaluate transaction: %w", err))
	}
	result := formatJSON(evaluateResult)

	fmt.Printf("*** Result:%s\n", result)
}

// Submit a transaction synchronously, blocking until it has been committed to the ledger.
func createAsset(contract *client.Contract, pid string, vin string, pk string, stat string) {
	fmt.Printf("Submit Transaction: CreateAsset, creates new asset with PsuedID, VIN, PublicKey and Status arguments \n")

	_, err := contract.SubmitTransaction("CreateAsset", vin, pk, pid, stat)
	if err != nil {
		panic(fmt.Errorf("failed to submit transaction: %w", err))
	}

	fmt.Printf("*** Transaction committed successfully\n")
}

// Evaluate a transaction by assetID to query ledger state.
func readAssetByID(contract *client.Contract, pid string) (Asset, error) {
	fmt.Printf("Evaluate Transaction: ReadAsset, function returns asset attributes\n")

	evaluateResult, err := contract.EvaluateTransaction("ReadAsset", pid)
	if err != nil {
		panic(fmt.Errorf("failed to evaluate transaction: %w", err))
	}
	result := formatJSON(evaluateResult)
	//fmt.Printf(evaluateResult)
	var asset Asset
	err = json.Unmarshal([]byte(result), &asset)

	if err != nil {
		return asset, err
	}

	//fmt.Printf("*** Result:%s\n", result)
	return asset, err
}

/*
Submit transaction asynchronously, blocking until the transaction has been sent to the orderer, and allowing
this thread to process the chaincode response (e.g. update a UI) without waiting for the commit notification
*/
func transferAssetAsync(contract *client.Contract, pid string) {
	fmt.Printf("Async Submit Transaction: TransferAsset, updates existing asset owner'\n")

	submitResult, commit, err := contract.SubmitAsync("TransferAsset", client.WithArguments(pid, "Mark"))
	if err != nil {
		panic(fmt.Errorf("failed to submit transaction asynchronously: %w", err))
	}

	fmt.Printf("Successfully submitted transaction to transfer ownership from %s to Mark. \n", string(submitResult))
	fmt.Println("Waiting for transaction commit.")

	if status, err := commit.Status(); err != nil {
		panic(fmt.Errorf("failed to get commit status: %w", err))
	} else if !status.Successful {
		panic(fmt.Errorf("transaction %s failed to commit with status: %d", status.TransactionID, int32(status.Code)))
	}

	fmt.Printf("*** Transaction committed successfully\n")
}

// Submit transaction, passing in the wrong number of arguments ,expected to throw an error containing details of any error responses from the smart contract.
func exampleErrorHandling(contract *client.Contract) {
	fmt.Println("Submit Transaction: UpdateAsset asset70, asset70 does not exist and should return an error")

	_, err := contract.SubmitTransaction("UpdateAsset")
	if err != nil {
		switch err := err.(type) {
		case *client.EndorseError:
			fmt.Printf("Endorse error with gRPC status %v: %s\n", status.Code(err), err)
		case *client.SubmitError:
			fmt.Printf("Submit error with gRPC status %v: %s\n", status.Code(err), err)
		case *client.CommitStatusError:
			if errors.Is(err, context.DeadlineExceeded) {
				fmt.Printf("Timeout waiting for transaction %s commit status: %s", err.TransactionID, err)
			} else {
				fmt.Printf("Error obtaining commit status with gRPC status %v: %s\n", status.Code(err), err)
			}
		case *client.CommitError:
			fmt.Printf("Transaction %s failed to commit with status %d: %s\n", err.TransactionID, int32(err.Code), err)
		}
		/*
		 Any error that originates from a peer or orderer node external to the gateway will have its details
		 embedded within the gRPC status error. The following code shows how to extract that.
		*/
		statusErr := status.Convert(err)
		for _, detail := range statusErr.Details() {
			errDetail := detail.(*gwproto.ErrorDetail)
			fmt.Printf("Error from endpoint: %s, mspId: %s, message: %s\n", errDetail.Address, errDetail.MspId, errDetail.Message)
		}
	}
}

//Format JSON data
func formatJSON(data []byte) string {
	var prettyJSON bytes.Buffer
	if err := json.Indent(&prettyJSON, data, " ", ""); err != nil {
		panic(fmt.Errorf("failed to parse JSON: %w", err))
	}
	return prettyJSON.String()
}
