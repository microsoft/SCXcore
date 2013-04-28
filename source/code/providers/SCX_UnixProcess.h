/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_UnixProcess_h
#define _SCX_UnixProcess_h

#include <MI.h>
#include "CIM_UnixProcess.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_UnixProcess [SCX_UnixProcess]
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

typedef struct _SCX_UnixProcess /* extends CIM_UnixProcess */
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
    /* SCX_UnixProcess properties */
}
SCX_UnixProcess;

typedef struct _SCX_UnixProcess_Ref
{
    SCX_UnixProcess* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcess_Ref;

typedef struct _SCX_UnixProcess_ConstRef
{
    MI_CONST SCX_UnixProcess* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcess_ConstRef;

typedef struct _SCX_UnixProcess_Array
{
    struct _SCX_UnixProcess** data;
    MI_Uint32 size;
}
SCX_UnixProcess_Array;

typedef struct _SCX_UnixProcess_ConstArray
{
    struct _SCX_UnixProcess MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_UnixProcess_ConstArray;

typedef struct _SCX_UnixProcess_ArrayRef
{
    SCX_UnixProcess_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcess_ArrayRef;

typedef struct _SCX_UnixProcess_ConstArrayRef
{
    SCX_UnixProcess_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcess_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_UnixProcess_rtti;

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Construct(
    SCX_UnixProcess* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_UnixProcess_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clone(
    const SCX_UnixProcess* self,
    SCX_UnixProcess** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_UnixProcess_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_UnixProcess_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Destruct(SCX_UnixProcess* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Delete(SCX_UnixProcess* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Post(
    const SCX_UnixProcess* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_InstanceID(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_InstanceID(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_InstanceID(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_Caption(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_Caption(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_Caption(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_Description(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_Description(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_Description(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ElementName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_ElementName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ElementName(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_InstallDate(
    SCX_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_InstallDate(
    SCX_UnixProcess* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_Name(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_Name(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_Name(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_OperationalStatus(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_OperationalStatus(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_OperationalStatus(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_StatusDescriptions(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_StatusDescriptions(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_StatusDescriptions(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_Status(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_Status(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_Status(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_HealthState(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_HealthState(
    SCX_UnixProcess* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_CommunicationStatus(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_CommunicationStatus(
    SCX_UnixProcess* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_DetailedStatus(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_DetailedStatus(
    SCX_UnixProcess* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_OperatingStatus(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_OperatingStatus(
    SCX_UnixProcess* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_PrimaryStatus(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_PrimaryStatus(
    SCX_UnixProcess* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_EnabledState(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_EnabledState(
    SCX_UnixProcess* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_OtherEnabledState(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_OtherEnabledState(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_OtherEnabledState(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_RequestedState(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_RequestedState(
    SCX_UnixProcess* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_EnabledDefault(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_EnabledDefault(
    SCX_UnixProcess* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_TimeOfLastStateChange(
    SCX_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_TimeOfLastStateChange(
    SCX_UnixProcess* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_AvailableRequestedStates(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_AvailableRequestedStates(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_AvailableRequestedStates(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_TransitioningToState(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_TransitioningToState(
    SCX_UnixProcess* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_CSCreationClassName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_CSCreationClassName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_CSCreationClassName(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_CSName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_CSName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_CSName(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_OSCreationClassName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_OSCreationClassName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_OSCreationClassName(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_OSName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_OSName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_OSName(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_CreationClassName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_CreationClassName(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_CreationClassName(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        25);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_Handle(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_Handle(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_Handle(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_Priority(
    SCX_UnixProcess* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->Priority)->value = x;
    ((MI_Uint32Field*)&self->Priority)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_Priority(
    SCX_UnixProcess* self)
{
    memset((void*)&self->Priority, 0, sizeof(self->Priority));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ExecutionState(
    SCX_UnixProcess* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ExecutionState)->value = x;
    ((MI_Uint16Field*)&self->ExecutionState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ExecutionState(
    SCX_UnixProcess* self)
{
    memset((void*)&self->ExecutionState, 0, sizeof(self->ExecutionState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_OtherExecutionDescription(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_OtherExecutionDescription(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_OtherExecutionDescription(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_CreationDate(
    SCX_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->CreationDate)->value = x;
    ((MI_DatetimeField*)&self->CreationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_CreationDate(
    SCX_UnixProcess* self)
{
    memset((void*)&self->CreationDate, 0, sizeof(self->CreationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_TerminationDate(
    SCX_UnixProcess* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TerminationDate)->value = x;
    ((MI_DatetimeField*)&self->TerminationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_TerminationDate(
    SCX_UnixProcess* self)
{
    memset((void*)&self->TerminationDate, 0, sizeof(self->TerminationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_KernelModeTime(
    SCX_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->KernelModeTime)->value = x;
    ((MI_Uint64Field*)&self->KernelModeTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_KernelModeTime(
    SCX_UnixProcess* self)
{
    memset((void*)&self->KernelModeTime, 0, sizeof(self->KernelModeTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_UserModeTime(
    SCX_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UserModeTime)->value = x;
    ((MI_Uint64Field*)&self->UserModeTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_UserModeTime(
    SCX_UnixProcess* self)
{
    memset((void*)&self->UserModeTime, 0, sizeof(self->UserModeTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_WorkingSetSize(
    SCX_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->WorkingSetSize)->value = x;
    ((MI_Uint64Field*)&self->WorkingSetSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_WorkingSetSize(
    SCX_UnixProcess* self)
{
    memset((void*)&self->WorkingSetSize, 0, sizeof(self->WorkingSetSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ParentProcessID(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        35,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_ParentProcessID(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        35,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ParentProcessID(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_RealUserID(
    SCX_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealUserID)->value = x;
    ((MI_Uint64Field*)&self->RealUserID)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_RealUserID(
    SCX_UnixProcess* self)
{
    memset((void*)&self->RealUserID, 0, sizeof(self->RealUserID));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ProcessGroupID(
    SCX_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ProcessGroupID)->value = x;
    ((MI_Uint64Field*)&self->ProcessGroupID)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ProcessGroupID(
    SCX_UnixProcess* self)
{
    memset((void*)&self->ProcessGroupID, 0, sizeof(self->ProcessGroupID));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ProcessSessionID(
    SCX_UnixProcess* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ProcessSessionID)->value = x;
    ((MI_Uint64Field*)&self->ProcessSessionID)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ProcessSessionID(
    SCX_UnixProcess* self)
{
    memset((void*)&self->ProcessSessionID, 0, sizeof(self->ProcessSessionID));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ProcessTTY(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_ProcessTTY(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ProcessTTY(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ModulePath(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_ModulePath(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ModulePath(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        40);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_Parameters(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_Parameters(
    SCX_UnixProcess* self,
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

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_Parameters(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ProcessNiceValue(
    SCX_UnixProcess* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ProcessNiceValue)->value = x;
    ((MI_Uint32Field*)&self->ProcessNiceValue)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ProcessNiceValue(
    SCX_UnixProcess* self)
{
    memset((void*)&self->ProcessNiceValue, 0, sizeof(self->ProcessNiceValue));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Set_ProcessWaitingForEvent(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_SetPtr_ProcessWaitingForEvent(
    SCX_UnixProcess* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_Clear_ProcessWaitingForEvent(
    SCX_UnixProcess* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        43);
}

/*
**==============================================================================
**
** SCX_UnixProcess.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_UnixProcess_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_UnixProcess_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_UnixProcess_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Construct(
    SCX_UnixProcess_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_UnixProcess_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Clone(
    const SCX_UnixProcess_RequestStateChange* self,
    SCX_UnixProcess_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Destruct(
    SCX_UnixProcess_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Delete(
    SCX_UnixProcess_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Post(
    const SCX_UnixProcess_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Set_MIReturn(
    SCX_UnixProcess_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Clear_MIReturn(
    SCX_UnixProcess_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Set_RequestedState(
    SCX_UnixProcess_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Clear_RequestedState(
    SCX_UnixProcess_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Set_Job(
    SCX_UnixProcess_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_SetPtr_Job(
    SCX_UnixProcess_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Clear_Job(
    SCX_UnixProcess_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Set_TimeoutPeriod(
    SCX_UnixProcess_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_RequestStateChange_Clear_TimeoutPeriod(
    SCX_UnixProcess_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_UnixProcess.TopResourceConsumers()
**
**==============================================================================
*/

typedef struct _SCX_UnixProcess_TopResourceConsumers
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstStringField MIReturn;
    /*IN*/ MI_ConstStringField resource;
    /*IN*/ MI_ConstUint16Field count;
    /*IN*/ MI_ConstStringField elevationType;
}
SCX_UnixProcess_TopResourceConsumers;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_UnixProcess_TopResourceConsumers_rtti;

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Construct(
    SCX_UnixProcess_TopResourceConsumers* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_UnixProcess_TopResourceConsumers_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Clone(
    const SCX_UnixProcess_TopResourceConsumers* self,
    SCX_UnixProcess_TopResourceConsumers** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Destruct(
    SCX_UnixProcess_TopResourceConsumers* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Delete(
    SCX_UnixProcess_TopResourceConsumers* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Post(
    const SCX_UnixProcess_TopResourceConsumers* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Set_MIReturn(
    SCX_UnixProcess_TopResourceConsumers* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_SetPtr_MIReturn(
    SCX_UnixProcess_TopResourceConsumers* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Clear_MIReturn(
    SCX_UnixProcess_TopResourceConsumers* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Set_resource(
    SCX_UnixProcess_TopResourceConsumers* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_SetPtr_resource(
    SCX_UnixProcess_TopResourceConsumers* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Clear_resource(
    SCX_UnixProcess_TopResourceConsumers* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Set_count(
    SCX_UnixProcess_TopResourceConsumers* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->count)->value = x;
    ((MI_Uint16Field*)&self->count)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Clear_count(
    SCX_UnixProcess_TopResourceConsumers* self)
{
    memset((void*)&self->count, 0, sizeof(self->count));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Set_elevationType(
    SCX_UnixProcess_TopResourceConsumers* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_SetPtr_elevationType(
    SCX_UnixProcess_TopResourceConsumers* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcess_TopResourceConsumers_Clear_elevationType(
    SCX_UnixProcess_TopResourceConsumers* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

/*
**==============================================================================
**
** SCX_UnixProcess provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_UnixProcess_Self SCX_UnixProcess_Self;

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Load(
    SCX_UnixProcess_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Unload(
    SCX_UnixProcess_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_EnumerateInstances(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_GetInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_CreateInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* newInstance);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_ModifyInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_DeleteInstance(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcess* instanceName);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Invoke_RequestStateChange(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_UnixProcess* instanceName,
    const SCX_UnixProcess_RequestStateChange* in);

MI_EXTERN_C void MI_CALL SCX_UnixProcess_Invoke_TopResourceConsumers(
    SCX_UnixProcess_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_UnixProcess* instanceName,
    const SCX_UnixProcess_TopResourceConsumers* in);


/*
**==============================================================================
**
** SCX_UnixProcess_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_UnixProcess_Class : public CIM_UnixProcess_Class
{
public:
    
    typedef SCX_UnixProcess Self;
    
    SCX_UnixProcess_Class() :
        CIM_UnixProcess_Class(&SCX_UnixProcess_rtti)
    {
    }
    
    SCX_UnixProcess_Class(
        const SCX_UnixProcess* instanceName,
        bool keysOnly) :
        CIM_UnixProcess_Class(
            &SCX_UnixProcess_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_UnixProcess_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_UnixProcess_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_UnixProcess_Class(
        const MI_ClassDecl* clDecl) :
        CIM_UnixProcess_Class(clDecl)
    {
    }
    
    SCX_UnixProcess_Class& operator=(
        const SCX_UnixProcess_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_UnixProcess_Class(
        const SCX_UnixProcess_Class& x) :
        CIM_UnixProcess_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_UnixProcess_rtti;
    }

};

typedef Array<SCX_UnixProcess_Class> SCX_UnixProcess_ClassA;

class SCX_UnixProcess_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_UnixProcess_RequestStateChange Self;
    
    SCX_UnixProcess_RequestStateChange_Class() :
        Instance(&SCX_UnixProcess_RequestStateChange_rtti)
    {
    }
    
    SCX_UnixProcess_RequestStateChange_Class(
        const SCX_UnixProcess_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_UnixProcess_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_UnixProcess_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_UnixProcess_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_UnixProcess_RequestStateChange_Class& operator=(
        const SCX_UnixProcess_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_UnixProcess_RequestStateChange_Class(
        const SCX_UnixProcess_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_UnixProcess_RequestStateChange_Class.MIReturn
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
    // SCX_UnixProcess_RequestStateChange_Class.RequestedState
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
    // SCX_UnixProcess_RequestStateChange_Class.Job
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
    // SCX_UnixProcess_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<SCX_UnixProcess_RequestStateChange_Class> SCX_UnixProcess_RequestStateChange_ClassA;

class SCX_UnixProcess_TopResourceConsumers_Class : public Instance
{
public:
    
    typedef SCX_UnixProcess_TopResourceConsumers Self;
    
    SCX_UnixProcess_TopResourceConsumers_Class() :
        Instance(&SCX_UnixProcess_TopResourceConsumers_rtti)
    {
    }
    
    SCX_UnixProcess_TopResourceConsumers_Class(
        const SCX_UnixProcess_TopResourceConsumers* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_UnixProcess_TopResourceConsumers_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_UnixProcess_TopResourceConsumers_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_UnixProcess_TopResourceConsumers_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_UnixProcess_TopResourceConsumers_Class& operator=(
        const SCX_UnixProcess_TopResourceConsumers_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_UnixProcess_TopResourceConsumers_Class(
        const SCX_UnixProcess_TopResourceConsumers_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_UnixProcess_TopResourceConsumers_Class.MIReturn
    //
    
    const Field<String>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<String>(n);
    }
    
    void MIReturn(const Field<String>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<String>(n) = x;
    }
    
    const String& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<String>(n).value;
    }
    
    void MIReturn_value(const String& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<String>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<String>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<String>(n).Clear();
    }

    //
    // SCX_UnixProcess_TopResourceConsumers_Class.resource
    //
    
    const Field<String>& resource() const
    {
        const size_t n = offsetof(Self, resource);
        return GetField<String>(n);
    }
    
    void resource(const Field<String>& x)
    {
        const size_t n = offsetof(Self, resource);
        GetField<String>(n) = x;
    }
    
    const String& resource_value() const
    {
        const size_t n = offsetof(Self, resource);
        return GetField<String>(n).value;
    }
    
    void resource_value(const String& x)
    {
        const size_t n = offsetof(Self, resource);
        GetField<String>(n).Set(x);
    }
    
    bool resource_exists() const
    {
        const size_t n = offsetof(Self, resource);
        return GetField<String>(n).exists ? true : false;
    }
    
    void resource_clear()
    {
        const size_t n = offsetof(Self, resource);
        GetField<String>(n).Clear();
    }

    //
    // SCX_UnixProcess_TopResourceConsumers_Class.count
    //
    
    const Field<Uint16>& count() const
    {
        const size_t n = offsetof(Self, count);
        return GetField<Uint16>(n);
    }
    
    void count(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, count);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& count_value() const
    {
        const size_t n = offsetof(Self, count);
        return GetField<Uint16>(n).value;
    }
    
    void count_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, count);
        GetField<Uint16>(n).Set(x);
    }
    
    bool count_exists() const
    {
        const size_t n = offsetof(Self, count);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void count_clear()
    {
        const size_t n = offsetof(Self, count);
        GetField<Uint16>(n).Clear();
    }

    //
    // SCX_UnixProcess_TopResourceConsumers_Class.elevationType
    //
    
    const Field<String>& elevationType() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n);
    }
    
    void elevationType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n) = x;
    }
    
    const String& elevationType_value() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n).value;
    }
    
    void elevationType_value(const String& x)
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n).Set(x);
    }
    
    bool elevationType_exists() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void elevationType_clear()
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_UnixProcess_TopResourceConsumers_Class> SCX_UnixProcess_TopResourceConsumers_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_UnixProcess_h */
