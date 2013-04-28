/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_Memory_h
#define _CIM_Memory_h

#include <MI.h>
#include "CIM_StorageExtent.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_Memory [CIM_Memory]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _CIM_Memory /* extends CIM_StorageExtent */
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
    /* CIM_Memory properties */
    MI_ConstBooleanField Volatile;
    MI_ConstUint64Field StartingAddress;
    MI_ConstUint64Field EndingAddress;
    MI_ConstUint16Field ErrorInfo;
    MI_ConstStringField OtherErrorDescription;
    MI_ConstBooleanField CorrectableError;
    MI_ConstDatetimeField ErrorTime;
    MI_ConstUint16Field ErrorAccess;
    MI_ConstUint32Field ErrorTransferSize;
    MI_ConstUint8AField ErrorData;
    MI_ConstUint16Field ErrorDataOrder;
    MI_ConstUint64Field ErrorAddress;
    MI_ConstBooleanField SystemLevelAddress;
    MI_ConstUint64Field ErrorResolution;
    MI_ConstUint8AField AdditionalErrorData;
}
CIM_Memory;

typedef struct _CIM_Memory_Ref
{
    CIM_Memory* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Memory_Ref;

typedef struct _CIM_Memory_ConstRef
{
    MI_CONST CIM_Memory* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Memory_ConstRef;

typedef struct _CIM_Memory_Array
{
    struct _CIM_Memory** data;
    MI_Uint32 size;
}
CIM_Memory_Array;

typedef struct _CIM_Memory_ConstArray
{
    struct _CIM_Memory MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_Memory_ConstArray;

typedef struct _CIM_Memory_ArrayRef
{
    CIM_Memory_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Memory_ArrayRef;

typedef struct _CIM_Memory_ConstArrayRef
{
    CIM_Memory_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Memory_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_Memory_rtti;

MI_INLINE MI_Result MI_CALL CIM_Memory_Construct(
    CIM_Memory* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_Memory_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clone(
    const CIM_Memory* self,
    CIM_Memory** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_Memory_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_Memory_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Destruct(CIM_Memory* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Delete(CIM_Memory* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Post(
    const CIM_Memory* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_InstanceID(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_InstanceID(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_InstanceID(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Caption(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_Caption(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Caption(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Description(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_Description(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Description(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ElementName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_ElementName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ElementName(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_InstallDate(
    CIM_Memory* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_InstallDate(
    CIM_Memory* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Name(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_Name(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Name(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_OperationalStatus(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_OperationalStatus(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_OperationalStatus(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_StatusDescriptions(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_StatusDescriptions(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_StatusDescriptions(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Status(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_Status(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Status(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_HealthState(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_HealthState(
    CIM_Memory* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_CommunicationStatus(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_CommunicationStatus(
    CIM_Memory* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_DetailedStatus(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_DetailedStatus(
    CIM_Memory* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_OperatingStatus(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_OperatingStatus(
    CIM_Memory* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_PrimaryStatus(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_PrimaryStatus(
    CIM_Memory* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_EnabledState(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_EnabledState(
    CIM_Memory* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_OtherEnabledState(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_OtherEnabledState(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_OtherEnabledState(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_RequestedState(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_RequestedState(
    CIM_Memory* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_EnabledDefault(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_EnabledDefault(
    CIM_Memory* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_TimeOfLastStateChange(
    CIM_Memory* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_TimeOfLastStateChange(
    CIM_Memory* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_AvailableRequestedStates(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_AvailableRequestedStates(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_AvailableRequestedStates(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_TransitioningToState(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_TransitioningToState(
    CIM_Memory* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_SystemCreationClassName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_SystemCreationClassName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_SystemCreationClassName(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_SystemName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_SystemName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_SystemName(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_CreationClassName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_CreationClassName(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_CreationClassName(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_DeviceID(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_DeviceID(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_DeviceID(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_PowerManagementSupported(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_PowerManagementSupported(
    CIM_Memory* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_PowerManagementCapabilities(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_PowerManagementCapabilities(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_PowerManagementCapabilities(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Availability(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Availability(
    CIM_Memory* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_StatusInfo(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_StatusInfo(
    CIM_Memory* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_LastErrorCode(
    CIM_Memory* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_LastErrorCode(
    CIM_Memory* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorDescription(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_ErrorDescription(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorDescription(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorCleared(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorCleared(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_OtherIdentifyingInfo(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_OtherIdentifyingInfo(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_OtherIdentifyingInfo(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_PowerOnHours(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_PowerOnHours(
    CIM_Memory* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_TotalPowerOnHours(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_TotalPowerOnHours(
    CIM_Memory* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_IdentifyingDescriptions(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_IdentifyingDescriptions(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_IdentifyingDescriptions(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_AdditionalAvailability(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_AdditionalAvailability(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_AdditionalAvailability(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_MaxQuiesceTime(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_MaxQuiesceTime(
    CIM_Memory* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_DataOrganization(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataOrganization)->value = x;
    ((MI_Uint16Field*)&self->DataOrganization)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_DataOrganization(
    CIM_Memory* self)
{
    memset((void*)&self->DataOrganization, 0, sizeof(self->DataOrganization));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Purpose(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_Purpose(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Purpose(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Access(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Access)->value = x;
    ((MI_Uint16Field*)&self->Access)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Access(
    CIM_Memory* self)
{
    memset((void*)&self->Access, 0, sizeof(self->Access));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorMethodology(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_ErrorMethodology(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorMethodology(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_BlockSize(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockSize)->value = x;
    ((MI_Uint64Field*)&self->BlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_BlockSize(
    CIM_Memory* self)
{
    memset((void*)&self->BlockSize, 0, sizeof(self->BlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_NumberOfBlocks(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->NumberOfBlocks)->value = x;
    ((MI_Uint64Field*)&self->NumberOfBlocks)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_NumberOfBlocks(
    CIM_Memory* self)
{
    memset((void*)&self->NumberOfBlocks, 0, sizeof(self->NumberOfBlocks));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ConsumableBlocks(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ConsumableBlocks)->value = x;
    ((MI_Uint64Field*)&self->ConsumableBlocks)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ConsumableBlocks(
    CIM_Memory* self)
{
    memset((void*)&self->ConsumableBlocks, 0, sizeof(self->ConsumableBlocks));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_IsBasedOnUnderlyingRedundancy(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsBasedOnUnderlyingRedundancy)->value = x;
    ((MI_BooleanField*)&self->IsBasedOnUnderlyingRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_IsBasedOnUnderlyingRedundancy(
    CIM_Memory* self)
{
    memset((void*)&self->IsBasedOnUnderlyingRedundancy, 0, sizeof(self->IsBasedOnUnderlyingRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_SequentialAccess(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->SequentialAccess)->value = x;
    ((MI_BooleanField*)&self->SequentialAccess)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_SequentialAccess(
    CIM_Memory* self)
{
    memset((void*)&self->SequentialAccess, 0, sizeof(self->SequentialAccess));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ExtentStatus(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_ExtentStatus(
    CIM_Memory* self,
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

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ExtentStatus(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        47);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_NoSinglePointOfFailure(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->NoSinglePointOfFailure)->value = x;
    ((MI_BooleanField*)&self->NoSinglePointOfFailure)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_NoSinglePointOfFailure(
    CIM_Memory* self)
{
    memset((void*)&self->NoSinglePointOfFailure, 0, sizeof(self->NoSinglePointOfFailure));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_DataRedundancy(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataRedundancy)->value = x;
    ((MI_Uint16Field*)&self->DataRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_DataRedundancy(
    CIM_Memory* self)
{
    memset((void*)&self->DataRedundancy, 0, sizeof(self->DataRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_PackageRedundancy(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PackageRedundancy)->value = x;
    ((MI_Uint16Field*)&self->PackageRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_PackageRedundancy(
    CIM_Memory* self)
{
    memset((void*)&self->PackageRedundancy, 0, sizeof(self->PackageRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_DeltaReservation(
    CIM_Memory* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->DeltaReservation)->value = x;
    ((MI_Uint8Field*)&self->DeltaReservation)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_DeltaReservation(
    CIM_Memory* self)
{
    memset((void*)&self->DeltaReservation, 0, sizeof(self->DeltaReservation));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Primordial(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Primordial)->value = x;
    ((MI_BooleanField*)&self->Primordial)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Primordial(
    CIM_Memory* self)
{
    memset((void*)&self->Primordial, 0, sizeof(self->Primordial));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_NameFormat(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NameFormat)->value = x;
    ((MI_Uint16Field*)&self->NameFormat)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_NameFormat(
    CIM_Memory* self)
{
    memset((void*)&self->NameFormat, 0, sizeof(self->NameFormat));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_NameNamespace(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NameNamespace)->value = x;
    ((MI_Uint16Field*)&self->NameNamespace)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_NameNamespace(
    CIM_Memory* self)
{
    memset((void*)&self->NameNamespace, 0, sizeof(self->NameNamespace));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_OtherNameNamespace(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_OtherNameNamespace(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_OtherNameNamespace(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        55);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_OtherNameFormat(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_OtherNameFormat(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_OtherNameFormat(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        56);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_Volatile(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Volatile)->value = x;
    ((MI_BooleanField*)&self->Volatile)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_Volatile(
    CIM_Memory* self)
{
    memset((void*)&self->Volatile, 0, sizeof(self->Volatile));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_StartingAddress(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->StartingAddress)->value = x;
    ((MI_Uint64Field*)&self->StartingAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_StartingAddress(
    CIM_Memory* self)
{
    memset((void*)&self->StartingAddress, 0, sizeof(self->StartingAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_EndingAddress(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->EndingAddress)->value = x;
    ((MI_Uint64Field*)&self->EndingAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_EndingAddress(
    CIM_Memory* self)
{
    memset((void*)&self->EndingAddress, 0, sizeof(self->EndingAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorInfo(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorInfo)->value = x;
    ((MI_Uint16Field*)&self->ErrorInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorInfo(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorInfo, 0, sizeof(self->ErrorInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_OtherErrorDescription(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        61,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_OtherErrorDescription(
    CIM_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        61,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_OtherErrorDescription(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        61);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_CorrectableError(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->CorrectableError)->value = x;
    ((MI_BooleanField*)&self->CorrectableError)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_CorrectableError(
    CIM_Memory* self)
{
    memset((void*)&self->CorrectableError, 0, sizeof(self->CorrectableError));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorTime(
    CIM_Memory* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->ErrorTime)->value = x;
    ((MI_DatetimeField*)&self->ErrorTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorTime(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorTime, 0, sizeof(self->ErrorTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorAccess(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorAccess)->value = x;
    ((MI_Uint16Field*)&self->ErrorAccess)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorAccess(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorAccess, 0, sizeof(self->ErrorAccess));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorTransferSize(
    CIM_Memory* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ErrorTransferSize)->value = x;
    ((MI_Uint32Field*)&self->ErrorTransferSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorTransferSize(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorTransferSize, 0, sizeof(self->ErrorTransferSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorData(
    CIM_Memory* self,
    const MI_Uint8* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        66,
        (MI_Value*)&arr,
        MI_UINT8A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_ErrorData(
    CIM_Memory* self,
    const MI_Uint8* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        66,
        (MI_Value*)&arr,
        MI_UINT8A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorData(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        66);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorDataOrder(
    CIM_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorDataOrder)->value = x;
    ((MI_Uint16Field*)&self->ErrorDataOrder)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorDataOrder(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorDataOrder, 0, sizeof(self->ErrorDataOrder));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorAddress(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ErrorAddress)->value = x;
    ((MI_Uint64Field*)&self->ErrorAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorAddress(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorAddress, 0, sizeof(self->ErrorAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_SystemLevelAddress(
    CIM_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->SystemLevelAddress)->value = x;
    ((MI_BooleanField*)&self->SystemLevelAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_SystemLevelAddress(
    CIM_Memory* self)
{
    memset((void*)&self->SystemLevelAddress, 0, sizeof(self->SystemLevelAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_ErrorResolution(
    CIM_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ErrorResolution)->value = x;
    ((MI_Uint64Field*)&self->ErrorResolution)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_ErrorResolution(
    CIM_Memory* self)
{
    memset((void*)&self->ErrorResolution, 0, sizeof(self->ErrorResolution));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Set_AdditionalErrorData(
    CIM_Memory* self,
    const MI_Uint8* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        71,
        (MI_Value*)&arr,
        MI_UINT8A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPtr_AdditionalErrorData(
    CIM_Memory* self,
    const MI_Uint8* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        71,
        (MI_Value*)&arr,
        MI_UINT8A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Clear_AdditionalErrorData(
    CIM_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        71);
}

/*
**==============================================================================
**
** CIM_Memory.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_Memory_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_Memory_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Set_MIReturn(
    CIM_Memory_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Clear_MIReturn(
    CIM_Memory_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Set_RequestedState(
    CIM_Memory_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Clear_RequestedState(
    CIM_Memory_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Set_Job(
    CIM_Memory_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_SetPtr_Job(
    CIM_Memory_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Clear_Job(
    CIM_Memory_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Set_TimeoutPeriod(
    CIM_Memory_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RequestStateChange_Clear_TimeoutPeriod(
    CIM_Memory_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Memory.SetPowerState()
**
**==============================================================================
*/

typedef struct _CIM_Memory_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
CIM_Memory_SetPowerState;

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPowerState_Set_MIReturn(
    CIM_Memory_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPowerState_Clear_MIReturn(
    CIM_Memory_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPowerState_Set_PowerState(
    CIM_Memory_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPowerState_Clear_PowerState(
    CIM_Memory_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPowerState_Set_Time(
    CIM_Memory_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SetPowerState_Clear_Time(
    CIM_Memory_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Memory.Reset()
**
**==============================================================================
*/

typedef struct _CIM_Memory_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_Memory_Reset;

MI_INLINE MI_Result MI_CALL CIM_Memory_Reset_Set_MIReturn(
    CIM_Memory_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_Reset_Clear_MIReturn(
    CIM_Memory_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Memory.EnableDevice()
**
**==============================================================================
*/

typedef struct _CIM_Memory_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
CIM_Memory_EnableDevice;

MI_INLINE MI_Result MI_CALL CIM_Memory_EnableDevice_Set_MIReturn(
    CIM_Memory_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_EnableDevice_Clear_MIReturn(
    CIM_Memory_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_EnableDevice_Set_Enabled(
    CIM_Memory_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_EnableDevice_Clear_Enabled(
    CIM_Memory_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Memory.OnlineDevice()
**
**==============================================================================
*/

typedef struct _CIM_Memory_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
CIM_Memory_OnlineDevice;

MI_INLINE MI_Result MI_CALL CIM_Memory_OnlineDevice_Set_MIReturn(
    CIM_Memory_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_OnlineDevice_Clear_MIReturn(
    CIM_Memory_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_OnlineDevice_Set_Online(
    CIM_Memory_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_OnlineDevice_Clear_Online(
    CIM_Memory_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Memory.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _CIM_Memory_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
CIM_Memory_QuiesceDevice;

MI_INLINE MI_Result MI_CALL CIM_Memory_QuiesceDevice_Set_MIReturn(
    CIM_Memory_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_QuiesceDevice_Clear_MIReturn(
    CIM_Memory_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_QuiesceDevice_Set_Quiesce(
    CIM_Memory_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_QuiesceDevice_Clear_Quiesce(
    CIM_Memory_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Memory.SaveProperties()
**
**==============================================================================
*/

typedef struct _CIM_Memory_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_Memory_SaveProperties;

MI_INLINE MI_Result MI_CALL CIM_Memory_SaveProperties_Set_MIReturn(
    CIM_Memory_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_SaveProperties_Clear_MIReturn(
    CIM_Memory_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_Memory.RestoreProperties()
**
**==============================================================================
*/

typedef struct _CIM_Memory_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_Memory_RestoreProperties;

MI_INLINE MI_Result MI_CALL CIM_Memory_RestoreProperties_Set_MIReturn(
    CIM_Memory_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Memory_RestoreProperties_Clear_MIReturn(
    CIM_Memory_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_Memory_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_Memory_Class : public CIM_StorageExtent_Class
{
public:
    
    typedef CIM_Memory Self;
    
    CIM_Memory_Class() :
        CIM_StorageExtent_Class(&CIM_Memory_rtti)
    {
    }
    
    CIM_Memory_Class(
        const CIM_Memory* instanceName,
        bool keysOnly) :
        CIM_StorageExtent_Class(
            &CIM_Memory_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_Memory_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_StorageExtent_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_Memory_Class(
        const MI_ClassDecl* clDecl) :
        CIM_StorageExtent_Class(clDecl)
    {
    }
    
    CIM_Memory_Class& operator=(
        const CIM_Memory_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_Memory_Class(
        const CIM_Memory_Class& x) :
        CIM_StorageExtent_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_Memory_rtti;
    }

    //
    // CIM_Memory_Class.Volatile
    //
    
    const Field<Boolean>& Volatile() const
    {
        const size_t n = offsetof(Self, Volatile);
        return GetField<Boolean>(n);
    }
    
    void Volatile(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Volatile);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Volatile_value() const
    {
        const size_t n = offsetof(Self, Volatile);
        return GetField<Boolean>(n).value;
    }
    
    void Volatile_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Volatile);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Volatile_exists() const
    {
        const size_t n = offsetof(Self, Volatile);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Volatile_clear()
    {
        const size_t n = offsetof(Self, Volatile);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_Memory_Class.StartingAddress
    //
    
    const Field<Uint64>& StartingAddress() const
    {
        const size_t n = offsetof(Self, StartingAddress);
        return GetField<Uint64>(n);
    }
    
    void StartingAddress(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, StartingAddress);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& StartingAddress_value() const
    {
        const size_t n = offsetof(Self, StartingAddress);
        return GetField<Uint64>(n).value;
    }
    
    void StartingAddress_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, StartingAddress);
        GetField<Uint64>(n).Set(x);
    }
    
    bool StartingAddress_exists() const
    {
        const size_t n = offsetof(Self, StartingAddress);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void StartingAddress_clear()
    {
        const size_t n = offsetof(Self, StartingAddress);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_Memory_Class.EndingAddress
    //
    
    const Field<Uint64>& EndingAddress() const
    {
        const size_t n = offsetof(Self, EndingAddress);
        return GetField<Uint64>(n);
    }
    
    void EndingAddress(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, EndingAddress);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& EndingAddress_value() const
    {
        const size_t n = offsetof(Self, EndingAddress);
        return GetField<Uint64>(n).value;
    }
    
    void EndingAddress_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, EndingAddress);
        GetField<Uint64>(n).Set(x);
    }
    
    bool EndingAddress_exists() const
    {
        const size_t n = offsetof(Self, EndingAddress);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void EndingAddress_clear()
    {
        const size_t n = offsetof(Self, EndingAddress);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorInfo
    //
    
    const Field<Uint16>& ErrorInfo() const
    {
        const size_t n = offsetof(Self, ErrorInfo);
        return GetField<Uint16>(n);
    }
    
    void ErrorInfo(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, ErrorInfo);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& ErrorInfo_value() const
    {
        const size_t n = offsetof(Self, ErrorInfo);
        return GetField<Uint16>(n).value;
    }
    
    void ErrorInfo_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, ErrorInfo);
        GetField<Uint16>(n).Set(x);
    }
    
    bool ErrorInfo_exists() const
    {
        const size_t n = offsetof(Self, ErrorInfo);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void ErrorInfo_clear()
    {
        const size_t n = offsetof(Self, ErrorInfo);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Memory_Class.OtherErrorDescription
    //
    
    const Field<String>& OtherErrorDescription() const
    {
        const size_t n = offsetof(Self, OtherErrorDescription);
        return GetField<String>(n);
    }
    
    void OtherErrorDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherErrorDescription);
        GetField<String>(n) = x;
    }
    
    const String& OtherErrorDescription_value() const
    {
        const size_t n = offsetof(Self, OtherErrorDescription);
        return GetField<String>(n).value;
    }
    
    void OtherErrorDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherErrorDescription);
        GetField<String>(n).Set(x);
    }
    
    bool OtherErrorDescription_exists() const
    {
        const size_t n = offsetof(Self, OtherErrorDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherErrorDescription_clear()
    {
        const size_t n = offsetof(Self, OtherErrorDescription);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Memory_Class.CorrectableError
    //
    
    const Field<Boolean>& CorrectableError() const
    {
        const size_t n = offsetof(Self, CorrectableError);
        return GetField<Boolean>(n);
    }
    
    void CorrectableError(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, CorrectableError);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& CorrectableError_value() const
    {
        const size_t n = offsetof(Self, CorrectableError);
        return GetField<Boolean>(n).value;
    }
    
    void CorrectableError_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, CorrectableError);
        GetField<Boolean>(n).Set(x);
    }
    
    bool CorrectableError_exists() const
    {
        const size_t n = offsetof(Self, CorrectableError);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void CorrectableError_clear()
    {
        const size_t n = offsetof(Self, CorrectableError);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorTime
    //
    
    const Field<Datetime>& ErrorTime() const
    {
        const size_t n = offsetof(Self, ErrorTime);
        return GetField<Datetime>(n);
    }
    
    void ErrorTime(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, ErrorTime);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& ErrorTime_value() const
    {
        const size_t n = offsetof(Self, ErrorTime);
        return GetField<Datetime>(n).value;
    }
    
    void ErrorTime_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, ErrorTime);
        GetField<Datetime>(n).Set(x);
    }
    
    bool ErrorTime_exists() const
    {
        const size_t n = offsetof(Self, ErrorTime);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void ErrorTime_clear()
    {
        const size_t n = offsetof(Self, ErrorTime);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorAccess
    //
    
    const Field<Uint16>& ErrorAccess() const
    {
        const size_t n = offsetof(Self, ErrorAccess);
        return GetField<Uint16>(n);
    }
    
    void ErrorAccess(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, ErrorAccess);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& ErrorAccess_value() const
    {
        const size_t n = offsetof(Self, ErrorAccess);
        return GetField<Uint16>(n).value;
    }
    
    void ErrorAccess_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, ErrorAccess);
        GetField<Uint16>(n).Set(x);
    }
    
    bool ErrorAccess_exists() const
    {
        const size_t n = offsetof(Self, ErrorAccess);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void ErrorAccess_clear()
    {
        const size_t n = offsetof(Self, ErrorAccess);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorTransferSize
    //
    
    const Field<Uint32>& ErrorTransferSize() const
    {
        const size_t n = offsetof(Self, ErrorTransferSize);
        return GetField<Uint32>(n);
    }
    
    void ErrorTransferSize(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, ErrorTransferSize);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& ErrorTransferSize_value() const
    {
        const size_t n = offsetof(Self, ErrorTransferSize);
        return GetField<Uint32>(n).value;
    }
    
    void ErrorTransferSize_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, ErrorTransferSize);
        GetField<Uint32>(n).Set(x);
    }
    
    bool ErrorTransferSize_exists() const
    {
        const size_t n = offsetof(Self, ErrorTransferSize);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void ErrorTransferSize_clear()
    {
        const size_t n = offsetof(Self, ErrorTransferSize);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorData
    //
    
    const Field<Uint8A>& ErrorData() const
    {
        const size_t n = offsetof(Self, ErrorData);
        return GetField<Uint8A>(n);
    }
    
    void ErrorData(const Field<Uint8A>& x)
    {
        const size_t n = offsetof(Self, ErrorData);
        GetField<Uint8A>(n) = x;
    }
    
    const Uint8A& ErrorData_value() const
    {
        const size_t n = offsetof(Self, ErrorData);
        return GetField<Uint8A>(n).value;
    }
    
    void ErrorData_value(const Uint8A& x)
    {
        const size_t n = offsetof(Self, ErrorData);
        GetField<Uint8A>(n).Set(x);
    }
    
    bool ErrorData_exists() const
    {
        const size_t n = offsetof(Self, ErrorData);
        return GetField<Uint8A>(n).exists ? true : false;
    }
    
    void ErrorData_clear()
    {
        const size_t n = offsetof(Self, ErrorData);
        GetField<Uint8A>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorDataOrder
    //
    
    const Field<Uint16>& ErrorDataOrder() const
    {
        const size_t n = offsetof(Self, ErrorDataOrder);
        return GetField<Uint16>(n);
    }
    
    void ErrorDataOrder(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, ErrorDataOrder);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& ErrorDataOrder_value() const
    {
        const size_t n = offsetof(Self, ErrorDataOrder);
        return GetField<Uint16>(n).value;
    }
    
    void ErrorDataOrder_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, ErrorDataOrder);
        GetField<Uint16>(n).Set(x);
    }
    
    bool ErrorDataOrder_exists() const
    {
        const size_t n = offsetof(Self, ErrorDataOrder);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void ErrorDataOrder_clear()
    {
        const size_t n = offsetof(Self, ErrorDataOrder);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorAddress
    //
    
    const Field<Uint64>& ErrorAddress() const
    {
        const size_t n = offsetof(Self, ErrorAddress);
        return GetField<Uint64>(n);
    }
    
    void ErrorAddress(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, ErrorAddress);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& ErrorAddress_value() const
    {
        const size_t n = offsetof(Self, ErrorAddress);
        return GetField<Uint64>(n).value;
    }
    
    void ErrorAddress_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, ErrorAddress);
        GetField<Uint64>(n).Set(x);
    }
    
    bool ErrorAddress_exists() const
    {
        const size_t n = offsetof(Self, ErrorAddress);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void ErrorAddress_clear()
    {
        const size_t n = offsetof(Self, ErrorAddress);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_Memory_Class.SystemLevelAddress
    //
    
    const Field<Boolean>& SystemLevelAddress() const
    {
        const size_t n = offsetof(Self, SystemLevelAddress);
        return GetField<Boolean>(n);
    }
    
    void SystemLevelAddress(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, SystemLevelAddress);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& SystemLevelAddress_value() const
    {
        const size_t n = offsetof(Self, SystemLevelAddress);
        return GetField<Boolean>(n).value;
    }
    
    void SystemLevelAddress_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, SystemLevelAddress);
        GetField<Boolean>(n).Set(x);
    }
    
    bool SystemLevelAddress_exists() const
    {
        const size_t n = offsetof(Self, SystemLevelAddress);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void SystemLevelAddress_clear()
    {
        const size_t n = offsetof(Self, SystemLevelAddress);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_Memory_Class.ErrorResolution
    //
    
    const Field<Uint64>& ErrorResolution() const
    {
        const size_t n = offsetof(Self, ErrorResolution);
        return GetField<Uint64>(n);
    }
    
    void ErrorResolution(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, ErrorResolution);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& ErrorResolution_value() const
    {
        const size_t n = offsetof(Self, ErrorResolution);
        return GetField<Uint64>(n).value;
    }
    
    void ErrorResolution_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, ErrorResolution);
        GetField<Uint64>(n).Set(x);
    }
    
    bool ErrorResolution_exists() const
    {
        const size_t n = offsetof(Self, ErrorResolution);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void ErrorResolution_clear()
    {
        const size_t n = offsetof(Self, ErrorResolution);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_Memory_Class.AdditionalErrorData
    //
    
    const Field<Uint8A>& AdditionalErrorData() const
    {
        const size_t n = offsetof(Self, AdditionalErrorData);
        return GetField<Uint8A>(n);
    }
    
    void AdditionalErrorData(const Field<Uint8A>& x)
    {
        const size_t n = offsetof(Self, AdditionalErrorData);
        GetField<Uint8A>(n) = x;
    }
    
    const Uint8A& AdditionalErrorData_value() const
    {
        const size_t n = offsetof(Self, AdditionalErrorData);
        return GetField<Uint8A>(n).value;
    }
    
    void AdditionalErrorData_value(const Uint8A& x)
    {
        const size_t n = offsetof(Self, AdditionalErrorData);
        GetField<Uint8A>(n).Set(x);
    }
    
    bool AdditionalErrorData_exists() const
    {
        const size_t n = offsetof(Self, AdditionalErrorData);
        return GetField<Uint8A>(n).exists ? true : false;
    }
    
    void AdditionalErrorData_clear()
    {
        const size_t n = offsetof(Self, AdditionalErrorData);
        GetField<Uint8A>(n).Clear();
    }
};

typedef Array<CIM_Memory_Class> CIM_Memory_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_Memory_h */
