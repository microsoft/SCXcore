/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_DiskDrive_h
#define _CIM_DiskDrive_h

#include <MI.h>
#include "CIM_MediaAccessDevice.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_DiskDrive [CIM_DiskDrive]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive /* extends CIM_MediaAccessDevice */
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
    /* CIM_DiskDrive properties */
}
CIM_DiskDrive;

typedef struct _CIM_DiskDrive_Ref
{
    CIM_DiskDrive* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_DiskDrive_Ref;

typedef struct _CIM_DiskDrive_ConstRef
{
    MI_CONST CIM_DiskDrive* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_DiskDrive_ConstRef;

typedef struct _CIM_DiskDrive_Array
{
    struct _CIM_DiskDrive** data;
    MI_Uint32 size;
}
CIM_DiskDrive_Array;

typedef struct _CIM_DiskDrive_ConstArray
{
    struct _CIM_DiskDrive MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_DiskDrive_ConstArray;

typedef struct _CIM_DiskDrive_ArrayRef
{
    CIM_DiskDrive_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_DiskDrive_ArrayRef;

typedef struct _CIM_DiskDrive_ConstArrayRef
{
    CIM_DiskDrive_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_DiskDrive_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_DiskDrive_rtti;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Construct(
    CIM_DiskDrive* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_DiskDrive_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clone(
    const CIM_DiskDrive* self,
    CIM_DiskDrive** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_DiskDrive_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_DiskDrive_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Destruct(CIM_DiskDrive* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Delete(CIM_DiskDrive* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Post(
    const CIM_DiskDrive* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_InstanceID(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_InstanceID(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_InstanceID(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_Caption(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_Caption(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_Caption(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_Description(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_Description(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_Description(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_ElementName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_ElementName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_ElementName(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_InstallDate(
    CIM_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_InstallDate(
    CIM_DiskDrive* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_Name(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_Name(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_Name(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_OperationalStatus(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_OperationalStatus(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_OperationalStatus(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_StatusDescriptions(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_StatusDescriptions(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_StatusDescriptions(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_Status(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_Status(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_Status(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_HealthState(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_HealthState(
    CIM_DiskDrive* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_CommunicationStatus(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_CommunicationStatus(
    CIM_DiskDrive* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_DetailedStatus(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_DetailedStatus(
    CIM_DiskDrive* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_OperatingStatus(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_OperatingStatus(
    CIM_DiskDrive* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_PrimaryStatus(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_PrimaryStatus(
    CIM_DiskDrive* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_EnabledState(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_EnabledState(
    CIM_DiskDrive* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_OtherEnabledState(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_OtherEnabledState(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_OtherEnabledState(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_RequestedState(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_RequestedState(
    CIM_DiskDrive* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_EnabledDefault(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_EnabledDefault(
    CIM_DiskDrive* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_TimeOfLastStateChange(
    CIM_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_TimeOfLastStateChange(
    CIM_DiskDrive* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_AvailableRequestedStates(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_AvailableRequestedStates(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_AvailableRequestedStates(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_TransitioningToState(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_TransitioningToState(
    CIM_DiskDrive* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_SystemCreationClassName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_SystemCreationClassName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_SystemCreationClassName(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_SystemName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_SystemName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_SystemName(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_CreationClassName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_CreationClassName(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_CreationClassName(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_DeviceID(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_DeviceID(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_DeviceID(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_PowerManagementSupported(
    CIM_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_PowerManagementSupported(
    CIM_DiskDrive* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_PowerManagementCapabilities(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_PowerManagementCapabilities(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_PowerManagementCapabilities(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_Availability(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_Availability(
    CIM_DiskDrive* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_StatusInfo(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_StatusInfo(
    CIM_DiskDrive* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_LastErrorCode(
    CIM_DiskDrive* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_LastErrorCode(
    CIM_DiskDrive* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_ErrorDescription(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_ErrorDescription(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_ErrorDescription(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_ErrorCleared(
    CIM_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_ErrorCleared(
    CIM_DiskDrive* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_OtherIdentifyingInfo(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_OtherIdentifyingInfo(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_OtherIdentifyingInfo(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_PowerOnHours(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_PowerOnHours(
    CIM_DiskDrive* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_TotalPowerOnHours(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_TotalPowerOnHours(
    CIM_DiskDrive* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_IdentifyingDescriptions(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_IdentifyingDescriptions(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_IdentifyingDescriptions(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_AdditionalAvailability(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_AdditionalAvailability(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_AdditionalAvailability(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MaxQuiesceTime(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MaxQuiesceTime(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_Capabilities(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_Capabilities(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_Capabilities(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_CapabilityDescriptions(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_CapabilityDescriptions(
    CIM_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_CapabilityDescriptions(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_ErrorMethodology(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_ErrorMethodology(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_ErrorMethodology(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        40);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_CompressionMethod(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_CompressionMethod(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_CompressionMethod(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_NumberOfMediaSupported(
    CIM_DiskDrive* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfMediaSupported)->value = x;
    ((MI_Uint32Field*)&self->NumberOfMediaSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_NumberOfMediaSupported(
    CIM_DiskDrive* self)
{
    memset((void*)&self->NumberOfMediaSupported, 0, sizeof(self->NumberOfMediaSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MaxMediaSize(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxMediaSize)->value = x;
    ((MI_Uint64Field*)&self->MaxMediaSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MaxMediaSize(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MaxMediaSize, 0, sizeof(self->MaxMediaSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_DefaultBlockSize(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->DefaultBlockSize)->value = x;
    ((MI_Uint64Field*)&self->DefaultBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_DefaultBlockSize(
    CIM_DiskDrive* self)
{
    memset((void*)&self->DefaultBlockSize, 0, sizeof(self->DefaultBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MaxBlockSize(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxBlockSize)->value = x;
    ((MI_Uint64Field*)&self->MaxBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MaxBlockSize(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MaxBlockSize, 0, sizeof(self->MaxBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MinBlockSize(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MinBlockSize)->value = x;
    ((MI_Uint64Field*)&self->MinBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MinBlockSize(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MinBlockSize, 0, sizeof(self->MinBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_NeedsCleaning(
    CIM_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->NeedsCleaning)->value = x;
    ((MI_BooleanField*)&self->NeedsCleaning)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_NeedsCleaning(
    CIM_DiskDrive* self)
{
    memset((void*)&self->NeedsCleaning, 0, sizeof(self->NeedsCleaning));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MediaIsLocked(
    CIM_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MediaIsLocked)->value = x;
    ((MI_BooleanField*)&self->MediaIsLocked)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MediaIsLocked(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MediaIsLocked, 0, sizeof(self->MediaIsLocked));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_Security(
    CIM_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Security)->value = x;
    ((MI_Uint16Field*)&self->Security)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_Security(
    CIM_DiskDrive* self)
{
    memset((void*)&self->Security, 0, sizeof(self->Security));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_LastCleaned(
    CIM_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastCleaned)->value = x;
    ((MI_DatetimeField*)&self->LastCleaned)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_LastCleaned(
    CIM_DiskDrive* self)
{
    memset((void*)&self->LastCleaned, 0, sizeof(self->LastCleaned));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MaxAccessTime(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxAccessTime)->value = x;
    ((MI_Uint64Field*)&self->MaxAccessTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MaxAccessTime(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MaxAccessTime, 0, sizeof(self->MaxAccessTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_UncompressedDataRate(
    CIM_DiskDrive* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->UncompressedDataRate)->value = x;
    ((MI_Uint32Field*)&self->UncompressedDataRate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_UncompressedDataRate(
    CIM_DiskDrive* self)
{
    memset((void*)&self->UncompressedDataRate, 0, sizeof(self->UncompressedDataRate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_LoadTime(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->LoadTime)->value = x;
    ((MI_Uint64Field*)&self->LoadTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_LoadTime(
    CIM_DiskDrive* self)
{
    memset((void*)&self->LoadTime, 0, sizeof(self->LoadTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_UnloadTime(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UnloadTime)->value = x;
    ((MI_Uint64Field*)&self->UnloadTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_UnloadTime(
    CIM_DiskDrive* self)
{
    memset((void*)&self->UnloadTime, 0, sizeof(self->UnloadTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MountCount(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MountCount)->value = x;
    ((MI_Uint64Field*)&self->MountCount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MountCount(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MountCount, 0, sizeof(self->MountCount));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_TimeOfLastMount(
    CIM_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastMount)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastMount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_TimeOfLastMount(
    CIM_DiskDrive* self)
{
    memset((void*)&self->TimeOfLastMount, 0, sizeof(self->TimeOfLastMount));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_TotalMountTime(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalMountTime)->value = x;
    ((MI_Uint64Field*)&self->TotalMountTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_TotalMountTime(
    CIM_DiskDrive* self)
{
    memset((void*)&self->TotalMountTime, 0, sizeof(self->TotalMountTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_UnitsDescription(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPtr_UnitsDescription(
    CIM_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_UnitsDescription(
    CIM_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        58);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_MaxUnitsBeforeCleaning(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxUnitsBeforeCleaning)->value = x;
    ((MI_Uint64Field*)&self->MaxUnitsBeforeCleaning)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_MaxUnitsBeforeCleaning(
    CIM_DiskDrive* self)
{
    memset((void*)&self->MaxUnitsBeforeCleaning, 0, sizeof(self->MaxUnitsBeforeCleaning));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Set_UnitsUsed(
    CIM_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UnitsUsed)->value = x;
    ((MI_Uint64Field*)&self->UnitsUsed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Clear_UnitsUsed(
    CIM_DiskDrive* self)
{
    memset((void*)&self->UnitsUsed, 0, sizeof(self->UnitsUsed));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_DiskDrive_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Set_MIReturn(
    CIM_DiskDrive_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Clear_MIReturn(
    CIM_DiskDrive_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Set_RequestedState(
    CIM_DiskDrive_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Clear_RequestedState(
    CIM_DiskDrive_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Set_Job(
    CIM_DiskDrive_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_SetPtr_Job(
    CIM_DiskDrive_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Clear_Job(
    CIM_DiskDrive_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Set_TimeoutPeriod(
    CIM_DiskDrive_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RequestStateChange_Clear_TimeoutPeriod(
    CIM_DiskDrive_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.SetPowerState()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
CIM_DiskDrive_SetPowerState;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPowerState_Set_MIReturn(
    CIM_DiskDrive_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPowerState_Clear_MIReturn(
    CIM_DiskDrive_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPowerState_Set_PowerState(
    CIM_DiskDrive_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPowerState_Clear_PowerState(
    CIM_DiskDrive_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPowerState_Set_Time(
    CIM_DiskDrive_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SetPowerState_Clear_Time(
    CIM_DiskDrive_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.Reset()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_DiskDrive_Reset;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Reset_Set_MIReturn(
    CIM_DiskDrive_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_Reset_Clear_MIReturn(
    CIM_DiskDrive_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.EnableDevice()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
CIM_DiskDrive_EnableDevice;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_EnableDevice_Set_MIReturn(
    CIM_DiskDrive_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_EnableDevice_Clear_MIReturn(
    CIM_DiskDrive_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_EnableDevice_Set_Enabled(
    CIM_DiskDrive_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_EnableDevice_Clear_Enabled(
    CIM_DiskDrive_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.OnlineDevice()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
CIM_DiskDrive_OnlineDevice;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_OnlineDevice_Set_MIReturn(
    CIM_DiskDrive_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_OnlineDevice_Clear_MIReturn(
    CIM_DiskDrive_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_OnlineDevice_Set_Online(
    CIM_DiskDrive_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_OnlineDevice_Clear_Online(
    CIM_DiskDrive_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
CIM_DiskDrive_QuiesceDevice;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_QuiesceDevice_Set_MIReturn(
    CIM_DiskDrive_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_QuiesceDevice_Clear_MIReturn(
    CIM_DiskDrive_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_QuiesceDevice_Set_Quiesce(
    CIM_DiskDrive_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_QuiesceDevice_Clear_Quiesce(
    CIM_DiskDrive_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.SaveProperties()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_DiskDrive_SaveProperties;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SaveProperties_Set_MIReturn(
    CIM_DiskDrive_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_SaveProperties_Clear_MIReturn(
    CIM_DiskDrive_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.RestoreProperties()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
CIM_DiskDrive_RestoreProperties;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RestoreProperties_Set_MIReturn(
    CIM_DiskDrive_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_RestoreProperties_Clear_MIReturn(
    CIM_DiskDrive_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_DiskDrive.LockMedia()
**
**==============================================================================
*/

typedef struct _CIM_DiskDrive_LockMedia
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Lock;
}
CIM_DiskDrive_LockMedia;

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_LockMedia_Set_MIReturn(
    CIM_DiskDrive_LockMedia* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_LockMedia_Clear_MIReturn(
    CIM_DiskDrive_LockMedia* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_LockMedia_Set_Lock(
    CIM_DiskDrive_LockMedia* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Lock)->value = x;
    ((MI_BooleanField*)&self->Lock)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_DiskDrive_LockMedia_Clear_Lock(
    CIM_DiskDrive_LockMedia* self)
{
    memset((void*)&self->Lock, 0, sizeof(self->Lock));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_DiskDrive_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_DiskDrive_Class : public CIM_MediaAccessDevice_Class
{
public:
    
    typedef CIM_DiskDrive Self;
    
    CIM_DiskDrive_Class() :
        CIM_MediaAccessDevice_Class(&CIM_DiskDrive_rtti)
    {
    }
    
    CIM_DiskDrive_Class(
        const CIM_DiskDrive* instanceName,
        bool keysOnly) :
        CIM_MediaAccessDevice_Class(
            &CIM_DiskDrive_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_DiskDrive_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_MediaAccessDevice_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_DiskDrive_Class(
        const MI_ClassDecl* clDecl) :
        CIM_MediaAccessDevice_Class(clDecl)
    {
    }
    
    CIM_DiskDrive_Class& operator=(
        const CIM_DiskDrive_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_DiskDrive_Class(
        const CIM_DiskDrive_Class& x) :
        CIM_MediaAccessDevice_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_DiskDrive_rtti;
    }

};

typedef Array<CIM_DiskDrive_Class> CIM_DiskDrive_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_DiskDrive_h */
