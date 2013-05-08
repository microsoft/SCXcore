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
#include <scxsystemlib/scxostypeinfo.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include "SCX_UnixProcess_Class_Provider.h"
#include "SCX_UnixProcessStatisticalInformation_Class_Provider.h"

using namespace SCXCoreLib;

class SCXUnixProcessKeyTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXUnixProcessKeyTest );

    CPPUNIT_TEST( TestUnixProcessEnumerateKeysOnly );
    CPPUNIT_TEST( TestUnixProcessStatisticalInformationEnumerateKeysOnly );

    CPPUNIT_TEST( TestUnixProcessCheckKeyValues );
    CPPUNIT_TEST( TestUnixProcessStatisticalInformationCheckKeyValues );

    CPPUNIT_TEST( TestVerifyKeyCompletePartialUnixProcess );
    CPPUNIT_TEST( TestVerifyKeyCompletePartialUnixProcessStatisticalInformation );


    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessEnumerateKeysOnly, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessStatisticalInformationEnumerateKeysOnly, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessCheckKeyValues, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessStatisticalInformationCheckKeyValues, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartialUnixProcess, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartialUnixProcessStatisticalInformation, SLOW);

    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNamesUP;
    std::vector<std::wstring> m_keyNamesUPS;

public:
    void setUp(void)
    {
        std::wostringstream errMsg;
        SetUpAgent<mi::SCX_UnixProcess_Class_Provider>(CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));
        
        m_keyNamesUP.push_back(L"CSCreationClassName");
        m_keyNamesUP.push_back(L"CSName");
        m_keyNamesUP.push_back(L"OSCreationClassName");
        m_keyNamesUP.push_back(L"OSName");
        m_keyNamesUP.push_back(L"CreationClassName");
        m_keyNamesUP.push_back(L"Handle");

        m_keyNamesUPS.push_back(L"Name");
        m_keyNamesUPS.push_back(L"CSCreationClassName");
        m_keyNamesUPS.push_back(L"CSName");
        m_keyNamesUPS.push_back(L"OSCreationClassName");
        m_keyNamesUPS.push_back(L"OSName");
        m_keyNamesUPS.push_back(L"Handle");
        m_keyNamesUPS.push_back(L"ProcessCreationClassName");
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TearDownAgent<mi::SCX_UnixProcess_Class_Provider>(CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));
    }

    void TestUnixProcessEnumerateKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_UnixProcess_Class_Provider>(
            m_keyNamesUP, context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationEnumerateKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(
            m_keyNamesUPS, context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessCheckKeyValues()
    {
        std::wostringstream errMsg;
        TestableContext context;

        std::vector<std::wstring> keysSame;// Unused.

        std::vector<std::wstring> keyNames;
        std::vector<std::wstring> keyValues;
        keyNames.push_back(L"CSCreationClassName");
        keyValues.push_back(L"SCX_ComputerSystem");
        keyNames.push_back(L"CSName");
        keyValues.push_back(GetFQHostName(CALL_LOCATION(errMsg)));
        keyNames.push_back(L"OSCreationClassName");
        keyValues.push_back(L"SCX_OperatingSystem");
        keyNames.push_back(L"OSName");
        keyValues.push_back(GetDistributionName(CALL_LOCATION(errMsg)));
        keyNames.push_back(L"CreationClassName");
        keyValues.push_back(L"SCX_UnixProcess");
        StandardTestCheckKeyValues<mi::SCX_UnixProcess_Class_Provider>(
            keyNames, keyValues, keysSame, context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationCheckKeyValues()
    {
        std::wostringstream errMsg;
        TestableContext context;

        std::vector<std::wstring> keysSame;// Unused.

        std::vector<std::wstring> keyNames;
        std::vector<std::wstring> keyValues;
        keyNames.push_back(L"CSCreationClassName");
        keyValues.push_back(L"SCX_ComputerSystem");
        keyNames.push_back(L"CSName");
        keyValues.push_back(GetFQHostName(CALL_LOCATION(errMsg)));
        keyNames.push_back(L"OSCreationClassName");
        keyValues.push_back(L"SCX_OperatingSystem");
        keyNames.push_back(L"OSName");
        keyValues.push_back(GetDistributionName(CALL_LOCATION(errMsg)));
        keyNames.push_back(L"ProcessCreationClassName");
        keyValues.push_back(L"SCX_UnixProcessStatisticalInformation");
        StandardTestCheckKeyValues<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(
            keyNames, keyValues, keysSame, context, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialUnixProcess()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_UnixProcess_Class_Provider,
                mi::SCX_UnixProcess_Class>(m_keyNamesUP, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialUnixProcessStatisticalInformation()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_UnixProcessStatisticalInformation_Class_Provider,
                mi::SCX_UnixProcessStatisticalInformation_Class>(m_keyNamesUPS, CALL_LOCATION(errMsg));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXUnixProcessKeyTest );
