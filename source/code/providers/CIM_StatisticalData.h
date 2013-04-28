/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_StatisticalData_h
#define _CIM_StatisticalData_h

#include <MI.h>
#include "CIM_ManagedElement.h"

/*
**==============================================================================
**
** CIM_StatisticalData [CIM_StatisticalData]
**
** Keys:
**    InstanceID
**
**==============================================================================
*/

typedef struct _CIM_StatisticalData /* extends CIM_ManagedElement */
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
}
CIM_StatisticalData;

typedef struct _CIM_StatisticalData_Ref
{
    CIM_StatisticalData* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalData_Ref;

typedef struct _CIM_StatisticalData_ConstRef
{
    MI_CONST CIM_StatisticalData* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalData_ConstRef;

typedef struct _CIM_StatisticalData_Array
{
    struct _CIM_StatisticalData** data;
    MI_Uint32 size;
}
CIM_StatisticalData_Array;

typedef struct _CIM_StatisticalData_ConstArray
{
    struct _CIM_StatisticalData MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_StatisticalData_ConstArray;

typedef struct _CIM_StatisticalData_ArrayRef
{
    CIM_StatisticalData_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalData_ArrayRef;

typedef struct _CIM_StatisticalData_ConstArrayRef
{
    CIM_StatisticalData_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_StatisticalData_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_StatisticalData_rtti;

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Construct(
    CIM_StatisticalData* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_StatisticalData_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clone(
    const CIM_StatisticalData* self,
    CIM_StatisticalData** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_StatisticalData_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_StatisticalData_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Destruct(CIM_StatisticalData* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Delete(CIM_StatisticalData* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Post(
    const CIM_StatisticalData* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Set_InstanceID(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_SetPtr_InstanceID(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clear_InstanceID(
    CIM_StatisticalData* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Set_Caption(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_SetPtr_Caption(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clear_Caption(
    CIM_StatisticalData* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Set_Description(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_SetPtr_Description(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clear_Description(
    CIM_StatisticalData* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Set_ElementName(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_SetPtr_ElementName(
    CIM_StatisticalData* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clear_ElementName(
    CIM_StatisticalData* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Set_StartStatisticTime(
    CIM_StatisticalData* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StartStatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StartStatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clear_StartStatisticTime(
    CIM_StatisticalData* self)
{
    memset((void*)&self->StartStatisticTime, 0, sizeof(self->StartStatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Set_StatisticTime(
    CIM_StatisticalData* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clear_StatisticTime(
    CIM_StatisticalData* self)
{
    memset((void*)&self->StatisticTime, 0, sizeof(self->StatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Set_SampleInterval(
    CIM_StatisticalData* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->SampleInterval)->value = x;
    ((MI_DatetimeField*)&self->SampleInterval)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_Clear_SampleInterval(
    CIM_StatisticalData* self)
{
    memset((void*)&self->SampleInterval, 0, sizeof(self->SampleInterval));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_StatisticalData.ResetSelectedStats()
**
**==============================================================================
*/

typedef struct _CIM_StatisticalData_ResetSelectedStats
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstStringAField SelectedStatistics;
}
CIM_StatisticalData_ResetSelectedStats;

MI_EXTERN_C MI_CONST MI_MethodDecl CIM_StatisticalData_ResetSelectedStats_rtti;

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Construct(
    CIM_StatisticalData_ResetSelectedStats* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &CIM_StatisticalData_ResetSelectedStats_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Clone(
    const CIM_StatisticalData_ResetSelectedStats* self,
    CIM_StatisticalData_ResetSelectedStats** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Destruct(
    CIM_StatisticalData_ResetSelectedStats* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Delete(
    CIM_StatisticalData_ResetSelectedStats* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Post(
    const CIM_StatisticalData_ResetSelectedStats* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Set_MIReturn(
    CIM_StatisticalData_ResetSelectedStats* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Clear_MIReturn(
    CIM_StatisticalData_ResetSelectedStats* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Set_SelectedStatistics(
    CIM_StatisticalData_ResetSelectedStats* self,
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

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_SetPtr_SelectedStatistics(
    CIM_StatisticalData_ResetSelectedStats* self,
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

MI_INLINE MI_Result MI_CALL CIM_StatisticalData_ResetSelectedStats_Clear_SelectedStatistics(
    CIM_StatisticalData_ResetSelectedStats* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}


/*
**==============================================================================
**
** CIM_StatisticalData_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_StatisticalData_Class : public CIM_ManagedElement_Class
{
public:
    
    typedef CIM_StatisticalData Self;
    
    CIM_StatisticalData_Class() :
        CIM_ManagedElement_Class(&CIM_StatisticalData_rtti)
    {
    }
    
    CIM_StatisticalData_Class(
        const CIM_StatisticalData* instanceName,
        bool keysOnly) :
        CIM_ManagedElement_Class(
            &CIM_StatisticalData_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_StatisticalData_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_ManagedElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_StatisticalData_Class(
        const MI_ClassDecl* clDecl) :
        CIM_ManagedElement_Class(clDecl)
    {
    }
    
    CIM_StatisticalData_Class& operator=(
        const CIM_StatisticalData_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_StatisticalData_Class(
        const CIM_StatisticalData_Class& x) :
        CIM_ManagedElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_StatisticalData_rtti;
    }

    //
    // CIM_StatisticalData_Class.StartStatisticTime
    //
    
    const Field<Datetime>& StartStatisticTime() const
    {
        const size_t n = offsetof(Self, StartStatisticTime);
        return GetField<Datetime>(n);
    }
    
    void StartStatisticTime(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, StartStatisticTime);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& StartStatisticTime_value() const
    {
        const size_t n = offsetof(Self, StartStatisticTime);
        return GetField<Datetime>(n).value;
    }
    
    void StartStatisticTime_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, StartStatisticTime);
        GetField<Datetime>(n).Set(x);
    }
    
    bool StartStatisticTime_exists() const
    {
        const size_t n = offsetof(Self, StartStatisticTime);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void StartStatisticTime_clear()
    {
        const size_t n = offsetof(Self, StartStatisticTime);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_StatisticalData_Class.StatisticTime
    //
    
    const Field<Datetime>& StatisticTime() const
    {
        const size_t n = offsetof(Self, StatisticTime);
        return GetField<Datetime>(n);
    }
    
    void StatisticTime(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, StatisticTime);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& StatisticTime_value() const
    {
        const size_t n = offsetof(Self, StatisticTime);
        return GetField<Datetime>(n).value;
    }
    
    void StatisticTime_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, StatisticTime);
        GetField<Datetime>(n).Set(x);
    }
    
    bool StatisticTime_exists() const
    {
        const size_t n = offsetof(Self, StatisticTime);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void StatisticTime_clear()
    {
        const size_t n = offsetof(Self, StatisticTime);
        GetField<Datetime>(n).Clear();
    }

    //
    // CIM_StatisticalData_Class.SampleInterval
    //
    
    const Field<Datetime>& SampleInterval() const
    {
        const size_t n = offsetof(Self, SampleInterval);
        return GetField<Datetime>(n);
    }
    
    void SampleInterval(const Field<Datetime>& x)
    {
        const size_t n = offsetof(Self, SampleInterval);
        GetField<Datetime>(n) = x;
    }
    
    const Datetime& SampleInterval_value() const
    {
        const size_t n = offsetof(Self, SampleInterval);
        return GetField<Datetime>(n).value;
    }
    
    void SampleInterval_value(const Datetime& x)
    {
        const size_t n = offsetof(Self, SampleInterval);
        GetField<Datetime>(n).Set(x);
    }
    
    bool SampleInterval_exists() const
    {
        const size_t n = offsetof(Self, SampleInterval);
        return GetField<Datetime>(n).exists ? true : false;
    }
    
    void SampleInterval_clear()
    {
        const size_t n = offsetof(Self, SampleInterval);
        GetField<Datetime>(n).Clear();
    }
};

typedef Array<CIM_StatisticalData_Class> CIM_StatisticalData_ClassA;

class CIM_StatisticalData_ResetSelectedStats_Class : public Instance
{
public:
    
    typedef CIM_StatisticalData_ResetSelectedStats Self;
    
    CIM_StatisticalData_ResetSelectedStats_Class() :
        Instance(&CIM_StatisticalData_ResetSelectedStats_rtti)
    {
    }
    
    CIM_StatisticalData_ResetSelectedStats_Class(
        const CIM_StatisticalData_ResetSelectedStats* instanceName,
        bool keysOnly) :
        Instance(
            &CIM_StatisticalData_ResetSelectedStats_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_StatisticalData_ResetSelectedStats_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    CIM_StatisticalData_ResetSelectedStats_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    CIM_StatisticalData_ResetSelectedStats_Class& operator=(
        const CIM_StatisticalData_ResetSelectedStats_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_StatisticalData_ResetSelectedStats_Class(
        const CIM_StatisticalData_ResetSelectedStats_Class& x) :
        Instance(x)
    {
    }

    //
    // CIM_StatisticalData_ResetSelectedStats_Class.MIReturn
    //
    
    const Field<Uint32>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n);
    }
    
    void MIReturn(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).value;
    }
    
    void MIReturn_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_StatisticalData_ResetSelectedStats_Class.SelectedStatistics
    //
    
    const Field<StringA>& SelectedStatistics() const
    {
        const size_t n = offsetof(Self, SelectedStatistics);
        return GetField<StringA>(n);
    }
    
    void SelectedStatistics(const Field<StringA>& x)
    {
        const size_t n = offsetof(Self, SelectedStatistics);
        GetField<StringA>(n) = x;
    }
    
    const StringA& SelectedStatistics_value() const
    {
        const size_t n = offsetof(Self, SelectedStatistics);
        return GetField<StringA>(n).value;
    }
    
    void SelectedStatistics_value(const StringA& x)
    {
        const size_t n = offsetof(Self, SelectedStatistics);
        GetField<StringA>(n).Set(x);
    }
    
    bool SelectedStatistics_exists() const
    {
        const size_t n = offsetof(Self, SelectedStatistics);
        return GetField<StringA>(n).exists ? true : false;
    }
    
    void SelectedStatistics_clear()
    {
        const size_t n = offsetof(Self, SelectedStatistics);
        GetField<StringA>(n).Clear();
    }
};

typedef Array<CIM_StatisticalData_ResetSelectedStats_Class> CIM_StatisticalData_ResetSelectedStats_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_StatisticalData_h */
