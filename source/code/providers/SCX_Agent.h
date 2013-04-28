/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_Agent_h
#define _SCX_Agent_h

#include <MI.h>
#include "CIM_LogicalElement.h"

/*
**==============================================================================
**
** SCX_Agent [SCX_Agent]
**
** Keys:
**    Name
**
**==============================================================================
*/

typedef struct _SCX_Agent /* extends CIM_LogicalElement */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_ManagedSystemElement properties */
    MI_ConstDatetimeField InstallDate;
    /*KEY*/ MI_ConstStringField Name;
    MI_ConstUint16AField OperationalStatus;
    MI_ConstStringAField StatusDescriptions;
    MI_ConstStringField Status;
    MI_ConstUint16Field HealthState;
    MI_ConstUint16Field CommunicationStatus;
    MI_ConstUint16Field DetailedStatus;
    MI_ConstUint16Field OperatingStatus;
    MI_ConstUint16Field PrimaryStatus;
    /* CIM_LogicalElement properties */
    /* SCX_Agent properties */
    MI_ConstStringField VersionString;
    MI_ConstUint16Field MajorVersion;
    MI_ConstUint16Field MinorVersion;
    MI_ConstUint16Field RevisionNumber;
    MI_ConstUint16Field BuildNumber;
    MI_ConstStringField BuildDate;
    MI_ConstStringField Architecture;
    MI_ConstStringField OSName;
    MI_ConstStringField OSType;
    MI_ConstStringField OSVersion;
    MI_ConstStringField KitVersionString;
    MI_ConstStringField Hostname;
    MI_ConstStringField OSAlias;
    MI_ConstStringField UnameArchitecture;
    MI_ConstStringField MinActiveLogSeverityThreshold;
    MI_ConstStringField MachineType;
    MI_ConstUint64Field PhysicalProcessors;
    MI_ConstUint64Field LogicalProcessors;
}
SCX_Agent;

typedef struct _SCX_Agent_Ref
{
    SCX_Agent* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Agent_Ref;

typedef struct _SCX_Agent_ConstRef
{
    MI_CONST SCX_Agent* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Agent_ConstRef;

typedef struct _SCX_Agent_Array
{
    struct _SCX_Agent** data;
    MI_Uint32 size;
}
SCX_Agent_Array;

typedef struct _SCX_Agent_ConstArray
{
    struct _SCX_Agent MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_Agent_ConstArray;

typedef struct _SCX_Agent_ArrayRef
{
    SCX_Agent_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Agent_ArrayRef;

typedef struct _SCX_Agent_ConstArrayRef
{
    SCX_Agent_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Agent_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_Agent_rtti;

MI_INLINE MI_Result MI_CALL SCX_Agent_Construct(
    SCX_Agent* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_Agent_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clone(
    const SCX_Agent* self,
    SCX_Agent** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_Agent_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_Agent_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Destruct(SCX_Agent* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Delete(SCX_Agent* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Post(
    const SCX_Agent* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_InstanceID(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_InstanceID(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_InstanceID(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_Caption(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_Caption(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_Caption(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_Description(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_Description(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_Description(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_ElementName(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_ElementName(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_ElementName(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_InstallDate(
    SCX_Agent* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_InstallDate(
    SCX_Agent* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_Name(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_Name(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_Name(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_OperationalStatus(
    SCX_Agent* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_OperationalStatus(
    SCX_Agent* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_OperationalStatus(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_StatusDescriptions(
    SCX_Agent* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_StatusDescriptions(
    SCX_Agent* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_StatusDescriptions(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_Status(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_Status(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_Status(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_HealthState(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_HealthState(
    SCX_Agent* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_CommunicationStatus(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_CommunicationStatus(
    SCX_Agent* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_DetailedStatus(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_DetailedStatus(
    SCX_Agent* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_OperatingStatus(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_OperatingStatus(
    SCX_Agent* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_PrimaryStatus(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_PrimaryStatus(
    SCX_Agent* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_VersionString(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_VersionString(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_VersionString(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        14);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_MajorVersion(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->MajorVersion)->value = x;
    ((MI_Uint16Field*)&self->MajorVersion)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_MajorVersion(
    SCX_Agent* self)
{
    memset((void*)&self->MajorVersion, 0, sizeof(self->MajorVersion));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_MinorVersion(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->MinorVersion)->value = x;
    ((MI_Uint16Field*)&self->MinorVersion)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_MinorVersion(
    SCX_Agent* self)
{
    memset((void*)&self->MinorVersion, 0, sizeof(self->MinorVersion));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_RevisionNumber(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RevisionNumber)->value = x;
    ((MI_Uint16Field*)&self->RevisionNumber)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_RevisionNumber(
    SCX_Agent* self)
{
    memset((void*)&self->RevisionNumber, 0, sizeof(self->RevisionNumber));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_BuildNumber(
    SCX_Agent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->BuildNumber)->value = x;
    ((MI_Uint16Field*)&self->BuildNumber)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_BuildNumber(
    SCX_Agent* self)
{
    memset((void*)&self->BuildNumber, 0, sizeof(self->BuildNumber));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_BuildDate(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        19,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_BuildDate(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        19,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_BuildDate(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_Architecture(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        20,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_Architecture(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        20,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_Architecture(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        20);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_OSName(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_OSName(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_OSName(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_OSType(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_OSType(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_OSType(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_OSVersion(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_OSVersion(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_OSVersion(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_KitVersionString(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_KitVersionString(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_KitVersionString(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_Hostname(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_Hostname(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_Hostname(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        25);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_OSAlias(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_OSAlias(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_OSAlias(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_UnameArchitecture(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_UnameArchitecture(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_UnameArchitecture(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        27);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_MinActiveLogSeverityThreshold(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_MinActiveLogSeverityThreshold(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_MinActiveLogSeverityThreshold(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        28);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_MachineType(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_SetPtr_MachineType(
    SCX_Agent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_MachineType(
    SCX_Agent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_PhysicalProcessors(
    SCX_Agent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PhysicalProcessors)->value = x;
    ((MI_Uint64Field*)&self->PhysicalProcessors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_PhysicalProcessors(
    SCX_Agent* self)
{
    memset((void*)&self->PhysicalProcessors, 0, sizeof(self->PhysicalProcessors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Set_LogicalProcessors(
    SCX_Agent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->LogicalProcessors)->value = x;
    ((MI_Uint64Field*)&self->LogicalProcessors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Agent_Clear_LogicalProcessors(
    SCX_Agent* self)
{
    memset((void*)&self->LogicalProcessors, 0, sizeof(self->LogicalProcessors));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Agent provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_Agent_Self SCX_Agent_Self;

MI_EXTERN_C void MI_CALL SCX_Agent_Load(
    SCX_Agent_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Agent_Unload(
    SCX_Agent_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Agent_EnumerateInstances(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_Agent_GetInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Agent_CreateInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* newInstance);

MI_EXTERN_C void MI_CALL SCX_Agent_ModifyInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Agent_DeleteInstance(
    SCX_Agent_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Agent* instanceName);


/*
**==============================================================================
**
** SCX_Agent_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_Agent_Class : public CIM_LogicalElement_Class
{
public:
    
    typedef SCX_Agent Self;
    
    SCX_Agent_Class() :
        CIM_LogicalElement_Class(&SCX_Agent_rtti)
    {
    }
    
    SCX_Agent_Class(
        const SCX_Agent* instanceName,
        bool keysOnly) :
        CIM_LogicalElement_Class(
            &SCX_Agent_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Agent_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Agent_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalElement_Class(clDecl)
    {
    }
    
    SCX_Agent_Class& operator=(
        const SCX_Agent_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Agent_Class(
        const SCX_Agent_Class& x) :
        CIM_LogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_Agent_rtti;
    }

    //
    // SCX_Agent_Class.VersionString
    //
    
    const Field<String>& VersionString() const
    {
        const size_t n = offsetof(Self, VersionString);
        return GetField<String>(n);
    }
    
    void VersionString(const Field<String>& x)
    {
        const size_t n = offsetof(Self, VersionString);
        GetField<String>(n) = x;
    }
    
    const String& VersionString_value() const
    {
        const size_t n = offsetof(Self, VersionString);
        return GetField<String>(n).value;
    }
    
    void VersionString_value(const String& x)
    {
        const size_t n = offsetof(Self, VersionString);
        GetField<String>(n).Set(x);
    }
    
    bool VersionString_exists() const
    {
        const size_t n = offsetof(Self, VersionString);
        return GetField<String>(n).exists ? true : false;
    }
    
    void VersionString_clear()
    {
        const size_t n = offsetof(Self, VersionString);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.MajorVersion
    //
    
    const Field<Uint16>& MajorVersion() const
    {
        const size_t n = offsetof(Self, MajorVersion);
        return GetField<Uint16>(n);
    }
    
    void MajorVersion(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, MajorVersion);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& MajorVersion_value() const
    {
        const size_t n = offsetof(Self, MajorVersion);
        return GetField<Uint16>(n).value;
    }
    
    void MajorVersion_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, MajorVersion);
        GetField<Uint16>(n).Set(x);
    }
    
    bool MajorVersion_exists() const
    {
        const size_t n = offsetof(Self, MajorVersion);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void MajorVersion_clear()
    {
        const size_t n = offsetof(Self, MajorVersion);
        GetField<Uint16>(n).Clear();
    }

    //
    // SCX_Agent_Class.MinorVersion
    //
    
    const Field<Uint16>& MinorVersion() const
    {
        const size_t n = offsetof(Self, MinorVersion);
        return GetField<Uint16>(n);
    }
    
    void MinorVersion(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, MinorVersion);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& MinorVersion_value() const
    {
        const size_t n = offsetof(Self, MinorVersion);
        return GetField<Uint16>(n).value;
    }
    
    void MinorVersion_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, MinorVersion);
        GetField<Uint16>(n).Set(x);
    }
    
    bool MinorVersion_exists() const
    {
        const size_t n = offsetof(Self, MinorVersion);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void MinorVersion_clear()
    {
        const size_t n = offsetof(Self, MinorVersion);
        GetField<Uint16>(n).Clear();
    }

    //
    // SCX_Agent_Class.RevisionNumber
    //
    
    const Field<Uint16>& RevisionNumber() const
    {
        const size_t n = offsetof(Self, RevisionNumber);
        return GetField<Uint16>(n);
    }
    
    void RevisionNumber(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, RevisionNumber);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& RevisionNumber_value() const
    {
        const size_t n = offsetof(Self, RevisionNumber);
        return GetField<Uint16>(n).value;
    }
    
    void RevisionNumber_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, RevisionNumber);
        GetField<Uint16>(n).Set(x);
    }
    
    bool RevisionNumber_exists() const
    {
        const size_t n = offsetof(Self, RevisionNumber);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void RevisionNumber_clear()
    {
        const size_t n = offsetof(Self, RevisionNumber);
        GetField<Uint16>(n).Clear();
    }

    //
    // SCX_Agent_Class.BuildNumber
    //
    
    const Field<Uint16>& BuildNumber() const
    {
        const size_t n = offsetof(Self, BuildNumber);
        return GetField<Uint16>(n);
    }
    
    void BuildNumber(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, BuildNumber);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& BuildNumber_value() const
    {
        const size_t n = offsetof(Self, BuildNumber);
        return GetField<Uint16>(n).value;
    }
    
    void BuildNumber_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, BuildNumber);
        GetField<Uint16>(n).Set(x);
    }
    
    bool BuildNumber_exists() const
    {
        const size_t n = offsetof(Self, BuildNumber);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void BuildNumber_clear()
    {
        const size_t n = offsetof(Self, BuildNumber);
        GetField<Uint16>(n).Clear();
    }

    //
    // SCX_Agent_Class.BuildDate
    //
    
    const Field<String>& BuildDate() const
    {
        const size_t n = offsetof(Self, BuildDate);
        return GetField<String>(n);
    }
    
    void BuildDate(const Field<String>& x)
    {
        const size_t n = offsetof(Self, BuildDate);
        GetField<String>(n) = x;
    }
    
    const String& BuildDate_value() const
    {
        const size_t n = offsetof(Self, BuildDate);
        return GetField<String>(n).value;
    }
    
    void BuildDate_value(const String& x)
    {
        const size_t n = offsetof(Self, BuildDate);
        GetField<String>(n).Set(x);
    }
    
    bool BuildDate_exists() const
    {
        const size_t n = offsetof(Self, BuildDate);
        return GetField<String>(n).exists ? true : false;
    }
    
    void BuildDate_clear()
    {
        const size_t n = offsetof(Self, BuildDate);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.Architecture
    //
    
    const Field<String>& Architecture() const
    {
        const size_t n = offsetof(Self, Architecture);
        return GetField<String>(n);
    }
    
    void Architecture(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Architecture);
        GetField<String>(n) = x;
    }
    
    const String& Architecture_value() const
    {
        const size_t n = offsetof(Self, Architecture);
        return GetField<String>(n).value;
    }
    
    void Architecture_value(const String& x)
    {
        const size_t n = offsetof(Self, Architecture);
        GetField<String>(n).Set(x);
    }
    
    bool Architecture_exists() const
    {
        const size_t n = offsetof(Self, Architecture);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Architecture_clear()
    {
        const size_t n = offsetof(Self, Architecture);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.OSName
    //
    
    const Field<String>& OSName() const
    {
        const size_t n = offsetof(Self, OSName);
        return GetField<String>(n);
    }
    
    void OSName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OSName);
        GetField<String>(n) = x;
    }
    
    const String& OSName_value() const
    {
        const size_t n = offsetof(Self, OSName);
        return GetField<String>(n).value;
    }
    
    void OSName_value(const String& x)
    {
        const size_t n = offsetof(Self, OSName);
        GetField<String>(n).Set(x);
    }
    
    bool OSName_exists() const
    {
        const size_t n = offsetof(Self, OSName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OSName_clear()
    {
        const size_t n = offsetof(Self, OSName);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.OSType
    //
    
    const Field<String>& OSType() const
    {
        const size_t n = offsetof(Self, OSType);
        return GetField<String>(n);
    }
    
    void OSType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OSType);
        GetField<String>(n) = x;
    }
    
    const String& OSType_value() const
    {
        const size_t n = offsetof(Self, OSType);
        return GetField<String>(n).value;
    }
    
    void OSType_value(const String& x)
    {
        const size_t n = offsetof(Self, OSType);
        GetField<String>(n).Set(x);
    }
    
    bool OSType_exists() const
    {
        const size_t n = offsetof(Self, OSType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OSType_clear()
    {
        const size_t n = offsetof(Self, OSType);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.OSVersion
    //
    
    const Field<String>& OSVersion() const
    {
        const size_t n = offsetof(Self, OSVersion);
        return GetField<String>(n);
    }
    
    void OSVersion(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OSVersion);
        GetField<String>(n) = x;
    }
    
    const String& OSVersion_value() const
    {
        const size_t n = offsetof(Self, OSVersion);
        return GetField<String>(n).value;
    }
    
    void OSVersion_value(const String& x)
    {
        const size_t n = offsetof(Self, OSVersion);
        GetField<String>(n).Set(x);
    }
    
    bool OSVersion_exists() const
    {
        const size_t n = offsetof(Self, OSVersion);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OSVersion_clear()
    {
        const size_t n = offsetof(Self, OSVersion);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.KitVersionString
    //
    
    const Field<String>& KitVersionString() const
    {
        const size_t n = offsetof(Self, KitVersionString);
        return GetField<String>(n);
    }
    
    void KitVersionString(const Field<String>& x)
    {
        const size_t n = offsetof(Self, KitVersionString);
        GetField<String>(n) = x;
    }
    
    const String& KitVersionString_value() const
    {
        const size_t n = offsetof(Self, KitVersionString);
        return GetField<String>(n).value;
    }
    
    void KitVersionString_value(const String& x)
    {
        const size_t n = offsetof(Self, KitVersionString);
        GetField<String>(n).Set(x);
    }
    
    bool KitVersionString_exists() const
    {
        const size_t n = offsetof(Self, KitVersionString);
        return GetField<String>(n).exists ? true : false;
    }
    
    void KitVersionString_clear()
    {
        const size_t n = offsetof(Self, KitVersionString);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.Hostname
    //
    
    const Field<String>& Hostname() const
    {
        const size_t n = offsetof(Self, Hostname);
        return GetField<String>(n);
    }
    
    void Hostname(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Hostname);
        GetField<String>(n) = x;
    }
    
    const String& Hostname_value() const
    {
        const size_t n = offsetof(Self, Hostname);
        return GetField<String>(n).value;
    }
    
    void Hostname_value(const String& x)
    {
        const size_t n = offsetof(Self, Hostname);
        GetField<String>(n).Set(x);
    }
    
    bool Hostname_exists() const
    {
        const size_t n = offsetof(Self, Hostname);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Hostname_clear()
    {
        const size_t n = offsetof(Self, Hostname);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.OSAlias
    //
    
    const Field<String>& OSAlias() const
    {
        const size_t n = offsetof(Self, OSAlias);
        return GetField<String>(n);
    }
    
    void OSAlias(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OSAlias);
        GetField<String>(n) = x;
    }
    
    const String& OSAlias_value() const
    {
        const size_t n = offsetof(Self, OSAlias);
        return GetField<String>(n).value;
    }
    
    void OSAlias_value(const String& x)
    {
        const size_t n = offsetof(Self, OSAlias);
        GetField<String>(n).Set(x);
    }
    
    bool OSAlias_exists() const
    {
        const size_t n = offsetof(Self, OSAlias);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OSAlias_clear()
    {
        const size_t n = offsetof(Self, OSAlias);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.UnameArchitecture
    //
    
    const Field<String>& UnameArchitecture() const
    {
        const size_t n = offsetof(Self, UnameArchitecture);
        return GetField<String>(n);
    }
    
    void UnameArchitecture(const Field<String>& x)
    {
        const size_t n = offsetof(Self, UnameArchitecture);
        GetField<String>(n) = x;
    }
    
    const String& UnameArchitecture_value() const
    {
        const size_t n = offsetof(Self, UnameArchitecture);
        return GetField<String>(n).value;
    }
    
    void UnameArchitecture_value(const String& x)
    {
        const size_t n = offsetof(Self, UnameArchitecture);
        GetField<String>(n).Set(x);
    }
    
    bool UnameArchitecture_exists() const
    {
        const size_t n = offsetof(Self, UnameArchitecture);
        return GetField<String>(n).exists ? true : false;
    }
    
    void UnameArchitecture_clear()
    {
        const size_t n = offsetof(Self, UnameArchitecture);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.MinActiveLogSeverityThreshold
    //
    
    const Field<String>& MinActiveLogSeverityThreshold() const
    {
        const size_t n = offsetof(Self, MinActiveLogSeverityThreshold);
        return GetField<String>(n);
    }
    
    void MinActiveLogSeverityThreshold(const Field<String>& x)
    {
        const size_t n = offsetof(Self, MinActiveLogSeverityThreshold);
        GetField<String>(n) = x;
    }
    
    const String& MinActiveLogSeverityThreshold_value() const
    {
        const size_t n = offsetof(Self, MinActiveLogSeverityThreshold);
        return GetField<String>(n).value;
    }
    
    void MinActiveLogSeverityThreshold_value(const String& x)
    {
        const size_t n = offsetof(Self, MinActiveLogSeverityThreshold);
        GetField<String>(n).Set(x);
    }
    
    bool MinActiveLogSeverityThreshold_exists() const
    {
        const size_t n = offsetof(Self, MinActiveLogSeverityThreshold);
        return GetField<String>(n).exists ? true : false;
    }
    
    void MinActiveLogSeverityThreshold_clear()
    {
        const size_t n = offsetof(Self, MinActiveLogSeverityThreshold);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.MachineType
    //
    
    const Field<String>& MachineType() const
    {
        const size_t n = offsetof(Self, MachineType);
        return GetField<String>(n);
    }
    
    void MachineType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, MachineType);
        GetField<String>(n) = x;
    }
    
    const String& MachineType_value() const
    {
        const size_t n = offsetof(Self, MachineType);
        return GetField<String>(n).value;
    }
    
    void MachineType_value(const String& x)
    {
        const size_t n = offsetof(Self, MachineType);
        GetField<String>(n).Set(x);
    }
    
    bool MachineType_exists() const
    {
        const size_t n = offsetof(Self, MachineType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void MachineType_clear()
    {
        const size_t n = offsetof(Self, MachineType);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Agent_Class.PhysicalProcessors
    //
    
    const Field<Uint64>& PhysicalProcessors() const
    {
        const size_t n = offsetof(Self, PhysicalProcessors);
        return GetField<Uint64>(n);
    }
    
    void PhysicalProcessors(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, PhysicalProcessors);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& PhysicalProcessors_value() const
    {
        const size_t n = offsetof(Self, PhysicalProcessors);
        return GetField<Uint64>(n).value;
    }
    
    void PhysicalProcessors_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, PhysicalProcessors);
        GetField<Uint64>(n).Set(x);
    }
    
    bool PhysicalProcessors_exists() const
    {
        const size_t n = offsetof(Self, PhysicalProcessors);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void PhysicalProcessors_clear()
    {
        const size_t n = offsetof(Self, PhysicalProcessors);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_Agent_Class.LogicalProcessors
    //
    
    const Field<Uint64>& LogicalProcessors() const
    {
        const size_t n = offsetof(Self, LogicalProcessors);
        return GetField<Uint64>(n);
    }
    
    void LogicalProcessors(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, LogicalProcessors);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& LogicalProcessors_value() const
    {
        const size_t n = offsetof(Self, LogicalProcessors);
        return GetField<Uint64>(n).value;
    }
    
    void LogicalProcessors_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, LogicalProcessors);
        GetField<Uint64>(n).Set(x);
    }
    
    bool LogicalProcessors_exists() const
    {
        const size_t n = offsetof(Self, LogicalProcessors);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void LogicalProcessors_clear()
    {
        const size_t n = offsetof(Self, LogicalProcessors);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<SCX_Agent_Class> SCX_Agent_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_Agent_h */
