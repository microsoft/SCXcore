/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_EthernetPort_h
#define _SCX_EthernetPort_h

#include <MI.h>
#include "CIM_EthernetPort.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_EthernetPort [SCX_EthernetPort]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort /* extends CIM_EthernetPort */
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
    /* CIM_NetworkPort properties */
    MI_ConstStringField OtherNetworkPortType;
    MI_ConstUint16Field PortNumber;
    MI_ConstUint16Field LinkTechnology;
    MI_ConstStringField OtherLinkTechnology;
    MI_ConstStringField PermanentAddress;
    MI_ConstStringAField NetworkAddresses;
    MI_ConstBooleanField FullDuplex;
    MI_ConstBooleanField AutoSense;
    MI_ConstUint64Field SupportedMaximumTransmissionUnit;
    MI_ConstUint64Field ActiveMaximumTransmissionUnit;
    /* CIM_EthernetPort properties */
    MI_ConstUint32Field MaxDataSize;
    MI_ConstUint16AField Capabilities;
    MI_ConstStringAField CapabilityDescriptions;
    MI_ConstUint16AField EnabledCapabilities;
    MI_ConstStringAField OtherEnabledCapabilities;
    /* SCX_EthernetPort properties */
}
SCX_EthernetPort;

typedef struct _SCX_EthernetPort_Ref
{
    SCX_EthernetPort* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPort_Ref;

typedef struct _SCX_EthernetPort_ConstRef
{
    MI_CONST SCX_EthernetPort* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPort_ConstRef;

typedef struct _SCX_EthernetPort_Array
{
    struct _SCX_EthernetPort** data;
    MI_Uint32 size;
}
SCX_EthernetPort_Array;

typedef struct _SCX_EthernetPort_ConstArray
{
    struct _SCX_EthernetPort MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_EthernetPort_ConstArray;

typedef struct _SCX_EthernetPort_ArrayRef
{
    SCX_EthernetPort_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPort_ArrayRef;

typedef struct _SCX_EthernetPort_ConstArrayRef
{
    SCX_EthernetPort_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPort_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_EthernetPort_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Construct(
    SCX_EthernetPort* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_EthernetPort_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clone(
    const SCX_EthernetPort* self,
    SCX_EthernetPort** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_EthernetPort_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_EthernetPort_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Destruct(SCX_EthernetPort* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Delete(SCX_EthernetPort* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Post(
    const SCX_EthernetPort* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_InstanceID(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_InstanceID(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_InstanceID(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_Caption(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_Caption(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_Caption(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_Description(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_Description(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_Description(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_ElementName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_ElementName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_ElementName(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_InstallDate(
    SCX_EthernetPort* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_InstallDate(
    SCX_EthernetPort* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_Name(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_Name(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_Name(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OperationalStatus(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_OperationalStatus(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OperationalStatus(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_StatusDescriptions(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_StatusDescriptions(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_StatusDescriptions(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_Status(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_Status(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_Status(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_HealthState(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_HealthState(
    SCX_EthernetPort* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_CommunicationStatus(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_CommunicationStatus(
    SCX_EthernetPort* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_DetailedStatus(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_DetailedStatus(
    SCX_EthernetPort* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OperatingStatus(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OperatingStatus(
    SCX_EthernetPort* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_PrimaryStatus(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_PrimaryStatus(
    SCX_EthernetPort* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_EnabledState(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_EnabledState(
    SCX_EthernetPort* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OtherEnabledState(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_OtherEnabledState(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OtherEnabledState(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_RequestedState(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_RequestedState(
    SCX_EthernetPort* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_EnabledDefault(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_EnabledDefault(
    SCX_EthernetPort* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_TimeOfLastStateChange(
    SCX_EthernetPort* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_TimeOfLastStateChange(
    SCX_EthernetPort* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_AvailableRequestedStates(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_AvailableRequestedStates(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_AvailableRequestedStates(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_TransitioningToState(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_TransitioningToState(
    SCX_EthernetPort* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_SystemCreationClassName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_SystemCreationClassName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_SystemCreationClassName(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_SystemName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_SystemName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_SystemName(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_CreationClassName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_CreationClassName(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_CreationClassName(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_DeviceID(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_DeviceID(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_DeviceID(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_PowerManagementSupported(
    SCX_EthernetPort* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_PowerManagementSupported(
    SCX_EthernetPort* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_PowerManagementCapabilities(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_PowerManagementCapabilities(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_PowerManagementCapabilities(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_Availability(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_Availability(
    SCX_EthernetPort* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_StatusInfo(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_StatusInfo(
    SCX_EthernetPort* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_LastErrorCode(
    SCX_EthernetPort* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_LastErrorCode(
    SCX_EthernetPort* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_ErrorDescription(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_ErrorDescription(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_ErrorDescription(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_ErrorCleared(
    SCX_EthernetPort* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_ErrorCleared(
    SCX_EthernetPort* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OtherIdentifyingInfo(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_OtherIdentifyingInfo(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OtherIdentifyingInfo(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_PowerOnHours(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_PowerOnHours(
    SCX_EthernetPort* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_TotalPowerOnHours(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_TotalPowerOnHours(
    SCX_EthernetPort* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_IdentifyingDescriptions(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_IdentifyingDescriptions(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_IdentifyingDescriptions(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_AdditionalAvailability(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_AdditionalAvailability(
    SCX_EthernetPort* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_AdditionalAvailability(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_MaxQuiesceTime(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_MaxQuiesceTime(
    SCX_EthernetPort* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_Speed(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->Speed)->value = x;
    ((MI_Uint64Field*)&self->Speed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_Speed(
    SCX_EthernetPort* self)
{
    memset((void*)&self->Speed, 0, sizeof(self->Speed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_MaxSpeed(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxSpeed)->value = x;
    ((MI_Uint64Field*)&self->MaxSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_MaxSpeed(
    SCX_EthernetPort* self)
{
    memset((void*)&self->MaxSpeed, 0, sizeof(self->MaxSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_RequestedSpeed(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RequestedSpeed)->value = x;
    ((MI_Uint64Field*)&self->RequestedSpeed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_RequestedSpeed(
    SCX_EthernetPort* self)
{
    memset((void*)&self->RequestedSpeed, 0, sizeof(self->RequestedSpeed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_UsageRestriction(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->UsageRestriction)->value = x;
    ((MI_Uint16Field*)&self->UsageRestriction)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_UsageRestriction(
    SCX_EthernetPort* self)
{
    memset((void*)&self->UsageRestriction, 0, sizeof(self->UsageRestriction));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_PortType(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PortType)->value = x;
    ((MI_Uint16Field*)&self->PortType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_PortType(
    SCX_EthernetPort* self)
{
    memset((void*)&self->PortType, 0, sizeof(self->PortType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OtherPortType(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_OtherPortType(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        43,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OtherPortType(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        43);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OtherNetworkPortType(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        44,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_OtherNetworkPortType(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        44,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OtherNetworkPortType(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        44);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_PortNumber(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PortNumber)->value = x;
    ((MI_Uint16Field*)&self->PortNumber)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_PortNumber(
    SCX_EthernetPort* self)
{
    memset((void*)&self->PortNumber, 0, sizeof(self->PortNumber));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_LinkTechnology(
    SCX_EthernetPort* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->LinkTechnology)->value = x;
    ((MI_Uint16Field*)&self->LinkTechnology)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_LinkTechnology(
    SCX_EthernetPort* self)
{
    memset((void*)&self->LinkTechnology, 0, sizeof(self->LinkTechnology));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OtherLinkTechnology(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_OtherLinkTechnology(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OtherLinkTechnology(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        47);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_PermanentAddress(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        48,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_PermanentAddress(
    SCX_EthernetPort* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        48,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_PermanentAddress(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        48);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_NetworkAddresses(
    SCX_EthernetPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        49,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_NetworkAddresses(
    SCX_EthernetPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        49,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_NetworkAddresses(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        49);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_FullDuplex(
    SCX_EthernetPort* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->FullDuplex)->value = x;
    ((MI_BooleanField*)&self->FullDuplex)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_FullDuplex(
    SCX_EthernetPort* self)
{
    memset((void*)&self->FullDuplex, 0, sizeof(self->FullDuplex));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_AutoSense(
    SCX_EthernetPort* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->AutoSense)->value = x;
    ((MI_BooleanField*)&self->AutoSense)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_AutoSense(
    SCX_EthernetPort* self)
{
    memset((void*)&self->AutoSense, 0, sizeof(self->AutoSense));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_SupportedMaximumTransmissionUnit(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->SupportedMaximumTransmissionUnit)->value = x;
    ((MI_Uint64Field*)&self->SupportedMaximumTransmissionUnit)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_SupportedMaximumTransmissionUnit(
    SCX_EthernetPort* self)
{
    memset((void*)&self->SupportedMaximumTransmissionUnit, 0, sizeof(self->SupportedMaximumTransmissionUnit));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_ActiveMaximumTransmissionUnit(
    SCX_EthernetPort* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ActiveMaximumTransmissionUnit)->value = x;
    ((MI_Uint64Field*)&self->ActiveMaximumTransmissionUnit)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_ActiveMaximumTransmissionUnit(
    SCX_EthernetPort* self)
{
    memset((void*)&self->ActiveMaximumTransmissionUnit, 0, sizeof(self->ActiveMaximumTransmissionUnit));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_MaxDataSize(
    SCX_EthernetPort* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxDataSize)->value = x;
    ((MI_Uint32Field*)&self->MaxDataSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_MaxDataSize(
    SCX_EthernetPort* self)
{
    memset((void*)&self->MaxDataSize, 0, sizeof(self->MaxDataSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_Capabilities(
    SCX_EthernetPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_Capabilities(
    SCX_EthernetPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_Capabilities(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        55);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_CapabilityDescriptions(
    SCX_EthernetPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_CapabilityDescriptions(
    SCX_EthernetPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_CapabilityDescriptions(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        56);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_EnabledCapabilities(
    SCX_EthernetPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        57,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_EnabledCapabilities(
    SCX_EthernetPort* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        57,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_EnabledCapabilities(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        57);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Set_OtherEnabledCapabilities(
    SCX_EthernetPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPtr_OtherEnabledCapabilities(
    SCX_EthernetPort* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Clear_OtherEnabledCapabilities(
    SCX_EthernetPort* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        58);
}

/*
**==============================================================================
**
** SCX_EthernetPort.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_EthernetPort_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Construct(
    SCX_EthernetPort_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Clone(
    const SCX_EthernetPort_RequestStateChange* self,
    SCX_EthernetPort_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Destruct(
    SCX_EthernetPort_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Delete(
    SCX_EthernetPort_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Post(
    const SCX_EthernetPort_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Set_MIReturn(
    SCX_EthernetPort_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Clear_MIReturn(
    SCX_EthernetPort_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Set_RequestedState(
    SCX_EthernetPort_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Clear_RequestedState(
    SCX_EthernetPort_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Set_Job(
    SCX_EthernetPort_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_SetPtr_Job(
    SCX_EthernetPort_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Clear_Job(
    SCX_EthernetPort_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Set_TimeoutPeriod(
    SCX_EthernetPort_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RequestStateChange_Clear_TimeoutPeriod(
    SCX_EthernetPort_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort.SetPowerState()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
SCX_EthernetPort_SetPowerState;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_SetPowerState_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Construct(
    SCX_EthernetPort_SetPowerState* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_SetPowerState_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Clone(
    const SCX_EthernetPort_SetPowerState* self,
    SCX_EthernetPort_SetPowerState** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Destruct(
    SCX_EthernetPort_SetPowerState* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Delete(
    SCX_EthernetPort_SetPowerState* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Post(
    const SCX_EthernetPort_SetPowerState* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Set_MIReturn(
    SCX_EthernetPort_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Clear_MIReturn(
    SCX_EthernetPort_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Set_PowerState(
    SCX_EthernetPort_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Clear_PowerState(
    SCX_EthernetPort_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Set_Time(
    SCX_EthernetPort_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SetPowerState_Clear_Time(
    SCX_EthernetPort_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort.Reset()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_EthernetPort_Reset;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_Reset_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Reset_Construct(
    SCX_EthernetPort_Reset* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_Reset_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Reset_Clone(
    const SCX_EthernetPort_Reset* self,
    SCX_EthernetPort_Reset** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Reset_Destruct(
    SCX_EthernetPort_Reset* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Reset_Delete(
    SCX_EthernetPort_Reset* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Reset_Post(
    const SCX_EthernetPort_Reset* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Reset_Set_MIReturn(
    SCX_EthernetPort_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_Reset_Clear_MIReturn(
    SCX_EthernetPort_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort.EnableDevice()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
SCX_EthernetPort_EnableDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_EnableDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Construct(
    SCX_EthernetPort_EnableDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_EnableDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Clone(
    const SCX_EthernetPort_EnableDevice* self,
    SCX_EthernetPort_EnableDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Destruct(
    SCX_EthernetPort_EnableDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Delete(
    SCX_EthernetPort_EnableDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Post(
    const SCX_EthernetPort_EnableDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Set_MIReturn(
    SCX_EthernetPort_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Clear_MIReturn(
    SCX_EthernetPort_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Set_Enabled(
    SCX_EthernetPort_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_EnableDevice_Clear_Enabled(
    SCX_EthernetPort_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort.OnlineDevice()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
SCX_EthernetPort_OnlineDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_OnlineDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Construct(
    SCX_EthernetPort_OnlineDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_OnlineDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Clone(
    const SCX_EthernetPort_OnlineDevice* self,
    SCX_EthernetPort_OnlineDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Destruct(
    SCX_EthernetPort_OnlineDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Delete(
    SCX_EthernetPort_OnlineDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Post(
    const SCX_EthernetPort_OnlineDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Set_MIReturn(
    SCX_EthernetPort_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Clear_MIReturn(
    SCX_EthernetPort_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Set_Online(
    SCX_EthernetPort_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_OnlineDevice_Clear_Online(
    SCX_EthernetPort_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
SCX_EthernetPort_QuiesceDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_QuiesceDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Construct(
    SCX_EthernetPort_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_QuiesceDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Clone(
    const SCX_EthernetPort_QuiesceDevice* self,
    SCX_EthernetPort_QuiesceDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Destruct(
    SCX_EthernetPort_QuiesceDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Delete(
    SCX_EthernetPort_QuiesceDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Post(
    const SCX_EthernetPort_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Set_MIReturn(
    SCX_EthernetPort_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Clear_MIReturn(
    SCX_EthernetPort_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Set_Quiesce(
    SCX_EthernetPort_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_QuiesceDevice_Clear_Quiesce(
    SCX_EthernetPort_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort.SaveProperties()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_EthernetPort_SaveProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_SaveProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SaveProperties_Construct(
    SCX_EthernetPort_SaveProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_SaveProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SaveProperties_Clone(
    const SCX_EthernetPort_SaveProperties* self,
    SCX_EthernetPort_SaveProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SaveProperties_Destruct(
    SCX_EthernetPort_SaveProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SaveProperties_Delete(
    SCX_EthernetPort_SaveProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SaveProperties_Post(
    const SCX_EthernetPort_SaveProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SaveProperties_Set_MIReturn(
    SCX_EthernetPort_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_SaveProperties_Clear_MIReturn(
    SCX_EthernetPort_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort.RestoreProperties()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPort_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_EthernetPort_RestoreProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPort_RestoreProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RestoreProperties_Construct(
    SCX_EthernetPort_RestoreProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPort_RestoreProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RestoreProperties_Clone(
    const SCX_EthernetPort_RestoreProperties* self,
    SCX_EthernetPort_RestoreProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RestoreProperties_Destruct(
    SCX_EthernetPort_RestoreProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RestoreProperties_Delete(
    SCX_EthernetPort_RestoreProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RestoreProperties_Post(
    const SCX_EthernetPort_RestoreProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RestoreProperties_Set_MIReturn(
    SCX_EthernetPort_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPort_RestoreProperties_Clear_MIReturn(
    SCX_EthernetPort_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPort provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_EthernetPort_Self SCX_EthernetPort_Self;

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Load(
    SCX_EthernetPort_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Unload(
    SCX_EthernetPort_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_EnumerateInstances(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_GetInstance(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPort* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_CreateInstance(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPort* newInstance);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_ModifyInstance(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPort* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_DeleteInstance(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPort* instanceName);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_RequestStateChange(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_RequestStateChange* in);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_SetPowerState(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_SetPowerState* in);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_Reset(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_Reset* in);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_EnableDevice(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_EnableDevice* in);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_OnlineDevice(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_OnlineDevice* in);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_QuiesceDevice(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_QuiesceDevice* in);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_SaveProperties(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_SaveProperties* in);

MI_EXTERN_C void MI_CALL SCX_EthernetPort_Invoke_RestoreProperties(
    SCX_EthernetPort_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPort* instanceName,
    const SCX_EthernetPort_RestoreProperties* in);


/*
**==============================================================================
**
** SCX_EthernetPort_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_EthernetPort_Class : public CIM_EthernetPort_Class
{
public:
    
    typedef SCX_EthernetPort Self;
    
    SCX_EthernetPort_Class() :
        CIM_EthernetPort_Class(&SCX_EthernetPort_rtti)
    {
    }
    
    SCX_EthernetPort_Class(
        const SCX_EthernetPort* instanceName,
        bool keysOnly) :
        CIM_EthernetPort_Class(
            &SCX_EthernetPort_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_EthernetPort_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_Class(
        const MI_ClassDecl* clDecl) :
        CIM_EthernetPort_Class(clDecl)
    {
    }
    
    SCX_EthernetPort_Class& operator=(
        const SCX_EthernetPort_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_Class(
        const SCX_EthernetPort_Class& x) :
        CIM_EthernetPort_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_EthernetPort_rtti;
    }

};

typedef Array<SCX_EthernetPort_Class> SCX_EthernetPort_ClassA;

class SCX_EthernetPort_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_RequestStateChange Self;
    
    SCX_EthernetPort_RequestStateChange_Class() :
        Instance(&SCX_EthernetPort_RequestStateChange_rtti)
    {
    }
    
    SCX_EthernetPort_RequestStateChange_Class(
        const SCX_EthernetPort_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_RequestStateChange_Class& operator=(
        const SCX_EthernetPort_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_RequestStateChange_Class(
        const SCX_EthernetPort_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_RequestStateChange_Class.MIReturn
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
    // SCX_EthernetPort_RequestStateChange_Class.RequestedState
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
    // SCX_EthernetPort_RequestStateChange_Class.Job
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
    // SCX_EthernetPort_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<SCX_EthernetPort_RequestStateChange_Class> SCX_EthernetPort_RequestStateChange_ClassA;

class SCX_EthernetPort_SetPowerState_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_SetPowerState Self;
    
    SCX_EthernetPort_SetPowerState_Class() :
        Instance(&SCX_EthernetPort_SetPowerState_rtti)
    {
    }
    
    SCX_EthernetPort_SetPowerState_Class(
        const SCX_EthernetPort_SetPowerState* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_SetPowerState_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_SetPowerState_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_SetPowerState_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_SetPowerState_Class& operator=(
        const SCX_EthernetPort_SetPowerState_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_SetPowerState_Class(
        const SCX_EthernetPort_SetPowerState_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_SetPowerState_Class.MIReturn
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
    // SCX_EthernetPort_SetPowerState_Class.PowerState
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
    // SCX_EthernetPort_SetPowerState_Class.Time
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

typedef Array<SCX_EthernetPort_SetPowerState_Class> SCX_EthernetPort_SetPowerState_ClassA;

class SCX_EthernetPort_Reset_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_Reset Self;
    
    SCX_EthernetPort_Reset_Class() :
        Instance(&SCX_EthernetPort_Reset_rtti)
    {
    }
    
    SCX_EthernetPort_Reset_Class(
        const SCX_EthernetPort_Reset* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_Reset_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_Reset_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_Reset_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_Reset_Class& operator=(
        const SCX_EthernetPort_Reset_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_Reset_Class(
        const SCX_EthernetPort_Reset_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_Reset_Class.MIReturn
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

typedef Array<SCX_EthernetPort_Reset_Class> SCX_EthernetPort_Reset_ClassA;

class SCX_EthernetPort_EnableDevice_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_EnableDevice Self;
    
    SCX_EthernetPort_EnableDevice_Class() :
        Instance(&SCX_EthernetPort_EnableDevice_rtti)
    {
    }
    
    SCX_EthernetPort_EnableDevice_Class(
        const SCX_EthernetPort_EnableDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_EnableDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_EnableDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_EnableDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_EnableDevice_Class& operator=(
        const SCX_EthernetPort_EnableDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_EnableDevice_Class(
        const SCX_EthernetPort_EnableDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_EnableDevice_Class.MIReturn
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
    // SCX_EthernetPort_EnableDevice_Class.Enabled
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

typedef Array<SCX_EthernetPort_EnableDevice_Class> SCX_EthernetPort_EnableDevice_ClassA;

class SCX_EthernetPort_OnlineDevice_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_OnlineDevice Self;
    
    SCX_EthernetPort_OnlineDevice_Class() :
        Instance(&SCX_EthernetPort_OnlineDevice_rtti)
    {
    }
    
    SCX_EthernetPort_OnlineDevice_Class(
        const SCX_EthernetPort_OnlineDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_OnlineDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_OnlineDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_OnlineDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_OnlineDevice_Class& operator=(
        const SCX_EthernetPort_OnlineDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_OnlineDevice_Class(
        const SCX_EthernetPort_OnlineDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_OnlineDevice_Class.MIReturn
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
    // SCX_EthernetPort_OnlineDevice_Class.Online
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

typedef Array<SCX_EthernetPort_OnlineDevice_Class> SCX_EthernetPort_OnlineDevice_ClassA;

class SCX_EthernetPort_QuiesceDevice_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_QuiesceDevice Self;
    
    SCX_EthernetPort_QuiesceDevice_Class() :
        Instance(&SCX_EthernetPort_QuiesceDevice_rtti)
    {
    }
    
    SCX_EthernetPort_QuiesceDevice_Class(
        const SCX_EthernetPort_QuiesceDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_QuiesceDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_QuiesceDevice_Class& operator=(
        const SCX_EthernetPort_QuiesceDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_QuiesceDevice_Class(
        const SCX_EthernetPort_QuiesceDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_QuiesceDevice_Class.MIReturn
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
    // SCX_EthernetPort_QuiesceDevice_Class.Quiesce
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

typedef Array<SCX_EthernetPort_QuiesceDevice_Class> SCX_EthernetPort_QuiesceDevice_ClassA;

class SCX_EthernetPort_SaveProperties_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_SaveProperties Self;
    
    SCX_EthernetPort_SaveProperties_Class() :
        Instance(&SCX_EthernetPort_SaveProperties_rtti)
    {
    }
    
    SCX_EthernetPort_SaveProperties_Class(
        const SCX_EthernetPort_SaveProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_SaveProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_SaveProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_SaveProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_SaveProperties_Class& operator=(
        const SCX_EthernetPort_SaveProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_SaveProperties_Class(
        const SCX_EthernetPort_SaveProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_SaveProperties_Class.MIReturn
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

typedef Array<SCX_EthernetPort_SaveProperties_Class> SCX_EthernetPort_SaveProperties_ClassA;

class SCX_EthernetPort_RestoreProperties_Class : public Instance
{
public:
    
    typedef SCX_EthernetPort_RestoreProperties Self;
    
    SCX_EthernetPort_RestoreProperties_Class() :
        Instance(&SCX_EthernetPort_RestoreProperties_rtti)
    {
    }
    
    SCX_EthernetPort_RestoreProperties_Class(
        const SCX_EthernetPort_RestoreProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPort_RestoreProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPort_RestoreProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPort_RestoreProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPort_RestoreProperties_Class& operator=(
        const SCX_EthernetPort_RestoreProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPort_RestoreProperties_Class(
        const SCX_EthernetPort_RestoreProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPort_RestoreProperties_Class.MIReturn
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

typedef Array<SCX_EthernetPort_RestoreProperties_Class> SCX_EthernetPort_RestoreProperties_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_EthernetPort_h */
