/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_ProcessorStatisticalInformation_h
#define _SCX_ProcessorStatisticalInformation_h

#include <MI.h>
#include "SCX_StatisticalInformation.h"

/*
**==============================================================================
**
** SCX_ProcessorStatisticalInformation [SCX_ProcessorStatisticalInformation]
**
** Keys:
**    Name
**
**==============================================================================
*/

typedef struct _SCX_ProcessorStatisticalInformation /* extends SCX_StatisticalInformation */
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
    /* SCX_ProcessorStatisticalInformation properties */
    MI_ConstUint8Field PercentIdleTime;
    MI_ConstUint8Field PercentUserTime;
    MI_ConstUint8Field PercentNiceTime;
    MI_ConstUint8Field PercentPrivilegedTime;
    MI_ConstUint8Field PercentInterruptTime;
    MI_ConstUint8Field PercentDPCTime;
    MI_ConstUint8Field PercentProcessorTime;
    MI_ConstUint8Field PercentIOWaitTime;
}
SCX_ProcessorStatisticalInformation;

typedef struct _SCX_ProcessorStatisticalInformation_Ref
{
    SCX_ProcessorStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_ProcessorStatisticalInformation_Ref;

typedef struct _SCX_ProcessorStatisticalInformation_ConstRef
{
    MI_CONST SCX_ProcessorStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_ProcessorStatisticalInformation_ConstRef;

typedef struct _SCX_ProcessorStatisticalInformation_Array
{
    struct _SCX_ProcessorStatisticalInformation** data;
    MI_Uint32 size;
}
SCX_ProcessorStatisticalInformation_Array;

typedef struct _SCX_ProcessorStatisticalInformation_ConstArray
{
    struct _SCX_ProcessorStatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_ProcessorStatisticalInformation_ConstArray;

typedef struct _SCX_ProcessorStatisticalInformation_ArrayRef
{
    SCX_ProcessorStatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_ProcessorStatisticalInformation_ArrayRef;

typedef struct _SCX_ProcessorStatisticalInformation_ConstArrayRef
{
    SCX_ProcessorStatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_ProcessorStatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_ProcessorStatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Construct(
    SCX_ProcessorStatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_ProcessorStatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clone(
    const SCX_ProcessorStatisticalInformation* self,
    SCX_ProcessorStatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_ProcessorStatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_ProcessorStatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Destruct(SCX_ProcessorStatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Delete(SCX_ProcessorStatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Post(
    const SCX_ProcessorStatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_InstanceID(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_SetPtr_InstanceID(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_InstanceID(
    SCX_ProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_Caption(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_SetPtr_Caption(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_Caption(
    SCX_ProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_Description(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_SetPtr_Description(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_Description(
    SCX_ProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_ElementName(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_SetPtr_ElementName(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_ElementName(
    SCX_ProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_Name(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_SetPtr_Name(
    SCX_ProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_Name(
    SCX_ProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_IsAggregate(
    SCX_ProcessorStatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsAggregate)->value = x;
    ((MI_BooleanField*)&self->IsAggregate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_IsAggregate(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->IsAggregate, 0, sizeof(self->IsAggregate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentIdleTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentIdleTime)->value = x;
    ((MI_Uint8Field*)&self->PercentIdleTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentIdleTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentIdleTime, 0, sizeof(self->PercentIdleTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentUserTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUserTime)->value = x;
    ((MI_Uint8Field*)&self->PercentUserTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentUserTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentUserTime, 0, sizeof(self->PercentUserTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentNiceTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentNiceTime)->value = x;
    ((MI_Uint8Field*)&self->PercentNiceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentNiceTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentNiceTime, 0, sizeof(self->PercentNiceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentPrivilegedTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentPrivilegedTime)->value = x;
    ((MI_Uint8Field*)&self->PercentPrivilegedTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentPrivilegedTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentPrivilegedTime, 0, sizeof(self->PercentPrivilegedTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentInterruptTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentInterruptTime)->value = x;
    ((MI_Uint8Field*)&self->PercentInterruptTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentInterruptTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentInterruptTime, 0, sizeof(self->PercentInterruptTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentDPCTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentDPCTime)->value = x;
    ((MI_Uint8Field*)&self->PercentDPCTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentDPCTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentDPCTime, 0, sizeof(self->PercentDPCTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentProcessorTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentProcessorTime)->value = x;
    ((MI_Uint8Field*)&self->PercentProcessorTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentProcessorTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentProcessorTime, 0, sizeof(self->PercentProcessorTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Set_PercentIOWaitTime(
    SCX_ProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentIOWaitTime)->value = x;
    ((MI_Uint8Field*)&self->PercentIOWaitTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_ProcessorStatisticalInformation_Clear_PercentIOWaitTime(
    SCX_ProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentIOWaitTime, 0, sizeof(self->PercentIOWaitTime));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_ProcessorStatisticalInformation provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_ProcessorStatisticalInformation_Self SCX_ProcessorStatisticalInformation_Self;

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_Load(
    SCX_ProcessorStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_Unload(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_EnumerateInstances(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_GetInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_CreateInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* newInstance);

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_ModifyInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_ProcessorStatisticalInformation_DeleteInstance(
    SCX_ProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_ProcessorStatisticalInformation* instanceName);


/*
**==============================================================================
**
** SCX_ProcessorStatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_ProcessorStatisticalInformation_Class : public SCX_StatisticalInformation_Class
{
public:
    
    typedef SCX_ProcessorStatisticalInformation Self;
    
    SCX_ProcessorStatisticalInformation_Class() :
        SCX_StatisticalInformation_Class(&SCX_ProcessorStatisticalInformation_rtti)
    {
    }
    
    SCX_ProcessorStatisticalInformation_Class(
        const SCX_ProcessorStatisticalInformation* instanceName,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(
            &SCX_ProcessorStatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_ProcessorStatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_ProcessorStatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        SCX_StatisticalInformation_Class(clDecl)
    {
    }
    
    SCX_ProcessorStatisticalInformation_Class& operator=(
        const SCX_ProcessorStatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_ProcessorStatisticalInformation_Class(
        const SCX_ProcessorStatisticalInformation_Class& x) :
        SCX_StatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_ProcessorStatisticalInformation_rtti;
    }

    //
    // SCX_ProcessorStatisticalInformation_Class.PercentIdleTime
    //
    
    const Field<Uint8>& PercentIdleTime() const
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        return GetField<Uint8>(n);
    }
    
    void PercentIdleTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentIdleTime_value() const
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentIdleTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentIdleTime_exists() const
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentIdleTime_clear()
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_ProcessorStatisticalInformation_Class.PercentUserTime
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
    // SCX_ProcessorStatisticalInformation_Class.PercentNiceTime
    //
    
    const Field<Uint8>& PercentNiceTime() const
    {
        const size_t n = offsetof(Self, PercentNiceTime);
        return GetField<Uint8>(n);
    }
    
    void PercentNiceTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentNiceTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentNiceTime_value() const
    {
        const size_t n = offsetof(Self, PercentNiceTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentNiceTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentNiceTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentNiceTime_exists() const
    {
        const size_t n = offsetof(Self, PercentNiceTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentNiceTime_clear()
    {
        const size_t n = offsetof(Self, PercentNiceTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_ProcessorStatisticalInformation_Class.PercentPrivilegedTime
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
    // SCX_ProcessorStatisticalInformation_Class.PercentInterruptTime
    //
    
    const Field<Uint8>& PercentInterruptTime() const
    {
        const size_t n = offsetof(Self, PercentInterruptTime);
        return GetField<Uint8>(n);
    }
    
    void PercentInterruptTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentInterruptTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentInterruptTime_value() const
    {
        const size_t n = offsetof(Self, PercentInterruptTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentInterruptTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentInterruptTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentInterruptTime_exists() const
    {
        const size_t n = offsetof(Self, PercentInterruptTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentInterruptTime_clear()
    {
        const size_t n = offsetof(Self, PercentInterruptTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_ProcessorStatisticalInformation_Class.PercentDPCTime
    //
    
    const Field<Uint8>& PercentDPCTime() const
    {
        const size_t n = offsetof(Self, PercentDPCTime);
        return GetField<Uint8>(n);
    }
    
    void PercentDPCTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentDPCTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentDPCTime_value() const
    {
        const size_t n = offsetof(Self, PercentDPCTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentDPCTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentDPCTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentDPCTime_exists() const
    {
        const size_t n = offsetof(Self, PercentDPCTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentDPCTime_clear()
    {
        const size_t n = offsetof(Self, PercentDPCTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_ProcessorStatisticalInformation_Class.PercentProcessorTime
    //
    
    const Field<Uint8>& PercentProcessorTime() const
    {
        const size_t n = offsetof(Self, PercentProcessorTime);
        return GetField<Uint8>(n);
    }
    
    void PercentProcessorTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentProcessorTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentProcessorTime_value() const
    {
        const size_t n = offsetof(Self, PercentProcessorTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentProcessorTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentProcessorTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentProcessorTime_exists() const
    {
        const size_t n = offsetof(Self, PercentProcessorTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentProcessorTime_clear()
    {
        const size_t n = offsetof(Self, PercentProcessorTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_ProcessorStatisticalInformation_Class.PercentIOWaitTime
    //
    
    const Field<Uint8>& PercentIOWaitTime() const
    {
        const size_t n = offsetof(Self, PercentIOWaitTime);
        return GetField<Uint8>(n);
    }
    
    void PercentIOWaitTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentIOWaitTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentIOWaitTime_value() const
    {
        const size_t n = offsetof(Self, PercentIOWaitTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentIOWaitTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentIOWaitTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentIOWaitTime_exists() const
    {
        const size_t n = offsetof(Self, PercentIOWaitTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentIOWaitTime_clear()
    {
        const size_t n = offsetof(Self, PercentIOWaitTime);
        GetField<Uint8>(n).Clear();
    }
};

typedef Array<SCX_ProcessorStatisticalInformation_Class> SCX_ProcessorStatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_ProcessorStatisticalInformation_h */
