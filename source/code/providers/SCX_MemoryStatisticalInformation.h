/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_MemoryStatisticalInformation_h
#define _SCX_MemoryStatisticalInformation_h

#include <MI.h>
#include "SCX_StatisticalInformation.h"

/*
**==============================================================================
**
** SCX_MemoryStatisticalInformation [SCX_MemoryStatisticalInformation]
**
** Keys:
**    Name
**
**==============================================================================
*/

typedef struct _SCX_MemoryStatisticalInformation /* extends SCX_StatisticalInformation */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_StatisticalInformation properties */
    /*KEY*/ MI_ConstStringField Name;
    /* SCX_StatisticalInformation properties */
    MI_ConstBooleanField IsAggregate;
    /* SCX_MemoryStatisticalInformation properties */
    MI_ConstUint64Field AvailableMemory;
    MI_ConstUint8Field PercentAvailableMemory;
    MI_ConstUint64Field UsedMemory;
    MI_ConstUint8Field PercentUsedMemory;
    MI_ConstUint8Field PercentUsedByCache;
    MI_ConstUint64Field PagesPerSec;
    MI_ConstUint64Field PagesReadPerSec;
    MI_ConstUint64Field PagesWrittenPerSec;
    MI_ConstUint64Field AvailableSwap;
    MI_ConstUint8Field PercentAvailableSwap;
    MI_ConstUint64Field UsedSwap;
    MI_ConstUint8Field PercentUsedSwap;
}
SCX_MemoryStatisticalInformation;

typedef struct _SCX_MemoryStatisticalInformation_Ref
{
    SCX_MemoryStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_MemoryStatisticalInformation_Ref;

typedef struct _SCX_MemoryStatisticalInformation_ConstRef
{
    MI_CONST SCX_MemoryStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_MemoryStatisticalInformation_ConstRef;

typedef struct _SCX_MemoryStatisticalInformation_Array
{
    struct _SCX_MemoryStatisticalInformation** data;
    MI_Uint32 size;
}
SCX_MemoryStatisticalInformation_Array;

typedef struct _SCX_MemoryStatisticalInformation_ConstArray
{
    struct _SCX_MemoryStatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_MemoryStatisticalInformation_ConstArray;

typedef struct _SCX_MemoryStatisticalInformation_ArrayRef
{
    SCX_MemoryStatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_MemoryStatisticalInformation_ArrayRef;

typedef struct _SCX_MemoryStatisticalInformation_ConstArrayRef
{
    SCX_MemoryStatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_MemoryStatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_MemoryStatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Construct(
    SCX_MemoryStatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_MemoryStatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clone(
    const SCX_MemoryStatisticalInformation* self,
    SCX_MemoryStatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_MemoryStatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_MemoryStatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Destruct(SCX_MemoryStatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Delete(SCX_MemoryStatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Post(
    const SCX_MemoryStatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_InstanceID(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_SetPtr_InstanceID(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_InstanceID(
    SCX_MemoryStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_Caption(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_SetPtr_Caption(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_Caption(
    SCX_MemoryStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_Description(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_SetPtr_Description(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_Description(
    SCX_MemoryStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_ElementName(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_SetPtr_ElementName(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_ElementName(
    SCX_MemoryStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_Name(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_SetPtr_Name(
    SCX_MemoryStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_Name(
    SCX_MemoryStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_IsAggregate(
    SCX_MemoryStatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsAggregate)->value = x;
    ((MI_BooleanField*)&self->IsAggregate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_IsAggregate(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->IsAggregate, 0, sizeof(self->IsAggregate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_AvailableMemory(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->AvailableMemory)->value = x;
    ((MI_Uint64Field*)&self->AvailableMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_AvailableMemory(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->AvailableMemory, 0, sizeof(self->AvailableMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PercentAvailableMemory(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentAvailableMemory)->value = x;
    ((MI_Uint8Field*)&self->PercentAvailableMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PercentAvailableMemory(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PercentAvailableMemory, 0, sizeof(self->PercentAvailableMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_UsedMemory(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UsedMemory)->value = x;
    ((MI_Uint64Field*)&self->UsedMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_UsedMemory(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->UsedMemory, 0, sizeof(self->UsedMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PercentUsedMemory(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUsedMemory)->value = x;
    ((MI_Uint8Field*)&self->PercentUsedMemory)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PercentUsedMemory(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PercentUsedMemory, 0, sizeof(self->PercentUsedMemory));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PercentUsedByCache(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUsedByCache)->value = x;
    ((MI_Uint8Field*)&self->PercentUsedByCache)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PercentUsedByCache(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PercentUsedByCache, 0, sizeof(self->PercentUsedByCache));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PagesPerSec(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PagesPerSec)->value = x;
    ((MI_Uint64Field*)&self->PagesPerSec)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PagesPerSec(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PagesPerSec, 0, sizeof(self->PagesPerSec));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PagesReadPerSec(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PagesReadPerSec)->value = x;
    ((MI_Uint64Field*)&self->PagesReadPerSec)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PagesReadPerSec(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PagesReadPerSec, 0, sizeof(self->PagesReadPerSec));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PagesWrittenPerSec(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PagesWrittenPerSec)->value = x;
    ((MI_Uint64Field*)&self->PagesWrittenPerSec)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PagesWrittenPerSec(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PagesWrittenPerSec, 0, sizeof(self->PagesWrittenPerSec));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_AvailableSwap(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->AvailableSwap)->value = x;
    ((MI_Uint64Field*)&self->AvailableSwap)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_AvailableSwap(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->AvailableSwap, 0, sizeof(self->AvailableSwap));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PercentAvailableSwap(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentAvailableSwap)->value = x;
    ((MI_Uint8Field*)&self->PercentAvailableSwap)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PercentAvailableSwap(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PercentAvailableSwap, 0, sizeof(self->PercentAvailableSwap));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_UsedSwap(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UsedSwap)->value = x;
    ((MI_Uint64Field*)&self->UsedSwap)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_UsedSwap(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->UsedSwap, 0, sizeof(self->UsedSwap));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Set_PercentUsedSwap(
    SCX_MemoryStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUsedSwap)->value = x;
    ((MI_Uint8Field*)&self->PercentUsedSwap)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_MemoryStatisticalInformation_Clear_PercentUsedSwap(
    SCX_MemoryStatisticalInformation* self)
{
    memset((void*)&self->PercentUsedSwap, 0, sizeof(self->PercentUsedSwap));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_MemoryStatisticalInformation provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_MemoryStatisticalInformation_Self SCX_MemoryStatisticalInformation_Self;

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_Load(
    SCX_MemoryStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_Unload(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_EnumerateInstances(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_GetInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_CreateInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* newInstance);

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_ModifyInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_MemoryStatisticalInformation_DeleteInstance(
    SCX_MemoryStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_MemoryStatisticalInformation* instanceName);


/*
**==============================================================================
**
** SCX_MemoryStatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_MemoryStatisticalInformation_Class : public SCX_StatisticalInformation_Class
{
public:
    
    typedef SCX_MemoryStatisticalInformation Self;
    
    SCX_MemoryStatisticalInformation_Class() :
        SCX_StatisticalInformation_Class(&SCX_MemoryStatisticalInformation_rtti)
    {
    }
    
    SCX_MemoryStatisticalInformation_Class(
        const SCX_MemoryStatisticalInformation* instanceName,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(
            &SCX_MemoryStatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_MemoryStatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_MemoryStatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        SCX_StatisticalInformation_Class(clDecl)
    {
    }
    
    SCX_MemoryStatisticalInformation_Class& operator=(
        const SCX_MemoryStatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_MemoryStatisticalInformation_Class(
        const SCX_MemoryStatisticalInformation_Class& x) :
        SCX_StatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_MemoryStatisticalInformation_rtti;
    }

    //
    // SCX_MemoryStatisticalInformation_Class.AvailableMemory
    //
    
    const Field<Uint64>& AvailableMemory() const
    {
        const size_t n = offsetof(Self, AvailableMemory);
        return GetField<Uint64>(n);
    }
    
    void AvailableMemory(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, AvailableMemory);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& AvailableMemory_value() const
    {
        const size_t n = offsetof(Self, AvailableMemory);
        return GetField<Uint64>(n).value;
    }
    
    void AvailableMemory_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, AvailableMemory);
        GetField<Uint64>(n).Set(x);
    }
    
    bool AvailableMemory_exists() const
    {
        const size_t n = offsetof(Self, AvailableMemory);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void AvailableMemory_clear()
    {
        const size_t n = offsetof(Self, AvailableMemory);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.PercentAvailableMemory
    //
    
    const Field<Uint8>& PercentAvailableMemory() const
    {
        const size_t n = offsetof(Self, PercentAvailableMemory);
        return GetField<Uint8>(n);
    }
    
    void PercentAvailableMemory(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentAvailableMemory);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentAvailableMemory_value() const
    {
        const size_t n = offsetof(Self, PercentAvailableMemory);
        return GetField<Uint8>(n).value;
    }
    
    void PercentAvailableMemory_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentAvailableMemory);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentAvailableMemory_exists() const
    {
        const size_t n = offsetof(Self, PercentAvailableMemory);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentAvailableMemory_clear()
    {
        const size_t n = offsetof(Self, PercentAvailableMemory);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.UsedMemory
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
    // SCX_MemoryStatisticalInformation_Class.PercentUsedMemory
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
    // SCX_MemoryStatisticalInformation_Class.PercentUsedByCache
    //
    
    const Field<Uint8>& PercentUsedByCache() const
    {
        const size_t n = offsetof(Self, PercentUsedByCache);
        return GetField<Uint8>(n);
    }
    
    void PercentUsedByCache(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentUsedByCache);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentUsedByCache_value() const
    {
        const size_t n = offsetof(Self, PercentUsedByCache);
        return GetField<Uint8>(n).value;
    }
    
    void PercentUsedByCache_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentUsedByCache);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentUsedByCache_exists() const
    {
        const size_t n = offsetof(Self, PercentUsedByCache);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentUsedByCache_clear()
    {
        const size_t n = offsetof(Self, PercentUsedByCache);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.PagesPerSec
    //
    
    const Field<Uint64>& PagesPerSec() const
    {
        const size_t n = offsetof(Self, PagesPerSec);
        return GetField<Uint64>(n);
    }
    
    void PagesPerSec(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, PagesPerSec);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& PagesPerSec_value() const
    {
        const size_t n = offsetof(Self, PagesPerSec);
        return GetField<Uint64>(n).value;
    }
    
    void PagesPerSec_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, PagesPerSec);
        GetField<Uint64>(n).Set(x);
    }
    
    bool PagesPerSec_exists() const
    {
        const size_t n = offsetof(Self, PagesPerSec);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void PagesPerSec_clear()
    {
        const size_t n = offsetof(Self, PagesPerSec);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.PagesReadPerSec
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

    //
    // SCX_MemoryStatisticalInformation_Class.PagesWrittenPerSec
    //
    
    const Field<Uint64>& PagesWrittenPerSec() const
    {
        const size_t n = offsetof(Self, PagesWrittenPerSec);
        return GetField<Uint64>(n);
    }
    
    void PagesWrittenPerSec(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, PagesWrittenPerSec);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& PagesWrittenPerSec_value() const
    {
        const size_t n = offsetof(Self, PagesWrittenPerSec);
        return GetField<Uint64>(n).value;
    }
    
    void PagesWrittenPerSec_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, PagesWrittenPerSec);
        GetField<Uint64>(n).Set(x);
    }
    
    bool PagesWrittenPerSec_exists() const
    {
        const size_t n = offsetof(Self, PagesWrittenPerSec);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void PagesWrittenPerSec_clear()
    {
        const size_t n = offsetof(Self, PagesWrittenPerSec);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.AvailableSwap
    //
    
    const Field<Uint64>& AvailableSwap() const
    {
        const size_t n = offsetof(Self, AvailableSwap);
        return GetField<Uint64>(n);
    }
    
    void AvailableSwap(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, AvailableSwap);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& AvailableSwap_value() const
    {
        const size_t n = offsetof(Self, AvailableSwap);
        return GetField<Uint64>(n).value;
    }
    
    void AvailableSwap_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, AvailableSwap);
        GetField<Uint64>(n).Set(x);
    }
    
    bool AvailableSwap_exists() const
    {
        const size_t n = offsetof(Self, AvailableSwap);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void AvailableSwap_clear()
    {
        const size_t n = offsetof(Self, AvailableSwap);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.PercentAvailableSwap
    //
    
    const Field<Uint8>& PercentAvailableSwap() const
    {
        const size_t n = offsetof(Self, PercentAvailableSwap);
        return GetField<Uint8>(n);
    }
    
    void PercentAvailableSwap(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentAvailableSwap);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentAvailableSwap_value() const
    {
        const size_t n = offsetof(Self, PercentAvailableSwap);
        return GetField<Uint8>(n).value;
    }
    
    void PercentAvailableSwap_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentAvailableSwap);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentAvailableSwap_exists() const
    {
        const size_t n = offsetof(Self, PercentAvailableSwap);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentAvailableSwap_clear()
    {
        const size_t n = offsetof(Self, PercentAvailableSwap);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.UsedSwap
    //
    
    const Field<Uint64>& UsedSwap() const
    {
        const size_t n = offsetof(Self, UsedSwap);
        return GetField<Uint64>(n);
    }
    
    void UsedSwap(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, UsedSwap);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& UsedSwap_value() const
    {
        const size_t n = offsetof(Self, UsedSwap);
        return GetField<Uint64>(n).value;
    }
    
    void UsedSwap_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, UsedSwap);
        GetField<Uint64>(n).Set(x);
    }
    
    bool UsedSwap_exists() const
    {
        const size_t n = offsetof(Self, UsedSwap);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void UsedSwap_clear()
    {
        const size_t n = offsetof(Self, UsedSwap);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_MemoryStatisticalInformation_Class.PercentUsedSwap
    //
    
    const Field<Uint8>& PercentUsedSwap() const
    {
        const size_t n = offsetof(Self, PercentUsedSwap);
        return GetField<Uint8>(n);
    }
    
    void PercentUsedSwap(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentUsedSwap);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentUsedSwap_value() const
    {
        const size_t n = offsetof(Self, PercentUsedSwap);
        return GetField<Uint8>(n).value;
    }
    
    void PercentUsedSwap_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentUsedSwap);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentUsedSwap_exists() const
    {
        const size_t n = offsetof(Self, PercentUsedSwap);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentUsedSwap_clear()
    {
        const size_t n = offsetof(Self, PercentUsedSwap);
        GetField<Uint8>(n).Clear();
    }
};

typedef Array<SCX_MemoryStatisticalInformation_Class> SCX_MemoryStatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_MemoryStatisticalInformation_h */
