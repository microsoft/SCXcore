/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_LogicalDevice_h
#define _CIM_LogicalDevice_h

#include <MI.h>
#include "CIM_EnabledLogicalElement.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_LogicalDevice [CIM_LogicalDevice]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice /* extends CIM_EnabledLogicalElement */
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
}
CIM_LogicalDevice;

typedef struct _CIM_LogicalDevice_Ref
{
    CIM_LogicalDevice* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalDevice_Ref;

typedef struct _CIM_LogicalDevice_ConstRef
{
    MI_CONST CIM_LogicalDevice* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalDevice_ConstRef;

typedef struct _CIM_LogicalDevice_Array
{
    struct _CIM_LogicalDevice** data;
    MI_Uint32 size;
}
CIM_LogicalDevice_Array;

typedef struct _CIM_LogicalDevice_ConstArray
{
    struct _CIM_LogicalDevice MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_LogicalDevice_ConstArray;

typedef struct _CIM_LogicalDevice_ArrayRef
{
    CIM_LogicalDevice_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalDevice_ArrayRef;

typedef struct _CIM_LogicalDevice_ConstArrayRef
{
    CIM_LogicalDevice_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalDevice_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_LogicalDevice_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Construct(
    CIM_LogicalDevice* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_LogicalDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clone(
    const CIM_LogicalDevice* self,
    CIM_LogicalDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_LogicalDevice_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_LogicalDevice_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Destruct(CIM_LogicalDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Delete(CIM_LogicalDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Post(
    const CIM_LogicalDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_InstanceID(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_InstanceID(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_InstanceID(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_Caption(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_Caption(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_Caption(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_Description(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_Description(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_Description(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_ElementName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_ElementName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_ElementName(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_InstallDate(
    CIM_LogicalDevice* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_InstallDate(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_Name(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_Name(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_Name(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_OperationalStatus(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_OperationalStatus(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_OperationalStatus(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_StatusDescriptions(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_StatusDescriptions(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_StatusDescriptions(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_Status(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_Status(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_Status(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_HealthState(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_HealthState(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_CommunicationStatus(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_CommunicationStatus(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_DetailedStatus(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_DetailedStatus(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_OperatingStatus(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_OperatingStatus(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_PrimaryStatus(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_PrimaryStatus(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_EnabledState(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_EnabledState(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_OtherEnabledState(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_OtherEnabledState(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_OtherEnabledState(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_RequestedState(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_RequestedState(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_EnabledDefault(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_EnabledDefault(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_TimeOfLastStateChange(
    CIM_LogicalDevice* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_TimeOfLastStateChange(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_AvailableRequestedStates(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_AvailableRequestedStates(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_AvailableRequestedStates(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_TransitioningToState(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_TransitioningToState(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_SystemCreationClassName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_SystemCreationClassName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_SystemCreationClassName(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_SystemName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_SystemName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_SystemName(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_CreationClassName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_CreationClassName(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_CreationClassName(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_DeviceID(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_DeviceID(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_DeviceID(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_PowerManagementSupported(
    CIM_LogicalDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_PowerManagementSupported(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_PowerManagementCapabilities(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_PowerManagementCapabilities(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_PowerManagementCapabilities(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_Availability(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_Availability(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_StatusInfo(
    CIM_LogicalDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_StatusInfo(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_LastErrorCode(
    CIM_LogicalDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_LastErrorCode(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_ErrorDescription(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_ErrorDescription(
    CIM_LogicalDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_ErrorDescription(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_ErrorCleared(
    CIM_LogicalDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_ErrorCleared(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_OtherIdentifyingInfo(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_OtherIdentifyingInfo(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_OtherIdentifyingInfo(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_PowerOnHours(
    CIM_LogicalDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_PowerOnHours(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_TotalPowerOnHours(
    CIM_LogicalDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_TotalPowerOnHours(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_IdentifyingDescriptions(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_IdentifyingDescriptions(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_IdentifyingDescriptions(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_AdditionalAvailability(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPtr_AdditionalAvailability(
    CIM_LogicalDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_AdditionalAvailability(
    CIM_LogicalDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Set_MaxQuiesceTime(
    CIM_LogicalDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Clear_MaxQuiesceTime(
    CIM_LogicalDevice* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_LogicalDevice_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Set_MIReturn(
    CIM_LogicalDevice_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Clear_MIReturn(
    CIM_LogicalDevice_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Set_RequestedState(
    CIM_LogicalDevice_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Clear_RequestedState(
    CIM_LogicalDevice_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Set_Job(
    CIM_LogicalDevice_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_SetPtr_Job(
    CIM_LogicalDevice_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Clear_Job(
    CIM_LogicalDevice_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Set_TimeoutPeriod(
    CIM_LogicalDevice_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RequestStateChange_Clear_TimeoutPeriod(
    CIM_LogicalDevice_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.SetPowerState()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
CIM_LogicalDevice_SetPowerState;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_LogicalDevice_SetPowerState_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Construct(
    CIM_LogicalDevice_SetPowerState* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_LogicalDevice_SetPowerState_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Clone(
    const CIM_LogicalDevice_SetPowerState* self,
    CIM_LogicalDevice_SetPowerState** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Destruct(
    CIM_LogicalDevice_SetPowerState* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Delete(
    CIM_LogicalDevice_SetPowerState* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Post(
    const CIM_LogicalDevice_SetPowerState* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Set_MIReturn(
    CIM_LogicalDevice_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Clear_MIReturn(
    CIM_LogicalDevice_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Set_PowerState(
    CIM_LogicalDevice_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Clear_PowerState(
    CIM_LogicalDevice_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Set_Time(
    CIM_LogicalDevice_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SetPowerState_Clear_Time(
    CIM_LogicalDevice_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.Reset()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_LogicalDevice_Reset;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_LogicalDevice_Reset_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Reset_Construct(
    CIM_LogicalDevice_Reset* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_LogicalDevice_Reset_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Reset_Clone(
    const CIM_LogicalDevice_Reset* self,
    CIM_LogicalDevice_Reset** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Reset_Destruct(
    CIM_LogicalDevice_Reset* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Reset_Delete(
    CIM_LogicalDevice_Reset* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Reset_Post(
    const CIM_LogicalDevice_Reset* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Reset_Set_MIReturn(
    CIM_LogicalDevice_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_Reset_Clear_MIReturn(
    CIM_LogicalDevice_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.EnableDevice()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
CIM_LogicalDevice_EnableDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_LogicalDevice_EnableDevice_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Construct(
    CIM_LogicalDevice_EnableDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_LogicalDevice_EnableDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Clone(
    const CIM_LogicalDevice_EnableDevice* self,
    CIM_LogicalDevice_EnableDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Destruct(
    CIM_LogicalDevice_EnableDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Delete(
    CIM_LogicalDevice_EnableDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Post(
    const CIM_LogicalDevice_EnableDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Set_MIReturn(
    CIM_LogicalDevice_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Clear_MIReturn(
    CIM_LogicalDevice_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Set_Enabled(
    CIM_LogicalDevice_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_EnableDevice_Clear_Enabled(
    CIM_LogicalDevice_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.OnlineDevice()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
CIM_LogicalDevice_OnlineDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_LogicalDevice_OnlineDevice_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Construct(
    CIM_LogicalDevice_OnlineDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_LogicalDevice_OnlineDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Clone(
    const CIM_LogicalDevice_OnlineDevice* self,
    CIM_LogicalDevice_OnlineDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Destruct(
    CIM_LogicalDevice_OnlineDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Delete(
    CIM_LogicalDevice_OnlineDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Post(
    const CIM_LogicalDevice_OnlineDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Set_MIReturn(
    CIM_LogicalDevice_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Clear_MIReturn(
    CIM_LogicalDevice_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Set_Online(
    CIM_LogicalDevice_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_OnlineDevice_Clear_Online(
    CIM_LogicalDevice_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
CIM_LogicalDevice_QuiesceDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_LogicalDevice_QuiesceDevice_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Construct(
    CIM_LogicalDevice_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_LogicalDevice_QuiesceDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Clone(
    const CIM_LogicalDevice_QuiesceDevice* self,
    CIM_LogicalDevice_QuiesceDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Destruct(
    CIM_LogicalDevice_QuiesceDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Delete(
    CIM_LogicalDevice_QuiesceDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Post(
    const CIM_LogicalDevice_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Set_MIReturn(
    CIM_LogicalDevice_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Clear_MIReturn(
    CIM_LogicalDevice_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Set_Quiesce(
    CIM_LogicalDevice_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_QuiesceDevice_Clear_Quiesce(
    CIM_LogicalDevice_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.SaveProperties()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_LogicalDevice_SaveProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_LogicalDevice_SaveProperties_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SaveProperties_Construct(
    CIM_LogicalDevice_SaveProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_LogicalDevice_SaveProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SaveProperties_Clone(
    const CIM_LogicalDevice_SaveProperties* self,
    CIM_LogicalDevice_SaveProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SaveProperties_Destruct(
    CIM_LogicalDevice_SaveProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SaveProperties_Delete(
    CIM_LogicalDevice_SaveProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SaveProperties_Post(
    const CIM_LogicalDevice_SaveProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SaveProperties_Set_MIReturn(
    CIM_LogicalDevice_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_SaveProperties_Clear_MIReturn(
    CIM_LogicalDevice_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LogicalDevice.RestoreProperties()
**
**==============================================================================
*/

typedef struct _CIM_LogicalDevice_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_LogicalDevice_RestoreProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_LogicalDevice_RestoreProperties_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RestoreProperties_Construct(
    CIM_LogicalDevice_RestoreProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_LogicalDevice_RestoreProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RestoreProperties_Clone(
    const CIM_LogicalDevice_RestoreProperties* self,
    CIM_LogicalDevice_RestoreProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RestoreProperties_Destruct(
    CIM_LogicalDevice_RestoreProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RestoreProperties_Delete(
    CIM_LogicalDevice_RestoreProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RestoreProperties_Post(
    const CIM_LogicalDevice_RestoreProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RestoreProperties_Set_MIReturn(
    CIM_LogicalDevice_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalDevice_RestoreProperties_Clear_MIReturn(
    CIM_LogicalDevice_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_LogicalDevice_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_LogicalDevice_Class : public CIM_EnabledLogicalElement_Class
{
public:
    
    typedef CIM_LogicalDevice Self;
    
    CIM_LogicalDevice_Class() :
        CIM_EnabledLogicalElement_Class(&CIM_LogicalDevice_rtti)
    {
    }
    
    CIM_LogicalDevice_Class(
        const CIM_LogicalDevice* instanceName,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(
            &CIM_LogicalDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_Class(
        const MI_ClassDecl* clDecl) :
        CIM_EnabledLogicalElement_Class(clDecl)
    {
    }
    
    CIM_LogicalDevice_Class& operator=(
        const CIM_LogicalDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_Class(
        const CIM_LogicalDevice_Class& x) :
        CIM_EnabledLogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_LogicalDevice_rtti;
    }

    //
    // CIM_LogicalDevice_Class.SystemCreationClassName
    //
    
    const Field<String>& SystemCreationClassName() const
    {
        const size_t n = offsetof(Self, SystemCreationClassName);
        return GetField<String>(n);
    }
    
    void SystemCreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, SystemCreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& SystemCreationClassName_value() const
    {
        const size_t n = offsetof(Self, SystemCreationClassName);
        return GetField<String>(n).value;
    }
    
    void SystemCreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, SystemCreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool SystemCreationClassName_exists() const
    {
        const size_t n = offsetof(Self, SystemCreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void SystemCreationClassName_clear()
    {
        const size_t n = offsetof(Self, SystemCreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.SystemName
    //
    
    const Field<String>& SystemName() const
    {
        const size_t n = offsetof(Self, SystemName);
        return GetField<String>(n);
    }
    
    void SystemName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, SystemName);
        GetField<String>(n) = x;
    }
    
    const String& SystemName_value() const
    {
        const size_t n = offsetof(Self, SystemName);
        return GetField<String>(n).value;
    }
    
    void SystemName_value(const String& x)
    {
        const size_t n = offsetof(Self, SystemName);
        GetField<String>(n).Set(x);
    }
    
    bool SystemName_exists() const
    {
        const size_t n = offsetof(Self, SystemName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void SystemName_clear()
    {
        const size_t n = offsetof(Self, SystemName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.CreationClassName
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
    // CIM_LogicalDevice_Class.DeviceID
    //
    
    const Field<String>& DeviceID() const
    {
        const size_t n = offsetof(Self, DeviceID);
        return GetField<String>(n);
    }
    
    void DeviceID(const Field<String>& x)
    {
        const size_t n = offsetof(Self, DeviceID);
        GetField<String>(n) = x;
    }
    
    const String& DeviceID_value() const
    {
        const size_t n = offsetof(Self, DeviceID);
        return GetField<String>(n).value;
    }
    
    void DeviceID_value(const String& x)
    {
        const size_t n = offsetof(Self, DeviceID);
        GetField<String>(n).Set(x);
    }
    
    bool DeviceID_exists() const
    {
        const size_t n = offsetof(Self, DeviceID);
        return GetField<String>(n).exists ? true : false;
    }
    
    void DeviceID_clear()
    {
        const size_t n = offsetof(Self, DeviceID);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.PowerManagementSupported
    //
    
    const Field<Boolean>& PowerManagementSupported() const
    {
        const size_t n = offsetof(Self, PowerManagementSupported);
        return GetField<Boolean>(n);
    }
    
    void PowerManagementSupported(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, PowerManagementSupported);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& PowerManagementSupported_value() const
    {
        const size_t n = offsetof(Self, PowerManagementSupported);
        return GetField<Boolean>(n).value;
    }
    
    void PowerManagementSupported_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, PowerManagementSupported);
        GetField<Boolean>(n).Set(x);
    }
    
    bool PowerManagementSupported_exists() const
    {
        const size_t n = offsetof(Self, PowerManagementSupported);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void PowerManagementSupported_clear()
    {
        const size_t n = offsetof(Self, PowerManagementSupported);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.PowerManagementCapabilities
    //
    
    const Field<Uint16A>& PowerManagementCapabilities() const
    {
        const size_t n = offsetof(Self, PowerManagementCapabilities);
        return GetField<Uint16A>(n);
    }
    
    void PowerManagementCapabilities(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, PowerManagementCapabilities);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& PowerManagementCapabilities_value() const
    {
        const size_t n = offsetof(Self, PowerManagementCapabilities);
        return GetField<Uint16A>(n).value;
    }
    
    void PowerManagementCapabilities_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, PowerManagementCapabilities);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool PowerManagementCapabilities_exists() const
    {
        const size_t n = offsetof(Self, PowerManagementCapabilities);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void PowerManagementCapabilities_clear()
    {
        const size_t n = offsetof(Self, PowerManagementCapabilities);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.Availability
    //
    
    const Field<Uint16>& Availability() const
    {
        const size_t n = offsetof(Self, Availability);
        return GetField<Uint16>(n);
    }
    
    void Availability(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, Availability);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& Availability_value() const
    {
        const size_t n = offsetof(Self, Availability);
        return GetField<Uint16>(n).value;
    }
    
    void Availability_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, Availability);
        GetField<Uint16>(n).Set(x);
    }
    
    bool Availability_exists() const
    {
        const size_t n = offsetof(Self, Availability);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void Availability_clear()
    {
        const size_t n = offsetof(Self, Availability);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.StatusInfo
    //
    
    const Field<Uint16>& StatusInfo() const
    {
        const size_t n = offsetof(Self, StatusInfo);
        return GetField<Uint16>(n);
    }
    
    void StatusInfo(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, StatusInfo);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& StatusInfo_value() const
    {
        const size_t n = offsetof(Self, StatusInfo);
        return GetField<Uint16>(n).value;
    }
    
    void StatusInfo_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, StatusInfo);
        GetField<Uint16>(n).Set(x);
    }
    
    bool StatusInfo_exists() const
    {
        const size_t n = offsetof(Self, StatusInfo);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void StatusInfo_clear()
    {
        const size_t n = offsetof(Self, StatusInfo);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.LastErrorCode
    //
    
    const Field<Uint32>& LastErrorCode() const
    {
        const size_t n = offsetof(Self, LastErrorCode);
        return GetField<Uint32>(n);
    }
    
    void LastErrorCode(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, LastErrorCode);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& LastErrorCode_value() const
    {
        const size_t n = offsetof(Self, LastErrorCode);
        return GetField<Uint32>(n).value;
    }
    
    void LastErrorCode_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, LastErrorCode);
        GetField<Uint32>(n).Set(x);
    }
    
    bool LastErrorCode_exists() const
    {
        const size_t n = offsetof(Self, LastErrorCode);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void LastErrorCode_clear()
    {
        const size_t n = offsetof(Self, LastErrorCode);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.ErrorDescription
    //
    
    const Field<String>& ErrorDescription() const
    {
        const size_t n = offsetof(Self, ErrorDescription);
        return GetField<String>(n);
    }
    
    void ErrorDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ErrorDescription);
        GetField<String>(n) = x;
    }
    
    const String& ErrorDescription_value() const
    {
        const size_t n = offsetof(Self, ErrorDescription);
        return GetField<String>(n).value;
    }
    
    void ErrorDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, ErrorDescription);
        GetField<String>(n).Set(x);
    }
    
    bool ErrorDescription_exists() const
    {
        const size_t n = offsetof(Self, ErrorDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ErrorDescription_clear()
    {
        const size_t n = offsetof(Self, ErrorDescription);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.ErrorCleared
    //
    
    const Field<Boolean>& ErrorCleared() const
    {
        const size_t n = offsetof(Self, ErrorCleared);
        return GetField<Boolean>(n);
    }
    
    void ErrorCleared(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, ErrorCleared);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& ErrorCleared_value() const
    {
        const size_t n = offsetof(Self, ErrorCleared);
        return GetField<Boolean>(n).value;
    }
    
    void ErrorCleared_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, ErrorCleared);
        GetField<Boolean>(n).Set(x);
    }
    
    bool ErrorCleared_exists() const
    {
        const size_t n = offsetof(Self, ErrorCleared);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void ErrorCleared_clear()
    {
        const size_t n = offsetof(Self, ErrorCleared);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.OtherIdentifyingInfo
    //
    
    const Field<StringA>& OtherIdentifyingInfo() const
    {
        const size_t n = offsetof(Self, OtherIdentifyingInfo);
        return GetField<StringA>(n);
    }
    
    void OtherIdentifyingInfo(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, OtherIdentifyingInfo);
        GetField<StringA>(n) = x;
    }
    
    const StringA& OtherIdentifyingInfo_value() const
    {
        const size_t n = offsetof(Self, OtherIdentifyingInfo);
        return GetField<StringA>(n).value;
    }
    
    void OtherIdentifyingInfo_value(const StringA& x)
    {
        const size_t n = offsetof(Self, OtherIdentifyingInfo);
        GetField<StringA>(n).Set(x);
    }
    
    bool OtherIdentifyingInfo_exists() const
    {
        const size_t n = offsetof(Self, OtherIdentifyingInfo);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void OtherIdentifyingInfo_clear()
    {
        const size_t n = offsetof(Self, OtherIdentifyingInfo);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.PowerOnHours
    //
    
    const Field<Uint64>& PowerOnHours() const
    {
        const size_t n = offsetof(Self, PowerOnHours);
        return GetField<Uint64>(n);
    }
    
    void PowerOnHours(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, PowerOnHours);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& PowerOnHours_value() const
    {
        const size_t n = offsetof(Self, PowerOnHours);
        return GetField<Uint64>(n).value;
    }
    
    void PowerOnHours_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, PowerOnHours);
        GetField<Uint64>(n).Set(x);
    }
    
    bool PowerOnHours_exists() const
    {
        const size_t n = offsetof(Self, PowerOnHours);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void PowerOnHours_clear()
    {
        const size_t n = offsetof(Self, PowerOnHours);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.TotalPowerOnHours
    //
    
    const Field<Uint64>& TotalPowerOnHours() const
    {
        const size_t n = offsetof(Self, TotalPowerOnHours);
        return GetField<Uint64>(n);
    }
    
    void TotalPowerOnHours(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalPowerOnHours);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalPowerOnHours_value() const
    {
        const size_t n = offsetof(Self, TotalPowerOnHours);
        return GetField<Uint64>(n).value;
    }
    
    void TotalPowerOnHours_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalPowerOnHours);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalPowerOnHours_exists() const
    {
        const size_t n = offsetof(Self, TotalPowerOnHours);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalPowerOnHours_clear()
    {
        const size_t n = offsetof(Self, TotalPowerOnHours);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.IdentifyingDescriptions
    //
    
    const Field<StringA>& IdentifyingDescriptions() const
    {
        const size_t n = offsetof(Self, IdentifyingDescriptions);
        return GetField<StringA>(n);
    }
    
    void IdentifyingDescriptions(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, IdentifyingDescriptions);
        GetField<StringA>(n) = x;
    }
    
    const StringA& IdentifyingDescriptions_value() const
    {
        const size_t n = offsetof(Self, IdentifyingDescriptions);
        return GetField<StringA>(n).value;
    }
    
    void IdentifyingDescriptions_value(const StringA& x)
    {
        const size_t n = offsetof(Self, IdentifyingDescriptions);
        GetField<StringA>(n).Set(x);
    }
    
    bool IdentifyingDescriptions_exists() const
    {
        const size_t n = offsetof(Self, IdentifyingDescriptions);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void IdentifyingDescriptions_clear()
    {
        const size_t n = offsetof(Self, IdentifyingDescriptions);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.AdditionalAvailability
    //
    
    const Field<Uint16A>& AdditionalAvailability() const
    {
        const size_t n = offsetof(Self, AdditionalAvailability);
        return GetField<Uint16A>(n);
    }
    
    void AdditionalAvailability(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, AdditionalAvailability);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& AdditionalAvailability_value() const
    {
        const size_t n = offsetof(Self, AdditionalAvailability);
        return GetField<Uint16A>(n).value;
    }
    
    void AdditionalAvailability_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, AdditionalAvailability);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool AdditionalAvailability_exists() const
    {
        const size_t n = offsetof(Self, AdditionalAvailability);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void AdditionalAvailability_clear()
    {
        const size_t n = offsetof(Self, AdditionalAvailability);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_LogicalDevice_Class.MaxQuiesceTime
    //
    
    const Field<Uint64>& MaxQuiesceTime() const
    {
        const size_t n = offsetof(Self, MaxQuiesceTime);
        return GetField<Uint64>(n);
    }
    
    void MaxQuiesceTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MaxQuiesceTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MaxQuiesceTime_value() const
    {
        const size_t n = offsetof(Self, MaxQuiesceTime);
        return GetField<Uint64>(n).value;
    }
    
    void MaxQuiesceTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MaxQuiesceTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MaxQuiesceTime_exists() const
    {
        const size_t n = offsetof(Self, MaxQuiesceTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MaxQuiesceTime_clear()
    {
        const size_t n = offsetof(Self, MaxQuiesceTime);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<CIM_LogicalDevice_Class> CIM_LogicalDevice_ClassA;

class CIM_LogicalDevice_SetPowerState_Class : public Instance
{
public:
    
    typedef CIM_LogicalDevice_SetPowerState Self;
    
    CIM_LogicalDevice_SetPowerState_Class() :
        Instance(&CIM_LogicalDevice_SetPowerState_rtti)
    {
    }
    
    CIM_LogicalDevice_SetPowerState_Class(
        const CIM_LogicalDevice_SetPowerState* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_LogicalDevice_SetPowerState_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_SetPowerState_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_SetPowerState_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_LogicalDevice_SetPowerState_Class& operator=(
        const CIM_LogicalDevice_SetPowerState_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_SetPowerState_Class(
        const CIM_LogicalDevice_SetPowerState_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_LogicalDevice_SetPowerState_Class.MIReturn
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
    // CIM_LogicalDevice_SetPowerState_Class.PowerState
    //
    
    const Field<Uint16>& PowerState() const
    {
        const size_t n = offsetof(Self, PowerState);
        return GetField<Uint16>(n);
    }
    
    void PowerState(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, PowerState);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& PowerState_value() const
    {
        const size_t n = offsetof(Self, PowerState);
        return GetField<Uint16>(n).value;
    }
    
    void PowerState_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, PowerState);
        GetField<Uint16>(n).Set(x);
    }
    
    bool PowerState_exists() const
    {
        const size_t n = offsetof(Self, PowerState);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void PowerState_clear()
    {
        const size_t n = offsetof(Self, PowerState);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_LogicalDevice_SetPowerState_Class.Time
    //
    
    const Field<Datetime>& Time() const
    {
        const size_t n = offsetof(Self, Time);
        return GetField<Datetime>(n);
    }
    
    void Time(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, Time);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& Time_value() const
    {
        const size_t n = offsetof(Self, Time);
        return GetField<Datetime>(n).value;
    }
    
    void Time_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, Time);
        GetField<Datetime>(n).Set(x);
    }
    
    bool Time_exists() const
    {
        const size_t n = offsetof(Self, Time);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void Time_clear()
    {
        const size_t n = offsetof(Self, Time);
        GetField<Datetime>(n).Clear();
    }
};

typedef Array<CIM_LogicalDevice_SetPowerState_Class> CIM_LogicalDevice_SetPowerState_ClassA;

class CIM_LogicalDevice_Reset_Class : public Instance
{
public:
    
    typedef CIM_LogicalDevice_Reset Self;
    
    CIM_LogicalDevice_Reset_Class() :
        Instance(&CIM_LogicalDevice_Reset_rtti)
    {
    }
    
    CIM_LogicalDevice_Reset_Class(
        const CIM_LogicalDevice_Reset* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_LogicalDevice_Reset_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_Reset_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_Reset_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_LogicalDevice_Reset_Class& operator=(
        const CIM_LogicalDevice_Reset_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_Reset_Class(
        const CIM_LogicalDevice_Reset_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_LogicalDevice_Reset_Class.MIReturn
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

typedef Array<CIM_LogicalDevice_Reset_Class> CIM_LogicalDevice_Reset_ClassA;

class CIM_LogicalDevice_EnableDevice_Class : public Instance
{
public:
    
    typedef CIM_LogicalDevice_EnableDevice Self;
    
    CIM_LogicalDevice_EnableDevice_Class() :
        Instance(&CIM_LogicalDevice_EnableDevice_rtti)
    {
    }
    
    CIM_LogicalDevice_EnableDevice_Class(
        const CIM_LogicalDevice_EnableDevice* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_LogicalDevice_EnableDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_EnableDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_EnableDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_LogicalDevice_EnableDevice_Class& operator=(
        const CIM_LogicalDevice_EnableDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_EnableDevice_Class(
        const CIM_LogicalDevice_EnableDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_LogicalDevice_EnableDevice_Class.MIReturn
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
    // CIM_LogicalDevice_EnableDevice_Class.Enabled
    //
    
    const Field<Boolean>& Enabled() const
    {
        const size_t n = offsetof(Self, Enabled);
        return GetField<Boolean>(n);
    }
    
    void Enabled(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Enabled);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Enabled_value() const
    {
        const size_t n = offsetof(Self, Enabled);
        return GetField<Boolean>(n).value;
    }
    
    void Enabled_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Enabled);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Enabled_exists() const
    {
        const size_t n = offsetof(Self, Enabled);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Enabled_clear()
    {
        const size_t n = offsetof(Self, Enabled);
        GetField<Boolean>(n).Clear();
    }
};

typedef Array<CIM_LogicalDevice_EnableDevice_Class> CIM_LogicalDevice_EnableDevice_ClassA;

class CIM_LogicalDevice_OnlineDevice_Class : public Instance
{
public:
    
    typedef CIM_LogicalDevice_OnlineDevice Self;
    
    CIM_LogicalDevice_OnlineDevice_Class() :
        Instance(&CIM_LogicalDevice_OnlineDevice_rtti)
    {
    }
    
    CIM_LogicalDevice_OnlineDevice_Class(
        const CIM_LogicalDevice_OnlineDevice* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_LogicalDevice_OnlineDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_OnlineDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_OnlineDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_LogicalDevice_OnlineDevice_Class& operator=(
        const CIM_LogicalDevice_OnlineDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_OnlineDevice_Class(
        const CIM_LogicalDevice_OnlineDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_LogicalDevice_OnlineDevice_Class.MIReturn
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
    // CIM_LogicalDevice_OnlineDevice_Class.Online
    //
    
    const Field<Boolean>& Online() const
    {
        const size_t n = offsetof(Self, Online);
        return GetField<Boolean>(n);
    }
    
    void Online(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Online);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Online_value() const
    {
        const size_t n = offsetof(Self, Online);
        return GetField<Boolean>(n).value;
    }
    
    void Online_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Online);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Online_exists() const
    {
        const size_t n = offsetof(Self, Online);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Online_clear()
    {
        const size_t n = offsetof(Self, Online);
        GetField<Boolean>(n).Clear();
    }
};

typedef Array<CIM_LogicalDevice_OnlineDevice_Class> CIM_LogicalDevice_OnlineDevice_ClassA;

class CIM_LogicalDevice_QuiesceDevice_Class : public Instance
{
public:
    
    typedef CIM_LogicalDevice_QuiesceDevice Self;
    
    CIM_LogicalDevice_QuiesceDevice_Class() :
        Instance(&CIM_LogicalDevice_QuiesceDevice_rtti)
    {
    }
    
    CIM_LogicalDevice_QuiesceDevice_Class(
        const CIM_LogicalDevice_QuiesceDevice* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_LogicalDevice_QuiesceDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_LogicalDevice_QuiesceDevice_Class& operator=(
        const CIM_LogicalDevice_QuiesceDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_QuiesceDevice_Class(
        const CIM_LogicalDevice_QuiesceDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_LogicalDevice_QuiesceDevice_Class.MIReturn
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
    // CIM_LogicalDevice_QuiesceDevice_Class.Quiesce
    //
    
    const Field<Boolean>& Quiesce() const
    {
        const size_t n = offsetof(Self, Quiesce);
        return GetField<Boolean>(n);
    }
    
    void Quiesce(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Quiesce);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Quiesce_value() const
    {
        const size_t n = offsetof(Self, Quiesce);
        return GetField<Boolean>(n).value;
    }
    
    void Quiesce_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Quiesce);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Quiesce_exists() const
    {
        const size_t n = offsetof(Self, Quiesce);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Quiesce_clear()
    {
        const size_t n = offsetof(Self, Quiesce);
        GetField<Boolean>(n).Clear();
    }
};

typedef Array<CIM_LogicalDevice_QuiesceDevice_Class> CIM_LogicalDevice_QuiesceDevice_ClassA;

class CIM_LogicalDevice_SaveProperties_Class : public Instance
{
public:
    
    typedef CIM_LogicalDevice_SaveProperties Self;
    
    CIM_LogicalDevice_SaveProperties_Class() :
        Instance(&CIM_LogicalDevice_SaveProperties_rtti)
    {
    }
    
    CIM_LogicalDevice_SaveProperties_Class(
        const CIM_LogicalDevice_SaveProperties* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_LogicalDevice_SaveProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_SaveProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_SaveProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_LogicalDevice_SaveProperties_Class& operator=(
        const CIM_LogicalDevice_SaveProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_SaveProperties_Class(
        const CIM_LogicalDevice_SaveProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_LogicalDevice_SaveProperties_Class.MIReturn
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

typedef Array<CIM_LogicalDevice_SaveProperties_Class> CIM_LogicalDevice_SaveProperties_ClassA;

class CIM_LogicalDevice_RestoreProperties_Class : public Instance
{
public:
    
    typedef CIM_LogicalDevice_RestoreProperties Self;
    
    CIM_LogicalDevice_RestoreProperties_Class() :
        Instance(&CIM_LogicalDevice_RestoreProperties_rtti)
    {
    }
    
    CIM_LogicalDevice_RestoreProperties_Class(
        const CIM_LogicalDevice_RestoreProperties* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_LogicalDevice_RestoreProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalDevice_RestoreProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalDevice_RestoreProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_LogicalDevice_RestoreProperties_Class& operator=(
        const CIM_LogicalDevice_RestoreProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalDevice_RestoreProperties_Class(
        const CIM_LogicalDevice_RestoreProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_LogicalDevice_RestoreProperties_Class.MIReturn
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

typedef Array<CIM_LogicalDevice_RestoreProperties_Class> CIM_LogicalDevice_RestoreProperties_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_LogicalDevice_h */
