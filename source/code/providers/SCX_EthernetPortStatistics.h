/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_EthernetPortStatistics_h
#define _SCX_EthernetPortStatistics_h

#include <MI.h>
#include "CIM_EthernetPortStatistics.h"

/*
**==============================================================================
**
** SCX_EthernetPortStatistics [SCX_EthernetPortStatistics]
**
** Keys:
**    InstanceID
**
**==============================================================================
*/

typedef struct _SCX_EthernetPortStatistics /* extends CIM_EthernetPortStatistics */
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
    /* CIM_EthernetPortStatistics properties */
    MI_ConstUint32Field SymbolErrors;
    MI_ConstUint32Field AlignmentErrors;
    MI_ConstUint32Field FCSErrors;
    MI_ConstUint32Field SingleCollisionFrames;
    MI_ConstUint32Field MultipleCollisionFrames;
    MI_ConstUint32Field SQETestErrors;
    MI_ConstUint32Field DeferredTransmissions;
    MI_ConstUint32Field LateCollisions;
    MI_ConstUint32Field ExcessiveCollisions;
    MI_ConstUint32Field InternalMACTransmitErrors;
    MI_ConstUint32Field InternalMACReceiveErrors;
    MI_ConstUint32Field CarrierSenseErrors;
    MI_ConstUint32Field FrameTooLongs;
    /* SCX_EthernetPortStatistics properties */
    MI_ConstUint64Field BytesTotal;
    MI_ConstUint64Field TotalRxErrors;
    MI_ConstUint64Field TotalTxErrors;
    MI_ConstUint64Field TotalCollisions;
}
SCX_EthernetPortStatistics;

typedef struct _SCX_EthernetPortStatistics_Ref
{
    SCX_EthernetPortStatistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPortStatistics_Ref;

typedef struct _SCX_EthernetPortStatistics_ConstRef
{
    MI_CONST SCX_EthernetPortStatistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPortStatistics_ConstRef;

typedef struct _SCX_EthernetPortStatistics_Array
{
    struct _SCX_EthernetPortStatistics** data;
    MI_Uint32 size;
}
SCX_EthernetPortStatistics_Array;

typedef struct _SCX_EthernetPortStatistics_ConstArray
{
    struct _SCX_EthernetPortStatistics MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_EthernetPortStatistics_ConstArray;

typedef struct _SCX_EthernetPortStatistics_ArrayRef
{
    SCX_EthernetPortStatistics_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPortStatistics_ArrayRef;

typedef struct _SCX_EthernetPortStatistics_ConstArrayRef
{
    SCX_EthernetPortStatistics_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_EthernetPortStatistics_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_EthernetPortStatistics_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Construct(
    SCX_EthernetPortStatistics* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_EthernetPortStatistics_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clone(
    const SCX_EthernetPortStatistics* self,
    SCX_EthernetPortStatistics** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_EthernetPortStatistics_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_EthernetPortStatistics_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Destruct(SCX_EthernetPortStatistics* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Delete(SCX_EthernetPortStatistics* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Post(
    const SCX_EthernetPortStatistics* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_InstanceID(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_SetPtr_InstanceID(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_InstanceID(
    SCX_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_Caption(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_SetPtr_Caption(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_Caption(
    SCX_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_Description(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_SetPtr_Description(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_Description(
    SCX_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_ElementName(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_SetPtr_ElementName(
    SCX_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_ElementName(
    SCX_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_StartStatisticTime(
    SCX_EthernetPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StartStatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StartStatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_StartStatisticTime(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->StartStatisticTime, 0, sizeof(self->StartStatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_StatisticTime(
    SCX_EthernetPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_StatisticTime(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->StatisticTime, 0, sizeof(self->StatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_SampleInterval(
    SCX_EthernetPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->SampleInterval)->value = x;
    ((MI_DatetimeField*)&self->SampleInterval)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_SampleInterval(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->SampleInterval, 0, sizeof(self->SampleInterval));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_BytesTransmitted(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesTransmitted)->value = x;
    ((MI_Uint64Field*)&self->BytesTransmitted)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_BytesTransmitted(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->BytesTransmitted, 0, sizeof(self->BytesTransmitted));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_BytesReceived(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesReceived)->value = x;
    ((MI_Uint64Field*)&self->BytesReceived)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_BytesReceived(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->BytesReceived, 0, sizeof(self->BytesReceived));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_PacketsTransmitted(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PacketsTransmitted)->value = x;
    ((MI_Uint64Field*)&self->PacketsTransmitted)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_PacketsTransmitted(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->PacketsTransmitted, 0, sizeof(self->PacketsTransmitted));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_PacketsReceived(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PacketsReceived)->value = x;
    ((MI_Uint64Field*)&self->PacketsReceived)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_PacketsReceived(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->PacketsReceived, 0, sizeof(self->PacketsReceived));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_SymbolErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->SymbolErrors)->value = x;
    ((MI_Uint32Field*)&self->SymbolErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_SymbolErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->SymbolErrors, 0, sizeof(self->SymbolErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_AlignmentErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->AlignmentErrors)->value = x;
    ((MI_Uint32Field*)&self->AlignmentErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_AlignmentErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->AlignmentErrors, 0, sizeof(self->AlignmentErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_FCSErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->FCSErrors)->value = x;
    ((MI_Uint32Field*)&self->FCSErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_FCSErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->FCSErrors, 0, sizeof(self->FCSErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_SingleCollisionFrames(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->SingleCollisionFrames)->value = x;
    ((MI_Uint32Field*)&self->SingleCollisionFrames)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_SingleCollisionFrames(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->SingleCollisionFrames, 0, sizeof(self->SingleCollisionFrames));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_MultipleCollisionFrames(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MultipleCollisionFrames)->value = x;
    ((MI_Uint32Field*)&self->MultipleCollisionFrames)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_MultipleCollisionFrames(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->MultipleCollisionFrames, 0, sizeof(self->MultipleCollisionFrames));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_SQETestErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->SQETestErrors)->value = x;
    ((MI_Uint32Field*)&self->SQETestErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_SQETestErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->SQETestErrors, 0, sizeof(self->SQETestErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_DeferredTransmissions(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->DeferredTransmissions)->value = x;
    ((MI_Uint32Field*)&self->DeferredTransmissions)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_DeferredTransmissions(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->DeferredTransmissions, 0, sizeof(self->DeferredTransmissions));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_LateCollisions(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LateCollisions)->value = x;
    ((MI_Uint32Field*)&self->LateCollisions)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_LateCollisions(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->LateCollisions, 0, sizeof(self->LateCollisions));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_ExcessiveCollisions(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ExcessiveCollisions)->value = x;
    ((MI_Uint32Field*)&self->ExcessiveCollisions)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_ExcessiveCollisions(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->ExcessiveCollisions, 0, sizeof(self->ExcessiveCollisions));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_InternalMACTransmitErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->InternalMACTransmitErrors)->value = x;
    ((MI_Uint32Field*)&self->InternalMACTransmitErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_InternalMACTransmitErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->InternalMACTransmitErrors, 0, sizeof(self->InternalMACTransmitErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_InternalMACReceiveErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->InternalMACReceiveErrors)->value = x;
    ((MI_Uint32Field*)&self->InternalMACReceiveErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_InternalMACReceiveErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->InternalMACReceiveErrors, 0, sizeof(self->InternalMACReceiveErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_CarrierSenseErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CarrierSenseErrors)->value = x;
    ((MI_Uint32Field*)&self->CarrierSenseErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_CarrierSenseErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->CarrierSenseErrors, 0, sizeof(self->CarrierSenseErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_FrameTooLongs(
    SCX_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->FrameTooLongs)->value = x;
    ((MI_Uint32Field*)&self->FrameTooLongs)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_FrameTooLongs(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->FrameTooLongs, 0, sizeof(self->FrameTooLongs));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_BytesTotal(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesTotal)->value = x;
    ((MI_Uint64Field*)&self->BytesTotal)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_BytesTotal(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->BytesTotal, 0, sizeof(self->BytesTotal));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_TotalRxErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalRxErrors)->value = x;
    ((MI_Uint64Field*)&self->TotalRxErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_TotalRxErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->TotalRxErrors, 0, sizeof(self->TotalRxErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_TotalTxErrors(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalTxErrors)->value = x;
    ((MI_Uint64Field*)&self->TotalTxErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_TotalTxErrors(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->TotalTxErrors, 0, sizeof(self->TotalTxErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Set_TotalCollisions(
    SCX_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TotalCollisions)->value = x;
    ((MI_Uint64Field*)&self->TotalCollisions)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_Clear_TotalCollisions(
    SCX_EthernetPortStatistics* self)
{
    memset((void*)&self->TotalCollisions, 0, sizeof(self->TotalCollisions));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_EthernetPortStatistics.ResetSelectedStats()
**
**==============================================================================
*/

typedef struct _SCX_EthernetPortStatistics_ResetSelectedStats
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstStringAField SelectedStatistics;
}
SCX_EthernetPortStatistics_ResetSelectedStats;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_EthernetPortStatistics_ResetSelectedStats_rtti;

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Construct(
    SCX_EthernetPortStatistics_ResetSelectedStats* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_EthernetPortStatistics_ResetSelectedStats_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Clone(
    const SCX_EthernetPortStatistics_ResetSelectedStats* self,
    SCX_EthernetPortStatistics_ResetSelectedStats** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Destruct(
    SCX_EthernetPortStatistics_ResetSelectedStats* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Delete(
    SCX_EthernetPortStatistics_ResetSelectedStats* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Post(
    const SCX_EthernetPortStatistics_ResetSelectedStats* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Set_MIReturn(
    SCX_EthernetPortStatistics_ResetSelectedStats* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Clear_MIReturn(
    SCX_EthernetPortStatistics_ResetSelectedStats* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Set_SelectedStatistics(
    SCX_EthernetPortStatistics_ResetSelectedStats* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_SetPtr_SelectedStatistics(
    SCX_EthernetPortStatistics_ResetSelectedStats* self,
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

MI_INLINE MI_Result MI_CALL SCX_EthernetPortStatistics_ResetSelectedStats_Clear_SelectedStatistics(
    SCX_EthernetPortStatistics_ResetSelectedStats* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

/*
**==============================================================================
**
** SCX_EthernetPortStatistics provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_EthernetPortStatistics_Self SCX_EthernetPortStatistics_Self;

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_Load(
    SCX_EthernetPortStatistics_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_Unload(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_EnumerateInstances(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_GetInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_CreateInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* newInstance);

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_ModifyInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_DeleteInstance(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_EthernetPortStatistics* instanceName);

MI_EXTERN_C void MI_CALL SCX_EthernetPortStatistics_Invoke_ResetSelectedStats(
    SCX_EthernetPortStatistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_EthernetPortStatistics* instanceName,
    const SCX_EthernetPortStatistics_ResetSelectedStats* in);


/*
**==============================================================================
**
** SCX_EthernetPortStatistics_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_EthernetPortStatistics_Class : public CIM_EthernetPortStatistics_Class
{
public:
    
    typedef SCX_EthernetPortStatistics Self;
    
    SCX_EthernetPortStatistics_Class() :
        CIM_EthernetPortStatistics_Class(&SCX_EthernetPortStatistics_rtti)
    {
    }
    
    SCX_EthernetPortStatistics_Class(
        const SCX_EthernetPortStatistics* instanceName,
        bool keysOnly) :
        CIM_EthernetPortStatistics_Class(
            &SCX_EthernetPortStatistics_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPortStatistics_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_EthernetPortStatistics_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPortStatistics_Class(
        const MI_ClassDecl* clDecl) :
        CIM_EthernetPortStatistics_Class(clDecl)
    {
    }
    
    SCX_EthernetPortStatistics_Class& operator=(
        const SCX_EthernetPortStatistics_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPortStatistics_Class(
        const SCX_EthernetPortStatistics_Class& x) :
        CIM_EthernetPortStatistics_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_EthernetPortStatistics_rtti;
    }

    //
    // SCX_EthernetPortStatistics_Class.BytesTotal
    //
    
    const Field<Uint64>& BytesTotal() const
    {
        const size_t n = offsetof(Self, BytesTotal);
        return GetField<Uint64>(n);
    }
    
    void BytesTotal(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BytesTotal);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BytesTotal_value() const
    {
        const size_t n = offsetof(Self, BytesTotal);
        return GetField<Uint64>(n).value;
    }
    
    void BytesTotal_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BytesTotal);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BytesTotal_exists() const
    {
        const size_t n = offsetof(Self, BytesTotal);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BytesTotal_clear()
    {
        const size_t n = offsetof(Self, BytesTotal);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_EthernetPortStatistics_Class.TotalRxErrors
    //
    
    const Field<Uint64>& TotalRxErrors() const
    {
        const size_t n = offsetof(Self, TotalRxErrors);
        return GetField<Uint64>(n);
    }
    
    void TotalRxErrors(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalRxErrors);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalRxErrors_value() const
    {
        const size_t n = offsetof(Self, TotalRxErrors);
        return GetField<Uint64>(n).value;
    }
    
    void TotalRxErrors_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalRxErrors);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalRxErrors_exists() const
    {
        const size_t n = offsetof(Self, TotalRxErrors);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalRxErrors_clear()
    {
        const size_t n = offsetof(Self, TotalRxErrors);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_EthernetPortStatistics_Class.TotalTxErrors
    //
    
    const Field<Uint64>& TotalTxErrors() const
    {
        const size_t n = offsetof(Self, TotalTxErrors);
        return GetField<Uint64>(n);
    }
    
    void TotalTxErrors(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalTxErrors);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalTxErrors_value() const
    {
        const size_t n = offsetof(Self, TotalTxErrors);
        return GetField<Uint64>(n).value;
    }
    
    void TotalTxErrors_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalTxErrors);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalTxErrors_exists() const
    {
        const size_t n = offsetof(Self, TotalTxErrors);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalTxErrors_clear()
    {
        const size_t n = offsetof(Self, TotalTxErrors);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_EthernetPortStatistics_Class.TotalCollisions
    //
    
    const Field<Uint64>& TotalCollisions() const
    {
        const size_t n = offsetof(Self, TotalCollisions);
        return GetField<Uint64>(n);
    }
    
    void TotalCollisions(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TotalCollisions);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TotalCollisions_value() const
    {
        const size_t n = offsetof(Self, TotalCollisions);
        return GetField<Uint64>(n).value;
    }
    
    void TotalCollisions_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TotalCollisions);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TotalCollisions_exists() const
    {
        const size_t n = offsetof(Self, TotalCollisions);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TotalCollisions_clear()
    {
        const size_t n = offsetof(Self, TotalCollisions);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<SCX_EthernetPortStatistics_Class> SCX_EthernetPortStatistics_ClassA;

class SCX_EthernetPortStatistics_ResetSelectedStats_Class : public Instance
{
public:
    
    typedef SCX_EthernetPortStatistics_ResetSelectedStats Self;
    
    SCX_EthernetPortStatistics_ResetSelectedStats_Class() :
        Instance(&SCX_EthernetPortStatistics_ResetSelectedStats_rtti)
    {
    }
    
    SCX_EthernetPortStatistics_ResetSelectedStats_Class(
        const SCX_EthernetPortStatistics_ResetSelectedStats* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_EthernetPortStatistics_ResetSelectedStats_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_EthernetPortStatistics_ResetSelectedStats_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_EthernetPortStatistics_ResetSelectedStats_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_EthernetPortStatistics_ResetSelectedStats_Class& operator=(
        const SCX_EthernetPortStatistics_ResetSelectedStats_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_EthernetPortStatistics_ResetSelectedStats_Class(
        const SCX_EthernetPortStatistics_ResetSelectedStats_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_EthernetPortStatistics_ResetSelectedStats_Class.MIReturn
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
    // SCX_EthernetPortStatistics_ResetSelectedStats_Class.SelectedStatistics
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

typedef Array<SCX_EthernetPortStatistics_ResetSelectedStats_Class> SCX_EthernetPortStatistics_ResetSelectedStats_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_EthernetPortStatistics_h */
