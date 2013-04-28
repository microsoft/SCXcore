/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_Error_h
#define _CIM_Error_h

#include <MI.h>

/*
**==============================================================================
**
** CIM_Error [CIM_Error]
**
** Keys:
**
**==============================================================================
*/

typedef struct _CIM_Error
{
    MI_Instance __instance;
    /* CIM_Error properties */
    MI_ConstUint16Field ErrorType;
    MI_ConstStringField OtherErrorType;
    MI_ConstStringField OwningEntity;
    MI_ConstStringField MessageID;
    MI_ConstStringField Message;
    MI_ConstStringAField MessageArguments;
    MI_ConstUint16Field PerceivedSeverity;
    MI_ConstUint16Field ProbableCause;
    MI_ConstStringField ProbableCauseDescription;
    MI_ConstStringAField RecommendedActions;
    MI_ConstStringField ErrorSource;
    MI_ConstUint16Field ErrorSourceFormat;
    MI_ConstStringField OtherErrorSourceFormat;
    MI_ConstUint32Field CIMStatusCode;
    MI_ConstStringField CIMStatusCodeDescription;
}
CIM_Error;

typedef struct _CIM_Error_Ref
{
    CIM_Error* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Error_Ref;

typedef struct _CIM_Error_ConstRef
{
    MI_CONST CIM_Error* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Error_ConstRef;

typedef struct _CIM_Error_Array
{
    struct _CIM_Error** data;
    MI_Uint32 size;
}
CIM_Error_Array;

typedef struct _CIM_Error_ConstArray
{
    struct _CIM_Error MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_Error_ConstArray;

typedef struct _CIM_Error_ArrayRef
{
    CIM_Error_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Error_ArrayRef;

typedef struct _CIM_Error_ConstArrayRef
{
    CIM_Error_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_Error_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_Error_rtti;

MI_INLINE MI_Result MI_CALL CIM_Error_Construct(
    CIM_Error* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_Error_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clone(
    const CIM_Error* self,
    CIM_Error** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_Error_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_Error_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Destruct(CIM_Error* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Delete(CIM_Error* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Post(
    const CIM_Error* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_ErrorType(
    CIM_Error* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorType)->value = x;
    ((MI_Uint16Field*)&self->ErrorType)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_ErrorType(
    CIM_Error* self)
{
    memset((void*)&self->ErrorType, 0, sizeof(self->ErrorType));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_OtherErrorType(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_OtherErrorType(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_OtherErrorType(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_OwningEntity(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_OwningEntity(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_OwningEntity(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_MessageID(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_MessageID(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_MessageID(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_Message(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_Message(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_Message(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_MessageArguments(
    CIM_Error* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_MessageArguments(
    CIM_Error* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_MessageArguments(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_PerceivedSeverity(
    CIM_Error* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PerceivedSeverity)->value = x;
    ((MI_Uint16Field*)&self->PerceivedSeverity)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_PerceivedSeverity(
    CIM_Error* self)
{
    memset((void*)&self->PerceivedSeverity, 0, sizeof(self->PerceivedSeverity));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_ProbableCause(
    CIM_Error* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ProbableCause)->value = x;
    ((MI_Uint16Field*)&self->ProbableCause)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_ProbableCause(
    CIM_Error* self)
{
    memset((void*)&self->ProbableCause, 0, sizeof(self->ProbableCause));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_ProbableCauseDescription(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_ProbableCauseDescription(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_ProbableCauseDescription(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_RecommendedActions(
    CIM_Error* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        9,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_RecommendedActions(
    CIM_Error* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        9,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_RecommendedActions(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        9);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_ErrorSource(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        10,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_ErrorSource(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        10,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_ErrorSource(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        10);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_ErrorSourceFormat(
    CIM_Error* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->ErrorSourceFormat)->value = x;
    ((MI_Uint16Field*)&self->ErrorSourceFormat)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_ErrorSourceFormat(
    CIM_Error* self)
{
    memset((void*)&self->ErrorSourceFormat, 0, sizeof(self->ErrorSourceFormat));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_OtherErrorSourceFormat(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        12,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_OtherErrorSourceFormat(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        12,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_OtherErrorSourceFormat(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        12);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_CIMStatusCode(
    CIM_Error* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CIMStatusCode)->value = x;
    ((MI_Uint32Field*)&self->CIMStatusCode)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_CIMStatusCode(
    CIM_Error* self)
{
    memset((void*)&self->CIMStatusCode, 0, sizeof(self->CIMStatusCode));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_Error_Set_CIMStatusCodeDescription(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_Error_SetPtr_CIMStatusCodeDescription(
    CIM_Error* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_Error_Clear_CIMStatusCodeDescription(
    CIM_Error* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        14);
}


/*
**==============================================================================
**
** CIM_Error_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_Error_Class : public Instance
{
public:
    
    typedef CIM_Error Self;
    
    CIM_Error_Class() :
        Instance(&CIM_Error_rtti)
    {
    }
    
    CIM_Error_Class(
        const CIM_Error* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_Error_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_Error_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_Error_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_Error_Class& operator=(
        const CIM_Error_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_Error_Class(
        const CIM_Error_Class& x) :
        Instance(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_Error_rtti;
    }

    //
    // CIM_Error_Class.ErrorType
    //
    
    const Field<Uint16>& ErrorType() const
    {
        const size_t n = offsetof(Self, ErrorType);
        return GetField<Uint16>(n);
    }
    
    void ErrorType(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, ErrorType);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& ErrorType_value() const
    {
        const size_t n = offsetof(Self, ErrorType);
        return GetField<Uint16>(n).value;
    }
    
    void ErrorType_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, ErrorType);
        GetField<Uint16>(n).Set(x);
    }
    
    bool ErrorType_exists() const
    {
        const size_t n = offsetof(Self, ErrorType);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void ErrorType_clear()
    {
        const size_t n = offsetof(Self, ErrorType);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Error_Class.OtherErrorType
    //
    
    const Field<String>& OtherErrorType() const
    {
        const size_t n = offsetof(Self, OtherErrorType);
        return GetField<String>(n);
    }
    
    void OtherErrorType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherErrorType);
        GetField<String>(n) = x;
    }
    
    const String& OtherErrorType_value() const
    {
        const size_t n = offsetof(Self, OtherErrorType);
        return GetField<String>(n).value;
    }
    
    void OtherErrorType_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherErrorType);
        GetField<String>(n).Set(x);
    }
    
    bool OtherErrorType_exists() const
    {
        const size_t n = offsetof(Self, OtherErrorType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherErrorType_clear()
    {
        const size_t n = offsetof(Self, OtherErrorType);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Error_Class.OwningEntity
    //
    
    const Field<String>& OwningEntity() const
    {
        const size_t n = offsetof(Self, OwningEntity);
        return GetField<String>(n);
    }
    
    void OwningEntity(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OwningEntity);
        GetField<String>(n) = x;
    }
    
    const String& OwningEntity_value() const
    {
        const size_t n = offsetof(Self, OwningEntity);
        return GetField<String>(n).value;
    }
    
    void OwningEntity_value(const String& x)
    {
        const size_t n = offsetof(Self, OwningEntity);
        GetField<String>(n).Set(x);
    }
    
    bool OwningEntity_exists() const
    {
        const size_t n = offsetof(Self, OwningEntity);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OwningEntity_clear()
    {
        const size_t n = offsetof(Self, OwningEntity);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Error_Class.MessageID
    //
    
    const Field<String>& MessageID() const
    {
        const size_t n = offsetof(Self, MessageID);
        return GetField<String>(n);
    }
    
    void MessageID(const Field<String>& x)
    {
        const size_t n = offsetof(Self, MessageID);
        GetField<String>(n) = x;
    }
    
    const String& MessageID_value() const
    {
        const size_t n = offsetof(Self, MessageID);
        return GetField<String>(n).value;
    }
    
    void MessageID_value(const String& x)
    {
        const size_t n = offsetof(Self, MessageID);
        GetField<String>(n).Set(x);
    }
    
    bool MessageID_exists() const
    {
        const size_t n = offsetof(Self, MessageID);
        return GetField<String>(n).exists ? true : false;
    }
    
    void MessageID_clear()
    {
        const size_t n = offsetof(Self, MessageID);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Error_Class.Message
    //
    
    const Field<String>& Message() const
    {
        const size_t n = offsetof(Self, Message);
        return GetField<String>(n);
    }
    
    void Message(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Message);
        GetField<String>(n) = x;
    }
    
    const String& Message_value() const
    {
        const size_t n = offsetof(Self, Message);
        return GetField<String>(n).value;
    }
    
    void Message_value(const String& x)
    {
        const size_t n = offsetof(Self, Message);
        GetField<String>(n).Set(x);
    }
    
    bool Message_exists() const
    {
        const size_t n = offsetof(Self, Message);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Message_clear()
    {
        const size_t n = offsetof(Self, Message);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Error_Class.MessageArguments
    //
    
    const Field<StringA>& MessageArguments() const
    {
        const size_t n = offsetof(Self, MessageArguments);
        return GetField<StringA>(n);
    }
    
    void MessageArguments(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, MessageArguments);
        GetField<StringA>(n) = x;
    }
    
    const StringA& MessageArguments_value() const
    {
        const size_t n = offsetof(Self, MessageArguments);
        return GetField<StringA>(n).value;
    }
    
    void MessageArguments_value(const StringA& x)
    {
        const size_t n = offsetof(Self, MessageArguments);
        GetField<StringA>(n).Set(x);
    }
    
    bool MessageArguments_exists() const
    {
        const size_t n = offsetof(Self, MessageArguments);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void MessageArguments_clear()
    {
        const size_t n = offsetof(Self, MessageArguments);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_Error_Class.PerceivedSeverity
    //
    
    const Field<Uint16>& PerceivedSeverity() const
    {
        const size_t n = offsetof(Self, PerceivedSeverity);
        return GetField<Uint16>(n);
    }
    
    void PerceivedSeverity(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, PerceivedSeverity);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& PerceivedSeverity_value() const
    {
        const size_t n = offsetof(Self, PerceivedSeverity);
        return GetField<Uint16>(n).value;
    }
    
    void PerceivedSeverity_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, PerceivedSeverity);
        GetField<Uint16>(n).Set(x);
    }
    
    bool PerceivedSeverity_exists() const
    {
        const size_t n = offsetof(Self, PerceivedSeverity);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void PerceivedSeverity_clear()
    {
        const size_t n = offsetof(Self, PerceivedSeverity);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Error_Class.ProbableCause
    //
    
    const Field<Uint16>& ProbableCause() const
    {
        const size_t n = offsetof(Self, ProbableCause);
        return GetField<Uint16>(n);
    }
    
    void ProbableCause(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, ProbableCause);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& ProbableCause_value() const
    {
        const size_t n = offsetof(Self, ProbableCause);
        return GetField<Uint16>(n).value;
    }
    
    void ProbableCause_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, ProbableCause);
        GetField<Uint16>(n).Set(x);
    }
    
    bool ProbableCause_exists() const
    {
        const size_t n = offsetof(Self, ProbableCause);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void ProbableCause_clear()
    {
        const size_t n = offsetof(Self, ProbableCause);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Error_Class.ProbableCauseDescription
    //
    
    const Field<String>& ProbableCauseDescription() const
    {
        const size_t n = offsetof(Self, ProbableCauseDescription);
        return GetField<String>(n);
    }
    
    void ProbableCauseDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ProbableCauseDescription);
        GetField<String>(n) = x;
    }
    
    const String& ProbableCauseDescription_value() const
    {
        const size_t n = offsetof(Self, ProbableCauseDescription);
        return GetField<String>(n).value;
    }
    
    void ProbableCauseDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, ProbableCauseDescription);
        GetField<String>(n).Set(x);
    }
    
    bool ProbableCauseDescription_exists() const
    {
        const size_t n = offsetof(Self, ProbableCauseDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ProbableCauseDescription_clear()
    {
        const size_t n = offsetof(Self, ProbableCauseDescription);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Error_Class.RecommendedActions
    //
    
    const Field<StringA>& RecommendedActions() const
    {
        const size_t n = offsetof(Self, RecommendedActions);
        return GetField<StringA>(n);
    }
    
    void RecommendedActions(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, RecommendedActions);
        GetField<StringA>(n) = x;
    }
    
    const StringA& RecommendedActions_value() const
    {
        const size_t n = offsetof(Self, RecommendedActions);
        return GetField<StringA>(n).value;
    }
    
    void RecommendedActions_value(const StringA& x)
    {
        const size_t n = offsetof(Self, RecommendedActions);
        GetField<StringA>(n).Set(x);
    }
    
    bool RecommendedActions_exists() const
    {
        const size_t n = offsetof(Self, RecommendedActions);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void RecommendedActions_clear()
    {
        const size_t n = offsetof(Self, RecommendedActions);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_Error_Class.ErrorSource
    //
    
    const Field<String>& ErrorSource() const
    {
        const size_t n = offsetof(Self, ErrorSource);
        return GetField<String>(n);
    }
    
    void ErrorSource(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ErrorSource);
        GetField<String>(n) = x;
    }
    
    const String& ErrorSource_value() const
    {
        const size_t n = offsetof(Self, ErrorSource);
        return GetField<String>(n).value;
    }
    
    void ErrorSource_value(const String& x)
    {
        const size_t n = offsetof(Self, ErrorSource);
        GetField<String>(n).Set(x);
    }
    
    bool ErrorSource_exists() const
    {
        const size_t n = offsetof(Self, ErrorSource);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ErrorSource_clear()
    {
        const size_t n = offsetof(Self, ErrorSource);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Error_Class.ErrorSourceFormat
    //
    
    const Field<Uint16>& ErrorSourceFormat() const
    {
        const size_t n = offsetof(Self, ErrorSourceFormat);
        return GetField<Uint16>(n);
    }
    
    void ErrorSourceFormat(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, ErrorSourceFormat);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& ErrorSourceFormat_value() const
    {
        const size_t n = offsetof(Self, ErrorSourceFormat);
        return GetField<Uint16>(n).value;
    }
    
    void ErrorSourceFormat_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, ErrorSourceFormat);
        GetField<Uint16>(n).Set(x);
    }
    
    bool ErrorSourceFormat_exists() const
    {
        const size_t n = offsetof(Self, ErrorSourceFormat);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void ErrorSourceFormat_clear()
    {
        const size_t n = offsetof(Self, ErrorSourceFormat);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_Error_Class.OtherErrorSourceFormat
    //
    
    const Field<String>& OtherErrorSourceFormat() const
    {
        const size_t n = offsetof(Self, OtherErrorSourceFormat);
        return GetField<String>(n);
    }
    
    void OtherErrorSourceFormat(const Field<String>& x)
    {
        const size_t n = offsetof(Self, OtherErrorSourceFormat);
        GetField<String>(n) = x;
    }
    
    const String& OtherErrorSourceFormat_value() const
    {
        const size_t n = offsetof(Self, OtherErrorSourceFormat);
        return GetField<String>(n).value;
    }
    
    void OtherErrorSourceFormat_value(const String& x)
    {
        const size_t n = offsetof(Self, OtherErrorSourceFormat);
        GetField<String>(n).Set(x);
    }
    
    bool OtherErrorSourceFormat_exists() const
    {
        const size_t n = offsetof(Self, OtherErrorSourceFormat);
        return GetField<String>(n).exists ? true : false;
    }
    
    void OtherErrorSourceFormat_clear()
    {
        const size_t n = offsetof(Self, OtherErrorSourceFormat);
        GetField<String>(n).Clear();
    }

    //
    // CIM_Error_Class.CIMStatusCode
    //
    
    const Field<Uint32>& CIMStatusCode() const
    {
        const size_t n = offsetof(Self, CIMStatusCode);
        return GetField<Uint32>(n);
    }
    
    void CIMStatusCode(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, CIMStatusCode);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& CIMStatusCode_value() const
    {
        const size_t n = offsetof(Self, CIMStatusCode);
        return GetField<Uint32>(n).value;
    }
    
    void CIMStatusCode_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, CIMStatusCode);
        GetField<Uint32>(n).Set(x);
    }
    
    bool CIMStatusCode_exists() const
    {
        const size_t n = offsetof(Self, CIMStatusCode);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void CIMStatusCode_clear()
    {
        const size_t n = offsetof(Self, CIMStatusCode);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_Error_Class.CIMStatusCodeDescription
    //
    
    const Field<String>& CIMStatusCodeDescription() const
    {
        const size_t n = offsetof(Self, CIMStatusCodeDescription);
        return GetField<String>(n);
    }
    
    void CIMStatusCodeDescription(const Field<String>& x)
    {
        const size_t n = offsetof(Self, CIMStatusCodeDescription);
        GetField<String>(n) = x;
    }
    
    const String& CIMStatusCodeDescription_value() const
    {
        const size_t n = offsetof(Self, CIMStatusCodeDescription);
        return GetField<String>(n).value;
    }
    
    void CIMStatusCodeDescription_value(const String& x)
    {
        const size_t n = offsetof(Self, CIMStatusCodeDescription);
        GetField<String>(n).Set(x);
    }
    
    bool CIMStatusCodeDescription_exists() const
    {
        const size_t n = offsetof(Self, CIMStatusCodeDescription);
        return GetField<String>(n).exists ? true : false;
    }
    
    void CIMStatusCodeDescription_clear()
    {
        const size_t n = offsetof(Self, CIMStatusCodeDescription);
        GetField<String>(n).Clear();
    }
};

typedef Array<CIM_Error_Class> CIM_Error_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_Error_h */
