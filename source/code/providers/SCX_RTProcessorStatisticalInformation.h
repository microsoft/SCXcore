/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_RTProcessorStatisticalInformation_h
#define _SCX_RTProcessorStatisticalInformation_h

#include <MI.h>
#include "SCX_StatisticalInformation.h"

/*
**==============================================================================
**
** SCX_RTProcessorStatisticalInformation [SCX_RTProcessorStatisticalInformation]
**
** Keys:
**    Name
**
**==============================================================================
*/

typedef struct _SCX_RTProcessorStatisticalInformation /* extends SCX_StatisticalInformation */
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
    /* SCX_RTProcessorStatisticalInformation properties */
    MI_ConstUint8Field PercentIdleTime;
    MI_ConstUint8Field PercentUserTime;
    MI_ConstUint8Field PercentNiceTime;
    MI_ConstUint8Field PercentPrivilegedTime;
    MI_ConstUint8Field PercentInterruptTime;
    MI_ConstUint8Field PercentDPCTime;
    MI_ConstUint8Field PercentProcessorTime;
    MI_ConstUint8Field PercentIOWaitTime;
}
SCX_RTProcessorStatisticalInformation;

typedef struct _SCX_RTProcessorStatisticalInformation_Ref
{
    SCX_RTProcessorStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_RTProcessorStatisticalInformation_Ref;

typedef struct _SCX_RTProcessorStatisticalInformation_ConstRef
{
    MI_CONST SCX_RTProcessorStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_RTProcessorStatisticalInformation_ConstRef;

typedef struct _SCX_RTProcessorStatisticalInformation_Array
{
    struct _SCX_RTProcessorStatisticalInformation** data;
    MI_Uint32 size;
}
SCX_RTProcessorStatisticalInformation_Array;

typedef struct _SCX_RTProcessorStatisticalInformation_ConstArray
{
    struct _SCX_RTProcessorStatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_RTProcessorStatisticalInformation_ConstArray;

typedef struct _SCX_RTProcessorStatisticalInformation_ArrayRef
{
    SCX_RTProcessorStatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_RTProcessorStatisticalInformation_ArrayRef;

typedef struct _SCX_RTProcessorStatisticalInformation_ConstArrayRef
{
    SCX_RTProcessorStatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_RTProcessorStatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_RTProcessorStatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Construct(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_RTProcessorStatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clone(
    const SCX_RTProcessorStatisticalInformation* self,
    SCX_RTProcessorStatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_RTProcessorStatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_RTProcessorStatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Destruct(SCX_RTProcessorStatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Delete(SCX_RTProcessorStatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Post(
    const SCX_RTProcessorStatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_InstanceID(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_SetPtr_InstanceID(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_InstanceID(
    SCX_RTProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_Caption(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_SetPtr_Caption(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_Caption(
    SCX_RTProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_Description(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_SetPtr_Description(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_Description(
    SCX_RTProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_ElementName(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_SetPtr_ElementName(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_ElementName(
    SCX_RTProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_Name(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_SetPtr_Name(
    SCX_RTProcessorStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_Name(
    SCX_RTProcessorStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_IsAggregate(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsAggregate)->value = x;
    ((MI_BooleanField*)&self->IsAggregate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_IsAggregate(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->IsAggregate, 0, sizeof(self->IsAggregate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentIdleTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentIdleTime)->value = x;
    ((MI_Uint8Field*)&self->PercentIdleTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentIdleTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentIdleTime, 0, sizeof(self->PercentIdleTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentUserTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUserTime)->value = x;
    ((MI_Uint8Field*)&self->PercentUserTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentUserTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentUserTime, 0, sizeof(self->PercentUserTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentNiceTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentNiceTime)->value = x;
    ((MI_Uint8Field*)&self->PercentNiceTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentNiceTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentNiceTime, 0, sizeof(self->PercentNiceTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentPrivilegedTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentPrivilegedTime)->value = x;
    ((MI_Uint8Field*)&self->PercentPrivilegedTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentPrivilegedTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentPrivilegedTime, 0, sizeof(self->PercentPrivilegedTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentInterruptTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentInterruptTime)->value = x;
    ((MI_Uint8Field*)&self->PercentInterruptTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentInterruptTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentInterruptTime, 0, sizeof(self->PercentInterruptTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentDPCTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentDPCTime)->value = x;
    ((MI_Uint8Field*)&self->PercentDPCTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentDPCTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentDPCTime, 0, sizeof(self->PercentDPCTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentProcessorTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentProcessorTime)->value = x;
    ((MI_Uint8Field*)&self->PercentProcessorTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentProcessorTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentProcessorTime, 0, sizeof(self->PercentProcessorTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Set_PercentIOWaitTime(
    SCX_RTProcessorStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentIOWaitTime)->value = x;
    ((MI_Uint8Field*)&self->PercentIOWaitTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_RTProcessorStatisticalInformation_Clear_PercentIOWaitTime(
    SCX_RTProcessorStatisticalInformation* self)
{
    memset((void*)&self->PercentIOWaitTime, 0, sizeof(self->PercentIOWaitTime));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_RTProcessorStatisticalInformation provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_RTProcessorStatisticalInformation_Self SCX_RTProcessorStatisticalInformation_Self;

MI_EXTERN_C void MI_CALL SCX_RTProcessorStatisticalInformation_Load(
    SCX_RTProcessorStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_RTProcessorStatisticalInformation_Unload(
    SCX_RTProcessorStatisticalInformation_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_RTProcessorStatisticalInformation_EnumerateInstances(
    SCX_RTProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_RTProcessorStatisticalInformation_GetInstance(
    SCX_RTProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_RTProcessorStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_RTProcessorStatisticalInformation_CreateInstance(
    SCX_RTProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_RTProcessorStatisticalInformation* newInstance);

MI_EXTERN_C void MI_CALL SCX_RTProcessorStatisticalInformation_ModifyInstance(
    SCX_RTProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_RTProcessorStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_RTProcessorStatisticalInformation_DeleteInstance(
    SCX_RTProcessorStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_RTProcessorStatisticalInformation* instanceName);


/*
**==============================================================================
**
** SCX_RTProcessorStatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_RTProcessorStatisticalInformation_Class : public SCX_StatisticalInformation_Class
{
public:
    
    typedef SCX_RTProcessorStatisticalInformation Self;
    
    SCX_RTProcessorStatisticalInformation_Class() :
        SCX_StatisticalInformation_Class(&SCX_RTProcessorStatisticalInformation_rtti)
    {
    }
    
    SCX_RTProcessorStatisticalInformation_Class(
        const SCX_RTProcessorStatisticalInformation* instanceName,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(
            &SCX_RTProcessorStatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_RTProcessorStatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_RTProcessorStatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        SCX_StatisticalInformation_Class(clDecl)
    {
    }
    
    SCX_RTProcessorStatisticalInformation_Class& operator=(
        const SCX_RTProcessorStatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_RTProcessorStatisticalInformation_Class(
        const SCX_RTProcessorStatisticalInformation_Class& x) :
        SCX_StatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_RTProcessorStatisticalInformation_rtti;
    }

    //
    // SCX_RTProcessorStatisticalInformation_Class.PercentIdleTime
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
    // SCX_RTProcessorStatisticalInformation_Class.PercentUserTime
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
    // SCX_RTProcessorStatisticalInformation_Class.PercentNiceTime
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
    // SCX_RTProcessorStatisticalInformation_Class.PercentPrivilegedTime
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
    // SCX_RTProcessorStatisticalInformation_Class.PercentInterruptTime
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
    // SCX_RTProcessorStatisticalInformation_Class.PercentDPCTime
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
    // SCX_RTProcessorStatisticalInformation_Class.PercentProcessorTime
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
    // SCX_RTProcessorStatisticalInformation_Class.PercentIOWaitTime
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

typedef Array<SCX_RTProcessorStatisticalInformation_Class> SCX_RTProcessorStatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_RTProcessorStatisticalInformation_h */
