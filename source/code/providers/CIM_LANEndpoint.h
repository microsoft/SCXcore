/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_LANEndpoint_h
#define _CIM_LANEndpoint_h

#include <MI.h>
#include "CIM_ProtocolEndpoint.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_LANEndpoint [CIM_LANEndpoint]
**
** Keys:
**    Name
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _CIM_LANEndpoint /* extends CIM_ProtocolEndpoint */
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
    /* CIM_LANEndpoint properties */
    MI_ConstStringField LANID;
    MI_ConstUint16Field LANType;
    MI_ConstStringField OtherLANType;
    MI_ConstStringField MACAddress;
    MI_ConstStringAField AliasAddresses;
    MI_ConstStringAField GroupAddresses;
    MI_ConstUint32Field MaxDataSize;
}
CIM_LANEndpoint;

typedef struct _CIM_LANEndpoint_Ref
{
    CIM_LANEndpoint* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LANEndpoint_Ref;

typedef struct _CIM_LANEndpoint_ConstRef
{
    MI_CONST CIM_LANEndpoint* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LANEndpoint_ConstRef;

typedef struct _CIM_LANEndpoint_Array
{
    struct _CIM_LANEndpoint** data;
    MI_Uint32 size;
}
CIM_LANEndpoint_Array;

typedef struct _CIM_LANEndpoint_ConstArray
{
    struct _CIM_LANEndpoint MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_LANEndpoint_ConstArray;

typedef struct _CIM_LANEndpoint_ArrayRef
{
    CIM_LANEndpoint_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LANEndpoint_ArrayRef;

typedef struct _CIM_LANEndpoint_ConstArrayRef
{
    CIM_LANEndpoint_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LANEndpoint_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_LANEndpoint_rtti;

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Construct(
    CIM_LANEndpoint* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_LANEndpoint_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clone(
    const CIM_LANEndpoint* self,
    CIM_LANEndpoint** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_LANEndpoint_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_LANEndpoint_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Destruct(CIM_LANEndpoint* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Delete(CIM_LANEndpoint* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Post(
    const CIM_LANEndpoint* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_InstanceID(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_InstanceID(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_InstanceID(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_Caption(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_Caption(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_Caption(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_Description(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_Description(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_Description(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_ElementName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_ElementName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_ElementName(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_InstallDate(
    CIM_LANEndpoint* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_InstallDate(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_Name(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_Name(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_Name(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_OperationalStatus(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_OperationalStatus(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_OperationalStatus(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_StatusDescriptions(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_StatusDescriptions(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_StatusDescriptions(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_Status(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_Status(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_Status(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_HealthState(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_HealthState(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_CommunicationStatus(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_CommunicationStatus(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_DetailedStatus(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_DetailedStatus(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_OperatingStatus(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_OperatingStatus(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_PrimaryStatus(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_PrimaryStatus(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_EnabledState(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_EnabledState(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_OtherEnabledState(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_OtherEnabledState(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_OtherEnabledState(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_RequestedState(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_RequestedState(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_EnabledDefault(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_EnabledDefault(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_TimeOfLastStateChange(
    CIM_LANEndpoint* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_TimeOfLastStateChange(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_AvailableRequestedStates(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_AvailableRequestedStates(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_AvailableRequestedStates(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_TransitioningToState(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_TransitioningToState(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_SystemCreationClassName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_SystemCreationClassName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_SystemCreationClassName(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_SystemName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_SystemName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_SystemName(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_CreationClassName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_CreationClassName(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_CreationClassName(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_NameFormat(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_NameFormat(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_NameFormat(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_ProtocolType(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ProtocolType)->value = x;
    ((MI_Uint16Field*)&self->ProtocolType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_ProtocolType(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->ProtocolType, 0, sizeof(self->ProtocolType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_ProtocolIFType(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ProtocolIFType)->value = x;
    ((MI_Uint16Field*)&self->ProtocolIFType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_ProtocolIFType(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->ProtocolIFType, 0, sizeof(self->ProtocolIFType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_OtherTypeDescription(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_OtherTypeDescription(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_OtherTypeDescription(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        27);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_LANID(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_LANID(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        28,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_LANID(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        28);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_LANType(
    CIM_LANEndpoint* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->LANType)->value = x;
    ((MI_Uint16Field*)&self->LANType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_LANType(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->LANType, 0, sizeof(self->LANType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_OtherLANType(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_OtherLANType(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_OtherLANType(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_MACAddress(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        31,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_MACAddress(
    CIM_LANEndpoint* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        31,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_MACAddress(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        31);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_AliasAddresses(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_AliasAddresses(
    CIM_LANEndpoint* self,
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

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_AliasAddresses(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_GroupAddresses(
    CIM_LANEndpoint* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        33,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_SetPtr_GroupAddresses(
    CIM_LANEndpoint* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        33,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_GroupAddresses(
    CIM_LANEndpoint* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        33);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Set_MaxDataSize(
    CIM_LANEndpoint* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxDataSize)->value = x;
    ((MI_Uint32Field*)&self->MaxDataSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_Clear_MaxDataSize(
    CIM_LANEndpoint* self)
{
    memset((void*)&self->MaxDataSize, 0, sizeof(self->MaxDataSize));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_LANEndpoint.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_LANEndpoint_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_LANEndpoint_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Set_MIReturn(
    CIM_LANEndpoint_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Clear_MIReturn(
    CIM_LANEndpoint_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Set_RequestedState(
    CIM_LANEndpoint_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Clear_RequestedState(
    CIM_LANEndpoint_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Set_Job(
    CIM_LANEndpoint_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_SetPtr_Job(
    CIM_LANEndpoint_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Clear_Job(
    CIM_LANEndpoint_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Set_TimeoutPeriod(
    CIM_LANEndpoint_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LANEndpoint_RequestStateChange_Clear_TimeoutPeriod(
    CIM_LANEndpoint_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_LANEndpoint_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_LANEndpoint_Class : public CIM_ProtocolEndpoint_Class
{
public:
    
    typedef CIM_LANEndpoint Self;
    
    CIM_LANEndpoint_Class() :
        CIM_ProtocolEndpoint_Class(&CIM_LANEndpoint_rtti)
    {
    }
    
    CIM_LANEndpoint_Class(
        const CIM_LANEndpoint* instanceName,
        bool keysOnly) :
        CIM_ProtocolEndpoint_Class(
            &CIM_LANEndpoint_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LANEndpoint_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_ProtocolEndpoint_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LANEndpoint_Class(
        const MI_ClassDecl* clDecl) :
        CIM_ProtocolEndpoint_Class(clDecl)
    {
    }
    
    CIM_LANEndpoint_Class& operator=(
        const CIM_LANEndpoint_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LANEndpoint_Class(
        const CIM_LANEndpoint_Class& x) :
        CIM_ProtocolEndpoint_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_LANEndpoint_rtti;
    }

    //
    // CIM_LANEndpoint_Class.LANID
    //
    
    const Field<String>& LANID() const
    {
        const size_t n = offsetof(Self, LANID);
        return GetField<String>(n);
    }
    
    void LANID(const Field<String>& x)
    {
        const size_t n = offsetof(Self, LANID);
        GetField<String>(n) = x;
    }
    
    const String& LANID_value() const
    {
        const size_t n = offsetof(Self, LANID);
        return GetField<String>(n).value;
    }
    
    void LANID_value(const String& x)
    {
        const size_t n = offsetof(Self, LANID);
        GetField<String>(n).Set(x);
    }
    
    bool LANID_exists() const
    {
        const size_t n = offsetof(Self, LANID);
        return GetField<String>(n).exists ? true : false;
    }
    
    void LANID_clear()
    {
        const size_t n = offsetof(Self, LANID);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LANEndpoint_Class.LANType
    //
    
    const Field<Uint16>& LANType() const
    {
        const size_t n = offsetof(Self, LANType);
        return GetField<Uint16>(n);
    }
    
    void LANType(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, LANType);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& LANType_value() const
    {
        const size_t n = offsetof(Self, LANType);
        return GetField<Uint16>(n).value;
    }
    
    void LANType_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, LANType);
        GetField<Uint16>(n).Set(x);
    }
    
    bool LANType_exists() const
    {
        const size_t n = offsetof(Self, LANType);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void LANType_clear()
    {
        const size_t n = offsetof(Self, LANType);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_LANEndpoint_Class.OtherLANType
    //
    
    const Field<String>& OtherLANType() const
    {
        const size_t n = offsetof(Self, OtherLANType);
        return GetField<String>(n);
    }
    
    void OtherLANType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherLANType);
        GetField<String>(n) = x;
    }
    
    const String& OtherLANType_value() const
    {
        const size_t n = offsetof(Self, OtherLANType);
        return GetField<String>(n).value;
    }
    
    void OtherLANType_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherLANType);
        GetField<String>(n).Set(x);
    }
    
    bool OtherLANType_exists() const
    {
        const size_t n = offsetof(Self, OtherLANType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherLANType_clear()
    {
        const size_t n = offsetof(Self, OtherLANType);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LANEndpoint_Class.MACAddress
    //
    
    const Field<String>& MACAddress() const
    {
        const size_t n = offsetof(Self, MACAddress);
        return GetField<String>(n);
    }
    
    void MACAddress(const Field<String>& x)
    {
        const size_t n = offsetof(Self, MACAddress);
        GetField<String>(n) = x;
    }
    
    const String& MACAddress_value() const
    {
        const size_t n = offsetof(Self, MACAddress);
        return GetField<String>(n).value;
    }
    
    void MACAddress_value(const String& x)
    {
        const size_t n = offsetof(Self, MACAddress);
        GetField<String>(n).Set(x);
    }
    
    bool MACAddress_exists() const
    {
        const size_t n = offsetof(Self, MACAddress);
        return GetField<String>(n).exists ? true : false;
    }
    
    void MACAddress_clear()
    {
        const size_t n = offsetof(Self, MACAddress);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LANEndpoint_Class.AliasAddresses
    //
    
    const Field<StringA>& AliasAddresses() const
    {
        const size_t n = offsetof(Self, AliasAddresses);
        return GetField<StringA>(n);
    }
    
    void AliasAddresses(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, AliasAddresses);
        GetField<StringA>(n) = x;
    }
    
    const StringA& AliasAddresses_value() const
    {
        const size_t n = offsetof(Self, AliasAddresses);
        return GetField<StringA>(n).value;
    }
    
    void AliasAddresses_value(const StringA& x)
    {
        const size_t n = offsetof(Self, AliasAddresses);
        GetField<StringA>(n).Set(x);
    }
    
    bool AliasAddresses_exists() const
    {
        const size_t n = offsetof(Self, AliasAddresses);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void AliasAddresses_clear()
    {
        const size_t n = offsetof(Self, AliasAddresses);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_LANEndpoint_Class.GroupAddresses
    //
    
    const Field<StringA>& GroupAddresses() const
    {
        const size_t n = offsetof(Self, GroupAddresses);
        return GetField<StringA>(n);
    }
    
    void GroupAddresses(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, GroupAddresses);
        GetField<StringA>(n) = x;
    }
    
    const StringA& GroupAddresses_value() const
    {
        const size_t n = offsetof(Self, GroupAddresses);
        return GetField<StringA>(n).value;
    }
    
    void GroupAddresses_value(const StringA& x)
    {
        const size_t n = offsetof(Self, GroupAddresses);
        GetField<StringA>(n).Set(x);
    }
    
    bool GroupAddresses_exists() const
    {
        const size_t n = offsetof(Self, GroupAddresses);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void GroupAddresses_clear()
    {
        const size_t n = offsetof(Self, GroupAddresses);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_LANEndpoint_Class.MaxDataSize
    //
    
    const Field<Uint32>& MaxDataSize() const
    {
        const size_t n = offsetof(Self, MaxDataSize);
        return GetField<Uint32>(n);
    }
    
    void MaxDataSize(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MaxDataSize);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MaxDataSize_value() const
    {
        const size_t n = offsetof(Self, MaxDataSize);
        return GetField<Uint32>(n).value;
    }
    
    void MaxDataSize_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MaxDataSize);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MaxDataSize_exists() const
    {
        const size_t n = offsetof(Self, MaxDataSize);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MaxDataSize_clear()
    {
        const size_t n = offsetof(Self, MaxDataSize);
        GetField<Uint32>(n).Clear();
    }
};

typedef Array<CIM_LANEndpoint_Class> CIM_LANEndpoint_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_LANEndpoint_h */
