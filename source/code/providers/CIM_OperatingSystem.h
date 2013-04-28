/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_OperatingSystem_h
#define _CIM_OperatingSystem_h

#include <MI.h>
#include "CIM_EnabledLogicalElement.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_OperatingSystem [CIM_OperatingSystem]
**
** Keys:
**    Name
**    CSCreationClassName
**    CSName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _CIM_OperatingSystem /* extends CIM_EnabledLogicalElement */
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
}
CIM_OperatingSystem;

typedef struct _CIM_OperatingSystem_Ref
{
    CIM_OperatingSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_OperatingSystem_Ref;

typedef struct _CIM_OperatingSystem_ConstRef
{
    MI_CONST CIM_OperatingSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_OperatingSystem_ConstRef;

typedef struct _CIM_OperatingSystem_Array
{
    struct _CIM_OperatingSystem** data;
    MI_Uint32 size;
}
CIM_OperatingSystem_Array;

typedef struct _CIM_OperatingSystem_ConstArray
{
    struct _CIM_OperatingSystem MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_OperatingSystem_ConstArray;

typedef struct _CIM_OperatingSystem_ArrayRef
{
    CIM_OperatingSystem_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_OperatingSystem_ArrayRef;

typedef struct _CIM_OperatingSystem_ConstArrayRef
{
    CIM_OperatingSystem_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_OperatingSystem_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_OperatingSystem_rtti;

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Construct(
    CIM_OperatingSystem* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_OperatingSystem_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clone(
    const CIM_OperatingSystem* self,
    CIM_OperatingSystem** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_OperatingSystem_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_OperatingSystem_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Destruct(CIM_OperatingSystem* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Delete(CIM_OperatingSystem* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Post(
    const CIM_OperatingSystem* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_InstanceID(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_InstanceID(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_InstanceID(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_Caption(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_Caption(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_Caption(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_Description(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_Description(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_Description(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_ElementName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_ElementName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_ElementName(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_InstallDate(
    CIM_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_InstallDate(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_Name(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_Name(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_Name(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_OperationalStatus(
    CIM_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_OperationalStatus(
    CIM_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_OperationalStatus(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_StatusDescriptions(
    CIM_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_StatusDescriptions(
    CIM_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_StatusDescriptions(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_Status(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_Status(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_Status(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_HealthState(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_HealthState(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_CommunicationStatus(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_CommunicationStatus(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_DetailedStatus(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_DetailedStatus(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_OperatingStatus(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_OperatingStatus(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_PrimaryStatus(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_PrimaryStatus(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_EnabledState(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_EnabledState(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_OtherEnabledState(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_OtherEnabledState(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_OtherEnabledState(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_RequestedState(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_RequestedState(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_EnabledDefault(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_EnabledDefault(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_TimeOfLastStateChange(
    CIM_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_TimeOfLastStateChange(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_AvailableRequestedStates(
    CIM_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_AvailableRequestedStates(
    CIM_OperatingSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_AvailableRequestedStates(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_TransitioningToState(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_TransitioningToState(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_CSCreationClassName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_CSCreationClassName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_CSCreationClassName(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_CSName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_CSName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_CSName(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_CreationClassName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_CreationClassName(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_CreationClassName(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_OSType(
    CIM_OperatingSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OSType)->value = x;
    ((MI_Uint16Field*)&self->OSType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_OSType(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->OSType, 0, sizeof(self->OSType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_OtherTypeDescription(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_OtherTypeDescription(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_OtherTypeDescription(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        25);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_Version(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_SetPtr_Version(
    CIM_OperatingSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_Version(
    CIM_OperatingSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_LastBootUpTime(
    CIM_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastBootUpTime)->value = x;
    ((MI_DatetimeField*)&self->LastBootUpTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_LastBootUpTime(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->LastBootUpTime, 0, sizeof(self->LastBootUpTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_LocalDateTime(
    CIM_OperatingSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LocalDateTime)->value = x;
    ((MI_DatetimeField*)&self->LocalDateTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_LocalDateTime(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->LocalDateTime, 0, sizeof(self->LocalDateTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_CurrentTimeZone(
    CIM_OperatingSystem* self,
    MI_Sint16 x)
{
    ((MI_Sint16Field*)&self->CurrentTimeZone)->value = x;
    ((MI_Sint16Field*)&self->CurrentTimeZone)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_CurrentTimeZone(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->CurrentTimeZone, 0, sizeof(self->CurrentTimeZone));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_NumberOfLicensedUsers(
    CIM_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfLicensedUsers)->value = x;
    ((MI_Uint32Field*)&self->NumberOfLicensedUsers)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_NumberOfLicensedUsers(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->NumberOfLicensedUsers, 0, sizeof(self->NumberOfLicensedUsers));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_NumberOfUsers(
    CIM_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfUsers)->value = x;
    ((MI_Uint32Field*)&self->NumberOfUsers)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_NumberOfUsers(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->NumberOfUsers, 0, sizeof(self->NumberOfUsers));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_NumberOfProcesses(
    CIM_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfProcesses)->value = x;
    ((MI_Uint32Field*)&self->NumberOfProcesses)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_NumberOfProcesses(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->NumberOfProcesses, 0, sizeof(self->NumberOfProcesses));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_MaxNumberOfProcesses(
    CIM_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxNumberOfProcesses)->value = x;
    ((MI_Uint32Field*)&self->MaxNumberOfProcesses)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_MaxNumberOfProcesses(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->MaxNumberOfProcesses, 0, sizeof(self->MaxNumberOfProcesses));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_TotalSwapSpaceSize(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalSwapSpaceSize)->value = x;
    ((MI_Uint64Field*)&self->TotalSwapSpaceSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_TotalSwapSpaceSize(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->TotalSwapSpaceSize, 0, sizeof(self->TotalSwapSpaceSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_TotalVirtualMemorySize(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalVirtualMemorySize)->value = x;
    ((MI_Uint64Field*)&self->TotalVirtualMemorySize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_TotalVirtualMemorySize(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->TotalVirtualMemorySize, 0, sizeof(self->TotalVirtualMemorySize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_FreeVirtualMemory(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreeVirtualMemory)->value = x;
    ((MI_Uint64Field*)&self->FreeVirtualMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_FreeVirtualMemory(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->FreeVirtualMemory, 0, sizeof(self->FreeVirtualMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_FreePhysicalMemory(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreePhysicalMemory)->value = x;
    ((MI_Uint64Field*)&self->FreePhysicalMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_FreePhysicalMemory(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->FreePhysicalMemory, 0, sizeof(self->FreePhysicalMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_TotalVisibleMemorySize(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalVisibleMemorySize)->value = x;
    ((MI_Uint64Field*)&self->TotalVisibleMemorySize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_TotalVisibleMemorySize(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->TotalVisibleMemorySize, 0, sizeof(self->TotalVisibleMemorySize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_SizeStoredInPagingFiles(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->SizeStoredInPagingFiles)->value = x;
    ((MI_Uint64Field*)&self->SizeStoredInPagingFiles)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_SizeStoredInPagingFiles(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->SizeStoredInPagingFiles, 0, sizeof(self->SizeStoredInPagingFiles));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_FreeSpaceInPagingFiles(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreeSpaceInPagingFiles)->value = x;
    ((MI_Uint64Field*)&self->FreeSpaceInPagingFiles)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_FreeSpaceInPagingFiles(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->FreeSpaceInPagingFiles, 0, sizeof(self->FreeSpaceInPagingFiles));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_MaxProcessMemorySize(
    CIM_OperatingSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxProcessMemorySize)->value = x;
    ((MI_Uint64Field*)&self->MaxProcessMemorySize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_MaxProcessMemorySize(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->MaxProcessMemorySize, 0, sizeof(self->MaxProcessMemorySize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_Distributed(
    CIM_OperatingSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Distributed)->value = x;
    ((MI_BooleanField*)&self->Distributed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_Distributed(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->Distributed, 0, sizeof(self->Distributed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Set_MaxProcessesPerUser(
    CIM_OperatingSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxProcessesPerUser)->value = x;
    ((MI_Uint32Field*)&self->MaxProcessesPerUser)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Clear_MaxProcessesPerUser(
    CIM_OperatingSystem* self)
{
    memset((void*)&self->MaxProcessesPerUser, 0, sizeof(self->MaxProcessesPerUser));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_OperatingSystem.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_OperatingSystem_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_OperatingSystem_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Set_MIReturn(
    CIM_OperatingSystem_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Clear_MIReturn(
    CIM_OperatingSystem_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Set_RequestedState(
    CIM_OperatingSystem_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Clear_RequestedState(
    CIM_OperatingSystem_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Set_Job(
    CIM_OperatingSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_SetPtr_Job(
    CIM_OperatingSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Clear_Job(
    CIM_OperatingSystem_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Set_TimeoutPeriod(
    CIM_OperatingSystem_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_RequestStateChange_Clear_TimeoutPeriod(
    CIM_OperatingSystem_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_OperatingSystem.Reboot()
**
**==============================================================================
*/

typedef struct _CIM_OperatingSystem_Reboot
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_OperatingSystem_Reboot;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_OperatingSystem_Reboot_rtti;

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Reboot_Construct(
    CIM_OperatingSystem_Reboot* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_OperatingSystem_Reboot_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Reboot_Clone(
    const CIM_OperatingSystem_Reboot* self,
    CIM_OperatingSystem_Reboot** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Reboot_Destruct(
    CIM_OperatingSystem_Reboot* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Reboot_Delete(
    CIM_OperatingSystem_Reboot* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Reboot_Post(
    const CIM_OperatingSystem_Reboot* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Reboot_Set_MIReturn(
    CIM_OperatingSystem_Reboot* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Reboot_Clear_MIReturn(
    CIM_OperatingSystem_Reboot* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_OperatingSystem.Shutdown()
**
**==============================================================================
*/

typedef struct _CIM_OperatingSystem_Shutdown
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_OperatingSystem_Shutdown;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_OperatingSystem_Shutdown_rtti;

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Shutdown_Construct(
    CIM_OperatingSystem_Shutdown* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_OperatingSystem_Shutdown_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Shutdown_Clone(
    const CIM_OperatingSystem_Shutdown* self,
    CIM_OperatingSystem_Shutdown** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Shutdown_Destruct(
    CIM_OperatingSystem_Shutdown* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Shutdown_Delete(
    CIM_OperatingSystem_Shutdown* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Shutdown_Post(
    const CIM_OperatingSystem_Shutdown* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Shutdown_Set_MIReturn(
    CIM_OperatingSystem_Shutdown* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_OperatingSystem_Shutdown_Clear_MIReturn(
    CIM_OperatingSystem_Shutdown* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_OperatingSystem_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_OperatingSystem_Class : public CIM_EnabledLogicalElement_Class
{
public:
    
    typedef CIM_OperatingSystem Self;
    
    CIM_OperatingSystem_Class() :
        CIM_EnabledLogicalElement_Class(&CIM_OperatingSystem_rtti)
    {
    }
    
    CIM_OperatingSystem_Class(
        const CIM_OperatingSystem* instanceName,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(
            &CIM_OperatingSystem_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_OperatingSystem_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_OperatingSystem_Class(
        const MI_ClassDecl* clDecl) :
        CIM_EnabledLogicalElement_Class(clDecl)
    {
    }
    
    CIM_OperatingSystem_Class& operator=(
        const CIM_OperatingSystem_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_OperatingSystem_Class(
        const CIM_OperatingSystem_Class& x) :
        CIM_EnabledLogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_OperatingSystem_rtti;
    }

    //
    // CIM_OperatingSystem_Class.CSCreationClassName
    //
    
    const Field<String>& CSCreationClassName() const
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        return GetField<String>(n);
    }
    
    void CSCreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& CSCreationClassName_value() const
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        return GetField<String>(n).value;
    }
    
    void CSCreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool CSCreationClassName_exists() const
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CSCreationClassName_clear()
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.CSName
    //
    
    const Field<String>& CSName() const
    {
        const size_t n = offsetof(Self, CSName);
        return GetField<String>(n);
    }
    
    void CSName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CSName);
        GetField<String>(n) = x;
    }
    
    const String& CSName_value() const
    {
        const size_t n = offsetof(Self, CSName);
        return GetField<String>(n).value;
    }
    
    void CSName_value(const String& x)
    {
        const size_t n = offsetof(Self, CSName);
        GetField<String>(n).Set(x);
    }
    
    bool CSName_exists() const
    {
        const size_t n = offsetof(Self, CSName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CSName_clear()
    {
        const size_t n = offsetof(Self, CSName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.CreationClassName
    //
    
    const Field<String>& CreationClassName() const
    {
        const size_t n = offsetof(Self, CreationClassName);
        return GetField<String>(n);
    }
    
    void CreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& CreationClassName_value() const
    {
        const size_t n = offsetof(Self, CreationClassName);
        return GetField<String>(n).value;
    }
    
    void CreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, CreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool CreationClassName_exists() const
    {
        const size_t n = offsetof(Self, CreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CreationClassName_clear()
    {
        const size_t n = offsetof(Self, CreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.OSType
    //
    
    const Field<Uint16>& OSType() const
    {
        const size_t n = offsetof(Self, OSType);
        return GetField<Uint16>(n);
    }
    
    void OSType(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, OSType);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& OSType_value() const
    {
        const size_t n = offsetof(Self, OSType);
        return GetField<Uint16>(n).value;
    }
    
    void OSType_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, OSType);
        GetField<Uint16>(n).Set(x);
    }
    
    bool OSType_exists() const
    {
        const size_t n = offsetof(Self, OSType);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void OSType_clear()
    {
        const size_t n = offsetof(Self, OSType);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.OtherTypeDescription
    //
    
    const Field<String>& OtherTypeDescription() const
    {
        const size_t n = offsetof(Self, OtherTypeDescription);
        return GetField<String>(n);
    }
    
    void OtherTypeDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherTypeDescription);
        GetField<String>(n) = x;
    }
    
    const String& OtherTypeDescription_value() const
    {
        const size_t n = offsetof(Self, OtherTypeDescription);
        return GetField<String>(n).value;
    }
    
    void OtherTypeDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherTypeDescription);
        GetField<String>(n).Set(x);
    }
    
    bool OtherTypeDescription_exists() const
    {
        const size_t n = offsetof(Self, OtherTypeDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherTypeDescription_clear()
    {
        const size_t n = offsetof(Self, OtherTypeDescription);
        GetField<String>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.Version
    //
    
    const Field<String>& Version() const
    {
        const size_t n = offsetof(Self, Version);
        return GetField<String>(n);
    }
    
    void Version(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Version);
        GetField<String>(n) = x;
    }
    
    const String& Version_value() const
    {
        const size_t n = offsetof(Self, Version);
        return GetField<String>(n).value;
    }
    
    void Version_value(const String& x)
    {
        const size_t n = offsetof(Self, Version);
        GetField<String>(n).Set(x);
    }
    
    bool Version_exists() const
    {
        const size_t n = offsetof(Self, Version);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Version_clear()
    {
        const size_t n = offsetof(Self, Version);
        GetField<String>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.LastBootUpTime
    //
    
    const Field<Datetime>& LastBootUpTime() const
    {
        const size_t n = offsetof(Self, LastBootUpTime);
        return GetField<Datetime>(n);
    }
    
    void LastBootUpTime(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, LastBootUpTime);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& LastBootUpTime_value() const
    {
        const size_t n = offsetof(Self, LastBootUpTime);
        return GetField<Datetime>(n).value;
    }
    
    void LastBootUpTime_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, LastBootUpTime);
        GetField<Datetime>(n).Set(x);
    }
    
    bool LastBootUpTime_exists() const
    {
        const size_t n = offsetof(Self, LastBootUpTime);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void LastBootUpTime_clear()
    {
        const size_t n = offsetof(Self, LastBootUpTime);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.LocalDateTime
    //
    
    const Field<Datetime>& LocalDateTime() const
    {
        const size_t n = offsetof(Self, LocalDateTime);
        return GetField<Datetime>(n);
    }
    
    void LocalDateTime(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, LocalDateTime);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& LocalDateTime_value() const
    {
        const size_t n = offsetof(Self, LocalDateTime);
        return GetField<Datetime>(n).value;
    }
    
    void LocalDateTime_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, LocalDateTime);
        GetField<Datetime>(n).Set(x);
    }
    
    bool LocalDateTime_exists() const
    {
        const size_t n = offsetof(Self, LocalDateTime);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void LocalDateTime_clear()
    {
        const size_t n = offsetof(Self, LocalDateTime);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.CurrentTimeZone
    //
    
    const Field<Sint16>& CurrentTimeZone() const
    {
        const size_t n = offsetof(Self, CurrentTimeZone);
        return GetField<Sint16>(n);
    }
    
    void CurrentTimeZone(const Field<Sint16>& x)
    {
        const size_t n = offsetof(Self, CurrentTimeZone);
        GetField<Sint16>(n) = x;
    }
    
    const Sint16& CurrentTimeZone_value() const
    {
        const size_t n = offsetof(Self, CurrentTimeZone);
        return GetField<Sint16>(n).value;
    }
    
    void CurrentTimeZone_value(const Sint16& x)
    {
        const size_t n = offsetof(Self, CurrentTimeZone);
        GetField<Sint16>(n).Set(x);
    }
    
    bool CurrentTimeZone_exists() const
    {
        const size_t n = offsetof(Self, CurrentTimeZone);
        return GetField<Sint16>(n).exists ? true : false;
    }
    
    void CurrentTimeZone_clear()
    {
        const size_t n = offsetof(Self, CurrentTimeZone);
        GetField<Sint16>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.NumberOfLicensedUsers
    //
    
    const Field<Uint32>& NumberOfLicensedUsers() const
    {
        const size_t n = offsetof(Self, NumberOfLicensedUsers);
        return GetField<Uint32>(n);
    }
    
    void NumberOfLicensedUsers(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, NumberOfLicensedUsers);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& NumberOfLicensedUsers_value() const
    {
        const size_t n = offsetof(Self, NumberOfLicensedUsers);
        return GetField<Uint32>(n).value;
    }
    
    void NumberOfLicensedUsers_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, NumberOfLicensedUsers);
        GetField<Uint32>(n).Set(x);
    }
    
    bool NumberOfLicensedUsers_exists() const
    {
        const size_t n = offsetof(Self, NumberOfLicensedUsers);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void NumberOfLicensedUsers_clear()
    {
        const size_t n = offsetof(Self, NumberOfLicensedUsers);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.NumberOfUsers
    //
    
    const Field<Uint32>& NumberOfUsers() const
    {
        const size_t n = offsetof(Self, NumberOfUsers);
        return GetField<Uint32>(n);
    }
    
    void NumberOfUsers(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, NumberOfUsers);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& NumberOfUsers_value() const
    {
        const size_t n = offsetof(Self, NumberOfUsers);
        return GetField<Uint32>(n).value;
    }
    
    void NumberOfUsers_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, NumberOfUsers);
        GetField<Uint32>(n).Set(x);
    }
    
    bool NumberOfUsers_exists() const
    {
        const size_t n = offsetof(Self, NumberOfUsers);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void NumberOfUsers_clear()
    {
        const size_t n = offsetof(Self, NumberOfUsers);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.NumberOfProcesses
    //
    
    const Field<Uint32>& NumberOfProcesses() const
    {
        const size_t n = offsetof(Self, NumberOfProcesses);
        return GetField<Uint32>(n);
    }
    
    void NumberOfProcesses(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, NumberOfProcesses);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& NumberOfProcesses_value() const
    {
        const size_t n = offsetof(Self, NumberOfProcesses);
        return GetField<Uint32>(n).value;
    }
    
    void NumberOfProcesses_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, NumberOfProcesses);
        GetField<Uint32>(n).Set(x);
    }
    
    bool NumberOfProcesses_exists() const
    {
        const size_t n = offsetof(Self, NumberOfProcesses);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void NumberOfProcesses_clear()
    {
        const size_t n = offsetof(Self, NumberOfProcesses);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.MaxNumberOfProcesses
    //
    
    const Field<Uint32>& MaxNumberOfProcesses() const
    {
        const size_t n = offsetof(Self, MaxNumberOfProcesses);
        return GetField<Uint32>(n);
    }
    
    void MaxNumberOfProcesses(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MaxNumberOfProcesses);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MaxNumberOfProcesses_value() const
    {
        const size_t n = offsetof(Self, MaxNumberOfProcesses);
        return GetField<Uint32>(n).value;
    }
    
    void MaxNumberOfProcesses_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MaxNumberOfProcesses);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MaxNumberOfProcesses_exists() const
    {
        const size_t n = offsetof(Self, MaxNumberOfProcesses);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MaxNumberOfProcesses_clear()
    {
        const size_t n = offsetof(Self, MaxNumberOfProcesses);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.TotalSwapSpaceSize
    //
    
    const Field<Uint64>& TotalSwapSpaceSize() const
    {
        const size_t n = offsetof(Self, TotalSwapSpaceSize);
        return GetField<Uint64>(n);
    }
    
    void TotalSwapSpaceSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalSwapSpaceSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalSwapSpaceSize_value() const
    {
        const size_t n = offsetof(Self, TotalSwapSpaceSize);
        return GetField<Uint64>(n).value;
    }
    
    void TotalSwapSpaceSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalSwapSpaceSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalSwapSpaceSize_exists() const
    {
        const size_t n = offsetof(Self, TotalSwapSpaceSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalSwapSpaceSize_clear()
    {
        const size_t n = offsetof(Self, TotalSwapSpaceSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.TotalVirtualMemorySize
    //
    
    const Field<Uint64>& TotalVirtualMemorySize() const
    {
        const size_t n = offsetof(Self, TotalVirtualMemorySize);
        return GetField<Uint64>(n);
    }
    
    void TotalVirtualMemorySize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalVirtualMemorySize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalVirtualMemorySize_value() const
    {
        const size_t n = offsetof(Self, TotalVirtualMemorySize);
        return GetField<Uint64>(n).value;
    }
    
    void TotalVirtualMemorySize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalVirtualMemorySize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalVirtualMemorySize_exists() const
    {
        const size_t n = offsetof(Self, TotalVirtualMemorySize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalVirtualMemorySize_clear()
    {
        const size_t n = offsetof(Self, TotalVirtualMemorySize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.FreeVirtualMemory
    //
    
    const Field<Uint64>& FreeVirtualMemory() const
    {
        const size_t n = offsetof(Self, FreeVirtualMemory);
        return GetField<Uint64>(n);
    }
    
    void FreeVirtualMemory(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, FreeVirtualMemory);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& FreeVirtualMemory_value() const
    {
        const size_t n = offsetof(Self, FreeVirtualMemory);
        return GetField<Uint64>(n).value;
    }
    
    void FreeVirtualMemory_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, FreeVirtualMemory);
        GetField<Uint64>(n).Set(x);
    }
    
    bool FreeVirtualMemory_exists() const
    {
        const size_t n = offsetof(Self, FreeVirtualMemory);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void FreeVirtualMemory_clear()
    {
        const size_t n = offsetof(Self, FreeVirtualMemory);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.FreePhysicalMemory
    //
    
    const Field<Uint64>& FreePhysicalMemory() const
    {
        const size_t n = offsetof(Self, FreePhysicalMemory);
        return GetField<Uint64>(n);
    }
    
    void FreePhysicalMemory(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, FreePhysicalMemory);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& FreePhysicalMemory_value() const
    {
        const size_t n = offsetof(Self, FreePhysicalMemory);
        return GetField<Uint64>(n).value;
    }
    
    void FreePhysicalMemory_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, FreePhysicalMemory);
        GetField<Uint64>(n).Set(x);
    }
    
    bool FreePhysicalMemory_exists() const
    {
        const size_t n = offsetof(Self, FreePhysicalMemory);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void FreePhysicalMemory_clear()
    {
        const size_t n = offsetof(Self, FreePhysicalMemory);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.TotalVisibleMemorySize
    //
    
    const Field<Uint64>& TotalVisibleMemorySize() const
    {
        const size_t n = offsetof(Self, TotalVisibleMemorySize);
        return GetField<Uint64>(n);
    }
    
    void TotalVisibleMemorySize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalVisibleMemorySize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalVisibleMemorySize_value() const
    {
        const size_t n = offsetof(Self, TotalVisibleMemorySize);
        return GetField<Uint64>(n).value;
    }
    
    void TotalVisibleMemorySize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalVisibleMemorySize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalVisibleMemorySize_exists() const
    {
        const size_t n = offsetof(Self, TotalVisibleMemorySize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalVisibleMemorySize_clear()
    {
        const size_t n = offsetof(Self, TotalVisibleMemorySize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.SizeStoredInPagingFiles
    //
    
    const Field<Uint64>& SizeStoredInPagingFiles() const
    {
        const size_t n = offsetof(Self, SizeStoredInPagingFiles);
        return GetField<Uint64>(n);
    }
    
    void SizeStoredInPagingFiles(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, SizeStoredInPagingFiles);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& SizeStoredInPagingFiles_value() const
    {
        const size_t n = offsetof(Self, SizeStoredInPagingFiles);
        return GetField<Uint64>(n).value;
    }
    
    void SizeStoredInPagingFiles_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, SizeStoredInPagingFiles);
        GetField<Uint64>(n).Set(x);
    }
    
    bool SizeStoredInPagingFiles_exists() const
    {
        const size_t n = offsetof(Self, SizeStoredInPagingFiles);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void SizeStoredInPagingFiles_clear()
    {
        const size_t n = offsetof(Self, SizeStoredInPagingFiles);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.FreeSpaceInPagingFiles
    //
    
    const Field<Uint64>& FreeSpaceInPagingFiles() const
    {
        const size_t n = offsetof(Self, FreeSpaceInPagingFiles);
        return GetField<Uint64>(n);
    }
    
    void FreeSpaceInPagingFiles(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, FreeSpaceInPagingFiles);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& FreeSpaceInPagingFiles_value() const
    {
        const size_t n = offsetof(Self, FreeSpaceInPagingFiles);
        return GetField<Uint64>(n).value;
    }
    
    void FreeSpaceInPagingFiles_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, FreeSpaceInPagingFiles);
        GetField<Uint64>(n).Set(x);
    }
    
    bool FreeSpaceInPagingFiles_exists() const
    {
        const size_t n = offsetof(Self, FreeSpaceInPagingFiles);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void FreeSpaceInPagingFiles_clear()
    {
        const size_t n = offsetof(Self, FreeSpaceInPagingFiles);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.MaxProcessMemorySize
    //
    
    const Field<Uint64>& MaxProcessMemorySize() const
    {
        const size_t n = offsetof(Self, MaxProcessMemorySize);
        return GetField<Uint64>(n);
    }
    
    void MaxProcessMemorySize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MaxProcessMemorySize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MaxProcessMemorySize_value() const
    {
        const size_t n = offsetof(Self, MaxProcessMemorySize);
        return GetField<Uint64>(n).value;
    }
    
    void MaxProcessMemorySize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MaxProcessMemorySize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MaxProcessMemorySize_exists() const
    {
        const size_t n = offsetof(Self, MaxProcessMemorySize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MaxProcessMemorySize_clear()
    {
        const size_t n = offsetof(Self, MaxProcessMemorySize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.Distributed
    //
    
    const Field<Boolean>& Distributed() const
    {
        const size_t n = offsetof(Self, Distributed);
        return GetField<Boolean>(n);
    }
    
    void Distributed(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Distributed);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Distributed_value() const
    {
        const size_t n = offsetof(Self, Distributed);
        return GetField<Boolean>(n).value;
    }
    
    void Distributed_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Distributed);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Distributed_exists() const
    {
        const size_t n = offsetof(Self, Distributed);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Distributed_clear()
    {
        const size_t n = offsetof(Self, Distributed);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_OperatingSystem_Class.MaxProcessesPerUser
    //
    
    const Field<Uint32>& MaxProcessesPerUser() const
    {
        const size_t n = offsetof(Self, MaxProcessesPerUser);
        return GetField<Uint32>(n);
    }
    
    void MaxProcessesPerUser(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MaxProcessesPerUser);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MaxProcessesPerUser_value() const
    {
        const size_t n = offsetof(Self, MaxProcessesPerUser);
        return GetField<Uint32>(n).value;
    }
    
    void MaxProcessesPerUser_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MaxProcessesPerUser);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MaxProcessesPerUser_exists() const
    {
        const size_t n = offsetof(Self, MaxProcessesPerUser);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MaxProcessesPerUser_clear()
    {
        const size_t n = offsetof(Self, MaxProcessesPerUser);
        GetField<Uint32>(n).Clear();
    }
};

typedef Array<CIM_OperatingSystem_Class> CIM_OperatingSystem_ClassA;

class CIM_OperatingSystem_Reboot_Class : public Instance
{
public:
    
    typedef CIM_OperatingSystem_Reboot Self;
    
    CIM_OperatingSystem_Reboot_Class() :
        Instance(&CIM_OperatingSystem_Reboot_rtti)
    {
    }
    
    CIM_OperatingSystem_Reboot_Class(
        const CIM_OperatingSystem_Reboot* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_OperatingSystem_Reboot_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_OperatingSystem_Reboot_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_OperatingSystem_Reboot_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_OperatingSystem_Reboot_Class& operator=(
        const CIM_OperatingSystem_Reboot_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_OperatingSystem_Reboot_Class(
        const CIM_OperatingSystem_Reboot_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_OperatingSystem_Reboot_Class.MIReturn
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

typedef Array<CIM_OperatingSystem_Reboot_Class> CIM_OperatingSystem_Reboot_ClassA;

class CIM_OperatingSystem_Shutdown_Class : public Instance
{
public:
    
    typedef CIM_OperatingSystem_Shutdown Self;
    
    CIM_OperatingSystem_Shutdown_Class() :
        Instance(&CIM_OperatingSystem_Shutdown_rtti)
    {
    }
    
    CIM_OperatingSystem_Shutdown_Class(
        const CIM_OperatingSystem_Shutdown* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_OperatingSystem_Shutdown_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_OperatingSystem_Shutdown_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_OperatingSystem_Shutdown_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_OperatingSystem_Shutdown_Class& operator=(
        const CIM_OperatingSystem_Shutdown_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_OperatingSystem_Shutdown_Class(
        const CIM_OperatingSystem_Shutdown_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_OperatingSystem_Shutdown_Class.MIReturn
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

typedef Array<CIM_OperatingSystem_Shutdown_Class> CIM_OperatingSystem_Shutdown_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_OperatingSystem_h */
