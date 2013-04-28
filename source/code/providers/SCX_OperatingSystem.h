/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_OperatingSystem_h
#define _SCX_OperatingSystem_h

#include <MI.h>
#include "CIM_OperatingSystem.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_OperatingSystem [SCX_OperatingSystem]
**
** Keys:
**    Name
**    CSCreationClassName
**    CSName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _SCX_OperatingSystem /* extends CIM_OperatingSystem */
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
    /* CIM_EnabledLogicalElement properties */
    MI_ConstUint16Field EnabledState;
    MI_ConstStringField OtherEnabledState;
    MI_ConstUint16Field RequestedState;
    MI_ConstUint16Field EnabledDefault;
    MI_ConstDatetimeField TimeOfLastStateChange;
    MI_ConstUint16AField AvailableRequestedStates;
    MI_ConstUint16Field TransitioningToState;
    /* CIM_OperatingSystem properties */
    /*KEY*/ MI_ConstStringField CSCreationClassName;
    /*KEY*/ MI_ConstStringField CSName;
    /*KEY*/ MI_ConstStringField CreationClassName;
    MI_ConstUint16Field OSType;
    MI_ConstStringField OtherTypeDescription;
    MI_ConstStringField Version;
    MI_ConstDatetimeField LastBootUpTime;
    MI_ConstDatetimeField LocalDateTime;
    MI_ConstSint16Field CurrentTimeZone;
    MI_ConstUint32Field NumberOfLicensedUsers;
    MI_ConstUint32Field NumberOfUsers;
    MI_ConstUint32Field NumberOfProcesses;
    MI_ConstUint32Field MaxNumberOfProcesses;
    MI_ConstUint64Field TotalSwapSpaceSize;
    MI_ConstUint64Field TotalVirtualMemorySize;
    MI_ConstUint64Field FreeVirtualMemory;
    MI_ConstUint64Field FreePhysicalMemory;
    MI_ConstUint64Field TotalVisibleMemorySize;
    MI_ConstUint64Field SizeStoredInPagingFiles;
    MI_ConstUint64Field FreeSpaceInPagingFiles;
    MI_ConstUint64Field MaxProcessMemorySize;
    MI_ConstBooleanField Distributed;
    MI_ConstUint32Field MaxProcessesPerUser;
    /* SCX_OperatingSystem properties */
    MI_ConstStringField OperatingSystemCapability;
    MI_ConstUint64Field SystemUpTime;
}
SCX_OperatingSystem;

typedef struct _SCX_OperatingSystem_Ref
{
    SCX_OperatingSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_OperatingSystem_Ref;

typedef struct _SCX_OperatingSystem_ConstRef
{
    MI_CONST SCX_OperatingSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_OperatingSystem_ConstRef;

typedef struct _SCX_OperatingSystem_Array
{
    struct _SCX_OperatingSystem** data;
    MI_Uint32 size;
}
SCX_OperatingSystem_Array;

typedef struct _SCX_OperatingSystem_ConstArray
{
    struct _SCX_OperatingSystem MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_OperatingSystem_ConstArray;

typedef struct _SCX_OperatingSystem_ArrayRef
{
    SCX_OperatingSystem_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_OperatingSystem_ArrayRef;

typedef struct _SCX_OperatingSystem_ConstArrayRef
{
    SCX_OperatingSystem_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_OperatingSystem_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_OperatingSystem_rtti;

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Construct(
    SCX_OperatingSystem* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_OperatingSystem_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clone(
    const SCX_OperatingSystem* self,
    SCX_OperatingSystem** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_OperatingSystem_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_OperatingSystem_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Destruct(SCX_OperatingSystem* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Delete(SCX_OperatingSystem* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Post(
    const SCX_OperatingSystem* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_InstanceID(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_InstanceID(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_InstanceID(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_Caption(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_Caption(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_Caption(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_Description(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_Description(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_Description(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_ElementName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_ElementName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_ElementName(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_InstallDate(
    SCX_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_InstallDate(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_Name(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_Name(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_Name(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_OperationalStatus(
    SCX_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_OperationalStatus(
    SCX_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_OperationalStatus(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_StatusDescriptions(
    SCX_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_StatusDescriptions(
    SCX_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_StatusDescriptions(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_Status(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_Status(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_Status(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_HealthState(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_HealthState(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_CommunicationStatus(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_CommunicationStatus(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_DetailedStatus(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_DetailedStatus(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_OperatingStatus(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_OperatingStatus(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_PrimaryStatus(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_PrimaryStatus(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_EnabledState(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_EnabledState(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_OtherEnabledState(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_OtherEnabledState(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_OtherEnabledState(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_RequestedState(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_RequestedState(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_EnabledDefault(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_EnabledDefault(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_TimeOfLastStateChange(
    SCX_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_TimeOfLastStateChange(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_AvailableRequestedStates(
    SCX_OperatingSystem* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        19,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_AvailableRequestedStates(
    SCX_OperatingSystem* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        19,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_AvailableRequestedStates(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_TransitioningToState(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_TransitioningToState(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_CSCreationClassName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_CSCreationClassName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_CSCreationClassName(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_CSName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_CSName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_CSName(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_CreationClassName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_CreationClassName(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_CreationClassName(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_OSType(
    SCX_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OSType)->value = x;
    ((MI_Uint16Field*)&self->OSType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_OSType(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->OSType, 0, sizeof(self->OSType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_OtherTypeDescription(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_OtherTypeDescription(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_OtherTypeDescription(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        25);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_Version(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_Version(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_Version(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_LastBootUpTime(
    SCX_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastBootUpTime)->value = x;
    ((MI_DatetimeField*)&self->LastBootUpTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_LastBootUpTime(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->LastBootUpTime, 0, sizeof(self->LastBootUpTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_LocalDateTime(
    SCX_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LocalDateTime)->value = x;
    ((MI_DatetimeField*)&self->LocalDateTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_LocalDateTime(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->LocalDateTime, 0, sizeof(self->LocalDateTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_CurrentTimeZone(
    SCX_OperatingSystem* self,
    MI_Sint16 x)
{
    ((MI_Sint16Field*)&self->CurrentTimeZone)->value = x;
    ((MI_Sint16Field*)&self->CurrentTimeZone)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_CurrentTimeZone(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->CurrentTimeZone, 0, sizeof(self->CurrentTimeZone));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_NumberOfLicensedUsers(
    SCX_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfLicensedUsers)->value = x;
    ((MI_Uint32Field*)&self->NumberOfLicensedUsers)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_NumberOfLicensedUsers(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->NumberOfLicensedUsers, 0, sizeof(self->NumberOfLicensedUsers));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_NumberOfUsers(
    SCX_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfUsers)->value = x;
    ((MI_Uint32Field*)&self->NumberOfUsers)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_NumberOfUsers(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->NumberOfUsers, 0, sizeof(self->NumberOfUsers));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_NumberOfProcesses(
    SCX_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfProcesses)->value = x;
    ((MI_Uint32Field*)&self->NumberOfProcesses)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_NumberOfProcesses(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->NumberOfProcesses, 0, sizeof(self->NumberOfProcesses));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_MaxNumberOfProcesses(
    SCX_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxNumberOfProcesses)->value = x;
    ((MI_Uint32Field*)&self->MaxNumberOfProcesses)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_MaxNumberOfProcesses(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->MaxNumberOfProcesses, 0, sizeof(self->MaxNumberOfProcesses));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_TotalSwapSpaceSize(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalSwapSpaceSize)->value = x;
    ((MI_Uint64Field*)&self->TotalSwapSpaceSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_TotalSwapSpaceSize(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->TotalSwapSpaceSize, 0, sizeof(self->TotalSwapSpaceSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_TotalVirtualMemorySize(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalVirtualMemorySize)->value = x;
    ((MI_Uint64Field*)&self->TotalVirtualMemorySize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_TotalVirtualMemorySize(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->TotalVirtualMemorySize, 0, sizeof(self->TotalVirtualMemorySize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_FreeVirtualMemory(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreeVirtualMemory)->value = x;
    ((MI_Uint64Field*)&self->FreeVirtualMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_FreeVirtualMemory(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->FreeVirtualMemory, 0, sizeof(self->FreeVirtualMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_FreePhysicalMemory(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreePhysicalMemory)->value = x;
    ((MI_Uint64Field*)&self->FreePhysicalMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_FreePhysicalMemory(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->FreePhysicalMemory, 0, sizeof(self->FreePhysicalMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_TotalVisibleMemorySize(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalVisibleMemorySize)->value = x;
    ((MI_Uint64Field*)&self->TotalVisibleMemorySize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_TotalVisibleMemorySize(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->TotalVisibleMemorySize, 0, sizeof(self->TotalVisibleMemorySize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_SizeStoredInPagingFiles(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->SizeStoredInPagingFiles)->value = x;
    ((MI_Uint64Field*)&self->SizeStoredInPagingFiles)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_SizeStoredInPagingFiles(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->SizeStoredInPagingFiles, 0, sizeof(self->SizeStoredInPagingFiles));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_FreeSpaceInPagingFiles(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreeSpaceInPagingFiles)->value = x;
    ((MI_Uint64Field*)&self->FreeSpaceInPagingFiles)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_FreeSpaceInPagingFiles(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->FreeSpaceInPagingFiles, 0, sizeof(self->FreeSpaceInPagingFiles));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_MaxProcessMemorySize(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxProcessMemorySize)->value = x;
    ((MI_Uint64Field*)&self->MaxProcessMemorySize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_MaxProcessMemorySize(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->MaxProcessMemorySize, 0, sizeof(self->MaxProcessMemorySize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_Distributed(
    SCX_OperatingSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Distributed)->value = x;
    ((MI_BooleanField*)&self->Distributed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_Distributed(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->Distributed, 0, sizeof(self->Distributed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_MaxProcessesPerUser(
    SCX_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxProcessesPerUser)->value = x;
    ((MI_Uint32Field*)&self->MaxProcessesPerUser)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_MaxProcessesPerUser(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->MaxProcessesPerUser, 0, sizeof(self->MaxProcessesPerUser));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_OperatingSystemCapability(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        44,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_SetPtr_OperatingSystemCapability(
    SCX_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        44,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_OperatingSystemCapability(
    SCX_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        44);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Set_SystemUpTime(
    SCX_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->SystemUpTime)->value = x;
    ((MI_Uint64Field*)&self->SystemUpTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Clear_SystemUpTime(
    SCX_OperatingSystem* self)
{
    memset((void*)&self->SystemUpTime, 0, sizeof(self->SystemUpTime));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_OperatingSystem.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_OperatingSystem_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_OperatingSystem_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_OperatingSystem_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Construct(
    SCX_OperatingSystem_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_OperatingSystem_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Clone(
    const SCX_OperatingSystem_RequestStateChange* self,
    SCX_OperatingSystem_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Destruct(
    SCX_OperatingSystem_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Delete(
    SCX_OperatingSystem_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Post(
    const SCX_OperatingSystem_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Set_MIReturn(
    SCX_OperatingSystem_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Clear_MIReturn(
    SCX_OperatingSystem_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Set_RequestedState(
    SCX_OperatingSystem_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Clear_RequestedState(
    SCX_OperatingSystem_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Set_Job(
    SCX_OperatingSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_SetPtr_Job(
    SCX_OperatingSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Clear_Job(
    SCX_OperatingSystem_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Set_TimeoutPeriod(
    SCX_OperatingSystem_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_RequestStateChange_Clear_TimeoutPeriod(
    SCX_OperatingSystem_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_OperatingSystem.Reboot()
**
**==============================================================================
*/

typedef struct _SCX_OperatingSystem_Reboot
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_OperatingSystem_Reboot;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_OperatingSystem_Reboot_rtti;

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Reboot_Construct(
    SCX_OperatingSystem_Reboot* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_OperatingSystem_Reboot_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Reboot_Clone(
    const SCX_OperatingSystem_Reboot* self,
    SCX_OperatingSystem_Reboot** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Reboot_Destruct(
    SCX_OperatingSystem_Reboot* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Reboot_Delete(
    SCX_OperatingSystem_Reboot* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Reboot_Post(
    const SCX_OperatingSystem_Reboot* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Reboot_Set_MIReturn(
    SCX_OperatingSystem_Reboot* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Reboot_Clear_MIReturn(
    SCX_OperatingSystem_Reboot* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_OperatingSystem.Shutdown()
**
**==============================================================================
*/

typedef struct _SCX_OperatingSystem_Shutdown
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_OperatingSystem_Shutdown;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_OperatingSystem_Shutdown_rtti;

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Shutdown_Construct(
    SCX_OperatingSystem_Shutdown* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_OperatingSystem_Shutdown_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Shutdown_Clone(
    const SCX_OperatingSystem_Shutdown* self,
    SCX_OperatingSystem_Shutdown** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Shutdown_Destruct(
    SCX_OperatingSystem_Shutdown* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Shutdown_Delete(
    SCX_OperatingSystem_Shutdown* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Shutdown_Post(
    const SCX_OperatingSystem_Shutdown* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Shutdown_Set_MIReturn(
    SCX_OperatingSystem_Shutdown* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_Shutdown_Clear_MIReturn(
    SCX_OperatingSystem_Shutdown* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_OperatingSystem.ExecuteCommand()
**
**==============================================================================
*/

typedef struct _SCX_OperatingSystem_ExecuteCommand
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstBooleanField MIReturn;
    /*IN*/ MI_ConstStringField Command;
    /*OUT*/ MI_ConstSint32Field ReturnCode;
    /*OUT*/ MI_ConstStringField StdOut;
    /*OUT*/ MI_ConstStringField StdErr;
    /*IN*/ MI_ConstUint32Field timeout;
    /*IN*/ MI_ConstStringField ElevationType;
}
SCX_OperatingSystem_ExecuteCommand;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_OperatingSystem_ExecuteCommand_rtti;

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Construct(
    SCX_OperatingSystem_ExecuteCommand* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_OperatingSystem_ExecuteCommand_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clone(
    const SCX_OperatingSystem_ExecuteCommand* self,
    SCX_OperatingSystem_ExecuteCommand** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Destruct(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Delete(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Post(
    const SCX_OperatingSystem_ExecuteCommand* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Set_MIReturn(
    SCX_OperatingSystem_ExecuteCommand* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MIReturn)->value = x;
    ((MI_BooleanField*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clear_MIReturn(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Set_Command(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_SetPtr_Command(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clear_Command(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Set_ReturnCode(
    SCX_OperatingSystem_ExecuteCommand* self,
    MI_Sint32 x)
{
    ((MI_Sint32Field*)&self->ReturnCode)->value = x;
    ((MI_Sint32Field*)&self->ReturnCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clear_ReturnCode(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    memset((void*)&self->ReturnCode, 0, sizeof(self->ReturnCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Set_StdOut(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_SetPtr_StdOut(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clear_StdOut(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Set_StdErr(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_SetPtr_StdErr(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clear_StdErr(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Set_timeout(
    SCX_OperatingSystem_ExecuteCommand* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->timeout)->value = x;
    ((MI_Uint32Field*)&self->timeout)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clear_timeout(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    memset((void*)&self->timeout, 0, sizeof(self->timeout));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Set_ElevationType(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_SetPtr_ElevationType(
    SCX_OperatingSystem_ExecuteCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteCommand_Clear_ElevationType(
    SCX_OperatingSystem_ExecuteCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

/*
**==============================================================================
**
** SCX_OperatingSystem.ExecuteShellCommand()
**
**==============================================================================
*/

typedef struct _SCX_OperatingSystem_ExecuteShellCommand
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstBooleanField MIReturn;
    /*IN*/ MI_ConstStringField Command;
    /*OUT*/ MI_ConstSint32Field ReturnCode;
    /*OUT*/ MI_ConstStringField StdOut;
    /*OUT*/ MI_ConstStringField StdErr;
    /*IN*/ MI_ConstUint32Field timeout;
    /*IN*/ MI_ConstStringField ElevationType;
}
SCX_OperatingSystem_ExecuteShellCommand;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_OperatingSystem_ExecuteShellCommand_rtti;

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Construct(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_OperatingSystem_ExecuteShellCommand_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clone(
    const SCX_OperatingSystem_ExecuteShellCommand* self,
    SCX_OperatingSystem_ExecuteShellCommand** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Destruct(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Delete(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Post(
    const SCX_OperatingSystem_ExecuteShellCommand* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Set_MIReturn(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MIReturn)->value = x;
    ((MI_BooleanField*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clear_MIReturn(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Set_Command(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_SetPtr_Command(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clear_Command(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Set_ReturnCode(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    MI_Sint32 x)
{
    ((MI_Sint32Field*)&self->ReturnCode)->value = x;
    ((MI_Sint32Field*)&self->ReturnCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clear_ReturnCode(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    memset((void*)&self->ReturnCode, 0, sizeof(self->ReturnCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Set_StdOut(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_SetPtr_StdOut(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clear_StdOut(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Set_StdErr(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_SetPtr_StdErr(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clear_StdErr(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Set_timeout(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->timeout)->value = x;
    ((MI_Uint32Field*)&self->timeout)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clear_timeout(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    memset((void*)&self->timeout, 0, sizeof(self->timeout));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Set_ElevationType(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_SetPtr_ElevationType(
    SCX_OperatingSystem_ExecuteShellCommand* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteShellCommand_Clear_ElevationType(
    SCX_OperatingSystem_ExecuteShellCommand* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

/*
**==============================================================================
**
** SCX_OperatingSystem.ExecuteScript()
**
**==============================================================================
*/

typedef struct _SCX_OperatingSystem_ExecuteScript
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstBooleanField MIReturn;
    /*IN*/ MI_ConstStringField Script;
    /*IN*/ MI_ConstStringField Arguments;
    /*OUT*/ MI_ConstSint32Field ReturnCode;
    /*OUT*/ MI_ConstStringField StdOut;
    /*OUT*/ MI_ConstStringField StdErr;
    /*IN*/ MI_ConstUint32Field timeout;
    /*IN*/ MI_ConstStringField ElevationType;
}
SCX_OperatingSystem_ExecuteScript;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_OperatingSystem_ExecuteScript_rtti;

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Construct(
    SCX_OperatingSystem_ExecuteScript* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_OperatingSystem_ExecuteScript_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clone(
    const SCX_OperatingSystem_ExecuteScript* self,
    SCX_OperatingSystem_ExecuteScript** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Destruct(
    SCX_OperatingSystem_ExecuteScript* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Delete(
    SCX_OperatingSystem_ExecuteScript* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Post(
    const SCX_OperatingSystem_ExecuteScript* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_MIReturn(
    SCX_OperatingSystem_ExecuteScript* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MIReturn)->value = x;
    ((MI_BooleanField*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_MIReturn(
    SCX_OperatingSystem_ExecuteScript* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_Script(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_SetPtr_Script(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_Script(
    SCX_OperatingSystem_ExecuteScript* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_Arguments(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_SetPtr_Arguments(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_Arguments(
    SCX_OperatingSystem_ExecuteScript* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_ReturnCode(
    SCX_OperatingSystem_ExecuteScript* self,
    MI_Sint32 x)
{
    ((MI_Sint32Field*)&self->ReturnCode)->value = x;
    ((MI_Sint32Field*)&self->ReturnCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_ReturnCode(
    SCX_OperatingSystem_ExecuteScript* self)
{
    memset((void*)&self->ReturnCode, 0, sizeof(self->ReturnCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_StdOut(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_SetPtr_StdOut(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_StdOut(
    SCX_OperatingSystem_ExecuteScript* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_StdErr(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_SetPtr_StdErr(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_StdErr(
    SCX_OperatingSystem_ExecuteScript* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_timeout(
    SCX_OperatingSystem_ExecuteScript* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->timeout)->value = x;
    ((MI_Uint32Field*)&self->timeout)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_timeout(
    SCX_OperatingSystem_ExecuteScript* self)
{
    memset((void*)&self->timeout, 0, sizeof(self->timeout));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Set_ElevationType(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_SetPtr_ElevationType(
    SCX_OperatingSystem_ExecuteScript* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_OperatingSystem_ExecuteScript_Clear_ElevationType(
    SCX_OperatingSystem_ExecuteScript* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

/*
**==============================================================================
**
** SCX_OperatingSystem provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_OperatingSystem_Self SCX_OperatingSystem_Self;

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Load(
    SCX_OperatingSystem_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Unload(
    SCX_OperatingSystem_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_EnumerateInstances(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_GetInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_CreateInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* newInstance);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_ModifyInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_DeleteInstance(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_OperatingSystem* instanceName);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_RequestStateChange(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_RequestStateChange* in);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_Reboot(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_Reboot* in);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_Shutdown(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_Shutdown* in);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_ExecuteCommand(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_ExecuteCommand* in);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_ExecuteShellCommand(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_ExecuteShellCommand* in);

MI_EXTERN_C void MI_CALL SCX_OperatingSystem_Invoke_ExecuteScript(
    SCX_OperatingSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_OperatingSystem* instanceName,
    const SCX_OperatingSystem_ExecuteScript* in);


/*
**==============================================================================
**
** SCX_OperatingSystem_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_OperatingSystem_Class : public CIM_OperatingSystem_Class
{
public:
    
    typedef SCX_OperatingSystem Self;
    
    SCX_OperatingSystem_Class() :
        CIM_OperatingSystem_Class(&SCX_OperatingSystem_rtti)
    {
    }
    
    SCX_OperatingSystem_Class(
        const SCX_OperatingSystem* instanceName,
        bool keysOnly) :
        CIM_OperatingSystem_Class(
            &SCX_OperatingSystem_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_OperatingSystem_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_OperatingSystem_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_OperatingSystem_Class(
        const MI_ClassDecl* clDecl) :
        CIM_OperatingSystem_Class(clDecl)
    {
    }
    
    SCX_OperatingSystem_Class& operator=(
        const SCX_OperatingSystem_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_OperatingSystem_Class(
        const SCX_OperatingSystem_Class& x) :
        CIM_OperatingSystem_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_OperatingSystem_rtti;
    }

    //
    // SCX_OperatingSystem_Class.OperatingSystemCapability
    //
    
    const Field<String>& OperatingSystemCapability() const
    {
        const size_t n = offsetof(Self, OperatingSystemCapability);
        return GetField<String>(n);
    }
    
    void OperatingSystemCapability(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OperatingSystemCapability);
        GetField<String>(n) = x;
    }
    
    const String& OperatingSystemCapability_value() const
    {
        const size_t n = offsetof(Self, OperatingSystemCapability);
        return GetField<String>(n).value;
    }
    
    void OperatingSystemCapability_value(const String& x)
    {
        const size_t n = offsetof(Self, OperatingSystemCapability);
        GetField<String>(n).Set(x);
    }
    
    bool OperatingSystemCapability_exists() const
    {
        const size_t n = offsetof(Self, OperatingSystemCapability);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OperatingSystemCapability_clear()
    {
        const size_t n = offsetof(Self, OperatingSystemCapability);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_Class.SystemUpTime
    //
    
    const Field<Uint64>& SystemUpTime() const
    {
        const size_t n = offsetof(Self, SystemUpTime);
        return GetField<Uint64>(n);
    }
    
    void SystemUpTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, SystemUpTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& SystemUpTime_value() const
    {
        const size_t n = offsetof(Self, SystemUpTime);
        return GetField<Uint64>(n).value;
    }
    
    void SystemUpTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, SystemUpTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool SystemUpTime_exists() const
    {
        const size_t n = offsetof(Self, SystemUpTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void SystemUpTime_clear()
    {
        const size_t n = offsetof(Self, SystemUpTime);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<SCX_OperatingSystem_Class> SCX_OperatingSystem_ClassA;

class SCX_OperatingSystem_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_OperatingSystem_RequestStateChange Self;
    
    SCX_OperatingSystem_RequestStateChange_Class() :
        Instance(&SCX_OperatingSystem_RequestStateChange_rtti)
    {
    }
    
    SCX_OperatingSystem_RequestStateChange_Class(
        const SCX_OperatingSystem_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_OperatingSystem_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_OperatingSystem_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_OperatingSystem_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_OperatingSystem_RequestStateChange_Class& operator=(
        const SCX_OperatingSystem_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_OperatingSystem_RequestStateChange_Class(
        const SCX_OperatingSystem_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_OperatingSystem_RequestStateChange_Class.MIReturn
    //
    
    const Field<Uint32>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n);
    }
    
    void MIReturn(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).value;
    }
    
    void MIReturn_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Clear();
    }

    //
    // SCX_OperatingSystem_RequestStateChange_Class.RequestedState
    //
    
    const Field<Uint16>& RequestedState() const
    {
        const size_t n = offsetof(Self, RequestedState);
        return GetField<Uint16>(n);
    }
    
    void RequestedState(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, RequestedState);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& RequestedState_value() const
    {
        const size_t n = offsetof(Self, RequestedState);
        return GetField<Uint16>(n).value;
    }
    
    void RequestedState_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, RequestedState);
        GetField<Uint16>(n).Set(x);
    }
    
    bool RequestedState_exists() const
    {
        const size_t n = offsetof(Self, RequestedState);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void RequestedState_clear()
    {
        const size_t n = offsetof(Self, RequestedState);
        GetField<Uint16>(n).Clear();
    }

    //
    // SCX_OperatingSystem_RequestStateChange_Class.Job
    //
    
    const Field<CIM_ConcreteJob_Class>& Job() const
    {
        const size_t n = offsetof(Self, Job);
        return GetField<CIM_ConcreteJob_Class>(n);
    }
    
    void Job(const Field<CIM_ConcreteJob_Class>& x)
    {
        const size_t n = offsetof(Self, Job);
        GetField<CIM_ConcreteJob_Class>(n) = x;
    }
    
    const CIM_ConcreteJob_Class& Job_value() const
    {
        const size_t n = offsetof(Self, Job);
        return GetField<CIM_ConcreteJob_Class>(n).value;
    }
    
    void Job_value(const CIM_ConcreteJob_Class& x)
    {
        const size_t n = offsetof(Self, Job);
        GetField<CIM_ConcreteJob_Class>(n).Set(x);
    }
    
    bool Job_exists() const
    {
        const size_t n = offsetof(Self, Job);
        return GetField<CIM_ConcreteJob_Class>(n).exists ? true : false;
    }
    
    void Job_clear()
    {
        const size_t n = offsetof(Self, Job);
        GetField<CIM_ConcreteJob_Class>(n).Clear();
    }

    //
    // SCX_OperatingSystem_RequestStateChange_Class.TimeoutPeriod
    //
    
    const Field<Datetime>& TimeoutPeriod() const
    {
        const size_t n = offsetof(Self, TimeoutPeriod);
        return GetField<Datetime>(n);
    }
    
    void TimeoutPeriod(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, TimeoutPeriod);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& TimeoutPeriod_value() const
    {
        const size_t n = offsetof(Self, TimeoutPeriod);
        return GetField<Datetime>(n).value;
    }
    
    void TimeoutPeriod_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, TimeoutPeriod);
        GetField<Datetime>(n).Set(x);
    }
    
    bool TimeoutPeriod_exists() const
    {
        const size_t n = offsetof(Self, TimeoutPeriod);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void TimeoutPeriod_clear()
    {
        const size_t n = offsetof(Self, TimeoutPeriod);
        GetField<Datetime>(n).Clear();
    }
};

typedef Array<SCX_OperatingSystem_RequestStateChange_Class> SCX_OperatingSystem_RequestStateChange_ClassA;

class SCX_OperatingSystem_Reboot_Class : public Instance
{
public:
    
    typedef SCX_OperatingSystem_Reboot Self;
    
    SCX_OperatingSystem_Reboot_Class() :
        Instance(&SCX_OperatingSystem_Reboot_rtti)
    {
    }
    
    SCX_OperatingSystem_Reboot_Class(
        const SCX_OperatingSystem_Reboot* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_OperatingSystem_Reboot_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_OperatingSystem_Reboot_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_OperatingSystem_Reboot_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_OperatingSystem_Reboot_Class& operator=(
        const SCX_OperatingSystem_Reboot_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_OperatingSystem_Reboot_Class(
        const SCX_OperatingSystem_Reboot_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_OperatingSystem_Reboot_Class.MIReturn
    //
    
    const Field<Uint32>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n);
    }
    
    void MIReturn(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).value;
    }
    
    void MIReturn_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Clear();
    }
};

typedef Array<SCX_OperatingSystem_Reboot_Class> SCX_OperatingSystem_Reboot_ClassA;

class SCX_OperatingSystem_Shutdown_Class : public Instance
{
public:
    
    typedef SCX_OperatingSystem_Shutdown Self;
    
    SCX_OperatingSystem_Shutdown_Class() :
        Instance(&SCX_OperatingSystem_Shutdown_rtti)
    {
    }
    
    SCX_OperatingSystem_Shutdown_Class(
        const SCX_OperatingSystem_Shutdown* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_OperatingSystem_Shutdown_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_OperatingSystem_Shutdown_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_OperatingSystem_Shutdown_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_OperatingSystem_Shutdown_Class& operator=(
        const SCX_OperatingSystem_Shutdown_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_OperatingSystem_Shutdown_Class(
        const SCX_OperatingSystem_Shutdown_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_OperatingSystem_Shutdown_Class.MIReturn
    //
    
    const Field<Uint32>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n);
    }
    
    void MIReturn(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).value;
    }
    
    void MIReturn_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Clear();
    }
};

typedef Array<SCX_OperatingSystem_Shutdown_Class> SCX_OperatingSystem_Shutdown_ClassA;

class SCX_OperatingSystem_ExecuteCommand_Class : public Instance
{
public:
    
    typedef SCX_OperatingSystem_ExecuteCommand Self;
    
    SCX_OperatingSystem_ExecuteCommand_Class() :
        Instance(&SCX_OperatingSystem_ExecuteCommand_rtti)
    {
    }
    
    SCX_OperatingSystem_ExecuteCommand_Class(
        const SCX_OperatingSystem_ExecuteCommand* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_OperatingSystem_ExecuteCommand_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_OperatingSystem_ExecuteCommand_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_OperatingSystem_ExecuteCommand_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_OperatingSystem_ExecuteCommand_Class& operator=(
        const SCX_OperatingSystem_ExecuteCommand_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_OperatingSystem_ExecuteCommand_Class(
        const SCX_OperatingSystem_ExecuteCommand_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_OperatingSystem_ExecuteCommand_Class.MIReturn
    //
    
    const Field<Boolean>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n);
    }
    
    void MIReturn(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).value;
    }
    
    void MIReturn_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteCommand_Class.Command
    //
    
    const Field<String>& Command() const
    {
        const size_t n = offsetof(Self, Command);
        return GetField<String>(n);
    }
    
    void Command(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Command);
        GetField<String>(n) = x;
    }
    
    const String& Command_value() const
    {
        const size_t n = offsetof(Self, Command);
        return GetField<String>(n).value;
    }
    
    void Command_value(const String& x)
    {
        const size_t n = offsetof(Self, Command);
        GetField<String>(n).Set(x);
    }
    
    bool Command_exists() const
    {
        const size_t n = offsetof(Self, Command);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Command_clear()
    {
        const size_t n = offsetof(Self, Command);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteCommand_Class.ReturnCode
    //
    
    const Field<Sint32>& ReturnCode() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n);
    }
    
    void ReturnCode(const Field<Sint32>& x)
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n) = x;
    }
    
    const Sint32& ReturnCode_value() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n).value;
    }
    
    void ReturnCode_value(const Sint32& x)
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n).Set(x);
    }
    
    bool ReturnCode_exists() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n).exists ? true : false;
    }
    
    void ReturnCode_clear()
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteCommand_Class.StdOut
    //
    
    const Field<String>& StdOut() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n);
    }
    
    void StdOut(const Field<String>& x)
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n) = x;
    }
    
    const String& StdOut_value() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n).value;
    }
    
    void StdOut_value(const String& x)
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n).Set(x);
    }
    
    bool StdOut_exists() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n).exists ? true : false;
    }
    
    void StdOut_clear()
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteCommand_Class.StdErr
    //
    
    const Field<String>& StdErr() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n);
    }
    
    void StdErr(const Field<String>& x)
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n) = x;
    }
    
    const String& StdErr_value() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n).value;
    }
    
    void StdErr_value(const String& x)
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n).Set(x);
    }
    
    bool StdErr_exists() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n).exists ? true : false;
    }
    
    void StdErr_clear()
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteCommand_Class.timeout
    //
    
    const Field<Uint32>& timeout() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n);
    }
    
    void timeout(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& timeout_value() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n).value;
    }
    
    void timeout_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n).Set(x);
    }
    
    bool timeout_exists() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void timeout_clear()
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteCommand_Class.ElevationType
    //
    
    const Field<String>& ElevationType() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n);
    }
    
    void ElevationType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n) = x;
    }
    
    const String& ElevationType_value() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n).value;
    }
    
    void ElevationType_value(const String& x)
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n).Set(x);
    }
    
    bool ElevationType_exists() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ElevationType_clear()
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_OperatingSystem_ExecuteCommand_Class> SCX_OperatingSystem_ExecuteCommand_ClassA;

class SCX_OperatingSystem_ExecuteShellCommand_Class : public Instance
{
public:
    
    typedef SCX_OperatingSystem_ExecuteShellCommand Self;
    
    SCX_OperatingSystem_ExecuteShellCommand_Class() :
        Instance(&SCX_OperatingSystem_ExecuteShellCommand_rtti)
    {
    }
    
    SCX_OperatingSystem_ExecuteShellCommand_Class(
        const SCX_OperatingSystem_ExecuteShellCommand* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_OperatingSystem_ExecuteShellCommand_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_OperatingSystem_ExecuteShellCommand_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_OperatingSystem_ExecuteShellCommand_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_OperatingSystem_ExecuteShellCommand_Class& operator=(
        const SCX_OperatingSystem_ExecuteShellCommand_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_OperatingSystem_ExecuteShellCommand_Class(
        const SCX_OperatingSystem_ExecuteShellCommand_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_OperatingSystem_ExecuteShellCommand_Class.MIReturn
    //
    
    const Field<Boolean>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n);
    }
    
    void MIReturn(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).value;
    }
    
    void MIReturn_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteShellCommand_Class.Command
    //
    
    const Field<String>& Command() const
    {
        const size_t n = offsetof(Self, Command);
        return GetField<String>(n);
    }
    
    void Command(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Command);
        GetField<String>(n) = x;
    }
    
    const String& Command_value() const
    {
        const size_t n = offsetof(Self, Command);
        return GetField<String>(n).value;
    }
    
    void Command_value(const String& x)
    {
        const size_t n = offsetof(Self, Command);
        GetField<String>(n).Set(x);
    }
    
    bool Command_exists() const
    {
        const size_t n = offsetof(Self, Command);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Command_clear()
    {
        const size_t n = offsetof(Self, Command);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteShellCommand_Class.ReturnCode
    //
    
    const Field<Sint32>& ReturnCode() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n);
    }
    
    void ReturnCode(const Field<Sint32>& x)
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n) = x;
    }
    
    const Sint32& ReturnCode_value() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n).value;
    }
    
    void ReturnCode_value(const Sint32& x)
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n).Set(x);
    }
    
    bool ReturnCode_exists() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n).exists ? true : false;
    }
    
    void ReturnCode_clear()
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteShellCommand_Class.StdOut
    //
    
    const Field<String>& StdOut() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n);
    }
    
    void StdOut(const Field<String>& x)
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n) = x;
    }
    
    const String& StdOut_value() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n).value;
    }
    
    void StdOut_value(const String& x)
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n).Set(x);
    }
    
    bool StdOut_exists() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n).exists ? true : false;
    }
    
    void StdOut_clear()
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteShellCommand_Class.StdErr
    //
    
    const Field<String>& StdErr() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n);
    }
    
    void StdErr(const Field<String>& x)
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n) = x;
    }
    
    const String& StdErr_value() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n).value;
    }
    
    void StdErr_value(const String& x)
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n).Set(x);
    }
    
    bool StdErr_exists() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n).exists ? true : false;
    }
    
    void StdErr_clear()
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteShellCommand_Class.timeout
    //
    
    const Field<Uint32>& timeout() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n);
    }
    
    void timeout(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& timeout_value() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n).value;
    }
    
    void timeout_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n).Set(x);
    }
    
    bool timeout_exists() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void timeout_clear()
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteShellCommand_Class.ElevationType
    //
    
    const Field<String>& ElevationType() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n);
    }
    
    void ElevationType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n) = x;
    }
    
    const String& ElevationType_value() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n).value;
    }
    
    void ElevationType_value(const String& x)
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n).Set(x);
    }
    
    bool ElevationType_exists() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ElevationType_clear()
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_OperatingSystem_ExecuteShellCommand_Class> SCX_OperatingSystem_ExecuteShellCommand_ClassA;

class SCX_OperatingSystem_ExecuteScript_Class : public Instance
{
public:
    
    typedef SCX_OperatingSystem_ExecuteScript Self;
    
    SCX_OperatingSystem_ExecuteScript_Class() :
        Instance(&SCX_OperatingSystem_ExecuteScript_rtti)
    {
    }
    
    SCX_OperatingSystem_ExecuteScript_Class(
        const SCX_OperatingSystem_ExecuteScript* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_OperatingSystem_ExecuteScript_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_OperatingSystem_ExecuteScript_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_OperatingSystem_ExecuteScript_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_OperatingSystem_ExecuteScript_Class& operator=(
        const SCX_OperatingSystem_ExecuteScript_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_OperatingSystem_ExecuteScript_Class(
        const SCX_OperatingSystem_ExecuteScript_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.MIReturn
    //
    
    const Field<Boolean>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n);
    }
    
    void MIReturn(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).value;
    }
    
    void MIReturn_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.Script
    //
    
    const Field<String>& Script() const
    {
        const size_t n = offsetof(Self, Script);
        return GetField<String>(n);
    }
    
    void Script(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Script);
        GetField<String>(n) = x;
    }
    
    const String& Script_value() const
    {
        const size_t n = offsetof(Self, Script);
        return GetField<String>(n).value;
    }
    
    void Script_value(const String& x)
    {
        const size_t n = offsetof(Self, Script);
        GetField<String>(n).Set(x);
    }
    
    bool Script_exists() const
    {
        const size_t n = offsetof(Self, Script);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Script_clear()
    {
        const size_t n = offsetof(Self, Script);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.Arguments
    //
    
    const Field<String>& Arguments() const
    {
        const size_t n = offsetof(Self, Arguments);
        return GetField<String>(n);
    }
    
    void Arguments(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Arguments);
        GetField<String>(n) = x;
    }
    
    const String& Arguments_value() const
    {
        const size_t n = offsetof(Self, Arguments);
        return GetField<String>(n).value;
    }
    
    void Arguments_value(const String& x)
    {
        const size_t n = offsetof(Self, Arguments);
        GetField<String>(n).Set(x);
    }
    
    bool Arguments_exists() const
    {
        const size_t n = offsetof(Self, Arguments);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Arguments_clear()
    {
        const size_t n = offsetof(Self, Arguments);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.ReturnCode
    //
    
    const Field<Sint32>& ReturnCode() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n);
    }
    
    void ReturnCode(const Field<Sint32>& x)
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n) = x;
    }
    
    const Sint32& ReturnCode_value() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n).value;
    }
    
    void ReturnCode_value(const Sint32& x)
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n).Set(x);
    }
    
    bool ReturnCode_exists() const
    {
        const size_t n = offsetof(Self, ReturnCode);
        return GetField<Sint32>(n).exists ? true : false;
    }
    
    void ReturnCode_clear()
    {
        const size_t n = offsetof(Self, ReturnCode);
        GetField<Sint32>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.StdOut
    //
    
    const Field<String>& StdOut() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n);
    }
    
    void StdOut(const Field<String>& x)
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n) = x;
    }
    
    const String& StdOut_value() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n).value;
    }
    
    void StdOut_value(const String& x)
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n).Set(x);
    }
    
    bool StdOut_exists() const
    {
        const size_t n = offsetof(Self, StdOut);
        return GetField<String>(n).exists ? true : false;
    }
    
    void StdOut_clear()
    {
        const size_t n = offsetof(Self, StdOut);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.StdErr
    //
    
    const Field<String>& StdErr() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n);
    }
    
    void StdErr(const Field<String>& x)
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n) = x;
    }
    
    const String& StdErr_value() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n).value;
    }
    
    void StdErr_value(const String& x)
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n).Set(x);
    }
    
    bool StdErr_exists() const
    {
        const size_t n = offsetof(Self, StdErr);
        return GetField<String>(n).exists ? true : false;
    }
    
    void StdErr_clear()
    {
        const size_t n = offsetof(Self, StdErr);
        GetField<String>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.timeout
    //
    
    const Field<Uint32>& timeout() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n);
    }
    
    void timeout(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& timeout_value() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n).value;
    }
    
    void timeout_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n).Set(x);
    }
    
    bool timeout_exists() const
    {
        const size_t n = offsetof(Self, timeout);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void timeout_clear()
    {
        const size_t n = offsetof(Self, timeout);
        GetField<Uint32>(n).Clear();
    }

    //
    // SCX_OperatingSystem_ExecuteScript_Class.ElevationType
    //
    
    const Field<String>& ElevationType() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n);
    }
    
    void ElevationType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n) = x;
    }
    
    const String& ElevationType_value() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n).value;
    }
    
    void ElevationType_value(const String& x)
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n).Set(x);
    }
    
    bool ElevationType_exists() const
    {
        const size_t n = offsetof(Self, ElevationType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ElevationType_clear()
    {
        const size_t n = offsetof(Self, ElevationType);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_OperatingSystem_ExecuteScript_Class> SCX_OperatingSystem_ExecuteScript_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_OperatingSystem_h */
