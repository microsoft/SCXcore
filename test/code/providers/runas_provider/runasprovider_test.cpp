/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the runas provider

   \date        2008-05-07 12:02

   Only tests the functionality of the provider class.
   The actual data gathering is tested by a separate class.

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxdirectoryinfo.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/strerror.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxprocess.h>
#include <scxsystemlib/scxsysteminfo.h>
#include <util/Base64Helper.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include "support/scxrunasconfigurator.h"
#include "support/runasprovider.h"
#include <list>
#include <unistd.h>
#include <sstream>
#include "SCX_OperatingSystem_Class_Provider.h"

using namespace SCXCoreLib;

// If you want to see extra information from executed commands/scripts
// set "c_EnableDebugOutput" to 1.
const int c_EnableDebugOutput = 0;

class SCXRunAsProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXRunAsProviderTest );
    CPPUNIT_TEST( TestDoInvokeMethodNoParams );
    CPPUNIT_TEST( TestDoInvokeMethodPartParams );
    CPPUNIT_TEST( TestDoInvokeMethodCommandOK );
    CPPUNIT_TEST( TestDoInvokeMethodCommandOKWithEmptyElevationType );
    CPPUNIT_TEST( TestDoInvokeMethodCommandOKWithElevationType );
    CPPUNIT_TEST( TestDoInvokeMethodCommandOKWithUppercaseElevationType );
    CPPUNIT_TEST( TestDoInvokeMethodCommandOKWithInvalidElevationType );
    CPPUNIT_TEST( TestDoInvokeMethodCommandFailed );
    CPPUNIT_TEST( TestDoInvokeMethodShellCommandOK );
    CPPUNIT_TEST( TestDoInvokeMethodShellCommandOKWithBase64 );
    CPPUNIT_TEST( TestDoInvokeMethodShellCommandOKWithSudoElevationType );
    CPPUNIT_TEST( TestDoInvokeMethodShellCommandOKWithEmptyElevationType );
    CPPUNIT_TEST( TestDoInvokeMethodShellCommandOKWithInvalidElevationType );
    CPPUNIT_TEST( TestDoInvokeMethodScriptOK );
    CPPUNIT_TEST( TestDoInvokeMethodScriptOKWithBase64 );
    CPPUNIT_TEST( TestDoInvokeMethodScriptOKWithSudoElevation );
    CPPUNIT_TEST( TestDoInvokeMethodScriptOKWithUpperCaseSudoElevation );
    CPPUNIT_TEST( TestDoInvokeMethodScriptOKWithEmptyElevation );
    CPPUNIT_TEST( TestDoInvokeMethodScriptFailed );
    CPPUNIT_TEST( TestDoInvokeMethodScriptNonSH );
    CPPUNIT_TEST( TestDoInvokeMethodScriptNoHashBang );
    CPPUNIT_TEST( TestDoInvokeMethodScriptTmpDir );
    CPPUNIT_TEST( TestDoInvokeMethodScriptDefaultTmpDir );
    CPPUNIT_TEST( TestDoInvokeMethodScriptNonDefaultTmpDir );
    CPPUNIT_TEST( TestChRoot );
    CPPUNIT_TEST( TestCWD );

    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodCommandOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodCommandOKWithEmptyElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodCommandOKWithElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodCommandOKWithUppercaseElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodCommandOKWithInvalidElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodCommandFailed, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodShellCommandOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodShellCommandOKWithBase64, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodShellCommandOKWithSudoElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodShellCommandOKWithEmptyElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodShellCommandOKWithInvalidElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptOKWithBase64, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptOKWithSudoElevation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptOKWithUpperCaseSudoElevation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptOKWithEmptyElevation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptFailed, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptNonSH, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDoInvokeMethodScriptNoHashBang, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestChRoot, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestCWD, SLOW);
    CPPUNIT_TEST_SUITE_END();

public:
    
    void RunCommand(std::wstring command, std::wstring caller)
    {
    	std::istringstream input;
    	std::ostringstream output, error;
    	int code = SCXCoreLib::SCXProcess::Run(command, input, output, error);
    	if(code !=0 || error.str().length() > 0) {
    		std::stringstream ss;
    		ss<<"Failure running command: "<<StrToUTF8(command)<<std::endl;
    		ss<<"Called by Method: "<<StrToUTF8(caller)<<std::endl;
    		if(code != 0) {
    			ss<<"Exit code: "<<code<<std::endl;
    		}
    		if(error.str().length() > 0) {
    			ss<<"Error: "<<error.str()<<std::endl;
    		}
    		CPPUNIT_ASSERT_EQUAL_MESSAGE(ss.str(), std::string(""), error.str());
    		CPPUNIT_ASSERT_EQUAL_MESSAGE(ss.str(), 0, code);
    	}
    }
    
    void setUp(void)
    {
        std::wstring errMsg;
        TestableContext context;
        SetUpAgent<mi::SCX_OperatingSystem_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );

        // The default CWD may not exist so we use the current instead.
        SCXCoreLib::SCXHandle<SCXCore::RunAsConfigurator> configurator(new SCXCore::RunAsConfigurator());
        configurator->SetCWD(SCXCoreLib::SCXFilePath(L"./"));
        if (0 == geteuid() && ! configurator->GetAllowRoot())
        {
            configurator->SetAllowRoot(true);
        }
        SCXCore::g_RunAsProvider.SetConfigurator(configurator);
    }

    void tearDown(void)
    {
        std::wstring errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_OperatingSystem_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
        RunCommand(L"rm -rf testChRoot", L"tearDown");
        RunCommand(L"rm -rf testCWD", L"tearDown");
        RunCommand(L"rm -rf testTmpDir", L"tearDown");
    }

    struct InvokeReturnData
    {
        MI_Sint32 returnCode;
        std::wstring stdOut;
        std::wstring stdErr;
        InvokeReturnData(): returnCode(-55555555){}
    };

    void VerifyInvokeResult(TestableContext &context, MI_Result result, InvokeReturnData &returnData,
        std::wstring errMsg)
    {
        if (c_EnableDebugOutput)
        {
            context.Print();
        }
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, result, context.GetResult());
        if (context.GetResult() == MI_RESULT_OK)
        {
            // We expect one instance to be returned.
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 1u, context.Size());
            bool miRet = context[0].GetProperty("MIReturn",
                CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg));
            returnData.returnCode = context[0].GetProperty(L"ReturnCode", CALL_LOCATION(errMsg)).
                GetValue_MISint32(CALL_LOCATION(errMsg));
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, miRet, (returnData.returnCode == 0));
            
            returnData.stdOut = context[0].GetProperty(L"StdOut", CALL_LOCATION(errMsg)).
                GetValue_MIString(CALL_LOCATION(errMsg));
            returnData.stdErr = context[0].GetProperty(L"StdErr", CALL_LOCATION(errMsg)).
                GetValue_MIString(CALL_LOCATION(errMsg));
                
            // Some common sense basic tests.
            if (!miRet)
            {
                CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, returnData.stdOut.empty());
                CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, returnData.stdErr.empty());
            }
        }
    }
    
    void ExecuteCommand(mi::SCX_OperatingSystem_ExecuteCommand_Class &param, MI_Result result, InvokeReturnData &returnData,
        std::wstring errMsg)
    {
        TestableContext context;
        mi::SCX_OperatingSystem_Class instanceName;
        mi::Module Module;
        mi::SCX_OperatingSystem_Class_Provider agent(&Module);
        agent.Invoke_ExecuteCommand(context, NULL, instanceName, param);
        context.WaitForResult();
        VerifyInvokeResult(context, result, returnData, CALL_LOCATION(errMsg));
    }

    void ExecuteShellCommand(mi::SCX_OperatingSystem_ExecuteShellCommand_Class &param, MI_Result result,
        InvokeReturnData &returnData, std::wstring errMsg)
    {
        TestableContext context;
        mi::SCX_OperatingSystem_Class instanceName;
        mi::Module Module;
        mi::SCX_OperatingSystem_Class_Provider agent(&Module);
        agent.Invoke_ExecuteShellCommand(context, NULL, instanceName, param);
        context.WaitForResult();
        VerifyInvokeResult(context, result, returnData, CALL_LOCATION(errMsg));
    }

    void ExecuteScript(mi::SCX_OperatingSystem_ExecuteScript_Class &param, MI_Result result, InvokeReturnData &returnData,
        std::wstring errMsg)
    {
        TestableContext context;
        mi::SCX_OperatingSystem_Class instanceName;
        mi::Module Module;
        mi::SCX_OperatingSystem_Class_Provider agent(&Module);
        agent.Invoke_ExecuteScript(context, NULL, instanceName, param);
        context.WaitForResult();
        VerifyInvokeResult(context, result, returnData, CALL_LOCATION(errMsg));
    }

    void TestDoInvokeMethodNoParams()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_INVALID_PARAMETER, returnData, CALL_LOCATION(errMsg));
        // Failure expected, nothing to be tested after this.
    }
    
    void TestDoInvokeMethodPartParams()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("ls");
        // Don't specify timeout in parameter list.
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_INVALID_PARAMETER, returnData, CALL_LOCATION(errMsg));
        // Failure expected, nothing to be tested after this.
    }
    
    void TestDoInvokeMethodCommandOK()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("echo Testing");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Testing\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestDoInvokeMethodCommandOKWithEmptyElevationType()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("echo Testing");
        param.timeout_value(0);
        param.ElevationType_value("");
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Testing\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestDoInvokeMethodCommandOKWithElevationType()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("echo Testing");
        param.timeout_value(0);
        param.ElevationType_value("sudo");
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Testing\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestDoInvokeMethodCommandOKWithUppercaseElevationType()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("echo Testing");
        param.timeout_value(0);
        param.ElevationType_value("SUdo");
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Testing\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestDoInvokeMethodCommandOKWithInvalidElevationType()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("echo Testing");
        param.timeout_value(0);
        param.ElevationType_value("aaaaaa");
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_INVALID_PARAMETER, returnData, CALL_LOCATION(errMsg));
        // Failure expected, nothing to be tested after this.
    }

    void TestDoInvokeMethodCommandFailed()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("/non-existing-directory/non-existing-command");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_MESSAGE(ERROR_MESSAGE, 0 != returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, returnData.stdOut.empty());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, returnData.stdErr.empty());
    }

    void TestDoInvokeMethodShellCommandOK()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteShellCommand_Class param;
        param.Command_value("echo 'a\nb\nc' | grep b");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteShellCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"b\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }


    void TestDoInvokeMethodShellCommandOKWithBase64()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteShellCommand_Class param;
        // Command is: "echo 'Howdy&There<Partner'"  (without quotes)
        param.Command_value("ZWNobyAnSG93ZHkmVGhlcmU8UGFydG5lcic=");
        param.timeout_value(0);
        param.b64encoded_value(true);
        InvokeReturnData returnData;
        ExecuteShellCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, std::wstring(L"Howdy&There<Partner\n"), returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, std::wstring(L""), returnData.stdErr);
    }

    void TestDoInvokeMethodShellCommandOKWithSudoElevationType()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteShellCommand_Class param;
        param.Command_value("echo 'a\nb\nc' | grep b");
        param.timeout_value(0);
        param.ElevationType_value("sudo");
        InvokeReturnData returnData;
        ExecuteShellCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"b\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestDoInvokeMethodShellCommandOKWithEmptyElevationType()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteShellCommand_Class param;
        param.Command_value("echo 'a\nb\nc' | grep b");
        param.timeout_value(0);
        param.ElevationType_value("");
        InvokeReturnData returnData;
        ExecuteShellCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"b\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestDoInvokeMethodShellCommandOKWithInvalidElevationType()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteShellCommand_Class param;
        param.Command_value("echo 'a\nb\nc' | grep b");
        param.timeout_value(0);
        param.ElevationType_value("aaaaaa");
        InvokeReturnData returnData;
        ExecuteShellCommand(param, MI_RESULT_INVALID_PARAMETER, returnData, CALL_LOCATION(errMsg));
        // Failure expected, nothing to be tested after this.
    }

    const char* GetScript()
    {
        return
            "#!/bin/sh\n"
            "# write something to stdout stream\n"
            "echo \"$3-$2-$1\"\n"
            "# and now create stderr output\n"
            "echo \"-$2-\">&2\n"
            "exit 0\n";
    }

    void TestDoInvokeMethodScriptOK()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(GetScript());
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"run-test-unit\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"-test-\n", returnData.stdErr);
    }

    void TestDoInvokeMethodScriptOKWithBase64()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        std::string command(GetScript());
        util::Base64Helper::Encode(command, command);
        param.Script_value(command.c_str());
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        param.b64encoded_value(true);
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"run-test-unit\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"-test-\n", returnData.stdErr);
    }

    void TestDoInvokeMethodScriptOKWithSudoElevation()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(GetScript());
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        param.ElevationType_value("sudo");
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"run-test-unit\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"-test-\n", returnData.stdErr);
    }

    void TestDoInvokeMethodScriptOKWithUpperCaseSudoElevation()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(GetScript());
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        param.ElevationType_value("SUDO");
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"run-test-unit\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"-test-\n", returnData.stdErr);
    }

    void TestDoInvokeMethodScriptOKWithEmptyElevation()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(GetScript());
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        param.ElevationType_value("");
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"run-test-unit\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"-test-\n", returnData.stdErr);
    }

    void TestDoInvokeMethodScriptFailed()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value("#!/bin/sh\n"
            "no_exisiting_command_echo \"$3-$2-$1\"\n"
            "# generate error code we can check later\n"
            "exit 7\n");
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 7, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, returnData.stdOut.empty());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, returnData.stdErr.empty());
    }

    void TestDoInvokeMethodScriptNonSH()
    {
        std::wstring errMsg;

        // Try to find bash.
        std::list<std::wstring> bashPaths;
        bashPaths.push_back(L"/bin/bash");
        bashPaths.push_back(L"/usr/bin/bash");
        bashPaths.push_back(L"/usr/local/bin/bash");
        std::wstring bash = L"";
        for (std::list<std::wstring>::const_iterator iter = bashPaths.begin();
             iter != bashPaths.end();
             ++iter)
        {
            if (SCXFile::Exists(*iter))
            {
                bash = *iter;
                bash.append(L"\n");
            }
        }

        CPPUNIT_ASSERT(L"" != bash);

        // This script will return what shell it is run in.
        std::string script = SCXCoreLib::StrToMultibyte(std::wstring(L"#!").append(bash).append(L"echo $BASH\n"));

        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(script.c_str());
        param.Arguments_value("");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, bash.c_str(), returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestDoInvokeMethodScriptNoHashBang()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(
            "# write something to stdout stream\n"
            "echo \"$3-$2-$1\"\n"
            "# and now create stderr output\n"
            "echo \"-$2-\">&2\n"
            "exit 0\n");
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"run-test-unit\n", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"-test-\n", returnData.stdErr);
    }
    
    void TestDoInvokeMethodScriptTmpDir()
    {
        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(
            		        "#!/bin/sh\n"
            		        "# Get location pointed by tmpdir\n"
            				"DIR=`dirname $0`\n"
            		        "echo $DIR\n"
            		        "exit 0\n");
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        InvokeReturnData returnData;
        SCXCore::g_RunAsProvider.SetTemporaryDirectory(L"/some/random/directory/");
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"/tmp\n", returnData.stdOut);
    }
    
    void TestDoInvokeMethodScriptDefaultTmpDir()
    {
    	std::wstring errMsg;
    	mi::SCX_OperatingSystem_ExecuteScript_Class param;
        param.Script_value(
                		    "#!/bin/sh\n"
                		    "# Get location pointed by tmpdir\n"
                			"DIR=`dirname $0`\n"
                		    "echo $DIR\n"
                		    "exit 0\n");
        param.Arguments_value("unit test run");
        param.timeout_value(0);
        InvokeReturnData returnData;
        SCXCore::g_RunAsProvider.SetTemporaryDirectory(L"/tmp/");
        ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"/tmp\n", returnData.stdOut);
    }
    
    void TestDoInvokeMethodScriptNonDefaultTmpDir()
    {
    	std::wstring errMsg;
    	mi::SCX_OperatingSystem_ExecuteScript_Class param;
    	param.Script_value(
    	                    "#!/bin/sh\n"
    	                	"# Get location pointed by tmpdir\n"
    	                	"DIR=`dirname $0`\n"
    	                	"echo $DIR\n"
    	                	"exit 0\n");
    	param.Arguments_value("unit test run");
    	param.timeout_value(0);
    	InvokeReturnData returnData;
    	
    	// As readlink is not available on all plaforms testing this with a non default
    	// directory
    	SCXDirectory::CreateDirectory(L"testTmpDir/");
    	SCXCore::g_RunAsProvider.SetTemporaryDirectory(L"./testTmpDir/");
    	
    	ExecuteScript(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
    	CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
    	CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"./testTmpDir\n", returnData.stdOut);
    }

    void TestChRoot()
    {
        RunCommand(L"rm -rf testChRoot", L"TestChRoot");
        SCXDirectory::CreateDirectory(L"testChRoot/");

        // Write our script out
        {
            std::ofstream ofs("testChRoot/setup.sh");
            ofs << "BASE=testChRoot" << std::endl;
            ofs << "FILESET=\"\\" << std::endl;
            ofs << "    /bin/touch \\" << std::endl;
            ofs << "    /lib64/ld-linux-x86-64.so.2 \\" << std::endl;
            ofs << "    /lib64/ld64.so.2 \\" << std::endl;
            ofs << "    /lib64/libc.so.6 \\" << std::endl;
            ofs << "    /lib64/libpthread.so.0 \\" << std::endl;
            ofs << "    /lib64/librt.so.1 \\" << std::endl;
            ofs << "    /lib64/tls/libc.so.6 \\" << std::endl;
            ofs << "    /lib/ld-linux.so.2 \\" << std::endl;
            ofs << "    /lib/libc.so.6 \\" << std::endl;
            ofs << "    /lib/libpthread.so.0 \\" << std::endl;
            ofs << "    /lib/librt.so.1 \\" << std::endl;
            ofs << "    /usr/lib/dld.sl \\" << std::endl;
            ofs << "    /usr/lib/hpux32/dld.so \\" << std::endl;
            ofs << "    /usr/lib/hpux32/libc.so.1 \\" << std::endl;
            ofs << "    /usr/lib/hpux32/libdl.so.1 \\" << std::endl;
            ofs << "    /usr/lib/hpux32/uld.so \\" << std::endl;
            ofs << "    /usr/lib/ld.so.1 \\" << std::endl;
            ofs << "    /usr/lib/libc.2 \\" << std::endl;
            ofs << "    /usr/lib/libc.a \\" << std::endl;
            ofs << "    /usr/lib/libcmd.so.1 \\" << std::endl;
            ofs << "    /usr/lib/libcrypt.a \\" << std::endl;
            ofs << "    /usr/lib/libc.so.1 \\" << std::endl;
            ofs << "    /usr/lib/libdld.2 \\" << std::endl;
            ofs << "    /usr/lib/libdl.so.1 \\" << std::endl;
#if !defined(aix)
            // AIX doesn't reliably know the 'uname -i' command ...
            ofs << "    /lib/`uname -i`-linux-gnu/libc.so.6 \\" << std::endl;
            ofs << "    /lib/`uname -i`-linux-gnu/librt.so.1 \\" << std::endl;
            ofs << "    /lib/`uname -i`-linux-gnu/libpthread.so.0 \\" << std::endl;
#endif
            ofs << "    \"" << std::endl;
            ofs << "" << std::endl;
            ofs << "" << std::endl;
            ofs << "rm -rf ${BASE} >/dev/null 2>&1" << std::endl;
            ofs << "for f in ${FILESET} ; do" << std::endl;
            ofs << "    test -r $f && mkdir -p ${BASE}/$(dirname $f) && cp -p $f ${BASE}/$f" << std::endl;
            ofs << "done" << std::endl;
            ofs << "exit 0" << std::endl;
        }

        RunCommand(L"chmod u+x testChRoot/setup.sh", L"TestChRoot");
        RunCommand(L"bash -c ./testChRoot/setup.sh", L"TestChRoot");

        SCXCoreLib::SCXHandle<SCXCore::RunAsConfigurator> configurator(new SCXCore::RunAsConfigurator());
        configurator->SetChRootPath(SCXCoreLib::SCXFilePath(L"./testChRoot"));
        configurator->SetCWD(SCXCoreLib::SCXFilePath(L"./"));
        if (0 == geteuid() && ! configurator->GetAllowRoot())
        {
            configurator->SetAllowRoot(true);
        }
        SCXCore::g_RunAsProvider.SetConfigurator(configurator);

        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("/bin/touch /ExecuteCommandWasHere");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT( SCXFile::Exists(L"testChRoot/ExecuteCommandWasHere") );
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }

    void TestCWD()
    {
        RunCommand(L"rm -rf testCWD", L"TestCWD");
        SCXDirectory::CreateDirectory(L"testCWD/");

        SCXCoreLib::SCXHandle<SCXCore::RunAsConfigurator> configurator(new SCXCore::RunAsConfigurator());
        configurator->SetCWD(SCXCoreLib::SCXFilePath(L"./testCWD/"));
        if (0 == geteuid() && ! configurator->GetAllowRoot())
        {
            configurator->SetAllowRoot(true);
        }
        SCXCore::g_RunAsProvider.SetConfigurator(configurator);

        std::wstring errMsg;
        mi::SCX_OperatingSystem_ExecuteCommand_Class param;
        param.Command_value("/bin/touch ./ExecuteCommandWasHere");
        param.timeout_value(0);
        InvokeReturnData returnData;
        ExecuteCommand(param, MI_RESULT_OK, returnData, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT( SCXFile::Exists(L"testCWD/ExecuteCommandWasHere") );
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 0, returnData.returnCode);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdOut);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", returnData.stdErr);
    }    
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXRunAsProviderTest );
