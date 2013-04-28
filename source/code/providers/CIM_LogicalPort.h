/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_LogicalPort_h
#define _CIM_LogicalPort_h

#include <MI.h>
#include "CIM_LogicalDevice.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_LogicalPort [CIM_LogicalPort]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort /* extends CIM_LogicalDevice */
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
    /* CIM_LogicalDevice properties */
    /*KEY*/ MI_ConstStringField SystemCreationClassName;
    /*KEY*/ MI_ConstStringField SystemName;
    /*KEY*/ MI_ConstStringField CreationClassName;
    /*KEY*/ MI_ConstStringField DeviceID;
    MI_ConstBooleanField PowerManagementSupported;
    MI_ConstUint16AField PowerManagementCapabilities;
    MI_ConstUint16Field Availability;
    MI_ConstUint16Field StatusInfo;
    MI_ConstUint32Field LastErrorCode;
    MI_ConstStringField ErrorDescription;
    MI_ConstBooleanField ErrorCleared;
    MI_ConstStringAField OtherIdentifyingInfo;
    MI_ConstUint64Field PowerOnHours;
    MI_ConstUint64Field TotalPowerOnHours;
    MI_ConstStringAField IdentifyingDescriptions;
    MI_ConstUint16AField AdditionalAvailability;
    MI_ConstUint64Field MaxQuiesceTime;
    /* CIM_LogicalPort properties */
    MI_ConstUint64Field Speed;
    MI_ConstUint64Field MaxSpeed;
    MI_ConstUint64Field RequestedSpeed;
    MI_ConstUint16Field UsageRestriction;
    MI_ConstUint16Field PortType;
    MI_ConstStringField OtherPortType;
}
CIM_LogicalPort;

typedef struct _CIM_LogicalPort_Ref
{
    CIM_LogicalPort* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalPort_Ref;

typedef struct _CIM_LogicalPort_ConstRef
{
    MI_CONST CIM_LogicalPort* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalPort_ConstRef;

typedef struct _CIM_LogicalPort_Array
{
    struct _CIM_LogicalPort** data;
    MI_Uint32 size;
}
CIM_LogicalPort_Array;

typedef struct _CIM_LogicalPort_ConstArray
{
    struct _CIM_LogicalPort MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_LogicalPort_ConstArray;

typedef struct _CIM_LogicalPort_ArrayRef
{
    CIM_LogicalPort_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalPort_ArrayRef;

typedef struct _CIM_LogicalPort_ConstArrayRef
{
    CIM_LogicalPort_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalPort_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_LogicalPort_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Construct(
    CIM_LogicalPort* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_LogicalPort_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clone(
    const CIM_LogicalPort* self,
    CIM_LogicalPort** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_LogicalPort_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_LogicalPort_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Destruct(CIM_LogicalPort* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Delete(CIM_LogicalPort* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Post(
    const CIM_LogicalPort* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_InstanceID(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_InstanceID(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_InstanceID(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_Caption(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_Caption(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_Caption(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_Description(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_Description(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_Description(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_ElementName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_ElementName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_ElementName(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_InstallDate(
    CIM_LogicalPort* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_InstallDate(
    CIM_LogicalPort* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_Name(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_Name(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_Name(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_OperationalStatus(
    CIM_LogicalPort* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_OperationalStatus(
    CIM_LogicalPort* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_OperationalStatus(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_StatusDescriptions(
    CIM_LogicalPort* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_StatusDescriptions(
    CIM_LogicalPort* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_StatusDescriptions(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_Status(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_Status(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_Status(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_HealthState(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_HealthState(
    CIM_LogicalPort* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_CommunicationStatus(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_CommunicationStatus(
    CIM_LogicalPort* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_DetailedStatus(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_DetailedStatus(
    CIM_LogicalPort* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_OperatingStatus(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_OperatingStatus(
    CIM_LogicalPort* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_PrimaryStatus(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_PrimaryStatus(
    CIM_LogicalPort* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_EnabledState(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_EnabledState(
    CIM_LogicalPort* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_OtherEnabledState(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_OtherEnabledState(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_OtherEnabledState(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_RequestedState(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_RequestedState(
    CIM_LogicalPort* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_EnabledDefault(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_EnabledDefault(
    CIM_LogicalPort* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_TimeOfLastStateChange(
    CIM_LogicalPort* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_TimeOfLastStateChange(
    CIM_LogicalPort* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_AvailableRequestedStates(
    CIM_LogicalPort* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_AvailableRequestedStates(
    CIM_LogicalPort* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_AvailableRequestedStates(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_TransitioningToState(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_TransitioningToState(
    CIM_LogicalPort* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_SystemCreationClassName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_SystemCreationClassName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_SystemCreationClassName(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_SystemName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_SystemName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_SystemName(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_CreationClassName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_CreationClassName(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_CreationClassName(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_DeviceID(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_DeviceID(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_DeviceID(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_PowerManagementSupported(
    CIM_LogicalPort* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_PowerManagementSupported(
    CIM_LogicalPort* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_PowerManagementCapabilities(
    CIM_LogicalPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_PowerManagementCapabilities(
    CIM_LogicalPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_PowerManagementCapabilities(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_Availability(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_Availability(
    CIM_LogicalPort* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_StatusInfo(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_StatusInfo(
    CIM_LogicalPort* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_LastErrorCode(
    CIM_LogicalPort* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_LastErrorCode(
    CIM_LogicalPort* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_ErrorDescription(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_ErrorDescription(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_ErrorDescription(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_ErrorCleared(
    CIM_LogicalPort* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_ErrorCleared(
    CIM_LogicalPort* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_OtherIdentifyingInfo(
    CIM_LogicalPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        32,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_OtherIdentifyingInfo(
    CIM_LogicalPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        32,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_OtherIdentifyingInfo(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_PowerOnHours(
    CIM_LogicalPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_PowerOnHours(
    CIM_LogicalPort* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_TotalPowerOnHours(
    CIM_LogicalPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_TotalPowerOnHours(
    CIM_LogicalPort* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_IdentifyingDescriptions(
    CIM_LogicalPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        35,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_IdentifyingDescriptions(
    CIM_LogicalPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        35,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_IdentifyingDescriptions(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_AdditionalAvailability(
    CIM_LogicalPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        36,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_AdditionalAvailability(
    CIM_LogicalPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        36,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_AdditionalAvailability(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_MaxQuiesceTime(
    CIM_LogicalPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_MaxQuiesceTime(
    CIM_LogicalPort* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_Speed(
    CIM_LogicalPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->Speed)->value = x;
    ((MI_Uint64Field*)&self->Speed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_Speed(
    CIM_LogicalPort* self)
{
    memset((void*)&self->Speed, 0, sizeof(self->Speed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_MaxSpeed(
    CIM_LogicalPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxSpeed)->value = x;
    ((MI_Uint64Field*)&self->MaxSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_MaxSpeed(
    CIM_LogicalPort* self)
{
    memset((void*)&self->MaxSpeed, 0, sizeof(self->MaxSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_RequestedSpeed(
    CIM_LogicalPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RequestedSpeed)->value = x;
    ((MI_Uint64Field*)&self->RequestedSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_RequestedSpeed(
    CIM_LogicalPort* self)
{
    memset((void*)&self->RequestedSpeed, 0, sizeof(self->RequestedSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_UsageRestriction(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->UsageRestriction)->value = x;
    ((MI_Uint16Field*)&self->UsageRestriction)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_UsageRestriction(
    CIM_LogicalPort* self)
{
    memset((void*)&self->UsageRestriction, 0, sizeof(self->UsageRestriction));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_PortType(
    CIM_LogicalPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PortType)->value = x;
    ((MI_Uint16Field*)&self->PortType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_PortType(
    CIM_LogicalPort* self)
{
    memset((void*)&self->PortType, 0, sizeof(self->PortType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Set_OtherPortType(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPtr_OtherPortType(
    CIM_LogicalPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Clear_OtherPortType(
    CIM_LogicalPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        43);
}

/*
**==============================================================================
**
** CIM_LogicalPort.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_LogicalPort_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Set_MIReturn(
    CIM_LogicalPort_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Clear_MIReturn(
    CIM_LogicalPort_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Set_RequestedState(
    CIM_LogicalPort_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Clear_RequestedState(
    CIM_LogicalPort_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Set_Job(
    CIM_LogicalPort_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_SetPtr_Job(
    CIM_LogicalPort_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Clear_Job(
    CIM_LogicalPort_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Set_TimeoutPeriod(
    CIM_LogicalPort_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RequestStateChange_Clear_TimeoutPeriod(
    CIM_LogicalPort_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalPort.SetPowerState()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
CIM_LogicalPort_SetPowerState;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPowerState_Set_MIReturn(
    CIM_LogicalPort_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPowerState_Clear_MIReturn(
    CIM_LogicalPort_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPowerState_Set_PowerState(
    CIM_LogicalPort_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPowerState_Clear_PowerState(
    CIM_LogicalPort_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPowerState_Set_Time(
    CIM_LogicalPort_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SetPowerState_Clear_Time(
    CIM_LogicalPort_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalPort.Reset()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_LogicalPort_Reset;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Reset_Set_MIReturn(
    CIM_LogicalPort_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_Reset_Clear_MIReturn(
    CIM_LogicalPort_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalPort.EnableDevice()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
CIM_LogicalPort_EnableDevice;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_EnableDevice_Set_MIReturn(
    CIM_LogicalPort_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_EnableDevice_Clear_MIReturn(
    CIM_LogicalPort_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_EnableDevice_Set_Enabled(
    CIM_LogicalPort_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_EnableDevice_Clear_Enabled(
    CIM_LogicalPort_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalPort.OnlineDevice()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
CIM_LogicalPort_OnlineDevice;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_OnlineDevice_Set_MIReturn(
    CIM_LogicalPort_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_OnlineDevice_Clear_MIReturn(
    CIM_LogicalPort_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_OnlineDevice_Set_Online(
    CIM_LogicalPort_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_OnlineDevice_Clear_Online(
    CIM_LogicalPort_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalPort.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
CIM_LogicalPort_QuiesceDevice;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_QuiesceDevice_Set_MIReturn(
    CIM_LogicalPort_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_QuiesceDevice_Clear_MIReturn(
    CIM_LogicalPort_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_QuiesceDevice_Set_Quiesce(
    CIM_LogicalPort_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_QuiesceDevice_Clear_Quiesce(
    CIM_LogicalPort_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalPort.SaveProperties()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_LogicalPort_SaveProperties;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SaveProperties_Set_MIReturn(
    CIM_LogicalPort_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_SaveProperties_Clear_MIReturn(
    CIM_LogicalPort_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalPort.RestoreProperties()
**
**==============================================================================
*/

typedef struct _CIM_LogicalPort_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_LogicalPort_RestoreProperties;

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RestoreProperties_Set_MIReturn(
    CIM_LogicalPort_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalPort_RestoreProperties_Clear_MIReturn(
    CIM_LogicalPort_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_LogicalPort_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_LogicalPort_Class : public CIM_LogicalDevice_Class
{
public:
    
    typedef CIM_LogicalPort Self;
    
    CIM_LogicalPort_Class() :
        CIM_LogicalDevice_Class(&CIM_LogicalPort_rtti)
    {
    }
    
    CIM_LogicalPort_Class(
        const CIM_LogicalPort* instanceName,
        bool keysOnly) :
        CIM_LogicalDevice_Class(
            &CIM_LogicalPort_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalPort_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalDevice_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalPort_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalDevice_Class(clDecl)
    {
    }
    
    CIM_LogicalPort_Class& operator=(
        const CIM_LogicalPort_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalPort_Class(
        const CIM_LogicalPort_Class& x) :
        CIM_LogicalDevice_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_LogicalPort_rtti;
    }

    //
    // CIM_LogicalPort_Class.Speed
    //
    
    const Field<Uint64>& Speed() const
    {
        const size_t n = offsetof(Self, Speed);
        return GetField<Uint64>(n);
    }
    
    void Speed(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, Speed);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& Speed_value() const
    {
        const size_t n = offsetof(Self, Speed);
        return GetField<Uint64>(n).value;
    }
    
    void Speed_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, Speed);
        GetField<Uint64>(n).Set(x);
    }
    
    bool Speed_exists() const
    {
        const size_t n = offsetof(Self, Speed);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void Speed_clear()
    {
        const size_t n = offsetof(Self, Speed);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_LogicalPort_Class.MaxSpeed
    //
    
    const Field<Uint64>& MaxSpeed() const
    {
        const size_t n = offsetof(Self, MaxSpeed);
        return GetField<Uint64>(n);
    }
    
    void MaxSpeed(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MaxSpeed);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MaxSpeed_value() const
    {
        const size_t n = offsetof(Self, MaxSpeed);
        return GetField<Uint64>(n).value;
    }
    
    void MaxSpeed_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MaxSpeed);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MaxSpeed_exists() const
    {
        const size_t n = offsetof(Self, MaxSpeed);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MaxSpeed_clear()
    {
        const size_t n = offsetof(Self, MaxSpeed);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_LogicalPort_Class.RequestedSpeed
    //
    
    const Field<Uint64>& RequestedSpeed() const
    {
        const size_t n = offsetof(Self, RequestedSpeed);
        return GetField<Uint64>(n);
    }
    
    void RequestedSpeed(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, RequestedSpeed);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& RequestedSpeed_value() const
    {
        const size_t n = offsetof(Self, RequestedSpeed);
        return GetField<Uint64>(n).value;
    }
    
    void RequestedSpeed_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, RequestedSpeed);
        GetField<Uint64>(n).Set(x);
    }
    
    bool RequestedSpeed_exists() const
    {
        const size_t n = offsetof(Self, RequestedSpeed);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void RequestedSpeed_clear()
    {
        const size_t n = offsetof(Self, RequestedSpeed);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_LogicalPort_Class.UsageRestriction
    //
    
    const Field<Uint16>& UsageRestriction() const
    {
        const size_t n = offsetof(Self, UsageRestriction);
        return GetField<Uint16>(n);
    }
    
    void UsageRestriction(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, UsageRestriction);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& UsageRestriction_value() const
    {
        const size_t n = offsetof(Self, UsageRestriction);
        return GetField<Uint16>(n).value;
    }
    
    void UsageRestriction_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, UsageRestriction);
        GetField<Uint16>(n).Set(x);
    }
    
    bool UsageRestriction_exists() const
    {
        const size_t n = offsetof(Self, UsageRestriction);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void UsageRestriction_clear()
    {
        const size_t n = offsetof(Self, UsageRestriction);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_LogicalPort_Class.PortType
    //
    
    const Field<Uint16>& PortType() const
    {
        const size_t n = offsetof(Self, PortType);
        return GetField<Uint16>(n);
    }
    
    void PortType(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, PortType);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& PortType_value() const
    {
        const size_t n = offsetof(Self, PortType);
        return GetField<Uint16>(n).value;
    }
    
    void PortType_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, PortType);
        GetField<Uint16>(n).Set(x);
    }
    
    bool PortType_exists() const
    {
        const size_t n = offsetof(Self, PortType);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void PortType_clear()
    {
        const size_t n = offsetof(Self, PortType);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_LogicalPort_Class.OtherPortType
    //
    
    const Field<String>& OtherPortType() const
    {
        const size_t n = offsetof(Self, OtherPortType);
        return GetField<String>(n);
    }
    
    void OtherPortType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherPortType);
        GetField<String>(n) = x;
    }
    
    const String& OtherPortType_value() const
    {
        const size_t n = offsetof(Self, OtherPortType);
        return GetField<String>(n).value;
    }
    
    void OtherPortType_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherPortType);
        GetField<String>(n).Set(x);
    }
    
    bool OtherPortType_exists() const
    {
        const size_t n = offsetof(Self, OtherPortType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherPortType_clear()
    {
        const size_t n = offsetof(Self, OtherPortType);
        GetField<String>(n).Clear();
    }
};

typedef Array<CIM_LogicalPort_Class> CIM_LogicalPort_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_LogicalPort_h */
