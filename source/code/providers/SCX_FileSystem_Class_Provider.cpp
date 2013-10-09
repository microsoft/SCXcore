/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
    \file        SCX_FileSystem_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-14-2013 11:09:45
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_FileSystem_Class_Provider.h"
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxassert.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxnameresolver.h>
#include "support/filesystemprovider.h"
#include "support/scxcimutils.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_FileSystem_Class& inst,
    bool keysOnly,
    SCXHandle<SCXSystemLib::StaticLogicalDiskInstance> diskinst)
{
    SCXCoreLib::NameResolver nr;
    std::wstring hostname = nr.GetHostDomainname();

    diskinst->Update();

    std::wstring name;
    if (diskinst->GetDeviceName(name)) 
    {
        inst.Name_value(StrToMultibyte(name).c_str());
    }

    inst.CreationClassName_value("SCX_FileSystem");
    inst.CSCreationClassName_value("SCX_ComputerSystem");
    inst.CSName_value(StrToMultibyte(hostname).c_str());

    if (!keysOnly) 
    {
        inst.Caption_value("File system information");
        inst.Description_value("Information about a logical unit of secondary storage");

        scxulong data;
        std::wstring sdata;
        bool bdata;

        if (diskinst->GetHealthState(bdata)) 
        {
            inst.IsOnline_value(bdata);
        }

        if (diskinst->GetMountpoint(sdata)) 
        {
            inst.Root_value(StrToMultibyte(sdata).c_str());
        }

        if (diskinst->GetFileSystemType(sdata)) 
        {
            inst.FileSystemType_value(StrToMultibyte(sdata).c_str());
        }

        if (diskinst->GetSizeInBytes(data)) 
        {
            inst.FileSystemSize_value(data);
        }

        if (diskinst->GetCompressionMethod(sdata)) 
        {
            inst.CompressionMethod_value(StrToMultibyte(sdata).c_str());
        }

        if (diskinst->GetIsReadOnly(bdata)) 
        {
            inst.ReadOnly_value(bdata);
        }

        if (diskinst->GetEncryptionMethod(sdata)) 
        {
            inst.EncryptionMethod_value(StrToMultibyte(sdata).c_str());
        }

        int idata;
        if (diskinst->GetPersistenceType(idata)) 
        {
            inst.PersistenceType_value(static_cast<unsigned short>(idata));
        }

        if (diskinst->GetBlockSize(data)) 
        {
            inst.BlockSize_value(data);
        }

        if (diskinst->GetAvailableSpaceInBytes(data)) 
        {
            inst.AvailableSpace_value(data);
        }
                         
        scxulong inodesTotal, inodesFree;
        if (diskinst->GetTotalInodes(inodesTotal) && diskinst->GetAvailableInodes(inodesFree)) 
        {
            inst.TotalInodes_value(inodesTotal);
            inst.FreeInodes_value(inodesFree);
            inst.NumberOfFiles_value(inodesTotal - inodesFree);
        }

        if (diskinst->GetIsCaseSensitive(bdata)) 
        {
            inst.CaseSensitive_value(bdata);
        }

        if (diskinst->GetIsCasePreserved(bdata)) 
        {
            inst.CasePreserved_value(bdata);
        }
        
        /*
          if (diskinst->GetCodeSet(idata))
          {
          Uint16A tmp;
          tmp[0] = (Uint16)idata;
          inst.CodeSet_value(tmp);
          }
        */

        if (diskinst->GetMaxFilenameLen(data)) 
        {
            inst.MaxFileNameLength_value(static_cast<unsigned int>(data));
        }
    }
    context.Post(inst);
}

SCX_FileSystem_Class_Provider::SCX_FileSystem_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_FileSystem_Class_Provider::~SCX_FileSystem_Class_Provider()
{
}

void SCX_FileSystem_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        SCXCore::g_FileSystemProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_FileSystemProvider.GetLogHandle(),
                           SCXCoreLib::StrAppend(L"SCX_FileSystem_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_FileSystem_Class_Provider::Load", SCXCore::g_FileSystemProvider.GetLogHandle() );
}

void SCX_FileSystem_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        SCXCore::g_FileSystemProvider.UnLoad();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_FileSystem_Class_Provider::Unload", SCXCore::g_FileSystemProvider.GetLogHandle() );
}

void SCX_FileSystem_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
   SCX_PEX_BEGIN
   {
       // Global lock for DiskProvider class
       SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));

       // (Note: Only do full update if we're not enumerating keys) 
       SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> staticLogicalDisksEnum = SCXCore::g_FileSystemProvider.getEnumstaticLogicalDisks();
       staticLogicalDisksEnum->Update(!keysOnly);

       for(size_t i = 0; i < staticLogicalDisksEnum->Size(); i++) 
       {
           SCX_FileSystem_Class inst;
           SCXHandle<SCXSystemLib::StaticLogicalDiskInstance> diskinst = staticLogicalDisksEnum->GetInstance(i);
           EnumerateOneInstance(context, inst, keysOnly, diskinst);
       }

       // Enumerate Total instance
       SCXHandle<SCXSystemLib::StaticLogicalDiskInstance> totalInst = staticLogicalDisksEnum->GetTotalInstance();
       if (totalInst != NULL)
       {
           // There will always be one total instance
           SCX_FileSystem_Class inst;
           EnumerateOneInstance(context, inst, keysOnly, totalInst);
       }

       context.Post(MI_RESULT_OK);
   }
   SCX_PEX_END( L"SCX_FileSystem_Class_Provider::EnumerateInstances", SCXCore::g_FileSystemProvider.GetLogHandle() );
}

void SCX_FileSystem_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystem_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));

        // We have 4-part key:
        //   [Key] Name=/boot
        //   [Key] CSCreationClassName=SCX_ComputerSystem
        //   [Key] CSName=jeffcof64-rhel6-01.scx.com
        //   [Key] CreationClassName=SCX_FileSystem

        if (!instanceName.Name_exists() || !instanceName.CSCreationClassName_exists() ||
            !instanceName.CSName_exists() || !instanceName.CreationClassName_exists())
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::string csName;
        try {
            NameResolver mi;
            csName = StrToMultibyte(mi.GetHostDomainname()).c_str();
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_FileSystemProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read host/domainname because ", e.What()),
                               e.Where()));
        }

        // Now compare (case insensitive for the class names, case sensitive for the others)
        if ( 0 != strcasecmp("SCX_ComputerSystem", instanceName.CSCreationClassName_value().Str())
             || 0 != strcasecmp("SCX_FileSystem", instanceName.CreationClassName_value().Str())
             || 0 != strcmp(csName.c_str(), instanceName.CSName_value().Str()))
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> staticLogicalDisksEnum = SCXCore::g_FileSystemProvider.getEnumstaticLogicalDisks();
        staticLogicalDisksEnum->Update(true);

        const std::string name = (instanceName.Name_value()).Str();
        if (name.size() == 0)
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        SCXHandle<SCXSystemLib::StaticLogicalDiskInstance> diskinst;
        diskinst = staticLogicalDisksEnum->GetInstance(StrFromUTF8(name));

        if (diskinst == NULL)
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_FileSystem_Class inst;
        EnumerateOneInstance(context, inst, false, diskinst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_FileSystem_Class_Provider::GetInstance",
                   SCXCore::g_FileSystemProvider.GetLogHandle() );
}

void SCX_FileSystem_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystem_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_FileSystem_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystem_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_FileSystem_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystem_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_FileSystem_Class_Provider::Invoke_RequestStateChange(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystem_Class& instanceName,
    const SCX_FileSystem_RequestStateChange_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_FileSystem_Class_Provider::Invoke_RemoveByName(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystem_Class& instanceName,
    const SCX_FileSystem_RemoveByName_Class& in)
{
    SCX_PEX_BEGIN
        {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        
        SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> staticLogicalDisksEnum = SCXCore::g_FileSystemProvider.getEnumstaticLogicalDisks();
        staticLogicalDisksEnum->Update(true);

        SCX_FileSystem_RemoveByName_Class inst;
        if (!in.Name_exists() || strlen(in.Name_value().Str()) == 0)
        {
            inst.MIReturn_value(0);
            context.Post(inst);
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }
        const std::wstring name = StrFromMultibyte(in.Name_value().Str());

        SCXHandle<SCXSystemLib::StaticLogicalDiskInstance> diskinst;
        if ( (diskinst = staticLogicalDisksEnum->GetInstance(name)) == NULL)
        {
            inst.MIReturn_value(0);
            context.Post(inst);
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_FileSystem_Class fsInst;
        EnumerateOneInstance(context, fsInst, false, diskinst);

        bool cmdok = SCXCore::g_FileSystemProvider.getEnumstatisticalLogicalDisks()->RemoveInstanceById(name) && 
                             SCXCore::g_FileSystemProvider.getEnumstaticLogicalDisks()->RemoveInstanceById(name);

        inst.MIReturn_value(cmdok);
        context.Post(inst);
        context.Post(MI_RESULT_OK);
        }
        SCX_PEX_END( L"SCX_FileSystem_Class_Provider::Invoke_RemoveByName", SCXCore::g_FileSystemProvider.GetLogHandle() );
}


MI_END_NAMESPACE
