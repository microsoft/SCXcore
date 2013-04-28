/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_FileSystem_h
#define _CIM_FileSystem_h

#include <MI.h>
#include "CIM_EnabledLogicalElement.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** CIM_FileSystem [CIM_FileSystem]
**
** Keys:
**    Name
**    CSCreationClassName
**    CSName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _CIM_FileSystem /* extends CIM_EnabledLogicalElement */
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
    /* CIM_FileSystem properties */
    /*KEY*/ MI_ConstStringField CSCreationClassName;
    /*KEY*/ MI_ConstStringField CSName;
    /*KEY*/ MI_ConstStringField CreationClassName;
    MI_ConstStringField Root;
    MI_ConstUint64Field BlockSize;
    MI_ConstUint64Field FileSystemSize;
    MI_ConstUint64Field AvailableSpace;
    MI_ConstBooleanField ReadOnly;
    MI_ConstStringField EncryptionMethod;
    MI_ConstStringField CompressionMethod;
    MI_ConstBooleanField CaseSensitive;
    MI_ConstBooleanField CasePreserved;
    MI_ConstUint16AField CodeSet;
    MI_ConstUint32Field MaxFileNameLength;
    MI_ConstUint32Field ClusterSize;
    MI_ConstStringField FileSystemType;
    MI_ConstUint16Field PersistenceType;
    MI_ConstStringField OtherPersistenceType;
    MI_ConstUint64Field NumberOfFiles;
}
CIM_FileSystem;

typedef struct _CIM_FileSystem_Ref
{
    CIM_FileSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_FileSystem_Ref;

typedef struct _CIM_FileSystem_ConstRef
{
    MI_CONST CIM_FileSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_FileSystem_ConstRef;

typedef struct _CIM_FileSystem_Array
{
    struct _CIM_FileSystem** data;
    MI_Uint32 size;
}
CIM_FileSystem_Array;

typedef struct _CIM_FileSystem_ConstArray
{
    struct _CIM_FileSystem MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_FileSystem_ConstArray;

typedef struct _CIM_FileSystem_ArrayRef
{
    CIM_FileSystem_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_FileSystem_ArrayRef;

typedef struct _CIM_FileSystem_ConstArrayRef
{
    CIM_FileSystem_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_FileSystem_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_FileSystem_rtti;

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Construct(
    CIM_FileSystem* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_FileSystem_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clone(
    const CIM_FileSystem* self,
    CIM_FileSystem** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_FileSystem_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_FileSystem_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Destruct(CIM_FileSystem* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Delete(CIM_FileSystem* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Post(
    const CIM_FileSystem* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_InstanceID(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_InstanceID(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_InstanceID(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_Caption(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_Caption(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_Caption(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_Description(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_Description(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_Description(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_ElementName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_ElementName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_ElementName(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_InstallDate(
    CIM_FileSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_InstallDate(
    CIM_FileSystem* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_Name(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_Name(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_Name(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_OperationalStatus(
    CIM_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_OperationalStatus(
    CIM_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_OperationalStatus(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_StatusDescriptions(
    CIM_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_StatusDescriptions(
    CIM_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_StatusDescriptions(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_Status(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_Status(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_Status(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_HealthState(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_HealthState(
    CIM_FileSystem* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CommunicationStatus(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CommunicationStatus(
    CIM_FileSystem* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_DetailedStatus(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_DetailedStatus(
    CIM_FileSystem* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_OperatingStatus(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_OperatingStatus(
    CIM_FileSystem* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_PrimaryStatus(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_PrimaryStatus(
    CIM_FileSystem* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_EnabledState(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_EnabledState(
    CIM_FileSystem* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_OtherEnabledState(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_OtherEnabledState(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_OtherEnabledState(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_RequestedState(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_RequestedState(
    CIM_FileSystem* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_EnabledDefault(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_EnabledDefault(
    CIM_FileSystem* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_TimeOfLastStateChange(
    CIM_FileSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_TimeOfLastStateChange(
    CIM_FileSystem* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_AvailableRequestedStates(
    CIM_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_AvailableRequestedStates(
    CIM_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_AvailableRequestedStates(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_TransitioningToState(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_TransitioningToState(
    CIM_FileSystem* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CSCreationClassName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_CSCreationClassName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CSCreationClassName(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CSName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_CSName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CSName(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CreationClassName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_CreationClassName(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CreationClassName(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_Root(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_Root(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_Root(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_BlockSize(
    CIM_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockSize)->value = x;
    ((MI_Uint64Field*)&self->BlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_BlockSize(
    CIM_FileSystem* self)
{
    memset((void*)&self->BlockSize, 0, sizeof(self->BlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_FileSystemSize(
    CIM_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FileSystemSize)->value = x;
    ((MI_Uint64Field*)&self->FileSystemSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_FileSystemSize(
    CIM_FileSystem* self)
{
    memset((void*)&self->FileSystemSize, 0, sizeof(self->FileSystemSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_AvailableSpace(
    CIM_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->AvailableSpace)->value = x;
    ((MI_Uint64Field*)&self->AvailableSpace)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_AvailableSpace(
    CIM_FileSystem* self)
{
    memset((void*)&self->AvailableSpace, 0, sizeof(self->AvailableSpace));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_ReadOnly(
    CIM_FileSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ReadOnly)->value = x;
    ((MI_BooleanField*)&self->ReadOnly)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_ReadOnly(
    CIM_FileSystem* self)
{
    memset((void*)&self->ReadOnly, 0, sizeof(self->ReadOnly));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_EncryptionMethod(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_EncryptionMethod(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_EncryptionMethod(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CompressionMethod(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_CompressionMethod(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CompressionMethod(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CaseSensitive(
    CIM_FileSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->CaseSensitive)->value = x;
    ((MI_BooleanField*)&self->CaseSensitive)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CaseSensitive(
    CIM_FileSystem* self)
{
    memset((void*)&self->CaseSensitive, 0, sizeof(self->CaseSensitive));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CasePreserved(
    CIM_FileSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->CasePreserved)->value = x;
    ((MI_BooleanField*)&self->CasePreserved)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CasePreserved(
    CIM_FileSystem* self)
{
    memset((void*)&self->CasePreserved, 0, sizeof(self->CasePreserved));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_CodeSet(
    CIM_FileSystem* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        33,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_CodeSet(
    CIM_FileSystem* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        33,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_CodeSet(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        33);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_MaxFileNameLength(
    CIM_FileSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxFileNameLength)->value = x;
    ((MI_Uint32Field*)&self->MaxFileNameLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_MaxFileNameLength(
    CIM_FileSystem* self)
{
    memset((void*)&self->MaxFileNameLength, 0, sizeof(self->MaxFileNameLength));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_ClusterSize(
    CIM_FileSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ClusterSize)->value = x;
    ((MI_Uint32Field*)&self->ClusterSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_ClusterSize(
    CIM_FileSystem* self)
{
    memset((void*)&self->ClusterSize, 0, sizeof(self->ClusterSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_FileSystemType(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        36,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_FileSystemType(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        36,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_FileSystemType(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_PersistenceType(
    CIM_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PersistenceType)->value = x;
    ((MI_Uint16Field*)&self->PersistenceType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_PersistenceType(
    CIM_FileSystem* self)
{
    memset((void*)&self->PersistenceType, 0, sizeof(self->PersistenceType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_OtherPersistenceType(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_SetPtr_OtherPersistenceType(
    CIM_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_OtherPersistenceType(
    CIM_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Set_NumberOfFiles(
    CIM_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->NumberOfFiles)->value = x;
    ((MI_Uint64Field*)&self->NumberOfFiles)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_Clear_NumberOfFiles(
    CIM_FileSystem* self)
{
    memset((void*)&self->NumberOfFiles, 0, sizeof(self->NumberOfFiles));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_FileSystem.RequestStateChange()
**
**==============================================================================
*/

typedef struct _CIM_FileSystem_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
CIM_FileSystem_RequestStateChange;

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Set_MIReturn(
    CIM_FileSystem_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Clear_MIReturn(
    CIM_FileSystem_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Set_RequestedState(
    CIM_FileSystem_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Clear_RequestedState(
    CIM_FileSystem_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Set_Job(
    CIM_FileSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_SetPtr_Job(
    CIM_FileSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Clear_Job(
    CIM_FileSystem_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Set_TimeoutPeriod(
    CIM_FileSystem_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_FileSystem_RequestStateChange_Clear_TimeoutPeriod(
    CIM_FileSystem_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_FileSystem_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_FileSystem_Class : public CIM_EnabledLogicalElement_Class
{
public:
    
    typedef CIM_FileSystem Self;
    
    CIM_FileSystem_Class() :
        CIM_EnabledLogicalElement_Class(&CIM_FileSystem_rtti)
    {
    }
    
    CIM_FileSystem_Class(
        const CIM_FileSystem* instanceName,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(
            &CIM_FileSystem_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_FileSystem_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_EnabledLogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_FileSystem_Class(
        const MI_ClassDecl* clDecl) :
        CIM_EnabledLogicalElement_Class(clDecl)
    {
    }
    
    CIM_FileSystem_Class& operator=(
        const CIM_FileSystem_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_FileSystem_Class(
        const CIM_FileSystem_Class& x) :
        CIM_EnabledLogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_FileSystem_rtti;
    }

    //
    // CIM_FileSystem_Class.CSCreationClassName
    //
    
    const Field<String>& CSCreationClassName() const
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        return GetField<String>(n);
    }
    
    void CSCreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& CSCreationClassName_value() const
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        return GetField<String>(n).value;
    }
    
    void CSCreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool CSCreationClassName_exists() const
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CSCreationClassName_clear()
    {
        const size_t n = offsetof(Self, CSCreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.CSName
    //
    
    const Field<String>& CSName() const
    {
        const size_t n = offsetof(Self, CSName);
        return GetField<String>(n);
    }
    
    void CSName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CSName);
        GetField<String>(n) = x;
    }
    
    const String& CSName_value() const
    {
        const size_t n = offsetof(Self, CSName);
        return GetField<String>(n).value;
    }
    
    void CSName_value(const String& x)
    {
        const size_t n = offsetof(Self, CSName);
        GetField<String>(n).Set(x);
    }
    
    bool CSName_exists() const
    {
        const size_t n = offsetof(Self, CSName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CSName_clear()
    {
        const size_t n = offsetof(Self, CSName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.CreationClassName
    //
    
    const Field<String>& CreationClassName() const
    {
        const size_t n = offsetof(Self, CreationClassName);
        return GetField<String>(n);
    }
    
    void CreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& CreationClassName_value() const
    {
        const size_t n = offsetof(Self, CreationClassName);
        return GetField<String>(n).value;
    }
    
    void CreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, CreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool CreationClassName_exists() const
    {
        const size_t n = offsetof(Self, CreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CreationClassName_clear()
    {
        const size_t n = offsetof(Self, CreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.Root
    //
    
    const Field<String>& Root() const
    {
        const size_t n = offsetof(Self, Root);
        return GetField<String>(n);
    }
    
    void Root(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Root);
        GetField<String>(n) = x;
    }
    
    const String& Root_value() const
    {
        const size_t n = offsetof(Self, Root);
        return GetField<String>(n).value;
    }
    
    void Root_value(const String& x)
    {
        const size_t n = offsetof(Self, Root);
        GetField<String>(n).Set(x);
    }
    
    bool Root_exists() const
    {
        const size_t n = offsetof(Self, Root);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Root_clear()
    {
        const size_t n = offsetof(Self, Root);
        GetField<String>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.BlockSize
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
    // CIM_FileSystem_Class.FileSystemSize
    //
    
    const Field<Uint64>& FileSystemSize() const
    {
        const size_t n = offsetof(Self, FileSystemSize);
        return GetField<Uint64>(n);
    }
    
    void FileSystemSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, FileSystemSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& FileSystemSize_value() const
    {
        const size_t n = offsetof(Self, FileSystemSize);
        return GetField<Uint64>(n).value;
    }
    
    void FileSystemSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, FileSystemSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool FileSystemSize_exists() const
    {
        const size_t n = offsetof(Self, FileSystemSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void FileSystemSize_clear()
    {
        const size_t n = offsetof(Self, FileSystemSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.AvailableSpace
    //
    
    const Field<Uint64>& AvailableSpace() const
    {
        const size_t n = offsetof(Self, AvailableSpace);
        return GetField<Uint64>(n);
    }
    
    void AvailableSpace(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, AvailableSpace);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& AvailableSpace_value() const
    {
        const size_t n = offsetof(Self, AvailableSpace);
        return GetField<Uint64>(n).value;
    }
    
    void AvailableSpace_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, AvailableSpace);
        GetField<Uint64>(n).Set(x);
    }
    
    bool AvailableSpace_exists() const
    {
        const size_t n = offsetof(Self, AvailableSpace);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void AvailableSpace_clear()
    {
        const size_t n = offsetof(Self, AvailableSpace);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.ReadOnly
    //
    
    const Field<Boolean>& ReadOnly() const
    {
        const size_t n = offsetof(Self, ReadOnly);
        return GetField<Boolean>(n);
    }
    
    void ReadOnly(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, ReadOnly);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& ReadOnly_value() const
    {
        const size_t n = offsetof(Self, ReadOnly);
        return GetField<Boolean>(n).value;
    }
    
    void ReadOnly_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, ReadOnly);
        GetField<Boolean>(n).Set(x);
    }
    
    bool ReadOnly_exists() const
    {
        const size_t n = offsetof(Self, ReadOnly);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void ReadOnly_clear()
    {
        const size_t n = offsetof(Self, ReadOnly);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.EncryptionMethod
    //
    
    const Field<String>& EncryptionMethod() const
    {
        const size_t n = offsetof(Self, EncryptionMethod);
        return GetField<String>(n);
    }
    
    void EncryptionMethod(const Field<String>& x)
    {
        const size_t n = offsetof(Self, EncryptionMethod);
        GetField<String>(n) = x;
    }
    
    const String& EncryptionMethod_value() const
    {
        const size_t n = offsetof(Self, EncryptionMethod);
        return GetField<String>(n).value;
    }
    
    void EncryptionMethod_value(const String& x)
    {
        const size_t n = offsetof(Self, EncryptionMethod);
        GetField<String>(n).Set(x);
    }
    
    bool EncryptionMethod_exists() const
    {
        const size_t n = offsetof(Self, EncryptionMethod);
        return GetField<String>(n).exists ? true : false;
    }
    
    void EncryptionMethod_clear()
    {
        const size_t n = offsetof(Self, EncryptionMethod);
        GetField<String>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.CompressionMethod
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
    // CIM_FileSystem_Class.CaseSensitive
    //
    
    const Field<Boolean>& CaseSensitive() const
    {
        const size_t n = offsetof(Self, CaseSensitive);
        return GetField<Boolean>(n);
    }
    
    void CaseSensitive(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, CaseSensitive);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& CaseSensitive_value() const
    {
        const size_t n = offsetof(Self, CaseSensitive);
        return GetField<Boolean>(n).value;
    }
    
    void CaseSensitive_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, CaseSensitive);
        GetField<Boolean>(n).Set(x);
    }
    
    bool CaseSensitive_exists() const
    {
        const size_t n = offsetof(Self, CaseSensitive);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void CaseSensitive_clear()
    {
        const size_t n = offsetof(Self, CaseSensitive);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.CasePreserved
    //
    
    const Field<Boolean>& CasePreserved() const
    {
        const size_t n = offsetof(Self, CasePreserved);
        return GetField<Boolean>(n);
    }
    
    void CasePreserved(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, CasePreserved);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& CasePreserved_value() const
    {
        const size_t n = offsetof(Self, CasePreserved);
        return GetField<Boolean>(n).value;
    }
    
    void CasePreserved_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, CasePreserved);
        GetField<Boolean>(n).Set(x);
    }
    
    bool CasePreserved_exists() const
    {
        const size_t n = offsetof(Self, CasePreserved);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void CasePreserved_clear()
    {
        const size_t n = offsetof(Self, CasePreserved);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.CodeSet
    //
    
    const Field<Uint16A>& CodeSet() const
    {
        const size_t n = offsetof(Self, CodeSet);
        return GetField<Uint16A>(n);
    }
    
    void CodeSet(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, CodeSet);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& CodeSet_value() const
    {
        const size_t n = offsetof(Self, CodeSet);
        return GetField<Uint16A>(n).value;
    }
    
    void CodeSet_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, CodeSet);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool CodeSet_exists() const
    {
        const size_t n = offsetof(Self, CodeSet);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void CodeSet_clear()
    {
        const size_t n = offsetof(Self, CodeSet);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.MaxFileNameLength
    //
    
    const Field<Uint32>& MaxFileNameLength() const
    {
        const size_t n = offsetof(Self, MaxFileNameLength);
        return GetField<Uint32>(n);
    }
    
    void MaxFileNameLength(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MaxFileNameLength);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MaxFileNameLength_value() const
    {
        const size_t n = offsetof(Self, MaxFileNameLength);
        return GetField<Uint32>(n).value;
    }
    
    void MaxFileNameLength_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MaxFileNameLength);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MaxFileNameLength_exists() const
    {
        const size_t n = offsetof(Self, MaxFileNameLength);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MaxFileNameLength_clear()
    {
        const size_t n = offsetof(Self, MaxFileNameLength);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.ClusterSize
    //
    
    const Field<Uint32>& ClusterSize() const
    {
        const size_t n = offsetof(Self, ClusterSize);
        return GetField<Uint32>(n);
    }
    
    void ClusterSize(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, ClusterSize);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& ClusterSize_value() const
    {
        const size_t n = offsetof(Self, ClusterSize);
        return GetField<Uint32>(n).value;
    }
    
    void ClusterSize_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, ClusterSize);
        GetField<Uint32>(n).Set(x);
    }
    
    bool ClusterSize_exists() const
    {
        const size_t n = offsetof(Self, ClusterSize);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void ClusterSize_clear()
    {
        const size_t n = offsetof(Self, ClusterSize);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.FileSystemType
    //
    
    const Field<String>& FileSystemType() const
    {
        const size_t n = offsetof(Self, FileSystemType);
        return GetField<String>(n);
    }
    
    void FileSystemType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, FileSystemType);
        GetField<String>(n) = x;
    }
    
    const String& FileSystemType_value() const
    {
        const size_t n = offsetof(Self, FileSystemType);
        return GetField<String>(n).value;
    }
    
    void FileSystemType_value(const String& x)
    {
        const size_t n = offsetof(Self, FileSystemType);
        GetField<String>(n).Set(x);
    }
    
    bool FileSystemType_exists() const
    {
        const size_t n = offsetof(Self, FileSystemType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void FileSystemType_clear()
    {
        const size_t n = offsetof(Self, FileSystemType);
        GetField<String>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.PersistenceType
    //
    
    const Field<Uint16>& PersistenceType() const
    {
        const size_t n = offsetof(Self, PersistenceType);
        return GetField<Uint16>(n);
    }
    
    void PersistenceType(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, PersistenceType);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& PersistenceType_value() const
    {
        const size_t n = offsetof(Self, PersistenceType);
        return GetField<Uint16>(n).value;
    }
    
    void PersistenceType_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, PersistenceType);
        GetField<Uint16>(n).Set(x);
    }
    
    bool PersistenceType_exists() const
    {
        const size_t n = offsetof(Self, PersistenceType);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void PersistenceType_clear()
    {
        const size_t n = offsetof(Self, PersistenceType);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.OtherPersistenceType
    //
    
    const Field<String>& OtherPersistenceType() const
    {
        const size_t n = offsetof(Self, OtherPersistenceType);
        return GetField<String>(n);
    }
    
    void OtherPersistenceType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherPersistenceType);
        GetField<String>(n) = x;
    }
    
    const String& OtherPersistenceType_value() const
    {
        const size_t n = offsetof(Self, OtherPersistenceType);
        return GetField<String>(n).value;
    }
    
    void OtherPersistenceType_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherPersistenceType);
        GetField<String>(n).Set(x);
    }
    
    bool OtherPersistenceType_exists() const
    {
        const size_t n = offsetof(Self, OtherPersistenceType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherPersistenceType_clear()
    {
        const size_t n = offsetof(Self, OtherPersistenceType);
        GetField<String>(n).Clear();
    }

    //
    // CIM_FileSystem_Class.NumberOfFiles
    //
    
    const Field<Uint64>& NumberOfFiles() const
    {
        const size_t n = offsetof(Self, NumberOfFiles);
        return GetField<Uint64>(n);
    }
    
    void NumberOfFiles(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, NumberOfFiles);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& NumberOfFiles_value() const
    {
        const size_t n = offsetof(Self, NumberOfFiles);
        return GetField<Uint64>(n).value;
    }
    
    void NumberOfFiles_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, NumberOfFiles);
        GetField<Uint64>(n).Set(x);
    }
    
    bool NumberOfFiles_exists() const
    {
        const size_t n = offsetof(Self, NumberOfFiles);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void NumberOfFiles_clear()
    {
        const size_t n = offsetof(Self, NumberOfFiles);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<CIM_FileSystem_Class> CIM_FileSystem_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_FileSystem_h */
