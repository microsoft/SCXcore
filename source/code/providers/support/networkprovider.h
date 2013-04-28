/**
    \file     networkprovider.h

    \brief    Declarations of the Network Provider class and its dependencies.


    \date     12-03-20 11:00

*/
/*----------------------------------------------------------------------------*/
#ifndef NETWORKPROVIDER_H
#define NETWORKPROVIDER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include <scxsystemlib/networkinterfaceinstance.h> // for  NetworkInterfaceInstance
#include <scxsystemlib/networkinterfaceenumeration.h> // for NetworkInterfaceEnumeration
#include "startuplog.h"

using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;

namespace SCXCore
{
    /*----------------------------------------------------------------------------*/
    //! Encapsulates the dependencies of the Network Provider
    //!
    class NetworkProviderDependencies  
    {
    public:
        NetworkProviderDependencies() : m_interfaces(0) {}
        virtual void InitIntf();
        virtual void CleanUpIntf();
        virtual void UpdateIntf(bool updateInstances=true);
        virtual size_t IntfCount() const;
        virtual SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> GetIntf(size_t pos) const;
        virtual SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> GetIntf(const std::wstring& intfId) const;

        //! Virtual destructor preparing for subclasses
        virtual ~NetworkProviderDependencies() { }
    private:
        //! PAL implementation retrieving network information for local host
        SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceEnumeration> m_interfaces;
    }; // End of class NetworkProviderDependencies

    /*----------------------------------------------------------------------------*/
    /**
       Network provider

       Provide base system information to the Network providers including:
       SCX_EthernetPortStatistics, SCX_LANEndpoint, and SCX_IPProtocolEndpoint.
    */
    class NetworkProvider
    {
    public:
        NetworkProvider() : m_deps(0) { }

        virtual ~NetworkProvider() { };

        void Load()
        {
            if ( 1 == ++ms_loadCount )
            {
                m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.Network_provider");
                LogStartup();
                SCX_LOGTRACE(m_log, L"NetworkProvider::Load()");

                // Create dependencies
                m_deps = new SCXCore::NetworkProviderDependencies();

                // Initialize the interface
                m_deps->InitIntf();
            }
        }

        void Unload()
        {
            SCX_LOGTRACE(m_log, L"NetworkProvider::Unload()");
            if ( 0 == --ms_loadCount )
            {
                m_deps->CleanUpIntf();
                m_deps = 0;
            }
        }

        SCXLogHandle& GetLogHandle(){ return m_log; }
        void UpdateDependencies(SCXHandle<SCXCore::NetworkProviderDependencies> deps) { m_deps = deps; }
        SCXCoreLib::SCXHandle<SCXCore::NetworkProviderDependencies> getDependencies() { return m_deps; }
    private:
        static int ms_loadCount;
        SCXCoreLib::SCXHandle<SCXCore::NetworkProviderDependencies> m_deps; //!< External functionality the provider is dependent upon.
        SCXCoreLib::SCXLogHandle m_log; //!< Handle to log file.

    }; // End of class NetworkProvider

    extern NetworkProvider g_NetworkProvider;
} // End of namespace SCXCore

#endif /* NETWORKPROVIDER_H */
