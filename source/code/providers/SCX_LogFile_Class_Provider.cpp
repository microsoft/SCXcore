/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_LogFile_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-22-2013 17:48:44
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_LogFile_Class_Provider.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxfilesystem.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/stringaid.h>

#include "support/logfileprovider.h"
#include "support/scxcimutils.h"

#include <iostream>

using namespace SCXCoreLib;

MI_BEGIN_NAMESPACE

static void InsertOneString(
    Context& context,
    std::vector<mi::String>& stringArray,
    const std::wstring& in)
{
    mi::String str( SCXCoreLib::StrToUTF8(in).c_str() );
    stringArray.push_back( str );
}

SCX_LogFile_Class_Provider::SCX_LogFile_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_LogFile_Class_Provider::~SCX_LogFile_Class_Provider()
{
}

void SCX_LogFile_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::LogFileProvider::Lock"));
        SCXCore::g_LogFileProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_LogFileProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_LogFile_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_LogFile_Class_Provider::Load", SCXCore::g_LogFileProvider.GetLogHandle() );
}

void SCX_LogFile_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::LogFileProvider::Lock"));
        SCXCore::g_LogFileProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_LogFile_Class_Provider::Load", SCXCore::g_LogFileProvider.GetLogHandle() );
}

void SCX_LogFile_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LogFile_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LogFile_Class& instanceName,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LogFile_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LogFile_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LogFile_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LogFile_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LogFile_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LogFile_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LogFile_Class_Provider::Invoke_GetMatchedRows(
    Context& context,
    const String& nameSpace,
    const SCX_LogFile_Class& instanceName,
    const SCX_LogFile_GetMatchedRows_Class& in)
{
    /*
     * To return data, we have to post a single instance that contains an array of strings
     * MOF format: [OUT, ArrayType("Ordered")] string rows[]
     *
     * Here's some sample code that will do the trick:
     *
     * SCX_LogFile_GetMatchedRows_Class inst;
     * std::vector<mi::String> fakeData;
     *
     * fakeData.push_back( mi::String("data1") );
     * fakeData.push_back( mi::String("data2") );
     *
     * StringA rows(&fakeData[0], static_cast<MI_Uint32>(fakeData.size()));
     * inst.rows_value( rows );
     *
     * context.Post(inst);
     * context.Post(MI_RESULT_OK);
     */

    SCXCoreLib::SCXLogHandle log = SCXCore::g_LogFileProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::LogFileProvider::Lock"));

        // Validate that we have mandatory arguments
        if ( !in.filename_exists() || !in.regexps_exists() || !in.qid_exists() )
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        // Get the arguments:
        //   filename      : string
        //   regexps       : string array
        //   qid           : string
        //   elevationType : [Optional] string
        //   initialize    : [Optional] boolean

        std::wstring filename = SCXCoreLib::StrFromMultibyte( in.filename_value().Str() );
        const StringA regexps_sa = in.regexps_value();
        std::wstring qid = SCXCoreLib::StrFromMultibyte( in.qid_value().Str() );
        std::wstring elevationType = SCXCoreLib::StrFromMultibyte( in.elevationType_value().Str() );
        int initializeFlag = in.initialize_exists() && in.initialize_value();

        bool fPerformElevation = false;
        if ( elevationType.length() )
        {
            if ( SCXCoreLib::StrToLower(elevationType) != L"sudo" )
            {
                context.Post(MI_RESULT_INVALID_PARAMETER);
                return;
            }

            fPerformElevation = true;
        }

        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCXLogFileProvider::InvokeMatchedRows - filename = ", filename));
        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCXLogFileProvider::InvokeMatchedRows - qid = ", qid));
        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCXLogFileProvider::InvokeMatchedRows - regexp count = ", regexps_sa.GetSize()));
        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCXLogFileProvider::InvokeMatchedRows - elevate = ", elevationType));
        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCXLogFileProvider::InvokeMatchedRows - initialize = ", initializeFlag));

        // Extract and parse the regular expressions

        std::vector<SCXRegexWithIndex> regexps;
        std::wstring invalid_regex(L"");
            
        for (size_t i=0; i<regexps_sa.GetSize(); i++)
        {
            std::wstring regexp = SCXCoreLib::StrFromMultibyte(regexps_sa[static_cast<MI_Uint32>(i)].Str());

            SCX_LOGTRACE(log, StrAppend(L"SCXLogFileProvider::InvokeMatchedRows - regexp = ", regexp));

            try
            {
                SCXRegexWithIndex regind;
                regind.regex = new SCXRegex(regexp);
                regind.index = i;
                regexps.push_back(regind);
            }
            catch (SCXInvalidRegexException& e)
            {
                SCX_LOGWARNING(log, StrAppend(L"SCXLogFileProvider DoInvokeMethod - invalid regexp : ", regexp));
                invalid_regex = StrAppend(StrAppend(invalid_regex, invalid_regex.length()>0?L" ":L""), i);
            }
        }

        // We have to post a single instance that contains an array of strings
        // MOF format: [OUT, ArrayType("Ordered")] string rows[]
        std::vector<mi::String> returnData;

        // If any regular expressions with invalid syntax, add special row to result
        if (invalid_regex.length() > 0)
        {
            InsertOneString( context, returnData, StrAppend(L"InvalidRegexp;", invalid_regex));
        }

        SCX_LogFile_GetMatchedRows_Class inst;
        try
        {
            // Call helper function to get the data
            std::vector<std::wstring> matchedLines;
            bool bWasPartialRead = SCXCore::g_LogFileProvider.InvokeLogFileReader(
                filename, qid, regexps, fPerformElevation, initializeFlag, matchedLines);

            // Add each match to the result property set
            //
            // Reserve space in the vector for efficiency:
            //   Current size + # of lines to add + 1 (for potential "MoreRowsAvailable")
            returnData.reserve( returnData.size() + matchedLines.size() + 1 );
            for (std::vector<std::wstring>::iterator it = matchedLines.begin();
                 it != matchedLines.end();
                 it++)
            {
                InsertOneString( context, returnData, *it );
            }

            // Set "MoreRowsAvailable" if we terminated early
            if (bWasPartialRead)
            {
                InsertOneString( context, returnData, L"MoreRowsAvailable;true" );
            }

            StringA rows(&returnData[0], static_cast<MI_Uint32>(returnData.size()));
            inst.rows_value( rows );
        }
        catch (SCXCoreLib::SCXFilePathNotFoundException& e)
        {
            SCX_LOGWARNING(log, SCXCoreLib::StrAppend(L"LogFileProvider DoInvokeMethod - File not found: ", filename).append(e.What()));
        }

        // Set the return value (the number of lines returned)
        inst.MIReturn_value( static_cast<MI_Uint32> (returnData.size()) );

        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_LogFile_Class_Provider::Load", log );
}


MI_END_NAMESPACE
