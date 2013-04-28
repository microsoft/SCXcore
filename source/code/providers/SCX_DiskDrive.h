/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_DiskDrive_h
#define _SCX_DiskDrive_h

#include <MI.h>
#include "CIM_DiskDrive.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_DiskDrive [SCX_DiskDrive]
**
** Keys:
**    SystemCreationClassName
**    SystemName
**    CreationClassName
**    DeviceID
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive /* extends CIM_DiskDrive */
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
    /* SCX_DiskDrive properties */
    MI_ConstBooleanField IsOnline;
    MI_ConstStringField InterfaceType;
    MI_ConstStringField Manufacturer;
    MI_ConstStringField Model;
    MI_ConstUint64Field TotalCylinders;
    MI_ConstUint64Field TotalHeads;
    MI_ConstUint64Field TotalSectors;
    MI_ConstUint64Field TotalTracks;
    MI_ConstUint64Field TracksPerCylinder;
}
SCX_DiskDrive;

typedef struct _SCX_DiskDrive_Ref
{
    SCX_DiskDrive* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDrive_Ref;

typedef struct _SCX_DiskDrive_ConstRef
{
    MI_CONST SCX_DiskDrive* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDrive_ConstRef;

typedef struct _SCX_DiskDrive_Array
{
    struct _SCX_DiskDrive** data;
    MI_Uint32 size;
}
SCX_DiskDrive_Array;

typedef struct _SCX_DiskDrive_ConstArray
{
    struct _SCX_DiskDrive MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_DiskDrive_ConstArray;

typedef struct _SCX_DiskDrive_ArrayRef
{
    SCX_DiskDrive_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDrive_ArrayRef;

typedef struct _SCX_DiskDrive_ConstArrayRef
{
    SCX_DiskDrive_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDrive_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_DiskDrive_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Construct(
    SCX_DiskDrive* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_DiskDrive_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clone(
    const SCX_DiskDrive* self,
    SCX_DiskDrive** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_DiskDrive_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_DiskDrive_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Destruct(SCX_DiskDrive* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Delete(SCX_DiskDrive* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Post(
    const SCX_DiskDrive* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_InstanceID(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_InstanceID(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_InstanceID(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Caption(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_Caption(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Caption(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Description(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_Description(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Description(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_ElementName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_ElementName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_ElementName(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_InstallDate(
    SCX_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_InstallDate(
    SCX_DiskDrive* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Name(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_Name(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Name(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_OperationalStatus(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_OperationalStatus(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_OperationalStatus(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_StatusDescriptions(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_StatusDescriptions(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_StatusDescriptions(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Status(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_Status(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Status(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_HealthState(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_HealthState(
    SCX_DiskDrive* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_CommunicationStatus(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_CommunicationStatus(
    SCX_DiskDrive* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_DetailedStatus(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_DetailedStatus(
    SCX_DiskDrive* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_OperatingStatus(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_OperatingStatus(
    SCX_DiskDrive* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_PrimaryStatus(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_PrimaryStatus(
    SCX_DiskDrive* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_EnabledState(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_EnabledState(
    SCX_DiskDrive* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_OtherEnabledState(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_OtherEnabledState(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_OtherEnabledState(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_RequestedState(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_RequestedState(
    SCX_DiskDrive* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_EnabledDefault(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_EnabledDefault(
    SCX_DiskDrive* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TimeOfLastStateChange(
    SCX_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TimeOfLastStateChange(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_AvailableRequestedStates(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_AvailableRequestedStates(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_AvailableRequestedStates(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TransitioningToState(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TransitioningToState(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_SystemCreationClassName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_SystemCreationClassName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_SystemCreationClassName(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_SystemName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_SystemName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_SystemName(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_CreationClassName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_CreationClassName(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_CreationClassName(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_DeviceID(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_DeviceID(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_DeviceID(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_PowerManagementSupported(
    SCX_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->PowerManagementSupported)->value = x;
    ((MI_BooleanField*)&self->PowerManagementSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_PowerManagementSupported(
    SCX_DiskDrive* self)
{
    memset((void*)&self->PowerManagementSupported, 0, sizeof(self->PowerManagementSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_PowerManagementCapabilities(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_PowerManagementCapabilities(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_PowerManagementCapabilities(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Availability(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Availability)->value = x;
    ((MI_Uint16Field*)&self->Availability)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Availability(
    SCX_DiskDrive* self)
{
    memset((void*)&self->Availability, 0, sizeof(self->Availability));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_StatusInfo(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->StatusInfo)->value = x;
    ((MI_Uint16Field*)&self->StatusInfo)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_StatusInfo(
    SCX_DiskDrive* self)
{
    memset((void*)&self->StatusInfo, 0, sizeof(self->StatusInfo));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_LastErrorCode(
    SCX_DiskDrive* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LastErrorCode)->value = x;
    ((MI_Uint32Field*)&self->LastErrorCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_LastErrorCode(
    SCX_DiskDrive* self)
{
    memset((void*)&self->LastErrorCode, 0, sizeof(self->LastErrorCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_ErrorDescription(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_ErrorDescription(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_ErrorDescription(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_ErrorCleared(
    SCX_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ErrorCleared)->value = x;
    ((MI_BooleanField*)&self->ErrorCleared)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_ErrorCleared(
    SCX_DiskDrive* self)
{
    memset((void*)&self->ErrorCleared, 0, sizeof(self->ErrorCleared));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_OtherIdentifyingInfo(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_OtherIdentifyingInfo(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_OtherIdentifyingInfo(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        32);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_PowerOnHours(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->PowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_PowerOnHours(
    SCX_DiskDrive* self)
{
    memset((void*)&self->PowerOnHours, 0, sizeof(self->PowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TotalPowerOnHours(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->value = x;
    ((MI_Uint64Field*)&self->TotalPowerOnHours)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TotalPowerOnHours(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TotalPowerOnHours, 0, sizeof(self->TotalPowerOnHours));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_IdentifyingDescriptions(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_IdentifyingDescriptions(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_IdentifyingDescriptions(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        35);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_AdditionalAvailability(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_AdditionalAvailability(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_AdditionalAvailability(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MaxQuiesceTime(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->value = x;
    ((MI_Uint64Field*)&self->MaxQuiesceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MaxQuiesceTime(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MaxQuiesceTime, 0, sizeof(self->MaxQuiesceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Capabilities(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_Capabilities(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Capabilities(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_CapabilityDescriptions(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_CapabilityDescriptions(
    SCX_DiskDrive* self,
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

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_CapabilityDescriptions(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        39);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_ErrorMethodology(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_ErrorMethodology(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        40,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_ErrorMethodology(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        40);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_CompressionMethod(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_CompressionMethod(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        41,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_CompressionMethod(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        41);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_NumberOfMediaSupported(
    SCX_DiskDrive* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->NumberOfMediaSupported)->value = x;
    ((MI_Uint32Field*)&self->NumberOfMediaSupported)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_NumberOfMediaSupported(
    SCX_DiskDrive* self)
{
    memset((void*)&self->NumberOfMediaSupported, 0, sizeof(self->NumberOfMediaSupported));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MaxMediaSize(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxMediaSize)->value = x;
    ((MI_Uint64Field*)&self->MaxMediaSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MaxMediaSize(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MaxMediaSize, 0, sizeof(self->MaxMediaSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_DefaultBlockSize(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->DefaultBlockSize)->value = x;
    ((MI_Uint64Field*)&self->DefaultBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_DefaultBlockSize(
    SCX_DiskDrive* self)
{
    memset((void*)&self->DefaultBlockSize, 0, sizeof(self->DefaultBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MaxBlockSize(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxBlockSize)->value = x;
    ((MI_Uint64Field*)&self->MaxBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MaxBlockSize(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MaxBlockSize, 0, sizeof(self->MaxBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MinBlockSize(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MinBlockSize)->value = x;
    ((MI_Uint64Field*)&self->MinBlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MinBlockSize(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MinBlockSize, 0, sizeof(self->MinBlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_NeedsCleaning(
    SCX_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->NeedsCleaning)->value = x;
    ((MI_BooleanField*)&self->NeedsCleaning)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_NeedsCleaning(
    SCX_DiskDrive* self)
{
    memset((void*)&self->NeedsCleaning, 0, sizeof(self->NeedsCleaning));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MediaIsLocked(
    SCX_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MediaIsLocked)->value = x;
    ((MI_BooleanField*)&self->MediaIsLocked)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MediaIsLocked(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MediaIsLocked, 0, sizeof(self->MediaIsLocked));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Security(
    SCX_DiskDrive* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->Security)->value = x;
    ((MI_Uint16Field*)&self->Security)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Security(
    SCX_DiskDrive* self)
{
    memset((void*)&self->Security, 0, sizeof(self->Security));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_LastCleaned(
    SCX_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastCleaned)->value = x;
    ((MI_DatetimeField*)&self->LastCleaned)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_LastCleaned(
    SCX_DiskDrive* self)
{
    memset((void*)&self->LastCleaned, 0, sizeof(self->LastCleaned));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MaxAccessTime(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxAccessTime)->value = x;
    ((MI_Uint64Field*)&self->MaxAccessTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MaxAccessTime(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MaxAccessTime, 0, sizeof(self->MaxAccessTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_UncompressedDataRate(
    SCX_DiskDrive* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->UncompressedDataRate)->value = x;
    ((MI_Uint32Field*)&self->UncompressedDataRate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_UncompressedDataRate(
    SCX_DiskDrive* self)
{
    memset((void*)&self->UncompressedDataRate, 0, sizeof(self->UncompressedDataRate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_LoadTime(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->LoadTime)->value = x;
    ((MI_Uint64Field*)&self->LoadTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_LoadTime(
    SCX_DiskDrive* self)
{
    memset((void*)&self->LoadTime, 0, sizeof(self->LoadTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_UnloadTime(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UnloadTime)->value = x;
    ((MI_Uint64Field*)&self->UnloadTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_UnloadTime(
    SCX_DiskDrive* self)
{
    memset((void*)&self->UnloadTime, 0, sizeof(self->UnloadTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MountCount(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MountCount)->value = x;
    ((MI_Uint64Field*)&self->MountCount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MountCount(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MountCount, 0, sizeof(self->MountCount));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TimeOfLastMount(
    SCX_DiskDrive* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastMount)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastMount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TimeOfLastMount(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TimeOfLastMount, 0, sizeof(self->TimeOfLastMount));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TotalMountTime(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalMountTime)->value = x;
    ((MI_Uint64Field*)&self->TotalMountTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TotalMountTime(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TotalMountTime, 0, sizeof(self->TotalMountTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_UnitsDescription(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_UnitsDescription(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        58,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_UnitsDescription(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        58);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_MaxUnitsBeforeCleaning(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->MaxUnitsBeforeCleaning)->value = x;
    ((MI_Uint64Field*)&self->MaxUnitsBeforeCleaning)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_MaxUnitsBeforeCleaning(
    SCX_DiskDrive* self)
{
    memset((void*)&self->MaxUnitsBeforeCleaning, 0, sizeof(self->MaxUnitsBeforeCleaning));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_UnitsUsed(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UnitsUsed)->value = x;
    ((MI_Uint64Field*)&self->UnitsUsed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_UnitsUsed(
    SCX_DiskDrive* self)
{
    memset((void*)&self->UnitsUsed, 0, sizeof(self->UnitsUsed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_IsOnline(
    SCX_DiskDrive* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsOnline)->value = x;
    ((MI_BooleanField*)&self->IsOnline)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_IsOnline(
    SCX_DiskDrive* self)
{
    memset((void*)&self->IsOnline, 0, sizeof(self->IsOnline));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_InterfaceType(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        62,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_InterfaceType(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        62,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_InterfaceType(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        62);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Manufacturer(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        63,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_Manufacturer(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        63,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Manufacturer(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        63);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_Model(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        64,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPtr_Model(
    SCX_DiskDrive* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        64,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_Model(
    SCX_DiskDrive* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        64);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TotalCylinders(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalCylinders)->value = x;
    ((MI_Uint64Field*)&self->TotalCylinders)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TotalCylinders(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TotalCylinders, 0, sizeof(self->TotalCylinders));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TotalHeads(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalHeads)->value = x;
    ((MI_Uint64Field*)&self->TotalHeads)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TotalHeads(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TotalHeads, 0, sizeof(self->TotalHeads));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TotalSectors(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalSectors)->value = x;
    ((MI_Uint64Field*)&self->TotalSectors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TotalSectors(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TotalSectors, 0, sizeof(self->TotalSectors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TotalTracks(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalTracks)->value = x;
    ((MI_Uint64Field*)&self->TotalTracks)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TotalTracks(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TotalTracks, 0, sizeof(self->TotalTracks));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Set_TracksPerCylinder(
    SCX_DiskDrive* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TracksPerCylinder)->value = x;
    ((MI_Uint64Field*)&self->TracksPerCylinder)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Clear_TracksPerCylinder(
    SCX_DiskDrive* self)
{
    memset((void*)&self->TracksPerCylinder, 0, sizeof(self->TracksPerCylinder));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_DiskDrive_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Construct(
    SCX_DiskDrive_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Clone(
    const SCX_DiskDrive_RequestStateChange* self,
    SCX_DiskDrive_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Destruct(
    SCX_DiskDrive_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Delete(
    SCX_DiskDrive_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Post(
    const SCX_DiskDrive_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Set_MIReturn(
    SCX_DiskDrive_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Clear_MIReturn(
    SCX_DiskDrive_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Set_RequestedState(
    SCX_DiskDrive_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Clear_RequestedState(
    SCX_DiskDrive_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Set_Job(
    SCX_DiskDrive_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_SetPtr_Job(
    SCX_DiskDrive_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Clear_Job(
    SCX_DiskDrive_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Set_TimeoutPeriod(
    SCX_DiskDrive_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RequestStateChange_Clear_TimeoutPeriod(
    SCX_DiskDrive_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.SetPowerState()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_SetPowerState
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field PowerState;
    /*IN*/ MI_ConstDatetimeField Time;
}
SCX_DiskDrive_SetPowerState;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_SetPowerState_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Construct(
    SCX_DiskDrive_SetPowerState* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_SetPowerState_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Clone(
    const SCX_DiskDrive_SetPowerState* self,
    SCX_DiskDrive_SetPowerState** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Destruct(
    SCX_DiskDrive_SetPowerState* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Delete(
    SCX_DiskDrive_SetPowerState* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Post(
    const SCX_DiskDrive_SetPowerState* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Set_MIReturn(
    SCX_DiskDrive_SetPowerState* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Clear_MIReturn(
    SCX_DiskDrive_SetPowerState* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Set_PowerState(
    SCX_DiskDrive_SetPowerState* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PowerState)->value = x;
    ((MI_Uint16Field*)&self->PowerState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Clear_PowerState(
    SCX_DiskDrive_SetPowerState* self)
{
    memset((void*)&self->PowerState, 0, sizeof(self->PowerState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Set_Time(
    SCX_DiskDrive_SetPowerState* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->Time)->value = x;
    ((MI_DatetimeField*)&self->Time)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SetPowerState_Clear_Time(
    SCX_DiskDrive_SetPowerState* self)
{
    memset((void*)&self->Time, 0, sizeof(self->Time));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.Reset()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_Reset
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_DiskDrive_Reset;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_Reset_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Reset_Construct(
    SCX_DiskDrive_Reset* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_Reset_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Reset_Clone(
    const SCX_DiskDrive_Reset* self,
    SCX_DiskDrive_Reset** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Reset_Destruct(
    SCX_DiskDrive_Reset* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Reset_Delete(
    SCX_DiskDrive_Reset* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Reset_Post(
    const SCX_DiskDrive_Reset* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Reset_Set_MIReturn(
    SCX_DiskDrive_Reset* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_Reset_Clear_MIReturn(
    SCX_DiskDrive_Reset* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.EnableDevice()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_EnableDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Enabled;
}
SCX_DiskDrive_EnableDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_EnableDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Construct(
    SCX_DiskDrive_EnableDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_EnableDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Clone(
    const SCX_DiskDrive_EnableDevice* self,
    SCX_DiskDrive_EnableDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Destruct(
    SCX_DiskDrive_EnableDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Delete(
    SCX_DiskDrive_EnableDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Post(
    const SCX_DiskDrive_EnableDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Set_MIReturn(
    SCX_DiskDrive_EnableDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Clear_MIReturn(
    SCX_DiskDrive_EnableDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Set_Enabled(
    SCX_DiskDrive_EnableDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Enabled)->value = x;
    ((MI_BooleanField*)&self->Enabled)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_EnableDevice_Clear_Enabled(
    SCX_DiskDrive_EnableDevice* self)
{
    memset((void*)&self->Enabled, 0, sizeof(self->Enabled));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.OnlineDevice()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_OnlineDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Online;
}
SCX_DiskDrive_OnlineDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_OnlineDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Construct(
    SCX_DiskDrive_OnlineDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_OnlineDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Clone(
    const SCX_DiskDrive_OnlineDevice* self,
    SCX_DiskDrive_OnlineDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Destruct(
    SCX_DiskDrive_OnlineDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Delete(
    SCX_DiskDrive_OnlineDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Post(
    const SCX_DiskDrive_OnlineDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Set_MIReturn(
    SCX_DiskDrive_OnlineDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Clear_MIReturn(
    SCX_DiskDrive_OnlineDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Set_Online(
    SCX_DiskDrive_OnlineDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Online)->value = x;
    ((MI_BooleanField*)&self->Online)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_OnlineDevice_Clear_Online(
    SCX_DiskDrive_OnlineDevice* self)
{
    memset((void*)&self->Online, 0, sizeof(self->Online));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.QuiesceDevice()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_QuiesceDevice
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Quiesce;
}
SCX_DiskDrive_QuiesceDevice;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_QuiesceDevice_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Construct(
    SCX_DiskDrive_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_QuiesceDevice_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Clone(
    const SCX_DiskDrive_QuiesceDevice* self,
    SCX_DiskDrive_QuiesceDevice** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Destruct(
    SCX_DiskDrive_QuiesceDevice* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Delete(
    SCX_DiskDrive_QuiesceDevice* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Post(
    const SCX_DiskDrive_QuiesceDevice* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Set_MIReturn(
    SCX_DiskDrive_QuiesceDevice* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Clear_MIReturn(
    SCX_DiskDrive_QuiesceDevice* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Set_Quiesce(
    SCX_DiskDrive_QuiesceDevice* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Quiesce)->value = x;
    ((MI_BooleanField*)&self->Quiesce)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_QuiesceDevice_Clear_Quiesce(
    SCX_DiskDrive_QuiesceDevice* self)
{
    memset((void*)&self->Quiesce, 0, sizeof(self->Quiesce));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.SaveProperties()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_SaveProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_DiskDrive_SaveProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_SaveProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SaveProperties_Construct(
    SCX_DiskDrive_SaveProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_SaveProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SaveProperties_Clone(
    const SCX_DiskDrive_SaveProperties* self,
    SCX_DiskDrive_SaveProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SaveProperties_Destruct(
    SCX_DiskDrive_SaveProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SaveProperties_Delete(
    SCX_DiskDrive_SaveProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SaveProperties_Post(
    const SCX_DiskDrive_SaveProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SaveProperties_Set_MIReturn(
    SCX_DiskDrive_SaveProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_SaveProperties_Clear_MIReturn(
    SCX_DiskDrive_SaveProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.RestoreProperties()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_RestoreProperties
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
}
SCX_DiskDrive_RestoreProperties;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_RestoreProperties_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RestoreProperties_Construct(
    SCX_DiskDrive_RestoreProperties* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_RestoreProperties_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RestoreProperties_Clone(
    const SCX_DiskDrive_RestoreProperties* self,
    SCX_DiskDrive_RestoreProperties** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RestoreProperties_Destruct(
    SCX_DiskDrive_RestoreProperties* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RestoreProperties_Delete(
    SCX_DiskDrive_RestoreProperties* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RestoreProperties_Post(
    const SCX_DiskDrive_RestoreProperties* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RestoreProperties_Set_MIReturn(
    SCX_DiskDrive_RestoreProperties* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RestoreProperties_Clear_MIReturn(
    SCX_DiskDrive_RestoreProperties* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.LockMedia()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_LockMedia
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstBooleanField Lock;
}
SCX_DiskDrive_LockMedia;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_LockMedia_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Construct(
    SCX_DiskDrive_LockMedia* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_LockMedia_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Clone(
    const SCX_DiskDrive_LockMedia* self,
    SCX_DiskDrive_LockMedia** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Destruct(
    SCX_DiskDrive_LockMedia* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Delete(
    SCX_DiskDrive_LockMedia* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Post(
    const SCX_DiskDrive_LockMedia* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Set_MIReturn(
    SCX_DiskDrive_LockMedia* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Clear_MIReturn(
    SCX_DiskDrive_LockMedia* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Set_Lock(
    SCX_DiskDrive_LockMedia* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Lock)->value = x;
    ((MI_BooleanField*)&self->Lock)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_LockMedia_Clear_Lock(
    SCX_DiskDrive_LockMedia* self)
{
    memset((void*)&self->Lock, 0, sizeof(self->Lock));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDrive.RemoveByName()
**
**==============================================================================
*/

typedef struct _SCX_DiskDrive_RemoveByName
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstBooleanField MIReturn;
    /*IN*/ MI_ConstStringField Name;
}
SCX_DiskDrive_RemoveByName;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_DiskDrive_RemoveByName_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Construct(
    SCX_DiskDrive_RemoveByName* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_DiskDrive_RemoveByName_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Clone(
    const SCX_DiskDrive_RemoveByName* self,
    SCX_DiskDrive_RemoveByName** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Destruct(
    SCX_DiskDrive_RemoveByName* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Delete(
    SCX_DiskDrive_RemoveByName* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Post(
    const SCX_DiskDrive_RemoveByName* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Set_MIReturn(
    SCX_DiskDrive_RemoveByName* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MIReturn)->value = x;
    ((MI_BooleanField*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Clear_MIReturn(
    SCX_DiskDrive_RemoveByName* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Set_Name(
    SCX_DiskDrive_RemoveByName* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_SetPtr_Name(
    SCX_DiskDrive_RemoveByName* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDrive_RemoveByName_Clear_Name(
    SCX_DiskDrive_RemoveByName* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

/*
**==============================================================================
**
** SCX_DiskDrive provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_DiskDrive_Self SCX_DiskDrive_Self;

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Load(
    SCX_DiskDrive_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Unload(
    SCX_DiskDrive_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_EnumerateInstances(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_GetInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_CreateInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* newInstance);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_ModifyInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_DeleteInstance(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDrive* instanceName);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_RequestStateChange(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_RequestStateChange* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_SetPowerState(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_SetPowerState* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_Reset(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_Reset* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_EnableDevice(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_EnableDevice* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_OnlineDevice(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_OnlineDevice* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_QuiesceDevice(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_QuiesceDevice* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_SaveProperties(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_SaveProperties* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_RestoreProperties(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_RestoreProperties* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_LockMedia(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_LockMedia* in);

MI_EXTERN_C void MI_CALL SCX_DiskDrive_Invoke_RemoveByName(
    SCX_DiskDrive_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_DiskDrive* instanceName,
    const SCX_DiskDrive_RemoveByName* in);


/*
**==============================================================================
**
** SCX_DiskDrive_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_DiskDrive_Class : public CIM_DiskDrive_Class
{
public:
    
    typedef SCX_DiskDrive Self;
    
    SCX_DiskDrive_Class() :
        CIM_DiskDrive_Class(&SCX_DiskDrive_rtti)
    {
    }
    
    SCX_DiskDrive_Class(
        const SCX_DiskDrive* instanceName,
        bool keysOnly) :
        CIM_DiskDrive_Class(
            &SCX_DiskDrive_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_DiskDrive_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_Class(
        const MI_ClassDecl* clDecl) :
        CIM_DiskDrive_Class(clDecl)
    {
    }
    
    SCX_DiskDrive_Class& operator=(
        const SCX_DiskDrive_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_Class(
        const SCX_DiskDrive_Class& x) :
        CIM_DiskDrive_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_DiskDrive_rtti;
    }

    //
    // SCX_DiskDrive_Class.IsOnline
    //
    
    const Field<Boolean>& IsOnline() const
    {
        const size_t n = offsetof(Self, IsOnline);
        return GetField<Boolean>(n);
    }
    
    void IsOnline(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, IsOnline);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& IsOnline_value() const
    {
        const size_t n = offsetof(Self, IsOnline);
        return GetField<Boolean>(n).value;
    }
    
    void IsOnline_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, IsOnline);
        GetField<Boolean>(n).Set(x);
    }
    
    bool IsOnline_exists() const
    {
        const size_t n = offsetof(Self, IsOnline);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void IsOnline_clear()
    {
        const size_t n = offsetof(Self, IsOnline);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.InterfaceType
    //
    
    const Field<String>& InterfaceType() const
    {
        const size_t n = offsetof(Self, InterfaceType);
        return GetField<String>(n);
    }
    
    void InterfaceType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, InterfaceType);
        GetField<String>(n) = x;
    }
    
    const String& InterfaceType_value() const
    {
        const size_t n = offsetof(Self, InterfaceType);
        return GetField<String>(n).value;
    }
    
    void InterfaceType_value(const String& x)
    {
        const size_t n = offsetof(Self, InterfaceType);
        GetField<String>(n).Set(x);
    }
    
    bool InterfaceType_exists() const
    {
        const size_t n = offsetof(Self, InterfaceType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void InterfaceType_clear()
    {
        const size_t n = offsetof(Self, InterfaceType);
        GetField<String>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.Manufacturer
    //
    
    const Field<String>& Manufacturer() const
    {
        const size_t n = offsetof(Self, Manufacturer);
        return GetField<String>(n);
    }
    
    void Manufacturer(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Manufacturer);
        GetField<String>(n) = x;
    }
    
    const String& Manufacturer_value() const
    {
        const size_t n = offsetof(Self, Manufacturer);
        return GetField<String>(n).value;
    }
    
    void Manufacturer_value(const String& x)
    {
        const size_t n = offsetof(Self, Manufacturer);
        GetField<String>(n).Set(x);
    }
    
    bool Manufacturer_exists() const
    {
        const size_t n = offsetof(Self, Manufacturer);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Manufacturer_clear()
    {
        const size_t n = offsetof(Self, Manufacturer);
        GetField<String>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.Model
    //
    
    const Field<String>& Model() const
    {
        const size_t n = offsetof(Self, Model);
        return GetField<String>(n);
    }
    
    void Model(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Model);
        GetField<String>(n) = x;
    }
    
    const String& Model_value() const
    {
        const size_t n = offsetof(Self, Model);
        return GetField<String>(n).value;
    }
    
    void Model_value(const String& x)
    {
        const size_t n = offsetof(Self, Model);
        GetField<String>(n).Set(x);
    }
    
    bool Model_exists() const
    {
        const size_t n = offsetof(Self, Model);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Model_clear()
    {
        const size_t n = offsetof(Self, Model);
        GetField<String>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.TotalCylinders
    //
    
    const Field<Uint64>& TotalCylinders() const
    {
        const size_t n = offsetof(Self, TotalCylinders);
        return GetField<Uint64>(n);
    }
    
    void TotalCylinders(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalCylinders);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalCylinders_value() const
    {
        const size_t n = offsetof(Self, TotalCylinders);
        return GetField<Uint64>(n).value;
    }
    
    void TotalCylinders_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalCylinders);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalCylinders_exists() const
    {
        const size_t n = offsetof(Self, TotalCylinders);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalCylinders_clear()
    {
        const size_t n = offsetof(Self, TotalCylinders);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.TotalHeads
    //
    
    const Field<Uint64>& TotalHeads() const
    {
        const size_t n = offsetof(Self, TotalHeads);
        return GetField<Uint64>(n);
    }
    
    void TotalHeads(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalHeads);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalHeads_value() const
    {
        const size_t n = offsetof(Self, TotalHeads);
        return GetField<Uint64>(n).value;
    }
    
    void TotalHeads_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalHeads);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalHeads_exists() const
    {
        const size_t n = offsetof(Self, TotalHeads);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalHeads_clear()
    {
        const size_t n = offsetof(Self, TotalHeads);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.TotalSectors
    //
    
    const Field<Uint64>& TotalSectors() const
    {
        const size_t n = offsetof(Self, TotalSectors);
        return GetField<Uint64>(n);
    }
    
    void TotalSectors(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalSectors);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalSectors_value() const
    {
        const size_t n = offsetof(Self, TotalSectors);
        return GetField<Uint64>(n).value;
    }
    
    void TotalSectors_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalSectors);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalSectors_exists() const
    {
        const size_t n = offsetof(Self, TotalSectors);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalSectors_clear()
    {
        const size_t n = offsetof(Self, TotalSectors);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.TotalTracks
    //
    
    const Field<Uint64>& TotalTracks() const
    {
        const size_t n = offsetof(Self, TotalTracks);
        return GetField<Uint64>(n);
    }
    
    void TotalTracks(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalTracks);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalTracks_value() const
    {
        const size_t n = offsetof(Self, TotalTracks);
        return GetField<Uint64>(n).value;
    }
    
    void TotalTracks_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalTracks);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalTracks_exists() const
    {
        const size_t n = offsetof(Self, TotalTracks);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalTracks_clear()
    {
        const size_t n = offsetof(Self, TotalTracks);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_DiskDrive_Class.TracksPerCylinder
    //
    
    const Field<Uint64>& TracksPerCylinder() const
    {
        const size_t n = offsetof(Self, TracksPerCylinder);
        return GetField<Uint64>(n);
    }
    
    void TracksPerCylinder(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TracksPerCylinder);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TracksPerCylinder_value() const
    {
        const size_t n = offsetof(Self, TracksPerCylinder);
        return GetField<Uint64>(n).value;
    }
    
    void TracksPerCylinder_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TracksPerCylinder);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TracksPerCylinder_exists() const
    {
        const size_t n = offsetof(Self, TracksPerCylinder);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TracksPerCylinder_clear()
    {
        const size_t n = offsetof(Self, TracksPerCylinder);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<SCX_DiskDrive_Class> SCX_DiskDrive_ClassA;

class SCX_DiskDrive_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_RequestStateChange Self;
    
    SCX_DiskDrive_RequestStateChange_Class() :
        Instance(&SCX_DiskDrive_RequestStateChange_rtti)
    {
    }
    
    SCX_DiskDrive_RequestStateChange_Class(
        const SCX_DiskDrive_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_RequestStateChange_Class& operator=(
        const SCX_DiskDrive_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_RequestStateChange_Class(
        const SCX_DiskDrive_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_RequestStateChange_Class.MIReturn
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
    // SCX_DiskDrive_RequestStateChange_Class.RequestedState
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
    // SCX_DiskDrive_RequestStateChange_Class.Job
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
    // SCX_DiskDrive_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<SCX_DiskDrive_RequestStateChange_Class> SCX_DiskDrive_RequestStateChange_ClassA;

class SCX_DiskDrive_SetPowerState_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_SetPowerState Self;
    
    SCX_DiskDrive_SetPowerState_Class() :
        Instance(&SCX_DiskDrive_SetPowerState_rtti)
    {
    }
    
    SCX_DiskDrive_SetPowerState_Class(
        const SCX_DiskDrive_SetPowerState* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_SetPowerState_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_SetPowerState_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_SetPowerState_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_SetPowerState_Class& operator=(
        const SCX_DiskDrive_SetPowerState_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_SetPowerState_Class(
        const SCX_DiskDrive_SetPowerState_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_SetPowerState_Class.MIReturn
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
    // SCX_DiskDrive_SetPowerState_Class.PowerState
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
    // SCX_DiskDrive_SetPowerState_Class.Time
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

typedef Array<SCX_DiskDrive_SetPowerState_Class> SCX_DiskDrive_SetPowerState_ClassA;

class SCX_DiskDrive_Reset_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_Reset Self;
    
    SCX_DiskDrive_Reset_Class() :
        Instance(&SCX_DiskDrive_Reset_rtti)
    {
    }
    
    SCX_DiskDrive_Reset_Class(
        const SCX_DiskDrive_Reset* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_Reset_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_Reset_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_Reset_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_Reset_Class& operator=(
        const SCX_DiskDrive_Reset_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_Reset_Class(
        const SCX_DiskDrive_Reset_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_Reset_Class.MIReturn
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

typedef Array<SCX_DiskDrive_Reset_Class> SCX_DiskDrive_Reset_ClassA;

class SCX_DiskDrive_EnableDevice_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_EnableDevice Self;
    
    SCX_DiskDrive_EnableDevice_Class() :
        Instance(&SCX_DiskDrive_EnableDevice_rtti)
    {
    }
    
    SCX_DiskDrive_EnableDevice_Class(
        const SCX_DiskDrive_EnableDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_EnableDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_EnableDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_EnableDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_EnableDevice_Class& operator=(
        const SCX_DiskDrive_EnableDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_EnableDevice_Class(
        const SCX_DiskDrive_EnableDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_EnableDevice_Class.MIReturn
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
    // SCX_DiskDrive_EnableDevice_Class.Enabled
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

typedef Array<SCX_DiskDrive_EnableDevice_Class> SCX_DiskDrive_EnableDevice_ClassA;

class SCX_DiskDrive_OnlineDevice_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_OnlineDevice Self;
    
    SCX_DiskDrive_OnlineDevice_Class() :
        Instance(&SCX_DiskDrive_OnlineDevice_rtti)
    {
    }
    
    SCX_DiskDrive_OnlineDevice_Class(
        const SCX_DiskDrive_OnlineDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_OnlineDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_OnlineDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_OnlineDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_OnlineDevice_Class& operator=(
        const SCX_DiskDrive_OnlineDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_OnlineDevice_Class(
        const SCX_DiskDrive_OnlineDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_OnlineDevice_Class.MIReturn
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
    // SCX_DiskDrive_OnlineDevice_Class.Online
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

typedef Array<SCX_DiskDrive_OnlineDevice_Class> SCX_DiskDrive_OnlineDevice_ClassA;

class SCX_DiskDrive_QuiesceDevice_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_QuiesceDevice Self;
    
    SCX_DiskDrive_QuiesceDevice_Class() :
        Instance(&SCX_DiskDrive_QuiesceDevice_rtti)
    {
    }
    
    SCX_DiskDrive_QuiesceDevice_Class(
        const SCX_DiskDrive_QuiesceDevice* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_QuiesceDevice_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_QuiesceDevice_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_QuiesceDevice_Class& operator=(
        const SCX_DiskDrive_QuiesceDevice_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_QuiesceDevice_Class(
        const SCX_DiskDrive_QuiesceDevice_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_QuiesceDevice_Class.MIReturn
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
    // SCX_DiskDrive_QuiesceDevice_Class.Quiesce
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

typedef Array<SCX_DiskDrive_QuiesceDevice_Class> SCX_DiskDrive_QuiesceDevice_ClassA;

class SCX_DiskDrive_SaveProperties_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_SaveProperties Self;
    
    SCX_DiskDrive_SaveProperties_Class() :
        Instance(&SCX_DiskDrive_SaveProperties_rtti)
    {
    }
    
    SCX_DiskDrive_SaveProperties_Class(
        const SCX_DiskDrive_SaveProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_SaveProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_SaveProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_SaveProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_SaveProperties_Class& operator=(
        const SCX_DiskDrive_SaveProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_SaveProperties_Class(
        const SCX_DiskDrive_SaveProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_SaveProperties_Class.MIReturn
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

typedef Array<SCX_DiskDrive_SaveProperties_Class> SCX_DiskDrive_SaveProperties_ClassA;

class SCX_DiskDrive_RestoreProperties_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_RestoreProperties Self;
    
    SCX_DiskDrive_RestoreProperties_Class() :
        Instance(&SCX_DiskDrive_RestoreProperties_rtti)
    {
    }
    
    SCX_DiskDrive_RestoreProperties_Class(
        const SCX_DiskDrive_RestoreProperties* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_RestoreProperties_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_RestoreProperties_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_RestoreProperties_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_RestoreProperties_Class& operator=(
        const SCX_DiskDrive_RestoreProperties_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_RestoreProperties_Class(
        const SCX_DiskDrive_RestoreProperties_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_RestoreProperties_Class.MIReturn
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

typedef Array<SCX_DiskDrive_RestoreProperties_Class> SCX_DiskDrive_RestoreProperties_ClassA;

class SCX_DiskDrive_LockMedia_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_LockMedia Self;
    
    SCX_DiskDrive_LockMedia_Class() :
        Instance(&SCX_DiskDrive_LockMedia_rtti)
    {
    }
    
    SCX_DiskDrive_LockMedia_Class(
        const SCX_DiskDrive_LockMedia* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_LockMedia_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_LockMedia_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_LockMedia_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_LockMedia_Class& operator=(
        const SCX_DiskDrive_LockMedia_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_LockMedia_Class(
        const SCX_DiskDrive_LockMedia_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_LockMedia_Class.MIReturn
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
    // SCX_DiskDrive_LockMedia_Class.Lock
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

typedef Array<SCX_DiskDrive_LockMedia_Class> SCX_DiskDrive_LockMedia_ClassA;

class SCX_DiskDrive_RemoveByName_Class : public Instance
{
public:
    
    typedef SCX_DiskDrive_RemoveByName Self;
    
    SCX_DiskDrive_RemoveByName_Class() :
        Instance(&SCX_DiskDrive_RemoveByName_rtti)
    {
    }
    
    SCX_DiskDrive_RemoveByName_Class(
        const SCX_DiskDrive_RemoveByName* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_DiskDrive_RemoveByName_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDrive_RemoveByName_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDrive_RemoveByName_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_DiskDrive_RemoveByName_Class& operator=(
        const SCX_DiskDrive_RemoveByName_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDrive_RemoveByName_Class(
        const SCX_DiskDrive_RemoveByName_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_DiskDrive_RemoveByName_Class.MIReturn
    //
    
    const Field<Boolean>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n);
    }
    
    void MIReturn(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).value;
    }
    
    void MIReturn_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_DiskDrive_RemoveByName_Class.Name
    //
    
    const Field<String>& Name() const
    {
        const size_t n = offsetof(Self, Name);
        return GetField<String>(n);
    }
    
    void Name(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Name);
        GetField<String>(n) = x;
    }
    
    const String& Name_value() const
    {
        const size_t n = offsetof(Self, Name);
        return GetField<String>(n).value;
    }
    
    void Name_value(const String& x)
    {
        const size_t n = offsetof(Self, Name);
        GetField<String>(n).Set(x);
    }
    
    bool Name_exists() const
    {
        const size_t n = offsetof(Self, Name);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Name_clear()
    {
        const size_t n = offsetof(Self, Name);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_DiskDrive_RemoveByName_Class> SCX_DiskDrive_RemoveByName_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_DiskDrive_h */
