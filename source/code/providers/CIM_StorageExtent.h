/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_StorageExtent_h
#define _CIM_StorageExtent_h

#include <MI.h>
#include "CIM_LogicalDevice.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_StorageExtent [CIM_StorageExtent]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent /* extends CIM_LogicalDevice */
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
    /* CIM_StorageExtent properties */
    MI_ConstUint16Field DataOrganization;
    MI_ConstStringField Purpose;
    MI_ConstUint16Field Access;
    MI_ConstStringField ErrorMethodology;
    MI_ConstUint64Field BlockSize;
    MI_ConstUint64Field NumberOfBlocks;
    MI_ConstUint64Field ConsumableBlocks;
    MI_ConstBooleanField IsBasedOnUnderlyingRedundancy;
    MI_ConstBooleanField SequentialAccess;
    MI_ConstUint16AField ExtentStatus;
    MI_ConstBooleanField NoSinglePointOfFailure;
    MI_ConstUint16Field DataRedundancy;
    MI_ConstUint16Field PackageRedundancy;
    MI_ConstUint8Field DeltaReservation;
    MI_ConstBooleanField Primordial;
    MI_ConstUint16Field NameFormat;
    MI_ConstUint16Field NameNamespace;
    MI_ConstStringField OtherNameNamespace;
    MI_ConstStringField OtherNameFormat;
}
CIM_StorageExtent;

typedef struct _CIM_StorageExtent_Ref
{
    CIM_StorageExtent* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StorageExtent_Ref;

typedef struct _CIM_StorageExtent_ConstRef
{
    MI_CONST CIM_StorageExtent* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StorageExtent_ConstRef;

typedef struct _CIM_StorageExtent_Array
{
    struct _CIM_StorageExtent** data;
    MI_Uint32 size;
}
CIM_StorageExtent_Array;

typedef struct _CIM_StorageExtent_ConstArray
{
    struct _CIM_StorageExtent MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_StorageExtent_ConstArray;

typedef struct _CIM_StorageExtent_ArrayRef
{
    CIM_StorageExtent_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StorageExtent_ArrayRef;

typedef struct _CIM_StorageExtent_ConstArrayRef
{
    CIM_StorageExtent_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StorageExtent_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_StorageExtent_rtti;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Construct(
    CIM_StorageExtent* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_StorageExtent_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clone(
    const CIM_StorageExtent* self,
    CIM_StorageExtent** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_StorageExtent_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_StorageExtent_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Destruct(CIM_StorageExtent* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Delete(CIM_StorageExtent* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Post(
    const CIM_StorageExtent* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_InstanceID(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_InstanceID(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_InstanceID(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Caption(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_Caption(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Caption(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Description(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_Description(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Description(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_ElementName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_ElementName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_ElementName(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_InstallDate(
    CIM_StorageExtent* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_InstallDate(
    CIM_StorageExtent* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Name(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_Name(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Name(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_OperationalStatus(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_OperationalStatus(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_OperationalStatus(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_StatusDescriptions(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_StatusDescriptions(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_StatusDescriptions(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Status(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_Status(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Status(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_HealthState(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_HealthState(
    CIM_StorageExtent* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_CommunicationStatus(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_CommunicationStatus(
    CIM_StorageExtent* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_DetailedStatus(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_DetailedStatus(
    CIM_StorageExtent* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_OperatingStatus(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_OperatingStatus(
    CIM_StorageExtent* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_PrimaryStatus(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_PrimaryStatus(
    CIM_StorageExtent* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_EnabledState(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_EnabledState(
    CIM_StorageExtent* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_OtherEnabledState(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_OtherEnabledState(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_OtherEnabledState(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_RequestedState(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_RequestedState(
    CIM_StorageExtent* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_EnabledDefault(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_EnabledDefault(
    CIM_StorageExtent* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_TimeOfLastStateChange(
    CIM_StorageExtent* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_TimeOfLastStateChange(
    CIM_StorageExtent* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_AvailableRequestedStates(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_AvailableRequestedStates(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_AvailableRequestedStates(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_TransitioningToState(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_TransitioningToState(
    CIM_StorageExtent* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_SystemCreationClassName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_SystemCreationClassName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_SystemCreationClassName(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_SystemName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_SystemName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_SystemName(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_CreationClassName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_CreationClassName(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_CreationClassName(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_DeviceID(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_DeviceID(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_DeviceID(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_PowerManagementSupported(
    CIM_StorageExtent* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_PowerManagementSupported(
    CIM_StorageExtent* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_PowerManagementCapabilities(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_PowerManagementCapabilities(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_PowerManagementCapabilities(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Availability(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Availability(
    CIM_StorageExtent* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_StatusInfo(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_StatusInfo(
    CIM_StorageExtent* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_LastErrorCode(
    CIM_StorageExtent* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_LastErrorCode(
    CIM_StorageExtent* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_ErrorDescription(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_ErrorDescription(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_ErrorDescription(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_ErrorCleared(
    CIM_StorageExtent* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_ErrorCleared(
    CIM_StorageExtent* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_OtherIdentifyingInfo(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_OtherIdentifyingInfo(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_OtherIdentifyingInfo(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_PowerOnHours(
    CIM_StorageExtent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_PowerOnHours(
    CIM_StorageExtent* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_TotalPowerOnHours(
    CIM_StorageExtent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_TotalPowerOnHours(
    CIM_StorageExtent* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_IdentifyingDescriptions(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_IdentifyingDescriptions(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_IdentifyingDescriptions(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_AdditionalAvailability(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_AdditionalAvailability(
    CIM_StorageExtent* self,
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

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_AdditionalAvailability(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_MaxQuiesceTime(
    CIM_StorageExtent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_MaxQuiesceTime(
    CIM_StorageExtent* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_DataOrganization(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataOrganization)->value = x;
    ((MI_Uint16Field*)&self->DataOrganization)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_DataOrganization(
    CIM_StorageExtent* self)
{
    memset((void*)&self->DataOrganization, 0, sizeof(self->DataOrganization));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Purpose(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_Purpose(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Purpose(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Access(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Access)->value = x;
    ((MI_Uint16Field*)&self->Access)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Access(
    CIM_StorageExtent* self)
{
    memset((void*)&self->Access, 0, sizeof(self->Access));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_ErrorMethodology(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_ErrorMethodology(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_ErrorMethodology(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_BlockSize(
    CIM_StorageExtent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockSize)->value = x;
    ((MI_Uint64Field*)&self->BlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_BlockSize(
    CIM_StorageExtent* self)
{
    memset((void*)&self->BlockSize, 0, sizeof(self->BlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_NumberOfBlocks(
    CIM_StorageExtent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->NumberOfBlocks)->value = x;
    ((MI_Uint64Field*)&self->NumberOfBlocks)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_NumberOfBlocks(
    CIM_StorageExtent* self)
{
    memset((void*)&self->NumberOfBlocks, 0, sizeof(self->NumberOfBlocks));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_ConsumableBlocks(
    CIM_StorageExtent* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ConsumableBlocks)->value = x;
    ((MI_Uint64Field*)&self->ConsumableBlocks)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_ConsumableBlocks(
    CIM_StorageExtent* self)
{
    memset((void*)&self->ConsumableBlocks, 0, sizeof(self->ConsumableBlocks));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_IsBasedOnUnderlyingRedundancy(
    CIM_StorageExtent* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsBasedOnUnderlyingRedundancy)->value = x;
    ((MI_BooleanField*)&self->IsBasedOnUnderlyingRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_IsBasedOnUnderlyingRedundancy(
    CIM_StorageExtent* self)
{
    memset((void*)&self->IsBasedOnUnderlyingRedundancy, 0, sizeof(self->IsBasedOnUnderlyingRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_SequentialAccess(
    CIM_StorageExtent* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->SequentialAccess)->value = x;
    ((MI_BooleanField*)&self->SequentialAccess)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_SequentialAccess(
    CIM_StorageExtent* self)
{
    memset((void*)&self->SequentialAccess, 0, sizeof(self->SequentialAccess));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_ExtentStatus(
    CIM_StorageExtent* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_ExtentStatus(
    CIM_StorageExtent* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        47,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_ExtentStatus(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        47);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_NoSinglePointOfFailure(
    CIM_StorageExtent* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->NoSinglePointOfFailure)->value = x;
    ((MI_BooleanField*)&self->NoSinglePointOfFailure)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_NoSinglePointOfFailure(
    CIM_StorageExtent* self)
{
    memset((void*)&self->NoSinglePointOfFailure, 0, sizeof(self->NoSinglePointOfFailure));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_DataRedundancy(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataRedundancy)->value = x;
    ((MI_Uint16Field*)&self->DataRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_DataRedundancy(
    CIM_StorageExtent* self)
{
    memset((void*)&self->DataRedundancy, 0, sizeof(self->DataRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_PackageRedundancy(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PackageRedundancy)->value = x;
    ((MI_Uint16Field*)&self->PackageRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_PackageRedundancy(
    CIM_StorageExtent* self)
{
    memset((void*)&self->PackageRedundancy, 0, sizeof(self->PackageRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_DeltaReservation(
    CIM_StorageExtent* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->DeltaReservation)->value = x;
    ((MI_Uint8Field*)&self->DeltaReservation)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_DeltaReservation(
    CIM_StorageExtent* self)
{
    memset((void*)&self->DeltaReservation, 0, sizeof(self->DeltaReservation));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_Primordial(
    CIM_StorageExtent* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Primordial)->value = x;
    ((MI_BooleanField*)&self->Primordial)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_Primordial(
    CIM_StorageExtent* self)
{
    memset((void*)&self->Primordial, 0, sizeof(self->Primordial));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_NameFormat(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NameFormat)->value = x;
    ((MI_Uint16Field*)&self->NameFormat)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_NameFormat(
    CIM_StorageExtent* self)
{
    memset((void*)&self->NameFormat, 0, sizeof(self->NameFormat));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_NameNamespace(
    CIM_StorageExtent* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NameNamespace)->value = x;
    ((MI_Uint16Field*)&self->NameNamespace)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_NameNamespace(
    CIM_StorageExtent* self)
{
    memset((void*)&self->NameNamespace, 0, sizeof(self->NameNamespace));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_OtherNameNamespace(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_OtherNameNamespace(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_OtherNameNamespace(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        55);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Set_OtherNameFormat(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPtr_OtherNameFormat(
    CIM_StorageExtent* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Clear_OtherNameFormat(
    CIM_StorageExtent* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        56);
}

/*
**==============================================================================
**
** CIM_StorageExtent.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_StorageExtent_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Set_MIReturn(
    CIM_StorageExtent_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Clear_MIReturn(
    CIM_StorageExtent_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Set_RequestedState(
    CIM_StorageExtent_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Clear_RequestedState(
    CIM_StorageExtent_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Set_Job(
    CIM_StorageExtent_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_SetPtr_Job(
    CIM_StorageExtent_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Clear_Job(
    CIM_StorageExtent_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Set_TimeoutPeriod(
    CIM_StorageExtent_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RequestStateChange_Clear_TimeoutPeriod(
    CIM_StorageExtent_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StorageExtent.SetPowerState()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
CIM_StorageExtent_SetPowerState;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPowerState_Set_MIReturn(
    CIM_StorageExtent_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPowerState_Clear_MIReturn(
    CIM_StorageExtent_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPowerState_Set_PowerState(
    CIM_StorageExtent_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPowerState_Clear_PowerState(
    CIM_StorageExtent_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPowerState_Set_Time(
    CIM_StorageExtent_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SetPowerState_Clear_Time(
    CIM_StorageExtent_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StorageExtent.Reset()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_StorageExtent_Reset;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Reset_Set_MIReturn(
    CIM_StorageExtent_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_Reset_Clear_MIReturn(
    CIM_StorageExtent_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StorageExtent.EnableDevice()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
CIM_StorageExtent_EnableDevice;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_EnableDevice_Set_MIReturn(
    CIM_StorageExtent_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_EnableDevice_Clear_MIReturn(
    CIM_StorageExtent_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_EnableDevice_Set_Enabled(
    CIM_StorageExtent_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_EnableDevice_Clear_Enabled(
    CIM_StorageExtent_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StorageExtent.OnlineDevice()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
CIM_StorageExtent_OnlineDevice;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_OnlineDevice_Set_MIReturn(
    CIM_StorageExtent_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_OnlineDevice_Clear_MIReturn(
    CIM_StorageExtent_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_OnlineDevice_Set_Online(
    CIM_StorageExtent_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_OnlineDevice_Clear_Online(
    CIM_StorageExtent_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StorageExtent.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
CIM_StorageExtent_QuiesceDevice;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_QuiesceDevice_Set_MIReturn(
    CIM_StorageExtent_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_QuiesceDevice_Clear_MIReturn(
    CIM_StorageExtent_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_QuiesceDevice_Set_Quiesce(
    CIM_StorageExtent_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_QuiesceDevice_Clear_Quiesce(
    CIM_StorageExtent_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StorageExtent.SaveProperties()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_StorageExtent_SaveProperties;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SaveProperties_Set_MIReturn(
    CIM_StorageExtent_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_SaveProperties_Clear_MIReturn(
    CIM_StorageExtent_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StorageExtent.RestoreProperties()
**
**==============================================================================
*/

typedef struct _CIM_StorageExtent_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_StorageExtent_RestoreProperties;

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RestoreProperties_Set_MIReturn(
    CIM_StorageExtent_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StorageExtent_RestoreProperties_Clear_MIReturn(
    CIM_StorageExtent_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_StorageExtent_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_StorageExtent_Class : public CIM_LogicalDevice_Class
{
public:
    
    typedef CIM_StorageExtent Self;
    
    CIM_StorageExtent_Class() :
        CIM_LogicalDevice_Class(&CIM_StorageExtent_rtti)
    {
    }
    
    CIM_StorageExtent_Class(
        const CIM_StorageExtent* instanceName,
        bool keysOnly) :
        CIM_LogicalDevice_Class(
            &CIM_StorageExtent_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_StorageExtent_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalDevice_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_StorageExtent_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalDevice_Class(clDecl)
    {
    }
    
    CIM_StorageExtent_Class& operator=(
        const CIM_StorageExtent_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_StorageExtent_Class(
        const CIM_StorageExtent_Class& x) :
        CIM_LogicalDevice_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_StorageExtent_rtti;
    }

    //
    // CIM_StorageExtent_Class.DataOrganization
    //
    
    const Field<Uint16>& DataOrganization() const
    {
        const size_t n = offsetof(Self, DataOrganization);
        return GetField<Uint16>(n);
    }
    
    void DataOrganization(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, DataOrganization);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& DataOrganization_value() const
    {
        const size_t n = offsetof(Self, DataOrganization);
        return GetField<Uint16>(n).value;
    }
    
    void DataOrganization_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, DataOrganization);
        GetField<Uint16>(n).Set(x);
    }
    
    bool DataOrganization_exists() const
    {
        const size_t n = offsetof(Self, DataOrganization);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void DataOrganization_clear()
    {
        const size_t n = offsetof(Self, DataOrganization);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.Purpose
    //
    
    const Field<String>& Purpose() const
    {
        const size_t n = offsetof(Self, Purpose);
        return GetField<String>(n);
    }
    
    void Purpose(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Purpose);
        GetField<String>(n) = x;
    }
    
    const String& Purpose_value() const
    {
        const size_t n = offsetof(Self, Purpose);
        return GetField<String>(n).value;
    }
    
    void Purpose_value(const String& x)
    {
        const size_t n = offsetof(Self, Purpose);
        GetField<String>(n).Set(x);
    }
    
    bool Purpose_exists() const
    {
        const size_t n = offsetof(Self, Purpose);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Purpose_clear()
    {
        const size_t n = offsetof(Self, Purpose);
        GetField<String>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.Access
    //
    
    const Field<Uint16>& Access() const
    {
        const size_t n = offsetof(Self, Access);
        return GetField<Uint16>(n);
    }
    
    void Access(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, Access);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& Access_value() const
    {
        const size_t n = offsetof(Self, Access);
        return GetField<Uint16>(n).value;
    }
    
    void Access_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, Access);
        GetField<Uint16>(n).Set(x);
    }
    
    bool Access_exists() const
    {
        const size_t n = offsetof(Self, Access);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void Access_clear()
    {
        const size_t n = offsetof(Self, Access);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.ErrorMethodology
    //
    
    const Field<String>& ErrorMethodology() const
    {
        const size_t n = offsetof(Self, ErrorMethodology);
        return GetField<String>(n);
    }
    
    void ErrorMethodology(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ErrorMethodology);
        GetField<String>(n) = x;
    }
    
    const String& ErrorMethodology_value() const
    {
        const size_t n = offsetof(Self, ErrorMethodology);
        return GetField<String>(n).value;
    }
    
    void ErrorMethodology_value(const String& x)
    {
        const size_t n = offsetof(Self, ErrorMethodology);
        GetField<String>(n).Set(x);
    }
    
    bool ErrorMethodology_exists() const
    {
        const size_t n = offsetof(Self, ErrorMethodology);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ErrorMethodology_clear()
    {
        const size_t n = offsetof(Self, ErrorMethodology);
        GetField<String>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.BlockSize
    //
    
    const Field<Uint64>& BlockSize() const
    {
        const size_t n = offsetof(Self, BlockSize);
        return GetField<Uint64>(n);
    }
    
    void BlockSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BlockSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BlockSize_value() const
    {
        const size_t n = offsetof(Self, BlockSize);
        return GetField<Uint64>(n).value;
    }
    
    void BlockSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BlockSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BlockSize_exists() const
    {
        const size_t n = offsetof(Self, BlockSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BlockSize_clear()
    {
        const size_t n = offsetof(Self, BlockSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.NumberOfBlocks
    //
    
    const Field<Uint64>& NumberOfBlocks() const
    {
        const size_t n = offsetof(Self, NumberOfBlocks);
        return GetField<Uint64>(n);
    }
    
    void NumberOfBlocks(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, NumberOfBlocks);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& NumberOfBlocks_value() const
    {
        const size_t n = offsetof(Self, NumberOfBlocks);
        return GetField<Uint64>(n).value;
    }
    
    void NumberOfBlocks_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, NumberOfBlocks);
        GetField<Uint64>(n).Set(x);
    }
    
    bool NumberOfBlocks_exists() const
    {
        const size_t n = offsetof(Self, NumberOfBlocks);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void NumberOfBlocks_clear()
    {
        const size_t n = offsetof(Self, NumberOfBlocks);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.ConsumableBlocks
    //
    
    const Field<Uint64>& ConsumableBlocks() const
    {
        const size_t n = offsetof(Self, ConsumableBlocks);
        return GetField<Uint64>(n);
    }
    
    void ConsumableBlocks(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, ConsumableBlocks);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& ConsumableBlocks_value() const
    {
        const size_t n = offsetof(Self, ConsumableBlocks);
        return GetField<Uint64>(n).value;
    }
    
    void ConsumableBlocks_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, ConsumableBlocks);
        GetField<Uint64>(n).Set(x);
    }
    
    bool ConsumableBlocks_exists() const
    {
        const size_t n = offsetof(Self, ConsumableBlocks);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void ConsumableBlocks_clear()
    {
        const size_t n = offsetof(Self, ConsumableBlocks);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.IsBasedOnUnderlyingRedundancy
    //
    
    const Field<Boolean>& IsBasedOnUnderlyingRedundancy() const
    {
        const size_t n = offsetof(Self, IsBasedOnUnderlyingRedundancy);
        return GetField<Boolean>(n);
    }
    
    void IsBasedOnUnderlyingRedundancy(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, IsBasedOnUnderlyingRedundancy);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& IsBasedOnUnderlyingRedundancy_value() const
    {
        const size_t n = offsetof(Self, IsBasedOnUnderlyingRedundancy);
        return GetField<Boolean>(n).value;
    }
    
    void IsBasedOnUnderlyingRedundancy_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, IsBasedOnUnderlyingRedundancy);
        GetField<Boolean>(n).Set(x);
    }
    
    bool IsBasedOnUnderlyingRedundancy_exists() const
    {
        const size_t n = offsetof(Self, IsBasedOnUnderlyingRedundancy);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void IsBasedOnUnderlyingRedundancy_clear()
    {
        const size_t n = offsetof(Self, IsBasedOnUnderlyingRedundancy);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.SequentialAccess
    //
    
    const Field<Boolean>& SequentialAccess() const
    {
        const size_t n = offsetof(Self, SequentialAccess);
        return GetField<Boolean>(n);
    }
    
    void SequentialAccess(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, SequentialAccess);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& SequentialAccess_value() const
    {
        const size_t n = offsetof(Self, SequentialAccess);
        return GetField<Boolean>(n).value;
    }
    
    void SequentialAccess_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, SequentialAccess);
        GetField<Boolean>(n).Set(x);
    }
    
    bool SequentialAccess_exists() const
    {
        const size_t n = offsetof(Self, SequentialAccess);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void SequentialAccess_clear()
    {
        const size_t n = offsetof(Self, SequentialAccess);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.ExtentStatus
    //
    
    const Field<Uint16A>& ExtentStatus() const
    {
        const size_t n = offsetof(Self, ExtentStatus);
        return GetField<Uint16A>(n);
    }
    
    void ExtentStatus(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, ExtentStatus);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& ExtentStatus_value() const
    {
        const size_t n = offsetof(Self, ExtentStatus);
        return GetField<Uint16A>(n).value;
    }
    
    void ExtentStatus_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, ExtentStatus);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool ExtentStatus_exists() const
    {
        const size_t n = offsetof(Self, ExtentStatus);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void ExtentStatus_clear()
    {
        const size_t n = offsetof(Self, ExtentStatus);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.NoSinglePointOfFailure
    //
    
    const Field<Boolean>& NoSinglePointOfFailure() const
    {
        const size_t n = offsetof(Self, NoSinglePointOfFailure);
        return GetField<Boolean>(n);
    }
    
    void NoSinglePointOfFailure(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, NoSinglePointOfFailure);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& NoSinglePointOfFailure_value() const
    {
        const size_t n = offsetof(Self, NoSinglePointOfFailure);
        return GetField<Boolean>(n).value;
    }
    
    void NoSinglePointOfFailure_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, NoSinglePointOfFailure);
        GetField<Boolean>(n).Set(x);
    }
    
    bool NoSinglePointOfFailure_exists() const
    {
        const size_t n = offsetof(Self, NoSinglePointOfFailure);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void NoSinglePointOfFailure_clear()
    {
        const size_t n = offsetof(Self, NoSinglePointOfFailure);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.DataRedundancy
    //
    
    const Field<Uint16>& DataRedundancy() const
    {
        const size_t n = offsetof(Self, DataRedundancy);
        return GetField<Uint16>(n);
    }
    
    void DataRedundancy(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, DataRedundancy);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& DataRedundancy_value() const
    {
        const size_t n = offsetof(Self, DataRedundancy);
        return GetField<Uint16>(n).value;
    }
    
    void DataRedundancy_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, DataRedundancy);
        GetField<Uint16>(n).Set(x);
    }
    
    bool DataRedundancy_exists() const
    {
        const size_t n = offsetof(Self, DataRedundancy);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void DataRedundancy_clear()
    {
        const size_t n = offsetof(Self, DataRedundancy);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.PackageRedundancy
    //
    
    const Field<Uint16>& PackageRedundancy() const
    {
        const size_t n = offsetof(Self, PackageRedundancy);
        return GetField<Uint16>(n);
    }
    
    void PackageRedundancy(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, PackageRedundancy);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& PackageRedundancy_value() const
    {
        const size_t n = offsetof(Self, PackageRedundancy);
        return GetField<Uint16>(n).value;
    }
    
    void PackageRedundancy_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, PackageRedundancy);
        GetField<Uint16>(n).Set(x);
    }
    
    bool PackageRedundancy_exists() const
    {
        const size_t n = offsetof(Self, PackageRedundancy);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void PackageRedundancy_clear()
    {
        const size_t n = offsetof(Self, PackageRedundancy);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.DeltaReservation
    //
    
    const Field<Uint8>& DeltaReservation() const
    {
        const size_t n = offsetof(Self, DeltaReservation);
        return GetField<Uint8>(n);
    }
    
    void DeltaReservation(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, DeltaReservation);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& DeltaReservation_value() const
    {
        const size_t n = offsetof(Self, DeltaReservation);
        return GetField<Uint8>(n).value;
    }
    
    void DeltaReservation_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, DeltaReservation);
        GetField<Uint8>(n).Set(x);
    }
    
    bool DeltaReservation_exists() const
    {
        const size_t n = offsetof(Self, DeltaReservation);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void DeltaReservation_clear()
    {
        const size_t n = offsetof(Self, DeltaReservation);
        GetField<Uint8>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.Primordial
    //
    
    const Field<Boolean>& Primordial() const
    {
        const size_t n = offsetof(Self, Primordial);
        return GetField<Boolean>(n);
    }
    
    void Primordial(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Primordial);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Primordial_value() const
    {
        const size_t n = offsetof(Self, Primordial);
        return GetField<Boolean>(n).value;
    }
    
    void Primordial_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Primordial);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Primordial_exists() const
    {
        const size_t n = offsetof(Self, Primordial);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Primordial_clear()
    {
        const size_t n = offsetof(Self, Primordial);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.NameFormat
    //
    
    const Field<Uint16>& NameFormat() const
    {
        const size_t n = offsetof(Self, NameFormat);
        return GetField<Uint16>(n);
    }
    
    void NameFormat(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, NameFormat);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& NameFormat_value() const
    {
        const size_t n = offsetof(Self, NameFormat);
        return GetField<Uint16>(n).value;
    }
    
    void NameFormat_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, NameFormat);
        GetField<Uint16>(n).Set(x);
    }
    
    bool NameFormat_exists() const
    {
        const size_t n = offsetof(Self, NameFormat);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void NameFormat_clear()
    {
        const size_t n = offsetof(Self, NameFormat);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.NameNamespace
    //
    
    const Field<Uint16>& NameNamespace() const
    {
        const size_t n = offsetof(Self, NameNamespace);
        return GetField<Uint16>(n);
    }
    
    void NameNamespace(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, NameNamespace);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& NameNamespace_value() const
    {
        const size_t n = offsetof(Self, NameNamespace);
        return GetField<Uint16>(n).value;
    }
    
    void NameNamespace_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, NameNamespace);
        GetField<Uint16>(n).Set(x);
    }
    
    bool NameNamespace_exists() const
    {
        const size_t n = offsetof(Self, NameNamespace);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void NameNamespace_clear()
    {
        const size_t n = offsetof(Self, NameNamespace);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.OtherNameNamespace
    //
    
    const Field<String>& OtherNameNamespace() const
    {
        const size_t n = offsetof(Self, OtherNameNamespace);
        return GetField<String>(n);
    }
    
    void OtherNameNamespace(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherNameNamespace);
        GetField<String>(n) = x;
    }
    
    const String& OtherNameNamespace_value() const
    {
        const size_t n = offsetof(Self, OtherNameNamespace);
        return GetField<String>(n).value;
    }
    
    void OtherNameNamespace_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherNameNamespace);
        GetField<String>(n).Set(x);
    }
    
    bool OtherNameNamespace_exists() const
    {
        const size_t n = offsetof(Self, OtherNameNamespace);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherNameNamespace_clear()
    {
        const size_t n = offsetof(Self, OtherNameNamespace);
        GetField<String>(n).Clear();
    }

    //
    // CIM_StorageExtent_Class.OtherNameFormat
    //
    
    const Field<String>& OtherNameFormat() const
    {
        const size_t n = offsetof(Self, OtherNameFormat);
        return GetField<String>(n);
    }
    
    void OtherNameFormat(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherNameFormat);
        GetField<String>(n) = x;
    }
    
    const String& OtherNameFormat_value() const
    {
        const size_t n = offsetof(Self, OtherNameFormat);
        return GetField<String>(n).value;
    }
    
    void OtherNameFormat_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherNameFormat);
        GetField<String>(n).Set(x);
    }
    
    bool OtherNameFormat_exists() const
    {
        const size_t n = offsetof(Self, OtherNameFormat);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherNameFormat_clear()
    {
        const size_t n = offsetof(Self, OtherNameFormat);
        GetField<String>(n).Clear();
    }
};

typedef Array<CIM_StorageExtent_Class> CIM_StorageExtent_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_StorageExtent_h */
