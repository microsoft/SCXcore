/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests the keys of the SCX_UnixProcess.

   \date        2008-09-23 10:26:18

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <source/code/providers/process_provider/processprovider.h>
#include <testutils/providertestutils.h>

#include <testutils/scxunit.h>
#include <scxcorelib/scxexception.h>
#include "testableprocessprovider.h"

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace SCXProviderLib;


class SCXUnixProcessKeyTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXUnixProcessKeyTest );
    CPPUNIT_TEST( testHandleIsKey );
    CPPUNIT_TEST( testCreationClassName );
    CPPUNIT_TEST( testOSNameIsSameForAll );
    CPPUNIT_TEST( testOSCreationClassName );
    CPPUNIT_TEST( testCSNameIsSameForAll );
    CPPUNIT_TEST( testCSCreationClassName );

    CPPUNIT_TEST( testStatisticalInformationHandleIsKey );
    CPPUNIT_TEST( testStatisticalInformationNameIsKey );
    CPPUNIT_TEST( testStatisticalInformationCreationClassName );
    CPPUNIT_TEST( testStatisticalInformationOSNameIsSameForAll );
    CPPUNIT_TEST( testStatisticalInformationOSCreationClassName );
    CPPUNIT_TEST( testStatisticalInformationCSNameIsSameForAll );
    CPPUNIT_TEST( testStatisticalInformationCSCreationClassName );

    SCXUNIT_TEST_ATTRIBUTE(testHandleIsKey, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testOSNameIsSameForAll, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testOSCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testCSNameIsSameForAll, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testCSCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testStatisticalInformationHandleIsKey, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testStatisticalInformationNameIsKey, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testStatisticalInformationCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testStatisticalInformationOSNameIsSameForAll, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testStatisticalInformationOSCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testStatisticalInformationCSNameIsSameForAll, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testStatisticalInformationCSCreationClassName, SLOW);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    void GivenAllInstanceNamesEnumerated(std::wstring classToEnumerate, SCXInstanceCollection& instances)
    {
        SCXCoreLib::SCXHandle<TestableProcessProvider> pp( new TestableProcessProvider() );
        pp->TestDoInit();
        pp->ForceSample(); // make sure we always have data to work on.

        SCXInstance objectPath;
        objectPath.SetCimClassName(classToEnumerate);
        SCXCallContext context(objectPath, eDirectSupport);
        pp->TestDoEnumInstanceNames(context, instances);
        pp->TestDoCleanup();
    }

    /**
        Tests if key is a key for each instance of classToCheck.
     */
    void testIsKey(std::wstring classToCheck, std::wstring key)
    {
        SCXInstanceCollection instances;

        try {
            GivenAllInstanceNamesEnumerated(classToCheck, instances);
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
            return;
        }

        for(unsigned int i = 0; i < instances.Size(); ++i)
        {
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Could not find key: ", key)), NULL != instances[i]->GetKey(key));
        }
    }

    /**
        Tests if key has value "value" for each instance of classToCheck.
     */
    void testKeyValueEquals(std::wstring classToCheck, std::wstring key, std::wstring value)
    {
        SCXInstanceCollection instances;

        try {
            GivenAllInstanceNamesEnumerated(classToCheck, instances);
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
            return;
        }

        for(unsigned int i = 0; i < instances.Size(); ++i)
        {
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Could not find key: ", key)), NULL != instances[i]->GetKey(key));
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Value of \"", key).append(L"\" is not \"").append(value).append(L"\"")),
                                   value == instances[i]->GetKey(key)->GetStrValue());
        }
    }

    /**
        Tests if key has the same non-empty value for each instance of classToCheck.
     */
    void testKeyIsSameForAllInstances(std::wstring classToCheck, std::wstring key)
    {
        SCXInstanceCollection instances;

        try {
            GivenAllInstanceNamesEnumerated(classToCheck, instances);
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
            return;
        }

        CPPUNIT_ASSERT(NULL != instances[0]->GetKey(key));
        std::wstring value = instances[0]->GetKey(key)->GetStrValue();
        CPPUNIT_ASSERT(L"" != value);
        for(unsigned int i = 1; i < instances.Size(); ++i)
        {
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Could not find key: ", key)), NULL != instances[i]->GetKey(key));
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Value of \"", key).append(L"\" is not \"").append(value).append(L"\"")),
                                   value == instances[i]->GetKey(key)->GetStrValue());
        }
    }

    void testHandleIsKey()
    {
        testIsKey(L"SCX_UnixProcess", L"Handle");
    }

    void testCreationClassName()
    {
        testKeyValueEquals(L"SCX_UnixProcess", L"CreationClassName", L"SCX_UnixProcess");
    }

    void testOSNameIsSameForAll()
    {
        testKeyIsSameForAllInstances(L"SCX_UnixProcess", L"OSName");
    }

    void testOSCreationClassName()
    {
        testKeyValueEquals(L"SCX_UnixProcess", L"OSCreationClassName", L"SCX_OperatingSystem");
    }

    void testCSNameIsSameForAll()
    {
        testKeyIsSameForAllInstances(L"SCX_UnixProcess", L"CSName");
    }

    void testCSCreationClassName()
    {
        testKeyValueEquals(L"SCX_UnixProcess", L"CSCreationClassName", L"SCX_ComputerSystem");
    }

    void testStatisticalInformationHandleIsKey()
    {
        testIsKey(L"SCX_UnixProcessStatisticalInformation", L"Handle");
    }

    void testStatisticalInformationNameIsKey()
    {
        testIsKey(L"SCX_UnixProcessStatisticalInformation", L"Name");
    }

    void testStatisticalInformationCreationClassName()
    {
        testKeyValueEquals(L"SCX_UnixProcessStatisticalInformation", L"ProcessCreationClassName", L"SCX_UnixProcessStatisticalInformation");
    }

    void testStatisticalInformationOSNameIsSameForAll()
    {
        testKeyIsSameForAllInstances(L"SCX_UnixProcessStatisticalInformation", L"OSName");
    }

    void testStatisticalInformationOSCreationClassName()
    {
        testKeyValueEquals(L"SCX_UnixProcessStatisticalInformation", L"OSCreationClassName", L"SCX_OperatingSystem");
    }

    void testStatisticalInformationCSNameIsSameForAll()
    {
        testKeyIsSameForAllInstances(L"SCX_UnixProcessStatisticalInformation", L"CSName");
    }

    void testStatisticalInformationCSCreationClassName()
    {
        testKeyValueEquals(L"SCX_UnixProcessStatisticalInformation", L"CSCreationClassName", L"SCX_ComputerSystem");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXUnixProcessKeyTest );
