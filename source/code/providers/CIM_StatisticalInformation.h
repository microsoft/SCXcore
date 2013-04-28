/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_StatisticalInformation_h
#define _CIM_StatisticalInformation_h

#include <MI.h>
#include "CIM_ManagedElement.h"

/*
**==============================================================================
**
** CIM_StatisticalInformation [CIM_StatisticalInformation]
**
** Keys:
**
**==============================================================================
*/

typedef struct _CIM_StatisticalInformation /* extends CIM_ManagedElement */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_StatisticalInformation properties */
    MI_ConstStringField Name;
}
CIM_StatisticalInformation;

typedef struct _CIM_StatisticalInformation_Ref
{
    CIM_StatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalInformation_Ref;

typedef struct _CIM_StatisticalInformation_ConstRef
{
    MI_CONST CIM_StatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalInformation_ConstRef;

typedef struct _CIM_StatisticalInformation_Array
{
    struct _CIM_StatisticalInformation** data;
    MI_Uint32 size;
}
CIM_StatisticalInformation_Array;

typedef struct _CIM_StatisticalInformation_ConstArray
{
    struct _CIM_StatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_StatisticalInformation_ConstArray;

typedef struct _CIM_StatisticalInformation_ArrayRef
{
    CIM_StatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalInformation_ArrayRef;

typedef struct _CIM_StatisticalInformation_ConstArrayRef
{
    CIM_StatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_StatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Construct(
    CIM_StatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_StatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Clone(
    const CIM_StatisticalInformation* self,
    CIM_StatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_StatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_StatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Destruct(CIM_StatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Delete(CIM_StatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Post(
    const CIM_StatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Set_InstanceID(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_SetPtr_InstanceID(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Clear_InstanceID(
    CIM_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Set_Caption(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_SetPtr_Caption(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Clear_Caption(
    CIM_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Set_Description(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_SetPtr_Description(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Clear_Description(
    CIM_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Set_ElementName(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_SetPtr_ElementName(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Clear_ElementName(
    CIM_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Set_Name(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_SetPtr_Name(
    CIM_StatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalInformation_Clear_Name(
    CIM_StatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}


/*
**==============================================================================
**
** CIM_StatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_StatisticalInformation_Class : public CIM_ManagedElement_Class
{
public:
    
    typedef CIM_StatisticalInformation Self;
    
    CIM_StatisticalInformation_Class() :
        CIM_ManagedElement_Class(&CIM_StatisticalInformation_rtti)
    {
    }
    
    CIM_StatisticalInformation_Class(
        const CIM_StatisticalInformation* instanceName,
        bool keysOnly) :
        CIM_ManagedElement_Class(
            &CIM_StatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_StatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_ManagedElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_StatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        CIM_ManagedElement_Class(clDecl)
    {
    }
    
    CIM_StatisticalInformation_Class& operator=(
        const CIM_StatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_StatisticalInformation_Class(
        const CIM_StatisticalInformation_Class& x) :
        CIM_ManagedElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_StatisticalInformation_rtti;
    }

    //
    // CIM_StatisticalInformation_Class.Name
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

typedef Array<CIM_StatisticalInformation_Class> CIM_StatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_StatisticalInformation_h */
