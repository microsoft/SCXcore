/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_FileSystem_h
#define _SCX_FileSystem_h

#include <MI.h>
#include "CIM_FileSystem.h"
#include "CIM_ConcreteJob.h"

/*
**==============================================================================
**
** SCX_FileSystem [SCX_FileSystem]
**
** Keys:
**    Name
**    CSCreationClassName
**    CSName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _SCX_FileSystem /* extends CIM_FileSystem */
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
    /* SCX_FileSystem properties */
    MI_ConstBooleanField IsOnline;
    MI_ConstUint64Field TotalInodes;
    MI_ConstUint64Field FreeInodes;
}
SCX_FileSystem;

typedef struct _SCX_FileSystem_Ref
{
    SCX_FileSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystem_Ref;

typedef struct _SCX_FileSystem_ConstRef
{
    MI_CONST SCX_FileSystem* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystem_ConstRef;

typedef struct _SCX_FileSystem_Array
{
    struct _SCX_FileSystem** data;
    MI_Uint32 size;
}
SCX_FileSystem_Array;

typedef struct _SCX_FileSystem_ConstArray
{
    struct _SCX_FileSystem MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_FileSystem_ConstArray;

typedef struct _SCX_FileSystem_ArrayRef
{
    SCX_FileSystem_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystem_ArrayRef;

typedef struct _SCX_FileSystem_ConstArrayRef
{
    SCX_FileSystem_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystem_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_FileSystem_rtti;

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Construct(
    SCX_FileSystem* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_FileSystem_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clone(
    const SCX_FileSystem* self,
    SCX_FileSystem** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_FileSystem_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_FileSystem_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Destruct(SCX_FileSystem* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Delete(SCX_FileSystem* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Post(
    const SCX_FileSystem* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_InstanceID(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_InstanceID(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_InstanceID(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_Caption(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_Caption(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_Caption(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_Description(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_Description(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_Description(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_ElementName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_ElementName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_ElementName(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_InstallDate(
    SCX_FileSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_InstallDate(
    SCX_FileSystem* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_Name(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_Name(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_Name(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_OperationalStatus(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_OperationalStatus(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_OperationalStatus(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_StatusDescriptions(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_StatusDescriptions(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_StatusDescriptions(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_Status(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_Status(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_Status(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_HealthState(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_HealthState(
    SCX_FileSystem* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CommunicationStatus(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CommunicationStatus(
    SCX_FileSystem* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_DetailedStatus(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_DetailedStatus(
    SCX_FileSystem* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_OperatingStatus(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_OperatingStatus(
    SCX_FileSystem* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_PrimaryStatus(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_PrimaryStatus(
    SCX_FileSystem* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_EnabledState(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledState)->value = x;
    ((MI_Uint16Field*)&self->EnabledState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_EnabledState(
    SCX_FileSystem* self)
{
    memset((void*)&self->EnabledState, 0, sizeof(self->EnabledState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_OtherEnabledState(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_OtherEnabledState(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_OtherEnabledState(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_RequestedState(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_RequestedState(
    SCX_FileSystem* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_EnabledDefault(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->EnabledDefault)->value = x;
    ((MI_Uint16Field*)&self->EnabledDefault)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_EnabledDefault(
    SCX_FileSystem* self)
{
    memset((void*)&self->EnabledDefault, 0, sizeof(self->EnabledDefault));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_TimeOfLastStateChange(
    SCX_FileSystem* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->value = x;
    ((MI_DatetimeField*)&self->TimeOfLastStateChange)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_TimeOfLastStateChange(
    SCX_FileSystem* self)
{
    memset((void*)&self->TimeOfLastStateChange, 0, sizeof(self->TimeOfLastStateChange));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_AvailableRequestedStates(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_AvailableRequestedStates(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_AvailableRequestedStates(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_TransitioningToState(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->TransitioningToState)->value = x;
    ((MI_Uint16Field*)&self->TransitioningToState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_TransitioningToState(
    SCX_FileSystem* self)
{
    memset((void*)&self->TransitioningToState, 0, sizeof(self->TransitioningToState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CSCreationClassName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_CSCreationClassName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CSCreationClassName(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CSName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_CSName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CSName(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CreationClassName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_CreationClassName(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CreationClassName(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_Root(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_Root(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_Root(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_BlockSize(
    SCX_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockSize)->value = x;
    ((MI_Uint64Field*)&self->BlockSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_BlockSize(
    SCX_FileSystem* self)
{
    memset((void*)&self->BlockSize, 0, sizeof(self->BlockSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_FileSystemSize(
    SCX_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FileSystemSize)->value = x;
    ((MI_Uint64Field*)&self->FileSystemSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_FileSystemSize(
    SCX_FileSystem* self)
{
    memset((void*)&self->FileSystemSize, 0, sizeof(self->FileSystemSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_AvailableSpace(
    SCX_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->AvailableSpace)->value = x;
    ((MI_Uint64Field*)&self->AvailableSpace)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_AvailableSpace(
    SCX_FileSystem* self)
{
    memset((void*)&self->AvailableSpace, 0, sizeof(self->AvailableSpace));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_ReadOnly(
    SCX_FileSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->ReadOnly)->value = x;
    ((MI_BooleanField*)&self->ReadOnly)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_ReadOnly(
    SCX_FileSystem* self)
{
    memset((void*)&self->ReadOnly, 0, sizeof(self->ReadOnly));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_EncryptionMethod(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_EncryptionMethod(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        29,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_EncryptionMethod(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        29);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CompressionMethod(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_CompressionMethod(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        30,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CompressionMethod(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        30);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CaseSensitive(
    SCX_FileSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->CaseSensitive)->value = x;
    ((MI_BooleanField*)&self->CaseSensitive)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CaseSensitive(
    SCX_FileSystem* self)
{
    memset((void*)&self->CaseSensitive, 0, sizeof(self->CaseSensitive));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CasePreserved(
    SCX_FileSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->CasePreserved)->value = x;
    ((MI_BooleanField*)&self->CasePreserved)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CasePreserved(
    SCX_FileSystem* self)
{
    memset((void*)&self->CasePreserved, 0, sizeof(self->CasePreserved));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_CodeSet(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_CodeSet(
    SCX_FileSystem* self,
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

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_CodeSet(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        33);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_MaxFileNameLength(
    SCX_FileSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MaxFileNameLength)->value = x;
    ((MI_Uint32Field*)&self->MaxFileNameLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_MaxFileNameLength(
    SCX_FileSystem* self)
{
    memset((void*)&self->MaxFileNameLength, 0, sizeof(self->MaxFileNameLength));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_ClusterSize(
    SCX_FileSystem* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ClusterSize)->value = x;
    ((MI_Uint32Field*)&self->ClusterSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_ClusterSize(
    SCX_FileSystem* self)
{
    memset((void*)&self->ClusterSize, 0, sizeof(self->ClusterSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_FileSystemType(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        36,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_FileSystemType(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        36,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_FileSystemType(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        36);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_PersistenceType(
    SCX_FileSystem* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PersistenceType)->value = x;
    ((MI_Uint16Field*)&self->PersistenceType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_PersistenceType(
    SCX_FileSystem* self)
{
    memset((void*)&self->PersistenceType, 0, sizeof(self->PersistenceType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_OtherPersistenceType(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_SetPtr_OtherPersistenceType(
    SCX_FileSystem* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        38,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_OtherPersistenceType(
    SCX_FileSystem* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        38);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_NumberOfFiles(
    SCX_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->NumberOfFiles)->value = x;
    ((MI_Uint64Field*)&self->NumberOfFiles)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_NumberOfFiles(
    SCX_FileSystem* self)
{
    memset((void*)&self->NumberOfFiles, 0, sizeof(self->NumberOfFiles));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_IsOnline(
    SCX_FileSystem* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsOnline)->value = x;
    ((MI_BooleanField*)&self->IsOnline)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_IsOnline(
    SCX_FileSystem* self)
{
    memset((void*)&self->IsOnline, 0, sizeof(self->IsOnline));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_TotalInodes(
    SCX_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalInodes)->value = x;
    ((MI_Uint64Field*)&self->TotalInodes)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_TotalInodes(
    SCX_FileSystem* self)
{
    memset((void*)&self->TotalInodes, 0, sizeof(self->TotalInodes));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Set_FreeInodes(
    SCX_FileSystem* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreeInodes)->value = x;
    ((MI_Uint64Field*)&self->FreeInodes)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_Clear_FreeInodes(
    SCX_FileSystem* self)
{
    memset((void*)&self->FreeInodes, 0, sizeof(self->FreeInodes));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_FileSystem.RequestStateChange()
**
**==============================================================================
*/

typedef struct _SCX_FileSystem_RequestStateChange
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstUint16Field RequestedState;
    /*OUT*/ CIM_ConcreteJob_ConstRef Job;
    /*IN*/ MI_ConstDatetimeField TimeoutPeriod;
}
SCX_FileSystem_RequestStateChange;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_FileSystem_RequestStateChange_rtti;

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Construct(
    SCX_FileSystem_RequestStateChange* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_FileSystem_RequestStateChange_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Clone(
    const SCX_FileSystem_RequestStateChange* self,
    SCX_FileSystem_RequestStateChange** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Destruct(
    SCX_FileSystem_RequestStateChange* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Delete(
    SCX_FileSystem_RequestStateChange* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Post(
    const SCX_FileSystem_RequestStateChange* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Set_MIReturn(
    SCX_FileSystem_RequestStateChange* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Clear_MIReturn(
    SCX_FileSystem_RequestStateChange* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Set_RequestedState(
    SCX_FileSystem_RequestStateChange* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->RequestedState)->value = x;
    ((MI_Uint16Field*)&self->RequestedState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Clear_RequestedState(
    SCX_FileSystem_RequestStateChange* self)
{
    memset((void*)&self->RequestedState, 0, sizeof(self->RequestedState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Set_Job(
    SCX_FileSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_SetPtr_Job(
    SCX_FileSystem_RequestStateChange* self,
    const CIM_ConcreteJob* x)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&x,
        MI_REFERENCE,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Clear_Job(
    SCX_FileSystem_RequestStateChange* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Set_TimeoutPeriod(
    SCX_FileSystem_RequestStateChange* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->TimeoutPeriod)->value = x;
    ((MI_DatetimeField*)&self->TimeoutPeriod)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RequestStateChange_Clear_TimeoutPeriod(
    SCX_FileSystem_RequestStateChange* self)
{
    memset((void*)&self->TimeoutPeriod, 0, sizeof(self->TimeoutPeriod));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_FileSystem.RemoveByName()
**
**==============================================================================
*/

typedef struct _SCX_FileSystem_RemoveByName
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstBooleanField MIReturn;
    /*IN*/ MI_ConstStringField Name;
}
SCX_FileSystem_RemoveByName;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_FileSystem_RemoveByName_rtti;

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Construct(
    SCX_FileSystem_RemoveByName* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_FileSystem_RemoveByName_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Clone(
    const SCX_FileSystem_RemoveByName* self,
    SCX_FileSystem_RemoveByName** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Destruct(
    SCX_FileSystem_RemoveByName* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Delete(
    SCX_FileSystem_RemoveByName* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Post(
    const SCX_FileSystem_RemoveByName* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Set_MIReturn(
    SCX_FileSystem_RemoveByName* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MIReturn)->value = x;
    ((MI_BooleanField*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Clear_MIReturn(
    SCX_FileSystem_RemoveByName* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Set_Name(
    SCX_FileSystem_RemoveByName* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_SetPtr_Name(
    SCX_FileSystem_RemoveByName* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystem_RemoveByName_Clear_Name(
    SCX_FileSystem_RemoveByName* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

/*
**==============================================================================
**
** SCX_FileSystem provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_FileSystem_Self SCX_FileSystem_Self;

MI_EXTERN_C void MI_CALL SCX_FileSystem_Load(
    SCX_FileSystem_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_FileSystem_Unload(
    SCX_FileSystem_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_FileSystem_EnumerateInstances(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_FileSystem_GetInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_FileSystem_CreateInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* newInstance);

MI_EXTERN_C void MI_CALL SCX_FileSystem_ModifyInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_FileSystem_DeleteInstance(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystem* instanceName);

MI_EXTERN_C void MI_CALL SCX_FileSystem_Invoke_RequestStateChange(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_FileSystem* instanceName,
    const SCX_FileSystem_RequestStateChange* in);

MI_EXTERN_C void MI_CALL SCX_FileSystem_Invoke_RemoveByName(
    SCX_FileSystem_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_FileSystem* instanceName,
    const SCX_FileSystem_RemoveByName* in);


/*
**==============================================================================
**
** SCX_FileSystem_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_FileSystem_Class : public CIM_FileSystem_Class
{
public:
    
    typedef SCX_FileSystem Self;
    
    SCX_FileSystem_Class() :
        CIM_FileSystem_Class(&SCX_FileSystem_rtti)
    {
    }
    
    SCX_FileSystem_Class(
        const SCX_FileSystem* instanceName,
        bool keysOnly) :
        CIM_FileSystem_Class(
            &SCX_FileSystem_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_FileSystem_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_FileSystem_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_FileSystem_Class(
        const MI_ClassDecl* clDecl) :
        CIM_FileSystem_Class(clDecl)
    {
    }
    
    SCX_FileSystem_Class& operator=(
        const SCX_FileSystem_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_FileSystem_Class(
        const SCX_FileSystem_Class& x) :
        CIM_FileSystem_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_FileSystem_rtti;
    }

    //
    // SCX_FileSystem_Class.IsOnline
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
    // SCX_FileSystem_Class.TotalInodes
    //
    
    const Field<Uint64>& TotalInodes() const
    {
        const size_t n = offsetof(Self, TotalInodes);
        return GetField<Uint64>(n);
    }
    
    void TotalInodes(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalInodes);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalInodes_value() const
    {
        const size_t n = offsetof(Self, TotalInodes);
        return GetField<Uint64>(n).value;
    }
    
    void TotalInodes_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalInodes);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalInodes_exists() const
    {
        const size_t n = offsetof(Self, TotalInodes);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalInodes_clear()
    {
        const size_t n = offsetof(Self, TotalInodes);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystem_Class.FreeInodes
    //
    
    const Field<Uint64>& FreeInodes() const
    {
        const size_t n = offsetof(Self, FreeInodes);
        return GetField<Uint64>(n);
    }
    
    void FreeInodes(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, FreeInodes);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& FreeInodes_value() const
    {
        const size_t n = offsetof(Self, FreeInodes);
        return GetField<Uint64>(n).value;
    }
    
    void FreeInodes_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, FreeInodes);
        GetField<Uint64>(n).Set(x);
    }
    
    bool FreeInodes_exists() const
    {
        const size_t n = offsetof(Self, FreeInodes);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void FreeInodes_clear()
    {
        const size_t n = offsetof(Self, FreeInodes);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<SCX_FileSystem_Class> SCX_FileSystem_ClassA;

class SCX_FileSystem_RequestStateChange_Class : public Instance
{
public:
    
    typedef SCX_FileSystem_RequestStateChange Self;
    
    SCX_FileSystem_RequestStateChange_Class() :
        Instance(&SCX_FileSystem_RequestStateChange_rtti)
    {
    }
    
    SCX_FileSystem_RequestStateChange_Class(
        const SCX_FileSystem_RequestStateChange* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_FileSystem_RequestStateChange_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_FileSystem_RequestStateChange_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_FileSystem_RequestStateChange_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_FileSystem_RequestStateChange_Class& operator=(
        const SCX_FileSystem_RequestStateChange_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_FileSystem_RequestStateChange_Class(
        const SCX_FileSystem_RequestStateChange_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_FileSystem_RequestStateChange_Class.MIReturn
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
    // SCX_FileSystem_RequestStateChange_Class.RequestedState
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
    // SCX_FileSystem_RequestStateChange_Class.Job
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
    // SCX_FileSystem_RequestStateChange_Class.TimeoutPeriod
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

typedef Array<SCX_FileSystem_RequestStateChange_Class> SCX_FileSystem_RequestStateChange_ClassA;

class SCX_FileSystem_RemoveByName_Class : public Instance
{
public:
    
    typedef SCX_FileSystem_RemoveByName Self;
    
    SCX_FileSystem_RemoveByName_Class() :
        Instance(&SCX_FileSystem_RemoveByName_rtti)
    {
    }
    
    SCX_FileSystem_RemoveByName_Class(
        const SCX_FileSystem_RemoveByName* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_FileSystem_RemoveByName_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_FileSystem_RemoveByName_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_FileSystem_RemoveByName_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_FileSystem_RemoveByName_Class& operator=(
        const SCX_FileSystem_RemoveByName_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_FileSystem_RemoveByName_Class(
        const SCX_FileSystem_RemoveByName_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_FileSystem_RemoveByName_Class.MIReturn
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
    // SCX_FileSystem_RemoveByName_Class.Name
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

typedef Array<SCX_FileSystem_RemoveByName_Class> SCX_FileSystem_RemoveByName_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_FileSystem_h */
