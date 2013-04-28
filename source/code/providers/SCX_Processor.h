/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_Processor_h
#define _SCX_Processor_h

#include <MI.h>
#include "CIM_Processor.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_Processor [SCX_Processor]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _SCX_Processor /* extends CIM_Processor */
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
    /* SCX_Processor properties */
}
SCX_Processor;

typedef struct _SCX_Processor_Ref
{
    SCX_Processor* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Processor_Ref;

typedef struct _SCX_Processor_ConstRef
{
    MI_CONST SCX_Processor* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Processor_ConstRef;

typedef struct _SCX_Processor_Array
{
    struct _SCX_Processor** data;
    MI_Uint32 size;
}
SCX_Processor_Array;

typedef struct _SCX_Processor_ConstArray
{
    struct _SCX_Processor MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_Processor_ConstArray;

typedef struct _SCX_Processor_ArrayRef
{
    SCX_Processor_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Processor_ArrayRef;

typedef struct _SCX_Processor_ConstArrayRef
{
    SCX_Processor_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Processor_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_Processor_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_Construct(
    SCX_Processor* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_Processor_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clone(
    const SCX_Processor* self,
    SCX_Processor** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_Processor_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_Processor_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Destruct(SCX_Processor* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Delete(SCX_Processor* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Post(
    const SCX_Processor* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_InstanceID(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_InstanceID(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_InstanceID(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Caption(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_Caption(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Caption(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Description(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_Description(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Description(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_ElementName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_ElementName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_ElementName(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_InstallDate(
    SCX_Processor* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_InstallDate(
    SCX_Processor* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Name(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_Name(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Name(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_OperationalStatus(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_OperationalStatus(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_OperationalStatus(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_StatusDescriptions(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_StatusDescriptions(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_StatusDescriptions(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Status(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_Status(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Status(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_HealthState(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_HealthState(
    SCX_Processor* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_CommunicationStatus(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_CommunicationStatus(
    SCX_Processor* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_DetailedStatus(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_DetailedStatus(
    SCX_Processor* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_OperatingStatus(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_OperatingStatus(
    SCX_Processor* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_PrimaryStatus(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_PrimaryStatus(
    SCX_Processor* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_EnabledState(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_EnabledState(
    SCX_Processor* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_OtherEnabledState(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_OtherEnabledState(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_OtherEnabledState(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_RequestedState(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_RequestedState(
    SCX_Processor* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_EnabledDefault(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_EnabledDefault(
    SCX_Processor* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_TimeOfLastStateChange(
    SCX_Processor* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_TimeOfLastStateChange(
    SCX_Processor* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_AvailableRequestedStates(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_AvailableRequestedStates(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_AvailableRequestedStates(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_TransitioningToState(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_TransitioningToState(
    SCX_Processor* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_SystemCreationClassName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_SystemCreationClassName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_SystemCreationClassName(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_SystemName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_SystemName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_SystemName(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_CreationClassName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_CreationClassName(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_CreationClassName(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_DeviceID(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_DeviceID(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_DeviceID(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_PowerManagementSupported(
    SCX_Processor* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_PowerManagementSupported(
    SCX_Processor* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_PowerManagementCapabilities(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_PowerManagementCapabilities(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_PowerManagementCapabilities(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Availability(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Availability(
    SCX_Processor* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_StatusInfo(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_StatusInfo(
    SCX_Processor* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_LastErrorCode(
    SCX_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_LastErrorCode(
    SCX_Processor* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_ErrorDescription(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_ErrorDescription(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_ErrorDescription(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_ErrorCleared(
    SCX_Processor* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_ErrorCleared(
    SCX_Processor* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_OtherIdentifyingInfo(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_OtherIdentifyingInfo(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_OtherIdentifyingInfo(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_PowerOnHours(
    SCX_Processor* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_PowerOnHours(
    SCX_Processor* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_TotalPowerOnHours(
    SCX_Processor* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_TotalPowerOnHours(
    SCX_Processor* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_IdentifyingDescriptions(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_IdentifyingDescriptions(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_IdentifyingDescriptions(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_AdditionalAvailability(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_AdditionalAvailability(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_AdditionalAvailability(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_MaxQuiesceTime(
    SCX_Processor* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_MaxQuiesceTime(
    SCX_Processor* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Role(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_Role(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Role(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Family(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Family)->value = x;
    ((MI_Uint16Field*)&self->Family)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Family(
    SCX_Processor* self)
{
    memset((void*)&self->Family, 0, sizeof(self->Family));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_OtherFamilyDescription(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_OtherFamilyDescription(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_OtherFamilyDescription(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        40);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_UpgradeMethod(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->UpgradeMethod)->value = x;
    ((MI_Uint16Field*)&self->UpgradeMethod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_UpgradeMethod(
    SCX_Processor* self)
{
    memset((void*)&self->UpgradeMethod, 0, sizeof(self->UpgradeMethod));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_MaxClockSpeed(
    SCX_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxClockSpeed)->value = x;
    ((MI_Uint32Field*)&self->MaxClockSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_MaxClockSpeed(
    SCX_Processor* self)
{
    memset((void*)&self->MaxClockSpeed, 0, sizeof(self->MaxClockSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_CurrentClockSpeed(
    SCX_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CurrentClockSpeed)->value = x;
    ((MI_Uint32Field*)&self->CurrentClockSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_CurrentClockSpeed(
    SCX_Processor* self)
{
    memset((void*)&self->CurrentClockSpeed, 0, sizeof(self->CurrentClockSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_DataWidth(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataWidth)->value = x;
    ((MI_Uint16Field*)&self->DataWidth)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_DataWidth(
    SCX_Processor* self)
{
    memset((void*)&self->DataWidth, 0, sizeof(self->DataWidth));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_AddressWidth(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->AddressWidth)->value = x;
    ((MI_Uint16Field*)&self->AddressWidth)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_AddressWidth(
    SCX_Processor* self)
{
    memset((void*)&self->AddressWidth, 0, sizeof(self->AddressWidth));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_LoadPercentage(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->LoadPercentage)->value = x;
    ((MI_Uint16Field*)&self->LoadPercentage)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_LoadPercentage(
    SCX_Processor* self)
{
    memset((void*)&self->LoadPercentage, 0, sizeof(self->LoadPercentage));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Stepping(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_Stepping(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Stepping(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        47);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_UniqueID(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        48,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_UniqueID(
    SCX_Processor* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        48,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_UniqueID(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        48);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_CPUStatus(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CPUStatus)->value = x;
    ((MI_Uint16Field*)&self->CPUStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_CPUStatus(
    SCX_Processor* self)
{
    memset((void*)&self->CPUStatus, 0, sizeof(self->CPUStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_ExternalBusClockSpeed(
    SCX_Processor* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ExternalBusClockSpeed)->value = x;
    ((MI_Uint32Field*)&self->ExternalBusClockSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_ExternalBusClockSpeed(
    SCX_Processor* self)
{
    memset((void*)&self->ExternalBusClockSpeed, 0, sizeof(self->ExternalBusClockSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_Characteristics(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_Characteristics(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_Characteristics(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        51);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_EnabledProcessorCharacteristics(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPtr_EnabledProcessorCharacteristics(
    SCX_Processor* self,
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

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_EnabledProcessorCharacteristics(
    SCX_Processor* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        52);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Set_NumberOfEnabledCores(
    SCX_Processor* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NumberOfEnabledCores)->value = x;
    ((MI_Uint16Field*)&self->NumberOfEnabledCores)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Clear_NumberOfEnabledCores(
    SCX_Processor* self)
{
    memset((void*)&self->NumberOfEnabledCores, 0, sizeof(self->NumberOfEnabledCores));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_Processor_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_Processor_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Construct(
    SCX_Processor_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Clone(
    const SCX_Processor_RequestStateChange* self,
    SCX_Processor_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Destruct(
    SCX_Processor_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Delete(
    SCX_Processor_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Post(
    const SCX_Processor_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Set_MIReturn(
    SCX_Processor_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Clear_MIReturn(
    SCX_Processor_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Set_RequestedState(
    SCX_Processor_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Clear_RequestedState(
    SCX_Processor_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Set_Job(
    SCX_Processor_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_SetPtr_Job(
    SCX_Processor_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Clear_Job(
    SCX_Processor_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Set_TimeoutPeriod(
    SCX_Processor_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RequestStateChange_Clear_TimeoutPeriod(
    SCX_Processor_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.SetPowerState()
**
**==============================================================================
*/

typedef struct _SCX_Processor_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
SCX_Processor_SetPowerState;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_SetPowerState_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Construct(
    SCX_Processor_SetPowerState* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_SetPowerState_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Clone(
    const SCX_Processor_SetPowerState* self,
    SCX_Processor_SetPowerState** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Destruct(
    SCX_Processor_SetPowerState* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Delete(
    SCX_Processor_SetPowerState* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Post(
    const SCX_Processor_SetPowerState* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Set_MIReturn(
    SCX_Processor_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Clear_MIReturn(
    SCX_Processor_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Set_PowerState(
    SCX_Processor_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Clear_PowerState(
    SCX_Processor_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Set_Time(
    SCX_Processor_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SetPowerState_Clear_Time(
    SCX_Processor_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.Reset()
**
**==============================================================================
*/

typedef struct _SCX_Processor_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_Processor_Reset;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_Reset_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_Reset_Construct(
    SCX_Processor_Reset* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_Reset_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Reset_Clone(
    const SCX_Processor_Reset* self,
    SCX_Processor_Reset** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Reset_Destruct(
    SCX_Processor_Reset* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Reset_Delete(
    SCX_Processor_Reset* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Reset_Post(
    const SCX_Processor_Reset* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Reset_Set_MIReturn(
    SCX_Processor_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_Reset_Clear_MIReturn(
    SCX_Processor_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.EnableDevice()
**
**==============================================================================
*/

typedef struct _SCX_Processor_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
SCX_Processor_EnableDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_EnableDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Construct(
    SCX_Processor_EnableDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_EnableDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Clone(
    const SCX_Processor_EnableDevice* self,
    SCX_Processor_EnableDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Destruct(
    SCX_Processor_EnableDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Delete(
    SCX_Processor_EnableDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Post(
    const SCX_Processor_EnableDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Set_MIReturn(
    SCX_Processor_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Clear_MIReturn(
    SCX_Processor_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Set_Enabled(
    SCX_Processor_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_EnableDevice_Clear_Enabled(
    SCX_Processor_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.OnlineDevice()
**
**==============================================================================
*/

typedef struct _SCX_Processor_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
SCX_Processor_OnlineDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_OnlineDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Construct(
    SCX_Processor_OnlineDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_OnlineDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Clone(
    const SCX_Processor_OnlineDevice* self,
    SCX_Processor_OnlineDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Destruct(
    SCX_Processor_OnlineDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Delete(
    SCX_Processor_OnlineDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Post(
    const SCX_Processor_OnlineDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Set_MIReturn(
    SCX_Processor_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Clear_MIReturn(
    SCX_Processor_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Set_Online(
    SCX_Processor_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_OnlineDevice_Clear_Online(
    SCX_Processor_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _SCX_Processor_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
SCX_Processor_QuiesceDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_QuiesceDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Construct(
    SCX_Processor_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_QuiesceDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Clone(
    const SCX_Processor_QuiesceDevice* self,
    SCX_Processor_QuiesceDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Destruct(
    SCX_Processor_QuiesceDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Delete(
    SCX_Processor_QuiesceDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Post(
    const SCX_Processor_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Set_MIReturn(
    SCX_Processor_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Clear_MIReturn(
    SCX_Processor_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Set_Quiesce(
    SCX_Processor_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_QuiesceDevice_Clear_Quiesce(
    SCX_Processor_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.SaveProperties()
**
**==============================================================================
*/

typedef struct _SCX_Processor_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_Processor_SaveProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_SaveProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_SaveProperties_Construct(
    SCX_Processor_SaveProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_SaveProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SaveProperties_Clone(
    const SCX_Processor_SaveProperties* self,
    SCX_Processor_SaveProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SaveProperties_Destruct(
    SCX_Processor_SaveProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SaveProperties_Delete(
    SCX_Processor_SaveProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SaveProperties_Post(
    const SCX_Processor_SaveProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SaveProperties_Set_MIReturn(
    SCX_Processor_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_SaveProperties_Clear_MIReturn(
    SCX_Processor_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor.RestoreProperties()
**
**==============================================================================
*/

typedef struct _SCX_Processor_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_Processor_RestoreProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Processor_RestoreProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_Processor_RestoreProperties_Construct(
    SCX_Processor_RestoreProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Processor_RestoreProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RestoreProperties_Clone(
    const SCX_Processor_RestoreProperties* self,
    SCX_Processor_RestoreProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RestoreProperties_Destruct(
    SCX_Processor_RestoreProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RestoreProperties_Delete(
    SCX_Processor_RestoreProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RestoreProperties_Post(
    const SCX_Processor_RestoreProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RestoreProperties_Set_MIReturn(
    SCX_Processor_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Processor_RestoreProperties_Clear_MIReturn(
    SCX_Processor_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Processor provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_Processor_Self SCX_Processor_Self;

MI_EXTERN_C void MI_CALL SCX_Processor_Load(
    SCX_Processor_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Processor_Unload(
    SCX_Processor_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Processor_EnumerateInstances(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_Processor_GetInstance(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Processor* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Processor_CreateInstance(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Processor* newInstance);

MI_EXTERN_C void MI_CALL SCX_Processor_ModifyInstance(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Processor* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Processor_DeleteInstance(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Processor* instanceName);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_RequestStateChange(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_RequestStateChange* in);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_SetPowerState(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_SetPowerState* in);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_Reset(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_Reset* in);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_EnableDevice(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_EnableDevice* in);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_OnlineDevice(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_OnlineDevice* in);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_QuiesceDevice(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_QuiesceDevice* in);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_SaveProperties(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_SaveProperties* in);

MI_EXTERN_C void MI_CALL SCX_Processor_Invoke_RestoreProperties(
    SCX_Processor_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Processor* instanceName,
    const SCX_Processor_RestoreProperties* in);


/*
**==============================================================================
**
** SCX_Processor_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_Processor_Class : public CIM_Processor_Class
{
public:
    
    typedef SCX_Processor Self;
    
    SCX_Processor_Class() :
        CIM_Processor_Class(&SCX_Processor_rtti)
    {
    }
    
    SCX_Processor_Class(
        const SCX_Processor* instanceName,
        bool keysOnly) :
        CIM_Processor_Class(
            &SCX_Processor_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_Processor_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_Class(
        const MI_ClassDecl* clDecl) :
        CIM_Processor_Class(clDecl)
    {
    }
    
    SCX_Processor_Class& operator=(
        const SCX_Processor_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_Class(
        const SCX_Processor_Class& x) :
        CIM_Processor_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_Processor_rtti;
    }

};

typedef Array<SCX_Processor_Class> SCX_Processor_ClassA;

class SCX_Processor_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_Processor_RequestStateChange Self;
    
    SCX_Processor_RequestStateChange_Class() :
        Instance(&SCX_Processor_RequestStateChange_rtti)
    {
    }
    
    SCX_Processor_RequestStateChange_Class(
        const SCX_Processor_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_RequestStateChange_Class& operator=(
        const SCX_Processor_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_RequestStateChange_Class(
        const SCX_Processor_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_RequestStateChange_Class.MIReturn
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
    // SCX_Processor_RequestStateChange_Class.RequestedState
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
    // SCX_Processor_RequestStateChange_Class.Job
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
    // SCX_Processor_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<SCX_Processor_RequestStateChange_Class> SCX_Processor_RequestStateChange_ClassA;

class SCX_Processor_SetPowerState_Class : public Instance
{
public:
    
    typedef SCX_Processor_SetPowerState Self;
    
    SCX_Processor_SetPowerState_Class() :
        Instance(&SCX_Processor_SetPowerState_rtti)
    {
    }
    
    SCX_Processor_SetPowerState_Class(
        const SCX_Processor_SetPowerState* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_SetPowerState_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_SetPowerState_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_SetPowerState_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_SetPowerState_Class& operator=(
        const SCX_Processor_SetPowerState_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_SetPowerState_Class(
        const SCX_Processor_SetPowerState_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_SetPowerState_Class.MIReturn
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
    // SCX_Processor_SetPowerState_Class.PowerState
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
    // SCX_Processor_SetPowerState_Class.Time
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

typedef Array<SCX_Processor_SetPowerState_Class> SCX_Processor_SetPowerState_ClassA;

class SCX_Processor_Reset_Class : public Instance
{
public:
    
    typedef SCX_Processor_Reset Self;
    
    SCX_Processor_Reset_Class() :
        Instance(&SCX_Processor_Reset_rtti)
    {
    }
    
    SCX_Processor_Reset_Class(
        const SCX_Processor_Reset* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_Reset_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_Reset_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_Reset_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_Reset_Class& operator=(
        const SCX_Processor_Reset_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_Reset_Class(
        const SCX_Processor_Reset_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_Reset_Class.MIReturn
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

typedef Array<SCX_Processor_Reset_Class> SCX_Processor_Reset_ClassA;

class SCX_Processor_EnableDevice_Class : public Instance
{
public:
    
    typedef SCX_Processor_EnableDevice Self;
    
    SCX_Processor_EnableDevice_Class() :
        Instance(&SCX_Processor_EnableDevice_rtti)
    {
    }
    
    SCX_Processor_EnableDevice_Class(
        const SCX_Processor_EnableDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_EnableDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_EnableDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_EnableDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_EnableDevice_Class& operator=(
        const SCX_Processor_EnableDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_EnableDevice_Class(
        const SCX_Processor_EnableDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_EnableDevice_Class.MIReturn
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
    // SCX_Processor_EnableDevice_Class.Enabled
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

typedef Array<SCX_Processor_EnableDevice_Class> SCX_Processor_EnableDevice_ClassA;

class SCX_Processor_OnlineDevice_Class : public Instance
{
public:
    
    typedef SCX_Processor_OnlineDevice Self;
    
    SCX_Processor_OnlineDevice_Class() :
        Instance(&SCX_Processor_OnlineDevice_rtti)
    {
    }
    
    SCX_Processor_OnlineDevice_Class(
        const SCX_Processor_OnlineDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_OnlineDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_OnlineDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_OnlineDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_OnlineDevice_Class& operator=(
        const SCX_Processor_OnlineDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_OnlineDevice_Class(
        const SCX_Processor_OnlineDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_OnlineDevice_Class.MIReturn
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
    // SCX_Processor_OnlineDevice_Class.Online
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

typedef Array<SCX_Processor_OnlineDevice_Class> SCX_Processor_OnlineDevice_ClassA;

class SCX_Processor_QuiesceDevice_Class : public Instance
{
public:
    
    typedef SCX_Processor_QuiesceDevice Self;
    
    SCX_Processor_QuiesceDevice_Class() :
        Instance(&SCX_Processor_QuiesceDevice_rtti)
    {
    }
    
    SCX_Processor_QuiesceDevice_Class(
        const SCX_Processor_QuiesceDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_QuiesceDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_QuiesceDevice_Class& operator=(
        const SCX_Processor_QuiesceDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_QuiesceDevice_Class(
        const SCX_Processor_QuiesceDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_QuiesceDevice_Class.MIReturn
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
    // SCX_Processor_QuiesceDevice_Class.Quiesce
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

typedef Array<SCX_Processor_QuiesceDevice_Class> SCX_Processor_QuiesceDevice_ClassA;

class SCX_Processor_SaveProperties_Class : public Instance
{
public:
    
    typedef SCX_Processor_SaveProperties Self;
    
    SCX_Processor_SaveProperties_Class() :
        Instance(&SCX_Processor_SaveProperties_rtti)
    {
    }
    
    SCX_Processor_SaveProperties_Class(
        const SCX_Processor_SaveProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_SaveProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_SaveProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_SaveProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_SaveProperties_Class& operator=(
        const SCX_Processor_SaveProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_SaveProperties_Class(
        const SCX_Processor_SaveProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_SaveProperties_Class.MIReturn
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

typedef Array<SCX_Processor_SaveProperties_Class> SCX_Processor_SaveProperties_ClassA;

class SCX_Processor_RestoreProperties_Class : public Instance
{
public:
    
    typedef SCX_Processor_RestoreProperties Self;
    
    SCX_Processor_RestoreProperties_Class() :
        Instance(&SCX_Processor_RestoreProperties_rtti)
    {
    }
    
    SCX_Processor_RestoreProperties_Class(
        const SCX_Processor_RestoreProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Processor_RestoreProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Processor_RestoreProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Processor_RestoreProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Processor_RestoreProperties_Class& operator=(
        const SCX_Processor_RestoreProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Processor_RestoreProperties_Class(
        const SCX_Processor_RestoreProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Processor_RestoreProperties_Class.MIReturn
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

typedef Array<SCX_Processor_RestoreProperties_Class> SCX_Processor_RestoreProperties_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_Processor_h */
