/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_UnixProcess_h
#define _CIM_UnixProcess_h

#include <MI.h>
#include "CIM_Process.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_UnixProcess [CIM_UnixProcess]
**
** Keys:
**    CSCreationClassName
**    CSName
**    OSCreationClassName
**    OSName
**    CreationClassName
**    Handle
**
**==============================================================================
*/

typedef struct _CIM_UnixProcess /* extends CIM_Process */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_ManagedSystemElement properties */
    MI_ConstDatetimeField InstallDate;
    MI_ConstStringField Name;
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
    /* CIM_Process properties */
    /*KEY*/ MI_ConstStringField CSCreationClassName;
    /*KEY*/ MI_ConstStringField CSName;
    /*KEY*/ MI_ConstStringField OSCreationClassName;
    /*KEY*/ MI_ConstStringField OSName;
    /*KEY*/ MI_ConstStringField CreationClassName;
    /*KEY*/ MI_ConstStringField Handle;
    MI_ConstUint32Field Priority;
    MI_ConstUint16Field ExecutionState;
    MI_ConstStringField OtherExecutionDescription;
    MI_ConstDatetimeField CreationDate;
    MI_ConstDatetimeField TerminationDate;
    MI_ConstUint64Field KernelModeTime;
    MI_ConstUint64Field UserModeTime;
    MI_ConstUint64Field WorkingSetSize;
    /* CIM_UnixProcess properties */
    MI_ConstStringField ParentProcessID;
    MI_ConstUint64Field RealUserID;
    MI_ConstUint64Field ProcessGroupID;
    MI_ConstUint64Field ProcessSessionID;
    MI_ConstStringField ProcessTTY;
    MI_ConstStringField ModulePath;
    MI_ConstStringAField Parameters;
    MI_ConstUint32Field ProcessNiceValue;
    MI_ConstStringField ProcessWaitingForEvent;
}
CIM_UnixProcess;

typedef struct _CIM_UnixProcess_Ref
{
    CIM_UnixProcess* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcess_Ref;

typedef struct _CIM_UnixProcess_ConstRef
{
    MI_CONST CIM_UnixProcess* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcess_ConstRef;

typedef struct _CIM_UnixProcess_Array
{
    struct _CIM_UnixProcess** data;
    MI_Uint32 size;
}
CIM_UnixProcess_Array;

typedef struct _CIM_UnixProcess_ConstArray
{
    struct _CIM_UnixProcess MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_UnixProcess_ConstArray;

typedef struct _CIM_UnixProcess_ArrayRef
{
    CIM_UnixProcess_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcess_ArrayRef;

typedef struct _CIM_UnixProcess_ConstArrayRef
{
    CIM_UnixProcess_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcess_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_UnixProcess_rtti;

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Construct(
    CIM_UnixProcess* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_UnixProcess_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clone(
    const CIM_UnixProcess* self,
    CIM_UnixProcess** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_UnixProcess_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_UnixProcess_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Destruct(CIM_UnixProcess* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Delete(CIM_UnixProcess* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Post(
    const CIM_UnixProcess* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_InstanceID(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_InstanceID(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_InstanceID(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_Caption(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_Caption(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_Caption(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_Description(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_Description(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_Description(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ElementName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_ElementName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ElementName(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_InstallDate(
    CIM_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_InstallDate(
    CIM_UnixProcess* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_Name(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_Name(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_Name(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_OperationalStatus(
    CIM_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_OperationalStatus(
    CIM_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_OperationalStatus(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_StatusDescriptions(
    CIM_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_StatusDescriptions(
    CIM_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_StatusDescriptions(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_Status(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_Status(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_Status(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_HealthState(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_HealthState(
    CIM_UnixProcess* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_CommunicationStatus(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_CommunicationStatus(
    CIM_UnixProcess* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_DetailedStatus(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_DetailedStatus(
    CIM_UnixProcess* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_OperatingStatus(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_OperatingStatus(
    CIM_UnixProcess* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_PrimaryStatus(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_PrimaryStatus(
    CIM_UnixProcess* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_EnabledState(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_EnabledState(
    CIM_UnixProcess* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_OtherEnabledState(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_OtherEnabledState(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_OtherEnabledState(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_RequestedState(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_RequestedState(
    CIM_UnixProcess* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_EnabledDefault(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_EnabledDefault(
    CIM_UnixProcess* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_TimeOfLastStateChange(
    CIM_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_TimeOfLastStateChange(
    CIM_UnixProcess* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_AvailableRequestedStates(
    CIM_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_AvailableRequestedStates(
    CIM_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_AvailableRequestedStates(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_TransitioningToState(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_TransitioningToState(
    CIM_UnixProcess* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_CSCreationClassName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_CSCreationClassName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_CSCreationClassName(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_CSName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_CSName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_CSName(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_OSCreationClassName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_OSCreationClassName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_OSCreationClassName(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_OSName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_OSName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_OSName(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_CreationClassName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_CreationClassName(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_CreationClassName(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        25);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_Handle(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_Handle(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_Handle(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_Priority(
    CIM_UnixProcess* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->Priority)->value = x;
    ((MI_Uint32Field*)&self->Priority)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_Priority(
    CIM_UnixProcess* self)
{
    memset((void*)&self->Priority, 0, sizeof(self->Priority));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ExecutionState(
    CIM_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ExecutionState)->value = x;
    ((MI_Uint16Field*)&self->ExecutionState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ExecutionState(
    CIM_UnixProcess* self)
{
    memset((void*)&self->ExecutionState, 0, sizeof(self->ExecutionState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_OtherExecutionDescription(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_OtherExecutionDescription(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_OtherExecutionDescription(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_CreationDate(
    CIM_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->CreationDate)->value = x;
    ((MI_DatetimeField*)&self->CreationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_CreationDate(
    CIM_UnixProcess* self)
{
    memset((void*)&self->CreationDate, 0, sizeof(self->CreationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_TerminationDate(
    CIM_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TerminationDate)->value = x;
    ((MI_DatetimeField*)&self->TerminationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_TerminationDate(
    CIM_UnixProcess* self)
{
    memset((void*)&self->TerminationDate, 0, sizeof(self->TerminationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_KernelModeTime(
    CIM_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->KernelModeTime)->value = x;
    ((MI_Uint64Field*)&self->KernelModeTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_KernelModeTime(
    CIM_UnixProcess* self)
{
    memset((void*)&self->KernelModeTime, 0, sizeof(self->KernelModeTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_UserModeTime(
    CIM_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UserModeTime)->value = x;
    ((MI_Uint64Field*)&self->UserModeTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_UserModeTime(
    CIM_UnixProcess* self)
{
    memset((void*)&self->UserModeTime, 0, sizeof(self->UserModeTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_WorkingSetSize(
    CIM_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->WorkingSetSize)->value = x;
    ((MI_Uint64Field*)&self->WorkingSetSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_WorkingSetSize(
    CIM_UnixProcess* self)
{
    memset((void*)&self->WorkingSetSize, 0, sizeof(self->WorkingSetSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ParentProcessID(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        35,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_ParentProcessID(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        35,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ParentProcessID(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_RealUserID(
    CIM_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealUserID)->value = x;
    ((MI_Uint64Field*)&self->RealUserID)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_RealUserID(
    CIM_UnixProcess* self)
{
    memset((void*)&self->RealUserID, 0, sizeof(self->RealUserID));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ProcessGroupID(
    CIM_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ProcessGroupID)->value = x;
    ((MI_Uint64Field*)&self->ProcessGroupID)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ProcessGroupID(
    CIM_UnixProcess* self)
{
    memset((void*)&self->ProcessGroupID, 0, sizeof(self->ProcessGroupID));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ProcessSessionID(
    CIM_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ProcessSessionID)->value = x;
    ((MI_Uint64Field*)&self->ProcessSessionID)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ProcessSessionID(
    CIM_UnixProcess* self)
{
    memset((void*)&self->ProcessSessionID, 0, sizeof(self->ProcessSessionID));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ProcessTTY(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_ProcessTTY(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ProcessTTY(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ModulePath(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_ModulePath(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ModulePath(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        40);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_Parameters(
    CIM_UnixProcess* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_Parameters(
    CIM_UnixProcess* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_Parameters(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ProcessNiceValue(
    CIM_UnixProcess* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ProcessNiceValue)->value = x;
    ((MI_Uint32Field*)&self->ProcessNiceValue)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ProcessNiceValue(
    CIM_UnixProcess* self)
{
    memset((void*)&self->ProcessNiceValue, 0, sizeof(self->ProcessNiceValue));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Set_ProcessWaitingForEvent(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_SetPtr_ProcessWaitingForEvent(
    CIM_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_Clear_ProcessWaitingForEvent(
    CIM_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        43);
}

/*
**==============================================================================
**
** CIM_UnixProcess.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_UnixProcess_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_UnixProcess_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Set_MIReturn(
    CIM_UnixProcess_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Clear_MIReturn(
    CIM_UnixProcess_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Set_RequestedState(
    CIM_UnixProcess_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Clear_RequestedState(
    CIM_UnixProcess_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Set_Job(
    CIM_UnixProcess_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_SetPtr_Job(
    CIM_UnixProcess_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Clear_Job(
    CIM_UnixProcess_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Set_TimeoutPeriod(
    CIM_UnixProcess_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcess_RequestStateChange_Clear_TimeoutPeriod(
    CIM_UnixProcess_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_UnixProcess_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_UnixProcess_Class : public CIM_Process_Class
{
public:
    
    typedef CIM_UnixProcess Self;
    
    CIM_UnixProcess_Class() :
        CIM_Process_Class(&CIM_UnixProcess_rtti)
    {
    }
    
    CIM_UnixProcess_Class(
        const CIM_UnixProcess* instanceName,
        bool keysOnly) :
        CIM_Process_Class(
            &CIM_UnixProcess_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_UnixProcess_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_Process_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_UnixProcess_Class(
        const MI_ClassDecl* clDecl) :
        CIM_Process_Class(clDecl)
    {
    }
    
    CIM_UnixProcess_Class& operator=(
        const CIM_UnixProcess_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_UnixProcess_Class(
        const CIM_UnixProcess_Class& x) :
        CIM_Process_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_UnixProcess_rtti;
    }

    //
    // CIM_UnixProcess_Class.ParentProcessID
    //
    
    const Field<String>& ParentProcessID() const
    {
        const size_t n = offsetof(Self, ParentProcessID);
        return GetField<String>(n);
    }
    
    void ParentProcessID(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ParentProcessID);
        GetField<String>(n) = x;
    }
    
    const String& ParentProcessID_value() const
    {
        const size_t n = offsetof(Self, ParentProcessID);
        return GetField<String>(n).value;
    }
    
    void ParentProcessID_value(const String& x)
    {
        const size_t n = offsetof(Self, ParentProcessID);
        GetField<String>(n).Set(x);
    }
    
    bool ParentProcessID_exists() const
    {
        const size_t n = offsetof(Self, ParentProcessID);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ParentProcessID_clear()
    {
        const size_t n = offsetof(Self, ParentProcessID);
        GetField<String>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.RealUserID
    //
    
    const Field<Uint64>& RealUserID() const
    {
        const size_t n = offsetof(Self, RealUserID);
        return GetField<Uint64>(n);
    }
    
    void RealUserID(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, RealUserID);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& RealUserID_value() const
    {
        const size_t n = offsetof(Self, RealUserID);
        return GetField<Uint64>(n).value;
    }
    
    void RealUserID_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, RealUserID);
        GetField<Uint64>(n).Set(x);
    }
    
    bool RealUserID_exists() const
    {
        const size_t n = offsetof(Self, RealUserID);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void RealUserID_clear()
    {
        const size_t n = offsetof(Self, RealUserID);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.ProcessGroupID
    //
    
    const Field<Uint64>& ProcessGroupID() const
    {
        const size_t n = offsetof(Self, ProcessGroupID);
        return GetField<Uint64>(n);
    }
    
    void ProcessGroupID(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, ProcessGroupID);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& ProcessGroupID_value() const
    {
        const size_t n = offsetof(Self, ProcessGroupID);
        return GetField<Uint64>(n).value;
    }
    
    void ProcessGroupID_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, ProcessGroupID);
        GetField<Uint64>(n).Set(x);
    }
    
    bool ProcessGroupID_exists() const
    {
        const size_t n = offsetof(Self, ProcessGroupID);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void ProcessGroupID_clear()
    {
        const size_t n = offsetof(Self, ProcessGroupID);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.ProcessSessionID
    //
    
    const Field<Uint64>& ProcessSessionID() const
    {
        const size_t n = offsetof(Self, ProcessSessionID);
        return GetField<Uint64>(n);
    }
    
    void ProcessSessionID(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, ProcessSessionID);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& ProcessSessionID_value() const
    {
        const size_t n = offsetof(Self, ProcessSessionID);
        return GetField<Uint64>(n).value;
    }
    
    void ProcessSessionID_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, ProcessSessionID);
        GetField<Uint64>(n).Set(x);
    }
    
    bool ProcessSessionID_exists() const
    {
        const size_t n = offsetof(Self, ProcessSessionID);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void ProcessSessionID_clear()
    {
        const size_t n = offsetof(Self, ProcessSessionID);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.ProcessTTY
    //
    
    const Field<String>& ProcessTTY() const
    {
        const size_t n = offsetof(Self, ProcessTTY);
        return GetField<String>(n);
    }
    
    void ProcessTTY(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ProcessTTY);
        GetField<String>(n) = x;
    }
    
    const String& ProcessTTY_value() const
    {
        const size_t n = offsetof(Self, ProcessTTY);
        return GetField<String>(n).value;
    }
    
    void ProcessTTY_value(const String& x)
    {
        const size_t n = offsetof(Self, ProcessTTY);
        GetField<String>(n).Set(x);
    }
    
    bool ProcessTTY_exists() const
    {
        const size_t n = offsetof(Self, ProcessTTY);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ProcessTTY_clear()
    {
        const size_t n = offsetof(Self, ProcessTTY);
        GetField<String>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.ModulePath
    //
    
    const Field<String>& ModulePath() const
    {
        const size_t n = offsetof(Self, ModulePath);
        return GetField<String>(n);
    }
    
    void ModulePath(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ModulePath);
        GetField<String>(n) = x;
    }
    
    const String& ModulePath_value() const
    {
        const size_t n = offsetof(Self, ModulePath);
        return GetField<String>(n).value;
    }
    
    void ModulePath_value(const String& x)
    {
        const size_t n = offsetof(Self, ModulePath);
        GetField<String>(n).Set(x);
    }
    
    bool ModulePath_exists() const
    {
        const size_t n = offsetof(Self, ModulePath);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ModulePath_clear()
    {
        const size_t n = offsetof(Self, ModulePath);
        GetField<String>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.Parameters
    //
    
    const Field<StringA>& Parameters() const
    {
        const size_t n = offsetof(Self, Parameters);
        return GetField<StringA>(n);
    }
    
    void Parameters(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, Parameters);
        GetField<StringA>(n) = x;
    }
    
    const StringA& Parameters_value() const
    {
        const size_t n = offsetof(Self, Parameters);
        return GetField<StringA>(n).value;
    }
    
    void Parameters_value(const StringA& x)
    {
        const size_t n = offsetof(Self, Parameters);
        GetField<StringA>(n).Set(x);
    }
    
    bool Parameters_exists() const
    {
        const size_t n = offsetof(Self, Parameters);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void Parameters_clear()
    {
        const size_t n = offsetof(Self, Parameters);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.ProcessNiceValue
    //
    
    const Field<Uint32>& ProcessNiceValue() const
    {
        const size_t n = offsetof(Self, ProcessNiceValue);
        return GetField<Uint32>(n);
    }
    
    void ProcessNiceValue(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, ProcessNiceValue);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& ProcessNiceValue_value() const
    {
        const size_t n = offsetof(Self, ProcessNiceValue);
        return GetField<Uint32>(n).value;
    }
    
    void ProcessNiceValue_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, ProcessNiceValue);
        GetField<Uint32>(n).Set(x);
    }
    
    bool ProcessNiceValue_exists() const
    {
        const size_t n = offsetof(Self, ProcessNiceValue);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void ProcessNiceValue_clear()
    {
        const size_t n = offsetof(Self, ProcessNiceValue);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_UnixProcess_Class.ProcessWaitingForEvent
    //
    
    const Field<String>& ProcessWaitingForEvent() const
    {
        const size_t n = offsetof(Self, ProcessWaitingForEvent);
        return GetField<String>(n);
    }
    
    void ProcessWaitingForEvent(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ProcessWaitingForEvent);
        GetField<String>(n) = x;
    }
    
    const String& ProcessWaitingForEvent_value() const
    {
        const size_t n = offsetof(Self, ProcessWaitingForEvent);
        return GetField<String>(n).value;
    }
    
    void ProcessWaitingForEvent_value(const String& x)
    {
        const size_t n = offsetof(Self, ProcessWaitingForEvent);
        GetField<String>(n).Set(x);
    }
    
    bool ProcessWaitingForEvent_exists() const
    {
        const size_t n = offsetof(Self, ProcessWaitingForEvent);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ProcessWaitingForEvent_clear()
    {
        const size_t n = offsetof(Self, ProcessWaitingForEvent);
        GetField<String>(n).Clear();
    }
};

typedef Array<CIM_UnixProcess_Class> CIM_UnixProcess_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_UnixProcess_h */
