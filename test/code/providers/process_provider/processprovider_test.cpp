/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the process provider

   \date        2008-04-10 12:02

   Only tests the functionality of the provider class.
   The actual data gathering is tested by a separate class.

*/
/*----------------------------------------------------------------------------*/
// For getpid()
#include <unistd.h>

#include <testutils/providertestutils.h>

#include <scxcorelib/scxcmn.h>
#include <processprovider.h>
#include <testutils/scxunit.h>
#include <scxcorelib/scxexception.h>
#include "testableprocessprovider.h"

#include <iostream>

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace SCXProviderLib;

class SCXProcessProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXProcessProviderTest );
    CPPUNIT_TEST( testGetUnixProcessInstance );
    CPPUNIT_TEST( testGetUnixProcessStatisticalInformationInstance );
    CPPUNIT_TEST( testDoEnumInstanceNames );
    CPPUNIT_TEST( testDoEnumInstances );
    CPPUNIT_TEST( testDoGetInstance );
    CPPUNIT_TEST( testDoInvokeMethod );
    CPPUNIT_TEST( DoInvokeMethodThrowsUnknownResourceException );
    CPPUNIT_TEST( testGetParametersAsPropertyVector );

    SCXUNIT_TEST_ATTRIBUTE(testGetUnixProcessInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testGetUnixProcessStatisticalInformationInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoEnumInstanceNames, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoEnumInstances, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoGetInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethod, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(DoInvokeMethodThrowsUnknownResourceException, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testGetParametersAsPropertyVector, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    /* Add any data commonly used in several tests as members here. */
    SCXCoreLib::SCXHandle<TestableProcessProvider> pp;

public:
    void setUp(void)
    {
        /* This method will be called once before each test function. */
        pp = new TestableProcessProvider();
        pp->TestDoInit();
        pp->ForceSample(); // make sure we always have data to work on.
    }

    void tearDown(void)
    {
        /* This method will be called once after each test function. */
        pp->TestDoCleanup();
        pp = 0;
    }

    void testDoEnumInstanceNames()
    {
        try {
            SCXInstanceCollection instances;

            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_UnixProcess");
            SCXCallContext context(objectPath, eDirectSupport);

            pp->TestDoEnumInstanceNames(context, instances);

            CPPUNIT_ASSERT(instances.Size() > 10);
            CPPUNIT_ASSERT(6 == instances[0]->NumberOfKeys());
            CPPUNIT_ASSERT(L"Handle" == instances[0]->GetKey(0)->GetName());

        } catch (SCXAccessViolationException&) {
            // Silently skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoEnumInstanceNames: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        }
    }

    void testDoEnumInstances()
    {
        try {
            SCXInstanceCollection instances;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_UnixProcessStatisticalInformation");
            SCXCallContext context(objectPath, eDirectSupport);

            pp->TestDoEnumInstances(context, instances);

            CPPUNIT_ASSERT(instances.Size() > 10);
            CPPUNIT_ASSERT(7 == instances[0]->NumberOfKeys());

        } catch (SCXAccessViolationException&) {
            // Silently skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoEnumInstances: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        }
    }

    void testGetUnixProcessInstance()
    {
        try {
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"CreationClassName");
            keyNames.push_back(L"Handle");
            keyNames.push_back(L"CSName");
            keyNames.push_back(L"CSCreationClassName");
            keyNames.push_back(L"OSName");
            keyNames.push_back(L"OSCreationClassName");
            CPPUNIT_ASSERT(pp->VerifyGetInstanceByCompleteKeySuccess(L"SCX_UnixProcess", keyNames));
            CPPUNIT_ASSERT(pp->VerifyGetInstanceByPartialKeyFailure(L"SCX_UnixProcess", keyNames));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }

    void testGetUnixProcessStatisticalInformationInstance()
    {
        try {
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"Name");
            keyNames.push_back(L"Handle");
            keyNames.push_back(L"CSName");
            keyNames.push_back(L"CSCreationClassName");
            keyNames.push_back(L"OSName");
            keyNames.push_back(L"OSCreationClassName");
            keyNames.push_back(L"ProcessCreationClassName");
            CPPUNIT_ASSERT(pp->VerifyGetInstanceByCompleteKeySuccess(L"SCX_UnixProcessStatisticalInformation", keyNames,
                    TestableProvider::eKeysOnly));
            CPPUNIT_ASSERT(pp->VerifyGetInstanceByPartialKeyFailure(L"SCX_UnixProcessStatisticalInformation", keyNames,
                    TestableProvider::eKeysOnly));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }

    void testDoGetInstance()
    {
        try {
            const SCXProperty* nameProperty = NULL;

            SCXInstance instance;
            SCXInstance objectPath;

            BaseProvider::AddScopingOperatingSystemKeys(objectPath);
            objectPath.AddKey(SCXProperty(SCXProperty(L"CreationClassName", L"SCX_UnixProcess")));
            objectPath.AddKey(SCXProperty(SCXProperty(L"Handle", StrFrom(getpid()))));
            objectPath.SetCimClassName(L"SCX_UnixProcess");


            SCXCallContext context(objectPath, eDirectSupport);

            // Get the testrunner process instance
            pp->TestDoGetInstance(context, instance);

            CPPUNIT_ASSERT((nameProperty = instance.GetProperty(L"Name")) != NULL);

            // And the name property should be "testrunner"
            ostringstream msg;
            msg << "nameProperty->GetStrValue: " << StrToMultibyte(nameProperty->GetStrValue()) << endl;
            CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), nameProperty->GetStrValue() == L"testrunner");

        } catch (SCXAccessViolationException&) {
            // Silently skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoGetInstance: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        }
    }

    void testDoInvokeMethod ()
    {
        try {
            SCXArgs args;
            SCXArgs out;        // Not used
            SCXProperty result;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_UnixProcess");

            SCXCallContext context(objectPath, eDirectSupport);

            SCXProperty resource(L"resource", L"CPUTime");

            SCXProperty count(L"count", static_cast<unsigned short>(10));

            args.AddProperty(resource);
            args.AddProperty(count);

            pp->TestDoInvokeMethod(context, L"TopResourceConsumers", args, out, result);

            CPPUNIT_ASSERT(! result.GetStrValue().empty());

            // We just happen to know that the first characters are a newline followed by "PID"
            CPPUNIT_ASSERT(result.GetStrValue().substr(1, 3) == L"PID");

            // Print out the top resource consumers. Saved for debug.
            // std::wcout << result.GetStrValue() << std::endl;

        } catch (SCXAccessViolationException&) {
            // Silently skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoInvokeMethod: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        }
    }

    void DoInvokeMethodThrowsUnknownResourceException()
    {
        SCXArgs args;
        SCXArgs out;        // Not used
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_UnixProcess");
        
        SCXCallContext context(objectPath, eDirectSupport);
        
        SCXProperty resource(L"resource", L"InvalidResource");
        SCXProperty count(L"count", static_cast<unsigned short>(10));
        
        args.AddProperty(resource);
        args.AddProperty(count);
        
        CPPUNIT_ASSERT_THROW(pp->TestDoInvokeMethod(context, L"TopResourceConsumers", args, out, result), 
                             ProcessProvider::UnknownResourceException);
    }

    void testGetParametersAsPropertyVector()
    {
        try {
            const SCXProperty* paramsProperty = NULL;

            ;
            SCXInstance instance;
            SCXInstance objectPath;

            BaseProvider::AddScopingOperatingSystemKeys(objectPath);
            objectPath.AddKey(SCXProperty(L"Handle", StrFrom(getpid())));
            objectPath.AddKey(SCXProperty(L"CreationClassName", L"SCX_UnixProcess"));
            objectPath.SetCimClassName(L"SCX_UnixProcess");

            SCXCallContext context(objectPath, eDirectSupport);

            // Get the testrunner process instance
            pp->TestDoGetInstance(context, instance);

            CPPUNIT_ASSERT_NO_THROW(paramsProperty = instance.GetProperty(L"Parameters"));
#if defined(linux) || defined(aix) || defined(hpux) || defined(sun)
            CPPUNIT_ASSERT(NULL != paramsProperty);

            CPPUNIT_ASSERT_EQUAL(SCXProperty::SCXArrayType, paramsProperty->GetType());
#else
            CPPUNIT_ASSERT(NULL == paramsProperty);
#endif
        } catch (SCXAccessViolationException&) {
            // Silently skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        } catch (SCXException& e) {
            std::wcout << L"\nException in testGetParametersAsPropertyVector: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_FAIL("Exception");
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXProcessProviderTest );
