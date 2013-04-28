/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_LogFile_h
#define _SCX_LogFile_h

#include <MI.h>
#include "CIM_LogicalFile.h"

/*
**==============================================================================
**
** SCX_LogFile [SCX_LogFile]
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

typedef struct _SCX_LogFile /* extends CIM_LogicalFile */
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
    /* SCX_LogFile properties */
}
SCX_LogFile;

typedef struct _SCX_LogFile_Ref
{
    SCX_LogFile* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_LogFile_Ref;

typedef struct _SCX_LogFile_ConstRef
{
    MI_CONST SCX_LogFile* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_LogFile_ConstRef;

typedef struct _SCX_LogFile_Array
{
    struct _SCX_LogFile** data;
    MI_Uint32 size;
}
SCX_LogFile_Array;

typedef struct _SCX_LogFile_ConstArray
{
    struct _SCX_LogFile MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_LogFile_ConstArray;

typedef struct _SCX_LogFile_ArrayRef
{
    SCX_LogFile_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_LogFile_ArrayRef;

typedef struct _SCX_LogFile_ConstArrayRef
{
    SCX_LogFile_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_LogFile_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_LogFile_rtti;

MI_INLINE MI_Result MI_CALL SCX_LogFile_Construct(
    SCX_LogFile* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_LogFile_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clone(
    const SCX_LogFile* self,
    SCX_LogFile** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_LogFile_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_LogFile_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Destruct(SCX_LogFile* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Delete(SCX_LogFile* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Post(
    const SCX_LogFile* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_InstanceID(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_InstanceID(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_InstanceID(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_Caption(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_Caption(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_Caption(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_Description(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_Description(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_Description(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_ElementName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_ElementName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_ElementName(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_InstallDate(
    SCX_LogFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_InstallDate(
    SCX_LogFile* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_Name(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_Name(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_Name(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_OperationalStatus(
    SCX_LogFile* self,
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

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_OperationalStatus(
    SCX_LogFile* self,
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

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_OperationalStatus(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_StatusDescriptions(
    SCX_LogFile* self,
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

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_StatusDescriptions(
    SCX_LogFile* self,
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

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_StatusDescriptions(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_Status(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_Status(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_Status(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_HealthState(
    SCX_LogFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_HealthState(
    SCX_LogFile* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_CommunicationStatus(
    SCX_LogFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_CommunicationStatus(
    SCX_LogFile* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_DetailedStatus(
    SCX_LogFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_DetailedStatus(
    SCX_LogFile* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_OperatingStatus(
    SCX_LogFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_OperatingStatus(
    SCX_LogFile* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_PrimaryStatus(
    SCX_LogFile* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_PrimaryStatus(
    SCX_LogFile* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_CSCreationClassName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_CSCreationClassName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_CSCreationClassName(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        14);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_CSName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_CSName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_CSName(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_FSCreationClassName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        16,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_FSCreationClassName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        16,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_FSCreationClassName(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        16);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_FSName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        17,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_FSName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        17,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_FSName(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        17);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_CreationClassName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        18,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_CreationClassName(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        18,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_CreationClassName(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        18);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_FileSize(
    SCX_LogFile* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FileSize)->value = x;
    ((MI_Uint64Field*)&self->FileSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_FileSize(
    SCX_LogFile* self)
{
    memset((void*)&self->FileSize, 0, sizeof(self->FileSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_CreationDate(
    SCX_LogFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->CreationDate)->value = x;
    ((MI_DatetimeField*)&self->CreationDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_CreationDate(
    SCX_LogFile* self)
{
    memset((void*)&self->CreationDate, 0, sizeof(self->CreationDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_LastModified(
    SCX_LogFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastModified)->value = x;
    ((MI_DatetimeField*)&self->LastModified)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_LastModified(
    SCX_LogFile* self)
{
    memset((void*)&self->LastModified, 0, sizeof(self->LastModified));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_LastAccessed(
    SCX_LogFile* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->LastAccessed)->value = x;
    ((MI_DatetimeField*)&self->LastAccessed)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_LastAccessed(
    SCX_LogFile* self)
{
    memset((void*)&self->LastAccessed, 0, sizeof(self->LastAccessed));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_Readable(
    SCX_LogFile* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Readable)->value = x;
    ((MI_BooleanField*)&self->Readable)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_Readable(
    SCX_LogFile* self)
{
    memset((void*)&self->Readable, 0, sizeof(self->Readable));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_Writeable(
    SCX_LogFile* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Writeable)->value = x;
    ((MI_BooleanField*)&self->Writeable)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_Writeable(
    SCX_LogFile* self)
{
    memset((void*)&self->Writeable, 0, sizeof(self->Writeable));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_Executable(
    SCX_LogFile* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->Executable)->value = x;
    ((MI_BooleanField*)&self->Executable)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_Executable(
    SCX_LogFile* self)
{
    memset((void*)&self->Executable, 0, sizeof(self->Executable));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_CompressionMethod(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_CompressionMethod(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        26,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_CompressionMethod(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        26);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_EncryptionMethod(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_SetPtr_EncryptionMethod(
    SCX_LogFile* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        27,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_EncryptionMethod(
    SCX_LogFile* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        27);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Set_InUseCount(
    SCX_LogFile* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->InUseCount)->value = x;
    ((MI_Uint64Field*)&self->InUseCount)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_Clear_InUseCount(
    SCX_LogFile* self)
{
    memset((void*)&self->InUseCount, 0, sizeof(self->InUseCount));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_LogFile.GetMatchedRows()
**
**==============================================================================
*/

typedef struct _SCX_LogFile_GetMatchedRows
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstStringField filename;
    /*IN*/ MI_ConstStringAField regexps;
    /*IN*/ MI_ConstStringField qid;
    /*OUT*/ MI_ConstStringAField rows;
    /*IN*/ MI_ConstStringField elevationType;
}
SCX_LogFile_GetMatchedRows;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_LogFile_GetMatchedRows_rtti;

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Construct(
    SCX_LogFile_GetMatchedRows* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_LogFile_GetMatchedRows_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Clone(
    const SCX_LogFile_GetMatchedRows* self,
    SCX_LogFile_GetMatchedRows** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Destruct(
    SCX_LogFile_GetMatchedRows* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Delete(
    SCX_LogFile_GetMatchedRows* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Post(
    const SCX_LogFile_GetMatchedRows* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Set_MIReturn(
    SCX_LogFile_GetMatchedRows* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Clear_MIReturn(
    SCX_LogFile_GetMatchedRows* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Set_filename(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_SetPtr_filename(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Clear_filename(
    SCX_LogFile_GetMatchedRows* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Set_regexps(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_SetPtr_regexps(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Clear_regexps(
    SCX_LogFile_GetMatchedRows* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Set_qid(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_SetPtr_qid(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Clear_qid(
    SCX_LogFile_GetMatchedRows* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Set_rows(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_SetPtr_rows(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Clear_rows(
    SCX_LogFile_GetMatchedRows* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Set_elevationType(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_SetPtr_elevationType(
    SCX_LogFile_GetMatchedRows* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_LogFile_GetMatchedRows_Clear_elevationType(
    SCX_LogFile_GetMatchedRows* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

/*
**==============================================================================
**
** SCX_LogFile provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_LogFile_Self SCX_LogFile_Self;

MI_EXTERN_C void MI_CALL SCX_LogFile_Load(
    SCX_LogFile_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_LogFile_Unload(
    SCX_LogFile_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_LogFile_EnumerateInstances(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_LogFile_GetInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_LogFile_CreateInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* newInstance);

MI_EXTERN_C void MI_CALL SCX_LogFile_ModifyInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_LogFile_DeleteInstance(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_LogFile* instanceName);

MI_EXTERN_C void MI_CALL SCX_LogFile_Invoke_GetMatchedRows(
    SCX_LogFile_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_LogFile* instanceName,
    const SCX_LogFile_GetMatchedRows* in);


/*
**==============================================================================
**
** SCX_LogFile_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_LogFile_Class : public CIM_LogicalFile_Class
{
public:
    
    typedef SCX_LogFile Self;
    
    SCX_LogFile_Class() :
        CIM_LogicalFile_Class(&SCX_LogFile_rtti)
    {
    }
    
    SCX_LogFile_Class(
        const SCX_LogFile* instanceName,
        bool keysOnly) :
        CIM_LogicalFile_Class(
            &SCX_LogFile_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_LogFile_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalFile_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_LogFile_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalFile_Class(clDecl)
    {
    }
    
    SCX_LogFile_Class& operator=(
        const SCX_LogFile_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_LogFile_Class(
        const SCX_LogFile_Class& x) :
        CIM_LogicalFile_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_LogFile_rtti;
    }

};

typedef Array<SCX_LogFile_Class> SCX_LogFile_ClassA;

class SCX_LogFile_GetMatchedRows_Class : public Instance
{
public:
    
    typedef SCX_LogFile_GetMatchedRows Self;
    
    SCX_LogFile_GetMatchedRows_Class() :
        Instance(&SCX_LogFile_GetMatchedRows_rtti)
    {
    }
    
    SCX_LogFile_GetMatchedRows_Class(
        const SCX_LogFile_GetMatchedRows* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_LogFile_GetMatchedRows_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_LogFile_GetMatchedRows_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_LogFile_GetMatchedRows_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_LogFile_GetMatchedRows_Class& operator=(
        const SCX_LogFile_GetMatchedRows_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_LogFile_GetMatchedRows_Class(
        const SCX_LogFile_GetMatchedRows_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_LogFile_GetMatchedRows_Class.MIReturn
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
    // SCX_LogFile_GetMatchedRows_Class.filename
    //
    
    const Field<String>& filename() const
    {
        const size_t n = offsetof(Self, filename);
        return GetField<String>(n);
    }
    
    void filename(const Field<String>& x)
    {
        const size_t n = offsetof(Self, filename);
        GetField<String>(n) = x;
    }
    
    const String& filename_value() const
    {
        const size_t n = offsetof(Self, filename);
        return GetField<String>(n).value;
    }
    
    void filename_value(const String& x)
    {
        const size_t n = offsetof(Self, filename);
        GetField<String>(n).Set(x);
    }
    
    bool filename_exists() const
    {
        const size_t n = offsetof(Self, filename);
        return GetField<String>(n).exists ? true : false;
    }
    
    void filename_clear()
    {
        const size_t n = offsetof(Self, filename);
        GetField<String>(n).Clear();
    }

    //
    // SCX_LogFile_GetMatchedRows_Class.regexps
    //
    
    const Field<StringA>& regexps() const
    {
        const size_t n = offsetof(Self, regexps);
        return GetField<StringA>(n);
    }
    
    void regexps(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, regexps);
        GetField<StringA>(n) = x;
    }
    
    const StringA& regexps_value() const
    {
        const size_t n = offsetof(Self, regexps);
        return GetField<StringA>(n).value;
    }
    
    void regexps_value(const StringA& x)
    {
        const size_t n = offsetof(Self, regexps);
        GetField<StringA>(n).Set(x);
    }
    
    bool regexps_exists() const
    {
        const size_t n = offsetof(Self, regexps);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void regexps_clear()
    {
        const size_t n = offsetof(Self, regexps);
        GetField<StringA>(n).Clear();
    }

    //
    // SCX_LogFile_GetMatchedRows_Class.qid
    //
    
    const Field<String>& qid() const
    {
        const size_t n = offsetof(Self, qid);
        return GetField<String>(n);
    }
    
    void qid(const Field<String>& x)
    {
        const size_t n = offsetof(Self, qid);
        GetField<String>(n) = x;
    }
    
    const String& qid_value() const
    {
        const size_t n = offsetof(Self, qid);
        return GetField<String>(n).value;
    }
    
    void qid_value(const String& x)
    {
        const size_t n = offsetof(Self, qid);
        GetField<String>(n).Set(x);
    }
    
    bool qid_exists() const
    {
        const size_t n = offsetof(Self, qid);
        return GetField<String>(n).exists ? true : false;
    }
    
    void qid_clear()
    {
        const size_t n = offsetof(Self, qid);
        GetField<String>(n).Clear();
    }

    //
    // SCX_LogFile_GetMatchedRows_Class.rows
    //
    
    const Field<StringA>& rows() const
    {
        const size_t n = offsetof(Self, rows);
        return GetField<StringA>(n);
    }
    
    void rows(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, rows);
        GetField<StringA>(n) = x;
    }
    
    const StringA& rows_value() const
    {
        const size_t n = offsetof(Self, rows);
        return GetField<StringA>(n).value;
    }
    
    void rows_value(const StringA& x)
    {
        const size_t n = offsetof(Self, rows);
        GetField<StringA>(n).Set(x);
    }
    
    bool rows_exists() const
    {
        const size_t n = offsetof(Self, rows);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void rows_clear()
    {
        const size_t n = offsetof(Self, rows);
        GetField<StringA>(n).Clear();
    }

    //
    // SCX_LogFile_GetMatchedRows_Class.elevationType
    //
    
    const Field<String>& elevationType() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n);
    }
    
    void elevationType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n) = x;
    }
    
    const String& elevationType_value() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n).value;
    }
    
    void elevationType_value(const String& x)
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n).Set(x);
    }
    
    bool elevationType_exists() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void elevationType_clear()
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_LogFile_GetMatchedRows_Class> SCX_LogFile_GetMatchedRows_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_LogFile_h */
