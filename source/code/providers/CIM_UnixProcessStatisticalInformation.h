/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_UnixProcessStatisticalInformation_h
#define _CIM_UnixProcessStatisticalInformation_h

#include <MI.h>
#include "CIM_StatisticalInformation.h"

/*
**==============================================================================
**
** CIM_UnixProcessStatisticalInformation [CIM_UnixProcessStatisticalInformation]
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

typedef struct _CIM_UnixProcessStatisticalInformation /* extends CIM_StatisticalInformation */
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
}
CIM_UnixProcessStatisticalInformation;

typedef struct _CIM_UnixProcessStatisticalInformation_Ref
{
    CIM_UnixProcessStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcessStatisticalInformation_Ref;

typedef struct _CIM_UnixProcessStatisticalInformation_ConstRef
{
    MI_CONST CIM_UnixProcessStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcessStatisticalInformation_ConstRef;

typedef struct _CIM_UnixProcessStatisticalInformation_Array
{
    struct _CIM_UnixProcessStatisticalInformation** data;
    MI_Uint32 size;
}
CIM_UnixProcessStatisticalInformation_Array;

typedef struct _CIM_UnixProcessStatisticalInformation_ConstArray
{
    struct _CIM_UnixProcessStatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_UnixProcessStatisticalInformation_ConstArray;

typedef struct _CIM_UnixProcessStatisticalInformation_ArrayRef
{
    CIM_UnixProcessStatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcessStatisticalInformation_ArrayRef;

typedef struct _CIM_UnixProcessStatisticalInformation_ConstArrayRef
{
    CIM_UnixProcessStatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_UnixProcessStatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_UnixProcessStatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Construct(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_UnixProcessStatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clone(
    const CIM_UnixProcessStatisticalInformation* self,
    CIM_UnixProcessStatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_UnixProcessStatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_UnixProcessStatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Destruct(CIM_UnixProcessStatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Delete(CIM_UnixProcessStatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Post(
    const CIM_UnixProcessStatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_InstanceID(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_InstanceID(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_InstanceID(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_Caption(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_Caption(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_Caption(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_Description(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_Description(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_Description(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_ElementName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_ElementName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_ElementName(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_Name(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_Name(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_Name(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_CSCreationClassName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_CSCreationClassName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_CSCreationClassName(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_CSName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_CSName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_CSName(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_OSCreationClassName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_OSCreationClassName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_OSCreationClassName(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_OSName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_OSName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_OSName(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_Handle(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        9,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_Handle(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        9,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_Handle(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        9);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_ProcessCreationClassName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        10,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_SetPtr_ProcessCreationClassName(
    CIM_UnixProcessStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        10,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_ProcessCreationClassName(
    CIM_UnixProcessStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        10);
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_CPUTime(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CPUTime)->value = x;
    ((MI_Uint32Field*)&self->CPUTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_CPUTime(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->CPUTime, 0, sizeof(self->CPUTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_RealText(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealText)->value = x;
    ((MI_Uint64Field*)&self->RealText)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_RealText(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->RealText, 0, sizeof(self->RealText));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_RealData(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealData)->value = x;
    ((MI_Uint64Field*)&self->RealData)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_RealData(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->RealData, 0, sizeof(self->RealData));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_RealStack(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->RealStack)->value = x;
    ((MI_Uint64Field*)&self->RealStack)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_RealStack(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->RealStack, 0, sizeof(self->RealStack));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_VirtualText(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualText)->value = x;
    ((MI_Uint64Field*)&self->VirtualText)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_VirtualText(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualText, 0, sizeof(self->VirtualText));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_VirtualData(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualData)->value = x;
    ((MI_Uint64Field*)&self->VirtualData)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_VirtualData(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualData, 0, sizeof(self->VirtualData));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_VirtualStack(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualStack)->value = x;
    ((MI_Uint64Field*)&self->VirtualStack)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_VirtualStack(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualStack, 0, sizeof(self->VirtualStack));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_VirtualMemoryMappedFileSize(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualMemoryMappedFileSize)->value = x;
    ((MI_Uint64Field*)&self->VirtualMemoryMappedFileSize)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_VirtualMemoryMappedFileSize(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualMemoryMappedFileSize, 0, sizeof(self->VirtualMemoryMappedFileSize));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_VirtualSharedMemory(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->VirtualSharedMemory)->value = x;
    ((MI_Uint64Field*)&self->VirtualSharedMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_VirtualSharedMemory(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->VirtualSharedMemory, 0, sizeof(self->VirtualSharedMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_CpuTimeDeadChildren(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->CpuTimeDeadChildren)->value = x;
    ((MI_Uint64Field*)&self->CpuTimeDeadChildren)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_CpuTimeDeadChildren(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->CpuTimeDeadChildren, 0, sizeof(self->CpuTimeDeadChildren));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Set_SystemTimeDeadChildren(
    CIM_UnixProcessStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->SystemTimeDeadChildren)->value = x;
    ((MI_Uint64Field*)&self->SystemTimeDeadChildren)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_UnixProcessStatisticalInformation_Clear_SystemTimeDeadChildren(
    CIM_UnixProcessStatisticalInformation* self)
{
    memset((void*)&self->SystemTimeDeadChildren, 0, sizeof(self->SystemTimeDeadChildren));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_UnixProcessStatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_UnixProcessStatisticalInformation_Class : public CIM_StatisticalInformation_Class
{
public:
    
    typedef CIM_UnixProcessStatisticalInformation Self;
    
    CIM_UnixProcessStatisticalInformation_Class() :
        CIM_StatisticalInformation_Class(&CIM_UnixProcessStatisticalInformation_rtti)
    {
    }
    
    CIM_UnixProcessStatisticalInformation_Class(
        const CIM_UnixProcessStatisticalInformation* instanceName,
        bool keysOnly) :
        CIM_StatisticalInformation_Class(
            &CIM_UnixProcessStatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_UnixProcessStatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_StatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_UnixProcessStatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        CIM_StatisticalInformation_Class(clDecl)
    {
    }
    
    CIM_UnixProcessStatisticalInformation_Class& operator=(
        const CIM_UnixProcessStatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_UnixProcessStatisticalInformation_Class(
        const CIM_UnixProcessStatisticalInformation_Class& x) :
        CIM_StatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_UnixProcessStatisticalInformation_rtti;
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.CSCreationClassName
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
    // CIM_UnixProcessStatisticalInformation_Class.CSName
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
    // CIM_UnixProcessStatisticalInformation_Class.OSCreationClassName
    //
    
    const Field<String>& OSCreationClassName() const
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        return GetField<String>(n);
    }
    
    void OSCreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& OSCreationClassName_value() const
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        return GetField<String>(n).value;
    }
    
    void OSCreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool OSCreationClassName_exists() const
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OSCreationClassName_clear()
    {
        const size_t n = offsetof(Self, OSCreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.OSName
    //
    
    const Field<String>& OSName() const
    {
        const size_t n = offsetof(Self, OSName);
        return GetField<String>(n);
    }
    
    void OSName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OSName);
        GetField<String>(n) = x;
    }
    
    const String& OSName_value() const
    {
        const size_t n = offsetof(Self, OSName);
        return GetField<String>(n).value;
    }
    
    void OSName_value(const String& x)
    {
        const size_t n = offsetof(Self, OSName);
        GetField<String>(n).Set(x);
    }
    
    bool OSName_exists() const
    {
        const size_t n = offsetof(Self, OSName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OSName_clear()
    {
        const size_t n = offsetof(Self, OSName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.Handle
    //
    
    const Field<String>& Handle() const
    {
        const size_t n = offsetof(Self, Handle);
        return GetField<String>(n);
    }
    
    void Handle(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Handle);
        GetField<String>(n) = x;
    }
    
    const String& Handle_value() const
    {
        const size_t n = offsetof(Self, Handle);
        return GetField<String>(n).value;
    }
    
    void Handle_value(const String& x)
    {
        const size_t n = offsetof(Self, Handle);
        GetField<String>(n).Set(x);
    }
    
    bool Handle_exists() const
    {
        const size_t n = offsetof(Self, Handle);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Handle_clear()
    {
        const size_t n = offsetof(Self, Handle);
        GetField<String>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.ProcessCreationClassName
    //
    
    const Field<String>& ProcessCreationClassName() const
    {
        const size_t n = offsetof(Self, ProcessCreationClassName);
        return GetField<String>(n);
    }
    
    void ProcessCreationClassName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ProcessCreationClassName);
        GetField<String>(n) = x;
    }
    
    const String& ProcessCreationClassName_value() const
    {
        const size_t n = offsetof(Self, ProcessCreationClassName);
        return GetField<String>(n).value;
    }
    
    void ProcessCreationClassName_value(const String& x)
    {
        const size_t n = offsetof(Self, ProcessCreationClassName);
        GetField<String>(n).Set(x);
    }
    
    bool ProcessCreationClassName_exists() const
    {
        const size_t n = offsetof(Self, ProcessCreationClassName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ProcessCreationClassName_clear()
    {
        const size_t n = offsetof(Self, ProcessCreationClassName);
        GetField<String>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.CPUTime
    //
    
    const Field<Uint32>& CPUTime() const
    {
        const size_t n = offsetof(Self, CPUTime);
        return GetField<Uint32>(n);
    }
    
    void CPUTime(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, CPUTime);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& CPUTime_value() const
    {
        const size_t n = offsetof(Self, CPUTime);
        return GetField<Uint32>(n).value;
    }
    
    void CPUTime_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, CPUTime);
        GetField<Uint32>(n).Set(x);
    }
    
    bool CPUTime_exists() const
    {
        const size_t n = offsetof(Self, CPUTime);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void CPUTime_clear()
    {
        const size_t n = offsetof(Self, CPUTime);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.RealText
    //
    
    const Field<Uint64>& RealText() const
    {
        const size_t n = offsetof(Self, RealText);
        return GetField<Uint64>(n);
    }
    
    void RealText(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, RealText);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& RealText_value() const
    {
        const size_t n = offsetof(Self, RealText);
        return GetField<Uint64>(n).value;
    }
    
    void RealText_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, RealText);
        GetField<Uint64>(n).Set(x);
    }
    
    bool RealText_exists() const
    {
        const size_t n = offsetof(Self, RealText);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void RealText_clear()
    {
        const size_t n = offsetof(Self, RealText);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.RealData
    //
    
    const Field<Uint64>& RealData() const
    {
        const size_t n = offsetof(Self, RealData);
        return GetField<Uint64>(n);
    }
    
    void RealData(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, RealData);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& RealData_value() const
    {
        const size_t n = offsetof(Self, RealData);
        return GetField<Uint64>(n).value;
    }
    
    void RealData_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, RealData);
        GetField<Uint64>(n).Set(x);
    }
    
    bool RealData_exists() const
    {
        const size_t n = offsetof(Self, RealData);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void RealData_clear()
    {
        const size_t n = offsetof(Self, RealData);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.RealStack
    //
    
    const Field<Uint64>& RealStack() const
    {
        const size_t n = offsetof(Self, RealStack);
        return GetField<Uint64>(n);
    }
    
    void RealStack(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, RealStack);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& RealStack_value() const
    {
        const size_t n = offsetof(Self, RealStack);
        return GetField<Uint64>(n).value;
    }
    
    void RealStack_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, RealStack);
        GetField<Uint64>(n).Set(x);
    }
    
    bool RealStack_exists() const
    {
        const size_t n = offsetof(Self, RealStack);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void RealStack_clear()
    {
        const size_t n = offsetof(Self, RealStack);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.VirtualText
    //
    
    const Field<Uint64>& VirtualText() const
    {
        const size_t n = offsetof(Self, VirtualText);
        return GetField<Uint64>(n);
    }
    
    void VirtualText(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, VirtualText);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& VirtualText_value() const
    {
        const size_t n = offsetof(Self, VirtualText);
        return GetField<Uint64>(n).value;
    }
    
    void VirtualText_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, VirtualText);
        GetField<Uint64>(n).Set(x);
    }
    
    bool VirtualText_exists() const
    {
        const size_t n = offsetof(Self, VirtualText);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void VirtualText_clear()
    {
        const size_t n = offsetof(Self, VirtualText);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.VirtualData
    //
    
    const Field<Uint64>& VirtualData() const
    {
        const size_t n = offsetof(Self, VirtualData);
        return GetField<Uint64>(n);
    }
    
    void VirtualData(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, VirtualData);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& VirtualData_value() const
    {
        const size_t n = offsetof(Self, VirtualData);
        return GetField<Uint64>(n).value;
    }
    
    void VirtualData_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, VirtualData);
        GetField<Uint64>(n).Set(x);
    }
    
    bool VirtualData_exists() const
    {
        const size_t n = offsetof(Self, VirtualData);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void VirtualData_clear()
    {
        const size_t n = offsetof(Self, VirtualData);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.VirtualStack
    //
    
    const Field<Uint64>& VirtualStack() const
    {
        const size_t n = offsetof(Self, VirtualStack);
        return GetField<Uint64>(n);
    }
    
    void VirtualStack(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, VirtualStack);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& VirtualStack_value() const
    {
        const size_t n = offsetof(Self, VirtualStack);
        return GetField<Uint64>(n).value;
    }
    
    void VirtualStack_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, VirtualStack);
        GetField<Uint64>(n).Set(x);
    }
    
    bool VirtualStack_exists() const
    {
        const size_t n = offsetof(Self, VirtualStack);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void VirtualStack_clear()
    {
        const size_t n = offsetof(Self, VirtualStack);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.VirtualMemoryMappedFileSize
    //
    
    const Field<Uint64>& VirtualMemoryMappedFileSize() const
    {
        const size_t n = offsetof(Self, VirtualMemoryMappedFileSize);
        return GetField<Uint64>(n);
    }
    
    void VirtualMemoryMappedFileSize(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, VirtualMemoryMappedFileSize);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& VirtualMemoryMappedFileSize_value() const
    {
        const size_t n = offsetof(Self, VirtualMemoryMappedFileSize);
        return GetField<Uint64>(n).value;
    }
    
    void VirtualMemoryMappedFileSize_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, VirtualMemoryMappedFileSize);
        GetField<Uint64>(n).Set(x);
    }
    
    bool VirtualMemoryMappedFileSize_exists() const
    {
        const size_t n = offsetof(Self, VirtualMemoryMappedFileSize);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void VirtualMemoryMappedFileSize_clear()
    {
        const size_t n = offsetof(Self, VirtualMemoryMappedFileSize);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.VirtualSharedMemory
    //
    
    const Field<Uint64>& VirtualSharedMemory() const
    {
        const size_t n = offsetof(Self, VirtualSharedMemory);
        return GetField<Uint64>(n);
    }
    
    void VirtualSharedMemory(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, VirtualSharedMemory);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& VirtualSharedMemory_value() const
    {
        const size_t n = offsetof(Self, VirtualSharedMemory);
        return GetField<Uint64>(n).value;
    }
    
    void VirtualSharedMemory_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, VirtualSharedMemory);
        GetField<Uint64>(n).Set(x);
    }
    
    bool VirtualSharedMemory_exists() const
    {
        const size_t n = offsetof(Self, VirtualSharedMemory);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void VirtualSharedMemory_clear()
    {
        const size_t n = offsetof(Self, VirtualSharedMemory);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.CpuTimeDeadChildren
    //
    
    const Field<Uint64>& CpuTimeDeadChildren() const
    {
        const size_t n = offsetof(Self, CpuTimeDeadChildren);
        return GetField<Uint64>(n);
    }
    
    void CpuTimeDeadChildren(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, CpuTimeDeadChildren);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& CpuTimeDeadChildren_value() const
    {
        const size_t n = offsetof(Self, CpuTimeDeadChildren);
        return GetField<Uint64>(n).value;
    }
    
    void CpuTimeDeadChildren_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, CpuTimeDeadChildren);
        GetField<Uint64>(n).Set(x);
    }
    
    bool CpuTimeDeadChildren_exists() const
    {
        const size_t n = offsetof(Self, CpuTimeDeadChildren);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void CpuTimeDeadChildren_clear()
    {
        const size_t n = offsetof(Self, CpuTimeDeadChildren);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_UnixProcessStatisticalInformation_Class.SystemTimeDeadChildren
    //
    
    const Field<Uint64>& SystemTimeDeadChildren() const
    {
        const size_t n = offsetof(Self, SystemTimeDeadChildren);
        return GetField<Uint64>(n);
    }
    
    void SystemTimeDeadChildren(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, SystemTimeDeadChildren);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& SystemTimeDeadChildren_value() const
    {
        const size_t n = offsetof(Self, SystemTimeDeadChildren);
        return GetField<Uint64>(n).value;
    }
    
    void SystemTimeDeadChildren_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, SystemTimeDeadChildren);
        GetField<Uint64>(n).Set(x);
    }
    
    bool SystemTimeDeadChildren_exists() const
    {
        const size_t n = offsetof(Self, SystemTimeDeadChildren);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void SystemTimeDeadChildren_clear()
    {
        const size_t n = offsetof(Self, SystemTimeDeadChildren);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<CIM_UnixProcessStatisticalInformation_Class> CIM_UnixProcessStatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_UnixProcessStatisticalInformation_h */
