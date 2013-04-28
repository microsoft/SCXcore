/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_Memory_h
#define _SCX_Memory_h

#include <MI.h>
#include "CIM_Memory.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_Memory [SCX_Memory]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _SCX_Memory /* extends CIM_Memory */
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
    /* SCX_Memory properties */
}
SCX_Memory;

typedef struct _SCX_Memory_Ref
{
    SCX_Memory* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Memory_Ref;

typedef struct _SCX_Memory_ConstRef
{
    MI_CONST SCX_Memory* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Memory_ConstRef;

typedef struct _SCX_Memory_Array
{
    struct _SCX_Memory** data;
    MI_Uint32 size;
}
SCX_Memory_Array;

typedef struct _SCX_Memory_ConstArray
{
    struct _SCX_Memory MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_Memory_ConstArray;

typedef struct _SCX_Memory_ArrayRef
{
    SCX_Memory_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Memory_ArrayRef;

typedef struct _SCX_Memory_ConstArrayRef
{
    SCX_Memory_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Memory_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_Memory_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_Construct(
    SCX_Memory* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_Memory_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clone(
    const SCX_Memory* self,
    SCX_Memory** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_Memory_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_Memory_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Destruct(SCX_Memory* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Delete(SCX_Memory* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Post(
    const SCX_Memory* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_InstanceID(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_InstanceID(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_InstanceID(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Caption(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_Caption(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Caption(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Description(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_Description(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Description(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ElementName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_ElementName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ElementName(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_InstallDate(
    SCX_Memory* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_InstallDate(
    SCX_Memory* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Name(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_Name(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Name(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_OperationalStatus(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_OperationalStatus(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_OperationalStatus(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_StatusDescriptions(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_StatusDescriptions(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_StatusDescriptions(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Status(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_Status(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Status(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_HealthState(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_HealthState(
    SCX_Memory* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_CommunicationStatus(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_CommunicationStatus(
    SCX_Memory* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_DetailedStatus(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_DetailedStatus(
    SCX_Memory* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_OperatingStatus(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_OperatingStatus(
    SCX_Memory* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_PrimaryStatus(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_PrimaryStatus(
    SCX_Memory* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_EnabledState(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_EnabledState(
    SCX_Memory* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_OtherEnabledState(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_OtherEnabledState(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_OtherEnabledState(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_RequestedState(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_RequestedState(
    SCX_Memory* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_EnabledDefault(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_EnabledDefault(
    SCX_Memory* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_TimeOfLastStateChange(
    SCX_Memory* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_TimeOfLastStateChange(
    SCX_Memory* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_AvailableRequestedStates(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_AvailableRequestedStates(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_AvailableRequestedStates(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_TransitioningToState(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_TransitioningToState(
    SCX_Memory* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_SystemCreationClassName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_SystemCreationClassName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_SystemCreationClassName(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_SystemName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_SystemName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_SystemName(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_CreationClassName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_CreationClassName(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_CreationClassName(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_DeviceID(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_DeviceID(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_DeviceID(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_PowerManagementSupported(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_PowerManagementSupported(
    SCX_Memory* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_PowerManagementCapabilities(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_PowerManagementCapabilities(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_PowerManagementCapabilities(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Availability(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Availability(
    SCX_Memory* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_StatusInfo(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_StatusInfo(
    SCX_Memory* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_LastErrorCode(
    SCX_Memory* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_LastErrorCode(
    SCX_Memory* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorDescription(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_ErrorDescription(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorDescription(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorCleared(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorCleared(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_OtherIdentifyingInfo(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_OtherIdentifyingInfo(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_OtherIdentifyingInfo(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_PowerOnHours(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_PowerOnHours(
    SCX_Memory* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_TotalPowerOnHours(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_TotalPowerOnHours(
    SCX_Memory* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_IdentifyingDescriptions(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_IdentifyingDescriptions(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_IdentifyingDescriptions(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_AdditionalAvailability(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_AdditionalAvailability(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_AdditionalAvailability(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_MaxQuiesceTime(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_MaxQuiesceTime(
    SCX_Memory* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_DataOrganization(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataOrganization)->value = x;
    ((MI_Uint16Field*)&self->DataOrganization)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_DataOrganization(
    SCX_Memory* self)
{
    memset((void*)&self->DataOrganization, 0, sizeof(self->DataOrganization));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Purpose(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_Purpose(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Purpose(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Access(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Access)->value = x;
    ((MI_Uint16Field*)&self->Access)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Access(
    SCX_Memory* self)
{
    memset((void*)&self->Access, 0, sizeof(self->Access));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorMethodology(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_ErrorMethodology(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorMethodology(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_BlockSize(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockSize)->value = x;
    ((MI_Uint64Field*)&self->BlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_BlockSize(
    SCX_Memory* self)
{
    memset((void*)&self->BlockSize, 0, sizeof(self->BlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_NumberOfBlocks(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->NumberOfBlocks)->value = x;
    ((MI_Uint64Field*)&self->NumberOfBlocks)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_NumberOfBlocks(
    SCX_Memory* self)
{
    memset((void*)&self->NumberOfBlocks, 0, sizeof(self->NumberOfBlocks));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ConsumableBlocks(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ConsumableBlocks)->value = x;
    ((MI_Uint64Field*)&self->ConsumableBlocks)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ConsumableBlocks(
    SCX_Memory* self)
{
    memset((void*)&self->ConsumableBlocks, 0, sizeof(self->ConsumableBlocks));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_IsBasedOnUnderlyingRedundancy(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsBasedOnUnderlyingRedundancy)->value = x;
    ((MI_BooleanField*)&self->IsBasedOnUnderlyingRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_IsBasedOnUnderlyingRedundancy(
    SCX_Memory* self)
{
    memset((void*)&self->IsBasedOnUnderlyingRedundancy, 0, sizeof(self->IsBasedOnUnderlyingRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_SequentialAccess(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->SequentialAccess)->value = x;
    ((MI_BooleanField*)&self->SequentialAccess)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_SequentialAccess(
    SCX_Memory* self)
{
    memset((void*)&self->SequentialAccess, 0, sizeof(self->SequentialAccess));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ExtentStatus(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_ExtentStatus(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ExtentStatus(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        47);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_NoSinglePointOfFailure(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->NoSinglePointOfFailure)->value = x;
    ((MI_BooleanField*)&self->NoSinglePointOfFailure)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_NoSinglePointOfFailure(
    SCX_Memory* self)
{
    memset((void*)&self->NoSinglePointOfFailure, 0, sizeof(self->NoSinglePointOfFailure));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_DataRedundancy(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DataRedundancy)->value = x;
    ((MI_Uint16Field*)&self->DataRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_DataRedundancy(
    SCX_Memory* self)
{
    memset((void*)&self->DataRedundancy, 0, sizeof(self->DataRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_PackageRedundancy(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PackageRedundancy)->value = x;
    ((MI_Uint16Field*)&self->PackageRedundancy)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_PackageRedundancy(
    SCX_Memory* self)
{
    memset((void*)&self->PackageRedundancy, 0, sizeof(self->PackageRedundancy));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_DeltaReservation(
    SCX_Memory* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->DeltaReservation)->value = x;
    ((MI_Uint8Field*)&self->DeltaReservation)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_DeltaReservation(
    SCX_Memory* self)
{
    memset((void*)&self->DeltaReservation, 0, sizeof(self->DeltaReservation));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Primordial(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Primordial)->value = x;
    ((MI_BooleanField*)&self->Primordial)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Primordial(
    SCX_Memory* self)
{
    memset((void*)&self->Primordial, 0, sizeof(self->Primordial));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_NameFormat(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NameFormat)->value = x;
    ((MI_Uint16Field*)&self->NameFormat)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_NameFormat(
    SCX_Memory* self)
{
    memset((void*)&self->NameFormat, 0, sizeof(self->NameFormat));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_NameNamespace(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->NameNamespace)->value = x;
    ((MI_Uint16Field*)&self->NameNamespace)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_NameNamespace(
    SCX_Memory* self)
{
    memset((void*)&self->NameNamespace, 0, sizeof(self->NameNamespace));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_OtherNameNamespace(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_OtherNameNamespace(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        55,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_OtherNameNamespace(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        55);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_OtherNameFormat(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_OtherNameFormat(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        56,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_OtherNameFormat(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        56);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_Volatile(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Volatile)->value = x;
    ((MI_BooleanField*)&self->Volatile)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_Volatile(
    SCX_Memory* self)
{
    memset((void*)&self->Volatile, 0, sizeof(self->Volatile));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_StartingAddress(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->StartingAddress)->value = x;
    ((MI_Uint64Field*)&self->StartingAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_StartingAddress(
    SCX_Memory* self)
{
    memset((void*)&self->StartingAddress, 0, sizeof(self->StartingAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_EndingAddress(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->EndingAddress)->value = x;
    ((MI_Uint64Field*)&self->EndingAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_EndingAddress(
    SCX_Memory* self)
{
    memset((void*)&self->EndingAddress, 0, sizeof(self->EndingAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorInfo(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorInfo)->value = x;
    ((MI_Uint16Field*)&self->ErrorInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorInfo(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorInfo, 0, sizeof(self->ErrorInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_OtherErrorDescription(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        61,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_OtherErrorDescription(
    SCX_Memory* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        61,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_OtherErrorDescription(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        61);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_CorrectableError(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->CorrectableError)->value = x;
    ((MI_BooleanField*)&self->CorrectableError)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_CorrectableError(
    SCX_Memory* self)
{
    memset((void*)&self->CorrectableError, 0, sizeof(self->CorrectableError));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorTime(
    SCX_Memory* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->ErrorTime)->value = x;
    ((MI_DatetimeField*)&self->ErrorTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorTime(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorTime, 0, sizeof(self->ErrorTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorAccess(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorAccess)->value = x;
    ((MI_Uint16Field*)&self->ErrorAccess)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorAccess(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorAccess, 0, sizeof(self->ErrorAccess));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorTransferSize(
    SCX_Memory* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ErrorTransferSize)->value = x;
    ((MI_Uint32Field*)&self->ErrorTransferSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorTransferSize(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorTransferSize, 0, sizeof(self->ErrorTransferSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorData(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_ErrorData(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorData(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        66);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorDataOrder(
    SCX_Memory* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorDataOrder)->value = x;
    ((MI_Uint16Field*)&self->ErrorDataOrder)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorDataOrder(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorDataOrder, 0, sizeof(self->ErrorDataOrder));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorAddress(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ErrorAddress)->value = x;
    ((MI_Uint64Field*)&self->ErrorAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorAddress(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorAddress, 0, sizeof(self->ErrorAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_SystemLevelAddress(
    SCX_Memory* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->SystemLevelAddress)->value = x;
    ((MI_BooleanField*)&self->SystemLevelAddress)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_SystemLevelAddress(
    SCX_Memory* self)
{
    memset((void*)&self->SystemLevelAddress, 0, sizeof(self->SystemLevelAddress));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_ErrorResolution(
    SCX_Memory* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ErrorResolution)->value = x;
    ((MI_Uint64Field*)&self->ErrorResolution)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_ErrorResolution(
    SCX_Memory* self)
{
    memset((void*)&self->ErrorResolution, 0, sizeof(self->ErrorResolution));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Set_AdditionalErrorData(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPtr_AdditionalErrorData(
    SCX_Memory* self,
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

MI_INLINE MI_Result MI_CALL SCX_Memory_Clear_AdditionalErrorData(
    SCX_Memory* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        71);
}

/*
**==============================================================================
**
** SCX_Memory.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_Memory_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_Memory_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Construct(
    SCX_Memory_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Clone(
    const SCX_Memory_RequestStateChange* self,
    SCX_Memory_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Destruct(
    SCX_Memory_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Delete(
    SCX_Memory_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Post(
    const SCX_Memory_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Set_MIReturn(
    SCX_Memory_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Clear_MIReturn(
    SCX_Memory_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Set_RequestedState(
    SCX_Memory_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Clear_RequestedState(
    SCX_Memory_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Set_Job(
    SCX_Memory_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_SetPtr_Job(
    SCX_Memory_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Clear_Job(
    SCX_Memory_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Set_TimeoutPeriod(
    SCX_Memory_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RequestStateChange_Clear_TimeoutPeriod(
    SCX_Memory_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory.SetPowerState()
**
**==============================================================================
*/

typedef struct _SCX_Memory_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
SCX_Memory_SetPowerState;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_SetPowerState_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Construct(
    SCX_Memory_SetPowerState* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_SetPowerState_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Clone(
    const SCX_Memory_SetPowerState* self,
    SCX_Memory_SetPowerState** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Destruct(
    SCX_Memory_SetPowerState* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Delete(
    SCX_Memory_SetPowerState* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Post(
    const SCX_Memory_SetPowerState* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Set_MIReturn(
    SCX_Memory_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Clear_MIReturn(
    SCX_Memory_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Set_PowerState(
    SCX_Memory_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Clear_PowerState(
    SCX_Memory_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Set_Time(
    SCX_Memory_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SetPowerState_Clear_Time(
    SCX_Memory_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory.Reset()
**
**==============================================================================
*/

typedef struct _SCX_Memory_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_Memory_Reset;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_Reset_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_Reset_Construct(
    SCX_Memory_Reset* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_Reset_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Reset_Clone(
    const SCX_Memory_Reset* self,
    SCX_Memory_Reset** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Reset_Destruct(
    SCX_Memory_Reset* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Reset_Delete(
    SCX_Memory_Reset* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Reset_Post(
    const SCX_Memory_Reset* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Reset_Set_MIReturn(
    SCX_Memory_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_Reset_Clear_MIReturn(
    SCX_Memory_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory.EnableDevice()
**
**==============================================================================
*/

typedef struct _SCX_Memory_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
SCX_Memory_EnableDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_EnableDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Construct(
    SCX_Memory_EnableDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_EnableDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Clone(
    const SCX_Memory_EnableDevice* self,
    SCX_Memory_EnableDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Destruct(
    SCX_Memory_EnableDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Delete(
    SCX_Memory_EnableDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Post(
    const SCX_Memory_EnableDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Set_MIReturn(
    SCX_Memory_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Clear_MIReturn(
    SCX_Memory_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Set_Enabled(
    SCX_Memory_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_EnableDevice_Clear_Enabled(
    SCX_Memory_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory.OnlineDevice()
**
**==============================================================================
*/

typedef struct _SCX_Memory_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
SCX_Memory_OnlineDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_OnlineDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Construct(
    SCX_Memory_OnlineDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_OnlineDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Clone(
    const SCX_Memory_OnlineDevice* self,
    SCX_Memory_OnlineDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Destruct(
    SCX_Memory_OnlineDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Delete(
    SCX_Memory_OnlineDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Post(
    const SCX_Memory_OnlineDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Set_MIReturn(
    SCX_Memory_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Clear_MIReturn(
    SCX_Memory_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Set_Online(
    SCX_Memory_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_OnlineDevice_Clear_Online(
    SCX_Memory_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _SCX_Memory_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
SCX_Memory_QuiesceDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_QuiesceDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Construct(
    SCX_Memory_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_QuiesceDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Clone(
    const SCX_Memory_QuiesceDevice* self,
    SCX_Memory_QuiesceDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Destruct(
    SCX_Memory_QuiesceDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Delete(
    SCX_Memory_QuiesceDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Post(
    const SCX_Memory_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Set_MIReturn(
    SCX_Memory_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Clear_MIReturn(
    SCX_Memory_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Set_Quiesce(
    SCX_Memory_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_QuiesceDevice_Clear_Quiesce(
    SCX_Memory_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory.SaveProperties()
**
**==============================================================================
*/

typedef struct _SCX_Memory_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_Memory_SaveProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_SaveProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_SaveProperties_Construct(
    SCX_Memory_SaveProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_SaveProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SaveProperties_Clone(
    const SCX_Memory_SaveProperties* self,
    SCX_Memory_SaveProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SaveProperties_Destruct(
    SCX_Memory_SaveProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SaveProperties_Delete(
    SCX_Memory_SaveProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SaveProperties_Post(
    const SCX_Memory_SaveProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SaveProperties_Set_MIReturn(
    SCX_Memory_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_SaveProperties_Clear_MIReturn(
    SCX_Memory_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory.RestoreProperties()
**
**==============================================================================
*/

typedef struct _SCX_Memory_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_Memory_RestoreProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Memory_RestoreProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_Memory_RestoreProperties_Construct(
    SCX_Memory_RestoreProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Memory_RestoreProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RestoreProperties_Clone(
    const SCX_Memory_RestoreProperties* self,
    SCX_Memory_RestoreProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RestoreProperties_Destruct(
    SCX_Memory_RestoreProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RestoreProperties_Delete(
    SCX_Memory_RestoreProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RestoreProperties_Post(
    const SCX_Memory_RestoreProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RestoreProperties_Set_MIReturn(
    SCX_Memory_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Memory_RestoreProperties_Clear_MIReturn(
    SCX_Memory_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Memory provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_Memory_Self SCX_Memory_Self;

MI_EXTERN_C void MI_CALL SCX_Memory_Load(
    SCX_Memory_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Memory_Unload(
    SCX_Memory_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Memory_EnumerateInstances(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_Memory_GetInstance(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Memory* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Memory_CreateInstance(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Memory* newInstance);

MI_EXTERN_C void MI_CALL SCX_Memory_ModifyInstance(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Memory* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Memory_DeleteInstance(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Memory* instanceName);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_RequestStateChange(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_RequestStateChange* in);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_SetPowerState(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_SetPowerState* in);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_Reset(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_Reset* in);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_EnableDevice(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_EnableDevice* in);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_OnlineDevice(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_OnlineDevice* in);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_QuiesceDevice(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_QuiesceDevice* in);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_SaveProperties(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_SaveProperties* in);

MI_EXTERN_C void MI_CALL SCX_Memory_Invoke_RestoreProperties(
    SCX_Memory_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Memory* instanceName,
    const SCX_Memory_RestoreProperties* in);


/*
**==============================================================================
**
** SCX_Memory_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_Memory_Class : public CIM_Memory_Class
{
public:
    
    typedef SCX_Memory Self;
    
    SCX_Memory_Class() :
        CIM_Memory_Class(&SCX_Memory_rtti)
    {
    }
    
    SCX_Memory_Class(
        const SCX_Memory* instanceName,
        bool keysOnly) :
        CIM_Memory_Class(
            &SCX_Memory_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_Memory_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_Class(
        const MI_ClassDecl* clDecl) :
        CIM_Memory_Class(clDecl)
    {
    }
    
    SCX_Memory_Class& operator=(
        const SCX_Memory_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_Class(
        const SCX_Memory_Class& x) :
        CIM_Memory_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_Memory_rtti;
    }

};

typedef Array<SCX_Memory_Class> SCX_Memory_ClassA;

class SCX_Memory_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_Memory_RequestStateChange Self;
    
    SCX_Memory_RequestStateChange_Class() :
        Instance(&SCX_Memory_RequestStateChange_rtti)
    {
    }
    
    SCX_Memory_RequestStateChange_Class(
        const SCX_Memory_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_RequestStateChange_Class& operator=(
        const SCX_Memory_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_RequestStateChange_Class(
        const SCX_Memory_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_RequestStateChange_Class.MIReturn
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
    // SCX_Memory_RequestStateChange_Class.RequestedState
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
    // SCX_Memory_RequestStateChange_Class.Job
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
    // SCX_Memory_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<SCX_Memory_RequestStateChange_Class> SCX_Memory_RequestStateChange_ClassA;

class SCX_Memory_SetPowerState_Class : public Instance
{
public:
    
    typedef SCX_Memory_SetPowerState Self;
    
    SCX_Memory_SetPowerState_Class() :
        Instance(&SCX_Memory_SetPowerState_rtti)
    {
    }
    
    SCX_Memory_SetPowerState_Class(
        const SCX_Memory_SetPowerState* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_SetPowerState_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_SetPowerState_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_SetPowerState_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_SetPowerState_Class& operator=(
        const SCX_Memory_SetPowerState_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_SetPowerState_Class(
        const SCX_Memory_SetPowerState_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_SetPowerState_Class.MIReturn
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
    // SCX_Memory_SetPowerState_Class.PowerState
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
    // SCX_Memory_SetPowerState_Class.Time
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

typedef Array<SCX_Memory_SetPowerState_Class> SCX_Memory_SetPowerState_ClassA;

class SCX_Memory_Reset_Class : public Instance
{
public:
    
    typedef SCX_Memory_Reset Self;
    
    SCX_Memory_Reset_Class() :
        Instance(&SCX_Memory_Reset_rtti)
    {
    }
    
    SCX_Memory_Reset_Class(
        const SCX_Memory_Reset* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_Reset_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_Reset_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_Reset_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_Reset_Class& operator=(
        const SCX_Memory_Reset_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_Reset_Class(
        const SCX_Memory_Reset_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_Reset_Class.MIReturn
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

typedef Array<SCX_Memory_Reset_Class> SCX_Memory_Reset_ClassA;

class SCX_Memory_EnableDevice_Class : public Instance
{
public:
    
    typedef SCX_Memory_EnableDevice Self;
    
    SCX_Memory_EnableDevice_Class() :
        Instance(&SCX_Memory_EnableDevice_rtti)
    {
    }
    
    SCX_Memory_EnableDevice_Class(
        const SCX_Memory_EnableDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_EnableDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_EnableDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_EnableDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_EnableDevice_Class& operator=(
        const SCX_Memory_EnableDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_EnableDevice_Class(
        const SCX_Memory_EnableDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_EnableDevice_Class.MIReturn
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
    // SCX_Memory_EnableDevice_Class.Enabled
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

typedef Array<SCX_Memory_EnableDevice_Class> SCX_Memory_EnableDevice_ClassA;

class SCX_Memory_OnlineDevice_Class : public Instance
{
public:
    
    typedef SCX_Memory_OnlineDevice Self;
    
    SCX_Memory_OnlineDevice_Class() :
        Instance(&SCX_Memory_OnlineDevice_rtti)
    {
    }
    
    SCX_Memory_OnlineDevice_Class(
        const SCX_Memory_OnlineDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_OnlineDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_OnlineDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_OnlineDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_OnlineDevice_Class& operator=(
        const SCX_Memory_OnlineDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_OnlineDevice_Class(
        const SCX_Memory_OnlineDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_OnlineDevice_Class.MIReturn
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
    // SCX_Memory_OnlineDevice_Class.Online
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

typedef Array<SCX_Memory_OnlineDevice_Class> SCX_Memory_OnlineDevice_ClassA;

class SCX_Memory_QuiesceDevice_Class : public Instance
{
public:
    
    typedef SCX_Memory_QuiesceDevice Self;
    
    SCX_Memory_QuiesceDevice_Class() :
        Instance(&SCX_Memory_QuiesceDevice_rtti)
    {
    }
    
    SCX_Memory_QuiesceDevice_Class(
        const SCX_Memory_QuiesceDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_QuiesceDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_QuiesceDevice_Class& operator=(
        const SCX_Memory_QuiesceDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_QuiesceDevice_Class(
        const SCX_Memory_QuiesceDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_QuiesceDevice_Class.MIReturn
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
    // SCX_Memory_QuiesceDevice_Class.Quiesce
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

typedef Array<SCX_Memory_QuiesceDevice_Class> SCX_Memory_QuiesceDevice_ClassA;

class SCX_Memory_SaveProperties_Class : public Instance
{
public:
    
    typedef SCX_Memory_SaveProperties Self;
    
    SCX_Memory_SaveProperties_Class() :
        Instance(&SCX_Memory_SaveProperties_rtti)
    {
    }
    
    SCX_Memory_SaveProperties_Class(
        const SCX_Memory_SaveProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_SaveProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_SaveProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_SaveProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_SaveProperties_Class& operator=(
        const SCX_Memory_SaveProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_SaveProperties_Class(
        const SCX_Memory_SaveProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_SaveProperties_Class.MIReturn
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

typedef Array<SCX_Memory_SaveProperties_Class> SCX_Memory_SaveProperties_ClassA;

class SCX_Memory_RestoreProperties_Class : public Instance
{
public:
    
    typedef SCX_Memory_RestoreProperties Self;
    
    SCX_Memory_RestoreProperties_Class() :
        Instance(&SCX_Memory_RestoreProperties_rtti)
    {
    }
    
    SCX_Memory_RestoreProperties_Class(
        const SCX_Memory_RestoreProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Memory_RestoreProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Memory_RestoreProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Memory_RestoreProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Memory_RestoreProperties_Class& operator=(
        const SCX_Memory_RestoreProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Memory_RestoreProperties_Class(
        const SCX_Memory_RestoreProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Memory_RestoreProperties_Class.MIReturn
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

typedef Array<SCX_Memory_RestoreProperties_Class> SCX_Memory_RestoreProperties_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_Memory_h */
