/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_UnixProcessStatisticalInformation_h
#define _SCX_UnixProcessStatisticalInformation_h

#include <MI.h>
#include "CIM_UnixProcessStatisticalInformation.h"

/*
**==============================================================================
**
** SCX_UnixProcessStatisticalInformation [SCX_UnixProcessStatisticalInformation]
**
** Keys:
**    Name
**    CSCreationClassName
**    CSName
**    OSCreationClassName
**    OSName
**    Handle
**    ProcessCreationClassName
**
**==============================================================================
*/

typedef struct _SCX_UnixProcessStatisticalInformation /* extends CIM_UnixProcessStatisticalInformation */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_StatisticalInformation properties */
    /*KEY*/ MI_ConstStringField Name;
    /* CIM_UnixProcessStatisticalInformation properties */
    /*KEY*/ MI_ConstStringField CSCreationClassName;
    /*KEY*/ MI_ConstStringField CSName;
    /*KEY*/ MI_ConstStringField OSCreationClassName;
    /*KEY*/ MI_ConstStringField OSName;
    /*KEY*/ MI_ConstStringField Handle;
    /*KEY*/ MI_ConstStringField ProcessCreationClassName;
    MI_ConstUint32Field CPUTime;
    MI_ConstUint64Field RealText;
    MI_ConstUint64Field RealData;
    MI_ConstUint64Field RealStack;
    MI_ConstUint64Field VirtualText;
    MI_ConstUint64Field VirtualData;
    MI_ConstUint64Field VirtualStack;
    MI_ConstUint64Field VirtualMemoryMappedFileSize;
    MI_ConstUint64Field VirtualSharedMemory;
    MI_ConstUint64Field CpuTimeDeadChildren;
    MI_ConstUint64Field SystemTimeDeadChildren;
    /* SCX_UnixProcessStatisticalInformation properties */
    MI_ConstUint64Field BlockReadsPerSecond;
    MI_ConstUint64Field BlockWritesPerSecond;
    MI_ConstUint64Field BlockTransfersPerSecond;
    MI_ConstUint8Field PercentUserTime;
    MI_ConstUint8Field PercentPrivilegedTime;
    MI_ConstUint64Field UsedMemory;
    MI_ConstUint8Field PercentUsedMemory;
    MI_ConstUint64Field PagesReadPerSec;
}
SCX_UnixProcessStatisticalInformation;

typedef struct _SCX_UnixProcessStatisticalInformation_Ref
{
    SCX_UnixProcessStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcessStatisticalInformation_Ref;

typedef struct _SCX_UnixProcessStatisticalInformation_ConstRef
{
    MI_CONST SCX_UnixProcessStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcessStatisticalInformation_ConstRef;

typedef struct _SCX_UnixProcessStatisticalInformation_Array
{
    struct _SCX_UnixProcessStatisticalInformation** data;
    MI_Uint32 size;
}
SCX_UnixProcessStatisticalInformation_Array;

typedef struct _SCX_UnixProcessStatisticalInformation_ConstArray
{
    struct _SCX_UnixProcessStatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_UnixProcessStatisticalInformation_ConstArray;

typedef struct _SCX_UnixProcessStatisticalInformation_ArrayRef
{
    SCX_UnixProcessStatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcessStatisticalInformation_ArrayRef;

typedef struct _SCX_UnixProcessStatisticalInformation_ConstArrayRef
{
    SCX_UnixProcessStatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_UnixProcessStatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_UnixProcessStatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Construct(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_UnixProcessStatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clone(
    const SCX_UnixProcessStatisticalInformation* self,
    SCX_UnixProcessStatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_UnixProcessStatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_UnixProcessStatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Destruct(SCX_UnixProcessStatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Delete(SCX_UnixProcessStatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Post(
    const SCX_UnixProcessStatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_InstanceID(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_InstanceID(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_InstanceID(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_Caption(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_Caption(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_Caption(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_Description(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_Description(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_Description(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_ElementName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_ElementName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_ElementName(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_Name(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_Name(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_Name(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_CSCreationClassName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_CSCreationClassName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_CSCreationClassName(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_CSName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_CSName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_CSName(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_OSCreationClassName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_OSCreationClassName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_OSCreationClassName(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_OSName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_OSName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_OSName(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_Handle(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        9,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_Handle(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        9,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_Handle(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        9);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_ProcessCreationClassName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        10,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_SetPtr_ProcessCreationClassName(
    SCX_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        10,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_ProcessCreationClassName(
    SCX_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        10);
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_CPUTime(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CPUTime)->value = x;
    ((MI_Uint32Field*)&self->CPUTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_CPUTime(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->CPUTime, 0, sizeof(self->CPUTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_RealText(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealText)->value = x;
    ((MI_Uint64Field*)&self->RealText)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_RealText(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->RealText, 0, sizeof(self->RealText));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_RealData(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealData)->value = x;
    ((MI_Uint64Field*)&self->RealData)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_RealData(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->RealData, 0, sizeof(self->RealData));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_RealStack(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealStack)->value = x;
    ((MI_Uint64Field*)&self->RealStack)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_RealStack(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->RealStack, 0, sizeof(self->RealStack));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_VirtualText(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualText)->value = x;
    ((MI_Uint64Field*)&self->VirtualText)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_VirtualText(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualText, 0, sizeof(self->VirtualText));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_VirtualData(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualData)->value = x;
    ((MI_Uint64Field*)&self->VirtualData)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_VirtualData(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualData, 0, sizeof(self->VirtualData));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_VirtualStack(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualStack)->value = x;
    ((MI_Uint64Field*)&self->VirtualStack)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_VirtualStack(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualStack, 0, sizeof(self->VirtualStack));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_VirtualMemoryMappedFileSize(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualMemoryMappedFileSize)->value = x;
    ((MI_Uint64Field*)&self->VirtualMemoryMappedFileSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_VirtualMemoryMappedFileSize(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualMemoryMappedFileSize, 0, sizeof(self->VirtualMemoryMappedFileSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_VirtualSharedMemory(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualSharedMemory)->value = x;
    ((MI_Uint64Field*)&self->VirtualSharedMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_VirtualSharedMemory(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualSharedMemory, 0, sizeof(self->VirtualSharedMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_CpuTimeDeadChildren(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->CpuTimeDeadChildren)->value = x;
    ((MI_Uint64Field*)&self->CpuTimeDeadChildren)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_CpuTimeDeadChildren(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->CpuTimeDeadChildren, 0, sizeof(self->CpuTimeDeadChildren));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_SystemTimeDeadChildren(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->SystemTimeDeadChildren)->value = x;
    ((MI_Uint64Field*)&self->SystemTimeDeadChildren)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_SystemTimeDeadChildren(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->SystemTimeDeadChildren, 0, sizeof(self->SystemTimeDeadChildren));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_BlockReadsPerSecond(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockReadsPerSecond)->value = x;
    ((MI_Uint64Field*)&self->BlockReadsPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_BlockReadsPerSecond(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->BlockReadsPerSecond, 0, sizeof(self->BlockReadsPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_BlockWritesPerSecond(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockWritesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->BlockWritesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_BlockWritesPerSecond(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->BlockWritesPerSecond, 0, sizeof(self->BlockWritesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_BlockTransfersPerSecond(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BlockTransfersPerSecond)->value = x;
    ((MI_Uint64Field*)&self->BlockTransfersPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_BlockTransfersPerSecond(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->BlockTransfersPerSecond, 0, sizeof(self->BlockTransfersPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_PercentUserTime(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUserTime)->value = x;
    ((MI_Uint8Field*)&self->PercentUserTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_PercentUserTime(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->PercentUserTime, 0, sizeof(self->PercentUserTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_PercentPrivilegedTime(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentPrivilegedTime)->value = x;
    ((MI_Uint8Field*)&self->PercentPrivilegedTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_PercentPrivilegedTime(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->PercentPrivilegedTime, 0, sizeof(self->PercentPrivilegedTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_UsedMemory(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UsedMemory)->value = x;
    ((MI_Uint64Field*)&self->UsedMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_UsedMemory(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->UsedMemory, 0, sizeof(self->UsedMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_PercentUsedMemory(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUsedMemory)->value = x;
    ((MI_Uint8Field*)&self->PercentUsedMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_PercentUsedMemory(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->PercentUsedMemory, 0, sizeof(self->PercentUsedMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Set_PagesReadPerSec(
    SCX_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PagesReadPerSec)->value = x;
    ((MI_Uint64Field*)&self->PagesReadPerSec)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_UnixProcessStatisticalInformation_Clear_PagesReadPerSec(
    SCX_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->PagesReadPerSec, 0, sizeof(self->PagesReadPerSec));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_UnixProcessStatisticalInformation provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_UnixProcessStatisticalInformation_Self SCX_UnixProcessStatisticalInformation_Self;

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_Load(
    SCX_UnixProcessStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_Unload(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_EnumerateInstances(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_GetInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_CreateInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* newInstance);

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_ModifyInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_UnixProcessStatisticalInformation_DeleteInstance(
    SCX_UnixProcessStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_UnixProcessStatisticalInformation* instanceName);


/*
**==============================================================================
**
** SCX_UnixProcessStatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_UnixProcessStatisticalInformation_Class : public CIM_UnixProcessStatisticalInformation_Class
{
public:
    
    typedef SCX_UnixProcessStatisticalInformation Self;
    
    SCX_UnixProcessStatisticalInformation_Class() :
        CIM_UnixProcessStatisticalInformation_Class(&SCX_UnixProcessStatisticalInformation_rtti)
    {
    }
    
    SCX_UnixProcessStatisticalInformation_Class(
        const SCX_UnixProcessStatisticalInformation* instanceName,
        bool keysOnly) :
        CIM_UnixProcessStatisticalInformation_Class(
            &SCX_UnixProcessStatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_UnixProcessStatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_UnixProcessStatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_UnixProcessStatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        CIM_UnixProcessStatisticalInformation_Class(clDecl)
    {
    }
    
    SCX_UnixProcessStatisticalInformation_Class& operator=(
        const SCX_UnixProcessStatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_UnixProcessStatisticalInformation_Class(
        const SCX_UnixProcessStatisticalInformation_Class& x) :
        CIM_UnixProcessStatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_UnixProcessStatisticalInformation_rtti;
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.BlockReadsPerSecond
    //
    
    const Field<Uint64>& BlockReadsPerSecond() const
    {
        const size_t n = offsetof(Self, BlockReadsPerSecond);
        return GetField<Uint64>(n);
    }
    
    void BlockReadsPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BlockReadsPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BlockReadsPerSecond_value() const
    {
        const size_t n = offsetof(Self, BlockReadsPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void BlockReadsPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BlockReadsPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BlockReadsPerSecond_exists() const
    {
        const size_t n = offsetof(Self, BlockReadsPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BlockReadsPerSecond_clear()
    {
        const size_t n = offsetof(Self, BlockReadsPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.BlockWritesPerSecond
    //
    
    const Field<Uint64>& BlockWritesPerSecond() const
    {
        const size_t n = offsetof(Self, BlockWritesPerSecond);
        return GetField<Uint64>(n);
    }
    
    void BlockWritesPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BlockWritesPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BlockWritesPerSecond_value() const
    {
        const size_t n = offsetof(Self, BlockWritesPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void BlockWritesPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BlockWritesPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BlockWritesPerSecond_exists() const
    {
        const size_t n = offsetof(Self, BlockWritesPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BlockWritesPerSecond_clear()
    {
        const size_t n = offsetof(Self, BlockWritesPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.BlockTransfersPerSecond
    //
    
    const Field<Uint64>& BlockTransfersPerSecond() const
    {
        const size_t n = offsetof(Self, BlockTransfersPerSecond);
        return GetField<Uint64>(n);
    }
    
    void BlockTransfersPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BlockTransfersPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BlockTransfersPerSecond_value() const
    {
        const size_t n = offsetof(Self, BlockTransfersPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void BlockTransfersPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BlockTransfersPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BlockTransfersPerSecond_exists() const
    {
        const size_t n = offsetof(Self, BlockTransfersPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BlockTransfersPerSecond_clear()
    {
        const size_t n = offsetof(Self, BlockTransfersPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.PercentUserTime
    //
    
    const Field<Uint8>& PercentUserTime() const
    {
        const size_t n = offsetof(Self, PercentUserTime);
        return GetField<Uint8>(n);
    }
    
    void PercentUserTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentUserTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentUserTime_value() const
    {
        const size_t n = offsetof(Self, PercentUserTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentUserTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentUserTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentUserTime_exists() const
    {
        const size_t n = offsetof(Self, PercentUserTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentUserTime_clear()
    {
        const size_t n = offsetof(Self, PercentUserTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.PercentPrivilegedTime
    //
    
    const Field<Uint8>& PercentPrivilegedTime() const
    {
        const size_t n = offsetof(Self, PercentPrivilegedTime);
        return GetField<Uint8>(n);
    }
    
    void PercentPrivilegedTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentPrivilegedTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentPrivilegedTime_value() const
    {
        const size_t n = offsetof(Self, PercentPrivilegedTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentPrivilegedTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentPrivilegedTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentPrivilegedTime_exists() const
    {
        const size_t n = offsetof(Self, PercentPrivilegedTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentPrivilegedTime_clear()
    {
        const size_t n = offsetof(Self, PercentPrivilegedTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.UsedMemory
    //
    
    const Field<Uint64>& UsedMemory() const
    {
        const size_t n = offsetof(Self, UsedMemory);
        return GetField<Uint64>(n);
    }
    
    void UsedMemory(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, UsedMemory);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& UsedMemory_value() const
    {
        const size_t n = offsetof(Self, UsedMemory);
        return GetField<Uint64>(n).value;
    }
    
    void UsedMemory_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, UsedMemory);
        GetField<Uint64>(n).Set(x);
    }
    
    bool UsedMemory_exists() const
    {
        const size_t n = offsetof(Self, UsedMemory);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void UsedMemory_clear()
    {
        const size_t n = offsetof(Self, UsedMemory);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.PercentUsedMemory
    //
    
    const Field<Uint8>& PercentUsedMemory() const
    {
        const size_t n = offsetof(Self, PercentUsedMemory);
        return GetField<Uint8>(n);
    }
    
    void PercentUsedMemory(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentUsedMemory);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentUsedMemory_value() const
    {
        const size_t n = offsetof(Self, PercentUsedMemory);
        return GetField<Uint8>(n).value;
    }
    
    void PercentUsedMemory_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentUsedMemory);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentUsedMemory_exists() const
    {
        const size_t n = offsetof(Self, PercentUsedMemory);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentUsedMemory_clear()
    {
        const size_t n = offsetof(Self, PercentUsedMemory);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_UnixProcessStatisticalInformation_Class.PagesReadPerSec
    //
    
    const Field<Uint64>& PagesReadPerSec() const
    {
        const size_t n = offsetof(Self, PagesReadPerSec);
        return GetField<Uint64>(n);
    }
    
    void PagesReadPerSec(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, PagesReadPerSec);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& PagesReadPerSec_value() const
    {
        const size_t n = offsetof(Self, PagesReadPerSec);
        return GetField<Uint64>(n).value;
    }
    
    void PagesReadPerSec_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, PagesReadPerSec);
        GetField<Uint64>(n).Set(x);
    }
    
    bool PagesReadPerSec_exists() const
    {
        const size_t n = offsetof(Self, PagesReadPerSec);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void PagesReadPerSec_clear()
    {
        const size_t n = offsetof(Self, PagesReadPerSec);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<SCX_UnixProcessStatisticalInformation_Class> SCX_UnixProcessStatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_UnixProcessStatisticalInformation_h */
