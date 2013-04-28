/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the appserver provider

   \date        2011-05-05

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <appserverprovider.h>
#include <websphereappserverinstance.h>
#include <testutils/scxunit.h>
#include <scxcorelib/scxexception.h>

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXProviderLib;
using namespace SCXSystemLib;

class TestableASProvider : public ASProvider
{
public:
    TestableASProvider(SCXCoreLib::SCXHandle<AppServerProviderPALDependencies> deps) : ASProvider(deps)
    {
        DoInit();
    }

    virtual ~TestableASProvider()
    {
        DoCleanup();
    }

    void TestDoEnumInstances(const SCXCallContext& callContext, SCXInstanceCollection &instances)
    {
        DoEnumInstances(callContext, instances);
    }

    void TestDoGetInstance(const SCXCallContext& callContext, SCXInstance& instance) 
    {
        DoGetInstance(callContext, instance);
    }

    void TestDoEnumInstanceNames(const SCXCallContext& callContext, SCXInstanceCollection &instances)
    {
        DoEnumInstanceNames(callContext, instances);
    }

    void TestDoInvokeMethod(const SCXCallContext& callContext,
                            const std::wstring& methodname, const SCXArgs& args,
                            SCXArgs& outargs, SCXProperty& result)
    {
        DoInvokeMethod(callContext, methodname, args, outargs, result);
    }

};


class AppServerTestEnumeration : public AppServerEnumeration
{
public:
    AppServerTestEnumeration() {};
    ~AppServerTestEnumeration() {};

    virtual void Init()
    {
        Update(false);
    };

    virtual void Update(bool /*updateInstances*/)
    {
        if (Size() == 0)
        {
            SCXHandle<AppServerInstance> inst = SCXHandle<AppServerInstance>(new AppServerInstance(L"/opt/jboss-5.1.0.GA/", L"JBoss"));

            inst->SetHttpPort(L"8280");
            inst->SetHttpsPort(L"8643");
            inst->SetVersion(L"5.1.0.GA");

            AddInstance(inst);

            SCXHandle<WebSphereAppServerInstance> inst2 = SCXHandle<WebSphereAppServerInstance>(new WebSphereAppServerInstance(L"/opt/websphere/AppServer/profiles/AppSrv01/", L"Node01Cell", L"Node01", L"AppSrv01", L"server1"));

            inst2->SetHttpPort(L"9080");
            inst2->SetHttpsPort(L"9443");
            inst2->SetVersion(L"7.0.0.0");

            AddInstance(inst2);
        }
    };

    virtual void CleanUp() {};
};

class AppServerProviderTestPALDependencies : public AppServerProviderPALDependencies
{
public:
    virtual ~AppServerProviderTestPALDependencies() {};
    
    virtual SCXHandle<AppServerEnumeration> CreateEnum()
    {
        return SCXHandle<AppServerEnumeration>(new AppServerTestEnumeration());
    }
};

class SCXASProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXASProviderTest );

    CPPUNIT_TEST( callDumpStringForCoverage );
    CPPUNIT_TEST( TestDoEnumInstances );
    CPPUNIT_TEST( TestDoGetInstanceGood );
    CPPUNIT_TEST( TestDoGetInstanceNotFound );
    CPPUNIT_TEST( TestDoEnumInstanceNames );
    CPPUNIT_TEST( TestDoInvokeMethodNoAppServer );
    CPPUNIT_TEST( TestDoInvokeMethodWrongMethod );
    CPPUNIT_TEST( TestDoInvokeMethodMissingArg );
    CPPUNIT_TEST( TestDoInvokeMethodWrongArgType );
    CPPUNIT_TEST( TestDoInvokeMethodGood );

    CPPUNIT_TEST_SUITE_END();

private:
    SCXHandle<TestableASProvider> m_asProvider;
    SCXHandle<AppServerProviderPALDependencies> m_deps;

public:
    void setUp(void)
    {
        CPPUNIT_ASSERT_NO_THROW(m_deps = new AppServerProviderTestPALDependencies());
        CPPUNIT_ASSERT_NO_THROW(m_asProvider = new TestableASProvider(m_deps));
    }

    void tearDown(void)
    {
        m_asProvider = 0;
        m_deps = 0;
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(m_asProvider->DumpString().find(L"ASProvider") != std::wstring::npos);
    }

    void TestDoEnumInstances()
    {
        SCXInstanceCollection instances;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");
        SCXCallContext context(objectPath, eDirectSupport);
        m_asProvider->TestDoEnumInstances(context, instances);
        
        CPPUNIT_ASSERT(2 == instances.Size());

        /* Verify that the key is correct */
        CPPUNIT_ASSERT(1 == instances[0]->NumberOfKeys());
        CPPUNIT_ASSERT(1 == instances[1]->NumberOfKeys());

        const SCXProperty* key = instances[0]->GetKey(L"Name");
        CPPUNIT_ASSERT(0 != key);
        CPPUNIT_ASSERT(key->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(key->GetStrValue() == L"/opt/jboss-5.1.0.GA/");
        
        key = instances[1]->GetKey(L"Name");
        CPPUNIT_ASSERT(0 != key);
        CPPUNIT_ASSERT(key->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(key->GetStrValue() == L"AppSrv01-Node01Cell-Node01-server1");
        
        /* Verify the properties */
        CPPUNIT_ASSERT(14 == instances[0]->NumberOfProperties());

        const SCXProperty* property = instances[0]->GetProperty(L"HttpPort");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"8280");

        property = instances[0]->GetProperty(L"HttpsPort");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"8643");

        property = instances[0]->GetProperty(L"Version");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"5.1.0.GA");

        property = instances[0]->GetProperty(L"MajorVersion");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"5");

        property = instances[0]->GetProperty(L"Port");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instances[0]->GetProperty(L"Protocol");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instances[0]->GetProperty(L"DiskPath");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"/opt/jboss-5.1.0.GA/");

        property = instances[0]->GetProperty(L"Type");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"JBoss");

        property = instances[0]->GetProperty(L"IsDeepMonitored");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXBoolType);
        CPPUNIT_ASSERT(property->GetBoolValue() == false);

        property = instances[0]->GetProperty(L"IsRunning");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXBoolType);
        CPPUNIT_ASSERT(property->GetBoolValue() == true);

        property = instances[0]->GetProperty(L"Profile");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instances[0]->GetProperty(L"Cell");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instances[0]->GetProperty(L"Node");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instances[0]->GetProperty(L"Server");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        CPPUNIT_ASSERT(14 == instances[1]->NumberOfProperties());

        property = instances[1]->GetProperty(L"HttpPort");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"9080");

        property = instances[1]->GetProperty(L"HttpsPort");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"9443");

        property = instances[1]->GetProperty(L"Version");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"7.0.0.0");

        property = instances[1]->GetProperty(L"MajorVersion");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"7");

        property = instances[1]->GetProperty(L"Port");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instances[1]->GetProperty(L"Protocol");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instances[1]->GetProperty(L"DiskPath");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"/opt/websphere/AppServer/profiles/AppSrv01/");

        property = instances[1]->GetProperty(L"Type");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"WebSphere");

        property = instances[1]->GetProperty(L"IsDeepMonitored");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXBoolType);
        CPPUNIT_ASSERT(property->GetBoolValue() == false);

        property = instances[1]->GetProperty(L"IsRunning");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXBoolType);
        CPPUNIT_ASSERT(property->GetBoolValue() == true);

        property = instances[1]->GetProperty(L"Profile");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"AppSrv01");

        property = instances[1]->GetProperty(L"Cell");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"Node01Cell");

        property = instances[1]->GetProperty(L"Node");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"Node01");

        property = instances[1]->GetProperty(L"Server");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"server1");
    }

    void TestDoGetInstanceGood()
    {
        SCXInstance instance;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");
        SCXProperty name_prop(L"Name", L"/opt/jboss-5.1.0.GA/");
        objectPath.AddKey(name_prop);
        SCXCallContext context(objectPath, eDirectSupport);

        m_asProvider->TestDoGetInstance(context, instance);
        
        /* Verify that the key is correct */
        CPPUNIT_ASSERT(1 == instance.NumberOfKeys());

        const SCXProperty* key = instance.GetKey(L"Name");
        CPPUNIT_ASSERT(0 != key);
        CPPUNIT_ASSERT(key->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(key->GetStrValue() == L"/opt/jboss-5.1.0.GA/");
        
        /* Verify the properties */
        CPPUNIT_ASSERT(14 == instance.NumberOfProperties());

        const SCXProperty* property = instance.GetProperty(L"HttpPort");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"8280");

        property = instance.GetProperty(L"HttpsPort");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"8643");

        property = instance.GetProperty(L"Version");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"5.1.0.GA");

        property = instance.GetProperty(L"MajorVersion");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"5");

        property = instance.GetProperty(L"Port");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instance.GetProperty(L"Protocol");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instance.GetProperty(L"DiskPath");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"/opt/jboss-5.1.0.GA/");

        property = instance.GetProperty(L"Type");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"JBoss");

        property = instance.GetProperty(L"IsDeepMonitored");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXBoolType);
        CPPUNIT_ASSERT(property->GetBoolValue() == false);

        property = instance.GetProperty(L"IsRunning");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXBoolType);
        CPPUNIT_ASSERT(property->GetBoolValue() == true);

        property = instance.GetProperty(L"Profile");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instance.GetProperty(L"Cell");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instance.GetProperty(L"Node");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");

        property = instance.GetProperty(L"Server");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(property->GetStrValue() == L"");
    }

    void TestDoGetInstanceNotFound()
    {
        SCXInstance instance;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");
        SCXProperty name_prop(L"Name", L"dummy");
        objectPath.AddKey(name_prop);
        SCXCallContext context(objectPath, eDirectSupport);

        CPPUNIT_ASSERT_THROW_MESSAGE( 
            "\"SCXCIMInstanceNotFound\" exception expected", 
            m_asProvider->TestDoGetInstance(context, instance),
            SCXCIMInstanceNotFound);
    }

    /** Test the DoEnumInstanceNames. It only has the key. */
    void TestDoEnumInstanceNames()
    {
        SCXInstanceCollection instances;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");
        SCXCallContext context(objectPath, eDirectSupport);

        m_asProvider->TestDoEnumInstanceNames(context, instances);
        
        CPPUNIT_ASSERT(2 == instances.Size());

        /* Verify that the key is correct */
        CPPUNIT_ASSERT(1 == instances[0]->NumberOfKeys());
        CPPUNIT_ASSERT(1 == instances[1]->NumberOfKeys());

        const SCXProperty* key = instances[0]->GetKey(L"Name");
        CPPUNIT_ASSERT(0 != key);
        CPPUNIT_ASSERT(key->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(key->GetStrValue() == L"/opt/jboss-5.1.0.GA/");

        key = instances[1]->GetKey(L"Name");
        CPPUNIT_ASSERT(0 != key);
        CPPUNIT_ASSERT(key->GetType() == SCXProperty::SCXStringType);
        CPPUNIT_ASSERT(key->GetStrValue() == L"AppSrv01-Node01Cell-Node01-server1");
        
    }

    void TestDoInvokeMethodNoAppServer()
    {
        SCXInstanceCollection instances;
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty id(L"id", L"dummy");
        SCXProperty deep(L"deep", true);

        args.AddProperty(id);
        args.AddProperty(deep);

        m_asProvider->TestDoInvokeMethod(context, L"SetDeepMonitoring", args, out, result);
        
        CPPUNIT_ASSERT(result.GetBoolValue() == false);
    }

    void TestDoInvokeMethodWrongMethod()
    {
        SCXInstanceCollection instances;
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");
        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty id(L"id", L"dummy");
        SCXProperty deep(L"deep", true);

        args.AddProperty(id);
        args.AddProperty(deep);

        CPPUNIT_ASSERT_THROW_MESSAGE( 
            "\"SCXProvCapNotRegistered\" exception expected", 
            m_asProvider->TestDoInvokeMethod(context, L"WrongMethod", args, out, result),
            SCXProvCapNotRegistered);
    }

    void TestDoInvokeMethodMissingArg()
    {
        SCXInstanceCollection instances;
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");
        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty id(L"id", L"dummy");

        args.AddProperty(id);

        CPPUNIT_ASSERT_THROW_MESSAGE( 
            "\"SCXInternalErrorException\" exception expected", 
            m_asProvider->TestDoInvokeMethod(context, L"SetDeepMonitoring", args, out, result),
            SCXInternalErrorException);

        // Verify that throwing this exception also asserts.
        SCXUNIT_ASSERTIONS_FAILED(1);
    }

    void TestDoInvokeMethodWrongArgType()
    {
        SCXInstanceCollection instances;
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");
        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty id(L"id", L"dummy");
        SCXProperty deep(L"deep", L"wrong");

        args.AddProperty(id);
        args.AddProperty(deep);

        CPPUNIT_ASSERT_THROW_MESSAGE( 
            "\"SCXInternalErrorException\" exception expected", 
            m_asProvider->TestDoInvokeMethod(context, L"SetDeepMonitoring", args, out, result),
            SCXInternalErrorException);

        // Verify that throwing this exception also asserts.
        SCXUNIT_ASSERTIONS_FAILED(1);
    }

    void TestDoInvokeMethodGood()
    {
        SCXInstanceCollection instances;
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_Application_Server");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty id(L"id", L"/opt/jboss-5.1.0.GA/");
        SCXProperty deep(L"deep", true);

        args.AddProperty(id);
        args.AddProperty(deep);

        m_asProvider->TestDoInvokeMethod(context, L"SetDeepMonitoring", args, out, result);
        
        CPPUNIT_ASSERT(result.GetBoolValue() == true);

        m_asProvider->TestDoEnumInstances(context, instances);
        
        CPPUNIT_ASSERT(2 == instances.Size());

        const SCXProperty* property = instances[0]->GetProperty(L"IsDeepMonitored");
        CPPUNIT_ASSERT(0 != property);
        CPPUNIT_ASSERT(property->GetType() == SCXProperty::SCXBoolType);
        CPPUNIT_ASSERT(property->GetBoolValue() == true);
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXASProviderTest );
