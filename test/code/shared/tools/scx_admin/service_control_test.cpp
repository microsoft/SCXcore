/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Service control test class.

    \date        2008-08-28 08:22:00

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <servicecontrol.h>
#include <testutils/scxunit.h>

#include <scxcorelib/scxexception.h>

class TestServiceControlCimom : public SCX_CimomServiceControl
{
public:
    TestServiceControlCimom() 
        : SCX_CimomServiceControl()
    {

    }
    
    virtual ~TestServiceControlCimom() { }

    std::wstring GetName() { return m_name; }
    std::wstring GetStart() { return m_start; }
    std::wstring GetStop() { return m_stop; }
};

class TestServiceControlProvider : public SCX_ProviderServiceControl
{
public:
    TestServiceControlProvider()
        : SCX_ProviderServiceControl()
    {

    }

    TestServiceControlProvider(const std::wstring& name)
        : SCX_ProviderServiceControl()
    {
        m_name = name;
    }

    virtual ~TestServiceControlProvider() { }

    std::wstring GetName() { return m_name; }
};

class ServiceControlTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ServiceControlTest );
    CPPUNIT_TEST( ServiceNamesCorrect );
    CPPUNIT_TEST( StartScriptForCimdOK );
    CPPUNIT_TEST( StopScriptForCimdOK );
    CPPUNIT_TEST( ServiceStartRunsScriptOK );
    CPPUNIT_TEST( ServiceStopRunsScriptOK );
    CPPUNIT_TEST( ServiceRestartRunsScriptOK );
    CPPUNIT_TEST( ServiceStatusForRunningProcessOK );
    CPPUNIT_TEST( ServiceStatusForStoppedProcessOK );
    CPPUNIT_TEST( ServiceCommandNotFound );
    CPPUNIT_TEST( ServiceCommandFails );
    CPPUNIT_TEST( StartProviderShouldFail );
    CPPUNIT_TEST( RestartProviderShouldOnlyStop );
    CPPUNIT_TEST( StatusProviderWhenNotRunningOK );
    CPPUNIT_TEST( StatusProviderWhenRunningOK );
    CPPUNIT_TEST( StopProviderWhenNotStartedOK );

    SCXUNIT_TEST_ATTRIBUTE(ServiceStartRunsScriptOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(ServiceStopRunsScriptOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(ServiceRestartRunsScriptOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(ServiceStatusForRunningProcessOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(ServiceStatusForStoppedProcessOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(ServiceCommandNotFound, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(ServiceCommandFails, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(RestartProviderShouldOnlyStop, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(StatusProviderWhenNotRunningOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(StatusProviderWhenRunningOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(StopProviderWhenNotStartedOK, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:

public:
    void setUp(void)
    {

    }

    void tearDown(void)
    {

    }

    void ServiceNamesCorrect(void)
    {
        TestServiceControlCimom cimom;
        TestServiceControlProvider provider;
        CPPUNIT_ASSERT(cimom.GetName() == L"omiserver");
        CPPUNIT_ASSERT(provider.GetName() == L"omiagent");
    }

    void StartScriptForCimdOK(void)
    {
        TestServiceControlCimom svc;
#if defined(aix)
        CPPUNIT_ASSERT(svc.GetStart() == L"/usr/bin/startsrc -s scx-cimd");
#elif defined(hpux)
        CPPUNIT_ASSERT(svc.GetStart() == L"/sbin/init.d/scx-cimd start");
#elif defined(linux)
        CPPUNIT_ASSERT(svc.GetStart() == L"/etc/init.d/scx-cimd start");
#elif defined(macos)
        CPPUNIT_ASSERT(svc.GetStart() == L"launchctl load -w /Library/LaunchDaemons/com.microsoft.scx-cimd.plist");
#elif defined(sun)
#if (PF_MAJOR == 5) && (PF_MINOR > 9)
        CPPUNIT_ASSERT(svc.GetStart() == L"/usr/sbin/svcadm -v enable -s svc:/application/management/scx-cimd");
#else
        CPPUNIT_ASSERT(svc.GetStart() == L"/etc/init.d/scx-cimd start");
#endif
#else
        CPPUNIT_FAIL("Platform not implemented");
#endif
    }

    void StopScriptForCimdOK(void)
    {
        TestServiceControlCimom svc;
#if defined(aix)
        CPPUNIT_ASSERT(svc.GetStop() == L"/usr/bin/stopsrc -c -s scx-cimd");
#elif defined(hpux)
        CPPUNIT_ASSERT(svc.GetStop() == L"/sbin/init.d/scx-cimd stop");
#elif defined(linux)
        CPPUNIT_ASSERT(svc.GetStop() == L"/etc/init.d/scx-cimd stop");
#elif defined(macos)
        CPPUNIT_ASSERT(svc.GetStop() == L"launchctl unload -w /Library/LaunchDaemons/com.microsoft.scx-cimd.plist");
#elif defined(sun)
#if (PF_MAJOR == 5) && (PF_MINOR > 9)
        CPPUNIT_ASSERT(svc.GetStop() == L"/usr/sbin/svcadm -v disable -s svc:/application/management/scx-cimd");
#else
        CPPUNIT_ASSERT(svc.GetStop() == L"/etc/init.d/scx-cimd stop");
#endif
#else
        CPPUNIT_FAIL("Platform not implemented");
#endif
    }

    void ServiceStartRunsScriptOK(void)
    {
        SCX_AdminServiceControl svc(L"dummy", L"echo START", L"echo STOP");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Start(info));
        CPPUNIT_ASSERT(info == L"START\n");
    }

    void ServiceStopRunsScriptOK(void)
    {
        SCX_AdminServiceControl svc(L"dummy", L"echo START", L"echo STOP");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Stop(info));
        CPPUNIT_ASSERT(info == L"STOP\n");
    }

    void ServiceRestartRunsScriptOK(void)
    {
        SCX_AdminServiceControl svc(L"dummy", L"echo START", L"echo STOP");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Restart(info));
        CPPUNIT_ASSERT(info == L"STOP\nSTART\n");
    }

    void ServiceStatusForRunningProcessOK(void)
    {
        SCX_AdminServiceControl svc(L"testrunner", L"echo START", L"echo STOP");
        std::wstring info;

        CPPUNIT_ASSERT(svc.Status(info));

        std::ostringstream msg;
        msg << "Info: " << StrToMultibyte(info) << std::endl;

        CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), info.find(L"testrunner") != std::wstring::npos);
        CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), info.find(L"running") != std::wstring::npos);
        CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), info.find(L"stopped") == std::wstring::npos);
    }

    void ServiceStatusForStoppedProcessOK(void)
    {
        SCX_AdminServiceControl svc(L"process_not_started", L"echo START", L"echo STOP");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Status(info));
        CPPUNIT_ASSERT(info.find(L"process_not_started") != std::wstring::npos);
        CPPUNIT_ASSERT(info.find(L"stopped") != std::wstring::npos);
        CPPUNIT_ASSERT(info.find(L"running") == std::wstring::npos);
    }

    void ServiceCommandNotFound(void)
    {
        SCX_AdminServiceControl svc(L"not_found", L"./script_not_found.sh start", L"./script_not_found.sh stop");
        std::wstring info;
        CPPUNIT_ASSERT_THROW(svc.Start(info), SCXAdminException);
        CPPUNIT_ASSERT_THROW(svc.Stop(info), SCXAdminException);
        CPPUNIT_ASSERT_THROW(svc.Restart(info), SCXAdminException);
    }

    void ServiceCommandFails(void)
    {
        SCX_AdminServiceControl svc(L"failing_process", L"grep dummy dummy.txt", L"grep dummy dummy.txt");
        std::wstring info;
        CPPUNIT_ASSERT_THROW(svc.Start(info), SCXAdminException);
        CPPUNIT_ASSERT_THROW(svc.Stop(info), SCXAdminException);
        CPPUNIT_ASSERT_THROW(svc.Restart(info), SCXAdminException);
        // verify the return code is part of exception description
        try {
            svc.Start(info);
            CPPUNIT_FAIL("SCXAdminException not thrown");
        } catch (SCXAdminException& e) {
            CPPUNIT_ASSERT(e.What().find(L"RETURN CODE") != std::wstring::npos);
        }
    }

    void StartProviderShouldFail()
    {
        SCX_ProviderServiceControl svc;
        std::wstring info;
        CPPUNIT_ASSERT_MESSAGE("Start is not supported for providers", ! svc.Start(info));
    }

    void RestartProviderShouldOnlyStop()
    {
        TestServiceControlProvider svc(L"process_not_started");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Restart(info));
        CPPUNIT_ASSERT(info.find(L"process_not_started") != std::wstring::npos);
        CPPUNIT_ASSERT(info.find(L"0 instances stopped") != std::wstring::npos);
        CPPUNIT_ASSERT(info.find(L"not started") != std::wstring::npos);
    }

    void StatusProviderWhenNotRunningOK()
    {
        TestServiceControlProvider svc(L"process_not_started");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Status(info));
        CPPUNIT_ASSERT(info.find(L"process_not_started") != std::wstring::npos);
        CPPUNIT_ASSERT(info.find(L"stopped") != std::wstring::npos);
        CPPUNIT_ASSERT(info.find(L"running") == std::wstring::npos);
    }

    void StatusProviderWhenRunningOK()
    {
        TestServiceControlProvider svc(L"testrunner");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Status(info));

        std::ostringstream msg;
        msg << "Info: " << StrToMultibyte(info) << std::endl;

        CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), info.find(L"testrunner") != std::wstring::npos);
        CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), info.find(L"stopped") == std::wstring::npos);
        CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), info.find(L"running") != std::wstring::npos);
    }

    void StopProviderWhenNotStartedOK()
    {
        TestServiceControlProvider svc(L"process_not_started");
        std::wstring info;
        CPPUNIT_ASSERT(svc.Stop(info));
        CPPUNIT_ASSERT(info.find(L"process_not_started") != std::wstring::npos);
        CPPUNIT_ASSERT(info.find(L"0 instances stopped") != std::wstring::npos);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( ServiceControlTest );
