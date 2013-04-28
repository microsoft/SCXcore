/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_NetworkPortStatistics_h
#define _CIM_NetworkPortStatistics_h

#include <MI.h>
#include "CIM_StatisticalData.h"

/*
**==============================================================================
**
** CIM_NetworkPortStatistics [CIM_NetworkPortStatistics]
**
** Keys:
**    InstanceID
**
**==============================================================================
*/

typedef struct _CIM_NetworkPortStatistics /* extends CIM_StatisticalData */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    /*KEY*/ MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_StatisticalData properties */
    MI_ConstDatetimeField StartStatisticTime;
    MI_ConstDatetimeField StatisticTime;
    MI_ConstDatetimeField SampleInterval;
    /* CIM_NetworkPortStatistics properties */
    MI_ConstUint64Field BytesTransmitted;
    MI_ConstUint64Field BytesReceived;
    MI_ConstUint64Field PacketsTransmitted;
    MI_ConstUint64Field PacketsReceived;
}
CIM_NetworkPortStatistics;

typedef struct _CIM_NetworkPortStatistics_Ref
{
    CIM_NetworkPortStatistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_NetworkPortStatistics_Ref;

typedef struct _CIM_NetworkPortStatistics_ConstRef
{
    MI_CONST CIM_NetworkPortStatistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_NetworkPortStatistics_ConstRef;

typedef struct _CIM_NetworkPortStatistics_Array
{
    struct _CIM_NetworkPortStatistics** data;
    MI_Uint32 size;
}
CIM_NetworkPortStatistics_Array;

typedef struct _CIM_NetworkPortStatistics_ConstArray
{
    struct _CIM_NetworkPortStatistics MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_NetworkPortStatistics_ConstArray;

typedef struct _CIM_NetworkPortStatistics_ArrayRef
{
    CIM_NetworkPortStatistics_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_NetworkPortStatistics_ArrayRef;

typedef struct _CIM_NetworkPortStatistics_ConstArrayRef
{
    CIM_NetworkPortStatistics_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_NetworkPortStatistics_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_NetworkPortStatistics_rtti;

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Construct(
    CIM_NetworkPortStatistics* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_NetworkPortStatistics_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clone(
    const CIM_NetworkPortStatistics* self,
    CIM_NetworkPortStatistics** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_NetworkPortStatistics_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_NetworkPortStatistics_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Destruct(CIM_NetworkPortStatistics* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Delete(CIM_NetworkPortStatistics* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Post(
    const CIM_NetworkPortStatistics* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_InstanceID(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_SetPtr_InstanceID(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_InstanceID(
    CIM_NetworkPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_Caption(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_SetPtr_Caption(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_Caption(
    CIM_NetworkPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_Description(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_SetPtr_Description(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_Description(
    CIM_NetworkPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_ElementName(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_SetPtr_ElementName(
    CIM_NetworkPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_ElementName(
    CIM_NetworkPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_StartStatisticTime(
    CIM_NetworkPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StartStatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StartStatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_StartStatisticTime(
    CIM_NetworkPortStatistics* self)
{
    memset((void*)&self->StartStatisticTime, 0, sizeof(self->StartStatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_StatisticTime(
    CIM_NetworkPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_StatisticTime(
    CIM_NetworkPortStatistics* self)
{
    memset((void*)&self->StatisticTime, 0, sizeof(self->StatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_SampleInterval(
    CIM_NetworkPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->SampleInterval)->value = x;
    ((MI_DatetimeField*)&self->SampleInterval)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_SampleInterval(
    CIM_NetworkPortStatistics* self)
{
    memset((void*)&self->SampleInterval, 0, sizeof(self->SampleInterval));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_BytesTransmitted(
    CIM_NetworkPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesTransmitted)->value = x;
    ((MI_Uint64Field*)&self->BytesTransmitted)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_BytesTransmitted(
    CIM_NetworkPortStatistics* self)
{
    memset((void*)&self->BytesTransmitted, 0, sizeof(self->BytesTransmitted));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_BytesReceived(
    CIM_NetworkPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesReceived)->value = x;
    ((MI_Uint64Field*)&self->BytesReceived)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_BytesReceived(
    CIM_NetworkPortStatistics* self)
{
    memset((void*)&self->BytesReceived, 0, sizeof(self->BytesReceived));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_PacketsTransmitted(
    CIM_NetworkPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PacketsTransmitted)->value = x;
    ((MI_Uint64Field*)&self->PacketsTransmitted)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_PacketsTransmitted(
    CIM_NetworkPortStatistics* self)
{
    memset((void*)&self->PacketsTransmitted, 0, sizeof(self->PacketsTransmitted));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Set_PacketsReceived(
    CIM_NetworkPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PacketsReceived)->value = x;
    ((MI_Uint64Field*)&self->PacketsReceived)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_Clear_PacketsReceived(
    CIM_NetworkPortStatistics* self)
{
    memset((void*)&self->PacketsReceived, 0, sizeof(self->PacketsReceived));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_NetworkPortStatistics.ResetSelectedStats()
**
**==============================================================================
*/

typedef struct _CIM_NetworkPortStatistics_ResetSelectedStats
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstStringAField SelectedStatistics;
}
CIM_NetworkPortStatistics_ResetSelectedStats;

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_ResetSelectedStats_Set_MIReturn(
    CIM_NetworkPortStatistics_ResetSelectedStats* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_ResetSelectedStats_Clear_MIReturn(
    CIM_NetworkPortStatistics_ResetSelectedStats* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_ResetSelectedStats_Set_SelectedStatistics(
    CIM_NetworkPortStatistics_ResetSelectedStats* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_ResetSelectedStats_SetPtr_SelectedStatistics(
    CIM_NetworkPortStatistics_ResetSelectedStats* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_NetworkPortStatistics_ResetSelectedStats_Clear_SelectedStatistics(
    CIM_NetworkPortStatistics_ResetSelectedStats* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}


/*
**==============================================================================
**
** CIM_NetworkPortStatistics_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_NetworkPortStatistics_Class : public CIM_StatisticalData_Class
{
public:
    
    typedef CIM_NetworkPortStatistics Self;
    
    CIM_NetworkPortStatistics_Class() :
        CIM_StatisticalData_Class(&CIM_NetworkPortStatistics_rtti)
    {
    }
    
    CIM_NetworkPortStatistics_Class(
        const CIM_NetworkPortStatistics* instanceName,
        bool keysOnly) :
        CIM_StatisticalData_Class(
            &CIM_NetworkPortStatistics_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_NetworkPortStatistics_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_StatisticalData_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_NetworkPortStatistics_Class(
        const MI_ClassDecl* clDecl) :
        CIM_StatisticalData_Class(clDecl)
    {
    }
    
    CIM_NetworkPortStatistics_Class& operator=(
        const CIM_NetworkPortStatistics_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_NetworkPortStatistics_Class(
        const CIM_NetworkPortStatistics_Class& x) :
        CIM_StatisticalData_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_NetworkPortStatistics_rtti;
    }

    //
    // CIM_NetworkPortStatistics_Class.BytesTransmitted
    //
    
    const Field<Uint64>& BytesTransmitted() const
    {
        const size_t n = offsetof(Self, BytesTransmitted);
        return GetField<Uint64>(n);
    }
    
    void BytesTransmitted(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BytesTransmitted);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BytesTransmitted_value() const
    {
        const size_t n = offsetof(Self, BytesTransmitted);
        return GetField<Uint64>(n).value;
    }
    
    void BytesTransmitted_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BytesTransmitted);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BytesTransmitted_exists() const
    {
        const size_t n = offsetof(Self, BytesTransmitted);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BytesTransmitted_clear()
    {
        const size_t n = offsetof(Self, BytesTransmitted);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_NetworkPortStatistics_Class.BytesReceived
    //
    
    const Field<Uint64>& BytesReceived() const
    {
        const size_t n = offsetof(Self, BytesReceived);
        return GetField<Uint64>(n);
    }
    
    void BytesReceived(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BytesReceived);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BytesReceived_value() const
    {
        const size_t n = offsetof(Self, BytesReceived);
        return GetField<Uint64>(n).value;
    }
    
    void BytesReceived_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BytesReceived);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BytesReceived_exists() const
    {
        const size_t n = offsetof(Self, BytesReceived);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BytesReceived_clear()
    {
        const size_t n = offsetof(Self, BytesReceived);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_NetworkPortStatistics_Class.PacketsTransmitted
    //
    
    const Field<Uint64>& PacketsTransmitted() const
    {
        const size_t n = offsetof(Self, PacketsTransmitted);
        return GetField<Uint64>(n);
    }
    
    void PacketsTransmitted(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, PacketsTransmitted);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& PacketsTransmitted_value() const
    {
        const size_t n = offsetof(Self, PacketsTransmitted);
        return GetField<Uint64>(n).value;
    }
    
    void PacketsTransmitted_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, PacketsTransmitted);
        GetField<Uint64>(n).Set(x);
    }
    
    bool PacketsTransmitted_exists() const
    {
        const size_t n = offsetof(Self, PacketsTransmitted);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void PacketsTransmitted_clear()
    {
        const size_t n = offsetof(Self, PacketsTransmitted);
        GetField<Uint64>(n).Clear();
    }

    //
    // CIM_NetworkPortStatistics_Class.PacketsReceived
    //
    
    const Field<Uint64>& PacketsReceived() const
    {
        const size_t n = offsetof(Self, PacketsReceived);
        return GetField<Uint64>(n);
    }
    
    void PacketsReceived(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, PacketsReceived);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& PacketsReceived_value() const
    {
        const size_t n = offsetof(Self, PacketsReceived);
        return GetField<Uint64>(n).value;
    }
    
    void PacketsReceived_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, PacketsReceived);
        GetField<Uint64>(n).Set(x);
    }
    
    bool PacketsReceived_exists() const
    {
        const size_t n = offsetof(Self, PacketsReceived);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void PacketsReceived_clear()
    {
        const size_t n = offsetof(Self, PacketsReceived);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<CIM_NetworkPortStatistics_Class> CIM_NetworkPortStatistics_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_NetworkPortStatistics_h */
