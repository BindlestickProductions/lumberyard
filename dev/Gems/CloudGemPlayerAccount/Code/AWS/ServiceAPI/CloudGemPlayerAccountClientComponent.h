/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// THIS CODE IS AUTOGENERATED, DO NOT MODIFY
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
#pragma once
#include <AzCore/Component/Component.h>
#include <AzCore/Component/Entity.h>
#include <AzCore/Component/ComponentBus.h>
#include <AzCore/EBus/EBus.h>
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/std/smart_ptr/make_shared.h>
#include <AzCore/std/smart_ptr/shared_ptr.h>
#include <AzCore/std/string/conversions.h>

#if defined (PLATFORM_SUPPORTS_AWS_NATIVE_SDK)
#include <aws/core/http/HttpRequest.h>
#include <aws/core/http/HttpResponse.h>
#endif // (PLATFORM_SUPPORTS_AWS_NATIVE_SDK)

#include <CloudGemFramework/ServiceRequestJob.h>

#include "StdAfx.h"

namespace CloudGemPlayerAccount {
namespace ServiceAPI {
    
    extern const char* LmbrAWS_CodeGen_Component_UUID;
    
    extern const char* LmbrAWS_CodeGen_ResponseHandler_UUID;
    
    extern const char* LmbrAWS_CodeGen_NotificationBus1_UUID;
    
    extern const char* LmbrAWS_CodeGen_RequestBus1_UUID;
    
    extern const char* LmbrAWS_CodeGen_ServiceStatus_UUID;
    
    extern const char* LmbrAWS_CodeGen_AccountResponse_UUID;
    
    extern const char* LmbrAWS_CodeGen_UpdateAccountRequest_UUID;
    

    // redefs
    

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const int& item);

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const AZStd::string& item);

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const double& item);

    
    
    struct UpdateAccountRequest
    {

        AZ_TYPE_INFO(UpdateAccountRequest, LmbrAWS_CodeGen_UpdateAccountRequest_UUID)
        AZ_CLASS_ALLOCATOR(UpdateAccountRequest, AZ::SystemAllocator, 0)

        
        AZStd::string PlayerName;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const UpdateAccountRequest& item);
    
    
    
    struct AccountResponse
    {

        AZ_TYPE_INFO(AccountResponse, LmbrAWS_CodeGen_AccountResponse_UUID)
        AZ_CLASS_ALLOCATOR(AccountResponse, AZ::SystemAllocator, 0)

        
        AZStd::string PlayerName;
        
        AZStd::string AccountId;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const AccountResponse& item);
    
    
    
    struct ServiceStatus
    {

        AZ_TYPE_INFO(ServiceStatus, LmbrAWS_CodeGen_ServiceStatus_UUID)
        AZ_CLASS_ALLOCATOR(ServiceStatus, AZ::SystemAllocator, 0)

        
        AZStd::string status;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const ServiceStatus& item);
    
    


    // Service RequestJobs
    CLOUD_GEM_SERVICE(CloudGemPlayerAccount);


    
    class PutAccountRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemPlayerAccount, HttpMethod::HTTP_PUT, "/account");

        struct Parameters
        {
            
            UpdateAccountRequest UpdateAccountRequest;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        AccountResponse result;
        

        Parameters parameters;
    };


    using PutAccountRequestJob = CloudGemFramework::ServiceRequestJob<PutAccountRequest>;
    
    class GetAccountRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemPlayerAccount, HttpMethod::HTTP_GET, "/account");

        struct Parameters
        {
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        AccountResponse result;
        

        Parameters parameters;
    };


    using GetAccountRequestJob = CloudGemFramework::ServiceRequestJob<GetAccountRequest>;
    
    class GetServiceStatusRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemPlayerAccount, HttpMethod::HTTP_GET, "/service/status");

        struct Parameters
        {
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        ServiceStatus result;
        

        Parameters parameters;
    };


    using GetServiceStatusRequestJob = CloudGemFramework::ServiceRequestJob<GetServiceStatusRequest>;
    


    // Notification bus for this component
    class CloudGemPlayerAccountNotifications
        : public AZ::ComponentBus
    {
    public:
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnPutAccountRequestSuccess(const AccountResponse response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnPutAccountRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnGetAccountRequestSuccess(const AccountResponse response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnGetAccountRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnGetServiceStatusRequestSuccess(const ServiceStatus response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnGetServiceStatusRequestError(const CloudGemFramework::Error error);
        
    };

    using CloudGemPlayerAccountNotificationBus = AZ::EBus<CloudGemPlayerAccountNotifications>;

    class BehaviorCloudGemPlayerAccountNotificationBusHandler
        : public CloudGemPlayerAccountNotificationBus::Handler, public AZ::BehaviorEBusHandler
    {
    public:
        AZ_EBUS_BEHAVIOR_BINDER(BehaviorCloudGemPlayerAccountNotificationBusHandler, LmbrAWS_CodeGen_NotificationBus1_UUID, AZ::SystemAllocator
        
        , OnPutAccountRequestSuccess
        , OnPutAccountRequestError
        
        , OnGetAccountRequestSuccess
        , OnGetAccountRequestError
        
        , OnGetServiceStatusRequestSuccess
        , OnGetServiceStatusRequestError
        
        );
        
        
        void OnPutAccountRequestSuccess(const AccountResponse response) override;
        
        void OnPutAccountRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnGetAccountRequestSuccess(const AccountResponse response) override;
        
        void OnGetAccountRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnGetServiceStatusRequestSuccess(const ServiceStatus response) override;
        
        void OnGetServiceStatusRequestError(const CloudGemFramework::Error error) override;
        
    };
    class CloudGemPlayerAccountResponseHandler;

    // Request bus for this component
    class CloudGemPlayerAccountRequests
        : public AZ::ComponentBus
    {
    public:
        virtual ~CloudGemPlayerAccountRequests() {}
        
        
        virtual void PutAccount(const UpdateAccountRequest& UpdateAccountRequest, CloudGemPlayerAccountResponseHandler* responseHandler);
        
        
        
        virtual void GetAccount(CloudGemPlayerAccountResponseHandler* responseHandler);
        
        
        
        virtual void GetServiceStatus(CloudGemPlayerAccountResponseHandler* responseHandler);
        
        
    };

    using CloudGemPlayerAccountRequestBus = AZ::EBus<CloudGemPlayerAccountRequests>;

    // This class is used as a parameter for all requests and throws the response on the CloudGemPlayerAccountNotificationBus
    // Inherit from this to define custom behavior.
    class CloudGemPlayerAccountResponseHandler
    {
    public:
        AZ_TYPE_INFO(CloudGemPlayerAccountResponseHandler, LmbrAWS_CodeGen_ResponseHandler_UUID)
        AZ_CLASS_ALLOCATOR(CloudGemPlayerAccountResponseHandler, AZ::SystemAllocator, 0)

        virtual ~CloudGemPlayerAccountResponseHandler() {}
        
        virtual void HandlePutAccountSuccess(PutAccountRequestJob* job, AZ::EntityId entityId);
        virtual void HandlePutAccountError(PutAccountRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleGetAccountSuccess(GetAccountRequestJob* job, AZ::EntityId entityId);
        virtual void HandleGetAccountError(GetAccountRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleGetServiceStatusSuccess(GetServiceStatusRequestJob* job, AZ::EntityId entityId);
        virtual void HandleGetServiceStatusError(GetServiceStatusRequestJob* job, AZ::EntityId entityId);
        
    };

    class CloudGemPlayerAccountClientComponent
        : public AZ::Component
        , public CloudGemPlayerAccountRequestBus::Handler
    {
    public:
        AZ_COMPONENT(CloudGemPlayerAccountClientComponent, LmbrAWS_CodeGen_Component_UUID);
        virtual ~CloudGemPlayerAccountClientComponent() = default;

        AZStd::shared_ptr<CloudGemPlayerAccountResponseHandler> m_defaultResponseHandler;

        void Init() override;

        void Activate() override;

        void Deactivate() override;

        static void Reflect(AZ::ReflectContext* reflection)
        {
            
            
            UpdateAccountRequest::Reflect(reflection);
            
            
            
            AccountResponse::Reflect(reflection);
            
            
            
            ServiceStatus::Reflect(reflection);
            
            

            AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflection);
            if (serializeContext)
            {
                // we must include any fields we want to expose to the editor or lua in the serialize context
                serializeContext->Class<CloudGemPlayerAccountClientComponent>()
                    ->Version(1);

                AZ::EditContext* editContext = serializeContext->GetEditContext();
                if (editContext)
                {
                    editContext->Class<CloudGemPlayerAccountClientComponent>("CloudGemPlayerAccountClientComponent", "CloudGemPlayerAccount Component")
                        ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                            ->Attribute(AZ::Edit::Attributes::Category, "Cloud Canvas Gems")
                            ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game"));
                }
            }

            AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(reflection);
            if (behaviorContext)
            {
                behaviorContext->EBus<CloudGemPlayerAccountRequestBus>("CloudGemPlayerAccountRequestBus")
                    // one of these for each function
                    
                    ->Event("PutAccount", &CloudGemPlayerAccountRequestBus::Events::PutAccount)
                    
                    ->Event("GetAccount", &CloudGemPlayerAccountRequestBus::Events::GetAccount)
                    
                    ->Event("GetServiceStatus", &CloudGemPlayerAccountRequestBus::Events::GetServiceStatus)
                    
                    ;
                behaviorContext->EBus<CloudGemPlayerAccountNotificationBus>("CloudGemPlayerAccountNotificationBus")
                    ->Handler<BehaviorCloudGemPlayerAccountNotificationBusHandler>()
                ;
            }
        }

        // Functions from the swagger definitions
        
        
        void PutAccount(const UpdateAccountRequest& UpdateAccountRequest, CloudGemPlayerAccountResponseHandler* responseHandler) override;
        
        
        
        void GetAccount(CloudGemPlayerAccountResponseHandler* responseHandler) override;
        
        
        
        void GetServiceStatus(CloudGemPlayerAccountResponseHandler* responseHandler) override;
        
        
    };
} // ServiceAPI
} // CloudGemPlayerAccount