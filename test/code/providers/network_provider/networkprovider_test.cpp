/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
    \file

    \brief       Tests for the network provider

    \date        2008-03-14 09:00

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <scxsystemlib/networkinterface.h>
#include <networkprovider.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include "SCX_EthernetPortStatistics_Class_Provider.h"
#include "SCX_IPProtocolEndpoint_Class_Provider.h"
#include "SCX_LANEndpoint_Class_Provider.h"

//! The provider relies on PAL(s) to provide information to return. This class makes
//! it possible to simulate PAL output to take control over the dependencies of
//! the provider. That makes it possible to correlate actual output with expected output.
class InjectedNetworkProviderDependencies : public SCXCore::NetworkProviderDependencies {
public:
    void InitIntf() {
    }

    void SetInstances(const vector< SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> >& instances) {
        m_instances = instances;
    }

    void CleanUpIntf() {
    }

    void UpdateIntf(bool) {
    }

    size_t IntfCount() const {
        return m_instances.size();
    }

    SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> GetIntf(size_t pos) const {
        return m_instances[pos];
    }

    SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> GetIntf(const std::wstring& intfId) const {
        for (size_t i = 0; i < m_instances.size() ; i++)
        {
            if (intfId == m_instances[i]->GetName())
            {
                return m_instances[i];
            }
        }
        return SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance>();
    }

private:
    vector< SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> > m_instances;
};

class SCXNetworkProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXNetworkProviderTest );
    CPPUNIT_TEST( TestVerifyKeyCompletePartialEthernetPortStatistics );
    CPPUNIT_TEST( TestVerifyKeyCompletePartialIPProtocolEndpoint );
    CPPUNIT_TEST( TestVerifyKeyCompletePartialLANEndpoint );
    CPPUNIT_TEST( TestEnumIPProtocolEndpointInstances );
    CPPUNIT_TEST( TestEnumLANEndpointInstances );
    CPPUNIT_TEST( TestEnumEthernetPortStatisticsInstances );
    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNamesEPS;// SCX_EthernetPortStatistics key names.
    std::vector<std::wstring> m_keyNamesIPPE;// SCX_IPProtocolEndpoint key names.
    std::vector<std::wstring> m_keyNamesLANE;// SCX_LANEndpoint key names.

public:
    void setUp(void)
    {
        m_keyNamesEPS.push_back(L"InstanceID");

        m_keyNamesIPPE.push_back(L"Name");
        m_keyNamesIPPE.push_back(L"SystemCreationClassName");
        m_keyNamesIPPE.push_back(L"SystemName");
        m_keyNamesIPPE.push_back(L"CreationClassName");

        m_keyNamesLANE.push_back(L"Name");
        m_keyNamesLANE.push_back(L"SystemCreationClassName");
        m_keyNamesLANE.push_back(L"SystemName");
        m_keyNamesLANE.push_back(L"CreationClassName");

        std::wostringstream errMsg;
        SetUpAgent<mi::SCX_EthernetPortStatistics_Class_Provider>(CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_IPProtocolEndpoint_Class_Provider>(CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_LANEndpoint_Class_Provider>(CALL_LOCATION(errMsg));

        vector< SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> > originalInstances;
        const unsigned allProperties = static_cast<unsigned> (-1);
        const unsigned noOptionalProperties = 0;
        originalInstances.push_back( SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance>(
            new NetworkInterfaceInstance(NetworkInterfaceInfo(
                L"eth0", allProperties,
//                L"0a123C4Defa6",
                L"192.168.0.34", L"255.255.255.0", L"192.168.0.255",
                10000, 20000, 100, 200, 1, 2, 3, true, true, SCXCoreLib::SCXHandle<NetworkInterfaceDependencies>(0)))));
        originalInstances.push_back(SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance>(
            new NetworkInterfaceInstance(NetworkInterfaceInfo(
                L"eth1", noOptionalProperties,
//                L"001122334455",
                L"192.168.1.35", L"255.255.255.0", L"192.168.1.255",
                20000, 40000, 200, 400, 2, 4, 6, false, false, SCXCoreLib::SCXHandle<NetworkInterfaceDependencies>(0)))));
        
        SCXHandle<InjectedNetworkProviderDependencies> deps(new InjectedNetworkProviderDependencies());
        deps->SetInstances(originalInstances);
        SCXCore::g_NetworkProvider.UpdateDependencies(deps);
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TearDownAgent<mi::SCX_EthernetPortStatistics_Class_Provider>(CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_IPProtocolEndpoint_Class_Provider>(CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_LANEndpoint_Class_Provider>(CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialEthernetPortStatistics()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_EthernetPortStatistics_Class_Provider,
                mi::SCX_EthernetPortStatistics_Class>(m_keyNamesEPS, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialIPProtocolEndpoint()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_IPProtocolEndpoint_Class_Provider,
                mi::SCX_IPProtocolEndpoint_Class>(m_keyNamesIPPE, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialLANEndpoint()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_LANEndpoint_Class_Provider,
                mi::SCX_LANEndpoint_Class>(m_keyNamesLANE, CALL_LOCATION(errMsg));
    }

    void TestEnumLANEndpointInstances(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_LANEndpoint_Class_Provider>(
            m_keyNamesLANE, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 2u, context.Size());

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"eth0",
            context[0].GetKey(L"Name", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX_ComputerSystem",
            context[0].GetKey(L"SystemCreationClassName", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, GetFQHostName(CALL_LOCATION(errMsg)),
            context[0].GetKey(L"SystemName", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX_LANEndpoint",
            context[0].GetKey(L"CreationClassName", CALL_LOCATION(errMsg)));
    }

    void TestEnumIPProtocolEndpointInstances(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_IPProtocolEndpoint_Class_Provider>(
            m_keyNamesIPPE, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 2u, context.Size());

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"eth0",
            context[0].GetKey(L"Name", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX_ComputerSystem",
            context[0].GetKey(L"SystemCreationClassName", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, GetFQHostName(CALL_LOCATION(errMsg)),
            context[0].GetKey(L"SystemName", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX_IPProtocolEndpoint",
            context[0].GetKey(L"CreationClassName", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"192.168.0.34",
            context[0].GetProperty(L"IPv4Address", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"255.255.255.0",
            context[0].GetProperty(L"SubnetMask", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
    }

    void TestEnumEthernetPortStatisticsInstances(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_EthernetPortStatistics_Class_Provider>(
            m_keyNamesEPS, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 2u, context.Size());

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"eth0", context[0].GetKey(L"InstanceID", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 10000u,
            context[0].GetProperty(L"BytesTransmitted", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 20000u,
            context[0].GetProperty(L"BytesReceived", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 30000u,
            context[0].GetProperty(L"BytesTotal", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 100u,
            context[0].GetProperty(L"PacketsTransmitted", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 200u,
            context[0].GetProperty(L"PacketsReceived", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 1u,
            context[0].GetProperty(L"TotalTxErrors", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 2u,
            context[0].GetProperty(L"TotalRxErrors", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 3u,
            context[0].GetProperty(L"TotalCollisions", CALL_LOCATION(errMsg)).GetValue_MIUint64(CALL_LOCATION(errMsg)));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXNetworkProviderTest ); /* CUSTOMIZE: Name must be same as classname */
