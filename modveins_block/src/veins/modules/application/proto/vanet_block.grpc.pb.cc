// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: vanet_block.proto

#include "vanet_block.pb.h"
#include "vanet_block.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace vanet_block {

static const char* BlockchainVanet_method_names[] = {
  "/vanet_block.BlockchainVanet/reg_vehicle",
  "/vanet_block.BlockchainVanet/update_pid",
  "/vanet_block.BlockchainVanet/qurery_Block",
};

std::unique_ptr< BlockchainVanet::Stub> BlockchainVanet::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< BlockchainVanet::Stub> stub(new BlockchainVanet::Stub(channel, options));
  return stub;
}

BlockchainVanet::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_reg_vehicle_(BlockchainVanet_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_update_pid_(BlockchainVanet_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_qurery_Block_(BlockchainVanet_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BlockchainVanet::Stub::reg_vehicle(::grpc::ClientContext* context, const ::vanet_block::block_data& request, ::vanet_block::response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::vanet_block::block_data, ::vanet_block::response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_reg_vehicle_, context, request, response);
}

void BlockchainVanet::Stub::async::reg_vehicle(::grpc::ClientContext* context, const ::vanet_block::block_data* request, ::vanet_block::response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::vanet_block::block_data, ::vanet_block::response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_reg_vehicle_, context, request, response, std::move(f));
}

void BlockchainVanet::Stub::async::reg_vehicle(::grpc::ClientContext* context, const ::vanet_block::block_data* request, ::vanet_block::response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_reg_vehicle_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::vanet_block::response>* BlockchainVanet::Stub::PrepareAsyncreg_vehicleRaw(::grpc::ClientContext* context, const ::vanet_block::block_data& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::vanet_block::response, ::vanet_block::block_data, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_reg_vehicle_, context, request);
}

::grpc::ClientAsyncResponseReader< ::vanet_block::response>* BlockchainVanet::Stub::Asyncreg_vehicleRaw(::grpc::ClientContext* context, const ::vanet_block::block_data& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncreg_vehicleRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BlockchainVanet::Stub::update_pid(::grpc::ClientContext* context, const ::vanet_block::block_data& request, ::vanet_block::response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::vanet_block::block_data, ::vanet_block::response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_update_pid_, context, request, response);
}

void BlockchainVanet::Stub::async::update_pid(::grpc::ClientContext* context, const ::vanet_block::block_data* request, ::vanet_block::response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::vanet_block::block_data, ::vanet_block::response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_update_pid_, context, request, response, std::move(f));
}

void BlockchainVanet::Stub::async::update_pid(::grpc::ClientContext* context, const ::vanet_block::block_data* request, ::vanet_block::response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_update_pid_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::vanet_block::response>* BlockchainVanet::Stub::PrepareAsyncupdate_pidRaw(::grpc::ClientContext* context, const ::vanet_block::block_data& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::vanet_block::response, ::vanet_block::block_data, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_update_pid_, context, request);
}

::grpc::ClientAsyncResponseReader< ::vanet_block::response>* BlockchainVanet::Stub::Asyncupdate_pidRaw(::grpc::ClientContext* context, const ::vanet_block::block_data& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncupdate_pidRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BlockchainVanet::Stub::qurery_Block(::grpc::ClientContext* context, const ::vanet_block::psuedoid& request, ::vanet_block::block_data* response) {
  return ::grpc::internal::BlockingUnaryCall< ::vanet_block::psuedoid, ::vanet_block::block_data, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_qurery_Block_, context, request, response);
}

void BlockchainVanet::Stub::async::qurery_Block(::grpc::ClientContext* context, const ::vanet_block::psuedoid* request, ::vanet_block::block_data* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::vanet_block::psuedoid, ::vanet_block::block_data, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_qurery_Block_, context, request, response, std::move(f));
}

void BlockchainVanet::Stub::async::qurery_Block(::grpc::ClientContext* context, const ::vanet_block::psuedoid* request, ::vanet_block::block_data* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_qurery_Block_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::vanet_block::block_data>* BlockchainVanet::Stub::PrepareAsyncqurery_BlockRaw(::grpc::ClientContext* context, const ::vanet_block::psuedoid& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::vanet_block::block_data, ::vanet_block::psuedoid, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_qurery_Block_, context, request);
}

::grpc::ClientAsyncResponseReader< ::vanet_block::block_data>* BlockchainVanet::Stub::Asyncqurery_BlockRaw(::grpc::ClientContext* context, const ::vanet_block::psuedoid& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncqurery_BlockRaw(context, request, cq);
  result->StartCall();
  return result;
}

BlockchainVanet::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BlockchainVanet_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BlockchainVanet::Service, ::vanet_block::block_data, ::vanet_block::response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BlockchainVanet::Service* service,
             ::grpc::ServerContext* ctx,
             const ::vanet_block::block_data* req,
             ::vanet_block::response* resp) {
               return service->reg_vehicle(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BlockchainVanet_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BlockchainVanet::Service, ::vanet_block::block_data, ::vanet_block::response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BlockchainVanet::Service* service,
             ::grpc::ServerContext* ctx,
             const ::vanet_block::block_data* req,
             ::vanet_block::response* resp) {
               return service->update_pid(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BlockchainVanet_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BlockchainVanet::Service, ::vanet_block::psuedoid, ::vanet_block::block_data, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BlockchainVanet::Service* service,
             ::grpc::ServerContext* ctx,
             const ::vanet_block::psuedoid* req,
             ::vanet_block::block_data* resp) {
               return service->qurery_Block(ctx, req, resp);
             }, this)));
}

BlockchainVanet::Service::~Service() {
}

::grpc::Status BlockchainVanet::Service::reg_vehicle(::grpc::ServerContext* context, const ::vanet_block::block_data* request, ::vanet_block::response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BlockchainVanet::Service::update_pid(::grpc::ServerContext* context, const ::vanet_block::block_data* request, ::vanet_block::response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BlockchainVanet::Service::qurery_Block(::grpc::ServerContext* context, const ::vanet_block::psuedoid* request, ::vanet_block::block_data* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace vanet_block

