/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_IPProtocolEndpoint_h
#define _SCX_IPProtocolEndpoint_h

#include <MI.h>
#include "CIM_IPProtocolEndpoint.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_IPProtocolEndpoint [SCX_IPProtocolEndpoint]
**
** Keys:
**    Name
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _SCX_IPProtocolEndpoint /* extends CIM_IPProtocolEndpoint */
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
    /* CIM_ServiceAccessPoint properties */
    /*KEY*/ MI_ConstStringField SystemCreationClassName;
    /*KEY*/ MI_ConstStringField SystemName;
    /*KEY*/ MI_ConstStringField CreationClassName;
    /* CIM_ProtocolEndpoint properties */
    MI_ConstStringField NameFormat;
    MI_ConstUint16Field ProtocolType;
    MI_ConstUint16Field ProtocolIFType;
    MI_ConstStringField OtherTypeDescription;
    /* CIM_IPProtocolEndpoint properties */
    MI_ConstStringField IPv4Address;
    MI_ConstStringField IPv6Address;
    MI_ConstStringField Address;
    MI_ConstStringField SubnetMask;
    MI_ConstUint8Field PrefixLength;
    MI_ConstUint16Field AddressType;
    MI_ConstUint16Field IPVersionSupport;
    MI_ConstUint16Field AddressOrigin;
    MI_ConstUint16Field IPv6AddressType;
    MI_ConstUint16Field IPv6SubnetPrefixLength;
    /* SCX_IPProtocolEndpoint properties */
    MI_ConstStringField IPv4BroadcastAddress;
}
SCX_IPProtocolEndpoint;

typedef struct _SCX_IPProtocolEndpoint_Ref
{
    SCX_IPProtocolEndpoint* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_IPProtocolEndpoint_Ref;

typedef struct _SCX_IPProtocolEndpoint_ConstRef
{
    MI_CONST SCX_IPProtocolEndpoint* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_IPProtocolEndpoint_ConstRef;

typedef struct _SCX_IPProtocolEndpoint_Array
{
    struct _SCX_IPProtocolEndpoint** data;
    MI_Uint32 size;
}
SCX_IPProtocolEndpoint_Array;

typedef struct _SCX_IPProtocolEndpoint_ConstArray
{
    struct _SCX_IPProtocolEndpoint MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_IPProtocolEndpoint_ConstArray;

typedef struct _SCX_IPProtocolEndpoint_ArrayRef
{
    SCX_IPProtocolEndpoint_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_IPProtocolEndpoint_ArrayRef;

typedef struct _SCX_IPProtocolEndpoint_ConstArrayRef
{
    SCX_IPProtocolEndpoint_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_IPProtocolEndpoint_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_IPProtocolEndpoint_rtti;

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Construct(
    SCX_IPProtocolEndpoint* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_IPProtocolEndpoint_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clone(
    const SCX_IPProtocolEndpoint* self,
    SCX_IPProtocolEndpoint** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_IPProtocolEndpoint_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_IPProtocolEndpoint_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Destruct(SCX_IPProtocolEndpoint* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Delete(SCX_IPProtocolEndpoint* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Post(
    const SCX_IPProtocolEndpoint* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_InstanceID(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_InstanceID(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_InstanceID(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_Caption(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_Caption(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_Caption(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_Description(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_Description(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_Description(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_ElementName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_ElementName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_ElementName(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_InstallDate(
    SCX_IPProtocolEndpoint* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_InstallDate(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_Name(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_Name(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_Name(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_OperationalStatus(
    SCX_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_OperationalStatus(
    SCX_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_OperationalStatus(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_StatusDescriptions(
    SCX_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_StatusDescriptions(
    SCX_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_StatusDescriptions(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_Status(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_Status(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_Status(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_HealthState(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_HealthState(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_CommunicationStatus(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_CommunicationStatus(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_DetailedStatus(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_DetailedStatus(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_OperatingStatus(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_OperatingStatus(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_PrimaryStatus(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_PrimaryStatus(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_EnabledState(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_EnabledState(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_OtherEnabledState(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_OtherEnabledState(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_OtherEnabledState(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_RequestedState(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_RequestedState(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_EnabledDefault(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_EnabledDefault(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_TimeOfLastStateChange(
    SCX_IPProtocolEndpoint* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_TimeOfLastStateChange(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_AvailableRequestedStates(
    SCX_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_AvailableRequestedStates(
    SCX_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_AvailableRequestedStates(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_TransitioningToState(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_TransitioningToState(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_SystemCreationClassName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_SystemCreationClassName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_SystemCreationClassName(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_SystemName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_SystemName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_SystemName(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_CreationClassName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_CreationClassName(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_CreationClassName(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_NameFormat(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_NameFormat(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_NameFormat(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_ProtocolType(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ProtocolType)->value = x;
    ((MI_Uint16Field*)&self->ProtocolType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_ProtocolType(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->ProtocolType, 0, sizeof(self->ProtocolType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_ProtocolIFType(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ProtocolIFType)->value = x;
    ((MI_Uint16Field*)&self->ProtocolIFType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_ProtocolIFType(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->ProtocolIFType, 0, sizeof(self->ProtocolIFType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_OtherTypeDescription(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_OtherTypeDescription(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_OtherTypeDescription(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        27);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_IPv4Address(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_IPv4Address(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_IPv4Address(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        28);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_IPv6Address(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_IPv6Address(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_IPv6Address(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_Address(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_Address(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_Address(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_SubnetMask(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        31,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_SubnetMask(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        31,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_SubnetMask(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        31);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_PrefixLength(
    SCX_IPProtocolEndpoint* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PrefixLength)->value = x;
    ((MI_Uint8Field*)&self->PrefixLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_PrefixLength(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->PrefixLength, 0, sizeof(self->PrefixLength));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_AddressType(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->AddressType)->value = x;
    ((MI_Uint16Field*)&self->AddressType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_AddressType(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->AddressType, 0, sizeof(self->AddressType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_IPVersionSupport(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->IPVersionSupport)->value = x;
    ((MI_Uint16Field*)&self->IPVersionSupport)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_IPVersionSupport(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->IPVersionSupport, 0, sizeof(self->IPVersionSupport));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_AddressOrigin(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->AddressOrigin)->value = x;
    ((MI_Uint16Field*)&self->AddressOrigin)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_AddressOrigin(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->AddressOrigin, 0, sizeof(self->AddressOrigin));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_IPv6AddressType(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->IPv6AddressType)->value = x;
    ((MI_Uint16Field*)&self->IPv6AddressType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_IPv6AddressType(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->IPv6AddressType, 0, sizeof(self->IPv6AddressType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_IPv6SubnetPrefixLength(
    SCX_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->IPv6SubnetPrefixLength)->value = x;
    ((MI_Uint16Field*)&self->IPv6SubnetPrefixLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_IPv6SubnetPrefixLength(
    SCX_IPProtocolEndpoint* self)
{
    memset((void*)&self->IPv6SubnetPrefixLength, 0, sizeof(self->IPv6SubnetPrefixLength));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Set_IPv4BroadcastAddress(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_SetPtr_IPv4BroadcastAddress(
    SCX_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_Clear_IPv4BroadcastAddress(
    SCX_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

/*
**==============================================================================
**
** SCX_IPProtocolEndpoint.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_IPProtocolEndpoint_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_IPProtocolEndpoint_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_IPProtocolEndpoint_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Construct(
    SCX_IPProtocolEndpoint_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_IPProtocolEndpoint_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Clone(
    const SCX_IPProtocolEndpoint_RequestStateChange* self,
    SCX_IPProtocolEndpoint_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Destruct(
    SCX_IPProtocolEndpoint_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Delete(
    SCX_IPProtocolEndpoint_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Post(
    const SCX_IPProtocolEndpoint_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Set_MIReturn(
    SCX_IPProtocolEndpoint_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Clear_MIReturn(
    SCX_IPProtocolEndpoint_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Set_RequestedState(
    SCX_IPProtocolEndpoint_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Clear_RequestedState(
    SCX_IPProtocolEndpoint_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Set_Job(
    SCX_IPProtocolEndpoint_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_SetPtr_Job(
    SCX_IPProtocolEndpoint_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Clear_Job(
    SCX_IPProtocolEndpoint_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Set_TimeoutPeriod(
    SCX_IPProtocolEndpoint_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_IPProtocolEndpoint_RequestStateChange_Clear_TimeoutPeriod(
    SCX_IPProtocolEndpoint_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_IPProtocolEndpoint provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_IPProtocolEndpoint_Self SCX_IPProtocolEndpoint_Self;

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_Load(
    SCX_IPProtocolEndpoint_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_Unload(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_EnumerateInstances(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_GetInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_CreateInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* newInstance);

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_ModifyInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_DeleteInstance(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_IPProtocolEndpoint* instanceName);

MI_EXTERN_C void MI_CALL SCX_IPProtocolEndpoint_Invoke_RequestStateChange(
    SCX_IPProtocolEndpoint_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_IPProtocolEndpoint* instanceName,
    const SCX_IPProtocolEndpoint_RequestStateChange* in);


/*
**==============================================================================
**
** SCX_IPProtocolEndpoint_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_IPProtocolEndpoint_Class : public CIM_IPProtocolEndpoint_Class
{
public:
    
    typedef SCX_IPProtocolEndpoint Self;
    
    SCX_IPProtocolEndpoint_Class() :
        CIM_IPProtocolEndpoint_Class(&SCX_IPProtocolEndpoint_rtti)
    {
    }
    
    SCX_IPProtocolEndpoint_Class(
        const SCX_IPProtocolEndpoint* instanceName,
        bool keysOnly) :
        CIM_IPProtocolEndpoint_Class(
            &SCX_IPProtocolEndpoint_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_IPProtocolEndpoint_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_IPProtocolEndpoint_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_IPProtocolEndpoint_Class(
        const MI_ClassDecl* clDecl) :
        CIM_IPProtocolEndpoint_Class(clDecl)
    {
    }
    
    SCX_IPProtocolEndpoint_Class& operator=(
        const SCX_IPProtocolEndpoint_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_IPProtocolEndpoint_Class(
        const SCX_IPProtocolEndpoint_Class& x) :
        CIM_IPProtocolEndpoint_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_IPProtocolEndpoint_rtti;
    }

    //
    // SCX_IPProtocolEndpoint_Class.IPv4BroadcastAddress
    //
    
    const Field<String>& IPv4BroadcastAddress() const
    {
        const size_t n = offsetof(Self, IPv4BroadcastAddress);
        return GetField<String>(n);
    }
    
    void IPv4BroadcastAddress(const Field<String>& x)
    {
        const size_t n = offsetof(Self, IPv4BroadcastAddress);
        GetField<String>(n) = x;
    }
    
    const String& IPv4BroadcastAddress_value() const
    {
        const size_t n = offsetof(Self, IPv4BroadcastAddress);
        return GetField<String>(n).value;
    }
    
    void IPv4BroadcastAddress_value(const String& x)
    {
        const size_t n = offsetof(Self, IPv4BroadcastAddress);
        GetField<String>(n).Set(x);
    }
    
    bool IPv4BroadcastAddress_exists() const
    {
        const size_t n = offsetof(Self, IPv4BroadcastAddress);
        return GetField<String>(n).exists ? true : false;
    }
    
    void IPv4BroadcastAddress_clear()
    {
        const size_t n = offsetof(Self, IPv4BroadcastAddress);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_IPProtocolEndpoint_Class> SCX_IPProtocolEndpoint_ClassA;

class SCX_IPProtocolEndpoint_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_IPProtocolEndpoint_RequestStateChange Self;
    
    SCX_IPProtocolEndpoint_RequestStateChange_Class() :
        Instance(&SCX_IPProtocolEndpoint_RequestStateChange_rtti)
    {
    }
    
    SCX_IPProtocolEndpoint_RequestStateChange_Class(
        const SCX_IPProtocolEndpoint_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_IPProtocolEndpoint_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_IPProtocolEndpoint_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_IPProtocolEndpoint_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_IPProtocolEndpoint_RequestStateChange_Class& operator=(
        const SCX_IPProtocolEndpoint_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_IPProtocolEndpoint_RequestStateChange_Class(
        const SCX_IPProtocolEndpoint_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_IPProtocolEndpoint_RequestStateChange_Class.MIReturn
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
    // SCX_IPProtocolEndpoint_RequestStateChange_Class.RequestedState
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
    // SCX_IPProtocolEndpoint_RequestStateChange_Class.Job
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
    // SCX_IPProtocolEndpoint_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<SCX_IPProtocolEndpoint_RequestStateChange_Class> SCX_IPProtocolEndpoint_RequestStateChange_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_IPProtocolEndpoint_h */
