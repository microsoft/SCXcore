/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_Processor_h
#define _CIM_Processor_h

#include <MI.h>
#include "CIM_LogicalDevice.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_Processor [CIM_Processor]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _CIM_Processor /* extends CIM_LogicalDevice */
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
    /* CIM_Processor properties */
    MI_ConstStringField Role;
    MI_ConstUint16Field Family;
    MI_ConstStringField OtherFamilyDescription;
    MI_ConstUint16Field UpgradeMethod;
    MI_ConstUint32Field MaxClockSpeed;
    MI_ConstUint32Field CurrentClockSpeed;
    MI_ConstUint16Field DataWidth;
    MI_ConstUint16Field AddressWidth;
    MI_ConstUint16Field LoadPercentage;
    MI_ConstStringField Stepping;
    MI_ConstStringField UniqueID;
    MI_ConstUint16Field CPUStatus;
    MI_ConstUint32Field ExternalBusClockSpeed;
    MI_ConstUint16AField Characteristics;
    MI_ConstUint16AField EnabledProcessorCharacteristics;
    MI_ConstUint16Field NumberOfEnabledCores;
}
CIM_Processor;

typedef struct _CIM_Processor_Ref
{
    CIM_Processor* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Processor_Ref;

typedef struct _CIM_Processor_ConstRef
{
    MI_CONST CIM_Processor* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Processor_ConstRef;

typedef struct _CIM_Processor_Array
{
    struct _CIM_Processor** data;
    MI_Uint32 size;
}
CIM_Processor_Array;

typedef struct _CIM_Processor_ConstArray
{
    struct _CIM_Processor MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_Processor_ConstArray;

typedef struct _CIM_Processor_ArrayRef
{
    CIM_Processor_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Processor_ArrayRef;

typedef struct _CIM_Processor_ConstArrayRef
{
    CIM_Processor_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Processor_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_Processor_rtti;

MI_INLINE MI_Result MI_CALL CIM_Processor_Construct(
    CIM_Processor* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_Processor_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clone(
    const CIM_Processor* self,
    CIM_Processor** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_Processor_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_Processor_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Destruct(CIM_Processor* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Delete(CIM_Processor* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Post(
    const CIM_Processor* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_InstanceID(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_InstanceID(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_InstanceID(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Caption(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_Caption(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Caption(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Description(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_Description(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Description(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_ElementName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_ElementName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_ElementName(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_InstallDate(
    CIM_Processor* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_InstallDate(
    CIM_Processor* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Name(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_Name(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Name(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_OperationalStatus(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_OperationalStatus(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_OperationalStatus(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_StatusDescriptions(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_StatusDescriptions(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_StatusDescriptions(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Status(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_Status(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Status(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_HealthState(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_HealthState(
    CIM_Processor* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_CommunicationStatus(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_CommunicationStatus(
    CIM_Processor* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_DetailedStatus(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_DetailedStatus(
    CIM_Processor* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_OperatingStatus(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_OperatingStatus(
    CIM_Processor* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_PrimaryStatus(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_PrimaryStatus(
    CIM_Processor* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_EnabledState(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_EnabledState(
    CIM_Processor* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_OtherEnabledState(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_OtherEnabledState(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_OtherEnabledState(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_RequestedState(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_RequestedState(
    CIM_Processor* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_EnabledDefault(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_EnabledDefault(
    CIM_Processor* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_TimeOfLastStateChange(
    CIM_Processor* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_TimeOfLastStateChange(
    CIM_Processor* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_AvailableRequestedStates(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_AvailableRequestedStates(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_AvailableRequestedStates(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_TransitioningToState(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_TransitioningToState(
    CIM_Processor* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_SystemCreationClassName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_SystemCreationClassName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_SystemCreationClassName(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_SystemName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_SystemName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_SystemName(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_CreationClassName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_CreationClassName(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_CreationClassName(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_DeviceID(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_DeviceID(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_DeviceID(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_PowerManagementSupported(
    CIM_Processor* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_PowerManagementSupported(
    CIM_Processor* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_PowerManagementCapabilities(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_PowerManagementCapabilities(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_PowerManagementCapabilities(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Availability(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Availability(
    CIM_Processor* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_StatusInfo(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_StatusInfo(
    CIM_Processor* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_LastErrorCode(
    CIM_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_LastErrorCode(
    CIM_Processor* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_ErrorDescription(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_ErrorDescription(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_ErrorDescription(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_ErrorCleared(
    CIM_Processor* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_ErrorCleared(
    CIM_Processor* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_OtherIdentifyingInfo(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_OtherIdentifyingInfo(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_OtherIdentifyingInfo(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_PowerOnHours(
    CIM_Processor* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_PowerOnHours(
    CIM_Processor* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_TotalPowerOnHours(
    CIM_Processor* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_TotalPowerOnHours(
    CIM_Processor* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_IdentifyingDescriptions(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_IdentifyingDescriptions(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_IdentifyingDescriptions(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_AdditionalAvailability(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_AdditionalAvailability(
    CIM_Processor* self,
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

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_AdditionalAvailability(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_MaxQuiesceTime(
    CIM_Processor* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_MaxQuiesceTime(
    CIM_Processor* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Role(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_Role(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Role(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Family(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Family)->value = x;
    ((MI_Uint16Field*)&self->Family)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Family(
    CIM_Processor* self)
{
    memset((void*)&self->Family, 0, sizeof(self->Family));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_OtherFamilyDescription(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_OtherFamilyDescription(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_OtherFamilyDescription(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        40);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_UpgradeMethod(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->UpgradeMethod)->value = x;
    ((MI_Uint16Field*)&self->UpgradeMethod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_UpgradeMethod(
    CIM_Processor* self)
{
    memset((void*)&self->UpgradeMethod, 0, sizeof(self->UpgradeMethod));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_MaxClockSpeed(
    CIM_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxClockSpeed)->value = x;
    ((MI_Uint32Field*)&self->MaxClockSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_MaxClockSpeed(
    CIM_Processor* self)
{
    memset((void*)&self->MaxClockSpeed, 0, sizeof(self->MaxClockSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_CurrentClockSpeed(
    CIM_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CurrentClockSpeed)->value = x;
    ((MI_Uint32Field*)&self->CurrentClockSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_CurrentClockSpeed(
    CIM_Processor* self)
{
    memset((void*)&self->CurrentClockSpeed, 0, sizeof(self->CurrentClockSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_DataWidth(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataWidth)->value = x;
    ((MI_Uint16Field*)&self->DataWidth)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_DataWidth(
    CIM_Processor* self)
{
    memset((void*)&self->DataWidth, 0, sizeof(self->DataWidth));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_AddressWidth(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->AddressWidth)->value = x;
    ((MI_Uint16Field*)&self->AddressWidth)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_AddressWidth(
    CIM_Processor* self)
{
    memset((void*)&self->AddressWidth, 0, sizeof(self->AddressWidth));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_LoadPercentage(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->LoadPercentage)->value = x;
    ((MI_Uint16Field*)&self->LoadPercentage)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_LoadPercentage(
    CIM_Processor* self)
{
    memset((void*)&self->LoadPercentage, 0, sizeof(self->LoadPercentage));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Stepping(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_Stepping(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Stepping(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        47);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_UniqueID(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        48,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_UniqueID(
    CIM_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        48,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_UniqueID(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        48);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_CPUStatus(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CPUStatus)->value = x;
    ((MI_Uint16Field*)&self->CPUStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_CPUStatus(
    CIM_Processor* self)
{
    memset((void*)&self->CPUStatus, 0, sizeof(self->CPUStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_ExternalBusClockSpeed(
    CIM_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ExternalBusClockSpeed)->value = x;
    ((MI_Uint32Field*)&self->ExternalBusClockSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_ExternalBusClockSpeed(
    CIM_Processor* self)
{
    memset((void*)&self->ExternalBusClockSpeed, 0, sizeof(self->ExternalBusClockSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_Characteristics(
    CIM_Processor* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        51,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_Characteristics(
    CIM_Processor* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        51,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_Characteristics(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        51);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_EnabledProcessorCharacteristics(
    CIM_Processor* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        52,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPtr_EnabledProcessorCharacteristics(
    CIM_Processor* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        52,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_EnabledProcessorCharacteristics(
    CIM_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        52);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Set_NumberOfEnabledCores(
    CIM_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NumberOfEnabledCores)->value = x;
    ((MI_Uint16Field*)&self->NumberOfEnabledCores)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Clear_NumberOfEnabledCores(
    CIM_Processor* self)
{
    memset((void*)&self->NumberOfEnabledCores, 0, sizeof(self->NumberOfEnabledCores));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_Processor_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_Processor_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Set_MIReturn(
    CIM_Processor_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Clear_MIReturn(
    CIM_Processor_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Set_RequestedState(
    CIM_Processor_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Clear_RequestedState(
    CIM_Processor_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Set_Job(
    CIM_Processor_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_SetPtr_Job(
    CIM_Processor_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Clear_Job(
    CIM_Processor_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Set_TimeoutPeriod(
    CIM_Processor_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RequestStateChange_Clear_TimeoutPeriod(
    CIM_Processor_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.SetPowerState()
**
**==============================================================================
*/

typedef struct _CIM_Processor_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
CIM_Processor_SetPowerState;

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPowerState_Set_MIReturn(
    CIM_Processor_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPowerState_Clear_MIReturn(
    CIM_Processor_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPowerState_Set_PowerState(
    CIM_Processor_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPowerState_Clear_PowerState(
    CIM_Processor_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPowerState_Set_Time(
    CIM_Processor_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SetPowerState_Clear_Time(
    CIM_Processor_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.Reset()
**
**==============================================================================
*/

typedef struct _CIM_Processor_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_Processor_Reset;

MI_INLINE MI_Result MI_CALL CIM_Processor_Reset_Set_MIReturn(
    CIM_Processor_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_Reset_Clear_MIReturn(
    CIM_Processor_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.EnableDevice()
**
**==============================================================================
*/

typedef struct _CIM_Processor_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
CIM_Processor_EnableDevice;

MI_INLINE MI_Result MI_CALL CIM_Processor_EnableDevice_Set_MIReturn(
    CIM_Processor_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_EnableDevice_Clear_MIReturn(
    CIM_Processor_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_EnableDevice_Set_Enabled(
    CIM_Processor_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_EnableDevice_Clear_Enabled(
    CIM_Processor_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.OnlineDevice()
**
**==============================================================================
*/

typedef struct _CIM_Processor_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
CIM_Processor_OnlineDevice;

MI_INLINE MI_Result MI_CALL CIM_Processor_OnlineDevice_Set_MIReturn(
    CIM_Processor_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_OnlineDevice_Clear_MIReturn(
    CIM_Processor_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_OnlineDevice_Set_Online(
    CIM_Processor_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_OnlineDevice_Clear_Online(
    CIM_Processor_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _CIM_Processor_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
CIM_Processor_QuiesceDevice;

MI_INLINE MI_Result MI_CALL CIM_Processor_QuiesceDevice_Set_MIReturn(
    CIM_Processor_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_QuiesceDevice_Clear_MIReturn(
    CIM_Processor_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_QuiesceDevice_Set_Quiesce(
    CIM_Processor_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_QuiesceDevice_Clear_Quiesce(
    CIM_Processor_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.SaveProperties()
**
**==============================================================================
*/

typedef struct _CIM_Processor_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_Processor_SaveProperties;

MI_INLINE MI_Result MI_CALL CIM_Processor_SaveProperties_Set_MIReturn(
    CIM_Processor_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_SaveProperties_Clear_MIReturn(
    CIM_Processor_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Processor.RestoreProperties()
**
**==============================================================================
*/

typedef struct _CIM_Processor_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_Processor_RestoreProperties;

MI_INLINE MI_Result MI_CALL CIM_Processor_RestoreProperties_Set_MIReturn(
    CIM_Processor_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Processor_RestoreProperties_Clear_MIReturn(
    CIM_Processor_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_Processor_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_Processor_Class : public CIM_LogicalDevice_Class
{
public:
    
    typedef CIM_Processor Self;
    
    CIM_Processor_Class() :
        CIM_LogicalDevice_Class(&CIM_Processor_rtti)
    {
    }
    
    CIM_Processor_Class(
        const CIM_Processor* instanceName,
        bool keysOnly) :
        CIM_LogicalDevice_Class(
            &CIM_Processor_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_Processor_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalDevice_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_Processor_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalDevice_Class(clDecl)
    {
    }
    
    CIM_Processor_Class& operator=(
        const CIM_Processor_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_Processor_Class(
        const CIM_Processor_Class& x) :
        CIM_LogicalDevice_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_Processor_rtti;
    }

    //
    // CIM_Processor_Class.Role
    //
    
    const Field<String>& Role() const
    {
        const size_t n = offsetof(Self, Role);
        return GetField<String>(n);
    }
    
    void Role(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Role);
        GetField<String>(n) = x;
    }
    
    const String& Role_value() const
    {
        const size_t n = offsetof(Self, Role);
        return GetField<String>(n).value;
    }
    
    void Role_value(const String& x)
    {
        const size_t n = offsetof(Self, Role);
        GetField<String>(n).Set(x);
    }
    
    bool Role_exists() const
    {
        const size_t n = offsetof(Self, Role);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Role_clear()
    {
        const size_t n = offsetof(Self, Role);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Processor_Class.Family
    //
    
    const Field<Uint16>& Family() const
    {
        const size_t n = offsetof(Self, Family);
        return GetField<Uint16>(n);
    }
    
    void Family(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, Family);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& Family_value() const
    {
        const size_t n = offsetof(Self, Family);
        return GetField<Uint16>(n).value;
    }
    
    void Family_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, Family);
        GetField<Uint16>(n).Set(x);
    }
    
    bool Family_exists() const
    {
        const size_t n = offsetof(Self, Family);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void Family_clear()
    {
        const size_t n = offsetof(Self, Family);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Processor_Class.OtherFamilyDescription
    //
    
    const Field<String>& OtherFamilyDescription() const
    {
        const size_t n = offsetof(Self, OtherFamilyDescription);
        return GetField<String>(n);
    }
    
    void OtherFamilyDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherFamilyDescription);
        GetField<String>(n) = x;
    }
    
    const String& OtherFamilyDescription_value() const
    {
        const size_t n = offsetof(Self, OtherFamilyDescription);
        return GetField<String>(n).value;
    }
    
    void OtherFamilyDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherFamilyDescription);
        GetField<String>(n).Set(x);
    }
    
    bool OtherFamilyDescription_exists() const
    {
        const size_t n = offsetof(Self, OtherFamilyDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherFamilyDescription_clear()
    {
        const size_t n = offsetof(Self, OtherFamilyDescription);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Processor_Class.UpgradeMethod
    //
    
    const Field<Uint16>& UpgradeMethod() const
    {
        const size_t n = offsetof(Self, UpgradeMethod);
        return GetField<Uint16>(n);
    }
    
    void UpgradeMethod(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, UpgradeMethod);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& UpgradeMethod_value() const
    {
        const size_t n = offsetof(Self, UpgradeMethod);
        return GetField<Uint16>(n).value;
    }
    
    void UpgradeMethod_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, UpgradeMethod);
        GetField<Uint16>(n).Set(x);
    }
    
    bool UpgradeMethod_exists() const
    {
        const size_t n = offsetof(Self, UpgradeMethod);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void UpgradeMethod_clear()
    {
        const size_t n = offsetof(Self, UpgradeMethod);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Processor_Class.MaxClockSpeed
    //
    
    const Field<Uint32>& MaxClockSpeed() const
    {
        const size_t n = offsetof(Self, MaxClockSpeed);
        return GetField<Uint32>(n);
    }
    
    void MaxClockSpeed(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MaxClockSpeed);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MaxClockSpeed_value() const
    {
        const size_t n = offsetof(Self, MaxClockSpeed);
        return GetField<Uint32>(n).value;
    }
    
    void MaxClockSpeed_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MaxClockSpeed);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MaxClockSpeed_exists() const
    {
        const size_t n = offsetof(Self, MaxClockSpeed);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MaxClockSpeed_clear()
    {
        const size_t n = offsetof(Self, MaxClockSpeed);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_Processor_Class.CurrentClockSpeed
    //
    
    const Field<Uint32>& CurrentClockSpeed() const
    {
        const size_t n = offsetof(Self, CurrentClockSpeed);
        return GetField<Uint32>(n);
    }
    
    void CurrentClockSpeed(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, CurrentClockSpeed);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& CurrentClockSpeed_value() const
    {
        const size_t n = offsetof(Self, CurrentClockSpeed);
        return GetField<Uint32>(n).value;
    }
    
    void CurrentClockSpeed_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, CurrentClockSpeed);
        GetField<Uint32>(n).Set(x);
    }
    
    bool CurrentClockSpeed_exists() const
    {
        const size_t n = offsetof(Self, CurrentClockSpeed);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void CurrentClockSpeed_clear()
    {
        const size_t n = offsetof(Self, CurrentClockSpeed);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_Processor_Class.DataWidth
    //
    
    const Field<Uint16>& DataWidth() const
    {
        const size_t n = offsetof(Self, DataWidth);
        return GetField<Uint16>(n);
    }
    
    void DataWidth(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, DataWidth);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& DataWidth_value() const
    {
        const size_t n = offsetof(Self, DataWidth);
        return GetField<Uint16>(n).value;
    }
    
    void DataWidth_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, DataWidth);
        GetField<Uint16>(n).Set(x);
    }
    
    bool DataWidth_exists() const
    {
        const size_t n = offsetof(Self, DataWidth);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void DataWidth_clear()
    {
        const size_t n = offsetof(Self, DataWidth);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Processor_Class.AddressWidth
    //
    
    const Field<Uint16>& AddressWidth() const
    {
        const size_t n = offsetof(Self, AddressWidth);
        return GetField<Uint16>(n);
    }
    
    void AddressWidth(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, AddressWidth);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& AddressWidth_value() const
    {
        const size_t n = offsetof(Self, AddressWidth);
        return GetField<Uint16>(n).value;
    }
    
    void AddressWidth_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, AddressWidth);
        GetField<Uint16>(n).Set(x);
    }
    
    bool AddressWidth_exists() const
    {
        const size_t n = offsetof(Self, AddressWidth);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void AddressWidth_clear()
    {
        const size_t n = offsetof(Self, AddressWidth);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Processor_Class.LoadPercentage
    //
    
    const Field<Uint16>& LoadPercentage() const
    {
        const size_t n = offsetof(Self, LoadPercentage);
        return GetField<Uint16>(n);
    }
    
    void LoadPercentage(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, LoadPercentage);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& LoadPercentage_value() const
    {
        const size_t n = offsetof(Self, LoadPercentage);
        return GetField<Uint16>(n).value;
    }
    
    void LoadPercentage_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, LoadPercentage);
        GetField<Uint16>(n).Set(x);
    }
    
    bool LoadPercentage_exists() const
    {
        const size_t n = offsetof(Self, LoadPercentage);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void LoadPercentage_clear()
    {
        const size_t n = offsetof(Self, LoadPercentage);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Processor_Class.Stepping
    //
    
    const Field<String>& Stepping() const
    {
        const size_t n = offsetof(Self, Stepping);
        return GetField<String>(n);
    }
    
    void Stepping(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Stepping);
        GetField<String>(n) = x;
    }
    
    const String& Stepping_value() const
    {
        const size_t n = offsetof(Self, Stepping);
        return GetField<String>(n).value;
    }
    
    void Stepping_value(const String& x)
    {
        const size_t n = offsetof(Self, Stepping);
        GetField<String>(n).Set(x);
    }
    
    bool Stepping_exists() const
    {
        const size_t n = offsetof(Self, Stepping);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Stepping_clear()
    {
        const size_t n = offsetof(Self, Stepping);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Processor_Class.UniqueID
    //
    
    const Field<String>& UniqueID() const
    {
        const size_t n = offsetof(Self, UniqueID);
        return GetField<String>(n);
    }
    
    void UniqueID(const Field<String>& x)
    {
        const size_t n = offsetof(Self, UniqueID);
        GetField<String>(n) = x;
    }
    
    const String& UniqueID_value() const
    {
        const size_t n = offsetof(Self, UniqueID);
        return GetField<String>(n).value;
    }
    
    void UniqueID_value(const String& x)
    {
        const size_t n = offsetof(Self, UniqueID);
        GetField<String>(n).Set(x);
    }
    
    bool UniqueID_exists() const
    {
        const size_t n = offsetof(Self, UniqueID);
        return GetField<String>(n).exists ? true : false;
    }
    
    void UniqueID_clear()
    {
        const size_t n = offsetof(Self, UniqueID);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Processor_Class.CPUStatus
    //
    
    const Field<Uint16>& CPUStatus() const
    {
        const size_t n = offsetof(Self, CPUStatus);
        return GetField<Uint16>(n);
    }
    
    void CPUStatus(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, CPUStatus);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& CPUStatus_value() const
    {
        const size_t n = offsetof(Self, CPUStatus);
        return GetField<Uint16>(n).value;
    }
    
    void CPUStatus_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, CPUStatus);
        GetField<Uint16>(n).Set(x);
    }
    
    bool CPUStatus_exists() const
    {
        const size_t n = offsetof(Self, CPUStatus);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void CPUStatus_clear()
    {
        const size_t n = offsetof(Self, CPUStatus);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Processor_Class.ExternalBusClockSpeed
    //
    
    const Field<Uint32>& ExternalBusClockSpeed() const
    {
        const size_t n = offsetof(Self, ExternalBusClockSpeed);
        return GetField<Uint32>(n);
    }
    
    void ExternalBusClockSpeed(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, ExternalBusClockSpeed);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& ExternalBusClockSpeed_value() const
    {
        const size_t n = offsetof(Self, ExternalBusClockSpeed);
        return GetField<Uint32>(n).value;
    }
    
    void ExternalBusClockSpeed_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, ExternalBusClockSpeed);
        GetField<Uint32>(n).Set(x);
    }
    
    bool ExternalBusClockSpeed_exists() const
    {
        const size_t n = offsetof(Self, ExternalBusClockSpeed);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void ExternalBusClockSpeed_clear()
    {
        const size_t n = offsetof(Self, ExternalBusClockSpeed);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_Processor_Class.Characteristics
    //
    
    const Field<Uint16A>& Characteristics() const
    {
        const size_t n = offsetof(Self, Characteristics);
        return GetField<Uint16A>(n);
    }
    
    void Characteristics(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, Characteristics);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& Characteristics_value() const
    {
        const size_t n = offsetof(Self, Characteristics);
        return GetField<Uint16A>(n).value;
    }
    
    void Characteristics_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, Characteristics);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool Characteristics_exists() const
    {
        const size_t n = offsetof(Self, Characteristics);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void Characteristics_clear()
    {
        const size_t n = offsetof(Self, Characteristics);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_Processor_Class.EnabledProcessorCharacteristics
    //
    
    const Field<Uint16A>& EnabledProcessorCharacteristics() const
    {
        const size_t n = offsetof(Self, EnabledProcessorCharacteristics);
        return GetField<Uint16A>(n);
    }
    
    void EnabledProcessorCharacteristics(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, EnabledProcessorCharacteristics);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& EnabledProcessorCharacteristics_value() const
    {
        const size_t n = offsetof(Self, EnabledProcessorCharacteristics);
        return GetField<Uint16A>(n).value;
    }
    
    void EnabledProcessorCharacteristics_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, EnabledProcessorCharacteristics);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool EnabledProcessorCharacteristics_exists() const
    {
        const size_t n = offsetof(Self, EnabledProcessorCharacteristics);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void EnabledProcessorCharacteristics_clear()
    {
        const size_t n = offsetof(Self, EnabledProcessorCharacteristics);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_Processor_Class.NumberOfEnabledCores
    //
    
    const Field<Uint16>& NumberOfEnabledCores() const
    {
        const size_t n = offsetof(Self, NumberOfEnabledCores);
        return GetField<Uint16>(n);
    }
    
    void NumberOfEnabledCores(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, NumberOfEnabledCores);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& NumberOfEnabledCores_value() const
    {
        const size_t n = offsetof(Self, NumberOfEnabledCores);
        return GetField<Uint16>(n).value;
    }
    
    void NumberOfEnabledCores_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, NumberOfEnabledCores);
        GetField<Uint16>(n).Set(x);
    }
    
    bool NumberOfEnabledCores_exists() const
    {
        const size_t n = offsetof(Self, NumberOfEnabledCores);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void NumberOfEnabledCores_clear()
    {
        const size_t n = offsetof(Self, NumberOfEnabledCores);
        GetField<Uint16>(n).Clear();
    }
};

typedef Array<CIM_Processor_Class> CIM_Processor_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_Processor_h */
