/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#include <MI.h>
#include "module.h"
#include "SCX_Agent_Class_Provider.h"
#include "SCX_Application_Server_Class_Provider.h"
#include "SCX_DiskDrive_Class_Provider.h"
#include "SCX_DiskDriveStatisticalInformation_Class_Provider.h"
#include "SCX_FileSystem_Class_Provider.h"
#include "SCX_FileSystemStatisticalInformation_Class_Provider.h"
#include "SCX_EthernetPortStatistics_Class_Provider.h"
#include "SCX_LANEndpoint_Class_Provider.h"
#include "SCX_IPProtocolEndpoint_Class_Provider.h"
#include "SCX_LogFile_Class_Provider.h"
#include "SCX_MemoryStatisticalInformation_Class_Provider.h"
#include "SCX_OperatingSystem_Class_Provider.h"
#include "SCX_ProcessorStatisticalInformation_Class_Provider.h"
#include "SCX_UnixProcess_Class_Provider.h"
#include "SCX_UnixProcessStatisticalInformation_Class_Provider.h"

using namespace mi;

MI_EXTERN_C void MI_CALL SCX_Agent_Load(
    SCX_Agent_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_Agent_Class_Provider* prov = new SCX_Agent_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_Agent_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_Agent_Unload(
    SCX_Agent_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_Agent_Class_Provider* prov = (SCX_Agent_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_Agent_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_Agent_EnumerateInstances(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_Agent_Class_Provider* cxxSelf =((SCX_Agent_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_Agent_GetInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_Agent_Class_Provider* cxxSelf =((SCX_Agent_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Agent_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_Agent_CreateInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* newInstance)
{
    SCX_Agent_Class_Provider* cxxSelf =((SCX_Agent_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Agent_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_Agent_ModifyInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_Agent_Class_Provider* cxxSelf =((SCX_Agent_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Agent_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_Agent_DeleteInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* instanceName)
{
    SCX_Agent_Class_Provider* cxxSelf =((SCX_Agent_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Agent_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_Load(
    SCX_Application_Server_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_Application_Server_Class_Provider* prov = new SCX_Application_Server_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_Application_Server_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_Unload(
    SCX_Application_Server_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_Application_Server_Class_Provider* prov = (SCX_Application_Server_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_Application_Server_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_EnumerateInstances(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_Application_Server_Class_Provider* cxxSelf =((SCX_Application_Server_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_GetInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_Application_Server_Class_Provider* cxxSelf =((SCX_Application_Server_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Application_Server_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_CreateInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* newInstance)
{
    SCX_Application_Server_Class_Provider* cxxSelf =((SCX_Application_Server_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Application_Server_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_ModifyInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_Application_Server_Class_Provider* cxxSelf =((SCX_Application_Server_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Application_Server_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_DeleteInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* instanceName)
{
    SCX_Application_Server_Class_Provider* cxxSelf =((SCX_Application_Server_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_Application_Server_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_Application_Server_Invoke_SetDeepMonitoring(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Application_Server* instanceName,
    const SCX_Application_Server_SetDeepMonitoring* in)
{
    SCX_Application_Server_Class_Provider* cxxSelf =((SCX_Application_Server_Class_Provider*)self);
    SCX_Application_Server_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_Application_Server_SetDeepMonitoring_Class param(in, false);

    cxxSelf->Invoke_SetDeepMonitoring(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Load(
    SCX_DiskDrive_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_DiskDrive_Class_Provider* prov = new SCX_DiskDrive_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_DiskDrive_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Unload(
    SCX_DiskDrive_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_DiskDrive_Class_Provider* prov = (SCX_DiskDrive_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_DiskDrive_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_EnumerateInstances(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_GetInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDrive_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_CreateInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* newInstance)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDrive_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_ModifyInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDrive_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_DeleteInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* instanceName)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDrive_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_RequestStateChange(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_RequestStateChange* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_RequestStateChange_Class param(in, false);

    cxxSelf->Invoke_RequestStateChange(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_SetPowerState(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_SetPowerState* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_SetPowerState_Class param(in, false);

    cxxSelf->Invoke_SetPowerState(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_Reset(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_Reset* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_Reset_Class param(in, false);

    cxxSelf->Invoke_Reset(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_EnableDevice(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_EnableDevice* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_EnableDevice_Class param(in, false);

    cxxSelf->Invoke_EnableDevice(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_OnlineDevice(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_OnlineDevice* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_OnlineDevice_Class param(in, false);

    cxxSelf->Invoke_OnlineDevice(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_QuiesceDevice(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_QuiesceDevice* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_QuiesceDevice_Class param(in, false);

    cxxSelf->Invoke_QuiesceDevice(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_SaveProperties(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_SaveProperties* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_SaveProperties_Class param(in, false);

    cxxSelf->Invoke_SaveProperties(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_RestoreProperties(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_RestoreProperties* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_RestoreProperties_Class param(in, false);

    cxxSelf->Invoke_RestoreProperties(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_LockMedia(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_LockMedia* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_LockMedia_Class param(in, false);

    cxxSelf->Invoke_LockMedia(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_RemoveByName(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_RemoveByName* in)
{
    SCX_DiskDrive_Class_Provider* cxxSelf =((SCX_DiskDrive_Class_Provider*)self);
    SCX_DiskDrive_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_DiskDrive_RemoveByName_Class param(in, false);

    cxxSelf->Invoke_RemoveByName(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_Load(
    SCX_DiskDriveStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_DiskDriveStatisticalInformation_Class_Provider* prov = new SCX_DiskDriveStatisticalInformation_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_DiskDriveStatisticalInformation_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_Unload(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_DiskDriveStatisticalInformation_Class_Provider* prov = (SCX_DiskDriveStatisticalInformation_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_DiskDriveStatisticalInformation_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_EnumerateInstances(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_DiskDriveStatisticalInformation_Class_Provider* cxxSelf =((SCX_DiskDriveStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_GetInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_DiskDriveStatisticalInformation_Class_Provider* cxxSelf =((SCX_DiskDriveStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDriveStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_CreateInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* newInstance)
{
    SCX_DiskDriveStatisticalInformation_Class_Provider* cxxSelf =((SCX_DiskDriveStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDriveStatisticalInformation_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_ModifyInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_DiskDriveStatisticalInformation_Class_Provider* cxxSelf =((SCX_DiskDriveStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDriveStatisticalInformation_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_DeleteInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* instanceName)
{
    SCX_DiskDriveStatisticalInformation_Class_Provider* cxxSelf =((SCX_DiskDriveStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_DiskDriveStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_Load(
    SCX_FileSystem_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_FileSystem_Class_Provider* prov = new SCX_FileSystem_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_FileSystem_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_Unload(
    SCX_FileSystem_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_FileSystem_Class_Provider* prov = (SCX_FileSystem_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_FileSystem_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_EnumerateInstances(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_FileSystem_Class_Provider* cxxSelf =((SCX_FileSystem_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_GetInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_FileSystem_Class_Provider* cxxSelf =((SCX_FileSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystem_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_CreateInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* newInstance)
{
    SCX_FileSystem_Class_Provider* cxxSelf =((SCX_FileSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystem_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_ModifyInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_FileSystem_Class_Provider* cxxSelf =((SCX_FileSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystem_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_DeleteInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* instanceName)
{
    SCX_FileSystem_Class_Provider* cxxSelf =((SCX_FileSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystem_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_Invoke_RequestStateChange(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_FileSystem* instanceName,
    const SCX_FileSystem_RequestStateChange* in)
{
    SCX_FileSystem_Class_Provider* cxxSelf =((SCX_FileSystem_Class_Provider*)self);
    SCX_FileSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_FileSystem_RequestStateChange_Class param(in, false);

    cxxSelf->Invoke_RequestStateChange(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_FileSystem_Invoke_RemoveByName(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_FileSystem* instanceName,
    const SCX_FileSystem_RemoveByName* in)
{
    SCX_FileSystem_Class_Provider* cxxSelf =((SCX_FileSystem_Class_Provider*)self);
    SCX_FileSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_FileSystem_RemoveByName_Class param(in, false);

    cxxSelf->Invoke_RemoveByName(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_Load(
    SCX_FileSystemStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_FileSystemStatisticalInformation_Class_Provider* prov = new SCX_FileSystemStatisticalInformation_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_FileSystemStatisticalInformation_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_Unload(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_FileSystemStatisticalInformation_Class_Provider* prov = (SCX_FileSystemStatisticalInformation_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_FileSystemStatisticalInformation_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_EnumerateInstances(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_FileSystemStatisticalInformation_Class_Provider* cxxSelf =((SCX_FileSystemStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_GetInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_FileSystemStatisticalInformation_Class_Provider* cxxSelf =((SCX_FileSystemStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystemStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_CreateInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* newInstance)
{
    SCX_FileSystemStatisticalInformation_Class_Provider* cxxSelf =((SCX_FileSystemStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystemStatisticalInformation_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_ModifyInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_FileSystemStatisticalInformation_Class_Provider* cxxSelf =((SCX_FileSystemStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystemStatisticalInformation_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_DeleteInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* instanceName)
{
    SCX_FileSystemStatisticalInformation_Class_Provider* cxxSelf =((SCX_FileSystemStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_FileSystemStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_Load(
    SCX_EthernetPortStatistics_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_EthernetPortStatistics_Class_Provider* prov = new SCX_EthernetPortStatistics_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_EthernetPortStatistics_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_Unload(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_EthernetPortStatistics_Class_Provider* prov = (SCX_EthernetPortStatistics_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_EthernetPortStatistics_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_EnumerateInstances(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_EthernetPortStatistics_Class_Provider* cxxSelf =((SCX_EthernetPortStatistics_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_GetInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_EthernetPortStatistics_Class_Provider* cxxSelf =((SCX_EthernetPortStatistics_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_EthernetPortStatistics_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_CreateInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* newInstance)
{
    SCX_EthernetPortStatistics_Class_Provider* cxxSelf =((SCX_EthernetPortStatistics_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_EthernetPortStatistics_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_ModifyInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_EthernetPortStatistics_Class_Provider* cxxSelf =((SCX_EthernetPortStatistics_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_EthernetPortStatistics_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_DeleteInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* instanceName)
{
    SCX_EthernetPortStatistics_Class_Provider* cxxSelf =((SCX_EthernetPortStatistics_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_EthernetPortStatistics_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_Invoke_ResetSelectedStats(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPortStatistics* instanceName,
    const SCX_EthernetPortStatistics_ResetSelectedStats* in)
{
    SCX_EthernetPortStatistics_Class_Provider* cxxSelf =((SCX_EthernetPortStatistics_Class_Provider*)self);
    SCX_EthernetPortStatistics_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_EthernetPortStatistics_ResetSelectedStats_Class param(in, false);

    cxxSelf->Invoke_ResetSelectedStats(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_Load(
    SCX_LANEndpoint_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_LANEndpoint_Class_Provider* prov = new SCX_LANEndpoint_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_LANEndpoint_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_Unload(
    SCX_LANEndpoint_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_LANEndpoint_Class_Provider* prov = (SCX_LANEndpoint_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_LANEndpoint_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_EnumerateInstances(
    SCX_LANEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_LANEndpoint_Class_Provider* cxxSelf =((SCX_LANEndpoint_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_GetInstance(
    SCX_LANEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LANEndpoint* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_LANEndpoint_Class_Provider* cxxSelf =((SCX_LANEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LANEndpoint_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_CreateInstance(
    SCX_LANEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LANEndpoint* newInstance)
{
    SCX_LANEndpoint_Class_Provider* cxxSelf =((SCX_LANEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LANEndpoint_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_ModifyInstance(
    SCX_LANEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LANEndpoint* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_LANEndpoint_Class_Provider* cxxSelf =((SCX_LANEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LANEndpoint_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_DeleteInstance(
    SCX_LANEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LANEndpoint* instanceName)
{
    SCX_LANEndpoint_Class_Provider* cxxSelf =((SCX_LANEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LANEndpoint_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_LANEndpoint_Invoke_RequestStateChange(
    SCX_LANEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_LANEndpoint* instanceName,
    const SCX_LANEndpoint_RequestStateChange* in)
{
    SCX_LANEndpoint_Class_Provider* cxxSelf =((SCX_LANEndpoint_Class_Provider*)self);
    SCX_LANEndpoint_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_LANEndpoint_RequestStateChange_Class param(in, false);

    cxxSelf->Invoke_RequestStateChange(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_Load(
    SCX_IPProtocolEndpoint_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_IPProtocolEndpoint_Class_Provider* prov = new SCX_IPProtocolEndpoint_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_IPProtocolEndpoint_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_Unload(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_IPProtocolEndpoint_Class_Provider* prov = (SCX_IPProtocolEndpoint_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_IPProtocolEndpoint_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_EnumerateInstances(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_IPProtocolEndpoint_Class_Provider* cxxSelf =((SCX_IPProtocolEndpoint_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_GetInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_IPProtocolEndpoint_Class_Provider* cxxSelf =((SCX_IPProtocolEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_IPProtocolEndpoint_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_CreateInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* newInstance)
{
    SCX_IPProtocolEndpoint_Class_Provider* cxxSelf =((SCX_IPProtocolEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_IPProtocolEndpoint_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_ModifyInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_IPProtocolEndpoint_Class_Provider* cxxSelf =((SCX_IPProtocolEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_IPProtocolEndpoint_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_DeleteInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* instanceName)
{
    SCX_IPProtocolEndpoint_Class_Provider* cxxSelf =((SCX_IPProtocolEndpoint_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_IPProtocolEndpoint_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_Invoke_RequestStateChange(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_IPProtocolEndpoint* instanceName,
    const SCX_IPProtocolEndpoint_RequestStateChange* in)
{
    SCX_IPProtocolEndpoint_Class_Provider* cxxSelf =((SCX_IPProtocolEndpoint_Class_Provider*)self);
    SCX_IPProtocolEndpoint_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_IPProtocolEndpoint_RequestStateChange_Class param(in, false);

    cxxSelf->Invoke_RequestStateChange(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_LogFile_Load(
    SCX_LogFile_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_LogFile_Class_Provider* prov = new SCX_LogFile_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_LogFile_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_LogFile_Unload(
    SCX_LogFile_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_LogFile_Class_Provider* prov = (SCX_LogFile_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_LogFile_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_LogFile_EnumerateInstances(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_LogFile_Class_Provider* cxxSelf =((SCX_LogFile_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_LogFile_GetInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_LogFile_Class_Provider* cxxSelf =((SCX_LogFile_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LogFile_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_LogFile_CreateInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* newInstance)
{
    SCX_LogFile_Class_Provider* cxxSelf =((SCX_LogFile_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LogFile_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_LogFile_ModifyInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_LogFile_Class_Provider* cxxSelf =((SCX_LogFile_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LogFile_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_LogFile_DeleteInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* instanceName)
{
    SCX_LogFile_Class_Provider* cxxSelf =((SCX_LogFile_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_LogFile_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_LogFile_Invoke_GetMatchedRows(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_LogFile* instanceName,
    const SCX_LogFile_GetMatchedRows* in)
{
    SCX_LogFile_Class_Provider* cxxSelf =((SCX_LogFile_Class_Provider*)self);
    SCX_LogFile_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_LogFile_GetMatchedRows_Class param(in, false);

    cxxSelf->Invoke_GetMatchedRows(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_LogFile_Invoke_ResetStateFile(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_LogFile* instanceName,
    const SCX_LogFile_ResetStateFile* in)
{
    SCX_LogFile_Class_Provider* cxxSelf =((SCX_LogFile_Class_Provider*)self);
    SCX_LogFile_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_LogFile_ResetStateFile_Class param(in, false);

    cxxSelf->Invoke_ResetStateFile(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_Load(
    SCX_MemoryStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_MemoryStatisticalInformation_Class_Provider* prov = new SCX_MemoryStatisticalInformation_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_MemoryStatisticalInformation_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_Unload(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_MemoryStatisticalInformation_Class_Provider* prov = (SCX_MemoryStatisticalInformation_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_MemoryStatisticalInformation_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_EnumerateInstances(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_MemoryStatisticalInformation_Class_Provider* cxxSelf =((SCX_MemoryStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_GetInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_MemoryStatisticalInformation_Class_Provider* cxxSelf =((SCX_MemoryStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_MemoryStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_CreateInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* newInstance)
{
    SCX_MemoryStatisticalInformation_Class_Provider* cxxSelf =((SCX_MemoryStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_MemoryStatisticalInformation_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_ModifyInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_MemoryStatisticalInformation_Class_Provider* cxxSelf =((SCX_MemoryStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_MemoryStatisticalInformation_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_DeleteInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* instanceName)
{
    SCX_MemoryStatisticalInformation_Class_Provider* cxxSelf =((SCX_MemoryStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_MemoryStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Load(
    SCX_OperatingSystem_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_OperatingSystem_Class_Provider* prov = new SCX_OperatingSystem_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_OperatingSystem_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Unload(
    SCX_OperatingSystem_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_OperatingSystem_Class_Provider* prov = (SCX_OperatingSystem_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_OperatingSystem_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_EnumerateInstances(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_GetInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_OperatingSystem_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_CreateInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* newInstance)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_OperatingSystem_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_ModifyInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_OperatingSystem_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_DeleteInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* instanceName)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_OperatingSystem_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_RequestStateChange(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_RequestStateChange* in)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    SCX_OperatingSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_OperatingSystem_RequestStateChange_Class param(in, false);

    cxxSelf->Invoke_RequestStateChange(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_Reboot(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_Reboot* in)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    SCX_OperatingSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_OperatingSystem_Reboot_Class param(in, false);

    cxxSelf->Invoke_Reboot(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_Shutdown(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_Shutdown* in)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    SCX_OperatingSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_OperatingSystem_Shutdown_Class param(in, false);

    cxxSelf->Invoke_Shutdown(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_ExecuteCommand(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_ExecuteCommand* in)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    SCX_OperatingSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_OperatingSystem_ExecuteCommand_Class param(in, false);

    cxxSelf->Invoke_ExecuteCommand(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_ExecuteShellCommand(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_ExecuteShellCommand* in)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    SCX_OperatingSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_OperatingSystem_ExecuteShellCommand_Class param(in, false);

    cxxSelf->Invoke_ExecuteShellCommand(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_ExecuteScript(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_ExecuteScript* in)
{
    SCX_OperatingSystem_Class_Provider* cxxSelf =((SCX_OperatingSystem_Class_Provider*)self);
    SCX_OperatingSystem_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_OperatingSystem_ExecuteScript_Class param(in, false);

    cxxSelf->Invoke_ExecuteScript(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_Load(
    SCX_ProcessorStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_ProcessorStatisticalInformation_Class_Provider* prov = new SCX_ProcessorStatisticalInformation_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_ProcessorStatisticalInformation_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_Unload(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_ProcessorStatisticalInformation_Class_Provider* prov = (SCX_ProcessorStatisticalInformation_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_ProcessorStatisticalInformation_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_EnumerateInstances(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_ProcessorStatisticalInformation_Class_Provider* cxxSelf =((SCX_ProcessorStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_GetInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_ProcessorStatisticalInformation_Class_Provider* cxxSelf =((SCX_ProcessorStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_ProcessorStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_CreateInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* newInstance)
{
    SCX_ProcessorStatisticalInformation_Class_Provider* cxxSelf =((SCX_ProcessorStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_ProcessorStatisticalInformation_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_ModifyInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_ProcessorStatisticalInformation_Class_Provider* cxxSelf =((SCX_ProcessorStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_ProcessorStatisticalInformation_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_DeleteInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* instanceName)
{
    SCX_ProcessorStatisticalInformation_Class_Provider* cxxSelf =((SCX_ProcessorStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_ProcessorStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Load(
    SCX_UnixProcess_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_UnixProcess_Class_Provider* prov = new SCX_UnixProcess_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_UnixProcess_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Unload(
    SCX_UnixProcess_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_UnixProcess_Class_Provider* prov = (SCX_UnixProcess_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_UnixProcess_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_EnumerateInstances(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_UnixProcess_Class_Provider* cxxSelf =((SCX_UnixProcess_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_GetInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_UnixProcess_Class_Provider* cxxSelf =((SCX_UnixProcess_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcess_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_CreateInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* newInstance)
{
    SCX_UnixProcess_Class_Provider* cxxSelf =((SCX_UnixProcess_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcess_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_ModifyInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_UnixProcess_Class_Provider* cxxSelf =((SCX_UnixProcess_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcess_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_DeleteInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* instanceName)
{
    SCX_UnixProcess_Class_Provider* cxxSelf =((SCX_UnixProcess_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcess_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Invoke_RequestStateChange(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_UnixProcess* instanceName,
    const SCX_UnixProcess_RequestStateChange* in)
{
    SCX_UnixProcess_Class_Provider* cxxSelf =((SCX_UnixProcess_Class_Provider*)self);
    SCX_UnixProcess_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_UnixProcess_RequestStateChange_Class param(in, false);

    cxxSelf->Invoke_RequestStateChange(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Invoke_TopResourceConsumers(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_UnixProcess* instanceName,
    const SCX_UnixProcess_TopResourceConsumers* in)
{
    SCX_UnixProcess_Class_Provider* cxxSelf =((SCX_UnixProcess_Class_Provider*)self);
    SCX_UnixProcess_Class instance(instanceName, false);
    Context  cxxContext(context);
    SCX_UnixProcess_TopResourceConsumers_Class param(in, false);

    cxxSelf->Invoke_TopResourceConsumers(cxxContext, nameSpace, instance, param);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_Load(
    SCX_UnixProcessStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_UnixProcessStatisticalInformation_Class_Provider* prov = new SCX_UnixProcessStatisticalInformation_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (SCX_UnixProcessStatisticalInformation_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_Unload(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    SCX_UnixProcessStatisticalInformation_Class_Provider* prov = (SCX_UnixProcessStatisticalInformation_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((SCX_UnixProcessStatisticalInformation_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_EnumerateInstances(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    SCX_UnixProcessStatisticalInformation_Class_Provider* cxxSelf =((SCX_UnixProcessStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_GetInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet)
{
    SCX_UnixProcessStatisticalInformation_Class_Provider* cxxSelf =((SCX_UnixProcessStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcessStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_CreateInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* newInstance)
{
    SCX_UnixProcessStatisticalInformation_Class_Provider* cxxSelf =((SCX_UnixProcessStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcessStatisticalInformation_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_ModifyInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    SCX_UnixProcessStatisticalInformation_Class_Provider* cxxSelf =((SCX_UnixProcessStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcessStatisticalInformation_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_DeleteInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* instanceName)
{
    SCX_UnixProcessStatisticalInformation_Class_Provider* cxxSelf =((SCX_UnixProcessStatisticalInformation_Class_Provider*)self);
    Context  cxxContext(context);
    SCX_UnixProcessStatisticalInformation_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}


MI_EXTERN_C MI_SchemaDecl schemaDecl;

void MI_CALL Load(MI_Module_Self** self, struct _MI_Context* context)
{
    *self = (MI_Module_Self*)new Module;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

void MI_CALL Unload(MI_Module_Self* self, struct _MI_Context* context)
{
    Module* module = (Module*)self;
    delete module;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C MI_EXPORT MI_Module* MI_MAIN_CALL MI_Main(MI_Server* server)
{
    /* WARNING: THIS FUNCTION AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT. */
    extern MI_Server* __mi_server;
    static MI_Module module;
    __mi_server = server;
    module.flags |= MI_MODULE_FLAG_STANDARD_QUALIFIERS;
    module.flags |= MI_MODULE_FLAG_CPLUSPLUS;
    module.charSize = sizeof(MI_Char);
    module.version = MI_VERSION;
    module.generatorVersion = MI_MAKE_VERSION(1,0,8);
    module.schemaDecl = &schemaDecl;
    module.Load = Load;
    module.Unload = Unload;
    return &module;
}

