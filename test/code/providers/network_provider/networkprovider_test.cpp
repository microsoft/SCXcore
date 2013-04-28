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
#include <networkprovider.h>
#include <testutils/providertestutils.h>
#include <scxsystemlib/networkinterfaceenumeration.h>
#include <scxsystemlib/networkinterface.h>
#include <cppunit/extensions/HelperMacros.h>

#include <scxcorelib/scxexception.h>
#include <testutils/scxunit.h>

#include <iostream>

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace SCXProviderLib;
using namespace std;

//! The provider relies on PAL(s) to provide information to return. This class makes
//! it possible to simulate PAL output to take control over the dependencies of
//! the provider. That makes it possible to correlate actual output with expected output.
class InjectedNetworkProviderDependencies : public NetworkProviderDependencies {
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

private:
    vector< SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> > m_instances;
};

//! Since the public interface is implemented by a separate class this
//! class makes the protected interface, implemented by the provider,
//! public so as to make it testable. The public interface is more cumbersome
//! to test and there is no need to test the implementation of it in every provider.
class TestableNetworkProvider : public TestableProvider, public NetworkProvider {
public:
    typedef NetworkProvider super;

    TestableNetworkProvider(SCXHandle<NetworkProviderDependencies> deps) : super(deps) {
    }

    virtual void TestDoInit() {
        super::DoInit();
    }

    virtual void TestDoEnumInstanceNames(const SCXProviderLib::SCXCallContext& callContext,
                                     SCXProviderLib::SCXInstanceCollection &names) {
        super::DoEnumInstanceNames(callContext, names);
    }

    virtual void TestDoEnumInstances(const SCXProviderLib::SCXCallContext& callContext,
                                 SCXProviderLib::SCXInstanceCollection &instances) {
        super::DoEnumInstances(callContext, instances);
    }

    virtual void TestDoGetInstance(const SCXProviderLib::SCXCallContext& callContext,
                               SCXProviderLib::SCXInstance& instance) {
        super::DoGetInstance(callContext, instance);
    }

    void TestDoInvokeMethod(const SCXProviderLib::SCXCallContext& callContext,
                            const std::wstring& methodname,
                            const SCXProviderLib::SCXArgs& args,
                            SCXProviderLib::SCXArgs& outargs,
                            SCXProviderLib::SCXProperty& result)
    {
        DoInvokeMethod(callContext, methodname, args, outargs, result);
    }

    virtual void TestDoCleanup() {
        super::DoCleanup();
    }

};

class SCXNetworkProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXNetworkProviderTest );
    CPPUNIT_TEST( testGetEthernetPortStatisticsInstance );
    CPPUNIT_TEST( testGetIPProtocolEndpointInstance );
    CPPUNIT_TEST( testGetLANEndpointInstance );
    CPPUNIT_TEST( TestEnumIPProtocolEndpointInstances );
    CPPUNIT_TEST( TestEnumLANEndpointInstances );
    CPPUNIT_TEST( TestEnumEthernetPortStatisticsInstances );
    CPPUNIT_TEST_SUITE_END();

private:
    SCXCoreLib::SCXHandle<TestableNetworkProvider> m_provider;

public:
    void setUp(void)
    {

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

        m_provider = new TestableNetworkProvider(deps);
        m_provider->TestDoInit();
    }

    void tearDown(void)
    {
        m_provider->TestDoCleanup();
        m_provider = 0;
    }

    void testGetEthernetPortStatisticsInstance()
    {
        try {
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"InstanceID");
            CPPUNIT_ASSERT(m_provider->VerifyGetInstanceByCompleteKeySuccess(L"SCX_EthernetPortStatistics", keyNames,
                    TestableProvider::eKeysOnly));
            CPPUNIT_ASSERT(m_provider->VerifyGetInstanceByPartialKeyFailure(L"SCX_EthernetPortStatistics", keyNames,
                    TestableProvider::eKeysOnly));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }

    void testGetIPProtocolEndpointInstance()
    {
        try {
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"Name");
            keyNames.push_back(L"CreationClassName");
            keyNames.push_back(L"SystemName");
            keyNames.push_back(L"SystemCreationClassName");
            CPPUNIT_ASSERT(m_provider->VerifyGetInstanceByCompleteKeySuccess(L"SCX_IPProtocolEndpoint", keyNames));
            CPPUNIT_ASSERT(m_provider->VerifyGetInstanceByPartialKeyFailure(L"SCX_IPProtocolEndpoint", keyNames));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }

    void testGetLANEndpointInstance(void)
    {
        try {
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"Name");
            keyNames.push_back(L"CreationClassName");
            keyNames.push_back(L"SystemName");
            keyNames.push_back(L"SystemCreationClassName");
            CPPUNIT_ASSERT(m_provider->VerifyGetInstanceByCompleteKeySuccess(L"SCX_LANEndpoint", keyNames));
            CPPUNIT_ASSERT(m_provider->VerifyGetInstanceByPartialKeyFailure(L"SCX_LANEndpoint", keyNames));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }

    void TestEnumLANEndpointInstances(void)
    {
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_LANEndpoint");
        SCXCallContext context(objectPath, eDirectSupport);
        SCXInstanceCollection instances;
        m_provider->TestDoEnumInstances(context, instances);
        CPPUNIT_ASSERT_EQUAL((size_t) 2, instances.Size());

        const SCXProperty *name = instances[0]->GetKey(L"Name");
        CPPUNIT_ASSERT(name != 0 && L"eth0" == name->GetStrValue());

        const SCXProperty *SystemCreationClassName = instances[0]->GetKey(L"SystemCreationClassName");
        CPPUNIT_ASSERT(SystemCreationClassName != 0 && L"SCX_ComputerSystem" == SystemCreationClassName->GetStrValue());

        const SCXProperty *SystemName = instances[0]->GetKey(L"SystemName");
        CPPUNIT_ASSERT(SystemName != 0 && L"" != SystemName->GetStrValue());

        const SCXProperty *CreationClassName = instances[0]->GetKey(L"CreationClassName");
        CPPUNIT_ASSERT(CreationClassName != 0 && L"SCX_LANEndpoint" == CreationClassName->GetStrValue());
    }

    void TestEnumIPProtocolEndpointInstances(void)
    {
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_IPProtocolEndpoint");
        SCXCallContext context(objectPath, eDirectSupport);
        SCXInstanceCollection instances;
        m_provider->TestDoEnumInstances(context, instances);
        CPPUNIT_ASSERT_EQUAL((size_t) 2, instances.Size());

        const SCXProperty *name = instances[0]->GetKey(L"Name");
        CPPUNIT_ASSERT(name != 0 && L"eth0" == name->GetStrValue());

        const SCXProperty *SystemCreationClassName = instances[0]->GetKey(L"SystemCreationClassName");
        CPPUNIT_ASSERT(SystemCreationClassName != 0 && L"SCX_ComputerSystem" == SystemCreationClassName->GetStrValue());

        const SCXProperty *SystemName = instances[0]->GetKey(L"SystemName");
        CPPUNIT_ASSERT(SystemName != 0 && L"" != SystemName->GetStrValue());

        const SCXProperty *CreationClassName = instances[0]->GetKey(L"CreationClassName");
        CPPUNIT_ASSERT(CreationClassName != 0 && L"SCX_IPProtocolEndpoint" == CreationClassName->GetStrValue());

        const SCXProperty *ipv4Address = instances[0]->GetProperty(L"IPv4Address");
        CPPUNIT_ASSERT(ipv4Address != 0 && L"192.168.0.34" == ipv4Address->GetStrValue());

        const SCXProperty *subnetMask = instances[0]->GetProperty(L"SubnetMask");
        CPPUNIT_ASSERT(subnetMask != 0 && L"255.255.255.0" == subnetMask->GetStrValue());

    }

    void TestEnumEthernetPortStatisticsInstances(void)
    {
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_EthernetPortStatistics");
        SCXCallContext context(objectPath, eDirectSupport);
        SCXInstanceCollection instances;
        m_provider->TestDoEnumInstances(context, instances);
        CPPUNIT_ASSERT_EQUAL((size_t) 2, instances.Size());

        const SCXProperty *instanceId = instances[0]->GetKey(L"InstanceID");
        CPPUNIT_ASSERT(instanceId != 0 && L"eth0" == instanceId->GetStrValue());

        const SCXProperty *bytesSent = instances[0]->GetProperty(L"BytesTransmitted");
        CPPUNIT_ASSERT(bytesSent != 0 && 10000 == bytesSent->GetULongValue());

        const SCXProperty *bytesReceived = instances[0]->GetProperty(L"BytesReceived");
        CPPUNIT_ASSERT(bytesReceived != 0 && 20000 == bytesReceived->GetULongValue());

        const SCXProperty *bytesTotal = instances[0]->GetProperty(L"BytesTotal");
        CPPUNIT_ASSERT(bytesTotal != 0 && (10000 + 20000) == bytesTotal->GetULongValue());

        const SCXProperty *packetsTransmitted = instances[0]->GetProperty(L"PacketsTransmitted");
        CPPUNIT_ASSERT(packetsTransmitted != 0 && 100 == packetsTransmitted->GetULongValue());

        const SCXProperty *packetsReceived = instances[0]->GetProperty(L"PacketsReceived");
        CPPUNIT_ASSERT(packetsReceived != 0 && 200 == packetsReceived->GetULongValue());

        const SCXProperty *totalTXErrors = instances[0]->GetProperty(L"TotalTxErrors");
        CPPUNIT_ASSERT(totalTXErrors != 0 && 1 == totalTXErrors->GetULongValue());

        const SCXProperty *totalRXErrors = instances[0]->GetProperty(L"TotalRxErrors");
        CPPUNIT_ASSERT(totalRXErrors != 0 && 2 == totalRXErrors->GetULongValue());

        const SCXProperty *totalCollisions = instances[0]->GetProperty(L"TotalCollisions");
        CPPUNIT_ASSERT(totalCollisions != 0 && 3 == totalCollisions->GetULongValue());

    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXNetworkProviderTest ); /* CUSTOMIZE: Name must be same as classname */
