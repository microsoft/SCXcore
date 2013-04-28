/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_IPProtocolEndpoint_h
#define _CIM_IPProtocolEndpoint_h

#include <MI.h>
#include "CIM_ProtocolEndpoint.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_IPProtocolEndpoint [CIM_IPProtocolEndpoint]
**
** Keys:
**    Name
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _CIM_IPProtocolEndpoint /* extends CIM_ProtocolEndpoint */
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
}
CIM_IPProtocolEndpoint;

typedef struct _CIM_IPProtocolEndpoint_Ref
{
    CIM_IPProtocolEndpoint* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_IPProtocolEndpoint_Ref;

typedef struct _CIM_IPProtocolEndpoint_ConstRef
{
    MI_CONST CIM_IPProtocolEndpoint* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_IPProtocolEndpoint_ConstRef;

typedef struct _CIM_IPProtocolEndpoint_Array
{
    struct _CIM_IPProtocolEndpoint** data;
    MI_Uint32 size;
}
CIM_IPProtocolEndpoint_Array;

typedef struct _CIM_IPProtocolEndpoint_ConstArray
{
    struct _CIM_IPProtocolEndpoint MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_IPProtocolEndpoint_ConstArray;

typedef struct _CIM_IPProtocolEndpoint_ArrayRef
{
    CIM_IPProtocolEndpoint_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_IPProtocolEndpoint_ArrayRef;

typedef struct _CIM_IPProtocolEndpoint_ConstArrayRef
{
    CIM_IPProtocolEndpoint_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_IPProtocolEndpoint_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_IPProtocolEndpoint_rtti;

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Construct(
    CIM_IPProtocolEndpoint* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_IPProtocolEndpoint_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clone(
    const CIM_IPProtocolEndpoint* self,
    CIM_IPProtocolEndpoint** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_IPProtocolEndpoint_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_IPProtocolEndpoint_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Destruct(CIM_IPProtocolEndpoint* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Delete(CIM_IPProtocolEndpoint* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Post(
    const CIM_IPProtocolEndpoint* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_InstanceID(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_InstanceID(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_InstanceID(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_Caption(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_Caption(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_Caption(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_Description(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_Description(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_Description(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_ElementName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_ElementName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_ElementName(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_InstallDate(
    CIM_IPProtocolEndpoint* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_InstallDate(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_Name(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_Name(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_Name(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_OperationalStatus(
    CIM_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_OperationalStatus(
    CIM_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_OperationalStatus(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_StatusDescriptions(
    CIM_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_StatusDescriptions(
    CIM_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_StatusDescriptions(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_Status(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_Status(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_Status(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_HealthState(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_HealthState(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_CommunicationStatus(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_CommunicationStatus(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_DetailedStatus(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_DetailedStatus(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_OperatingStatus(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_OperatingStatus(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_PrimaryStatus(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_PrimaryStatus(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_EnabledState(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_EnabledState(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_OtherEnabledState(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_OtherEnabledState(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_OtherEnabledState(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_RequestedState(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_RequestedState(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_EnabledDefault(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_EnabledDefault(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_TimeOfLastStateChange(
    CIM_IPProtocolEndpoint* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_TimeOfLastStateChange(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_AvailableRequestedStates(
    CIM_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_AvailableRequestedStates(
    CIM_IPProtocolEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_AvailableRequestedStates(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_TransitioningToState(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_TransitioningToState(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_SystemCreationClassName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_SystemCreationClassName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_SystemCreationClassName(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_SystemName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_SystemName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_SystemName(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_CreationClassName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_CreationClassName(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_CreationClassName(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_NameFormat(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_NameFormat(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_NameFormat(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_ProtocolType(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ProtocolType)->value = x;
    ((MI_Uint16Field*)&self->ProtocolType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_ProtocolType(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->ProtocolType, 0, sizeof(self->ProtocolType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_ProtocolIFType(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ProtocolIFType)->value = x;
    ((MI_Uint16Field*)&self->ProtocolIFType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_ProtocolIFType(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->ProtocolIFType, 0, sizeof(self->ProtocolIFType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_OtherTypeDescription(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_OtherTypeDescription(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_OtherTypeDescription(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        27);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_IPv4Address(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_IPv4Address(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_IPv4Address(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        28);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_IPv6Address(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_IPv6Address(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_IPv6Address(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_Address(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_Address(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_Address(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_SubnetMask(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        31,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_SetPtr_SubnetMask(
    CIM_IPProtocolEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        31,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_SubnetMask(
    CIM_IPProtocolEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        31);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_PrefixLength(
    CIM_IPProtocolEndpoint* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PrefixLength)->value = x;
    ((MI_Uint8Field*)&self->PrefixLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_PrefixLength(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->PrefixLength, 0, sizeof(self->PrefixLength));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_AddressType(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->AddressType)->value = x;
    ((MI_Uint16Field*)&self->AddressType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_AddressType(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->AddressType, 0, sizeof(self->AddressType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_IPVersionSupport(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->IPVersionSupport)->value = x;
    ((MI_Uint16Field*)&self->IPVersionSupport)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_IPVersionSupport(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->IPVersionSupport, 0, sizeof(self->IPVersionSupport));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_AddressOrigin(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->AddressOrigin)->value = x;
    ((MI_Uint16Field*)&self->AddressOrigin)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_AddressOrigin(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->AddressOrigin, 0, sizeof(self->AddressOrigin));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_IPv6AddressType(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->IPv6AddressType)->value = x;
    ((MI_Uint16Field*)&self->IPv6AddressType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_IPv6AddressType(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->IPv6AddressType, 0, sizeof(self->IPv6AddressType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Set_IPv6SubnetPrefixLength(
    CIM_IPProtocolEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->IPv6SubnetPrefixLength)->value = x;
    ((MI_Uint16Field*)&self->IPv6SubnetPrefixLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_Clear_IPv6SubnetPrefixLength(
    CIM_IPProtocolEndpoint* self)
{
    memset((void*)&self->IPv6SubnetPrefixLength, 0, sizeof(self->IPv6SubnetPrefixLength));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_IPProtocolEndpoint.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_IPProtocolEndpoint_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_IPProtocolEndpoint_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Set_MIReturn(
    CIM_IPProtocolEndpoint_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Clear_MIReturn(
    CIM_IPProtocolEndpoint_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Set_RequestedState(
    CIM_IPProtocolEndpoint_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Clear_RequestedState(
    CIM_IPProtocolEndpoint_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Set_Job(
    CIM_IPProtocolEndpoint_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_SetPtr_Job(
    CIM_IPProtocolEndpoint_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Clear_Job(
    CIM_IPProtocolEndpoint_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Set_TimeoutPeriod(
    CIM_IPProtocolEndpoint_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_IPProtocolEndpoint_RequestStateChange_Clear_TimeoutPeriod(
    CIM_IPProtocolEndpoint_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_IPProtocolEndpoint_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_IPProtocolEndpoint_Class : public CIM_ProtocolEndpoint_Class
{
public:
    
    typedef CIM_IPProtocolEndpoint Self;
    
    CIM_IPProtocolEndpoint_Class() :
        CIM_ProtocolEndpoint_Class(&CIM_IPProtocolEndpoint_rtti)
    {
    }
    
    CIM_IPProtocolEndpoint_Class(
        const CIM_IPProtocolEndpoint* instanceName,
        bool keysOnly) :
        CIM_ProtocolEndpoint_Class(
            &CIM_IPProtocolEndpoint_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_IPProtocolEndpoint_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_ProtocolEndpoint_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_IPProtocolEndpoint_Class(
        const MI_ClassDecl* clDecl) :
        CIM_ProtocolEndpoint_Class(clDecl)
    {
    }
    
    CIM_IPProtocolEndpoint_Class& operator=(
        const CIM_IPProtocolEndpoint_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_IPProtocolEndpoint_Class(
        const CIM_IPProtocolEndpoint_Class& x) :
        CIM_ProtocolEndpoint_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_IPProtocolEndpoint_rtti;
    }

    //
    // CIM_IPProtocolEndpoint_Class.IPv4Address
    //
    
    const Field<String>& IPv4Address() const
    {
        const size_t n = offsetof(Self, IPv4Address);
        return GetField<String>(n);
    }
    
    void IPv4Address(const Field<String>& x)
    {
        const size_t n = offsetof(Self, IPv4Address);
        GetField<String>(n) = x;
    }
    
    const String& IPv4Address_value() const
    {
        const size_t n = offsetof(Self, IPv4Address);
        return GetField<String>(n).value;
    }
    
    void IPv4Address_value(const String& x)
    {
        const size_t n = offsetof(Self, IPv4Address);
        GetField<String>(n).Set(x);
    }
    
    bool IPv4Address_exists() const
    {
        const size_t n = offsetof(Self, IPv4Address);
        return GetField<String>(n).exists ? true : false;
    }
    
    void IPv4Address_clear()
    {
        const size_t n = offsetof(Self, IPv4Address);
        GetField<String>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.IPv6Address
    //
    
    const Field<String>& IPv6Address() const
    {
        const size_t n = offsetof(Self, IPv6Address);
        return GetField<String>(n);
    }
    
    void IPv6Address(const Field<String>& x)
    {
        const size_t n = offsetof(Self, IPv6Address);
        GetField<String>(n) = x;
    }
    
    const String& IPv6Address_value() const
    {
        const size_t n = offsetof(Self, IPv6Address);
        return GetField<String>(n).value;
    }
    
    void IPv6Address_value(const String& x)
    {
        const size_t n = offsetof(Self, IPv6Address);
        GetField<String>(n).Set(x);
    }
    
    bool IPv6Address_exists() const
    {
        const size_t n = offsetof(Self, IPv6Address);
        return GetField<String>(n).exists ? true : false;
    }
    
    void IPv6Address_clear()
    {
        const size_t n = offsetof(Self, IPv6Address);
        GetField<String>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.Address
    //
    
    const Field<String>& Address() const
    {
        const size_t n = offsetof(Self, Address);
        return GetField<String>(n);
    }
    
    void Address(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Address);
        GetField<String>(n) = x;
    }
    
    const String& Address_value() const
    {
        const size_t n = offsetof(Self, Address);
        return GetField<String>(n).value;
    }
    
    void Address_value(const String& x)
    {
        const size_t n = offsetof(Self, Address);
        GetField<String>(n).Set(x);
    }
    
    bool Address_exists() const
    {
        const size_t n = offsetof(Self, Address);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Address_clear()
    {
        const size_t n = offsetof(Self, Address);
        GetField<String>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.SubnetMask
    //
    
    const Field<String>& SubnetMask() const
    {
        const size_t n = offsetof(Self, SubnetMask);
        return GetField<String>(n);
    }
    
    void SubnetMask(const Field<String>& x)
    {
        const size_t n = offsetof(Self, SubnetMask);
        GetField<String>(n) = x;
    }
    
    const String& SubnetMask_value() const
    {
        const size_t n = offsetof(Self, SubnetMask);
        return GetField<String>(n).value;
    }
    
    void SubnetMask_value(const String& x)
    {
        const size_t n = offsetof(Self, SubnetMask);
        GetField<String>(n).Set(x);
    }
    
    bool SubnetMask_exists() const
    {
        const size_t n = offsetof(Self, SubnetMask);
        return GetField<String>(n).exists ? true : false;
    }
    
    void SubnetMask_clear()
    {
        const size_t n = offsetof(Self, SubnetMask);
        GetField<String>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.PrefixLength
    //
    
    const Field<Uint8>& PrefixLength() const
    {
        const size_t n = offsetof(Self, PrefixLength);
        return GetField<Uint8>(n);
    }
    
    void PrefixLength(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PrefixLength);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PrefixLength_value() const
    {
        const size_t n = offsetof(Self, PrefixLength);
        return GetField<Uint8>(n).value;
    }
    
    void PrefixLength_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PrefixLength);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PrefixLength_exists() const
    {
        const size_t n = offsetof(Self, PrefixLength);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PrefixLength_clear()
    {
        const size_t n = offsetof(Self, PrefixLength);
        GetField<Uint8>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.AddressType
    //
    
    const Field<Uint16>& AddressType() const
    {
        const size_t n = offsetof(Self, AddressType);
        return GetField<Uint16>(n);
    }
    
    void AddressType(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, AddressType);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& AddressType_value() const
    {
        const size_t n = offsetof(Self, AddressType);
        return GetField<Uint16>(n).value;
    }
    
    void AddressType_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, AddressType);
        GetField<Uint16>(n).Set(x);
    }
    
    bool AddressType_exists() const
    {
        const size_t n = offsetof(Self, AddressType);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void AddressType_clear()
    {
        const size_t n = offsetof(Self, AddressType);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.IPVersionSupport
    //
    
    const Field<Uint16>& IPVersionSupport() const
    {
        const size_t n = offsetof(Self, IPVersionSupport);
        return GetField<Uint16>(n);
    }
    
    void IPVersionSupport(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, IPVersionSupport);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& IPVersionSupport_value() const
    {
        const size_t n = offsetof(Self, IPVersionSupport);
        return GetField<Uint16>(n).value;
    }
    
    void IPVersionSupport_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, IPVersionSupport);
        GetField<Uint16>(n).Set(x);
    }
    
    bool IPVersionSupport_exists() const
    {
        const size_t n = offsetof(Self, IPVersionSupport);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void IPVersionSupport_clear()
    {
        const size_t n = offsetof(Self, IPVersionSupport);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.AddressOrigin
    //
    
    const Field<Uint16>& AddressOrigin() const
    {
        const size_t n = offsetof(Self, AddressOrigin);
        return GetField<Uint16>(n);
    }
    
    void AddressOrigin(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, AddressOrigin);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& AddressOrigin_value() const
    {
        const size_t n = offsetof(Self, AddressOrigin);
        return GetField<Uint16>(n).value;
    }
    
    void AddressOrigin_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, AddressOrigin);
        GetField<Uint16>(n).Set(x);
    }
    
    bool AddressOrigin_exists() const
    {
        const size_t n = offsetof(Self, AddressOrigin);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void AddressOrigin_clear()
    {
        const size_t n = offsetof(Self, AddressOrigin);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.IPv6AddressType
    //
    
    const Field<Uint16>& IPv6AddressType() const
    {
        const size_t n = offsetof(Self, IPv6AddressType);
        return GetField<Uint16>(n);
    }
    
    void IPv6AddressType(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, IPv6AddressType);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& IPv6AddressType_value() const
    {
        const size_t n = offsetof(Self, IPv6AddressType);
        return GetField<Uint16>(n).value;
    }
    
    void IPv6AddressType_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, IPv6AddressType);
        GetField<Uint16>(n).Set(x);
    }
    
    bool IPv6AddressType_exists() const
    {
        const size_t n = offsetof(Self, IPv6AddressType);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void IPv6AddressType_clear()
    {
        const size_t n = offsetof(Self, IPv6AddressType);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_IPProtocolEndpoint_Class.IPv6SubnetPrefixLength
    //
    
    const Field<Uint16>& IPv6SubnetPrefixLength() const
    {
        const size_t n = offsetof(Self, IPv6SubnetPrefixLength);
        return GetField<Uint16>(n);
    }
    
    void IPv6SubnetPrefixLength(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, IPv6SubnetPrefixLength);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& IPv6SubnetPrefixLength_value() const
    {
        const size_t n = offsetof(Self, IPv6SubnetPrefixLength);
        return GetField<Uint16>(n).value;
    }
    
    void IPv6SubnetPrefixLength_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, IPv6SubnetPrefixLength);
        GetField<Uint16>(n).Set(x);
    }
    
    bool IPv6SubnetPrefixLength_exists() const
    {
        const size_t n = offsetof(Self, IPv6SubnetPrefixLength);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void IPv6SubnetPrefixLength_clear()
    {
        const size_t n = offsetof(Self, IPv6SubnetPrefixLength);
        GetField<Uint16>(n).Clear();
    }
};

typedef Array<CIM_IPProtocolEndpoint_Class> CIM_IPProtocolEndpoint_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_IPProtocolEndpoint_h */
