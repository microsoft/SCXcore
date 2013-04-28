/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_Process_h
#define _CIM_Process_h

#include <MI.h>
#include "CIM_EnabledLogicalElement.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_Process [CIM_Process]
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

typedef struct _CIM_Process /* extends CIM_EnabledLogicalElement */
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
}
CIM_Process;

typedef struct _CIM_Process_Ref
{
    CIM_Process* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Process_Ref;

typedef struct _CIM_Process_ConstRef
{
    MI_CONST CIM_Process* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Process_ConstRef;

typedef struct _CIM_Process_Array
{
    struct _CIM_Process** data;
    MI_Uint32 size;
}
CIM_Process_Array;

typedef struct _CIM_Process_ConstArray
{
    struct _CIM_Process MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_Process_ConstArray;

typedef struct _CIM_Process_ArrayRef
{
    CIM_Process_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Process_ArrayRef;

typedef struct _CIM_Process_ConstArrayRef
{
    CIM_Process_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Process_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_Process_rtti;

MI_INLINE MI_Result MI_CALL CIM_Process_Construct(
    CIM_Process* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_Process_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clone(
    const CIM_Process* self,
    CIM_Process** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_Process_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_Process_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Destruct(CIM_Process* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Delete(CIM_Process* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Post(
    const CIM_Process* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_InstanceID(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_InstanceID(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_InstanceID(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_Caption(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_Caption(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_Caption(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_Description(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_Description(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_Description(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_ElementName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_ElementName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_ElementName(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_InstallDate(
    CIM_Process* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_InstallDate(
    CIM_Process* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_Name(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_Name(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_Name(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_OperationalStatus(
    CIM_Process* self,
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

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_OperationalStatus(
    CIM_Process* self,
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

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_OperationalStatus(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_StatusDescriptions(
    CIM_Process* self,
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

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_StatusDescriptions(
    CIM_Process* self,
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

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_StatusDescriptions(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_Status(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_Status(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_Status(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_HealthState(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_HealthState(
    CIM_Process* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_CommunicationStatus(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_CommunicationStatus(
    CIM_Process* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_DetailedStatus(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_DetailedStatus(
    CIM_Process* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_OperatingStatus(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_OperatingStatus(
    CIM_Process* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_PrimaryStatus(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_PrimaryStatus(
    CIM_Process* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_EnabledState(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_EnabledState(
    CIM_Process* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_OtherEnabledState(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_OtherEnabledState(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_OtherEnabledState(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_RequestedState(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_RequestedState(
    CIM_Process* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_EnabledDefault(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_EnabledDefault(
    CIM_Process* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_TimeOfLastStateChange(
    CIM_Process* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_TimeOfLastStateChange(
    CIM_Process* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_AvailableRequestedStates(
    CIM_Process* self,
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

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_AvailableRequestedStates(
    CIM_Process* self,
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

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_AvailableRequestedStates(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_TransitioningToState(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_TransitioningToState(
    CIM_Process* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_CSCreationClassName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_CSCreationClassName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_CSCreationClassName(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_CSName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_CSName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_CSName(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_OSCreationClassName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_OSCreationClassName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_OSCreationClassName(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_OSName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_OSName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_OSName(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_CreationClassName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_CreationClassName(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_CreationClassName(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        25);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_Handle(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_Handle(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_Handle(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_Priority(
    CIM_Process* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->Priority)->value = x;
    ((MI_Uint32Field*)&self->Priority)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_Priority(
    CIM_Process* self)
{
    memset((void*)&self->Priority, 0, sizeof(self->Priority));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_ExecutionState(
    CIM_Process* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ExecutionState)->value = x;
    ((MI_Uint16Field*)&self->ExecutionState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_ExecutionState(
    CIM_Process* self)
{
    memset((void*)&self->ExecutionState, 0, sizeof(self->ExecutionState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_OtherExecutionDescription(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_SetPtr_OtherExecutionDescription(
    CIM_Process* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_OtherExecutionDescription(
    CIM_Process* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_CreationDate(
    CIM_Process* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->CreationDate)->value = x;
    ((MI_DatetimeField*)&self->CreationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_CreationDate(
    CIM_Process* self)
{
    memset((void*)&self->CreationDate, 0, sizeof(self->CreationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_TerminationDate(
    CIM_Process* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TerminationDate)->value = x;
    ((MI_DatetimeField*)&self->TerminationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_TerminationDate(
    CIM_Process* self)
{
    memset((void*)&self->TerminationDate, 0, sizeof(self->TerminationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_KernelModeTime(
    CIM_Process* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->KernelModeTime)->value = x;
    ((MI_Uint64Field*)&self->KernelModeTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_KernelModeTime(
    CIM_Process* self)
{
    memset((void*)&self->KernelModeTime, 0, sizeof(self->KernelModeTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_UserModeTime(
    CIM_Process* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UserModeTime)->value = x;
    ((MI_Uint64Field*)&self->UserModeTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_UserModeTime(
    CIM_Process* self)
{
    memset((void*)&self->UserModeTime, 0, sizeof(self->UserModeTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Set_WorkingSetSize(
    CIM_Process* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->WorkingSetSize)->value = x;
    ((MI_Uint64Field*)&self->WorkingSetSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_Clear_WorkingSetSize(
    CIM_Process* self)
{
    memset((void*)&self->WorkingSetSize, 0, sizeof(self->WorkingSetSize));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Process.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_Process_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_Process_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Set_MIReturn(
    CIM_Process_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Clear_MIReturn(
    CIM_Process_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Set_RequestedState(
    CIM_Process_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Clear_RequestedState(
    CIM_Process_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Set_Job(
    CIM_Process_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_SetPtr_Job(
    CIM_Process_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Clear_Job(
    CIM_Process_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Set_TimeoutPeriod(
    CIM_Process_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Process_RequestStateChange_Clear_TimeoutPeriod(
    CIM_Process_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_Process_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_Process_Class : public CIM_EnabledLogicalElement_Class
{
public:
    
    typedef CIM_Process Self;
    
    CIM_Process_Class() :
        CIM_EnabledLogicalElement_Class(&CIM_Process_rtti)
    {
    }
    
    CIM_Process_Class(
        const CIM_Process* instanceName,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(
            &CIM_Process_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_Process_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_Process_Class(
        const MI_ClassDecl* clDecl) :
        CIM_EnabledLogicalElement_Class(clDecl)
    {
    }
    
    CIM_Process_Class& operator=(
        const CIM_Process_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_Process_Class(
        const CIM_Process_Class& x) :
        CIM_EnabledLogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_Process_rtti;
    }

    //
    // CIM_Process_Class.CSCreationClassName
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
    // CIM_Process_Class.CSName
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
    // CIM_Process_Class.OSCreationClassName
    //
    
    const Field<String>& OSCreationClassName() const
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        return GetField<String>(n);
    }
    
    void OSCreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& OSCreationClassName_value() const
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        return GetField<String>(n).value;
    }
    
    void OSCreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool OSCreationClassName_exists() const
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OSCreationClassName_clear()
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Process_Class.OSName
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
    // CIM_Process_Class.CreationClassName
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
    // CIM_Process_Class.Handle
    //
    
    const Field<String>& Handle() const
    {
        const size_t n = offsetof(Self, Handle);
        return GetField<String>(n);
    }
    
    void Handle(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Handle);
        GetField<String>(n) = x;
    }
    
    const String& Handle_value() const
    {
        const size_t n = offsetof(Self, Handle);
        return GetField<String>(n).value;
    }
    
    void Handle_value(const String& x)
    {
        const size_t n = offsetof(Self, Handle);
        GetField<String>(n).Set(x);
    }
    
    bool Handle_exists() const
    {
        const size_t n = offsetof(Self, Handle);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Handle_clear()
    {
        const size_t n = offsetof(Self, Handle);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Process_Class.Priority
    //
    
    const Field<Uint32>& Priority() const
    {
        const size_t n = offsetof(Self, Priority);
        return GetField<Uint32>(n);
    }
    
    void Priority(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, Priority);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& Priority_value() const
    {
        const size_t n = offsetof(Self, Priority);
        return GetField<Uint32>(n).value;
    }
    
    void Priority_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, Priority);
        GetField<Uint32>(n).Set(x);
    }
    
    bool Priority_exists() const
    {
        const size_t n = offsetof(Self, Priority);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void Priority_clear()
    {
        const size_t n = offsetof(Self, Priority);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_Process_Class.ExecutionState
    //
    
    const Field<Uint16>& ExecutionState() const
    {
        const size_t n = offsetof(Self, ExecutionState);
        return GetField<Uint16>(n);
    }
    
    void ExecutionState(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, ExecutionState);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& ExecutionState_value() const
    {
        const size_t n = offsetof(Self, ExecutionState);
        return GetField<Uint16>(n).value;
    }
    
    void ExecutionState_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, ExecutionState);
        GetField<Uint16>(n).Set(x);
    }
    
    bool ExecutionState_exists() const
    {
        const size_t n = offsetof(Self, ExecutionState);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void ExecutionState_clear()
    {
        const size_t n = offsetof(Self, ExecutionState);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Process_Class.OtherExecutionDescription
    //
    
    const Field<String>& OtherExecutionDescription() const
    {
        const size_t n = offsetof(Self, OtherExecutionDescription);
        return GetField<String>(n);
    }
    
    void OtherExecutionDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherExecutionDescription);
        GetField<String>(n) = x;
    }
    
    const String& OtherExecutionDescription_value() const
    {
        const size_t n = offsetof(Self, OtherExecutionDescription);
        return GetField<String>(n).value;
    }
    
    void OtherExecutionDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherExecutionDescription);
        GetField<String>(n).Set(x);
    }
    
    bool OtherExecutionDescription_exists() const
    {
        const size_t n = offsetof(Self, OtherExecutionDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherExecutionDescription_clear()
    {
        const size_t n = offsetof(Self, OtherExecutionDescription);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Process_Class.CreationDate
    //
    
    const Field<Datetime>& CreationDate() const
    {
        const size_t n = offsetof(Self, CreationDate);
        return GetField<Datetime>(n);
    }
    
    void CreationDate(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, CreationDate);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& CreationDate_value() const
    {
        const size_t n = offsetof(Self, CreationDate);
        return GetField<Datetime>(n).value;
    }
    
    void CreationDate_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, CreationDate);
        GetField<Datetime>(n).Set(x);
    }
    
    bool CreationDate_exists() const
    {
        const size_t n = offsetof(Self, CreationDate);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void CreationDate_clear()
    {
        const size_t n = offsetof(Self, CreationDate);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_Process_Class.TerminationDate
    //
    
    const Field<Datetime>& TerminationDate() const
    {
        const size_t n = offsetof(Self, TerminationDate);
        return GetField<Datetime>(n);
    }
    
    void TerminationDate(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, TerminationDate);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& TerminationDate_value() const
    {
        const size_t n = offsetof(Self, TerminationDate);
        return GetField<Datetime>(n).value;
    }
    
    void TerminationDate_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, TerminationDate);
        GetField<Datetime>(n).Set(x);
    }
    
    bool TerminationDate_exists() const
    {
        const size_t n = offsetof(Self, TerminationDate);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void TerminationDate_clear()
    {
        const size_t n = offsetof(Self, TerminationDate);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_Process_Class.KernelModeTime
    //
    
    const Field<Uint64>& KernelModeTime() const
    {
        const size_t n = offsetof(Self, KernelModeTime);
        return GetField<Uint64>(n);
    }
    
    void KernelModeTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, KernelModeTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& KernelModeTime_value() const
    {
        const size_t n = offsetof(Self, KernelModeTime);
        return GetField<Uint64>(n).value;
    }
    
    void KernelModeTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, KernelModeTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool KernelModeTime_exists() const
    {
        const size_t n = offsetof(Self, KernelModeTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void KernelModeTime_clear()
    {
        const size_t n = offsetof(Self, KernelModeTime);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_Process_Class.UserModeTime
    //
    
    const Field<Uint64>& UserModeTime() const
    {
        const size_t n = offsetof(Self, UserModeTime);
        return GetField<Uint64>(n);
    }
    
    void UserModeTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, UserModeTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& UserModeTime_value() const
    {
        const size_t n = offsetof(Self, UserModeTime);
        return GetField<Uint64>(n).value;
    }
    
    void UserModeTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, UserModeTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool UserModeTime_exists() const
    {
        const size_t n = offsetof(Self, UserModeTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void UserModeTime_clear()
    {
        const size_t n = offsetof(Self, UserModeTime);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_Process_Class.WorkingSetSize
    //
    
    const Field<Uint64>& WorkingSetSize() const
    {
        const size_t n = offsetof(Self, WorkingSetSize);
        return GetField<Uint64>(n);
    }
    
    void WorkingSetSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, WorkingSetSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& WorkingSetSize_value() const
    {
        const size_t n = offsetof(Self, WorkingSetSize);
        return GetField<Uint64>(n).value;
    }
    
    void WorkingSetSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, WorkingSetSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool WorkingSetSize_exists() const
    {
        const size_t n = offsetof(Self, WorkingSetSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void WorkingSetSize_clear()
    {
        const size_t n = offsetof(Self, WorkingSetSize);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<CIM_Process_Class> CIM_Process_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_Process_h */
