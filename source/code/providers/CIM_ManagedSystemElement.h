/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_ManagedSystemElement_h
#define _CIM_ManagedSystemElement_h

#include <MI.h>
#include "CIM_ManagedElement.h"

/*
**==============================================================================
**
** CIM_ManagedSystemElement [CIM_ManagedSystemElement]
**
** Keys:
**
**==============================================================================
*/

typedef struct _CIM_ManagedSystemElement /* extends CIM_ManagedElement */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_ManagedSystemElement properties */
    MI_ConstDatetimeField InstallDate;
    MI_ConstStringField Name;
    MI_ConstUint16AField OperationalStatus;
    MI_ConstStringAField StatusDescriptions;
    MI_ConstStringField Status;
    MI_ConstUint16Field HealthState;
    MI_ConstUint16Field CommunicationStatus;
    MI_ConstUint16Field DetailedStatus;
    MI_ConstUint16Field OperatingStatus;
    MI_ConstUint16Field PrimaryStatus;
}
CIM_ManagedSystemElement;

typedef struct _CIM_ManagedSystemElement_Ref
{
    CIM_ManagedSystemElement* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_ManagedSystemElement_Ref;

typedef struct _CIM_ManagedSystemElement_ConstRef
{
    MI_CONST CIM_ManagedSystemElement* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_ManagedSystemElement_ConstRef;

typedef struct _CIM_ManagedSystemElement_Array
{
    struct _CIM_ManagedSystemElement** data;
    MI_Uint32 size;
}
CIM_ManagedSystemElement_Array;

typedef struct _CIM_ManagedSystemElement_ConstArray
{
    struct _CIM_ManagedSystemElement MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_ManagedSystemElement_ConstArray;

typedef struct _CIM_ManagedSystemElement_ArrayRef
{
    CIM_ManagedSystemElement_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_ManagedSystemElement_ArrayRef;

typedef struct _CIM_ManagedSystemElement_ConstArrayRef
{
    CIM_ManagedSystemElement_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_ManagedSystemElement_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_ManagedSystemElement_rtti;

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Construct(
    CIM_ManagedSystemElement* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_ManagedSystemElement_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clone(
    const CIM_ManagedSystemElement* self,
    CIM_ManagedSystemElement** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_ManagedSystemElement_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_ManagedSystemElement_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Destruct(CIM_ManagedSystemElement* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Delete(CIM_ManagedSystemElement* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Post(
    const CIM_ManagedSystemElement* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_InstanceID(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_InstanceID(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_InstanceID(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_Caption(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_Caption(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_Caption(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_Description(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_Description(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_Description(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_ElementName(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_ElementName(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_ElementName(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_InstallDate(
    CIM_ManagedSystemElement* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_InstallDate(
    CIM_ManagedSystemElement* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_Name(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_Name(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_Name(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_OperationalStatus(
    CIM_ManagedSystemElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_OperationalStatus(
    CIM_ManagedSystemElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_OperationalStatus(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_StatusDescriptions(
    CIM_ManagedSystemElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_StatusDescriptions(
    CIM_ManagedSystemElement* self,
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

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_StatusDescriptions(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_Status(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_SetPtr_Status(
    CIM_ManagedSystemElement* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_Status(
    CIM_ManagedSystemElement* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_HealthState(
    CIM_ManagedSystemElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_HealthState(
    CIM_ManagedSystemElement* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_CommunicationStatus(
    CIM_ManagedSystemElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_CommunicationStatus(
    CIM_ManagedSystemElement* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_DetailedStatus(
    CIM_ManagedSystemElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_DetailedStatus(
    CIM_ManagedSystemElement* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_OperatingStatus(
    CIM_ManagedSystemElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_OperatingStatus(
    CIM_ManagedSystemElement* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Set_PrimaryStatus(
    CIM_ManagedSystemElement* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_ManagedSystemElement_Clear_PrimaryStatus(
    CIM_ManagedSystemElement* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}


/*
**==============================================================================
**
** CIM_ManagedSystemElement_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_ManagedSystemElement_Class : public CIM_ManagedElement_Class
{
public:
    
    typedef CIM_ManagedSystemElement Self;
    
    CIM_ManagedSystemElement_Class() :
        CIM_ManagedElement_Class(&CIM_ManagedSystemElement_rtti)
    {
    }
    
    CIM_ManagedSystemElement_Class(
        const CIM_ManagedSystemElement* instanceName,
        bool keysOnly) :
        CIM_ManagedElement_Class(
            &CIM_ManagedSystemElement_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_ManagedSystemElement_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_ManagedElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_ManagedSystemElement_Class(
        const MI_ClassDecl* clDecl) :
        CIM_ManagedElement_Class(clDecl)
    {
    }
    
    CIM_ManagedSystemElement_Class& operator=(
        const CIM_ManagedSystemElement_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_ManagedSystemElement_Class(
        const CIM_ManagedSystemElement_Class& x) :
        CIM_ManagedElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_ManagedSystemElement_rtti;
    }

    //
    // CIM_ManagedSystemElement_Class.InstallDate
    //
    
    const Field<Datetime>& InstallDate() const
    {
        const size_t n = offsetof(Self, InstallDate);
        return GetField<Datetime>(n);
    }
    
    void InstallDate(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, InstallDate);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& InstallDate_value() const
    {
        const size_t n = offsetof(Self, InstallDate);
        return GetField<Datetime>(n).value;
    }
    
    void InstallDate_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, InstallDate);
        GetField<Datetime>(n).Set(x);
    }
    
    bool InstallDate_exists() const
    {
        const size_t n = offsetof(Self, InstallDate);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void InstallDate_clear()
    {
        const size_t n = offsetof(Self, InstallDate);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.Name
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

    //
    // CIM_ManagedSystemElement_Class.OperationalStatus
    //
    
    const Field<Uint16A>& OperationalStatus() const
    {
        const size_t n = offsetof(Self, OperationalStatus);
        return GetField<Uint16A>(n);
    }
    
    void OperationalStatus(const Field<Uint16A>& x)
    {
        const size_t n = offsetof(Self, OperationalStatus);
        GetField<Uint16A>(n) = x;
    }
    
    const Uint16A& OperationalStatus_value() const
    {
        const size_t n = offsetof(Self, OperationalStatus);
        return GetField<Uint16A>(n).value;
    }
    
    void OperationalStatus_value(const Uint16A& x)
    {
        const size_t n = offsetof(Self, OperationalStatus);
        GetField<Uint16A>(n).Set(x);
    }
    
    bool OperationalStatus_exists() const
    {
        const size_t n = offsetof(Self, OperationalStatus);
        return GetField<Uint16A>(n).exists ? true : false;
    }
    
    void OperationalStatus_clear()
    {
        const size_t n = offsetof(Self, OperationalStatus);
        GetField<Uint16A>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.StatusDescriptions
    //
    
    const Field<StringA>& StatusDescriptions() const
    {
        const size_t n = offsetof(Self, StatusDescriptions);
        return GetField<StringA>(n);
    }
    
    void StatusDescriptions(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, StatusDescriptions);
        GetField<StringA>(n) = x;
    }
    
    const StringA& StatusDescriptions_value() const
    {
        const size_t n = offsetof(Self, StatusDescriptions);
        return GetField<StringA>(n).value;
    }
    
    void StatusDescriptions_value(const StringA& x)
    {
        const size_t n = offsetof(Self, StatusDescriptions);
        GetField<StringA>(n).Set(x);
    }
    
    bool StatusDescriptions_exists() const
    {
        const size_t n = offsetof(Self, StatusDescriptions);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void StatusDescriptions_clear()
    {
        const size_t n = offsetof(Self, StatusDescriptions);
        GetField<StringA>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.Status
    //
    
    const Field<String>& Status() const
    {
        const size_t n = offsetof(Self, Status);
        return GetField<String>(n);
    }
    
    void Status(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Status);
        GetField<String>(n) = x;
    }
    
    const String& Status_value() const
    {
        const size_t n = offsetof(Self, Status);
        return GetField<String>(n).value;
    }
    
    void Status_value(const String& x)
    {
        const size_t n = offsetof(Self, Status);
        GetField<String>(n).Set(x);
    }
    
    bool Status_exists() const
    {
        const size_t n = offsetof(Self, Status);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Status_clear()
    {
        const size_t n = offsetof(Self, Status);
        GetField<String>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.HealthState
    //
    
    const Field<Uint16>& HealthState() const
    {
        const size_t n = offsetof(Self, HealthState);
        return GetField<Uint16>(n);
    }
    
    void HealthState(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, HealthState);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& HealthState_value() const
    {
        const size_t n = offsetof(Self, HealthState);
        return GetField<Uint16>(n).value;
    }
    
    void HealthState_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, HealthState);
        GetField<Uint16>(n).Set(x);
    }
    
    bool HealthState_exists() const
    {
        const size_t n = offsetof(Self, HealthState);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void HealthState_clear()
    {
        const size_t n = offsetof(Self, HealthState);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.CommunicationStatus
    //
    
    const Field<Uint16>& CommunicationStatus() const
    {
        const size_t n = offsetof(Self, CommunicationStatus);
        return GetField<Uint16>(n);
    }
    
    void CommunicationStatus(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, CommunicationStatus);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& CommunicationStatus_value() const
    {
        const size_t n = offsetof(Self, CommunicationStatus);
        return GetField<Uint16>(n).value;
    }
    
    void CommunicationStatus_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, CommunicationStatus);
        GetField<Uint16>(n).Set(x);
    }
    
    bool CommunicationStatus_exists() const
    {
        const size_t n = offsetof(Self, CommunicationStatus);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void CommunicationStatus_clear()
    {
        const size_t n = offsetof(Self, CommunicationStatus);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.DetailedStatus
    //
    
    const Field<Uint16>& DetailedStatus() const
    {
        const size_t n = offsetof(Self, DetailedStatus);
        return GetField<Uint16>(n);
    }
    
    void DetailedStatus(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, DetailedStatus);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& DetailedStatus_value() const
    {
        const size_t n = offsetof(Self, DetailedStatus);
        return GetField<Uint16>(n).value;
    }
    
    void DetailedStatus_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, DetailedStatus);
        GetField<Uint16>(n).Set(x);
    }
    
    bool DetailedStatus_exists() const
    {
        const size_t n = offsetof(Self, DetailedStatus);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void DetailedStatus_clear()
    {
        const size_t n = offsetof(Self, DetailedStatus);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.OperatingStatus
    //
    
    const Field<Uint16>& OperatingStatus() const
    {
        const size_t n = offsetof(Self, OperatingStatus);
        return GetField<Uint16>(n);
    }
    
    void OperatingStatus(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, OperatingStatus);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& OperatingStatus_value() const
    {
        const size_t n = offsetof(Self, OperatingStatus);
        return GetField<Uint16>(n).value;
    }
    
    void OperatingStatus_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, OperatingStatus);
        GetField<Uint16>(n).Set(x);
    }
    
    bool OperatingStatus_exists() const
    {
        const size_t n = offsetof(Self, OperatingStatus);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void OperatingStatus_clear()
    {
        const size_t n = offsetof(Self, OperatingStatus);
        GetField<Uint16>(n).Clear();
    }

    //
    // CIM_ManagedSystemElement_Class.PrimaryStatus
    //
    
    const Field<Uint16>& PrimaryStatus() const
    {
        const size_t n = offsetof(Self, PrimaryStatus);
        return GetField<Uint16>(n);
    }
    
    void PrimaryStatus(const Field<Uint16>& x)
    {
        const size_t n = offsetof(Self, PrimaryStatus);
        GetField<Uint16>(n) = x;
    }
    
    const Uint16& PrimaryStatus_value() const
    {
        const size_t n = offsetof(Self, PrimaryStatus);
        return GetField<Uint16>(n).value;
    }
    
    void PrimaryStatus_value(const Uint16& x)
    {
        const size_t n = offsetof(Self, PrimaryStatus);
        GetField<Uint16>(n).Set(x);
    }
    
    bool PrimaryStatus_exists() const
    {
        const size_t n = offsetof(Self, PrimaryStatus);
        return GetField<Uint16>(n).exists ? true : false;
    }
    
    void PrimaryStatus_clear()
    {
        const size_t n = offsetof(Self, PrimaryStatus);
        GetField<Uint16>(n).Clear();
    }
};

typedef Array<CIM_ManagedSystemElement_Class> CIM_ManagedSystemElement_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_ManagedSystemElement_h */
