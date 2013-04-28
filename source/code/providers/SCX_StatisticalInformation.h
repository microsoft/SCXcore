/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_StatisticalInformation_h
#define _SCX_StatisticalInformation_h

#include <MI.h>
#include "CIM_StatisticalInformation.h"

/*
**==============================================================================
**
** SCX_StatisticalInformation [SCX_StatisticalInformation]
**
** Keys:
**
**==============================================================================
*/

typedef struct _SCX_StatisticalInformation /* extends CIM_StatisticalInformation */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_StatisticalInformation properties */
    MI_ConstStringField Name;
    /* SCX_StatisticalInformation properties */
    MI_ConstBooleanField IsAggregate;
}
SCX_StatisticalInformation;

typedef struct _SCX_StatisticalInformation_Ref
{
    SCX_StatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_StatisticalInformation_Ref;

typedef struct _SCX_StatisticalInformation_ConstRef
{
    MI_CONST SCX_StatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_StatisticalInformation_ConstRef;

typedef struct _SCX_StatisticalInformation_Array
{
    struct _SCX_StatisticalInformation** data;
    MI_Uint32 size;
}
SCX_StatisticalInformation_Array;

typedef struct _SCX_StatisticalInformation_ConstArray
{
    struct _SCX_StatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_StatisticalInformation_ConstArray;

typedef struct _SCX_StatisticalInformation_ArrayRef
{
    SCX_StatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_StatisticalInformation_ArrayRef;

typedef struct _SCX_StatisticalInformation_ConstArrayRef
{
    SCX_StatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_StatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_StatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Construct(
    SCX_StatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_StatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Clone(
    const SCX_StatisticalInformation* self,
    SCX_StatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_StatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_StatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Destruct(SCX_StatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Delete(SCX_StatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Post(
    const SCX_StatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Set_InstanceID(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_SetPtr_InstanceID(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Clear_InstanceID(
    SCX_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Set_Caption(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_SetPtr_Caption(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Clear_Caption(
    SCX_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Set_Description(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_SetPtr_Description(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Clear_Description(
    SCX_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Set_ElementName(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_SetPtr_ElementName(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Clear_ElementName(
    SCX_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Set_Name(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_SetPtr_Name(
    SCX_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Clear_Name(
    SCX_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Set_IsAggregate(
    SCX_StatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsAggregate)->value = x;
    ((MI_BooleanField*)&self->IsAggregate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_StatisticalInformation_Clear_IsAggregate(
    SCX_StatisticalInformation* self)
{
    memset((void*)&self->IsAggregate, 0, sizeof(self->IsAggregate));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** SCX_StatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_StatisticalInformation_Class : public CIM_StatisticalInformation_Class
{
public:
    
    typedef SCX_StatisticalInformation Self;
    
    SCX_StatisticalInformation_Class() :
        CIM_StatisticalInformation_Class(&SCX_StatisticalInformation_rtti)
    {
    }
    
    SCX_StatisticalInformation_Class(
        const SCX_StatisticalInformation* instanceName,
        bool keysOnly) :
        CIM_StatisticalInformation_Class(
            &SCX_StatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_StatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_StatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_StatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        CIM_StatisticalInformation_Class(clDecl)
    {
    }
    
    SCX_StatisticalInformation_Class& operator=(
        const SCX_StatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_StatisticalInformation_Class(
        const SCX_StatisticalInformation_Class& x) :
        CIM_StatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_StatisticalInformation_rtti;
    }

    //
    // SCX_StatisticalInformation_Class.IsAggregate
    //
    
    const Field<Boolean>& IsAggregate() const
    {
        const size_t n = offsetof(Self, IsAggregate);
        return GetField<Boolean>(n);
    }
    
    void IsAggregate(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, IsAggregate);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& IsAggregate_value() const
    {
        const size_t n = offsetof(Self, IsAggregate);
        return GetField<Boolean>(n).value;
    }
    
    void IsAggregate_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, IsAggregate);
        GetField<Boolean>(n).Set(x);
    }
    
    bool IsAggregate_exists() const
    {
        const size_t n = offsetof(Self, IsAggregate);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void IsAggregate_clear()
    {
        const size_t n = offsetof(Self, IsAggregate);
        GetField<Boolean>(n).Clear();
    }
};

typedef Array<SCX_StatisticalInformation_Class> SCX_StatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_StatisticalInformation_h */
