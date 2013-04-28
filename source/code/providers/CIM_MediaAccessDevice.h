/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_MediaAccessDevice_h
#define _CIM_MediaAccessDevice_h

#include <MI.h>
#include "CIM_LogicalDevice.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_MediaAccessDevice [CIM_MediaAccessDevice]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice /* extends CIM_LogicalDevice */
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
    /* CIM_MediaAccessDevice properties */
    MI_ConstUint16AField Capabilities;
    MI_ConstStringAField CapabilityDescriptions;
    MI_ConstStringField ErrorMethodology;
    MI_ConstStringField CompressionMethod;
    MI_ConstUint32Field NumberOfMediaSupported;
    MI_ConstUint64Field MaxMediaSize;
    MI_ConstUint64Field DefaultBlockSize;
    MI_ConstUint64Field MaxBlockSize;
    MI_ConstUint64Field MinBlockSize;
    MI_ConstBooleanField NeedsCleaning;
    MI_ConstBooleanField MediaIsLocked;
    MI_ConstUint16Field Security;
    MI_ConstDatetimeField LastCleaned;
    MI_ConstUint64Field MaxAccessTime;
    MI_ConstUint32Field UncompressedDataRate;
    MI_ConstUint64Field LoadTime;
    MI_ConstUint64Field UnloadTime;
    MI_ConstUint64Field MountCount;
    MI_ConstDatetimeField TimeOfLastMount;
    MI_ConstUint64Field TotalMountTime;
    MI_ConstStringField UnitsDescription;
    MI_ConstUint64Field MaxUnitsBeforeCleaning;
    MI_ConstUint64Field UnitsUsed;
}
CIM_MediaAccessDevice;

typedef struct _CIM_MediaAccessDevice_Ref
{
    CIM_MediaAccessDevice* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_MediaAccessDevice_Ref;

typedef struct _CIM_MediaAccessDevice_ConstRef
{
    MI_CONST CIM_MediaAccessDevice* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_MediaAccessDevice_ConstRef;

typedef struct _CIM_MediaAccessDevice_Array
{
    struct _CIM_MediaAccessDevice** data;
    MI_Uint32 size;
}
CIM_MediaAccessDevice_Array;

typedef struct _CIM_MediaAccessDevice_ConstArray
{
    struct _CIM_MediaAccessDevice MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_MediaAccessDevice_ConstArray;

typedef struct _CIM_MediaAccessDevice_ArrayRef
{
    CIM_MediaAccessDevice_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_MediaAccessDevice_ArrayRef;

typedef struct _CIM_MediaAccessDevice_ConstArrayRef
{
    CIM_MediaAccessDevice_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_MediaAccessDevice_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_MediaAccessDevice_rtti;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Construct(
    CIM_MediaAccessDevice* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_MediaAccessDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clone(
    const CIM_MediaAccessDevice* self,
    CIM_MediaAccessDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_MediaAccessDevice_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_MediaAccessDevice_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Destruct(CIM_MediaAccessDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Delete(CIM_MediaAccessDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Post(
    const CIM_MediaAccessDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_InstanceID(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_InstanceID(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_InstanceID(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_Caption(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_Caption(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_Caption(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_Description(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_Description(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_Description(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_ElementName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_ElementName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_ElementName(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_InstallDate(
    CIM_MediaAccessDevice* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_InstallDate(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_Name(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_Name(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_Name(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_OperationalStatus(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_OperationalStatus(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_OperationalStatus(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_StatusDescriptions(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_StatusDescriptions(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_StatusDescriptions(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_Status(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_Status(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_Status(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_HealthState(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_HealthState(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_CommunicationStatus(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_CommunicationStatus(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_DetailedStatus(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_DetailedStatus(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_OperatingStatus(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_OperatingStatus(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_PrimaryStatus(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_PrimaryStatus(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_EnabledState(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_EnabledState(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_OtherEnabledState(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_OtherEnabledState(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_OtherEnabledState(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_RequestedState(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_RequestedState(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_EnabledDefault(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_EnabledDefault(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_TimeOfLastStateChange(
    CIM_MediaAccessDevice* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_TimeOfLastStateChange(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_AvailableRequestedStates(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_AvailableRequestedStates(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_AvailableRequestedStates(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_TransitioningToState(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_TransitioningToState(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_SystemCreationClassName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_SystemCreationClassName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_SystemCreationClassName(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_SystemName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_SystemName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_SystemName(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_CreationClassName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_CreationClassName(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_CreationClassName(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_DeviceID(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_DeviceID(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_DeviceID(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_PowerManagementSupported(
    CIM_MediaAccessDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_PowerManagementSupported(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_PowerManagementCapabilities(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_PowerManagementCapabilities(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_PowerManagementCapabilities(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_Availability(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_Availability(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_StatusInfo(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_StatusInfo(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_LastErrorCode(
    CIM_MediaAccessDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_LastErrorCode(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_ErrorDescription(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_ErrorDescription(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_ErrorDescription(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_ErrorCleared(
    CIM_MediaAccessDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_ErrorCleared(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_OtherIdentifyingInfo(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_OtherIdentifyingInfo(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_OtherIdentifyingInfo(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_PowerOnHours(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_PowerOnHours(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_TotalPowerOnHours(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_TotalPowerOnHours(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_IdentifyingDescriptions(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_IdentifyingDescriptions(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_IdentifyingDescriptions(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_AdditionalAvailability(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_AdditionalAvailability(
    CIM_MediaAccessDevice* self,
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

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_AdditionalAvailability(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MaxQuiesceTime(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MaxQuiesceTime(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_Capabilities(
    CIM_MediaAccessDevice* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_Capabilities(
    CIM_MediaAccessDevice* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_Capabilities(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_CapabilityDescriptions(
    CIM_MediaAccessDevice* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_CapabilityDescriptions(
    CIM_MediaAccessDevice* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        39,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_CapabilityDescriptions(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_ErrorMethodology(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_ErrorMethodology(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_ErrorMethodology(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        40);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_CompressionMethod(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_CompressionMethod(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_CompressionMethod(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_NumberOfMediaSupported(
    CIM_MediaAccessDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfMediaSupported)->value = x;
    ((MI_Uint32Field*)&self->NumberOfMediaSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_NumberOfMediaSupported(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->NumberOfMediaSupported, 0, sizeof(self->NumberOfMediaSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MaxMediaSize(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxMediaSize)->value = x;
    ((MI_Uint64Field*)&self->MaxMediaSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MaxMediaSize(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MaxMediaSize, 0, sizeof(self->MaxMediaSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_DefaultBlockSize(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->DefaultBlockSize)->value = x;
    ((MI_Uint64Field*)&self->DefaultBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_DefaultBlockSize(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->DefaultBlockSize, 0, sizeof(self->DefaultBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MaxBlockSize(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxBlockSize)->value = x;
    ((MI_Uint64Field*)&self->MaxBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MaxBlockSize(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MaxBlockSize, 0, sizeof(self->MaxBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MinBlockSize(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MinBlockSize)->value = x;
    ((MI_Uint64Field*)&self->MinBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MinBlockSize(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MinBlockSize, 0, sizeof(self->MinBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_NeedsCleaning(
    CIM_MediaAccessDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->NeedsCleaning)->value = x;
    ((MI_BooleanField*)&self->NeedsCleaning)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_NeedsCleaning(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->NeedsCleaning, 0, sizeof(self->NeedsCleaning));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MediaIsLocked(
    CIM_MediaAccessDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MediaIsLocked)->value = x;
    ((MI_BooleanField*)&self->MediaIsLocked)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MediaIsLocked(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MediaIsLocked, 0, sizeof(self->MediaIsLocked));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_Security(
    CIM_MediaAccessDevice* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Security)->value = x;
    ((MI_Uint16Field*)&self->Security)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_Security(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->Security, 0, sizeof(self->Security));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_LastCleaned(
    CIM_MediaAccessDevice* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastCleaned)->value = x;
    ((MI_DatetimeField*)&self->LastCleaned)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_LastCleaned(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->LastCleaned, 0, sizeof(self->LastCleaned));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MaxAccessTime(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxAccessTime)->value = x;
    ((MI_Uint64Field*)&self->MaxAccessTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MaxAccessTime(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MaxAccessTime, 0, sizeof(self->MaxAccessTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_UncompressedDataRate(
    CIM_MediaAccessDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->UncompressedDataRate)->value = x;
    ((MI_Uint32Field*)&self->UncompressedDataRate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_UncompressedDataRate(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->UncompressedDataRate, 0, sizeof(self->UncompressedDataRate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_LoadTime(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->LoadTime)->value = x;
    ((MI_Uint64Field*)&self->LoadTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_LoadTime(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->LoadTime, 0, sizeof(self->LoadTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_UnloadTime(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UnloadTime)->value = x;
    ((MI_Uint64Field*)&self->UnloadTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_UnloadTime(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->UnloadTime, 0, sizeof(self->UnloadTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MountCount(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MountCount)->value = x;
    ((MI_Uint64Field*)&self->MountCount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MountCount(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MountCount, 0, sizeof(self->MountCount));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_TimeOfLastMount(
    CIM_MediaAccessDevice* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastMount)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastMount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_TimeOfLastMount(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->TimeOfLastMount, 0, sizeof(self->TimeOfLastMount));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_TotalMountTime(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalMountTime)->value = x;
    ((MI_Uint64Field*)&self->TotalMountTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_TotalMountTime(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->TotalMountTime, 0, sizeof(self->TotalMountTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_UnitsDescription(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPtr_UnitsDescription(
    CIM_MediaAccessDevice* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_UnitsDescription(
    CIM_MediaAccessDevice* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        58);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_MaxUnitsBeforeCleaning(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxUnitsBeforeCleaning)->value = x;
    ((MI_Uint64Field*)&self->MaxUnitsBeforeCleaning)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_MaxUnitsBeforeCleaning(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->MaxUnitsBeforeCleaning, 0, sizeof(self->MaxUnitsBeforeCleaning));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Set_UnitsUsed(
    CIM_MediaAccessDevice* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UnitsUsed)->value = x;
    ((MI_Uint64Field*)&self->UnitsUsed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Clear_UnitsUsed(
    CIM_MediaAccessDevice* self)
{
    memset((void*)&self->UnitsUsed, 0, sizeof(self->UnitsUsed));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_MediaAccessDevice_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Set_MIReturn(
    CIM_MediaAccessDevice_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Clear_MIReturn(
    CIM_MediaAccessDevice_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Set_RequestedState(
    CIM_MediaAccessDevice_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Clear_RequestedState(
    CIM_MediaAccessDevice_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Set_Job(
    CIM_MediaAccessDevice_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_SetPtr_Job(
    CIM_MediaAccessDevice_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Clear_Job(
    CIM_MediaAccessDevice_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Set_TimeoutPeriod(
    CIM_MediaAccessDevice_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RequestStateChange_Clear_TimeoutPeriod(
    CIM_MediaAccessDevice_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.SetPowerState()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
CIM_MediaAccessDevice_SetPowerState;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPowerState_Set_MIReturn(
    CIM_MediaAccessDevice_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPowerState_Clear_MIReturn(
    CIM_MediaAccessDevice_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPowerState_Set_PowerState(
    CIM_MediaAccessDevice_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPowerState_Clear_PowerState(
    CIM_MediaAccessDevice_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPowerState_Set_Time(
    CIM_MediaAccessDevice_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SetPowerState_Clear_Time(
    CIM_MediaAccessDevice_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.Reset()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_MediaAccessDevice_Reset;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Reset_Set_MIReturn(
    CIM_MediaAccessDevice_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_Reset_Clear_MIReturn(
    CIM_MediaAccessDevice_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.EnableDevice()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
CIM_MediaAccessDevice_EnableDevice;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_EnableDevice_Set_MIReturn(
    CIM_MediaAccessDevice_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_EnableDevice_Clear_MIReturn(
    CIM_MediaAccessDevice_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_EnableDevice_Set_Enabled(
    CIM_MediaAccessDevice_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_EnableDevice_Clear_Enabled(
    CIM_MediaAccessDevice_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.OnlineDevice()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
CIM_MediaAccessDevice_OnlineDevice;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_OnlineDevice_Set_MIReturn(
    CIM_MediaAccessDevice_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_OnlineDevice_Clear_MIReturn(
    CIM_MediaAccessDevice_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_OnlineDevice_Set_Online(
    CIM_MediaAccessDevice_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_OnlineDevice_Clear_Online(
    CIM_MediaAccessDevice_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
CIM_MediaAccessDevice_QuiesceDevice;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_QuiesceDevice_Set_MIReturn(
    CIM_MediaAccessDevice_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_QuiesceDevice_Clear_MIReturn(
    CIM_MediaAccessDevice_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_QuiesceDevice_Set_Quiesce(
    CIM_MediaAccessDevice_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_QuiesceDevice_Clear_Quiesce(
    CIM_MediaAccessDevice_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.SaveProperties()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_MediaAccessDevice_SaveProperties;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SaveProperties_Set_MIReturn(
    CIM_MediaAccessDevice_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_SaveProperties_Clear_MIReturn(
    CIM_MediaAccessDevice_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.RestoreProperties()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_MediaAccessDevice_RestoreProperties;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RestoreProperties_Set_MIReturn(
    CIM_MediaAccessDevice_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_RestoreProperties_Clear_MIReturn(
    CIM_MediaAccessDevice_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_MediaAccessDevice.LockMedia()
**
**==============================================================================
*/

typedef struct _CIM_MediaAccessDevice_LockMedia
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Lock;
}
CIM_MediaAccessDevice_LockMedia;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_MediaAccessDevice_LockMedia_rtti;

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Construct(
    CIM_MediaAccessDevice_LockMedia* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_MediaAccessDevice_LockMedia_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Clone(
    const CIM_MediaAccessDevice_LockMedia* self,
    CIM_MediaAccessDevice_LockMedia** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Destruct(
    CIM_MediaAccessDevice_LockMedia* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Delete(
    CIM_MediaAccessDevice_LockMedia* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Post(
    const CIM_MediaAccessDevice_LockMedia* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Set_MIReturn(
    CIM_MediaAccessDevice_LockMedia* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Clear_MIReturn(
    CIM_MediaAccessDevice_LockMedia* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Set_Lock(
    CIM_MediaAccessDevice_LockMedia* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Lock)->value = x;
    ((MI_BooleanField*)&self->Lock)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_MediaAccessDevice_LockMedia_Clear_Lock(
    CIM_MediaAccessDevice_LockMedia* self)
{
    memset((void*)&self->Lock, 0, sizeof(self->Lock));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_MediaAccessDevice_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_MediaAccessDevice_Class : public CIM_LogicalDevice_Class
{
public:
    
    typedef CIM_MediaAccessDevice Self;
    
    CIM_MediaAccessDevice_Class() :
        CIM_LogicalDevice_Class(&CIM_MediaAccessDevice_rtti)
    {
    }
    
    CIM_MediaAccessDevice_Class(
        const CIM_MediaAccessDevice* instanceName,
        bool keysOnly) :
        CIM_LogicalDevice_Class(
            &CIM_MediaAccessDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_MediaAccessDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalDevice_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_MediaAccessDevice_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalDevice_Class(clDecl)
    {
    }
    
    CIM_MediaAccessDevice_Class& operator=(
        const CIM_MediaAccessDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_MediaAccessDevice_Class(
        const CIM_MediaAccessDevice_Class& x) :
        CIM_LogicalDevice_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_MediaAccessDevice_rtti;
    }

    //
    // CIM_MediaAccessDevice_Class.Capabilities
    //
    
    const Field<Uint16A>& Capabilities() const
    {
        const size_t n = offsetof(Self, Capabilities);
        return GetField<Uint16A>(n);
    }
    
    void Capabilities(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, Capabilities);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& Capabilities_value() const
    {
        const size_t n = offsetof(Self, Capabilities);
        return GetField<Uint16A>(n).value;
    }
    
    void Capabilities_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, Capabilities);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool Capabilities_exists() const
    {
        const size_t n = offsetof(Self, Capabilities);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void Capabilities_clear()
    {
        const size_t n = offsetof(Self, Capabilities);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.CapabilityDescriptions
    //
    
    const Field<StringA>& CapabilityDescriptions() const
    {
        const size_t n = offsetof(Self, CapabilityDescriptions);
        return GetField<StringA>(n);
    }
    
    void CapabilityDescriptions(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, CapabilityDescriptions);
        GetField<StringA>(n) = x;
    }
    
    const StringA& CapabilityDescriptions_value() const
    {
        const size_t n = offsetof(Self, CapabilityDescriptions);
        return GetField<StringA>(n).value;
    }
    
    void CapabilityDescriptions_value(const StringA& x)
    {
        const size_t n = offsetof(Self, CapabilityDescriptions);
        GetField<StringA>(n).Set(x);
    }
    
    bool CapabilityDescriptions_exists() const
    {
        const size_t n = offsetof(Self, CapabilityDescriptions);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void CapabilityDescriptions_clear()
    {
        const size_t n = offsetof(Self, CapabilityDescriptions);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.ErrorMethodology
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
    // CIM_MediaAccessDevice_Class.CompressionMethod
    //
    
    const Field<String>& CompressionMethod() const
    {
        const size_t n = offsetof(Self, CompressionMethod);
        return GetField<String>(n);
    }
    
    void CompressionMethod(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CompressionMethod);
        GetField<String>(n) = x;
    }
    
    const String& CompressionMethod_value() const
    {
        const size_t n = offsetof(Self, CompressionMethod);
        return GetField<String>(n).value;
    }
    
    void CompressionMethod_value(const String& x)
    {
        const size_t n = offsetof(Self, CompressionMethod);
        GetField<String>(n).Set(x);
    }
    
    bool CompressionMethod_exists() const
    {
        const size_t n = offsetof(Self, CompressionMethod);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CompressionMethod_clear()
    {
        const size_t n = offsetof(Self, CompressionMethod);
        GetField<String>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.NumberOfMediaSupported
    //
    
    const Field<Uint32>& NumberOfMediaSupported() const
    {
        const size_t n = offsetof(Self, NumberOfMediaSupported);
        return GetField<Uint32>(n);
    }
    
    void NumberOfMediaSupported(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, NumberOfMediaSupported);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& NumberOfMediaSupported_value() const
    {
        const size_t n = offsetof(Self, NumberOfMediaSupported);
        return GetField<Uint32>(n).value;
    }
    
    void NumberOfMediaSupported_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, NumberOfMediaSupported);
        GetField<Uint32>(n).Set(x);
    }
    
    bool NumberOfMediaSupported_exists() const
    {
        const size_t n = offsetof(Self, NumberOfMediaSupported);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void NumberOfMediaSupported_clear()
    {
        const size_t n = offsetof(Self, NumberOfMediaSupported);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.MaxMediaSize
    //
    
    const Field<Uint64>& MaxMediaSize() const
    {
        const size_t n = offsetof(Self, MaxMediaSize);
        return GetField<Uint64>(n);
    }
    
    void MaxMediaSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MaxMediaSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MaxMediaSize_value() const
    {
        const size_t n = offsetof(Self, MaxMediaSize);
        return GetField<Uint64>(n).value;
    }
    
    void MaxMediaSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MaxMediaSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MaxMediaSize_exists() const
    {
        const size_t n = offsetof(Self, MaxMediaSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MaxMediaSize_clear()
    {
        const size_t n = offsetof(Self, MaxMediaSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.DefaultBlockSize
    //
    
    const Field<Uint64>& DefaultBlockSize() const
    {
        const size_t n = offsetof(Self, DefaultBlockSize);
        return GetField<Uint64>(n);
    }
    
    void DefaultBlockSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, DefaultBlockSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& DefaultBlockSize_value() const
    {
        const size_t n = offsetof(Self, DefaultBlockSize);
        return GetField<Uint64>(n).value;
    }
    
    void DefaultBlockSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, DefaultBlockSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool DefaultBlockSize_exists() const
    {
        const size_t n = offsetof(Self, DefaultBlockSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void DefaultBlockSize_clear()
    {
        const size_t n = offsetof(Self, DefaultBlockSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.MaxBlockSize
    //
    
    const Field<Uint64>& MaxBlockSize() const
    {
        const size_t n = offsetof(Self, MaxBlockSize);
        return GetField<Uint64>(n);
    }
    
    void MaxBlockSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MaxBlockSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MaxBlockSize_value() const
    {
        const size_t n = offsetof(Self, MaxBlockSize);
        return GetField<Uint64>(n).value;
    }
    
    void MaxBlockSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MaxBlockSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MaxBlockSize_exists() const
    {
        const size_t n = offsetof(Self, MaxBlockSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MaxBlockSize_clear()
    {
        const size_t n = offsetof(Self, MaxBlockSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.MinBlockSize
    //
    
    const Field<Uint64>& MinBlockSize() const
    {
        const size_t n = offsetof(Self, MinBlockSize);
        return GetField<Uint64>(n);
    }
    
    void MinBlockSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MinBlockSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MinBlockSize_value() const
    {
        const size_t n = offsetof(Self, MinBlockSize);
        return GetField<Uint64>(n).value;
    }
    
    void MinBlockSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MinBlockSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MinBlockSize_exists() const
    {
        const size_t n = offsetof(Self, MinBlockSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MinBlockSize_clear()
    {
        const size_t n = offsetof(Self, MinBlockSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.NeedsCleaning
    //
    
    const Field<Boolean>& NeedsCleaning() const
    {
        const size_t n = offsetof(Self, NeedsCleaning);
        return GetField<Boolean>(n);
    }
    
    void NeedsCleaning(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, NeedsCleaning);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& NeedsCleaning_value() const
    {
        const size_t n = offsetof(Self, NeedsCleaning);
        return GetField<Boolean>(n).value;
    }
    
    void NeedsCleaning_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, NeedsCleaning);
        GetField<Boolean>(n).Set(x);
    }
    
    bool NeedsCleaning_exists() const
    {
        const size_t n = offsetof(Self, NeedsCleaning);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void NeedsCleaning_clear()
    {
        const size_t n = offsetof(Self, NeedsCleaning);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.MediaIsLocked
    //
    
    const Field<Boolean>& MediaIsLocked() const
    {
        const size_t n = offsetof(Self, MediaIsLocked);
        return GetField<Boolean>(n);
    }
    
    void MediaIsLocked(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, MediaIsLocked);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& MediaIsLocked_value() const
    {
        const size_t n = offsetof(Self, MediaIsLocked);
        return GetField<Boolean>(n).value;
    }
    
    void MediaIsLocked_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, MediaIsLocked);
        GetField<Boolean>(n).Set(x);
    }
    
    bool MediaIsLocked_exists() const
    {
        const size_t n = offsetof(Self, MediaIsLocked);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void MediaIsLocked_clear()
    {
        const size_t n = offsetof(Self, MediaIsLocked);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.Security
    //
    
    const Field<Uint16>& Security() const
    {
        const size_t n = offsetof(Self, Security);
        return GetField<Uint16>(n);
    }
    
    void Security(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, Security);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& Security_value() const
    {
        const size_t n = offsetof(Self, Security);
        return GetField<Uint16>(n).value;
    }
    
    void Security_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, Security);
        GetField<Uint16>(n).Set(x);
    }
    
    bool Security_exists() const
    {
        const size_t n = offsetof(Self, Security);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void Security_clear()
    {
        const size_t n = offsetof(Self, Security);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.LastCleaned
    //
    
    const Field<Datetime>& LastCleaned() const
    {
        const size_t n = offsetof(Self, LastCleaned);
        return GetField<Datetime>(n);
    }
    
    void LastCleaned(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, LastCleaned);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& LastCleaned_value() const
    {
        const size_t n = offsetof(Self, LastCleaned);
        return GetField<Datetime>(n).value;
    }
    
    void LastCleaned_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, LastCleaned);
        GetField<Datetime>(n).Set(x);
    }
    
    bool LastCleaned_exists() const
    {
        const size_t n = offsetof(Self, LastCleaned);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void LastCleaned_clear()
    {
        const size_t n = offsetof(Self, LastCleaned);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.MaxAccessTime
    //
    
    const Field<Uint64>& MaxAccessTime() const
    {
        const size_t n = offsetof(Self, MaxAccessTime);
        return GetField<Uint64>(n);
    }
    
    void MaxAccessTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MaxAccessTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MaxAccessTime_value() const
    {
        const size_t n = offsetof(Self, MaxAccessTime);
        return GetField<Uint64>(n).value;
    }
    
    void MaxAccessTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MaxAccessTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MaxAccessTime_exists() const
    {
        const size_t n = offsetof(Self, MaxAccessTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MaxAccessTime_clear()
    {
        const size_t n = offsetof(Self, MaxAccessTime);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.UncompressedDataRate
    //
    
    const Field<Uint32>& UncompressedDataRate() const
    {
        const size_t n = offsetof(Self, UncompressedDataRate);
        return GetField<Uint32>(n);
    }
    
    void UncompressedDataRate(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, UncompressedDataRate);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& UncompressedDataRate_value() const
    {
        const size_t n = offsetof(Self, UncompressedDataRate);
        return GetField<Uint32>(n).value;
    }
    
    void UncompressedDataRate_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, UncompressedDataRate);
        GetField<Uint32>(n).Set(x);
    }
    
    bool UncompressedDataRate_exists() const
    {
        const size_t n = offsetof(Self, UncompressedDataRate);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void UncompressedDataRate_clear()
    {
        const size_t n = offsetof(Self, UncompressedDataRate);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.LoadTime
    //
    
    const Field<Uint64>& LoadTime() const
    {
        const size_t n = offsetof(Self, LoadTime);
        return GetField<Uint64>(n);
    }
    
    void LoadTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, LoadTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& LoadTime_value() const
    {
        const size_t n = offsetof(Self, LoadTime);
        return GetField<Uint64>(n).value;
    }
    
    void LoadTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, LoadTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool LoadTime_exists() const
    {
        const size_t n = offsetof(Self, LoadTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void LoadTime_clear()
    {
        const size_t n = offsetof(Self, LoadTime);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.UnloadTime
    //
    
    const Field<Uint64>& UnloadTime() const
    {
        const size_t n = offsetof(Self, UnloadTime);
        return GetField<Uint64>(n);
    }
    
    void UnloadTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, UnloadTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& UnloadTime_value() const
    {
        const size_t n = offsetof(Self, UnloadTime);
        return GetField<Uint64>(n).value;
    }
    
    void UnloadTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, UnloadTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool UnloadTime_exists() const
    {
        const size_t n = offsetof(Self, UnloadTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void UnloadTime_clear()
    {
        const size_t n = offsetof(Self, UnloadTime);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.MountCount
    //
    
    const Field<Uint64>& MountCount() const
    {
        const size_t n = offsetof(Self, MountCount);
        return GetField<Uint64>(n);
    }
    
    void MountCount(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MountCount);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MountCount_value() const
    {
        const size_t n = offsetof(Self, MountCount);
        return GetField<Uint64>(n).value;
    }
    
    void MountCount_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MountCount);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MountCount_exists() const
    {
        const size_t n = offsetof(Self, MountCount);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MountCount_clear()
    {
        const size_t n = offsetof(Self, MountCount);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.TimeOfLastMount
    //
    
    const Field<Datetime>& TimeOfLastMount() const
    {
        const size_t n = offsetof(Self, TimeOfLastMount);
        return GetField<Datetime>(n);
    }
    
    void TimeOfLastMount(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, TimeOfLastMount);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& TimeOfLastMount_value() const
    {
        const size_t n = offsetof(Self, TimeOfLastMount);
        return GetField<Datetime>(n).value;
    }
    
    void TimeOfLastMount_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, TimeOfLastMount);
        GetField<Datetime>(n).Set(x);
    }
    
    bool TimeOfLastMount_exists() const
    {
        const size_t n = offsetof(Self, TimeOfLastMount);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void TimeOfLastMount_clear()
    {
        const size_t n = offsetof(Self, TimeOfLastMount);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.TotalMountTime
    //
    
    const Field<Uint64>& TotalMountTime() const
    {
        const size_t n = offsetof(Self, TotalMountTime);
        return GetField<Uint64>(n);
    }
    
    void TotalMountTime(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalMountTime);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalMountTime_value() const
    {
        const size_t n = offsetof(Self, TotalMountTime);
        return GetField<Uint64>(n).value;
    }
    
    void TotalMountTime_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalMountTime);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalMountTime_exists() const
    {
        const size_t n = offsetof(Self, TotalMountTime);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalMountTime_clear()
    {
        const size_t n = offsetof(Self, TotalMountTime);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.UnitsDescription
    //
    
    const Field<String>& UnitsDescription() const
    {
        const size_t n = offsetof(Self, UnitsDescription);
        return GetField<String>(n);
    }
    
    void UnitsDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, UnitsDescription);
        GetField<String>(n) = x;
    }
    
    const String& UnitsDescription_value() const
    {
        const size_t n = offsetof(Self, UnitsDescription);
        return GetField<String>(n).value;
    }
    
    void UnitsDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, UnitsDescription);
        GetField<String>(n).Set(x);
    }
    
    bool UnitsDescription_exists() const
    {
        const size_t n = offsetof(Self, UnitsDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void UnitsDescription_clear()
    {
        const size_t n = offsetof(Self, UnitsDescription);
        GetField<String>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.MaxUnitsBeforeCleaning
    //
    
    const Field<Uint64>& MaxUnitsBeforeCleaning() const
    {
        const size_t n = offsetof(Self, MaxUnitsBeforeCleaning);
        return GetField<Uint64>(n);
    }
    
    void MaxUnitsBeforeCleaning(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, MaxUnitsBeforeCleaning);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& MaxUnitsBeforeCleaning_value() const
    {
        const size_t n = offsetof(Self, MaxUnitsBeforeCleaning);
        return GetField<Uint64>(n).value;
    }
    
    void MaxUnitsBeforeCleaning_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, MaxUnitsBeforeCleaning);
        GetField<Uint64>(n).Set(x);
    }
    
    bool MaxUnitsBeforeCleaning_exists() const
    {
        const size_t n = offsetof(Self, MaxUnitsBeforeCleaning);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void MaxUnitsBeforeCleaning_clear()
    {
        const size_t n = offsetof(Self, MaxUnitsBeforeCleaning);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_MediaAccessDevice_Class.UnitsUsed
    //
    
    const Field<Uint64>& UnitsUsed() const
    {
        const size_t n = offsetof(Self, UnitsUsed);
        return GetField<Uint64>(n);
    }
    
    void UnitsUsed(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, UnitsUsed);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& UnitsUsed_value() const
    {
        const size_t n = offsetof(Self, UnitsUsed);
        return GetField<Uint64>(n).value;
    }
    
    void UnitsUsed_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, UnitsUsed);
        GetField<Uint64>(n).Set(x);
    }
    
    bool UnitsUsed_exists() const
    {
        const size_t n = offsetof(Self, UnitsUsed);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void UnitsUsed_clear()
    {
        const size_t n = offsetof(Self, UnitsUsed);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<CIM_MediaAccessDevice_Class> CIM_MediaAccessDevice_ClassA;

class CIM_MediaAccessDevice_LockMedia_Class : public Instance
{
public:
    
    typedef CIM_MediaAccessDevice_LockMedia Self;
    
    CIM_MediaAccessDevice_LockMedia_Class() :
        Instance(&CIM_MediaAccessDevice_LockMedia_rtti)
    {
    }
    
    CIM_MediaAccessDevice_LockMedia_Class(
        const CIM_MediaAccessDevice_LockMedia* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_MediaAccessDevice_LockMedia_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_MediaAccessDevice_LockMedia_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_MediaAccessDevice_LockMedia_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_MediaAccessDevice_LockMedia_Class& operator=(
        const CIM_MediaAccessDevice_LockMedia_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_MediaAccessDevice_LockMedia_Class(
        const CIM_MediaAccessDevice_LockMedia_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_MediaAccessDevice_LockMedia_Class.MIReturn
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
    // CIM_MediaAccessDevice_LockMedia_Class.Lock
    //
    
    const Field<Boolean>& Lock() const
    {
        const size_t n = offsetof(Self, Lock);
        return GetField<Boolean>(n);
    }
    
    void Lock(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Lock);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Lock_value() const
    {
        const size_t n = offsetof(Self, Lock);
        return GetField<Boolean>(n).value;
    }
    
    void Lock_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Lock);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Lock_exists() const
    {
        const size_t n = offsetof(Self, Lock);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Lock_clear()
    {
        const size_t n = offsetof(Self, Lock);
        GetField<Boolean>(n).Clear();
    }
};

typedef Array<CIM_MediaAccessDevice_LockMedia_Class> CIM_MediaAccessDevice_LockMedia_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_MediaAccessDevice_h */
