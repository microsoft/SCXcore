/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_LogicalFile_h
#define _CIM_LogicalFile_h

#include <MI.h>
#include "CIM_LogicalElement.h"

/*
**==============================================================================
**
** CIM_LogicalFile [CIM_LogicalFile]
**
** Keys:
**    Name
**    CSCreationClassName
**    CSName
**    FSCreationClassName
**    FSName
**    CreationClassName
**
**==============================================================================
*/

typedef struct _CIM_LogicalFile /* extends CIM_LogicalElement */
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
    /* CIM_LogicalFile properties */
    /*KEY*/ MI_ConstStringField CSCreationClassName;
    /*KEY*/ MI_ConstStringField CSName;
    /*KEY*/ MI_ConstStringField FSCreationClassName;
    /*KEY*/ MI_ConstStringField FSName;
    /*KEY*/ MI_ConstStringField CreationClassName;
    MI_ConstUint64Field FileSize;
    MI_ConstDatetimeField CreationDate;
    MI_ConstDatetimeField LastModified;
    MI_ConstDatetimeField LastAccessed;
    MI_ConstBooleanField Readable;
    MI_ConstBooleanField Writeable;
    MI_ConstBooleanField Executable;
    MI_ConstStringField CompressionMethod;
    MI_ConstStringField EncryptionMethod;
    MI_ConstUint64Field InUseCount;
}
CIM_LogicalFile;

typedef struct _CIM_LogicalFile_Ref
{
    CIM_LogicalFile* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalFile_Ref;

typedef struct _CIM_LogicalFile_ConstRef
{
    MI_CONST CIM_LogicalFile* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalFile_ConstRef;

typedef struct _CIM_LogicalFile_Array
{
    struct _CIM_LogicalFile** data;
    MI_Uint32 size;
}
CIM_LogicalFile_Array;

typedef struct _CIM_LogicalFile_ConstArray
{
    struct _CIM_LogicalFile MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_LogicalFile_ConstArray;

typedef struct _CIM_LogicalFile_ArrayRef
{
    CIM_LogicalFile_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalFile_ArrayRef;

typedef struct _CIM_LogicalFile_ConstArrayRef
{
    CIM_LogicalFile_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_LogicalFile_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_LogicalFile_rtti;

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Construct(
    CIM_LogicalFile* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_LogicalFile_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clone(
    const CIM_LogicalFile* self,
    CIM_LogicalFile** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_LogicalFile_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_LogicalFile_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Destruct(CIM_LogicalFile* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Delete(CIM_LogicalFile* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Post(
    const CIM_LogicalFile* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_InstanceID(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_InstanceID(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_InstanceID(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_Caption(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_Caption(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_Caption(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_Description(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_Description(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_Description(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_ElementName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_ElementName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_ElementName(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_InstallDate(
    CIM_LogicalFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_InstallDate(
    CIM_LogicalFile* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_Name(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_Name(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_Name(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_OperationalStatus(
    CIM_LogicalFile* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_OperationalStatus(
    CIM_LogicalFile* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_OperationalStatus(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_StatusDescriptions(
    CIM_LogicalFile* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_StatusDescriptions(
    CIM_LogicalFile* self,
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

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_StatusDescriptions(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_Status(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_Status(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_Status(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_HealthState(
    CIM_LogicalFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_HealthState(
    CIM_LogicalFile* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_CommunicationStatus(
    CIM_LogicalFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_CommunicationStatus(
    CIM_LogicalFile* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_DetailedStatus(
    CIM_LogicalFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_DetailedStatus(
    CIM_LogicalFile* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_OperatingStatus(
    CIM_LogicalFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_OperatingStatus(
    CIM_LogicalFile* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_PrimaryStatus(
    CIM_LogicalFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_PrimaryStatus(
    CIM_LogicalFile* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_CSCreationClassName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_CSCreationClassName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_CSCreationClassName(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        14);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_CSName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_CSName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_CSName(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_FSCreationClassName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        16,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_FSCreationClassName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        16,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_FSCreationClassName(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        16);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_FSName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        17,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_FSName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        17,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_FSName(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        17);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_CreationClassName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        18,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_CreationClassName(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        18,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_CreationClassName(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        18);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_FileSize(
    CIM_LogicalFile* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FileSize)->value = x;
    ((MI_Uint64Field*)&self->FileSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_FileSize(
    CIM_LogicalFile* self)
{
    memset((void*)&self->FileSize, 0, sizeof(self->FileSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_CreationDate(
    CIM_LogicalFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->CreationDate)->value = x;
    ((MI_DatetimeField*)&self->CreationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_CreationDate(
    CIM_LogicalFile* self)
{
    memset((void*)&self->CreationDate, 0, sizeof(self->CreationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_LastModified(
    CIM_LogicalFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastModified)->value = x;
    ((MI_DatetimeField*)&self->LastModified)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_LastModified(
    CIM_LogicalFile* self)
{
    memset((void*)&self->LastModified, 0, sizeof(self->LastModified));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_LastAccessed(
    CIM_LogicalFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastAccessed)->value = x;
    ((MI_DatetimeField*)&self->LastAccessed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_LastAccessed(
    CIM_LogicalFile* self)
{
    memset((void*)&self->LastAccessed, 0, sizeof(self->LastAccessed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_Readable(
    CIM_LogicalFile* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Readable)->value = x;
    ((MI_BooleanField*)&self->Readable)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_Readable(
    CIM_LogicalFile* self)
{
    memset((void*)&self->Readable, 0, sizeof(self->Readable));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_Writeable(
    CIM_LogicalFile* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Writeable)->value = x;
    ((MI_BooleanField*)&self->Writeable)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_Writeable(
    CIM_LogicalFile* self)
{
    memset((void*)&self->Writeable, 0, sizeof(self->Writeable));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_Executable(
    CIM_LogicalFile* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Executable)->value = x;
    ((MI_BooleanField*)&self->Executable)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_Executable(
    CIM_LogicalFile* self)
{
    memset((void*)&self->Executable, 0, sizeof(self->Executable));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_CompressionMethod(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_CompressionMethod(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_CompressionMethod(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_EncryptionMethod(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_SetPtr_EncryptionMethod(
    CIM_LogicalFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_EncryptionMethod(
    CIM_LogicalFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        27);
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Set_InUseCount(
    CIM_LogicalFile* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->InUseCount)->value = x;
    ((MI_Uint64Field*)&self->InUseCount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_LogicalFile_Clear_InUseCount(
    CIM_LogicalFile* self)
{
    memset((void*)&self->InUseCount, 0, sizeof(self->InUseCount));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_LogicalFile_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_LogicalFile_Class : public CIM_LogicalElement_Class
{
public:
    
    typedef CIM_LogicalFile Self;
    
    CIM_LogicalFile_Class() :
        CIM_LogicalElement_Class(&CIM_LogicalFile_rtti)
    {
    }
    
    CIM_LogicalFile_Class(
        const CIM_LogicalFile* instanceName,
        bool keysOnly) :
        CIM_LogicalElement_Class(
            &CIM_LogicalFile_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_LogicalFile_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_LogicalFile_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalElement_Class(clDecl)
    {
    }
    
    CIM_LogicalFile_Class& operator=(
        const CIM_LogicalFile_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_LogicalFile_Class(
        const CIM_LogicalFile_Class& x) :
        CIM_LogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_LogicalFile_rtti;
    }

    //
    // CIM_LogicalFile_Class.CSCreationClassName
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
    // CIM_LogicalFile_Class.CSName
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
    // CIM_LogicalFile_Class.FSCreationClassName
    //
    
    const Field<String>& FSCreationClassName() const
    {
        const size_t n = offsetof(Self, FSCreationClassName);
        return GetField<String>(n);
    }
    
    void FSCreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, FSCreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& FSCreationClassName_value() const
    {
        const size_t n = offsetof(Self, FSCreationClassName);
        return GetField<String>(n).value;
    }
    
    void FSCreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, FSCreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool FSCreationClassName_exists() const
    {
        const size_t n = offsetof(Self, FSCreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void FSCreationClassName_clear()
    {
        const size_t n = offsetof(Self, FSCreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.FSName
    //
    
    const Field<String>& FSName() const
    {
        const size_t n = offsetof(Self, FSName);
        return GetField<String>(n);
    }
    
    void FSName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, FSName);
        GetField<String>(n) = x;
    }
    
    const String& FSName_value() const
    {
        const size_t n = offsetof(Self, FSName);
        return GetField<String>(n).value;
    }
    
    void FSName_value(const String& x)
    {
        const size_t n = offsetof(Self, FSName);
        GetField<String>(n).Set(x);
    }
    
    bool FSName_exists() const
    {
        const size_t n = offsetof(Self, FSName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void FSName_clear()
    {
        const size_t n = offsetof(Self, FSName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.CreationClassName
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
    // CIM_LogicalFile_Class.FileSize
    //
    
    const Field<Uint64>& FileSize() const
    {
        const size_t n = offsetof(Self, FileSize);
        return GetField<Uint64>(n);
    }
    
    void FileSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, FileSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& FileSize_value() const
    {
        const size_t n = offsetof(Self, FileSize);
        return GetField<Uint64>(n).value;
    }
    
    void FileSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, FileSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool FileSize_exists() const
    {
        const size_t n = offsetof(Self, FileSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void FileSize_clear()
    {
        const size_t n = offsetof(Self, FileSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.CreationDate
    //
    
    const Field<Datetime>& CreationDate() const
    {
        const size_t n = offsetof(Self, CreationDate);
        return GetField<Datetime>(n);
    }
    
    void CreationDate(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, CreationDate);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& CreationDate_value() const
    {
        const size_t n = offsetof(Self, CreationDate);
        return GetField<Datetime>(n).value;
    }
    
    void CreationDate_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, CreationDate);
        GetField<Datetime>(n).Set(x);
    }
    
    bool CreationDate_exists() const
    {
        const size_t n = offsetof(Self, CreationDate);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void CreationDate_clear()
    {
        const size_t n = offsetof(Self, CreationDate);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.LastModified
    //
    
    const Field<Datetime>& LastModified() const
    {
        const size_t n = offsetof(Self, LastModified);
        return GetField<Datetime>(n);
    }
    
    void LastModified(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, LastModified);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& LastModified_value() const
    {
        const size_t n = offsetof(Self, LastModified);
        return GetField<Datetime>(n).value;
    }
    
    void LastModified_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, LastModified);
        GetField<Datetime>(n).Set(x);
    }
    
    bool LastModified_exists() const
    {
        const size_t n = offsetof(Self, LastModified);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void LastModified_clear()
    {
        const size_t n = offsetof(Self, LastModified);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.LastAccessed
    //
    
    const Field<Datetime>& LastAccessed() const
    {
        const size_t n = offsetof(Self, LastAccessed);
        return GetField<Datetime>(n);
    }
    
    void LastAccessed(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, LastAccessed);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& LastAccessed_value() const
    {
        const size_t n = offsetof(Self, LastAccessed);
        return GetField<Datetime>(n).value;
    }
    
    void LastAccessed_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, LastAccessed);
        GetField<Datetime>(n).Set(x);
    }
    
    bool LastAccessed_exists() const
    {
        const size_t n = offsetof(Self, LastAccessed);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void LastAccessed_clear()
    {
        const size_t n = offsetof(Self, LastAccessed);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.Readable
    //
    
    const Field<Boolean>& Readable() const
    {
        const size_t n = offsetof(Self, Readable);
        return GetField<Boolean>(n);
    }
    
    void Readable(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Readable);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Readable_value() const
    {
        const size_t n = offsetof(Self, Readable);
        return GetField<Boolean>(n).value;
    }
    
    void Readable_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Readable);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Readable_exists() const
    {
        const size_t n = offsetof(Self, Readable);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Readable_clear()
    {
        const size_t n = offsetof(Self, Readable);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.Writeable
    //
    
    const Field<Boolean>& Writeable() const
    {
        const size_t n = offsetof(Self, Writeable);
        return GetField<Boolean>(n);
    }
    
    void Writeable(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Writeable);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Writeable_value() const
    {
        const size_t n = offsetof(Self, Writeable);
        return GetField<Boolean>(n).value;
    }
    
    void Writeable_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Writeable);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Writeable_exists() const
    {
        const size_t n = offsetof(Self, Writeable);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Writeable_clear()
    {
        const size_t n = offsetof(Self, Writeable);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.Executable
    //
    
    const Field<Boolean>& Executable() const
    {
        const size_t n = offsetof(Self, Executable);
        return GetField<Boolean>(n);
    }
    
    void Executable(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, Executable);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& Executable_value() const
    {
        const size_t n = offsetof(Self, Executable);
        return GetField<Boolean>(n).value;
    }
    
    void Executable_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, Executable);
        GetField<Boolean>(n).Set(x);
    }
    
    bool Executable_exists() const
    {
        const size_t n = offsetof(Self, Executable);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void Executable_clear()
    {
        const size_t n = offsetof(Self, Executable);
        GetField<Boolean>(n).Clear();
    }

    //
    // CIM_LogicalFile_Class.CompressionMethod
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
    // CIM_LogicalFile_Class.EncryptionMethod
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
    // CIM_LogicalFile_Class.InUseCount
    //
    
    const Field<Uint64>& InUseCount() const
    {
        const size_t n = offsetof(Self, InUseCount);
        return GetField<Uint64>(n);
    }
    
    void InUseCount(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, InUseCount);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& InUseCount_value() const
    {
        const size_t n = offsetof(Self, InUseCount);
        return GetField<Uint64>(n).value;
    }
    
    void InUseCount_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, InUseCount);
        GetField<Uint64>(n).Set(x);
    }
    
    bool InUseCount_exists() const
    {
        const size_t n = offsetof(Self, InUseCount);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void InUseCount_clear()
    {
        const size_t n = offsetof(Self, InUseCount);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<CIM_LogicalFile_Class> CIM_LogicalFile_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_LogicalFile_h */
