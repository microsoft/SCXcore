/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_EnabledLogicalElement_h
#define _CIM_EnabledLogicalElement_h

#include <MI.h>
#include "CIM_LogicalElement.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_EnabledLogicalElement [CIM_EnabledLogicalElement]
**
** Keys:
**
**==============================================================================
*/

typedef struct _CIM_EnabledLogicalElement /* extends CIM_LogicalElement */
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
}
CIM_EnabledLogicalElement;

typedef struct _CIM_EnabledLogicalElement_Ref
{
    CIM_EnabledLogicalElement* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EnabledLogicalElement_Ref;

typedef struct _CIM_EnabledLogicalElement_ConstRef
{
    MI_CONST CIM_EnabledLogicalElement* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EnabledLogicalElement_ConstRef;

typedef struct _CIM_EnabledLogicalElement_Array
{
    struct _CIM_EnabledLogicalElement** data;
    MI_Uint32 size;
}
CIM_EnabledLogicalElement_Array;

typedef struct _CIM_EnabledLogicalElement_ConstArray
{
    struct _CIM_EnabledLogicalElement MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_EnabledLogicalElement_ConstArray;

typedef struct _CIM_EnabledLogicalElement_ArrayRef
{
    CIM_EnabledLogicalElement_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EnabledLogicalElement_ArrayRef;

typedef struct _CIM_EnabledLogicalElement_ConstArrayRef
{
    CIM_EnabledLogicalElement_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EnabledLogicalElement_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_EnabledLogicalElement_rtti;

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Construct(
    CIM_EnabledLogicalElement* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_EnabledLogicalElement_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clone(
    const CIM_EnabledLogicalElement* self,
    CIM_EnabledLogicalElement** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_EnabledLogicalElement_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_EnabledLogicalElement_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Destruct(CIM_EnabledLogicalElement* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Delete(CIM_EnabledLogicalElement* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Post(
    const CIM_EnabledLogicalElement* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_InstanceID(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_InstanceID(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_InstanceID(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_Caption(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_Caption(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_Caption(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_Description(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_Description(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_Description(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_ElementName(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_ElementName(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_ElementName(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_InstallDate(
    CIM_EnabledLogicalElement* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_InstallDate(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_Name(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_Name(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_Name(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_OperationalStatus(
    CIM_EnabledLogicalElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_OperationalStatus(
    CIM_EnabledLogicalElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_OperationalStatus(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_StatusDescriptions(
    CIM_EnabledLogicalElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_StatusDescriptions(
    CIM_EnabledLogicalElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_StatusDescriptions(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_Status(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_Status(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_Status(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_HealthState(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_HealthState(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_CommunicationStatus(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_CommunicationStatus(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_DetailedStatus(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_DetailedStatus(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_OperatingStatus(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_OperatingStatus(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_PrimaryStatus(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_PrimaryStatus(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_EnabledState(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_EnabledState(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_OtherEnabledState(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_OtherEnabledState(
    CIM_EnabledLogicalElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_OtherEnabledState(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_RequestedState(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_RequestedState(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_EnabledDefault(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_EnabledDefault(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_TimeOfLastStateChange(
    CIM_EnabledLogicalElement* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_TimeOfLastStateChange(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_AvailableRequestedStates(
    CIM_EnabledLogicalElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_SetPtr_AvailableRequestedStates(
    CIM_EnabledLogicalElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_AvailableRequestedStates(
    CIM_EnabledLogicalElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Set_TransitioningToState(
    CIM_EnabledLogicalElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_Clear_TransitioningToState(
    CIM_EnabledLogicalElement* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_EnabledLogicalElement.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_EnabledLogicalElement_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_EnabledLogicalElement_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_EnabledLogicalElement_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Construct(
    CIM_EnabledLogicalElement_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_EnabledLogicalElement_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Clone(
    const CIM_EnabledLogicalElement_RequestStateChange* self,
    CIM_EnabledLogicalElement_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Destruct(
    CIM_EnabledLogicalElement_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Delete(
    CIM_EnabledLogicalElement_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Post(
    const CIM_EnabledLogicalElement_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Set_MIReturn(
    CIM_EnabledLogicalElement_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Clear_MIReturn(
    CIM_EnabledLogicalElement_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Set_RequestedState(
    CIM_EnabledLogicalElement_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Clear_RequestedState(
    CIM_EnabledLogicalElement_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Set_Job(
    CIM_EnabledLogicalElement_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_SetPtr_Job(
    CIM_EnabledLogicalElement_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Clear_Job(
    CIM_EnabledLogicalElement_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Set_TimeoutPeriod(
    CIM_EnabledLogicalElement_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EnabledLogicalElement_RequestStateChange_Clear_TimeoutPeriod(
    CIM_EnabledLogicalElement_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_EnabledLogicalElement_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_EnabledLogicalElement_Class : public CIM_LogicalElement_Class
{
public:
    
    typedef CIM_EnabledLogicalElement Self;
    
    CIM_EnabledLogicalElement_Class() :
        CIM_LogicalElement_Class(&CIM_EnabledLogicalElement_rtti)
    {
    }
    
    CIM_EnabledLogicalElement_Class(
        const CIM_EnabledLogicalElement* instanceName,
        bool keysOnly) :
        CIM_LogicalElement_Class(
            &CIM_EnabledLogicalElement_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_EnabledLogicalElement_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_EnabledLogicalElement_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalElement_Class(clDecl)
    {
    }
    
    CIM_EnabledLogicalElement_Class& operator=(
        const CIM_EnabledLogicalElement_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_EnabledLogicalElement_Class(
        const CIM_EnabledLogicalElement_Class& x) :
        CIM_LogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_EnabledLogicalElement_rtti;
    }

    //
    // CIM_EnabledLogicalElement_Class.EnabledState
    //
    
    const Field<Uint16>& EnabledState() const
    {
        const size_t n = offsetof(Self, EnabledState);
        return GetField<Uint16>(n);
    }
    
    void EnabledState(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, EnabledState);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& EnabledState_value() const
    {
        const size_t n = offsetof(Self, EnabledState);
        return GetField<Uint16>(n).value;
    }
    
    void EnabledState_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, EnabledState);
        GetField<Uint16>(n).Set(x);
    }
    
    bool EnabledState_exists() const
    {
        const size_t n = offsetof(Self, EnabledState);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void EnabledState_clear()
    {
        const size_t n = offsetof(Self, EnabledState);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_EnabledLogicalElement_Class.OtherEnabledState
    //
    
    const Field<String>& OtherEnabledState() const
    {
        const size_t n = offsetof(Self, OtherEnabledState);
        return GetField<String>(n);
    }
    
    void OtherEnabledState(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherEnabledState);
        GetField<String>(n) = x;
    }
    
    const String& OtherEnabledState_value() const
    {
        const size_t n = offsetof(Self, OtherEnabledState);
        return GetField<String>(n).value;
    }
    
    void OtherEnabledState_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherEnabledState);
        GetField<String>(n).Set(x);
    }
    
    bool OtherEnabledState_exists() const
    {
        const size_t n = offsetof(Self, OtherEnabledState);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherEnabledState_clear()
    {
        const size_t n = offsetof(Self, OtherEnabledState);
        GetField<String>(n).Clear();
    }

    //
    // CIM_EnabledLogicalElement_Class.RequestedState
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
    // CIM_EnabledLogicalElement_Class.EnabledDefault
    //
    
    const Field<Uint16>& EnabledDefault() const
    {
        const size_t n = offsetof(Self, EnabledDefault);
        return GetField<Uint16>(n);
    }
    
    void EnabledDefault(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, EnabledDefault);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& EnabledDefault_value() const
    {
        const size_t n = offsetof(Self, EnabledDefault);
        return GetField<Uint16>(n).value;
    }
    
    void EnabledDefault_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, EnabledDefault);
        GetField<Uint16>(n).Set(x);
    }
    
    bool EnabledDefault_exists() const
    {
        const size_t n = offsetof(Self, EnabledDefault);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void EnabledDefault_clear()
    {
        const size_t n = offsetof(Self, EnabledDefault);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_EnabledLogicalElement_Class.TimeOfLastStateChange
    //
    
    const Field<Datetime>& TimeOfLastStateChange() const
    {
        const size_t n = offsetof(Self, TimeOfLastStateChange);
        return GetField<Datetime>(n);
    }
    
    void TimeOfLastStateChange(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, TimeOfLastStateChange);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& TimeOfLastStateChange_value() const
    {
        const size_t n = offsetof(Self, TimeOfLastStateChange);
        return GetField<Datetime>(n).value;
    }
    
    void TimeOfLastStateChange_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, TimeOfLastStateChange);
        GetField<Datetime>(n).Set(x);
    }
    
    bool TimeOfLastStateChange_exists() const
    {
        const size_t n = offsetof(Self, TimeOfLastStateChange);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void TimeOfLastStateChange_clear()
    {
        const size_t n = offsetof(Self, TimeOfLastStateChange);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_EnabledLogicalElement_Class.AvailableRequestedStates
    //
    
    const Field<Uint16A>& AvailableRequestedStates() const
    {
        const size_t n = offsetof(Self, AvailableRequestedStates);
        return GetField<Uint16A>(n);
    }
    
    void AvailableRequestedStates(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, AvailableRequestedStates);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& AvailableRequestedStates_value() const
    {
        const size_t n = offsetof(Self, AvailableRequestedStates);
        return GetField<Uint16A>(n).value;
    }
    
    void AvailableRequestedStates_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, AvailableRequestedStates);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool AvailableRequestedStates_exists() const
    {
        const size_t n = offsetof(Self, AvailableRequestedStates);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void AvailableRequestedStates_clear()
    {
        const size_t n = offsetof(Self, AvailableRequestedStates);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_EnabledLogicalElement_Class.TransitioningToState
    //
    
    const Field<Uint16>& TransitioningToState() const
    {
        const size_t n = offsetof(Self, TransitioningToState);
        return GetField<Uint16>(n);
    }
    
    void TransitioningToState(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, TransitioningToState);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& TransitioningToState_value() const
    {
        const size_t n = offsetof(Self, TransitioningToState);
        return GetField<Uint16>(n).value;
    }
    
    void TransitioningToState_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, TransitioningToState);
        GetField<Uint16>(n).Set(x);
    }
    
    bool TransitioningToState_exists() const
    {
        const size_t n = offsetof(Self, TransitioningToState);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void TransitioningToState_clear()
    {
        const size_t n = offsetof(Self, TransitioningToState);
        GetField<Uint16>(n).Clear();
    }
};

typedef Array<CIM_EnabledLogicalElement_Class> CIM_EnabledLogicalElement_ClassA;

class CIM_EnabledLogicalElement_RequestStateChange_Class : public Instance
{
public:
    
    typedef CIM_EnabledLogicalElement_RequestStateChange Self;
    
    CIM_EnabledLogicalElement_RequestStateChange_Class() :
        Instance(&CIM_EnabledLogicalElement_RequestStateChange_rtti)
    {
    }
    
    CIM_EnabledLogicalElement_RequestStateChange_Class(
        const CIM_EnabledLogicalElement_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_EnabledLogicalElement_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_EnabledLogicalElement_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_EnabledLogicalElement_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_EnabledLogicalElement_RequestStateChange_Class& operator=(
        const CIM_EnabledLogicalElement_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_EnabledLogicalElement_RequestStateChange_Class(
        const CIM_EnabledLogicalElement_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_EnabledLogicalElement_RequestStateChange_Class.MIReturn
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
    // CIM_EnabledLogicalElement_RequestStateChange_Class.RequestedState
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
    // CIM_EnabledLogicalElement_RequestStateChange_Class.Job
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
    // CIM_EnabledLogicalElement_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<CIM_EnabledLogicalElement_RequestStateChange_Class> CIM_EnabledLogicalElement_RequestStateChange_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_EnabledLogicalElement_h */
