/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#include <ctype.h>
#include <MI.h>
#include "SCX_Agent.h"
#include "SCX_Application_Server.h"
#include "SCX_DiskDrive.h"
#include "SCX_DiskDriveStatisticalInformation.h"
#include "SCX_FileSystem.h"
#include "SCX_FileSystemStatisticalInformation.h"
#include "SCX_EthernetPortStatistics.h"
#include "SCX_LANEndpoint.h"
#include "SCX_IPProtocolEndpoint.h"
#include "SCX_LogFile.h"
#include "SCX_MemoryStatisticalInformation.h"
#include "SCX_OperatingSystem.h"
#include "SCX_ProcessorStatisticalInformation.h"
#include "SCX_UnixProcess.h"
#include "SCX_UnixProcessStatisticalInformation.h"

/*
**==============================================================================
**
** Schema Declaration
**
**==============================================================================
*/

extern MI_SchemaDecl schemaDecl;

/*
**==============================================================================
**
** Qualifier declarations
**
**==============================================================================
*/

/*
**==============================================================================
**
** CIM_ManagedElement
**
**==============================================================================
*/

/* property CIM_ManagedElement.InstanceID */
static MI_CONST MI_PropertyDecl CIM_ManagedElement_InstanceID_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069640A, /* code */
    MI_T("InstanceID"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedElement, InstanceID), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_ManagedElement"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ManagedElement_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier CIM_ManagedElement_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ManagedElement_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ManagedElement_Caption_quals[] =
{
    &CIM_ManagedElement_Caption_MaxLen_qual,
};

/* property CIM_ManagedElement.Caption */
static MI_CONST MI_PropertyDecl CIM_ManagedElement_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    CIM_ManagedElement_Caption_quals, /* qualifiers */
    MI_COUNT(CIM_ManagedElement_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedElement, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_ManagedElement"), /* propagator */
    NULL,
};

/* property CIM_ManagedElement.Description */
static MI_CONST MI_PropertyDecl CIM_ManagedElement_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedElement, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_ManagedElement"), /* propagator */
    NULL,
};

/* property CIM_ManagedElement.ElementName */
static MI_CONST MI_PropertyDecl CIM_ManagedElement_ElementName_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065650B, /* code */
    MI_T("ElementName"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedElement, ElementName), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_ManagedElement"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_ManagedElement_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
};

static MI_CONST MI_Char* CIM_ManagedElement_Version_qual_value = MI_T("2.19.0");

static MI_CONST MI_Qualifier CIM_ManagedElement_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_ManagedElement_Version_qual_value
};

static MI_CONST MI_Char* CIM_ManagedElement_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier CIM_ManagedElement_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_ManagedElement_UMLPackagePath_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ManagedElement_quals[] =
{
    &CIM_ManagedElement_Version_qual,
    &CIM_ManagedElement_UMLPackagePath_qual,
};

/* class CIM_ManagedElement */
MI_CONST MI_ClassDecl CIM_ManagedElement_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00637412, /* code */
    MI_T("CIM_ManagedElement"), /* name */
    CIM_ManagedElement_quals, /* qualifiers */
    MI_COUNT(CIM_ManagedElement_quals), /* numQualifiers */
    CIM_ManagedElement_props, /* properties */
    MI_COUNT(CIM_ManagedElement_props), /* numProperties */
    sizeof(CIM_ManagedElement), /* size */
    NULL, /* superClass */
    NULL, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_ManagedSystemElement
**
**==============================================================================
*/

/* property CIM_ManagedSystemElement.InstallDate */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_InstallDate_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069650B, /* code */
    MI_T("InstallDate"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, InstallDate), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ManagedSystemElement_Name_MaxLen_qual_value = 1024U;

static MI_CONST MI_Qualifier CIM_ManagedSystemElement_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ManagedSystemElement_Name_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ManagedSystemElement_Name_quals[] =
{
    &CIM_ManagedSystemElement_Name_MaxLen_qual,
};

/* property CIM_ManagedSystemElement.Name */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_Name_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_ManagedSystemElement_Name_quals, /* qualifiers */
    MI_COUNT(CIM_ManagedSystemElement_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_ManagedSystemElement_OperationalStatus_ArrayType_qual_value = MI_T("Indexed");

static MI_CONST MI_Qualifier CIM_ManagedSystemElement_OperationalStatus_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_ManagedSystemElement_OperationalStatus_ArrayType_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ManagedSystemElement_OperationalStatus_quals[] =
{
    &CIM_ManagedSystemElement_OperationalStatus_ArrayType_qual,
};

/* property CIM_ManagedSystemElement.OperationalStatus */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_OperationalStatus_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F7311, /* code */
    MI_T("OperationalStatus"), /* name */
    CIM_ManagedSystemElement_OperationalStatus_quals, /* qualifiers */
    MI_COUNT(CIM_ManagedSystemElement_OperationalStatus_quals), /* numQualifiers */
    MI_UINT16A, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, OperationalStatus), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_ManagedSystemElement_StatusDescriptions_ArrayType_qual_value = MI_T("Indexed");

static MI_CONST MI_Qualifier CIM_ManagedSystemElement_StatusDescriptions_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_ManagedSystemElement_StatusDescriptions_ArrayType_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ManagedSystemElement_StatusDescriptions_quals[] =
{
    &CIM_ManagedSystemElement_StatusDescriptions_ArrayType_qual,
};

/* property CIM_ManagedSystemElement.StatusDescriptions */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_StatusDescriptions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00737312, /* code */
    MI_T("StatusDescriptions"), /* name */
    CIM_ManagedSystemElement_StatusDescriptions_quals, /* qualifiers */
    MI_COUNT(CIM_ManagedSystemElement_StatusDescriptions_quals), /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, StatusDescriptions), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_ManagedSystemElement_Status_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ManagedSystemElement.OperationalStatus"),
};

static MI_CONST MI_ConstStringA CIM_ManagedSystemElement_Status_Deprecated_qual_value =
{
    CIM_ManagedSystemElement_Status_Deprecated_qual_data_value,
    MI_COUNT(CIM_ManagedSystemElement_Status_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_ManagedSystemElement_Status_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ManagedSystemElement_Status_Deprecated_qual_value
};

static MI_CONST MI_Uint32 CIM_ManagedSystemElement_Status_MaxLen_qual_value = 10U;

static MI_CONST MI_Qualifier CIM_ManagedSystemElement_Status_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ManagedSystemElement_Status_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ManagedSystemElement_Status_quals[] =
{
    &CIM_ManagedSystemElement_Status_Deprecated_qual,
    &CIM_ManagedSystemElement_Status_MaxLen_qual,
};

/* property CIM_ManagedSystemElement.Status */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_Status_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00737306, /* code */
    MI_T("Status"), /* name */
    CIM_ManagedSystemElement_Status_quals, /* qualifiers */
    MI_COUNT(CIM_ManagedSystemElement_Status_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, Status), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

/* property CIM_ManagedSystemElement.HealthState */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_HealthState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0068650B, /* code */
    MI_T("HealthState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, HealthState), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

/* property CIM_ManagedSystemElement.CommunicationStatus */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_CommunicationStatus_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00637313, /* code */
    MI_T("CommunicationStatus"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, CommunicationStatus), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

/* property CIM_ManagedSystemElement.DetailedStatus */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_DetailedStatus_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0064730E, /* code */
    MI_T("DetailedStatus"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, DetailedStatus), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

/* property CIM_ManagedSystemElement.OperatingStatus */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_OperatingStatus_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F730F, /* code */
    MI_T("OperatingStatus"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, OperatingStatus), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

/* property CIM_ManagedSystemElement.PrimaryStatus */
static MI_CONST MI_PropertyDecl CIM_ManagedSystemElement_PrimaryStatus_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070730D, /* code */
    MI_T("PrimaryStatus"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ManagedSystemElement, PrimaryStatus), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ManagedSystemElement"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_ManagedSystemElement_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ManagedSystemElement_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
};

static MI_CONST MI_Char* CIM_ManagedSystemElement_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier CIM_ManagedSystemElement_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_ManagedSystemElement_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_ManagedSystemElement_Version_qual_value = MI_T("2.28.0");

static MI_CONST MI_Qualifier CIM_ManagedSystemElement_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_ManagedSystemElement_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ManagedSystemElement_quals[] =
{
    &CIM_ManagedSystemElement_UMLPackagePath_qual,
    &CIM_ManagedSystemElement_Version_qual,
};

/* class CIM_ManagedSystemElement */
MI_CONST MI_ClassDecl CIM_ManagedSystemElement_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00637418, /* code */
    MI_T("CIM_ManagedSystemElement"), /* name */
    CIM_ManagedSystemElement_quals, /* qualifiers */
    MI_COUNT(CIM_ManagedSystemElement_quals), /* numQualifiers */
    CIM_ManagedSystemElement_props, /* properties */
    MI_COUNT(CIM_ManagedSystemElement_props), /* numProperties */
    sizeof(CIM_ManagedSystemElement), /* size */
    MI_T("CIM_ManagedElement"), /* superClass */
    &CIM_ManagedElement_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_LogicalElement
**
**==============================================================================
*/

static MI_PropertyDecl MI_CONST* MI_CONST CIM_LogicalElement_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ManagedSystemElement_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
};

static MI_CONST MI_Char* CIM_LogicalElement_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier CIM_LogicalElement_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_LogicalElement_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_LogicalElement_Version_qual_value = MI_T("2.6.0");

static MI_CONST MI_Qualifier CIM_LogicalElement_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_LogicalElement_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalElement_quals[] =
{
    &CIM_LogicalElement_UMLPackagePath_qual,
    &CIM_LogicalElement_Version_qual,
};

/* class CIM_LogicalElement */
MI_CONST MI_ClassDecl CIM_LogicalElement_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00637412, /* code */
    MI_T("CIM_LogicalElement"), /* name */
    CIM_LogicalElement_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalElement_quals), /* numQualifiers */
    CIM_LogicalElement_props, /* properties */
    MI_COUNT(CIM_LogicalElement_props), /* numProperties */
    sizeof(CIM_LogicalElement), /* size */
    MI_T("CIM_ManagedSystemElement"), /* superClass */
    &CIM_ManagedSystemElement_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_Agent
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_Agent_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_Agent_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_Agent_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_Agent_Caption_quals[] =
{
    &SCX_Agent_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_Agent_Caption_value = MI_T("SCX Agent meta-information");

/* property SCX_Agent.Caption */
static MI_CONST MI_PropertyDecl SCX_Agent_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_Agent_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_Agent_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    &SCX_Agent_Caption_value,
};

static MI_CONST MI_Char* SCX_Agent_Description_value = MI_T("Information about the currenly installed version of SCX and the system it runs on");

/* property SCX_Agent.Description */
static MI_CONST MI_PropertyDecl SCX_Agent_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    &SCX_Agent_Description_value,
};

static MI_CONST MI_Uint32 SCX_Agent_Name_MaxLen_qual_value = 1024U;

static MI_CONST MI_Qualifier SCX_Agent_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_Agent_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* SCX_Agent_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier SCX_Agent_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_Agent_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_Agent_Name_quals[] =
{
    &SCX_Agent_Name_MaxLen_qual,
    &SCX_Agent_Name_Override_qual,
};

/* property SCX_Agent.Name */
static MI_CONST MI_PropertyDecl SCX_Agent_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    SCX_Agent_Name_quals, /* qualifiers */
    MI_COUNT(SCX_Agent_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.VersionString */
static MI_CONST MI_PropertyDecl SCX_Agent_VersionString_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0076670D, /* code */
    MI_T("VersionString"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, VersionString), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.MajorVersion */
static MI_CONST MI_PropertyDecl SCX_Agent_MajorVersion_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6E0C, /* code */
    MI_T("MajorVersion"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, MajorVersion), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.MinorVersion */
static MI_CONST MI_PropertyDecl SCX_Agent_MinorVersion_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6E0C, /* code */
    MI_T("MinorVersion"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, MinorVersion), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.RevisionNumber */
static MI_CONST MI_PropertyDecl SCX_Agent_RevisionNumber_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0072720E, /* code */
    MI_T("RevisionNumber"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, RevisionNumber), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.BuildNumber */
static MI_CONST MI_PropertyDecl SCX_Agent_BuildNumber_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0062720B, /* code */
    MI_T("BuildNumber"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, BuildNumber), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.BuildDate */
static MI_CONST MI_PropertyDecl SCX_Agent_BuildDate_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00626509, /* code */
    MI_T("BuildDate"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, BuildDate), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.Architecture */
static MI_CONST MI_PropertyDecl SCX_Agent_Architecture_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061650C, /* code */
    MI_T("Architecture"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, Architecture), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.OSName */
static MI_CONST MI_PropertyDecl SCX_Agent_OSName_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6506, /* code */
    MI_T("OSName"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, OSName), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.OSType */
static MI_CONST MI_PropertyDecl SCX_Agent_OSType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6506, /* code */
    MI_T("OSType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, OSType), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.OSVersion */
static MI_CONST MI_PropertyDecl SCX_Agent_OSVersion_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6E09, /* code */
    MI_T("OSVersion"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, OSVersion), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.KitVersionString */
static MI_CONST MI_PropertyDecl SCX_Agent_KitVersionString_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006B6710, /* code */
    MI_T("KitVersionString"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, KitVersionString), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.Hostname */
static MI_CONST MI_PropertyDecl SCX_Agent_Hostname_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00686508, /* code */
    MI_T("Hostname"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, Hostname), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.OSAlias */
static MI_CONST MI_PropertyDecl SCX_Agent_OSAlias_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F7307, /* code */
    MI_T("OSAlias"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, OSAlias), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.UnameArchitecture */
static MI_CONST MI_PropertyDecl SCX_Agent_UnameArchitecture_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00756511, /* code */
    MI_T("UnameArchitecture"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, UnameArchitecture), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.MinActiveLogSeverityThreshold */
static MI_CONST MI_PropertyDecl SCX_Agent_MinActiveLogSeverityThreshold_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D641D, /* code */
    MI_T("MinActiveLogSeverityThreshold"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, MinActiveLogSeverityThreshold), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.MachineType */
static MI_CONST MI_PropertyDecl SCX_Agent_MachineType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D650B, /* code */
    MI_T("MachineType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, MachineType), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.PhysicalProcessors */
static MI_CONST MI_PropertyDecl SCX_Agent_PhysicalProcessors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707312, /* code */
    MI_T("PhysicalProcessors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, PhysicalProcessors), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

/* property SCX_Agent.LogicalProcessors */
static MI_CONST MI_PropertyDecl SCX_Agent_LogicalProcessors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C7311, /* code */
    MI_T("LogicalProcessors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Agent, LogicalProcessors), /* offset */
    MI_T("SCX_Agent"), /* origin */
    MI_T("SCX_Agent"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_Agent_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_Agent_Caption_prop,
    &SCX_Agent_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &SCX_Agent_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &SCX_Agent_VersionString_prop,
    &SCX_Agent_MajorVersion_prop,
    &SCX_Agent_MinorVersion_prop,
    &SCX_Agent_RevisionNumber_prop,
    &SCX_Agent_BuildNumber_prop,
    &SCX_Agent_BuildDate_prop,
    &SCX_Agent_Architecture_prop,
    &SCX_Agent_OSName_prop,
    &SCX_Agent_OSType_prop,
    &SCX_Agent_OSVersion_prop,
    &SCX_Agent_KitVersionString_prop,
    &SCX_Agent_Hostname_prop,
    &SCX_Agent_OSAlias_prop,
    &SCX_Agent_UnameArchitecture_prop,
    &SCX_Agent_MinActiveLogSeverityThreshold_prop,
    &SCX_Agent_MachineType_prop,
    &SCX_Agent_PhysicalProcessors_prop,
    &SCX_Agent_LogicalProcessors_prop,
};

static MI_CONST MI_ProviderFT SCX_Agent_funcs =
{
  (MI_ProviderFT_Load)SCX_Agent_Load,
  (MI_ProviderFT_Unload)SCX_Agent_Unload,
  (MI_ProviderFT_GetInstance)SCX_Agent_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_Agent_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_Agent_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_Agent_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_Agent_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_Agent_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier SCX_Agent_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_Agent_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_Agent_Version_qual_value = MI_T("1.4.7");

static MI_CONST MI_Qualifier SCX_Agent_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_Agent_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_Agent_quals[] =
{
    &SCX_Agent_UMLPackagePath_qual,
    &SCX_Agent_Version_qual,
};

/* class SCX_Agent */
MI_CONST MI_ClassDecl SCX_Agent_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00737409, /* code */
    MI_T("SCX_Agent"), /* name */
    SCX_Agent_quals, /* qualifiers */
    MI_COUNT(SCX_Agent_quals), /* numQualifiers */
    SCX_Agent_props, /* properties */
    MI_COUNT(SCX_Agent_props), /* numProperties */
    sizeof(SCX_Agent), /* size */
    MI_T("CIM_LogicalElement"), /* superClass */
    &CIM_LogicalElement_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &SCX_Agent_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_Application_Server
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_Application_Server_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_Application_Server_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_Application_Server_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_Application_Server_Caption_quals[] =
{
    &SCX_Application_Server_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_Application_Server_Caption_value = MI_T("SCX Application Server");

/* property SCX_Application_Server.Caption */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_Application_Server_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_Application_Server_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    &SCX_Application_Server_Caption_value,
};

static MI_CONST MI_Char* SCX_Application_Server_Description_value = MI_T("Represents a JEE Application Server");

/* property SCX_Application_Server.Description */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    &SCX_Application_Server_Description_value,
};

static MI_CONST MI_Uint32 SCX_Application_Server_Name_MaxLen_qual_value = 1024U;

static MI_CONST MI_Qualifier SCX_Application_Server_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_Application_Server_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* SCX_Application_Server_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier SCX_Application_Server_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_Application_Server_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_Application_Server_Name_quals[] =
{
    &SCX_Application_Server_Name_MaxLen_qual,
    &SCX_Application_Server_Name_Override_qual,
};

/* property SCX_Application_Server.Name */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    SCX_Application_Server_Name_quals, /* qualifiers */
    MI_COUNT(SCX_Application_Server_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.HttpPort */
static MI_CONST MI_PropertyDecl SCX_Application_Server_HttpPort_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00687408, /* code */
    MI_T("HttpPort"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, HttpPort), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.HttpsPort */
static MI_CONST MI_PropertyDecl SCX_Application_Server_HttpsPort_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00687409, /* code */
    MI_T("HttpsPort"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, HttpsPort), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Port */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Port_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707404, /* code */
    MI_T("Port"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Port), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Protocol */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Protocol_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706C08, /* code */
    MI_T("Protocol"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Protocol), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Version */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Version_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00766E07, /* code */
    MI_T("Version"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Version), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.MajorVersion */
static MI_CONST MI_PropertyDecl SCX_Application_Server_MajorVersion_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6E0C, /* code */
    MI_T("MajorVersion"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, MajorVersion), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.DiskPath */
static MI_CONST MI_PropertyDecl SCX_Application_Server_DiskPath_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646808, /* code */
    MI_T("DiskPath"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, DiskPath), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Type */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Type_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746504, /* code */
    MI_T("Type"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Type), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Profile */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Profile_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706507, /* code */
    MI_T("Profile"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Profile), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Cell */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Cell_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636C04, /* code */
    MI_T("Cell"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Cell), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Node */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Node_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E6504, /* code */
    MI_T("Node"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Node), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.Server */
static MI_CONST MI_PropertyDecl SCX_Application_Server_Server_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00737206, /* code */
    MI_T("Server"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, Server), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.IsDeepMonitored */
static MI_CONST MI_PropertyDecl SCX_Application_Server_IsDeepMonitored_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069640F, /* code */
    MI_T("IsDeepMonitored"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, IsDeepMonitored), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

/* property SCX_Application_Server.IsRunning */
static MI_CONST MI_PropertyDecl SCX_Application_Server_IsRunning_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00696709, /* code */
    MI_T("IsRunning"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server, IsRunning), /* offset */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_Application_Server_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_Application_Server_Caption_prop,
    &SCX_Application_Server_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &SCX_Application_Server_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &SCX_Application_Server_HttpPort_prop,
    &SCX_Application_Server_HttpsPort_prop,
    &SCX_Application_Server_Port_prop,
    &SCX_Application_Server_Protocol_prop,
    &SCX_Application_Server_Version_prop,
    &SCX_Application_Server_MajorVersion_prop,
    &SCX_Application_Server_DiskPath_prop,
    &SCX_Application_Server_Type_prop,
    &SCX_Application_Server_Profile_prop,
    &SCX_Application_Server_Cell_prop,
    &SCX_Application_Server_Node_prop,
    &SCX_Application_Server_Server_prop,
    &SCX_Application_Server_IsDeepMonitored_prop,
    &SCX_Application_Server_IsRunning_prop,
};

/* parameter SCX_Application_Server.SetDeepMonitoring(): id */
static MI_CONST MI_ParameterDecl SCX_Application_Server_SetDeepMonitoring_id_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00696402, /* code */
    MI_T("id"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server_SetDeepMonitoring, id), /* offset */
};

/* parameter SCX_Application_Server.SetDeepMonitoring(): deep */
static MI_CONST MI_ParameterDecl SCX_Application_Server_SetDeepMonitoring_deep_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00647004, /* code */
    MI_T("deep"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server_SetDeepMonitoring, deep), /* offset */
};

/* parameter SCX_Application_Server.SetDeepMonitoring(): protocol */
static MI_CONST MI_ParameterDecl SCX_Application_Server_SetDeepMonitoring_protocol_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00706C08, /* code */
    MI_T("protocol"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server_SetDeepMonitoring, protocol), /* offset */
};

/* parameter SCX_Application_Server.SetDeepMonitoring(): elevationType */
static MI_CONST MI_ParameterDecl SCX_Application_Server_SetDeepMonitoring_elevationType_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0065650D, /* code */
    MI_T("elevationType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server_SetDeepMonitoring, elevationType), /* offset */
};

/* parameter SCX_Application_Server.SetDeepMonitoring(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_Application_Server_SetDeepMonitoring_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_Application_Server_SetDeepMonitoring, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_Application_Server_SetDeepMonitoring_params[] =
{
    &SCX_Application_Server_SetDeepMonitoring_MIReturn_param,
    &SCX_Application_Server_SetDeepMonitoring_id_param,
    &SCX_Application_Server_SetDeepMonitoring_deep_param,
    &SCX_Application_Server_SetDeepMonitoring_protocol_param,
    &SCX_Application_Server_SetDeepMonitoring_elevationType_param,
};

/* method SCX_Application_Server.SetDeepMonitoring() */
MI_CONST MI_MethodDecl SCX_Application_Server_SetDeepMonitoring_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x00736711, /* code */
    MI_T("SetDeepMonitoring"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_Application_Server_SetDeepMonitoring_params, /* parameters */
    MI_COUNT(SCX_Application_Server_SetDeepMonitoring_params), /* numParameters */
    sizeof(SCX_Application_Server_SetDeepMonitoring), /* size */
    MI_BOOLEAN, /* returnType */
    MI_T("SCX_Application_Server"), /* origin */
    MI_T("SCX_Application_Server"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_Application_Server_Invoke_SetDeepMonitoring, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_Application_Server_meths[] =
{
    &SCX_Application_Server_SetDeepMonitoring_rtti,
};

static MI_CONST MI_ProviderFT SCX_Application_Server_funcs =
{
  (MI_ProviderFT_Load)SCX_Application_Server_Load,
  (MI_ProviderFT_Unload)SCX_Application_Server_Unload,
  (MI_ProviderFT_GetInstance)SCX_Application_Server_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_Application_Server_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_Application_Server_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_Application_Server_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_Application_Server_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_Application_Server_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier SCX_Application_Server_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_Application_Server_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_Application_Server_Version_qual_value = MI_T("1.3.0");

static MI_CONST MI_Qualifier SCX_Application_Server_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_Application_Server_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_Application_Server_quals[] =
{
    &SCX_Application_Server_UMLPackagePath_qual,
    &SCX_Application_Server_Version_qual,
};

/* class SCX_Application_Server */
MI_CONST MI_ClassDecl SCX_Application_Server_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00737216, /* code */
    MI_T("SCX_Application_Server"), /* name */
    SCX_Application_Server_quals, /* qualifiers */
    MI_COUNT(SCX_Application_Server_quals), /* numQualifiers */
    SCX_Application_Server_props, /* properties */
    MI_COUNT(SCX_Application_Server_props), /* numProperties */
    sizeof(SCX_Application_Server), /* size */
    MI_T("CIM_LogicalElement"), /* superClass */
    &CIM_LogicalElement_rtti, /* superClassDecl */
    SCX_Application_Server_meths, /* methods */
    MI_COUNT(SCX_Application_Server_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_Application_Server_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_Job
**
**==============================================================================
*/

/* property CIM_Job.JobStatus */
static MI_CONST MI_PropertyDecl CIM_Job_JobStatus_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006A7309, /* code */
    MI_T("JobStatus"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, JobStatus), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.TimeSubmitted */
static MI_CONST MI_PropertyDecl CIM_Job_TimeSubmitted_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074640D, /* code */
    MI_T("TimeSubmitted"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, TimeSubmitted), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_Job_ScheduledStartTime_Deprecated_qual_data_value[] =
{
    MI_T("CIM_Job.RunMonth"),
    MI_T("CIM_Job.RunDay"),
    MI_T("CIM_Job.RunDayOfWeek"),
    MI_T("CIM_Job.RunStartInterval"),
};

static MI_CONST MI_ConstStringA CIM_Job_ScheduledStartTime_Deprecated_qual_value =
{
    CIM_Job_ScheduledStartTime_Deprecated_qual_data_value,
    MI_COUNT(CIM_Job_ScheduledStartTime_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_Job_ScheduledStartTime_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_Job_ScheduledStartTime_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Job_ScheduledStartTime_quals[] =
{
    &CIM_Job_ScheduledStartTime_Deprecated_qual,
};

/* property CIM_Job.ScheduledStartTime */
static MI_CONST MI_PropertyDecl CIM_Job_ScheduledStartTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736512, /* code */
    MI_T("ScheduledStartTime"), /* name */
    CIM_Job_ScheduledStartTime_quals, /* qualifiers */
    MI_COUNT(CIM_Job_ScheduledStartTime_quals), /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, ScheduledStartTime), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.StartTime */
static MI_CONST MI_PropertyDecl CIM_Job_StartTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736509, /* code */
    MI_T("StartTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, StartTime), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.ElapsedTime */
static MI_CONST MI_PropertyDecl CIM_Job_ElapsedTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065650B, /* code */
    MI_T("ElapsedTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, ElapsedTime), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_Job_JobRunTimes_value = 1U;

/* property CIM_Job.JobRunTimes */
static MI_CONST MI_PropertyDecl CIM_Job_JobRunTimes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006A730B, /* code */
    MI_T("JobRunTimes"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, JobRunTimes), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    &CIM_Job_JobRunTimes_value,
};

/* property CIM_Job.RunMonth */
static MI_CONST MI_PropertyDecl CIM_Job_RunMonth_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726808, /* code */
    MI_T("RunMonth"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, RunMonth), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

static MI_CONST MI_Sint64 CIM_Job_RunDay_MinValue_qual_value = -MI_LL(31);

static MI_CONST MI_Qualifier CIM_Job_RunDay_MinValue_qual =
{
    MI_T("MinValue"),
    MI_SINT64,
    0,
    &CIM_Job_RunDay_MinValue_qual_value
};

static MI_CONST MI_Sint64 CIM_Job_RunDay_MaxValue_qual_value = MI_LL(31);

static MI_CONST MI_Qualifier CIM_Job_RunDay_MaxValue_qual =
{
    MI_T("MaxValue"),
    MI_SINT64,
    0,
    &CIM_Job_RunDay_MaxValue_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Job_RunDay_quals[] =
{
    &CIM_Job_RunDay_MinValue_qual,
    &CIM_Job_RunDay_MaxValue_qual,
};

/* property CIM_Job.RunDay */
static MI_CONST MI_PropertyDecl CIM_Job_RunDay_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00727906, /* code */
    MI_T("RunDay"), /* name */
    CIM_Job_RunDay_quals, /* qualifiers */
    MI_COUNT(CIM_Job_RunDay_quals), /* numQualifiers */
    MI_SINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, RunDay), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.RunDayOfWeek */
static MI_CONST MI_PropertyDecl CIM_Job_RunDayOfWeek_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726B0C, /* code */
    MI_T("RunDayOfWeek"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_SINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, RunDayOfWeek), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.RunStartInterval */
static MI_CONST MI_PropertyDecl CIM_Job_RunStartInterval_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726C10, /* code */
    MI_T("RunStartInterval"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, RunStartInterval), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.LocalOrUtcTime */
static MI_CONST MI_PropertyDecl CIM_Job_LocalOrUtcTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C650E, /* code */
    MI_T("LocalOrUtcTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, LocalOrUtcTime), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.UntilTime */
static MI_CONST MI_PropertyDecl CIM_Job_UntilTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00756509, /* code */
    MI_T("UntilTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, UntilTime), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.Notify */
static MI_CONST MI_PropertyDecl CIM_Job_Notify_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E7906, /* code */
    MI_T("Notify"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, Notify), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.Owner */
static MI_CONST MI_PropertyDecl CIM_Job_Owner_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F7205, /* code */
    MI_T("Owner"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, Owner), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.Priority */
static MI_CONST MI_PropertyDecl CIM_Job_Priority_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707908, /* code */
    MI_T("Priority"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, Priority), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_Job_PercentComplete_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier CIM_Job_PercentComplete_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_Job_PercentComplete_Units_qual_value
};

static MI_CONST MI_Sint64 CIM_Job_PercentComplete_MinValue_qual_value = MI_LL(0);

static MI_CONST MI_Qualifier CIM_Job_PercentComplete_MinValue_qual =
{
    MI_T("MinValue"),
    MI_SINT64,
    0,
    &CIM_Job_PercentComplete_MinValue_qual_value
};

static MI_CONST MI_Sint64 CIM_Job_PercentComplete_MaxValue_qual_value = MI_LL(101);

static MI_CONST MI_Qualifier CIM_Job_PercentComplete_MaxValue_qual =
{
    MI_T("MaxValue"),
    MI_SINT64,
    0,
    &CIM_Job_PercentComplete_MaxValue_qual_value
};

static MI_CONST MI_Char* CIM_Job_PercentComplete_PUnit_qual_value = MI_T("percent");

static MI_CONST MI_Qualifier CIM_Job_PercentComplete_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_Job_PercentComplete_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Job_PercentComplete_quals[] =
{
    &CIM_Job_PercentComplete_Units_qual,
    &CIM_Job_PercentComplete_MinValue_qual,
    &CIM_Job_PercentComplete_MaxValue_qual,
    &CIM_Job_PercentComplete_PUnit_qual,
};

/* property CIM_Job.PercentComplete */
static MI_CONST MI_PropertyDecl CIM_Job_PercentComplete_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentComplete"), /* name */
    CIM_Job_PercentComplete_quals, /* qualifiers */
    MI_COUNT(CIM_Job_PercentComplete_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, PercentComplete), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.DeleteOnCompletion */
static MI_CONST MI_PropertyDecl CIM_Job_DeleteOnCompletion_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E12, /* code */
    MI_T("DeleteOnCompletion"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, DeleteOnCompletion), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.ErrorCode */
static MI_CONST MI_PropertyDecl CIM_Job_ErrorCode_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00656509, /* code */
    MI_T("ErrorCode"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, ErrorCode), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.ErrorDescription */
static MI_CONST MI_PropertyDecl CIM_Job_ErrorDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00656E10, /* code */
    MI_T("ErrorDescription"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, ErrorDescription), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.RecoveryAction */
static MI_CONST MI_PropertyDecl CIM_Job_RecoveryAction_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726E0E, /* code */
    MI_T("RecoveryAction"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, RecoveryAction), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

/* property CIM_Job.OtherRecoveryAction */
static MI_CONST MI_PropertyDecl CIM_Job_OtherRecoveryAction_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6E13, /* code */
    MI_T("OtherRecoveryAction"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job, OtherRecoveryAction), /* offset */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_Job_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ManagedSystemElement_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_Job_JobStatus_prop,
    &CIM_Job_TimeSubmitted_prop,
    &CIM_Job_ScheduledStartTime_prop,
    &CIM_Job_StartTime_prop,
    &CIM_Job_ElapsedTime_prop,
    &CIM_Job_JobRunTimes_prop,
    &CIM_Job_RunMonth_prop,
    &CIM_Job_RunDay_prop,
    &CIM_Job_RunDayOfWeek_prop,
    &CIM_Job_RunStartInterval_prop,
    &CIM_Job_LocalOrUtcTime_prop,
    &CIM_Job_UntilTime_prop,
    &CIM_Job_Notify_prop,
    &CIM_Job_Owner_prop,
    &CIM_Job_Priority_prop,
    &CIM_Job_PercentComplete_prop,
    &CIM_Job_DeleteOnCompletion_prop,
    &CIM_Job_ErrorCode_prop,
    &CIM_Job_ErrorDescription_prop,
    &CIM_Job_RecoveryAction_prop,
    &CIM_Job_OtherRecoveryAction_prop,
};

static MI_CONST MI_Char* CIM_Job_KillJob_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ConcreteJob.RequestStateChange()"),
};

static MI_CONST MI_ConstStringA CIM_Job_KillJob_Deprecated_qual_value =
{
    CIM_Job_KillJob_Deprecated_qual_data_value,
    MI_COUNT(CIM_Job_KillJob_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_Job_KillJob_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_Job_KillJob_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Job_KillJob_quals[] =
{
    &CIM_Job_KillJob_Deprecated_qual,
};

/* parameter CIM_Job.KillJob(): DeleteOnKill */
static MI_CONST MI_ParameterDecl CIM_Job_KillJob_DeleteOnKill_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00646C0C, /* code */
    MI_T("DeleteOnKill"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job_KillJob, DeleteOnKill), /* offset */
};

static MI_CONST MI_Char* CIM_Job_KillJob_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ConcreteJob.RequestStateChange()"),
};

static MI_CONST MI_ConstStringA CIM_Job_KillJob_MIReturn_Deprecated_qual_value =
{
    CIM_Job_KillJob_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(CIM_Job_KillJob_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_Job_KillJob_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_Job_KillJob_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Job_KillJob_MIReturn_quals[] =
{
    &CIM_Job_KillJob_MIReturn_Deprecated_qual,
};

/* parameter CIM_Job.KillJob(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_Job_KillJob_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    CIM_Job_KillJob_MIReturn_quals, /* qualifiers */
    MI_COUNT(CIM_Job_KillJob_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Job_KillJob, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_Job_KillJob_params[] =
{
    &CIM_Job_KillJob_MIReturn_param,
    &CIM_Job_KillJob_DeleteOnKill_param,
};

/* method CIM_Job.KillJob() */
MI_CONST MI_MethodDecl CIM_Job_KillJob_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x006B6207, /* code */
    MI_T("KillJob"), /* name */
    CIM_Job_KillJob_quals, /* qualifiers */
    MI_COUNT(CIM_Job_KillJob_quals), /* numQualifiers */
    CIM_Job_KillJob_params, /* parameters */
    MI_COUNT(CIM_Job_KillJob_params), /* numParameters */
    sizeof(CIM_Job_KillJob), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_Job"), /* origin */
    MI_T("CIM_Job"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_Job_meths[] =
{
    &CIM_Job_KillJob_rtti,
};

static MI_CONST MI_Char* CIM_Job_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier CIM_Job_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_Job_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_Job_Version_qual_value = MI_T("2.10.0");

static MI_CONST MI_Qualifier CIM_Job_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_Job_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Job_quals[] =
{
    &CIM_Job_UMLPackagePath_qual,
    &CIM_Job_Version_qual,
};

/* class CIM_Job */
MI_CONST MI_ClassDecl CIM_Job_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00636207, /* code */
    MI_T("CIM_Job"), /* name */
    CIM_Job_quals, /* qualifiers */
    MI_COUNT(CIM_Job_quals), /* numQualifiers */
    CIM_Job_props, /* properties */
    MI_COUNT(CIM_Job_props), /* numProperties */
    sizeof(CIM_Job), /* size */
    MI_T("CIM_LogicalElement"), /* superClass */
    &CIM_LogicalElement_rtti, /* superClassDecl */
    CIM_Job_meths, /* methods */
    MI_COUNT(CIM_Job_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_Error
**
**==============================================================================
*/

/* property CIM_Error.ErrorType */
static MI_CONST MI_PropertyDecl CIM_Error_ErrorType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00656509, /* code */
    MI_T("ErrorType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, ErrorType), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.OtherErrorType */
static MI_CONST MI_PropertyDecl CIM_Error_OtherErrorType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F650E, /* code */
    MI_T("OtherErrorType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, OtherErrorType), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.OwningEntity */
static MI_CONST MI_PropertyDecl CIM_Error_OwningEntity_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F790C, /* code */
    MI_T("OwningEntity"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, OwningEntity), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.MessageID */
static MI_CONST MI_PropertyDecl CIM_Error_MessageID_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_REQUIRED, /* flags */
    0x006D6409, /* code */
    MI_T("MessageID"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, MessageID), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.Message */
static MI_CONST MI_PropertyDecl CIM_Error_Message_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6507, /* code */
    MI_T("Message"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, Message), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.MessageArguments */
static MI_CONST MI_PropertyDecl CIM_Error_MessageArguments_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D7310, /* code */
    MI_T("MessageArguments"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, MessageArguments), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.PerceivedSeverity */
static MI_CONST MI_PropertyDecl CIM_Error_PerceivedSeverity_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707911, /* code */
    MI_T("PerceivedSeverity"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, PerceivedSeverity), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.ProbableCause */
static MI_CONST MI_PropertyDecl CIM_Error_ProbableCause_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650D, /* code */
    MI_T("ProbableCause"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, ProbableCause), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.ProbableCauseDescription */
static MI_CONST MI_PropertyDecl CIM_Error_ProbableCauseDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706E18, /* code */
    MI_T("ProbableCauseDescription"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, ProbableCauseDescription), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.RecommendedActions */
static MI_CONST MI_PropertyDecl CIM_Error_RecommendedActions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00727312, /* code */
    MI_T("RecommendedActions"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, RecommendedActions), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.ErrorSource */
static MI_CONST MI_PropertyDecl CIM_Error_ErrorSource_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065650B, /* code */
    MI_T("ErrorSource"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, ErrorSource), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint16 CIM_Error_ErrorSourceFormat_value = 0;

/* property CIM_Error.ErrorSourceFormat */
static MI_CONST MI_PropertyDecl CIM_Error_ErrorSourceFormat_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00657411, /* code */
    MI_T("ErrorSourceFormat"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, ErrorSourceFormat), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    &CIM_Error_ErrorSourceFormat_value,
};

/* property CIM_Error.OtherErrorSourceFormat */
static MI_CONST MI_PropertyDecl CIM_Error_OtherErrorSourceFormat_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F7416, /* code */
    MI_T("OtherErrorSourceFormat"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, OtherErrorSourceFormat), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.CIMStatusCode */
static MI_CONST MI_PropertyDecl CIM_Error_CIMStatusCode_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063650D, /* code */
    MI_T("CIMStatusCode"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, CIMStatusCode), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

/* property CIM_Error.CIMStatusCodeDescription */
static MI_CONST MI_PropertyDecl CIM_Error_CIMStatusCodeDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E18, /* code */
    MI_T("CIMStatusCodeDescription"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Error, CIMStatusCodeDescription), /* offset */
    MI_T("CIM_Error"), /* origin */
    MI_T("CIM_Error"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_Error_props[] =
{
    &CIM_Error_ErrorType_prop,
    &CIM_Error_OtherErrorType_prop,
    &CIM_Error_OwningEntity_prop,
    &CIM_Error_MessageID_prop,
    &CIM_Error_Message_prop,
    &CIM_Error_MessageArguments_prop,
    &CIM_Error_PerceivedSeverity_prop,
    &CIM_Error_ProbableCause_prop,
    &CIM_Error_ProbableCauseDescription_prop,
    &CIM_Error_RecommendedActions_prop,
    &CIM_Error_ErrorSource_prop,
    &CIM_Error_ErrorSourceFormat_prop,
    &CIM_Error_OtherErrorSourceFormat_prop,
    &CIM_Error_CIMStatusCode_prop,
    &CIM_Error_CIMStatusCodeDescription_prop,
};

static MI_CONST MI_Char* CIM_Error_Version_qual_value = MI_T("2.22.1");

static MI_CONST MI_Qualifier CIM_Error_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_Error_Version_qual_value
};

static MI_CONST MI_Char* CIM_Error_UMLPackagePath_qual_value = MI_T("CIM::Interop");

static MI_CONST MI_Qualifier CIM_Error_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_Error_UMLPackagePath_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Error_quals[] =
{
    &CIM_Error_Version_qual,
    &CIM_Error_UMLPackagePath_qual,
};

/* class CIM_Error */
MI_CONST MI_ClassDecl CIM_Error_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_INDICATION, /* flags */
    0x00637209, /* code */
    MI_T("CIM_Error"), /* name */
    CIM_Error_quals, /* qualifiers */
    MI_COUNT(CIM_Error_quals), /* numQualifiers */
    CIM_Error_props, /* properties */
    MI_COUNT(CIM_Error_props), /* numProperties */
    sizeof(CIM_Error), /* size */
    NULL, /* superClass */
    NULL, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_ConcreteJob
**
**==============================================================================
*/

static MI_CONST MI_Char* CIM_ConcreteJob_InstanceID_Override_qual_value = MI_T("InstanceID");

static MI_CONST MI_Qualifier CIM_ConcreteJob_InstanceID_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ConcreteJob_InstanceID_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ConcreteJob_InstanceID_quals[] =
{
    &CIM_ConcreteJob_InstanceID_Override_qual,
};

/* property CIM_ConcreteJob.InstanceID */
static MI_CONST MI_PropertyDecl CIM_ConcreteJob_InstanceID_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x0069640A, /* code */
    MI_T("InstanceID"), /* name */
    CIM_ConcreteJob_InstanceID_quals, /* qualifiers */
    MI_COUNT(CIM_ConcreteJob_InstanceID_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob, InstanceID), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ConcreteJob_Name_MaxLen_qual_value = 1024U;

static MI_CONST MI_Qualifier CIM_ConcreteJob_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ConcreteJob_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_ConcreteJob_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_ConcreteJob_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ConcreteJob_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ConcreteJob_Name_quals[] =
{
    &CIM_ConcreteJob_Name_MaxLen_qual,
    &CIM_ConcreteJob_Name_Override_qual,
};

/* property CIM_ConcreteJob.Name */
static MI_CONST MI_PropertyDecl CIM_ConcreteJob_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_REQUIRED, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_ConcreteJob_Name_quals, /* qualifiers */
    MI_COUNT(CIM_ConcreteJob_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    NULL,
};

/* property CIM_ConcreteJob.JobState */
static MI_CONST MI_PropertyDecl CIM_ConcreteJob_JobState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006A6508, /* code */
    MI_T("JobState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob, JobState), /* offset */
    MI_T("CIM_ConcreteJob"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    NULL,
};

/* property CIM_ConcreteJob.TimeOfLastStateChange */
static MI_CONST MI_PropertyDecl CIM_ConcreteJob_TimeOfLastStateChange_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746515, /* code */
    MI_T("TimeOfLastStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob, TimeOfLastStateChange), /* offset */
    MI_T("CIM_ConcreteJob"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    NULL,
};

static MI_CONST MI_Datetime CIM_ConcreteJob_TimeBeforeRemoval_value = {0,{{0,0,5,0,0}}};

/* property CIM_ConcreteJob.TimeBeforeRemoval */
static MI_CONST MI_PropertyDecl CIM_ConcreteJob_TimeBeforeRemoval_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_REQUIRED, /* flags */
    0x00746C11, /* code */
    MI_T("TimeBeforeRemoval"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob, TimeBeforeRemoval), /* offset */
    MI_T("CIM_ConcreteJob"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    &CIM_ConcreteJob_TimeBeforeRemoval_value,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_ConcreteJob_props[] =
{
    &CIM_ConcreteJob_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ConcreteJob_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_Job_JobStatus_prop,
    &CIM_Job_TimeSubmitted_prop,
    &CIM_Job_ScheduledStartTime_prop,
    &CIM_Job_StartTime_prop,
    &CIM_Job_ElapsedTime_prop,
    &CIM_Job_JobRunTimes_prop,
    &CIM_Job_RunMonth_prop,
    &CIM_Job_RunDay_prop,
    &CIM_Job_RunDayOfWeek_prop,
    &CIM_Job_RunStartInterval_prop,
    &CIM_Job_LocalOrUtcTime_prop,
    &CIM_Job_UntilTime_prop,
    &CIM_Job_Notify_prop,
    &CIM_Job_Owner_prop,
    &CIM_Job_Priority_prop,
    &CIM_Job_PercentComplete_prop,
    &CIM_Job_DeleteOnCompletion_prop,
    &CIM_Job_ErrorCode_prop,
    &CIM_Job_ErrorDescription_prop,
    &CIM_Job_RecoveryAction_prop,
    &CIM_Job_OtherRecoveryAction_prop,
    &CIM_ConcreteJob_JobState_prop,
    &CIM_ConcreteJob_TimeOfLastStateChange_prop,
    &CIM_ConcreteJob_TimeBeforeRemoval_prop,
};

/* parameter CIM_ConcreteJob.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl CIM_ConcreteJob_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob_RequestStateChange, RequestedState), /* offset */
};

/* parameter CIM_ConcreteJob.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl CIM_ConcreteJob_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter CIM_ConcreteJob.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_ConcreteJob_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_ConcreteJob_RequestStateChange_params[] =
{
    &CIM_ConcreteJob_RequestStateChange_MIReturn_param,
    &CIM_ConcreteJob_RequestStateChange_RequestedState_param,
    &CIM_ConcreteJob_RequestStateChange_TimeoutPeriod_param,
};

/* method CIM_ConcreteJob.RequestStateChange() */
MI_CONST MI_MethodDecl CIM_ConcreteJob_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_ConcreteJob_RequestStateChange_params, /* parameters */
    MI_COUNT(CIM_ConcreteJob_RequestStateChange_params), /* numParameters */
    sizeof(CIM_ConcreteJob_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_ConcreteJob"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_CONST MI_Char* CIM_ConcreteJob_GetError_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ConcreteJob.GetErrors"),
};

static MI_CONST MI_ConstStringA CIM_ConcreteJob_GetError_Deprecated_qual_value =
{
    CIM_ConcreteJob_GetError_Deprecated_qual_data_value,
    MI_COUNT(CIM_ConcreteJob_GetError_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_ConcreteJob_GetError_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ConcreteJob_GetError_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ConcreteJob_GetError_quals[] =
{
    &CIM_ConcreteJob_GetError_Deprecated_qual,
};

static MI_CONST MI_Char* CIM_ConcreteJob_GetError_Error_EmbeddedInstance_qual_value = MI_T("CIM_Error");

static MI_CONST MI_Qualifier CIM_ConcreteJob_GetError_Error_EmbeddedInstance_qual =
{
    MI_T("EmbeddedInstance"),
    MI_STRING,
    0,
    &CIM_ConcreteJob_GetError_Error_EmbeddedInstance_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ConcreteJob_GetError_Error_quals[] =
{
    &CIM_ConcreteJob_GetError_Error_EmbeddedInstance_qual,
};

/* parameter CIM_ConcreteJob.GetError(): Error */
static MI_CONST MI_ParameterDecl CIM_ConcreteJob_GetError_Error_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00657205, /* code */
    MI_T("Error"), /* name */
    CIM_ConcreteJob_GetError_Error_quals, /* qualifiers */
    MI_COUNT(CIM_ConcreteJob_GetError_Error_quals), /* numQualifiers */
    MI_INSTANCE, /* type */
    MI_T("CIM_Error"), /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob_GetError, Error), /* offset */
};

static MI_CONST MI_Char* CIM_ConcreteJob_GetError_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ConcreteJob.GetErrors"),
};

static MI_CONST MI_ConstStringA CIM_ConcreteJob_GetError_MIReturn_Deprecated_qual_value =
{
    CIM_ConcreteJob_GetError_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(CIM_ConcreteJob_GetError_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_ConcreteJob_GetError_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ConcreteJob_GetError_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ConcreteJob_GetError_MIReturn_quals[] =
{
    &CIM_ConcreteJob_GetError_MIReturn_Deprecated_qual,
};

/* parameter CIM_ConcreteJob.GetError(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_ConcreteJob_GetError_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    CIM_ConcreteJob_GetError_MIReturn_quals, /* qualifiers */
    MI_COUNT(CIM_ConcreteJob_GetError_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob_GetError, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_ConcreteJob_GetError_params[] =
{
    &CIM_ConcreteJob_GetError_MIReturn_param,
    &CIM_ConcreteJob_GetError_Error_param,
};

/* method CIM_ConcreteJob.GetError() */
MI_CONST MI_MethodDecl CIM_ConcreteJob_GetError_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00677208, /* code */
    MI_T("GetError"), /* name */
    CIM_ConcreteJob_GetError_quals, /* qualifiers */
    MI_COUNT(CIM_ConcreteJob_GetError_quals), /* numQualifiers */
    CIM_ConcreteJob_GetError_params, /* parameters */
    MI_COUNT(CIM_ConcreteJob_GetError_params), /* numParameters */
    sizeof(CIM_ConcreteJob_GetError), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_ConcreteJob"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_CONST MI_Char* CIM_ConcreteJob_GetErrors_Errors_EmbeddedInstance_qual_value = MI_T("CIM_Error");

static MI_CONST MI_Qualifier CIM_ConcreteJob_GetErrors_Errors_EmbeddedInstance_qual =
{
    MI_T("EmbeddedInstance"),
    MI_STRING,
    0,
    &CIM_ConcreteJob_GetErrors_Errors_EmbeddedInstance_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ConcreteJob_GetErrors_Errors_quals[] =
{
    &CIM_ConcreteJob_GetErrors_Errors_EmbeddedInstance_qual,
};

/* parameter CIM_ConcreteJob.GetErrors(): Errors */
static MI_CONST MI_ParameterDecl CIM_ConcreteJob_GetErrors_Errors_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00657306, /* code */
    MI_T("Errors"), /* name */
    CIM_ConcreteJob_GetErrors_Errors_quals, /* qualifiers */
    MI_COUNT(CIM_ConcreteJob_GetErrors_Errors_quals), /* numQualifiers */
    MI_INSTANCEA, /* type */
    MI_T("CIM_Error"), /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob_GetErrors, Errors), /* offset */
};

/* parameter CIM_ConcreteJob.GetErrors(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_ConcreteJob_GetErrors_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ConcreteJob_GetErrors, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_ConcreteJob_GetErrors_params[] =
{
    &CIM_ConcreteJob_GetErrors_MIReturn_param,
    &CIM_ConcreteJob_GetErrors_Errors_param,
};

/* method CIM_ConcreteJob.GetErrors() */
MI_CONST MI_MethodDecl CIM_ConcreteJob_GetErrors_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00677309, /* code */
    MI_T("GetErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_ConcreteJob_GetErrors_params, /* parameters */
    MI_COUNT(CIM_ConcreteJob_GetErrors_params), /* numParameters */
    sizeof(CIM_ConcreteJob_GetErrors), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_ConcreteJob"), /* origin */
    MI_T("CIM_ConcreteJob"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_ConcreteJob_meths[] =
{
    &CIM_Job_KillJob_rtti,
    &CIM_ConcreteJob_RequestStateChange_rtti,
    &CIM_ConcreteJob_GetError_rtti,
    &CIM_ConcreteJob_GetErrors_rtti,
};

static MI_CONST MI_Char* CIM_ConcreteJob_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier CIM_ConcreteJob_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_ConcreteJob_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_ConcreteJob_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ConcreteJob.GetErrors"),
};

static MI_CONST MI_ConstStringA CIM_ConcreteJob_Deprecated_qual_value =
{
    CIM_ConcreteJob_Deprecated_qual_data_value,
    MI_COUNT(CIM_ConcreteJob_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_ConcreteJob_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ConcreteJob_Deprecated_qual_value
};

static MI_CONST MI_Char* CIM_ConcreteJob_Version_qual_value = MI_T("2.31.1");

static MI_CONST MI_Qualifier CIM_ConcreteJob_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_ConcreteJob_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ConcreteJob_quals[] =
{
    &CIM_ConcreteJob_UMLPackagePath_qual,
    &CIM_ConcreteJob_Deprecated_qual,
    &CIM_ConcreteJob_Version_qual,
};

/* class CIM_ConcreteJob */
MI_CONST MI_ClassDecl CIM_ConcreteJob_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0063620F, /* code */
    MI_T("CIM_ConcreteJob"), /* name */
    CIM_ConcreteJob_quals, /* qualifiers */
    MI_COUNT(CIM_ConcreteJob_quals), /* numQualifiers */
    CIM_ConcreteJob_props, /* properties */
    MI_COUNT(CIM_ConcreteJob_props), /* numProperties */
    sizeof(CIM_ConcreteJob), /* size */
    MI_T("CIM_Job"), /* superClass */
    &CIM_Job_rtti, /* superClassDecl */
    CIM_ConcreteJob_meths, /* methods */
    MI_COUNT(CIM_ConcreteJob_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_EnabledLogicalElement
**
**==============================================================================
*/

static MI_CONST MI_Uint16 CIM_EnabledLogicalElement_EnabledState_value = 5;

/* property CIM_EnabledLogicalElement.EnabledState */
static MI_CONST MI_PropertyDecl CIM_EnabledLogicalElement_EnabledState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065650C, /* code */
    MI_T("EnabledState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement, EnabledState), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &CIM_EnabledLogicalElement_EnabledState_value,
};

/* property CIM_EnabledLogicalElement.OtherEnabledState */
static MI_CONST MI_PropertyDecl CIM_EnabledLogicalElement_OtherEnabledState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6511, /* code */
    MI_T("OtherEnabledState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement, OtherEnabledState), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint16 CIM_EnabledLogicalElement_RequestedState_value = 12;

/* property CIM_EnabledLogicalElement.RequestedState */
static MI_CONST MI_PropertyDecl CIM_EnabledLogicalElement_RequestedState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement, RequestedState), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &CIM_EnabledLogicalElement_RequestedState_value,
};

static MI_CONST MI_Uint16 CIM_EnabledLogicalElement_EnabledDefault_value = 2;

/* property CIM_EnabledLogicalElement.EnabledDefault */
static MI_CONST MI_PropertyDecl CIM_EnabledLogicalElement_EnabledDefault_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065740E, /* code */
    MI_T("EnabledDefault"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement, EnabledDefault), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &CIM_EnabledLogicalElement_EnabledDefault_value,
};

/* property CIM_EnabledLogicalElement.TimeOfLastStateChange */
static MI_CONST MI_PropertyDecl CIM_EnabledLogicalElement_TimeOfLastStateChange_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746515, /* code */
    MI_T("TimeOfLastStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement, TimeOfLastStateChange), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    NULL,
};

/* property CIM_EnabledLogicalElement.AvailableRequestedStates */
static MI_CONST MI_PropertyDecl CIM_EnabledLogicalElement_AvailableRequestedStates_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00617318, /* code */
    MI_T("AvailableRequestedStates"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16A, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement, AvailableRequestedStates), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint16 CIM_EnabledLogicalElement_TransitioningToState_value = 12;

/* property CIM_EnabledLogicalElement.TransitioningToState */
static MI_CONST MI_PropertyDecl CIM_EnabledLogicalElement_TransitioningToState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746514, /* code */
    MI_T("TransitioningToState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement, TransitioningToState), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &CIM_EnabledLogicalElement_TransitioningToState_value,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_EnabledLogicalElement_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ManagedSystemElement_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
};

/* parameter CIM_EnabledLogicalElement.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl CIM_EnabledLogicalElement_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement_RequestStateChange, RequestedState), /* offset */
};

/* parameter CIM_EnabledLogicalElement.RequestStateChange(): Job */
static MI_CONST MI_ParameterDecl CIM_EnabledLogicalElement_RequestStateChange_Job_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006A6203, /* code */
    MI_T("Job"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REFERENCE, /* type */
    MI_T("CIM_ConcreteJob"), /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement_RequestStateChange, Job), /* offset */
};

/* parameter CIM_EnabledLogicalElement.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl CIM_EnabledLogicalElement_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter CIM_EnabledLogicalElement.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_EnabledLogicalElement_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EnabledLogicalElement_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_EnabledLogicalElement_RequestStateChange_params[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_MIReturn_param,
    &CIM_EnabledLogicalElement_RequestStateChange_RequestedState_param,
    &CIM_EnabledLogicalElement_RequestStateChange_Job_param,
    &CIM_EnabledLogicalElement_RequestStateChange_TimeoutPeriod_param,
};

/* method CIM_EnabledLogicalElement.RequestStateChange() */
MI_CONST MI_MethodDecl CIM_EnabledLogicalElement_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_EnabledLogicalElement_RequestStateChange_params, /* parameters */
    MI_COUNT(CIM_EnabledLogicalElement_RequestStateChange_params), /* numParameters */
    sizeof(CIM_EnabledLogicalElement_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_EnabledLogicalElement_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_EnabledLogicalElement_UMLPackagePath_qual_value = MI_T("CIM::Core::CoreElements");

static MI_CONST MI_Qualifier CIM_EnabledLogicalElement_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_EnabledLogicalElement_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_EnabledLogicalElement_Version_qual_value = MI_T("2.22.0");

static MI_CONST MI_Qualifier CIM_EnabledLogicalElement_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_EnabledLogicalElement_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_EnabledLogicalElement_quals[] =
{
    &CIM_EnabledLogicalElement_UMLPackagePath_qual,
    &CIM_EnabledLogicalElement_Version_qual,
};

/* class CIM_EnabledLogicalElement */
MI_CONST MI_ClassDecl CIM_EnabledLogicalElement_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00637419, /* code */
    MI_T("CIM_EnabledLogicalElement"), /* name */
    CIM_EnabledLogicalElement_quals, /* qualifiers */
    MI_COUNT(CIM_EnabledLogicalElement_quals), /* numQualifiers */
    CIM_EnabledLogicalElement_props, /* properties */
    MI_COUNT(CIM_EnabledLogicalElement_props), /* numProperties */
    sizeof(CIM_EnabledLogicalElement), /* size */
    MI_T("CIM_LogicalElement"), /* superClass */
    &CIM_LogicalElement_rtti, /* superClassDecl */
    CIM_EnabledLogicalElement_meths, /* methods */
    MI_COUNT(CIM_EnabledLogicalElement_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_LogicalDevice
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_LogicalDevice_SystemCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalDevice_SystemCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalDevice_SystemCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_LogicalDevice_SystemCreationClassName_Propagated_qual_value = MI_T("CIM_System.CreationClassName");

static MI_CONST MI_Qualifier CIM_LogicalDevice_SystemCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalDevice_SystemCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_SystemCreationClassName_quals[] =
{
    &CIM_LogicalDevice_SystemCreationClassName_MaxLen_qual,
    &CIM_LogicalDevice_SystemCreationClassName_Propagated_qual,
};

/* property CIM_LogicalDevice.SystemCreationClassName */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_SystemCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00736517, /* code */
    MI_T("SystemCreationClassName"), /* name */
    CIM_LogicalDevice_SystemCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_SystemCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, SystemCreationClassName), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalDevice_SystemName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalDevice_SystemName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalDevice_SystemName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_LogicalDevice_SystemName_Propagated_qual_value = MI_T("CIM_System.Name");

static MI_CONST MI_Qualifier CIM_LogicalDevice_SystemName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalDevice_SystemName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_SystemName_quals[] =
{
    &CIM_LogicalDevice_SystemName_MaxLen_qual,
    &CIM_LogicalDevice_SystemName_Propagated_qual,
};

/* property CIM_LogicalDevice.SystemName */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_SystemName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x0073650A, /* code */
    MI_T("SystemName"), /* name */
    CIM_LogicalDevice_SystemName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_SystemName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, SystemName), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalDevice_CreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalDevice_CreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalDevice_CreationClassName_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_CreationClassName_quals[] =
{
    &CIM_LogicalDevice_CreationClassName_MaxLen_qual,
};

/* property CIM_LogicalDevice.CreationClassName */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_CreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636511, /* code */
    MI_T("CreationClassName"), /* name */
    CIM_LogicalDevice_CreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_CreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, CreationClassName), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalDevice_DeviceID_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier CIM_LogicalDevice_DeviceID_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalDevice_DeviceID_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_DeviceID_quals[] =
{
    &CIM_LogicalDevice_DeviceID_MaxLen_qual,
};

/* property CIM_LogicalDevice.DeviceID */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_DeviceID_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00646408, /* code */
    MI_T("DeviceID"), /* name */
    CIM_LogicalDevice_DeviceID_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_DeviceID_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, DeviceID), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_PowerManagementSupported_Deprecated_qual_data_value[] =
{
    MI_T("CIM_PowerManagementCapabilities"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_PowerManagementSupported_Deprecated_qual_value =
{
    CIM_LogicalDevice_PowerManagementSupported_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_PowerManagementSupported_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_PowerManagementSupported_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_PowerManagementSupported_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_PowerManagementSupported_quals[] =
{
    &CIM_LogicalDevice_PowerManagementSupported_Deprecated_qual,
};

/* property CIM_LogicalDevice.PowerManagementSupported */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_PowerManagementSupported_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706418, /* code */
    MI_T("PowerManagementSupported"), /* name */
    CIM_LogicalDevice_PowerManagementSupported_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_PowerManagementSupported_quals), /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, PowerManagementSupported), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_PowerManagementCapabilities_Deprecated_qual_data_value[] =
{
    MI_T("CIM_PowerManagementCapabilities.PowerCapabilities"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_PowerManagementCapabilities_Deprecated_qual_value =
{
    CIM_LogicalDevice_PowerManagementCapabilities_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_PowerManagementCapabilities_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_PowerManagementCapabilities_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_PowerManagementCapabilities_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_PowerManagementCapabilities_quals[] =
{
    &CIM_LogicalDevice_PowerManagementCapabilities_Deprecated_qual,
};

/* property CIM_LogicalDevice.PowerManagementCapabilities */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_PowerManagementCapabilities_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070731B, /* code */
    MI_T("PowerManagementCapabilities"), /* name */
    CIM_LogicalDevice_PowerManagementCapabilities_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_PowerManagementCapabilities_quals), /* numQualifiers */
    MI_UINT16A, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, PowerManagementCapabilities), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

/* property CIM_LogicalDevice.Availability */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_Availability_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061790C, /* code */
    MI_T("Availability"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, Availability), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_StatusInfo_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.EnabledState"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_StatusInfo_Deprecated_qual_value =
{
    CIM_LogicalDevice_StatusInfo_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_StatusInfo_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_StatusInfo_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_StatusInfo_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_StatusInfo_quals[] =
{
    &CIM_LogicalDevice_StatusInfo_Deprecated_qual,
};

/* property CIM_LogicalDevice.StatusInfo */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_StatusInfo_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736F0A, /* code */
    MI_T("StatusInfo"), /* name */
    CIM_LogicalDevice_StatusInfo_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_StatusInfo_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, StatusInfo), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_LastErrorCode_Deprecated_qual_data_value[] =
{
    MI_T("CIM_DeviceErrorData.LastErrorCode"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_LastErrorCode_Deprecated_qual_value =
{
    CIM_LogicalDevice_LastErrorCode_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_LastErrorCode_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_LastErrorCode_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_LastErrorCode_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_LastErrorCode_quals[] =
{
    &CIM_LogicalDevice_LastErrorCode_Deprecated_qual,
};

/* property CIM_LogicalDevice.LastErrorCode */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_LastErrorCode_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C650D, /* code */
    MI_T("LastErrorCode"), /* name */
    CIM_LogicalDevice_LastErrorCode_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_LastErrorCode_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, LastErrorCode), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_ErrorDescription_Deprecated_qual_data_value[] =
{
    MI_T("CIM_DeviceErrorData.ErrorDescription"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_ErrorDescription_Deprecated_qual_value =
{
    CIM_LogicalDevice_ErrorDescription_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_ErrorDescription_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_ErrorDescription_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_ErrorDescription_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_ErrorDescription_quals[] =
{
    &CIM_LogicalDevice_ErrorDescription_Deprecated_qual,
};

/* property CIM_LogicalDevice.ErrorDescription */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_ErrorDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00656E10, /* code */
    MI_T("ErrorDescription"), /* name */
    CIM_LogicalDevice_ErrorDescription_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_ErrorDescription_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, ErrorDescription), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_ErrorCleared_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ManagedSystemElement.OperationalStatus"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_ErrorCleared_Deprecated_qual_value =
{
    CIM_LogicalDevice_ErrorCleared_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_ErrorCleared_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_ErrorCleared_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_ErrorCleared_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_ErrorCleared_quals[] =
{
    &CIM_LogicalDevice_ErrorCleared_Deprecated_qual,
};

/* property CIM_LogicalDevice.ErrorCleared */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_ErrorCleared_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065640C, /* code */
    MI_T("ErrorCleared"), /* name */
    CIM_LogicalDevice_ErrorCleared_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_ErrorCleared_quals), /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, ErrorCleared), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_OtherIdentifyingInfo_ArrayType_qual_value = MI_T("Indexed");

static MI_CONST MI_Qualifier CIM_LogicalDevice_OtherIdentifyingInfo_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalDevice_OtherIdentifyingInfo_ArrayType_qual_value
};

static MI_CONST MI_Uint32 CIM_LogicalDevice_OtherIdentifyingInfo_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalDevice_OtherIdentifyingInfo_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalDevice_OtherIdentifyingInfo_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_OtherIdentifyingInfo_quals[] =
{
    &CIM_LogicalDevice_OtherIdentifyingInfo_ArrayType_qual,
    &CIM_LogicalDevice_OtherIdentifyingInfo_MaxLen_qual,
};

/* property CIM_LogicalDevice.OtherIdentifyingInfo */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_OtherIdentifyingInfo_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6F14, /* code */
    MI_T("OtherIdentifyingInfo"), /* name */
    CIM_LogicalDevice_OtherIdentifyingInfo_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_OtherIdentifyingInfo_quals), /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, OtherIdentifyingInfo), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_PowerOnHours_Units_qual_value = MI_T("Hours");

static MI_CONST MI_Qualifier CIM_LogicalDevice_PowerOnHours_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_LogicalDevice_PowerOnHours_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_PowerOnHours_quals[] =
{
    &CIM_LogicalDevice_PowerOnHours_Units_qual,
};

/* property CIM_LogicalDevice.PowerOnHours */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_PowerOnHours_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070730C, /* code */
    MI_T("PowerOnHours"), /* name */
    CIM_LogicalDevice_PowerOnHours_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_PowerOnHours_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, PowerOnHours), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_TotalPowerOnHours_Units_qual_value = MI_T("Hours");

static MI_CONST MI_Qualifier CIM_LogicalDevice_TotalPowerOnHours_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_LogicalDevice_TotalPowerOnHours_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_TotalPowerOnHours_quals[] =
{
    &CIM_LogicalDevice_TotalPowerOnHours_Units_qual,
};

/* property CIM_LogicalDevice.TotalPowerOnHours */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_TotalPowerOnHours_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00747311, /* code */
    MI_T("TotalPowerOnHours"), /* name */
    CIM_LogicalDevice_TotalPowerOnHours_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_TotalPowerOnHours_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, TotalPowerOnHours), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_IdentifyingDescriptions_ArrayType_qual_value = MI_T("Indexed");

static MI_CONST MI_Qualifier CIM_LogicalDevice_IdentifyingDescriptions_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalDevice_IdentifyingDescriptions_ArrayType_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_IdentifyingDescriptions_quals[] =
{
    &CIM_LogicalDevice_IdentifyingDescriptions_ArrayType_qual,
};

/* property CIM_LogicalDevice.IdentifyingDescriptions */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_IdentifyingDescriptions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00697317, /* code */
    MI_T("IdentifyingDescriptions"), /* name */
    CIM_LogicalDevice_IdentifyingDescriptions_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_IdentifyingDescriptions_quals), /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, IdentifyingDescriptions), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

/* property CIM_LogicalDevice.AdditionalAvailability */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_AdditionalAvailability_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00617916, /* code */
    MI_T("AdditionalAvailability"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16A, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, AdditionalAvailability), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalDevice_MaxQuiesceTime_Deprecated_qual_data_value[] =
{
    MI_T("No value"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_MaxQuiesceTime_Deprecated_qual_value =
{
    CIM_LogicalDevice_MaxQuiesceTime_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_MaxQuiesceTime_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_MaxQuiesceTime_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_MaxQuiesceTime_Deprecated_qual_value
};

static MI_CONST MI_Char* CIM_LogicalDevice_MaxQuiesceTime_Units_qual_value = MI_T("MilliSeconds");

static MI_CONST MI_Qualifier CIM_LogicalDevice_MaxQuiesceTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_LogicalDevice_MaxQuiesceTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_MaxQuiesceTime_quals[] =
{
    &CIM_LogicalDevice_MaxQuiesceTime_Deprecated_qual,
    &CIM_LogicalDevice_MaxQuiesceTime_Units_qual,
};

/* property CIM_LogicalDevice.MaxQuiesceTime */
static MI_CONST MI_PropertyDecl CIM_LogicalDevice_MaxQuiesceTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D650E, /* code */
    MI_T("MaxQuiesceTime"), /* name */
    CIM_LogicalDevice_MaxQuiesceTime_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_MaxQuiesceTime_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice, MaxQuiesceTime), /* offset */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_LogicalDevice_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ManagedSystemElement_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_LogicalDevice_SystemCreationClassName_prop,
    &CIM_LogicalDevice_SystemName_prop,
    &CIM_LogicalDevice_CreationClassName_prop,
    &CIM_LogicalDevice_DeviceID_prop,
    &CIM_LogicalDevice_PowerManagementSupported_prop,
    &CIM_LogicalDevice_PowerManagementCapabilities_prop,
    &CIM_LogicalDevice_Availability_prop,
    &CIM_LogicalDevice_StatusInfo_prop,
    &CIM_LogicalDevice_LastErrorCode_prop,
    &CIM_LogicalDevice_ErrorDescription_prop,
    &CIM_LogicalDevice_ErrorCleared_prop,
    &CIM_LogicalDevice_OtherIdentifyingInfo_prop,
    &CIM_LogicalDevice_PowerOnHours_prop,
    &CIM_LogicalDevice_TotalPowerOnHours_prop,
    &CIM_LogicalDevice_IdentifyingDescriptions_prop,
    &CIM_LogicalDevice_AdditionalAvailability_prop,
    &CIM_LogicalDevice_MaxQuiesceTime_prop,
};

static MI_CONST MI_Char* CIM_LogicalDevice_SetPowerState_Deprecated_qual_data_value[] =
{
    MI_T("CIM_PowerManagementService.SetPowerState"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_SetPowerState_Deprecated_qual_value =
{
    CIM_LogicalDevice_SetPowerState_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_SetPowerState_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_SetPowerState_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_SetPowerState_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_SetPowerState_quals[] =
{
    &CIM_LogicalDevice_SetPowerState_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.SetPowerState(): PowerState */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_SetPowerState_PowerState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0070650A, /* code */
    MI_T("PowerState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_SetPowerState, PowerState), /* offset */
};

/* parameter CIM_LogicalDevice.SetPowerState(): Time */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_SetPowerState_Time_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00746504, /* code */
    MI_T("Time"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_SetPowerState, Time), /* offset */
};

static MI_CONST MI_Char* CIM_LogicalDevice_SetPowerState_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_PowerManagementService.SetPowerState"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_SetPowerState_MIReturn_Deprecated_qual_value =
{
    CIM_LogicalDevice_SetPowerState_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_SetPowerState_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_SetPowerState_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_SetPowerState_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_SetPowerState_MIReturn_quals[] =
{
    &CIM_LogicalDevice_SetPowerState_MIReturn_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.SetPowerState(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_SetPowerState_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    CIM_LogicalDevice_SetPowerState_MIReturn_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_SetPowerState_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_SetPowerState, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_LogicalDevice_SetPowerState_params[] =
{
    &CIM_LogicalDevice_SetPowerState_MIReturn_param,
    &CIM_LogicalDevice_SetPowerState_PowerState_param,
    &CIM_LogicalDevice_SetPowerState_Time_param,
};

/* method CIM_LogicalDevice.SetPowerState() */
MI_CONST MI_MethodDecl CIM_LogicalDevice_SetPowerState_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0073650D, /* code */
    MI_T("SetPowerState"), /* name */
    CIM_LogicalDevice_SetPowerState_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_SetPowerState_quals), /* numQualifiers */
    CIM_LogicalDevice_SetPowerState_params, /* parameters */
    MI_COUNT(CIM_LogicalDevice_SetPowerState_params), /* numParameters */
    sizeof(CIM_LogicalDevice_SetPowerState), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

/* parameter CIM_LogicalDevice.Reset(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_Reset_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_Reset, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_LogicalDevice_Reset_params[] =
{
    &CIM_LogicalDevice_Reset_MIReturn_param,
};

/* method CIM_LogicalDevice.Reset() */
MI_CONST MI_MethodDecl CIM_LogicalDevice_Reset_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727405, /* code */
    MI_T("Reset"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_LogicalDevice_Reset_params, /* parameters */
    MI_COUNT(CIM_LogicalDevice_Reset_params), /* numParameters */
    sizeof(CIM_LogicalDevice_Reset), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_CONST MI_Char* CIM_LogicalDevice_EnableDevice_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_EnableDevice_Deprecated_qual_value =
{
    CIM_LogicalDevice_EnableDevice_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_EnableDevice_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_EnableDevice_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_EnableDevice_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_EnableDevice_quals[] =
{
    &CIM_LogicalDevice_EnableDevice_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.EnableDevice(): Enabled */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_EnableDevice_Enabled_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00656407, /* code */
    MI_T("Enabled"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_EnableDevice, Enabled), /* offset */
};

static MI_CONST MI_Char* CIM_LogicalDevice_EnableDevice_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_EnableDevice_MIReturn_Deprecated_qual_value =
{
    CIM_LogicalDevice_EnableDevice_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_EnableDevice_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_EnableDevice_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_EnableDevice_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_EnableDevice_MIReturn_quals[] =
{
    &CIM_LogicalDevice_EnableDevice_MIReturn_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.EnableDevice(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_EnableDevice_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    CIM_LogicalDevice_EnableDevice_MIReturn_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_EnableDevice_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_EnableDevice, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_LogicalDevice_EnableDevice_params[] =
{
    &CIM_LogicalDevice_EnableDevice_MIReturn_param,
    &CIM_LogicalDevice_EnableDevice_Enabled_param,
};

/* method CIM_LogicalDevice.EnableDevice() */
MI_CONST MI_MethodDecl CIM_LogicalDevice_EnableDevice_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0065650C, /* code */
    MI_T("EnableDevice"), /* name */
    CIM_LogicalDevice_EnableDevice_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_EnableDevice_quals), /* numQualifiers */
    CIM_LogicalDevice_EnableDevice_params, /* parameters */
    MI_COUNT(CIM_LogicalDevice_EnableDevice_params), /* numParameters */
    sizeof(CIM_LogicalDevice_EnableDevice), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_CONST MI_Char* CIM_LogicalDevice_OnlineDevice_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_OnlineDevice_Deprecated_qual_value =
{
    CIM_LogicalDevice_OnlineDevice_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_OnlineDevice_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_OnlineDevice_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_OnlineDevice_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_OnlineDevice_quals[] =
{
    &CIM_LogicalDevice_OnlineDevice_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.OnlineDevice(): Online */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_OnlineDevice_Online_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x006F6506, /* code */
    MI_T("Online"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_OnlineDevice, Online), /* offset */
};

static MI_CONST MI_Char* CIM_LogicalDevice_OnlineDevice_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_OnlineDevice_MIReturn_Deprecated_qual_value =
{
    CIM_LogicalDevice_OnlineDevice_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_OnlineDevice_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_OnlineDevice_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_OnlineDevice_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_OnlineDevice_MIReturn_quals[] =
{
    &CIM_LogicalDevice_OnlineDevice_MIReturn_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.OnlineDevice(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_OnlineDevice_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    CIM_LogicalDevice_OnlineDevice_MIReturn_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_OnlineDevice_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_OnlineDevice, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_LogicalDevice_OnlineDevice_params[] =
{
    &CIM_LogicalDevice_OnlineDevice_MIReturn_param,
    &CIM_LogicalDevice_OnlineDevice_Online_param,
};

/* method CIM_LogicalDevice.OnlineDevice() */
MI_CONST MI_MethodDecl CIM_LogicalDevice_OnlineDevice_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x006F650C, /* code */
    MI_T("OnlineDevice"), /* name */
    CIM_LogicalDevice_OnlineDevice_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_OnlineDevice_quals), /* numQualifiers */
    CIM_LogicalDevice_OnlineDevice_params, /* parameters */
    MI_COUNT(CIM_LogicalDevice_OnlineDevice_params), /* numParameters */
    sizeof(CIM_LogicalDevice_OnlineDevice), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_CONST MI_Char* CIM_LogicalDevice_QuiesceDevice_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_QuiesceDevice_Deprecated_qual_value =
{
    CIM_LogicalDevice_QuiesceDevice_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_QuiesceDevice_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_QuiesceDevice_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_QuiesceDevice_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_QuiesceDevice_quals[] =
{
    &CIM_LogicalDevice_QuiesceDevice_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.QuiesceDevice(): Quiesce */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_QuiesceDevice_Quiesce_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00716507, /* code */
    MI_T("Quiesce"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_QuiesceDevice, Quiesce), /* offset */
};

static MI_CONST MI_Char* CIM_LogicalDevice_QuiesceDevice_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA CIM_LogicalDevice_QuiesceDevice_MIReturn_Deprecated_qual_value =
{
    CIM_LogicalDevice_QuiesceDevice_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(CIM_LogicalDevice_QuiesceDevice_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LogicalDevice_QuiesceDevice_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_QuiesceDevice_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_QuiesceDevice_MIReturn_quals[] =
{
    &CIM_LogicalDevice_QuiesceDevice_MIReturn_Deprecated_qual,
};

/* parameter CIM_LogicalDevice.QuiesceDevice(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_QuiesceDevice_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    CIM_LogicalDevice_QuiesceDevice_MIReturn_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_QuiesceDevice_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_QuiesceDevice, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_LogicalDevice_QuiesceDevice_params[] =
{
    &CIM_LogicalDevice_QuiesceDevice_MIReturn_param,
    &CIM_LogicalDevice_QuiesceDevice_Quiesce_param,
};

/* method CIM_LogicalDevice.QuiesceDevice() */
MI_CONST MI_MethodDecl CIM_LogicalDevice_QuiesceDevice_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0071650D, /* code */
    MI_T("QuiesceDevice"), /* name */
    CIM_LogicalDevice_QuiesceDevice_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_QuiesceDevice_quals), /* numQualifiers */
    CIM_LogicalDevice_QuiesceDevice_params, /* parameters */
    MI_COUNT(CIM_LogicalDevice_QuiesceDevice_params), /* numParameters */
    sizeof(CIM_LogicalDevice_QuiesceDevice), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

/* parameter CIM_LogicalDevice.SaveProperties(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_SaveProperties_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_SaveProperties, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_LogicalDevice_SaveProperties_params[] =
{
    &CIM_LogicalDevice_SaveProperties_MIReturn_param,
};

/* method CIM_LogicalDevice.SaveProperties() */
MI_CONST MI_MethodDecl CIM_LogicalDevice_SaveProperties_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0073730E, /* code */
    MI_T("SaveProperties"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_LogicalDevice_SaveProperties_params, /* parameters */
    MI_COUNT(CIM_LogicalDevice_SaveProperties_params), /* numParameters */
    sizeof(CIM_LogicalDevice_SaveProperties), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

/* parameter CIM_LogicalDevice.RestoreProperties(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_LogicalDevice_RestoreProperties_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalDevice_RestoreProperties, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_LogicalDevice_RestoreProperties_params[] =
{
    &CIM_LogicalDevice_RestoreProperties_MIReturn_param,
};

/* method CIM_LogicalDevice.RestoreProperties() */
MI_CONST MI_MethodDecl CIM_LogicalDevice_RestoreProperties_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727311, /* code */
    MI_T("RestoreProperties"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_LogicalDevice_RestoreProperties_params, /* parameters */
    MI_COUNT(CIM_LogicalDevice_RestoreProperties_params), /* numParameters */
    sizeof(CIM_LogicalDevice_RestoreProperties), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_LogicalDevice_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
    &CIM_LogicalDevice_SetPowerState_rtti,
    &CIM_LogicalDevice_Reset_rtti,
    &CIM_LogicalDevice_EnableDevice_rtti,
    &CIM_LogicalDevice_OnlineDevice_rtti,
    &CIM_LogicalDevice_QuiesceDevice_rtti,
    &CIM_LogicalDevice_SaveProperties_rtti,
    &CIM_LogicalDevice_RestoreProperties_rtti,
};

static MI_CONST MI_Char* CIM_LogicalDevice_UMLPackagePath_qual_value = MI_T("CIM::Core::Device");

static MI_CONST MI_Qualifier CIM_LogicalDevice_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_LogicalDevice_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_LogicalDevice_Version_qual_value = MI_T("2.8.0");

static MI_CONST MI_Qualifier CIM_LogicalDevice_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_LogicalDevice_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalDevice_quals[] =
{
    &CIM_LogicalDevice_UMLPackagePath_qual,
    &CIM_LogicalDevice_Version_qual,
};

/* class CIM_LogicalDevice */
MI_CONST MI_ClassDecl CIM_LogicalDevice_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00636511, /* code */
    MI_T("CIM_LogicalDevice"), /* name */
    CIM_LogicalDevice_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalDevice_quals), /* numQualifiers */
    CIM_LogicalDevice_props, /* properties */
    MI_COUNT(CIM_LogicalDevice_props), /* numProperties */
    sizeof(CIM_LogicalDevice), /* size */
    MI_T("CIM_EnabledLogicalElement"), /* superClass */
    &CIM_EnabledLogicalElement_rtti, /* superClassDecl */
    CIM_LogicalDevice_meths, /* methods */
    MI_COUNT(CIM_LogicalDevice_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_MediaAccessDevice
**
**==============================================================================
*/

static MI_CONST MI_Char* CIM_MediaAccessDevice_Capabilities_ArrayType_qual_value = MI_T("Indexed");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_Capabilities_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_MediaAccessDevice_Capabilities_ArrayType_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_Capabilities_quals[] =
{
    &CIM_MediaAccessDevice_Capabilities_ArrayType_qual,
};

/* property CIM_MediaAccessDevice.Capabilities */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_Capabilities_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063730C, /* code */
    MI_T("Capabilities"), /* name */
    CIM_MediaAccessDevice_Capabilities_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_Capabilities_quals), /* numQualifiers */
    MI_UINT16A, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, Capabilities), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_CapabilityDescriptions_ArrayType_qual_value = MI_T("Indexed");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_CapabilityDescriptions_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_MediaAccessDevice_CapabilityDescriptions_ArrayType_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_CapabilityDescriptions_quals[] =
{
    &CIM_MediaAccessDevice_CapabilityDescriptions_ArrayType_qual,
};

/* property CIM_MediaAccessDevice.CapabilityDescriptions */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_CapabilityDescriptions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00637316, /* code */
    MI_T("CapabilityDescriptions"), /* name */
    CIM_MediaAccessDevice_CapabilityDescriptions_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_CapabilityDescriptions_quals), /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, CapabilityDescriptions), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.ErrorMethodology */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_ErrorMethodology_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00657910, /* code */
    MI_T("ErrorMethodology"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, ErrorMethodology), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.CompressionMethod */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_CompressionMethod_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636411, /* code */
    MI_T("CompressionMethod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, CompressionMethod), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.NumberOfMediaSupported */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_NumberOfMediaSupported_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E6416, /* code */
    MI_T("NumberOfMediaSupported"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, NumberOfMediaSupported), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.MaxMediaSize */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_MaxMediaSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D650C, /* code */
    MI_T("MaxMediaSize"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, MaxMediaSize), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_DefaultBlockSize_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_DefaultBlockSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_MediaAccessDevice_DefaultBlockSize_Units_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_DefaultBlockSize_PUnit_qual_value = MI_T("byte");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_DefaultBlockSize_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_DefaultBlockSize_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_DefaultBlockSize_quals[] =
{
    &CIM_MediaAccessDevice_DefaultBlockSize_Units_qual,
    &CIM_MediaAccessDevice_DefaultBlockSize_PUnit_qual,
};

/* property CIM_MediaAccessDevice.DefaultBlockSize */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_DefaultBlockSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646510, /* code */
    MI_T("DefaultBlockSize"), /* name */
    CIM_MediaAccessDevice_DefaultBlockSize_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_DefaultBlockSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, DefaultBlockSize), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_MaxBlockSize_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_MaxBlockSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_MediaAccessDevice_MaxBlockSize_Units_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_MaxBlockSize_PUnit_qual_value = MI_T("byte");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_MaxBlockSize_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_MaxBlockSize_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_MaxBlockSize_quals[] =
{
    &CIM_MediaAccessDevice_MaxBlockSize_Units_qual,
    &CIM_MediaAccessDevice_MaxBlockSize_PUnit_qual,
};

/* property CIM_MediaAccessDevice.MaxBlockSize */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_MaxBlockSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D650C, /* code */
    MI_T("MaxBlockSize"), /* name */
    CIM_MediaAccessDevice_MaxBlockSize_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_MaxBlockSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, MaxBlockSize), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_MinBlockSize_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_MinBlockSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_MediaAccessDevice_MinBlockSize_Units_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_MinBlockSize_PUnit_qual_value = MI_T("byte");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_MinBlockSize_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_MinBlockSize_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_MinBlockSize_quals[] =
{
    &CIM_MediaAccessDevice_MinBlockSize_Units_qual,
    &CIM_MediaAccessDevice_MinBlockSize_PUnit_qual,
};

/* property CIM_MediaAccessDevice.MinBlockSize */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_MinBlockSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D650C, /* code */
    MI_T("MinBlockSize"), /* name */
    CIM_MediaAccessDevice_MinBlockSize_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_MinBlockSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, MinBlockSize), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.NeedsCleaning */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_NeedsCleaning_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E670D, /* code */
    MI_T("NeedsCleaning"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, NeedsCleaning), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.MediaIsLocked */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_MediaIsLocked_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D640D, /* code */
    MI_T("MediaIsLocked"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, MediaIsLocked), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.Security */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_Security_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00737908, /* code */
    MI_T("Security"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, Security), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.LastCleaned */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_LastCleaned_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C640B, /* code */
    MI_T("LastCleaned"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, LastCleaned), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_MaxAccessTime_Units_qual_value = MI_T("MilliSeconds");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_MaxAccessTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_MediaAccessDevice_MaxAccessTime_Units_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_MaxAccessTime_PUnit_qual_value = MI_T("second * 10^-3");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_MaxAccessTime_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_MaxAccessTime_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_MaxAccessTime_quals[] =
{
    &CIM_MediaAccessDevice_MaxAccessTime_Units_qual,
    &CIM_MediaAccessDevice_MaxAccessTime_PUnit_qual,
};

/* property CIM_MediaAccessDevice.MaxAccessTime */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_MaxAccessTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D650D, /* code */
    MI_T("MaxAccessTime"), /* name */
    CIM_MediaAccessDevice_MaxAccessTime_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_MaxAccessTime_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, MaxAccessTime), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_UncompressedDataRate_Units_qual_value = MI_T("KiloBytes per Second");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_UncompressedDataRate_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_MediaAccessDevice_UncompressedDataRate_Units_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_UncompressedDataRate_PUnit_qual_value = MI_T("byte / second * 10^3");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_UncompressedDataRate_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_UncompressedDataRate_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_UncompressedDataRate_quals[] =
{
    &CIM_MediaAccessDevice_UncompressedDataRate_Units_qual,
    &CIM_MediaAccessDevice_UncompressedDataRate_PUnit_qual,
};

/* property CIM_MediaAccessDevice.UncompressedDataRate */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_UncompressedDataRate_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00756514, /* code */
    MI_T("UncompressedDataRate"), /* name */
    CIM_MediaAccessDevice_UncompressedDataRate_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_UncompressedDataRate_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, UncompressedDataRate), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_LoadTime_Units_qual_value = MI_T("MilliSeconds");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_LoadTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_MediaAccessDevice_LoadTime_Units_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_LoadTime_PUnit_qual_value = MI_T("second * 10^-3");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_LoadTime_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_LoadTime_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_LoadTime_quals[] =
{
    &CIM_MediaAccessDevice_LoadTime_Units_qual,
    &CIM_MediaAccessDevice_LoadTime_PUnit_qual,
};

/* property CIM_MediaAccessDevice.LoadTime */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_LoadTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C6508, /* code */
    MI_T("LoadTime"), /* name */
    CIM_MediaAccessDevice_LoadTime_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_LoadTime_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, LoadTime), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_UnloadTime_Units_qual_value = MI_T("MilliSeconds");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_UnloadTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_MediaAccessDevice_UnloadTime_Units_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_UnloadTime_PUnit_qual_value = MI_T("second * 10^-3");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_UnloadTime_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_UnloadTime_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_UnloadTime_quals[] =
{
    &CIM_MediaAccessDevice_UnloadTime_Units_qual,
    &CIM_MediaAccessDevice_UnloadTime_PUnit_qual,
};

/* property CIM_MediaAccessDevice.UnloadTime */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_UnloadTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0075650A, /* code */
    MI_T("UnloadTime"), /* name */
    CIM_MediaAccessDevice_UnloadTime_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_UnloadTime_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, UnloadTime), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.MountCount */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_MountCount_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D740A, /* code */
    MI_T("MountCount"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, MountCount), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.TimeOfLastMount */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_TimeOfLastMount_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074740F, /* code */
    MI_T("TimeOfLastMount"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, TimeOfLastMount), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.TotalMountTime */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_TotalMountTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074650E, /* code */
    MI_T("TotalMountTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, TotalMountTime), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.UnitsDescription */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_UnitsDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00756E10, /* code */
    MI_T("UnitsDescription"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, UnitsDescription), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.MaxUnitsBeforeCleaning */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_MaxUnitsBeforeCleaning_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6716, /* code */
    MI_T("MaxUnitsBeforeCleaning"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, MaxUnitsBeforeCleaning), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

/* property CIM_MediaAccessDevice.UnitsUsed */
static MI_CONST MI_PropertyDecl CIM_MediaAccessDevice_UnitsUsed_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00756409, /* code */
    MI_T("UnitsUsed"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice, UnitsUsed), /* offset */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_MediaAccessDevice_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ManagedSystemElement_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_LogicalDevice_SystemCreationClassName_prop,
    &CIM_LogicalDevice_SystemName_prop,
    &CIM_LogicalDevice_CreationClassName_prop,
    &CIM_LogicalDevice_DeviceID_prop,
    &CIM_LogicalDevice_PowerManagementSupported_prop,
    &CIM_LogicalDevice_PowerManagementCapabilities_prop,
    &CIM_LogicalDevice_Availability_prop,
    &CIM_LogicalDevice_StatusInfo_prop,
    &CIM_LogicalDevice_LastErrorCode_prop,
    &CIM_LogicalDevice_ErrorDescription_prop,
    &CIM_LogicalDevice_ErrorCleared_prop,
    &CIM_LogicalDevice_OtherIdentifyingInfo_prop,
    &CIM_LogicalDevice_PowerOnHours_prop,
    &CIM_LogicalDevice_TotalPowerOnHours_prop,
    &CIM_LogicalDevice_IdentifyingDescriptions_prop,
    &CIM_LogicalDevice_AdditionalAvailability_prop,
    &CIM_LogicalDevice_MaxQuiesceTime_prop,
    &CIM_MediaAccessDevice_Capabilities_prop,
    &CIM_MediaAccessDevice_CapabilityDescriptions_prop,
    &CIM_MediaAccessDevice_ErrorMethodology_prop,
    &CIM_MediaAccessDevice_CompressionMethod_prop,
    &CIM_MediaAccessDevice_NumberOfMediaSupported_prop,
    &CIM_MediaAccessDevice_MaxMediaSize_prop,
    &CIM_MediaAccessDevice_DefaultBlockSize_prop,
    &CIM_MediaAccessDevice_MaxBlockSize_prop,
    &CIM_MediaAccessDevice_MinBlockSize_prop,
    &CIM_MediaAccessDevice_NeedsCleaning_prop,
    &CIM_MediaAccessDevice_MediaIsLocked_prop,
    &CIM_MediaAccessDevice_Security_prop,
    &CIM_MediaAccessDevice_LastCleaned_prop,
    &CIM_MediaAccessDevice_MaxAccessTime_prop,
    &CIM_MediaAccessDevice_UncompressedDataRate_prop,
    &CIM_MediaAccessDevice_LoadTime_prop,
    &CIM_MediaAccessDevice_UnloadTime_prop,
    &CIM_MediaAccessDevice_MountCount_prop,
    &CIM_MediaAccessDevice_TimeOfLastMount_prop,
    &CIM_MediaAccessDevice_TotalMountTime_prop,
    &CIM_MediaAccessDevice_UnitsDescription_prop,
    &CIM_MediaAccessDevice_MaxUnitsBeforeCleaning_prop,
    &CIM_MediaAccessDevice_UnitsUsed_prop,
};

/* parameter CIM_MediaAccessDevice.LockMedia(): Lock */
static MI_CONST MI_ParameterDecl CIM_MediaAccessDevice_LockMedia_Lock_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x006C6B04, /* code */
    MI_T("Lock"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice_LockMedia, Lock), /* offset */
};

/* parameter CIM_MediaAccessDevice.LockMedia(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_MediaAccessDevice_LockMedia_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_MediaAccessDevice_LockMedia, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_MediaAccessDevice_LockMedia_params[] =
{
    &CIM_MediaAccessDevice_LockMedia_MIReturn_param,
    &CIM_MediaAccessDevice_LockMedia_Lock_param,
};

/* method CIM_MediaAccessDevice.LockMedia() */
MI_CONST MI_MethodDecl CIM_MediaAccessDevice_LockMedia_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x006C6109, /* code */
    MI_T("LockMedia"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_MediaAccessDevice_LockMedia_params, /* parameters */
    MI_COUNT(CIM_MediaAccessDevice_LockMedia_params), /* numParameters */
    sizeof(CIM_MediaAccessDevice_LockMedia), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_MediaAccessDevice_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
    &CIM_LogicalDevice_SetPowerState_rtti,
    &CIM_LogicalDevice_Reset_rtti,
    &CIM_LogicalDevice_EnableDevice_rtti,
    &CIM_LogicalDevice_OnlineDevice_rtti,
    &CIM_LogicalDevice_QuiesceDevice_rtti,
    &CIM_LogicalDevice_SaveProperties_rtti,
    &CIM_LogicalDevice_RestoreProperties_rtti,
    &CIM_MediaAccessDevice_LockMedia_rtti,
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_UMLPackagePath_qual_value = MI_T("CIM::Device::StorageDevices");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_MediaAccessDevice_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_MediaAccessDevice_Version_qual_value = MI_T("2.6.0");

static MI_CONST MI_Qualifier CIM_MediaAccessDevice_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_MediaAccessDevice_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_MediaAccessDevice_quals[] =
{
    &CIM_MediaAccessDevice_UMLPackagePath_qual,
    &CIM_MediaAccessDevice_Version_qual,
};

/* class CIM_MediaAccessDevice */
MI_CONST MI_ClassDecl CIM_MediaAccessDevice_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00636515, /* code */
    MI_T("CIM_MediaAccessDevice"), /* name */
    CIM_MediaAccessDevice_quals, /* qualifiers */
    MI_COUNT(CIM_MediaAccessDevice_quals), /* numQualifiers */
    CIM_MediaAccessDevice_props, /* properties */
    MI_COUNT(CIM_MediaAccessDevice_props), /* numProperties */
    sizeof(CIM_MediaAccessDevice), /* size */
    MI_T("CIM_LogicalDevice"), /* superClass */
    &CIM_LogicalDevice_rtti, /* superClassDecl */
    CIM_MediaAccessDevice_meths, /* methods */
    MI_COUNT(CIM_MediaAccessDevice_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_DiskDrive
**
**==============================================================================
*/

static MI_PropertyDecl MI_CONST* MI_CONST CIM_DiskDrive_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ManagedSystemElement_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_LogicalDevice_SystemCreationClassName_prop,
    &CIM_LogicalDevice_SystemName_prop,
    &CIM_LogicalDevice_CreationClassName_prop,
    &CIM_LogicalDevice_DeviceID_prop,
    &CIM_LogicalDevice_PowerManagementSupported_prop,
    &CIM_LogicalDevice_PowerManagementCapabilities_prop,
    &CIM_LogicalDevice_Availability_prop,
    &CIM_LogicalDevice_StatusInfo_prop,
    &CIM_LogicalDevice_LastErrorCode_prop,
    &CIM_LogicalDevice_ErrorDescription_prop,
    &CIM_LogicalDevice_ErrorCleared_prop,
    &CIM_LogicalDevice_OtherIdentifyingInfo_prop,
    &CIM_LogicalDevice_PowerOnHours_prop,
    &CIM_LogicalDevice_TotalPowerOnHours_prop,
    &CIM_LogicalDevice_IdentifyingDescriptions_prop,
    &CIM_LogicalDevice_AdditionalAvailability_prop,
    &CIM_LogicalDevice_MaxQuiesceTime_prop,
    &CIM_MediaAccessDevice_Capabilities_prop,
    &CIM_MediaAccessDevice_CapabilityDescriptions_prop,
    &CIM_MediaAccessDevice_ErrorMethodology_prop,
    &CIM_MediaAccessDevice_CompressionMethod_prop,
    &CIM_MediaAccessDevice_NumberOfMediaSupported_prop,
    &CIM_MediaAccessDevice_MaxMediaSize_prop,
    &CIM_MediaAccessDevice_DefaultBlockSize_prop,
    &CIM_MediaAccessDevice_MaxBlockSize_prop,
    &CIM_MediaAccessDevice_MinBlockSize_prop,
    &CIM_MediaAccessDevice_NeedsCleaning_prop,
    &CIM_MediaAccessDevice_MediaIsLocked_prop,
    &CIM_MediaAccessDevice_Security_prop,
    &CIM_MediaAccessDevice_LastCleaned_prop,
    &CIM_MediaAccessDevice_MaxAccessTime_prop,
    &CIM_MediaAccessDevice_UncompressedDataRate_prop,
    &CIM_MediaAccessDevice_LoadTime_prop,
    &CIM_MediaAccessDevice_UnloadTime_prop,
    &CIM_MediaAccessDevice_MountCount_prop,
    &CIM_MediaAccessDevice_TimeOfLastMount_prop,
    &CIM_MediaAccessDevice_TotalMountTime_prop,
    &CIM_MediaAccessDevice_UnitsDescription_prop,
    &CIM_MediaAccessDevice_MaxUnitsBeforeCleaning_prop,
    &CIM_MediaAccessDevice_UnitsUsed_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_DiskDrive_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
    &CIM_LogicalDevice_SetPowerState_rtti,
    &CIM_LogicalDevice_Reset_rtti,
    &CIM_LogicalDevice_EnableDevice_rtti,
    &CIM_LogicalDevice_OnlineDevice_rtti,
    &CIM_LogicalDevice_QuiesceDevice_rtti,
    &CIM_LogicalDevice_SaveProperties_rtti,
    &CIM_LogicalDevice_RestoreProperties_rtti,
    &CIM_MediaAccessDevice_LockMedia_rtti,
};

static MI_CONST MI_Char* CIM_DiskDrive_UMLPackagePath_qual_value = MI_T("CIM::Device::StorageDevices");

static MI_CONST MI_Qualifier CIM_DiskDrive_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_DiskDrive_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_DiskDrive_Version_qual_value = MI_T("2.6.0");

static MI_CONST MI_Qualifier CIM_DiskDrive_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_DiskDrive_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_DiskDrive_quals[] =
{
    &CIM_DiskDrive_UMLPackagePath_qual,
    &CIM_DiskDrive_Version_qual,
};

/* class CIM_DiskDrive */
MI_CONST MI_ClassDecl CIM_DiskDrive_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0063650D, /* code */
    MI_T("CIM_DiskDrive"), /* name */
    CIM_DiskDrive_quals, /* qualifiers */
    MI_COUNT(CIM_DiskDrive_quals), /* numQualifiers */
    CIM_DiskDrive_props, /* properties */
    MI_COUNT(CIM_DiskDrive_props), /* numProperties */
    sizeof(CIM_DiskDrive), /* size */
    MI_T("CIM_MediaAccessDevice"), /* superClass */
    &CIM_MediaAccessDevice_rtti, /* superClassDecl */
    CIM_DiskDrive_meths, /* methods */
    MI_COUNT(CIM_DiskDrive_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_DiskDrive
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_DiskDrive_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_DiskDrive_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_DiskDrive_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_Caption_quals[] =
{
    &SCX_DiskDrive_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_DiskDrive_Caption_value = MI_T("Disk drive information");

/* property SCX_DiskDrive.Caption */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_DiskDrive_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    &SCX_DiskDrive_Caption_value,
};

static MI_CONST MI_Char* SCX_DiskDrive_Description_value = MI_T("Information pertaining to a physical unit of secondary storage");

/* property SCX_DiskDrive.Description */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    &SCX_DiskDrive_Description_value,
};

static MI_CONST MI_Uint32 SCX_DiskDrive_Name_MaxLen_qual_value = 1024U;

static MI_CONST MI_Qualifier SCX_DiskDrive_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_DiskDrive_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* SCX_DiskDrive_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier SCX_DiskDrive_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_Name_quals[] =
{
    &SCX_DiskDrive_Name_MaxLen_qual,
    &SCX_DiskDrive_Name_Override_qual,
};

/* property SCX_DiskDrive.Name */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_Name_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    SCX_DiskDrive_Name_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.IsOnline */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_IsOnline_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00696508, /* code */
    MI_T("IsOnline"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, IsOnline), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.InterfaceType */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_InterfaceType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069650D, /* code */
    MI_T("InterfaceType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, InterfaceType), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.Manufacturer */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_Manufacturer_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D720C, /* code */
    MI_T("Manufacturer"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, Manufacturer), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.Model */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_Model_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6C05, /* code */
    MI_T("Model"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, Model), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.TotalCylinders */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_TotalCylinders_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730E, /* code */
    MI_T("TotalCylinders"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, TotalCylinders), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.TotalHeads */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_TotalHeads_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730A, /* code */
    MI_T("TotalHeads"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, TotalHeads), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.TotalSectors */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_TotalSectors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730C, /* code */
    MI_T("TotalSectors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, TotalSectors), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.TotalTracks */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_TotalTracks_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730B, /* code */
    MI_T("TotalTracks"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, TotalTracks), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

/* property SCX_DiskDrive.TracksPerCylinder */
static MI_CONST MI_PropertyDecl SCX_DiskDrive_TracksPerCylinder_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00747211, /* code */
    MI_T("TracksPerCylinder"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive, TracksPerCylinder), /* offset */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_DiskDrive_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_DiskDrive_Caption_prop,
    &SCX_DiskDrive_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &SCX_DiskDrive_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_LogicalDevice_SystemCreationClassName_prop,
    &CIM_LogicalDevice_SystemName_prop,
    &CIM_LogicalDevice_CreationClassName_prop,
    &CIM_LogicalDevice_DeviceID_prop,
    &CIM_LogicalDevice_PowerManagementSupported_prop,
    &CIM_LogicalDevice_PowerManagementCapabilities_prop,
    &CIM_LogicalDevice_Availability_prop,
    &CIM_LogicalDevice_StatusInfo_prop,
    &CIM_LogicalDevice_LastErrorCode_prop,
    &CIM_LogicalDevice_ErrorDescription_prop,
    &CIM_LogicalDevice_ErrorCleared_prop,
    &CIM_LogicalDevice_OtherIdentifyingInfo_prop,
    &CIM_LogicalDevice_PowerOnHours_prop,
    &CIM_LogicalDevice_TotalPowerOnHours_prop,
    &CIM_LogicalDevice_IdentifyingDescriptions_prop,
    &CIM_LogicalDevice_AdditionalAvailability_prop,
    &CIM_LogicalDevice_MaxQuiesceTime_prop,
    &CIM_MediaAccessDevice_Capabilities_prop,
    &CIM_MediaAccessDevice_CapabilityDescriptions_prop,
    &CIM_MediaAccessDevice_ErrorMethodology_prop,
    &CIM_MediaAccessDevice_CompressionMethod_prop,
    &CIM_MediaAccessDevice_NumberOfMediaSupported_prop,
    &CIM_MediaAccessDevice_MaxMediaSize_prop,
    &CIM_MediaAccessDevice_DefaultBlockSize_prop,
    &CIM_MediaAccessDevice_MaxBlockSize_prop,
    &CIM_MediaAccessDevice_MinBlockSize_prop,
    &CIM_MediaAccessDevice_NeedsCleaning_prop,
    &CIM_MediaAccessDevice_MediaIsLocked_prop,
    &CIM_MediaAccessDevice_Security_prop,
    &CIM_MediaAccessDevice_LastCleaned_prop,
    &CIM_MediaAccessDevice_MaxAccessTime_prop,
    &CIM_MediaAccessDevice_UncompressedDataRate_prop,
    &CIM_MediaAccessDevice_LoadTime_prop,
    &CIM_MediaAccessDevice_UnloadTime_prop,
    &CIM_MediaAccessDevice_MountCount_prop,
    &CIM_MediaAccessDevice_TimeOfLastMount_prop,
    &CIM_MediaAccessDevice_TotalMountTime_prop,
    &CIM_MediaAccessDevice_UnitsDescription_prop,
    &CIM_MediaAccessDevice_MaxUnitsBeforeCleaning_prop,
    &CIM_MediaAccessDevice_UnitsUsed_prop,
    &SCX_DiskDrive_IsOnline_prop,
    &SCX_DiskDrive_InterfaceType_prop,
    &SCX_DiskDrive_Manufacturer_prop,
    &SCX_DiskDrive_Model_prop,
    &SCX_DiskDrive_TotalCylinders_prop,
    &SCX_DiskDrive_TotalHeads_prop,
    &SCX_DiskDrive_TotalSectors_prop,
    &SCX_DiskDrive_TotalTracks_prop,
    &SCX_DiskDrive_TracksPerCylinder_prop,
};

/* parameter SCX_DiskDrive.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_RequestStateChange, RequestedState), /* offset */
};

/* parameter SCX_DiskDrive.RequestStateChange(): Job */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_RequestStateChange_Job_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006A6203, /* code */
    MI_T("Job"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REFERENCE, /* type */
    MI_T("CIM_ConcreteJob"), /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_RequestStateChange, Job), /* offset */
};

/* parameter SCX_DiskDrive.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter SCX_DiskDrive.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_RequestStateChange_params[] =
{
    &SCX_DiskDrive_RequestStateChange_MIReturn_param,
    &SCX_DiskDrive_RequestStateChange_RequestedState_param,
    &SCX_DiskDrive_RequestStateChange_Job_param,
    &SCX_DiskDrive_RequestStateChange_TimeoutPeriod_param,
};

/* method SCX_DiskDrive.RequestStateChange() */
MI_CONST MI_MethodDecl SCX_DiskDrive_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_DiskDrive_RequestStateChange_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_RequestStateChange_params), /* numParameters */
    sizeof(SCX_DiskDrive_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_RequestStateChange, /* method */
};

static MI_CONST MI_Char* SCX_DiskDrive_SetPowerState_Deprecated_qual_data_value[] =
{
    MI_T("CIM_PowerManagementService.SetPowerState"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_SetPowerState_Deprecated_qual_value =
{
    SCX_DiskDrive_SetPowerState_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_SetPowerState_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_SetPowerState_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_SetPowerState_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_SetPowerState_quals[] =
{
    &SCX_DiskDrive_SetPowerState_Deprecated_qual,
};

/* parameter SCX_DiskDrive.SetPowerState(): PowerState */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_SetPowerState_PowerState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0070650A, /* code */
    MI_T("PowerState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_SetPowerState, PowerState), /* offset */
};

/* parameter SCX_DiskDrive.SetPowerState(): Time */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_SetPowerState_Time_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00746504, /* code */
    MI_T("Time"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_SetPowerState, Time), /* offset */
};

static MI_CONST MI_Char* SCX_DiskDrive_SetPowerState_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_PowerManagementService.SetPowerState"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_SetPowerState_MIReturn_Deprecated_qual_value =
{
    SCX_DiskDrive_SetPowerState_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_SetPowerState_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_SetPowerState_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_SetPowerState_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_SetPowerState_MIReturn_quals[] =
{
    &SCX_DiskDrive_SetPowerState_MIReturn_Deprecated_qual,
};

/* parameter SCX_DiskDrive.SetPowerState(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_SetPowerState_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    SCX_DiskDrive_SetPowerState_MIReturn_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_SetPowerState_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_SetPowerState, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_SetPowerState_params[] =
{
    &SCX_DiskDrive_SetPowerState_MIReturn_param,
    &SCX_DiskDrive_SetPowerState_PowerState_param,
    &SCX_DiskDrive_SetPowerState_Time_param,
};

/* method SCX_DiskDrive.SetPowerState() */
MI_CONST MI_MethodDecl SCX_DiskDrive_SetPowerState_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0073650D, /* code */
    MI_T("SetPowerState"), /* name */
    SCX_DiskDrive_SetPowerState_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_SetPowerState_quals), /* numQualifiers */
    SCX_DiskDrive_SetPowerState_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_SetPowerState_params), /* numParameters */
    sizeof(SCX_DiskDrive_SetPowerState), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_SetPowerState, /* method */
};

/* parameter SCX_DiskDrive.Reset(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_Reset_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_Reset, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_Reset_params[] =
{
    &SCX_DiskDrive_Reset_MIReturn_param,
};

/* method SCX_DiskDrive.Reset() */
MI_CONST MI_MethodDecl SCX_DiskDrive_Reset_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727405, /* code */
    MI_T("Reset"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_DiskDrive_Reset_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_Reset_params), /* numParameters */
    sizeof(SCX_DiskDrive_Reset), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_Reset, /* method */
};

static MI_CONST MI_Char* SCX_DiskDrive_EnableDevice_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_EnableDevice_Deprecated_qual_value =
{
    SCX_DiskDrive_EnableDevice_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_EnableDevice_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_EnableDevice_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_EnableDevice_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_EnableDevice_quals[] =
{
    &SCX_DiskDrive_EnableDevice_Deprecated_qual,
};

/* parameter SCX_DiskDrive.EnableDevice(): Enabled */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_EnableDevice_Enabled_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00656407, /* code */
    MI_T("Enabled"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_EnableDevice, Enabled), /* offset */
};

static MI_CONST MI_Char* SCX_DiskDrive_EnableDevice_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_EnableDevice_MIReturn_Deprecated_qual_value =
{
    SCX_DiskDrive_EnableDevice_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_EnableDevice_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_EnableDevice_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_EnableDevice_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_EnableDevice_MIReturn_quals[] =
{
    &SCX_DiskDrive_EnableDevice_MIReturn_Deprecated_qual,
};

/* parameter SCX_DiskDrive.EnableDevice(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_EnableDevice_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    SCX_DiskDrive_EnableDevice_MIReturn_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_EnableDevice_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_EnableDevice, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_EnableDevice_params[] =
{
    &SCX_DiskDrive_EnableDevice_MIReturn_param,
    &SCX_DiskDrive_EnableDevice_Enabled_param,
};

/* method SCX_DiskDrive.EnableDevice() */
MI_CONST MI_MethodDecl SCX_DiskDrive_EnableDevice_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0065650C, /* code */
    MI_T("EnableDevice"), /* name */
    SCX_DiskDrive_EnableDevice_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_EnableDevice_quals), /* numQualifiers */
    SCX_DiskDrive_EnableDevice_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_EnableDevice_params), /* numParameters */
    sizeof(SCX_DiskDrive_EnableDevice), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_EnableDevice, /* method */
};

static MI_CONST MI_Char* SCX_DiskDrive_OnlineDevice_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_OnlineDevice_Deprecated_qual_value =
{
    SCX_DiskDrive_OnlineDevice_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_OnlineDevice_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_OnlineDevice_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_OnlineDevice_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_OnlineDevice_quals[] =
{
    &SCX_DiskDrive_OnlineDevice_Deprecated_qual,
};

/* parameter SCX_DiskDrive.OnlineDevice(): Online */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_OnlineDevice_Online_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x006F6506, /* code */
    MI_T("Online"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_OnlineDevice, Online), /* offset */
};

static MI_CONST MI_Char* SCX_DiskDrive_OnlineDevice_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_OnlineDevice_MIReturn_Deprecated_qual_value =
{
    SCX_DiskDrive_OnlineDevice_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_OnlineDevice_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_OnlineDevice_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_OnlineDevice_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_OnlineDevice_MIReturn_quals[] =
{
    &SCX_DiskDrive_OnlineDevice_MIReturn_Deprecated_qual,
};

/* parameter SCX_DiskDrive.OnlineDevice(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_OnlineDevice_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    SCX_DiskDrive_OnlineDevice_MIReturn_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_OnlineDevice_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_OnlineDevice, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_OnlineDevice_params[] =
{
    &SCX_DiskDrive_OnlineDevice_MIReturn_param,
    &SCX_DiskDrive_OnlineDevice_Online_param,
};

/* method SCX_DiskDrive.OnlineDevice() */
MI_CONST MI_MethodDecl SCX_DiskDrive_OnlineDevice_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x006F650C, /* code */
    MI_T("OnlineDevice"), /* name */
    SCX_DiskDrive_OnlineDevice_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_OnlineDevice_quals), /* numQualifiers */
    SCX_DiskDrive_OnlineDevice_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_OnlineDevice_params), /* numParameters */
    sizeof(SCX_DiskDrive_OnlineDevice), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_OnlineDevice, /* method */
};

static MI_CONST MI_Char* SCX_DiskDrive_QuiesceDevice_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_QuiesceDevice_Deprecated_qual_value =
{
    SCX_DiskDrive_QuiesceDevice_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_QuiesceDevice_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_QuiesceDevice_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_QuiesceDevice_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_QuiesceDevice_quals[] =
{
    &SCX_DiskDrive_QuiesceDevice_Deprecated_qual,
};

/* parameter SCX_DiskDrive.QuiesceDevice(): Quiesce */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_QuiesceDevice_Quiesce_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00716507, /* code */
    MI_T("Quiesce"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_QuiesceDevice, Quiesce), /* offset */
};

static MI_CONST MI_Char* SCX_DiskDrive_QuiesceDevice_MIReturn_Deprecated_qual_data_value[] =
{
    MI_T("CIM_EnabledLogicalElement.RequestStateChange"),
};

static MI_CONST MI_ConstStringA SCX_DiskDrive_QuiesceDevice_MIReturn_Deprecated_qual_value =
{
    SCX_DiskDrive_QuiesceDevice_MIReturn_Deprecated_qual_data_value,
    MI_COUNT(SCX_DiskDrive_QuiesceDevice_MIReturn_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier SCX_DiskDrive_QuiesceDevice_MIReturn_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_QuiesceDevice_MIReturn_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_QuiesceDevice_MIReturn_quals[] =
{
    &SCX_DiskDrive_QuiesceDevice_MIReturn_Deprecated_qual,
};

/* parameter SCX_DiskDrive.QuiesceDevice(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_QuiesceDevice_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    SCX_DiskDrive_QuiesceDevice_MIReturn_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_QuiesceDevice_MIReturn_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_QuiesceDevice, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_QuiesceDevice_params[] =
{
    &SCX_DiskDrive_QuiesceDevice_MIReturn_param,
    &SCX_DiskDrive_QuiesceDevice_Quiesce_param,
};

/* method SCX_DiskDrive.QuiesceDevice() */
MI_CONST MI_MethodDecl SCX_DiskDrive_QuiesceDevice_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0071650D, /* code */
    MI_T("QuiesceDevice"), /* name */
    SCX_DiskDrive_QuiesceDevice_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_QuiesceDevice_quals), /* numQualifiers */
    SCX_DiskDrive_QuiesceDevice_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_QuiesceDevice_params), /* numParameters */
    sizeof(SCX_DiskDrive_QuiesceDevice), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_QuiesceDevice, /* method */
};

/* parameter SCX_DiskDrive.SaveProperties(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_SaveProperties_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_SaveProperties, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_SaveProperties_params[] =
{
    &SCX_DiskDrive_SaveProperties_MIReturn_param,
};

/* method SCX_DiskDrive.SaveProperties() */
MI_CONST MI_MethodDecl SCX_DiskDrive_SaveProperties_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x0073730E, /* code */
    MI_T("SaveProperties"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_DiskDrive_SaveProperties_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_SaveProperties_params), /* numParameters */
    sizeof(SCX_DiskDrive_SaveProperties), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_SaveProperties, /* method */
};

/* parameter SCX_DiskDrive.RestoreProperties(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_RestoreProperties_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_RestoreProperties, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_RestoreProperties_params[] =
{
    &SCX_DiskDrive_RestoreProperties_MIReturn_param,
};

/* method SCX_DiskDrive.RestoreProperties() */
MI_CONST MI_MethodDecl SCX_DiskDrive_RestoreProperties_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727311, /* code */
    MI_T("RestoreProperties"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_DiskDrive_RestoreProperties_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_RestoreProperties_params), /* numParameters */
    sizeof(SCX_DiskDrive_RestoreProperties), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_LogicalDevice"), /* origin */
    MI_T("CIM_LogicalDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_RestoreProperties, /* method */
};

/* parameter SCX_DiskDrive.LockMedia(): Lock */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_LockMedia_Lock_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x006C6B04, /* code */
    MI_T("Lock"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_LockMedia, Lock), /* offset */
};

/* parameter SCX_DiskDrive.LockMedia(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_LockMedia_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_LockMedia, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_LockMedia_params[] =
{
    &SCX_DiskDrive_LockMedia_MIReturn_param,
    &SCX_DiskDrive_LockMedia_Lock_param,
};

/* method SCX_DiskDrive.LockMedia() */
MI_CONST MI_MethodDecl SCX_DiskDrive_LockMedia_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x006C6109, /* code */
    MI_T("LockMedia"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_DiskDrive_LockMedia_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_LockMedia_params), /* numParameters */
    sizeof(SCX_DiskDrive_LockMedia), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_MediaAccessDevice"), /* origin */
    MI_T("CIM_MediaAccessDevice"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_LockMedia, /* method */
};

/* parameter SCX_DiskDrive.RemoveByName(): Name */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_RemoveByName_Name_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_RemoveByName, Name), /* offset */
};

/* parameter SCX_DiskDrive.RemoveByName(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_DiskDrive_RemoveByName_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDrive_RemoveByName, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_DiskDrive_RemoveByName_params[] =
{
    &SCX_DiskDrive_RemoveByName_MIReturn_param,
    &SCX_DiskDrive_RemoveByName_Name_param,
};

/* method SCX_DiskDrive.RemoveByName() */
MI_CONST MI_MethodDecl SCX_DiskDrive_RemoveByName_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x0072650C, /* code */
    MI_T("RemoveByName"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_DiskDrive_RemoveByName_params, /* parameters */
    MI_COUNT(SCX_DiskDrive_RemoveByName_params), /* numParameters */
    sizeof(SCX_DiskDrive_RemoveByName), /* size */
    MI_BOOLEAN, /* returnType */
    MI_T("SCX_DiskDrive"), /* origin */
    MI_T("SCX_DiskDrive"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_DiskDrive_Invoke_RemoveByName, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_DiskDrive_meths[] =
{
    &SCX_DiskDrive_RequestStateChange_rtti,
    &SCX_DiskDrive_SetPowerState_rtti,
    &SCX_DiskDrive_Reset_rtti,
    &SCX_DiskDrive_EnableDevice_rtti,
    &SCX_DiskDrive_OnlineDevice_rtti,
    &SCX_DiskDrive_QuiesceDevice_rtti,
    &SCX_DiskDrive_SaveProperties_rtti,
    &SCX_DiskDrive_RestoreProperties_rtti,
    &SCX_DiskDrive_LockMedia_rtti,
    &SCX_DiskDrive_RemoveByName_rtti,
};

static MI_CONST MI_ProviderFT SCX_DiskDrive_funcs =
{
  (MI_ProviderFT_Load)SCX_DiskDrive_Load,
  (MI_ProviderFT_Unload)SCX_DiskDrive_Unload,
  (MI_ProviderFT_GetInstance)SCX_DiskDrive_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_DiskDrive_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_DiskDrive_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_DiskDrive_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_DiskDrive_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_DiskDrive_UMLPackagePath_qual_value = MI_T("CIM::Device::StorageDevices");

static MI_CONST MI_Qualifier SCX_DiskDrive_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_DiskDrive_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_DiskDrive_Version_qual_value = MI_T("1.3.1");

static MI_CONST MI_Qualifier SCX_DiskDrive_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_DiskDrive_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDrive_quals[] =
{
    &SCX_DiskDrive_UMLPackagePath_qual,
    &SCX_DiskDrive_Version_qual,
};

/* class SCX_DiskDrive */
MI_CONST MI_ClassDecl SCX_DiskDrive_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0073650D, /* code */
    MI_T("SCX_DiskDrive"), /* name */
    SCX_DiskDrive_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDrive_quals), /* numQualifiers */
    SCX_DiskDrive_props, /* properties */
    MI_COUNT(SCX_DiskDrive_props), /* numProperties */
    sizeof(SCX_DiskDrive), /* size */
    MI_T("CIM_DiskDrive"), /* superClass */
    &CIM_DiskDrive_rtti, /* superClassDecl */
    SCX_DiskDrive_meths, /* methods */
    MI_COUNT(SCX_DiskDrive_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_DiskDrive_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_StatisticalInformation
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_StatisticalInformation_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_StatisticalInformation_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_StatisticalInformation_Name_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_StatisticalInformation_Name_quals[] =
{
    &CIM_StatisticalInformation_Name_MaxLen_qual,
};

/* property CIM_StatisticalInformation.Name */
static MI_CONST MI_PropertyDecl CIM_StatisticalInformation_Name_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_StatisticalInformation_Name_quals, /* qualifiers */
    MI_COUNT(CIM_StatisticalInformation_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalInformation, Name), /* offset */
    MI_T("CIM_StatisticalInformation"), /* origin */
    MI_T("CIM_StatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_StatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_StatisticalInformation_Name_prop,
};

static MI_CONST MI_Char* CIM_StatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::Core::Statistics");

static MI_CONST MI_Qualifier CIM_StatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_StatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_StatisticalInformation_Version_qual_value = MI_T("2.6.0");

static MI_CONST MI_Qualifier CIM_StatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_StatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_StatisticalInformation_quals[] =
{
    &CIM_StatisticalInformation_UMLPackagePath_qual,
    &CIM_StatisticalInformation_Version_qual,
};

/* class CIM_StatisticalInformation */
MI_CONST MI_ClassDecl CIM_StatisticalInformation_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00636E1A, /* code */
    MI_T("CIM_StatisticalInformation"), /* name */
    CIM_StatisticalInformation_quals, /* qualifiers */
    MI_COUNT(CIM_StatisticalInformation_quals), /* numQualifiers */
    CIM_StatisticalInformation_props, /* properties */
    MI_COUNT(CIM_StatisticalInformation_props), /* numProperties */
    sizeof(CIM_StatisticalInformation), /* size */
    MI_T("CIM_ManagedElement"), /* superClass */
    &CIM_ManagedElement_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_StatisticalInformation
**
**==============================================================================
*/

/* property SCX_StatisticalInformation.IsAggregate */
static MI_CONST MI_PropertyDecl SCX_StatisticalInformation_IsAggregate_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069650B, /* code */
    MI_T("IsAggregate"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_StatisticalInformation, IsAggregate), /* offset */
    MI_T("SCX_StatisticalInformation"), /* origin */
    MI_T("SCX_StatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_StatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_StatisticalInformation_Name_prop,
    &SCX_StatisticalInformation_IsAggregate_prop,
};

static MI_CONST MI_Char* SCX_StatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::Core::Statistics");

static MI_CONST MI_Qualifier SCX_StatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_StatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_StatisticalInformation_Version_qual_value = MI_T("1.3.0");

static MI_CONST MI_Qualifier SCX_StatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_StatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_StatisticalInformation_quals[] =
{
    &SCX_StatisticalInformation_UMLPackagePath_qual,
    &SCX_StatisticalInformation_Version_qual,
};

/* class SCX_StatisticalInformation */
MI_CONST MI_ClassDecl SCX_StatisticalInformation_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736E1A, /* code */
    MI_T("SCX_StatisticalInformation"), /* name */
    SCX_StatisticalInformation_quals, /* qualifiers */
    MI_COUNT(SCX_StatisticalInformation_quals), /* numQualifiers */
    SCX_StatisticalInformation_props, /* properties */
    MI_COUNT(SCX_StatisticalInformation_props), /* numProperties */
    sizeof(SCX_StatisticalInformation), /* size */
    MI_T("CIM_StatisticalInformation"), /* superClass */
    &CIM_StatisticalInformation_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_DiskDriveStatisticalInformation
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_DiskDriveStatisticalInformation_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_DiskDriveStatisticalInformation_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_Caption_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_Caption_value = MI_T("Disk drive information");

/* property SCX_DiskDriveStatisticalInformation.Caption */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_DiskDriveStatisticalInformation_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    &SCX_DiskDriveStatisticalInformation_Caption_value,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_Description_value = MI_T("Performance statistics related to a physical unit of secondary storage");

/* property SCX_DiskDriveStatisticalInformation.Description */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    &SCX_DiskDriveStatisticalInformation_Description_value,
};

static MI_CONST MI_Uint32 SCX_DiskDriveStatisticalInformation_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_DiskDriveStatisticalInformation_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_DiskDriveStatisticalInformation_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_Name_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_Name_MaxLen_qual,
    &SCX_DiskDriveStatisticalInformation_Name_Override_qual,
};

/* property SCX_DiskDriveStatisticalInformation.Name */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    SCX_DiskDriveStatisticalInformation_Name_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, Name), /* offset */
    MI_T("CIM_StatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

/* property SCX_DiskDriveStatisticalInformation.IsOnline */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_IsOnline_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00696508, /* code */
    MI_T("IsOnline"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, IsOnline), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_PercentBusyTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_PercentBusyTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_PercentBusyTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_PercentBusyTime_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_PercentBusyTime_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.PercentBusyTime */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_PercentBusyTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentBusyTime"), /* name */
    SCX_DiskDriveStatisticalInformation_PercentBusyTime_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_PercentBusyTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, PercentBusyTime), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_PercentIdleTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_PercentIdleTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_PercentIdleTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_PercentIdleTime_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_PercentIdleTime_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.PercentIdleTime */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_PercentIdleTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentIdleTime"), /* name */
    SCX_DiskDriveStatisticalInformation_PercentIdleTime_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_PercentIdleTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, PercentIdleTime), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_BytesPerSecond_Units_qual_value = MI_T("Bytes per Second");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_BytesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_BytesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_BytesPerSecond_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_BytesPerSecond_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.BytesPerSecond */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_BytesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0062640E, /* code */
    MI_T("BytesPerSecond"), /* name */
    SCX_DiskDriveStatisticalInformation_BytesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_BytesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, BytesPerSecond), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_Units_qual_value = MI_T("Bytes per Second");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.ReadBytesPerSecond */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726412, /* code */
    MI_T("ReadBytesPerSecond"), /* name */
    SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, ReadBytesPerSecond), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_Units_qual_value = MI_T("Bytes per Second");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.WriteBytesPerSecond */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00776413, /* code */
    MI_T("WriteBytesPerSecond"), /* name */
    SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, WriteBytesPerSecond), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_TransfersPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_TransfersPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_TransfersPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_TransfersPerSecond_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_TransfersPerSecond_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.TransfersPerSecond */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_TransfersPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746412, /* code */
    MI_T("TransfersPerSecond"), /* name */
    SCX_DiskDriveStatisticalInformation_TransfersPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_TransfersPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, TransfersPerSecond), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_ReadsPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_ReadsPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_ReadsPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_ReadsPerSecond_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_ReadsPerSecond_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.ReadsPerSecond */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_ReadsPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0072640E, /* code */
    MI_T("ReadsPerSecond"), /* name */
    SCX_DiskDriveStatisticalInformation_ReadsPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_ReadsPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, ReadsPerSecond), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_WritesPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_WritesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_WritesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_WritesPerSecond_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_WritesPerSecond_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.WritesPerSecond */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_WritesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0077640F, /* code */
    MI_T("WritesPerSecond"), /* name */
    SCX_DiskDriveStatisticalInformation_WritesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_WritesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, WritesPerSecond), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_AverageReadTime_Units_qual_value = MI_T("Seconds");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_AverageReadTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_AverageReadTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_AverageReadTime_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_AverageReadTime_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.AverageReadTime */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_AverageReadTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061650F, /* code */
    MI_T("AverageReadTime"), /* name */
    SCX_DiskDriveStatisticalInformation_AverageReadTime_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_AverageReadTime_quals), /* numQualifiers */
    MI_REAL64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, AverageReadTime), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_AverageWriteTime_Units_qual_value = MI_T("Seconds");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_AverageWriteTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_AverageWriteTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_AverageWriteTime_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_AverageWriteTime_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.AverageWriteTime */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_AverageWriteTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00616510, /* code */
    MI_T("AverageWriteTime"), /* name */
    SCX_DiskDriveStatisticalInformation_AverageWriteTime_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_AverageWriteTime_quals), /* numQualifiers */
    MI_REAL64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, AverageWriteTime), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_AverageTransferTime_Units_qual_value = MI_T("Seconds");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_AverageTransferTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_DiskDriveStatisticalInformation_AverageTransferTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_AverageTransferTime_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_AverageTransferTime_Units_qual,
};

/* property SCX_DiskDriveStatisticalInformation.AverageTransferTime */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_AverageTransferTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00616513, /* code */
    MI_T("AverageTransferTime"), /* name */
    SCX_DiskDriveStatisticalInformation_AverageTransferTime_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_AverageTransferTime_quals), /* numQualifiers */
    MI_REAL64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, AverageTransferTime), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

/* property SCX_DiskDriveStatisticalInformation.AverageDiskQueueLength */
static MI_CONST MI_PropertyDecl SCX_DiskDriveStatisticalInformation_AverageDiskQueueLength_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00616816, /* code */
    MI_T("AverageDiskQueueLength"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REAL64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_DiskDriveStatisticalInformation, AverageDiskQueueLength), /* offset */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* origin */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_DiskDriveStatisticalInformation_Caption_prop,
    &SCX_DiskDriveStatisticalInformation_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &SCX_DiskDriveStatisticalInformation_Name_prop,
    &SCX_StatisticalInformation_IsAggregate_prop,
    &SCX_DiskDriveStatisticalInformation_IsOnline_prop,
    &SCX_DiskDriveStatisticalInformation_PercentBusyTime_prop,
    &SCX_DiskDriveStatisticalInformation_PercentIdleTime_prop,
    &SCX_DiskDriveStatisticalInformation_BytesPerSecond_prop,
    &SCX_DiskDriveStatisticalInformation_ReadBytesPerSecond_prop,
    &SCX_DiskDriveStatisticalInformation_WriteBytesPerSecond_prop,
    &SCX_DiskDriveStatisticalInformation_TransfersPerSecond_prop,
    &SCX_DiskDriveStatisticalInformation_ReadsPerSecond_prop,
    &SCX_DiskDriveStatisticalInformation_WritesPerSecond_prop,
    &SCX_DiskDriveStatisticalInformation_AverageReadTime_prop,
    &SCX_DiskDriveStatisticalInformation_AverageWriteTime_prop,
    &SCX_DiskDriveStatisticalInformation_AverageTransferTime_prop,
    &SCX_DiskDriveStatisticalInformation_AverageDiskQueueLength_prop,
};

static MI_CONST MI_ProviderFT SCX_DiskDriveStatisticalInformation_funcs =
{
  (MI_ProviderFT_Load)SCX_DiskDriveStatisticalInformation_Load,
  (MI_ProviderFT_Unload)SCX_DiskDriveStatisticalInformation_Unload,
  (MI_ProviderFT_GetInstance)SCX_DiskDriveStatisticalInformation_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_DiskDriveStatisticalInformation_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_DiskDriveStatisticalInformation_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_DiskDriveStatisticalInformation_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_DiskDriveStatisticalInformation_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::Core::Statistics");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_DiskDriveStatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_DiskDriveStatisticalInformation_Version_qual_value = MI_T("1.3.4");

static MI_CONST MI_Qualifier SCX_DiskDriveStatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_DiskDriveStatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_DiskDriveStatisticalInformation_quals[] =
{
    &SCX_DiskDriveStatisticalInformation_UMLPackagePath_qual,
    &SCX_DiskDriveStatisticalInformation_Version_qual,
};

/* class SCX_DiskDriveStatisticalInformation */
MI_CONST MI_ClassDecl SCX_DiskDriveStatisticalInformation_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736E23, /* code */
    MI_T("SCX_DiskDriveStatisticalInformation"), /* name */
    SCX_DiskDriveStatisticalInformation_quals, /* qualifiers */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_quals), /* numQualifiers */
    SCX_DiskDriveStatisticalInformation_props, /* properties */
    MI_COUNT(SCX_DiskDriveStatisticalInformation_props), /* numProperties */
    sizeof(SCX_DiskDriveStatisticalInformation), /* size */
    MI_T("SCX_StatisticalInformation"), /* superClass */
    &SCX_StatisticalInformation_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &SCX_DiskDriveStatisticalInformation_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_FileSystem
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_FileSystem_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_FileSystem_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_FileSystem_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_FileSystem_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_FileSystem_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_FileSystem_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_Name_quals[] =
{
    &CIM_FileSystem_Name_MaxLen_qual,
    &CIM_FileSystem_Name_Override_qual,
};

/* property CIM_FileSystem.Name */
static MI_CONST MI_PropertyDecl CIM_FileSystem_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_FileSystem_Name_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_FileSystem_CSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_FileSystem_CSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_FileSystem_CSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_FileSystem_CSCreationClassName_Propagated_qual_value = MI_T("CIM_System.CreationClassName");

static MI_CONST MI_Qualifier CIM_FileSystem_CSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_FileSystem_CSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_CSCreationClassName_quals[] =
{
    &CIM_FileSystem_CSCreationClassName_MaxLen_qual,
    &CIM_FileSystem_CSCreationClassName_Propagated_qual,
};

/* property CIM_FileSystem.CSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_FileSystem_CSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636513, /* code */
    MI_T("CSCreationClassName"), /* name */
    CIM_FileSystem_CSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_CSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, CSCreationClassName), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_FileSystem_CSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_FileSystem_CSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_FileSystem_CSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_FileSystem_CSName_Propagated_qual_value = MI_T("CIM_System.Name");

static MI_CONST MI_Qualifier CIM_FileSystem_CSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_FileSystem_CSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_CSName_quals[] =
{
    &CIM_FileSystem_CSName_MaxLen_qual,
    &CIM_FileSystem_CSName_Propagated_qual,
};

/* property CIM_FileSystem.CSName */
static MI_CONST MI_PropertyDecl CIM_FileSystem_CSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636506, /* code */
    MI_T("CSName"), /* name */
    CIM_FileSystem_CSName_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_CSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, CSName), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_FileSystem_CreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_FileSystem_CreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_FileSystem_CreationClassName_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_CreationClassName_quals[] =
{
    &CIM_FileSystem_CreationClassName_MaxLen_qual,
};

/* property CIM_FileSystem.CreationClassName */
static MI_CONST MI_PropertyDecl CIM_FileSystem_CreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636511, /* code */
    MI_T("CreationClassName"), /* name */
    CIM_FileSystem_CreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_CreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, CreationClassName), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.Root */
static MI_CONST MI_PropertyDecl CIM_FileSystem_Root_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00727404, /* code */
    MI_T("Root"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, Root), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_FileSystem_BlockSize_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_FileSystem_BlockSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_FileSystem_BlockSize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_BlockSize_quals[] =
{
    &CIM_FileSystem_BlockSize_Units_qual,
};

/* property CIM_FileSystem.BlockSize */
static MI_CONST MI_PropertyDecl CIM_FileSystem_BlockSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00626509, /* code */
    MI_T("BlockSize"), /* name */
    CIM_FileSystem_BlockSize_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_BlockSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, BlockSize), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_FileSystem_FileSystemSize_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_FileSystem_FileSystemSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_FileSystem_FileSystemSize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_FileSystemSize_quals[] =
{
    &CIM_FileSystem_FileSystemSize_Units_qual,
};

/* property CIM_FileSystem.FileSystemSize */
static MI_CONST MI_PropertyDecl CIM_FileSystem_FileSystemSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0066650E, /* code */
    MI_T("FileSystemSize"), /* name */
    CIM_FileSystem_FileSystemSize_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_FileSystemSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, FileSystemSize), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_FileSystem_AvailableSpace_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_FileSystem_AvailableSpace_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_FileSystem_AvailableSpace_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_AvailableSpace_quals[] =
{
    &CIM_FileSystem_AvailableSpace_Units_qual,
};

/* property CIM_FileSystem.AvailableSpace */
static MI_CONST MI_PropertyDecl CIM_FileSystem_AvailableSpace_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061650E, /* code */
    MI_T("AvailableSpace"), /* name */
    CIM_FileSystem_AvailableSpace_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_AvailableSpace_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, AvailableSpace), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.ReadOnly */
static MI_CONST MI_PropertyDecl CIM_FileSystem_ReadOnly_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00727908, /* code */
    MI_T("ReadOnly"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, ReadOnly), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.EncryptionMethod */
static MI_CONST MI_PropertyDecl CIM_FileSystem_EncryptionMethod_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00656410, /* code */
    MI_T("EncryptionMethod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, EncryptionMethod), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.CompressionMethod */
static MI_CONST MI_PropertyDecl CIM_FileSystem_CompressionMethod_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636411, /* code */
    MI_T("CompressionMethod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, CompressionMethod), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.CaseSensitive */
static MI_CONST MI_PropertyDecl CIM_FileSystem_CaseSensitive_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063650D, /* code */
    MI_T("CaseSensitive"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, CaseSensitive), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.CasePreserved */
static MI_CONST MI_PropertyDecl CIM_FileSystem_CasePreserved_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063640D, /* code */
    MI_T("CasePreserved"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, CasePreserved), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.CodeSet */
static MI_CONST MI_PropertyDecl CIM_FileSystem_CodeSet_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00637407, /* code */
    MI_T("CodeSet"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16A, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, CodeSet), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.MaxFileNameLength */
static MI_CONST MI_PropertyDecl CIM_FileSystem_MaxFileNameLength_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6811, /* code */
    MI_T("MaxFileNameLength"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, MaxFileNameLength), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.ClusterSize */
static MI_CONST MI_PropertyDecl CIM_FileSystem_ClusterSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063650B, /* code */
    MI_T("ClusterSize"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, ClusterSize), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.FileSystemType */
static MI_CONST MI_PropertyDecl CIM_FileSystem_FileSystemType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0066650E, /* code */
    MI_T("FileSystemType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, FileSystemType), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.PersistenceType */
static MI_CONST MI_PropertyDecl CIM_FileSystem_PersistenceType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PersistenceType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, PersistenceType), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.OtherPersistenceType */
static MI_CONST MI_PropertyDecl CIM_FileSystem_OtherPersistenceType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6514, /* code */
    MI_T("OtherPersistenceType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, OtherPersistenceType), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

/* property CIM_FileSystem.NumberOfFiles */
static MI_CONST MI_PropertyDecl CIM_FileSystem_NumberOfFiles_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E730D, /* code */
    MI_T("NumberOfFiles"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_FileSystem, NumberOfFiles), /* offset */
    MI_T("CIM_FileSystem"), /* origin */
    MI_T("CIM_FileSystem"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_FileSystem_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_FileSystem_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_FileSystem_CSCreationClassName_prop,
    &CIM_FileSystem_CSName_prop,
    &CIM_FileSystem_CreationClassName_prop,
    &CIM_FileSystem_Root_prop,
    &CIM_FileSystem_BlockSize_prop,
    &CIM_FileSystem_FileSystemSize_prop,
    &CIM_FileSystem_AvailableSpace_prop,
    &CIM_FileSystem_ReadOnly_prop,
    &CIM_FileSystem_EncryptionMethod_prop,
    &CIM_FileSystem_CompressionMethod_prop,
    &CIM_FileSystem_CaseSensitive_prop,
    &CIM_FileSystem_CasePreserved_prop,
    &CIM_FileSystem_CodeSet_prop,
    &CIM_FileSystem_MaxFileNameLength_prop,
    &CIM_FileSystem_ClusterSize_prop,
    &CIM_FileSystem_FileSystemType_prop,
    &CIM_FileSystem_PersistenceType_prop,
    &CIM_FileSystem_OtherPersistenceType_prop,
    &CIM_FileSystem_NumberOfFiles_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_FileSystem_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_FileSystem_UMLPackagePath_qual_value = MI_T("CIM::System::FileElements");

static MI_CONST MI_Qualifier CIM_FileSystem_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_FileSystem_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_FileSystem_Version_qual_value = MI_T("2.7.0");

static MI_CONST MI_Qualifier CIM_FileSystem_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_FileSystem_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_FileSystem_quals[] =
{
    &CIM_FileSystem_UMLPackagePath_qual,
    &CIM_FileSystem_Version_qual,
};

/* class CIM_FileSystem */
MI_CONST MI_ClassDecl CIM_FileSystem_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00636D0E, /* code */
    MI_T("CIM_FileSystem"), /* name */
    CIM_FileSystem_quals, /* qualifiers */
    MI_COUNT(CIM_FileSystem_quals), /* numQualifiers */
    CIM_FileSystem_props, /* properties */
    MI_COUNT(CIM_FileSystem_props), /* numProperties */
    sizeof(CIM_FileSystem), /* size */
    MI_T("CIM_EnabledLogicalElement"), /* superClass */
    &CIM_EnabledLogicalElement_rtti, /* superClassDecl */
    CIM_FileSystem_meths, /* methods */
    MI_COUNT(CIM_FileSystem_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_FileSystem
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_FileSystem_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_FileSystem_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_FileSystem_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystem_Caption_quals[] =
{
    &SCX_FileSystem_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_FileSystem_Caption_value = MI_T("File system information");

/* property SCX_FileSystem.Caption */
static MI_CONST MI_PropertyDecl SCX_FileSystem_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_FileSystem_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystem_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_FileSystem"), /* propagator */
    &SCX_FileSystem_Caption_value,
};

static MI_CONST MI_Char* SCX_FileSystem_Description_value = MI_T("Information about a logical unit of secondary storage");

/* property SCX_FileSystem.Description */
static MI_CONST MI_PropertyDecl SCX_FileSystem_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_FileSystem"), /* propagator */
    &SCX_FileSystem_Description_value,
};

/* property SCX_FileSystem.IsOnline */
static MI_CONST MI_PropertyDecl SCX_FileSystem_IsOnline_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00696508, /* code */
    MI_T("IsOnline"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem, IsOnline), /* offset */
    MI_T("SCX_FileSystem"), /* origin */
    MI_T("SCX_FileSystem"), /* propagator */
    NULL,
};

/* property SCX_FileSystem.TotalInodes */
static MI_CONST MI_PropertyDecl SCX_FileSystem_TotalInodes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730B, /* code */
    MI_T("TotalInodes"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem, TotalInodes), /* offset */
    MI_T("SCX_FileSystem"), /* origin */
    MI_T("SCX_FileSystem"), /* propagator */
    NULL,
};

/* property SCX_FileSystem.FreeInodes */
static MI_CONST MI_PropertyDecl SCX_FileSystem_FreeInodes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0066730A, /* code */
    MI_T("FreeInodes"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem, FreeInodes), /* offset */
    MI_T("SCX_FileSystem"), /* origin */
    MI_T("SCX_FileSystem"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_FileSystem_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_FileSystem_Caption_prop,
    &SCX_FileSystem_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_FileSystem_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_FileSystem_CSCreationClassName_prop,
    &CIM_FileSystem_CSName_prop,
    &CIM_FileSystem_CreationClassName_prop,
    &CIM_FileSystem_Root_prop,
    &CIM_FileSystem_BlockSize_prop,
    &CIM_FileSystem_FileSystemSize_prop,
    &CIM_FileSystem_AvailableSpace_prop,
    &CIM_FileSystem_ReadOnly_prop,
    &CIM_FileSystem_EncryptionMethod_prop,
    &CIM_FileSystem_CompressionMethod_prop,
    &CIM_FileSystem_CaseSensitive_prop,
    &CIM_FileSystem_CasePreserved_prop,
    &CIM_FileSystem_CodeSet_prop,
    &CIM_FileSystem_MaxFileNameLength_prop,
    &CIM_FileSystem_ClusterSize_prop,
    &CIM_FileSystem_FileSystemType_prop,
    &CIM_FileSystem_PersistenceType_prop,
    &CIM_FileSystem_OtherPersistenceType_prop,
    &CIM_FileSystem_NumberOfFiles_prop,
    &SCX_FileSystem_IsOnline_prop,
    &SCX_FileSystem_TotalInodes_prop,
    &SCX_FileSystem_FreeInodes_prop,
};

/* parameter SCX_FileSystem.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl SCX_FileSystem_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem_RequestStateChange, RequestedState), /* offset */
};

/* parameter SCX_FileSystem.RequestStateChange(): Job */
static MI_CONST MI_ParameterDecl SCX_FileSystem_RequestStateChange_Job_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006A6203, /* code */
    MI_T("Job"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REFERENCE, /* type */
    MI_T("CIM_ConcreteJob"), /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem_RequestStateChange, Job), /* offset */
};

/* parameter SCX_FileSystem.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl SCX_FileSystem_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter SCX_FileSystem.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_FileSystem_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_FileSystem_RequestStateChange_params[] =
{
    &SCX_FileSystem_RequestStateChange_MIReturn_param,
    &SCX_FileSystem_RequestStateChange_RequestedState_param,
    &SCX_FileSystem_RequestStateChange_Job_param,
    &SCX_FileSystem_RequestStateChange_TimeoutPeriod_param,
};

/* method SCX_FileSystem.RequestStateChange() */
MI_CONST MI_MethodDecl SCX_FileSystem_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_FileSystem_RequestStateChange_params, /* parameters */
    MI_COUNT(SCX_FileSystem_RequestStateChange_params), /* numParameters */
    sizeof(SCX_FileSystem_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_FileSystem_Invoke_RequestStateChange, /* method */
};

/* parameter SCX_FileSystem.RemoveByName(): Name */
static MI_CONST MI_ParameterDecl SCX_FileSystem_RemoveByName_Name_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem_RemoveByName, Name), /* offset */
};

/* parameter SCX_FileSystem.RemoveByName(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_FileSystem_RemoveByName_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystem_RemoveByName, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_FileSystem_RemoveByName_params[] =
{
    &SCX_FileSystem_RemoveByName_MIReturn_param,
    &SCX_FileSystem_RemoveByName_Name_param,
};

/* method SCX_FileSystem.RemoveByName() */
MI_CONST MI_MethodDecl SCX_FileSystem_RemoveByName_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x0072650C, /* code */
    MI_T("RemoveByName"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_FileSystem_RemoveByName_params, /* parameters */
    MI_COUNT(SCX_FileSystem_RemoveByName_params), /* numParameters */
    sizeof(SCX_FileSystem_RemoveByName), /* size */
    MI_BOOLEAN, /* returnType */
    MI_T("SCX_FileSystem"), /* origin */
    MI_T("SCX_FileSystem"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_FileSystem_Invoke_RemoveByName, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_FileSystem_meths[] =
{
    &SCX_FileSystem_RequestStateChange_rtti,
    &SCX_FileSystem_RemoveByName_rtti,
};

static MI_CONST MI_ProviderFT SCX_FileSystem_funcs =
{
  (MI_ProviderFT_Load)SCX_FileSystem_Load,
  (MI_ProviderFT_Unload)SCX_FileSystem_Unload,
  (MI_ProviderFT_GetInstance)SCX_FileSystem_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_FileSystem_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_FileSystem_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_FileSystem_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_FileSystem_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_FileSystem_UMLPackagePath_qual_value = MI_T("CIM::System::FileElements");

static MI_CONST MI_Qualifier SCX_FileSystem_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_FileSystem_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_FileSystem_Version_qual_value = MI_T("1.4.5");

static MI_CONST MI_Qualifier SCX_FileSystem_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_FileSystem_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystem_quals[] =
{
    &SCX_FileSystem_UMLPackagePath_qual,
    &SCX_FileSystem_Version_qual,
};

/* class SCX_FileSystem */
MI_CONST MI_ClassDecl SCX_FileSystem_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736D0E, /* code */
    MI_T("SCX_FileSystem"), /* name */
    SCX_FileSystem_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystem_quals), /* numQualifiers */
    SCX_FileSystem_props, /* properties */
    MI_COUNT(SCX_FileSystem_props), /* numProperties */
    sizeof(SCX_FileSystem), /* size */
    MI_T("CIM_FileSystem"), /* superClass */
    &CIM_FileSystem_rtti, /* superClassDecl */
    SCX_FileSystem_meths, /* methods */
    MI_COUNT(SCX_FileSystem_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_FileSystem_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_FileSystemStatisticalInformation
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_FileSystemStatisticalInformation_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_FileSystemStatisticalInformation_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_Caption_quals[] =
{
    &SCX_FileSystemStatisticalInformation_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_Caption_value = MI_T("File system information");

/* property SCX_FileSystemStatisticalInformation.Caption */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_FileSystemStatisticalInformation_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    &SCX_FileSystemStatisticalInformation_Caption_value,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_Description_value = MI_T("Performance statistics related to a logical unit of secondary storage");

/* property SCX_FileSystemStatisticalInformation.Description */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    &SCX_FileSystemStatisticalInformation_Description_value,
};

static MI_CONST MI_Uint32 SCX_FileSystemStatisticalInformation_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_FileSystemStatisticalInformation_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_FileSystemStatisticalInformation_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_Name_quals[] =
{
    &SCX_FileSystemStatisticalInformation_Name_MaxLen_qual,
    &SCX_FileSystemStatisticalInformation_Name_Override_qual,
};

/* property SCX_FileSystemStatisticalInformation.Name */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    SCX_FileSystemStatisticalInformation_Name_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, Name), /* offset */
    MI_T("CIM_StatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

/* property SCX_FileSystemStatisticalInformation.IsOnline */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_IsOnline_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00696508, /* code */
    MI_T("IsOnline"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, IsOnline), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_FreeMegabytes_Units_qual_value = MI_T("MegaBytes");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_FreeMegabytes_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_FreeMegabytes_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_FreeMegabytes_quals[] =
{
    &SCX_FileSystemStatisticalInformation_FreeMegabytes_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.FreeMegabytes */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_FreeMegabytes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0066730D, /* code */
    MI_T("FreeMegabytes"), /* name */
    SCX_FileSystemStatisticalInformation_FreeMegabytes_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_FreeMegabytes_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, FreeMegabytes), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_UsedMegabytes_Units_qual_value = MI_T("MegaBytes");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_UsedMegabytes_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_UsedMegabytes_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_UsedMegabytes_quals[] =
{
    &SCX_FileSystemStatisticalInformation_UsedMegabytes_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.UsedMegabytes */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_UsedMegabytes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0075730D, /* code */
    MI_T("UsedMegabytes"), /* name */
    SCX_FileSystemStatisticalInformation_UsedMegabytes_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_UsedMegabytes_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, UsedMegabytes), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_PercentFreeSpace_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_PercentFreeSpace_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_PercentFreeSpace_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_PercentFreeSpace_quals[] =
{
    &SCX_FileSystemStatisticalInformation_PercentFreeSpace_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.PercentFreeSpace */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_PercentFreeSpace_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706510, /* code */
    MI_T("PercentFreeSpace"), /* name */
    SCX_FileSystemStatisticalInformation_PercentFreeSpace_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_PercentFreeSpace_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, PercentFreeSpace), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_PercentUsedSpace_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_PercentUsedSpace_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_PercentUsedSpace_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_PercentUsedSpace_quals[] =
{
    &SCX_FileSystemStatisticalInformation_PercentUsedSpace_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.PercentUsedSpace */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_PercentUsedSpace_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706510, /* code */
    MI_T("PercentUsedSpace"), /* name */
    SCX_FileSystemStatisticalInformation_PercentUsedSpace_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_PercentUsedSpace_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, PercentUsedSpace), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_PercentFreeInodes_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_PercentFreeInodes_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_PercentFreeInodes_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_PercentFreeInodes_quals[] =
{
    &SCX_FileSystemStatisticalInformation_PercentFreeInodes_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.PercentFreeInodes */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_PercentFreeInodes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707311, /* code */
    MI_T("PercentFreeInodes"), /* name */
    SCX_FileSystemStatisticalInformation_PercentFreeInodes_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_PercentFreeInodes_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, PercentFreeInodes), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_PercentUsedInodes_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_PercentUsedInodes_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_PercentUsedInodes_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_PercentUsedInodes_quals[] =
{
    &SCX_FileSystemStatisticalInformation_PercentUsedInodes_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.PercentUsedInodes */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_PercentUsedInodes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707311, /* code */
    MI_T("PercentUsedInodes"), /* name */
    SCX_FileSystemStatisticalInformation_PercentUsedInodes_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_PercentUsedInodes_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, PercentUsedInodes), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_PercentBusyTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_PercentBusyTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_PercentBusyTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_PercentBusyTime_quals[] =
{
    &SCX_FileSystemStatisticalInformation_PercentBusyTime_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.PercentBusyTime */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_PercentBusyTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentBusyTime"), /* name */
    SCX_FileSystemStatisticalInformation_PercentBusyTime_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_PercentBusyTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, PercentBusyTime), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_PercentIdleTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_PercentIdleTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_PercentIdleTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_PercentIdleTime_quals[] =
{
    &SCX_FileSystemStatisticalInformation_PercentIdleTime_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.PercentIdleTime */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_PercentIdleTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentIdleTime"), /* name */
    SCX_FileSystemStatisticalInformation_PercentIdleTime_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_PercentIdleTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, PercentIdleTime), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_BytesPerSecond_Units_qual_value = MI_T("Bytes per Second");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_BytesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_BytesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_BytesPerSecond_quals[] =
{
    &SCX_FileSystemStatisticalInformation_BytesPerSecond_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.BytesPerSecond */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_BytesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0062640E, /* code */
    MI_T("BytesPerSecond"), /* name */
    SCX_FileSystemStatisticalInformation_BytesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_BytesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, BytesPerSecond), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_Units_qual_value = MI_T("Bytes per Second");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_quals[] =
{
    &SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.ReadBytesPerSecond */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726412, /* code */
    MI_T("ReadBytesPerSecond"), /* name */
    SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, ReadBytesPerSecond), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_Units_qual_value = MI_T("Bytes per Second");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_quals[] =
{
    &SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.WriteBytesPerSecond */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00776413, /* code */
    MI_T("WriteBytesPerSecond"), /* name */
    SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, WriteBytesPerSecond), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_TransfersPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_TransfersPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_TransfersPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_TransfersPerSecond_quals[] =
{
    &SCX_FileSystemStatisticalInformation_TransfersPerSecond_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.TransfersPerSecond */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_TransfersPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746412, /* code */
    MI_T("TransfersPerSecond"), /* name */
    SCX_FileSystemStatisticalInformation_TransfersPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_TransfersPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, TransfersPerSecond), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_ReadsPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_ReadsPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_ReadsPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_ReadsPerSecond_quals[] =
{
    &SCX_FileSystemStatisticalInformation_ReadsPerSecond_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.ReadsPerSecond */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_ReadsPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0072640E, /* code */
    MI_T("ReadsPerSecond"), /* name */
    SCX_FileSystemStatisticalInformation_ReadsPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_ReadsPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, ReadsPerSecond), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_WritesPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_WritesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_WritesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_WritesPerSecond_quals[] =
{
    &SCX_FileSystemStatisticalInformation_WritesPerSecond_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.WritesPerSecond */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_WritesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0077640F, /* code */
    MI_T("WritesPerSecond"), /* name */
    SCX_FileSystemStatisticalInformation_WritesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_WritesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, WritesPerSecond), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_AverageTransferTime_Units_qual_value = MI_T("Seconds");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_AverageTransferTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_FileSystemStatisticalInformation_AverageTransferTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_AverageTransferTime_quals[] =
{
    &SCX_FileSystemStatisticalInformation_AverageTransferTime_Units_qual,
};

/* property SCX_FileSystemStatisticalInformation.AverageTransferTime */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_AverageTransferTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00616513, /* code */
    MI_T("AverageTransferTime"), /* name */
    SCX_FileSystemStatisticalInformation_AverageTransferTime_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_AverageTransferTime_quals), /* numQualifiers */
    MI_REAL64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, AverageTransferTime), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

/* property SCX_FileSystemStatisticalInformation.AverageDiskQueueLength */
static MI_CONST MI_PropertyDecl SCX_FileSystemStatisticalInformation_AverageDiskQueueLength_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00616816, /* code */
    MI_T("AverageDiskQueueLength"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REAL64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_FileSystemStatisticalInformation, AverageDiskQueueLength), /* offset */
    MI_T("SCX_FileSystemStatisticalInformation"), /* origin */
    MI_T("SCX_FileSystemStatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_FileSystemStatisticalInformation_Caption_prop,
    &SCX_FileSystemStatisticalInformation_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &SCX_FileSystemStatisticalInformation_Name_prop,
    &SCX_StatisticalInformation_IsAggregate_prop,
    &SCX_FileSystemStatisticalInformation_IsOnline_prop,
    &SCX_FileSystemStatisticalInformation_FreeMegabytes_prop,
    &SCX_FileSystemStatisticalInformation_UsedMegabytes_prop,
    &SCX_FileSystemStatisticalInformation_PercentFreeSpace_prop,
    &SCX_FileSystemStatisticalInformation_PercentUsedSpace_prop,
    &SCX_FileSystemStatisticalInformation_PercentFreeInodes_prop,
    &SCX_FileSystemStatisticalInformation_PercentUsedInodes_prop,
    &SCX_FileSystemStatisticalInformation_PercentBusyTime_prop,
    &SCX_FileSystemStatisticalInformation_PercentIdleTime_prop,
    &SCX_FileSystemStatisticalInformation_BytesPerSecond_prop,
    &SCX_FileSystemStatisticalInformation_ReadBytesPerSecond_prop,
    &SCX_FileSystemStatisticalInformation_WriteBytesPerSecond_prop,
    &SCX_FileSystemStatisticalInformation_TransfersPerSecond_prop,
    &SCX_FileSystemStatisticalInformation_ReadsPerSecond_prop,
    &SCX_FileSystemStatisticalInformation_WritesPerSecond_prop,
    &SCX_FileSystemStatisticalInformation_AverageTransferTime_prop,
    &SCX_FileSystemStatisticalInformation_AverageDiskQueueLength_prop,
};

static MI_CONST MI_ProviderFT SCX_FileSystemStatisticalInformation_funcs =
{
  (MI_ProviderFT_Load)SCX_FileSystemStatisticalInformation_Load,
  (MI_ProviderFT_Unload)SCX_FileSystemStatisticalInformation_Unload,
  (MI_ProviderFT_GetInstance)SCX_FileSystemStatisticalInformation_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_FileSystemStatisticalInformation_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_FileSystemStatisticalInformation_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_FileSystemStatisticalInformation_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_FileSystemStatisticalInformation_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::Core::Statistics");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_FileSystemStatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_FileSystemStatisticalInformation_Version_qual_value = MI_T("1.4.8");

static MI_CONST MI_Qualifier SCX_FileSystemStatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_FileSystemStatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_FileSystemStatisticalInformation_quals[] =
{
    &SCX_FileSystemStatisticalInformation_UMLPackagePath_qual,
    &SCX_FileSystemStatisticalInformation_Version_qual,
};

/* class SCX_FileSystemStatisticalInformation */
MI_CONST MI_ClassDecl SCX_FileSystemStatisticalInformation_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736E24, /* code */
    MI_T("SCX_FileSystemStatisticalInformation"), /* name */
    SCX_FileSystemStatisticalInformation_quals, /* qualifiers */
    MI_COUNT(SCX_FileSystemStatisticalInformation_quals), /* numQualifiers */
    SCX_FileSystemStatisticalInformation_props, /* properties */
    MI_COUNT(SCX_FileSystemStatisticalInformation_props), /* numProperties */
    sizeof(SCX_FileSystemStatisticalInformation), /* size */
    MI_T("SCX_StatisticalInformation"), /* superClass */
    &SCX_StatisticalInformation_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &SCX_FileSystemStatisticalInformation_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_StatisticalData
**
**==============================================================================
*/

static MI_CONST MI_Char* CIM_StatisticalData_InstanceID_Override_qual_value = MI_T("InstanceID");

static MI_CONST MI_Qualifier CIM_StatisticalData_InstanceID_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_StatisticalData_InstanceID_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_StatisticalData_InstanceID_quals[] =
{
    &CIM_StatisticalData_InstanceID_Override_qual,
};

/* property CIM_StatisticalData.InstanceID */
static MI_CONST MI_PropertyDecl CIM_StatisticalData_InstanceID_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x0069640A, /* code */
    MI_T("InstanceID"), /* name */
    CIM_StatisticalData_InstanceID_quals, /* qualifiers */
    MI_COUNT(CIM_StatisticalData_InstanceID_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalData, InstanceID), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_StatisticalData"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_StatisticalData_ElementName_Override_qual_value = MI_T("ElementName");

static MI_CONST MI_Qualifier CIM_StatisticalData_ElementName_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_StatisticalData_ElementName_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_StatisticalData_ElementName_quals[] =
{
    &CIM_StatisticalData_ElementName_Override_qual,
};

/* property CIM_StatisticalData.ElementName */
static MI_CONST MI_PropertyDecl CIM_StatisticalData_ElementName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_REQUIRED, /* flags */
    0x0065650B, /* code */
    MI_T("ElementName"), /* name */
    CIM_StatisticalData_ElementName_quals, /* qualifiers */
    MI_COUNT(CIM_StatisticalData_ElementName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalData, ElementName), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_StatisticalData"), /* propagator */
    NULL,
};

/* property CIM_StatisticalData.StartStatisticTime */
static MI_CONST MI_PropertyDecl CIM_StatisticalData_StartStatisticTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736512, /* code */
    MI_T("StartStatisticTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalData, StartStatisticTime), /* offset */
    MI_T("CIM_StatisticalData"), /* origin */
    MI_T("CIM_StatisticalData"), /* propagator */
    NULL,
};

/* property CIM_StatisticalData.StatisticTime */
static MI_CONST MI_PropertyDecl CIM_StatisticalData_StatisticTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0073650D, /* code */
    MI_T("StatisticTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalData, StatisticTime), /* offset */
    MI_T("CIM_StatisticalData"), /* origin */
    MI_T("CIM_StatisticalData"), /* propagator */
    NULL,
};

static MI_CONST MI_Datetime CIM_StatisticalData_SampleInterval_value = {0,{{0,0,0,0,0}}};

/* property CIM_StatisticalData.SampleInterval */
static MI_CONST MI_PropertyDecl CIM_StatisticalData_SampleInterval_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736C0E, /* code */
    MI_T("SampleInterval"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalData, SampleInterval), /* offset */
    MI_T("CIM_StatisticalData"), /* origin */
    MI_T("CIM_StatisticalData"), /* propagator */
    &CIM_StatisticalData_SampleInterval_value,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_StatisticalData_props[] =
{
    &CIM_StatisticalData_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_StatisticalData_ElementName_prop,
    &CIM_StatisticalData_StartStatisticTime_prop,
    &CIM_StatisticalData_StatisticTime_prop,
    &CIM_StatisticalData_SampleInterval_prop,
};

/* parameter CIM_StatisticalData.ResetSelectedStats(): SelectedStatistics */
static MI_CONST MI_ParameterDecl CIM_StatisticalData_ResetSelectedStats_SelectedStatistics_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00737312, /* code */
    MI_T("SelectedStatistics"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalData_ResetSelectedStats, SelectedStatistics), /* offset */
};

/* parameter CIM_StatisticalData.ResetSelectedStats(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_StatisticalData_ResetSelectedStats_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_StatisticalData_ResetSelectedStats, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_StatisticalData_ResetSelectedStats_params[] =
{
    &CIM_StatisticalData_ResetSelectedStats_MIReturn_param,
    &CIM_StatisticalData_ResetSelectedStats_SelectedStatistics_param,
};

/* method CIM_StatisticalData.ResetSelectedStats() */
MI_CONST MI_MethodDecl CIM_StatisticalData_ResetSelectedStats_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727312, /* code */
    MI_T("ResetSelectedStats"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_StatisticalData_ResetSelectedStats_params, /* parameters */
    MI_COUNT(CIM_StatisticalData_ResetSelectedStats_params), /* numParameters */
    sizeof(CIM_StatisticalData_ResetSelectedStats), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_StatisticalData"), /* origin */
    MI_T("CIM_StatisticalData"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_StatisticalData_meths[] =
{
    &CIM_StatisticalData_ResetSelectedStats_rtti,
};

static MI_CONST MI_Char* CIM_StatisticalData_UMLPackagePath_qual_value = MI_T("CIM::Core::Statistics");

static MI_CONST MI_Qualifier CIM_StatisticalData_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_StatisticalData_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_StatisticalData_Version_qual_value = MI_T("2.19.0");

static MI_CONST MI_Qualifier CIM_StatisticalData_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_StatisticalData_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_StatisticalData_quals[] =
{
    &CIM_StatisticalData_UMLPackagePath_qual,
    &CIM_StatisticalData_Version_qual,
};

/* class CIM_StatisticalData */
MI_CONST MI_ClassDecl CIM_StatisticalData_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00636113, /* code */
    MI_T("CIM_StatisticalData"), /* name */
    CIM_StatisticalData_quals, /* qualifiers */
    MI_COUNT(CIM_StatisticalData_quals), /* numQualifiers */
    CIM_StatisticalData_props, /* properties */
    MI_COUNT(CIM_StatisticalData_props), /* numProperties */
    sizeof(CIM_StatisticalData), /* size */
    MI_T("CIM_ManagedElement"), /* superClass */
    &CIM_ManagedElement_rtti, /* superClassDecl */
    CIM_StatisticalData_meths, /* methods */
    MI_COUNT(CIM_StatisticalData_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_NetworkPortStatistics
**
**==============================================================================
*/

static MI_CONST MI_Char* CIM_NetworkPortStatistics_BytesTransmitted_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_NetworkPortStatistics_BytesTransmitted_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_NetworkPortStatistics_BytesTransmitted_Units_qual_value
};

static MI_CONST MI_Char* CIM_NetworkPortStatistics_BytesTransmitted_PUnit_qual_value = MI_T("byte");

static MI_CONST MI_Qualifier CIM_NetworkPortStatistics_BytesTransmitted_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_NetworkPortStatistics_BytesTransmitted_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_NetworkPortStatistics_BytesTransmitted_quals[] =
{
    &CIM_NetworkPortStatistics_BytesTransmitted_Units_qual,
    &CIM_NetworkPortStatistics_BytesTransmitted_PUnit_qual,
};

/* property CIM_NetworkPortStatistics.BytesTransmitted */
static MI_CONST MI_PropertyDecl CIM_NetworkPortStatistics_BytesTransmitted_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00626410, /* code */
    MI_T("BytesTransmitted"), /* name */
    CIM_NetworkPortStatistics_BytesTransmitted_quals, /* qualifiers */
    MI_COUNT(CIM_NetworkPortStatistics_BytesTransmitted_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_NetworkPortStatistics, BytesTransmitted), /* offset */
    MI_T("CIM_NetworkPortStatistics"), /* origin */
    MI_T("CIM_NetworkPortStatistics"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_NetworkPortStatistics_BytesReceived_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_NetworkPortStatistics_BytesReceived_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_NetworkPortStatistics_BytesReceived_Units_qual_value
};

static MI_CONST MI_Char* CIM_NetworkPortStatistics_BytesReceived_PUnit_qual_value = MI_T("byte");

static MI_CONST MI_Qualifier CIM_NetworkPortStatistics_BytesReceived_PUnit_qual =
{
    MI_T("PUnit"),
    MI_STRING,
    0,
    &CIM_NetworkPortStatistics_BytesReceived_PUnit_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_NetworkPortStatistics_BytesReceived_quals[] =
{
    &CIM_NetworkPortStatistics_BytesReceived_Units_qual,
    &CIM_NetworkPortStatistics_BytesReceived_PUnit_qual,
};

/* property CIM_NetworkPortStatistics.BytesReceived */
static MI_CONST MI_PropertyDecl CIM_NetworkPortStatistics_BytesReceived_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0062640D, /* code */
    MI_T("BytesReceived"), /* name */
    CIM_NetworkPortStatistics_BytesReceived_quals, /* qualifiers */
    MI_COUNT(CIM_NetworkPortStatistics_BytesReceived_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_NetworkPortStatistics, BytesReceived), /* offset */
    MI_T("CIM_NetworkPortStatistics"), /* origin */
    MI_T("CIM_NetworkPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_NetworkPortStatistics.PacketsTransmitted */
static MI_CONST MI_PropertyDecl CIM_NetworkPortStatistics_PacketsTransmitted_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706412, /* code */
    MI_T("PacketsTransmitted"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_NetworkPortStatistics, PacketsTransmitted), /* offset */
    MI_T("CIM_NetworkPortStatistics"), /* origin */
    MI_T("CIM_NetworkPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_NetworkPortStatistics.PacketsReceived */
static MI_CONST MI_PropertyDecl CIM_NetworkPortStatistics_PacketsReceived_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070640F, /* code */
    MI_T("PacketsReceived"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_NetworkPortStatistics, PacketsReceived), /* offset */
    MI_T("CIM_NetworkPortStatistics"), /* origin */
    MI_T("CIM_NetworkPortStatistics"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_NetworkPortStatistics_props[] =
{
    &CIM_StatisticalData_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_StatisticalData_ElementName_prop,
    &CIM_StatisticalData_StartStatisticTime_prop,
    &CIM_StatisticalData_StatisticTime_prop,
    &CIM_StatisticalData_SampleInterval_prop,
    &CIM_NetworkPortStatistics_BytesTransmitted_prop,
    &CIM_NetworkPortStatistics_BytesReceived_prop,
    &CIM_NetworkPortStatistics_PacketsTransmitted_prop,
    &CIM_NetworkPortStatistics_PacketsReceived_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_NetworkPortStatistics_meths[] =
{
    &CIM_StatisticalData_ResetSelectedStats_rtti,
};

static MI_CONST MI_Char* CIM_NetworkPortStatistics_UMLPackagePath_qual_value = MI_T("CIM::Device::Ports");

static MI_CONST MI_Qualifier CIM_NetworkPortStatistics_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_NetworkPortStatistics_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_NetworkPortStatistics_Version_qual_value = MI_T("2.10.0");

static MI_CONST MI_Qualifier CIM_NetworkPortStatistics_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_NetworkPortStatistics_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_NetworkPortStatistics_quals[] =
{
    &CIM_NetworkPortStatistics_UMLPackagePath_qual,
    &CIM_NetworkPortStatistics_Version_qual,
};

/* class CIM_NetworkPortStatistics */
MI_CONST MI_ClassDecl CIM_NetworkPortStatistics_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00637319, /* code */
    MI_T("CIM_NetworkPortStatistics"), /* name */
    CIM_NetworkPortStatistics_quals, /* qualifiers */
    MI_COUNT(CIM_NetworkPortStatistics_quals), /* numQualifiers */
    CIM_NetworkPortStatistics_props, /* properties */
    MI_COUNT(CIM_NetworkPortStatistics_props), /* numProperties */
    sizeof(CIM_NetworkPortStatistics), /* size */
    MI_T("CIM_StatisticalData"), /* superClass */
    &CIM_StatisticalData_rtti, /* superClassDecl */
    CIM_NetworkPortStatistics_meths, /* methods */
    MI_COUNT(CIM_NetworkPortStatistics_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_EthernetPortStatistics
**
**==============================================================================
*/

static MI_CONST MI_Char* CIM_EthernetPortStatistics_PacketsTransmitted_Override_qual_value = MI_T("PacketsTransmitted");

static MI_CONST MI_Qualifier CIM_EthernetPortStatistics_PacketsTransmitted_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_EthernetPortStatistics_PacketsTransmitted_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_EthernetPortStatistics_PacketsTransmitted_quals[] =
{
    &CIM_EthernetPortStatistics_PacketsTransmitted_Override_qual,
};

/* property CIM_EthernetPortStatistics.PacketsTransmitted */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_PacketsTransmitted_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706412, /* code */
    MI_T("PacketsTransmitted"), /* name */
    CIM_EthernetPortStatistics_PacketsTransmitted_quals, /* qualifiers */
    MI_COUNT(CIM_EthernetPortStatistics_PacketsTransmitted_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, PacketsTransmitted), /* offset */
    MI_T("CIM_NetworkPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_EthernetPortStatistics_PacketsReceived_Override_qual_value = MI_T("PacketsReceived");

static MI_CONST MI_Qualifier CIM_EthernetPortStatistics_PacketsReceived_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_EthernetPortStatistics_PacketsReceived_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_EthernetPortStatistics_PacketsReceived_quals[] =
{
    &CIM_EthernetPortStatistics_PacketsReceived_Override_qual,
};

/* property CIM_EthernetPortStatistics.PacketsReceived */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_PacketsReceived_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070640F, /* code */
    MI_T("PacketsReceived"), /* name */
    CIM_EthernetPortStatistics_PacketsReceived_quals, /* qualifiers */
    MI_COUNT(CIM_EthernetPortStatistics_PacketsReceived_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, PacketsReceived), /* offset */
    MI_T("CIM_NetworkPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.SymbolErrors */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_SymbolErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0073730C, /* code */
    MI_T("SymbolErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, SymbolErrors), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.AlignmentErrors */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_AlignmentErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061730F, /* code */
    MI_T("AlignmentErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, AlignmentErrors), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.FCSErrors */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_FCSErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00667309, /* code */
    MI_T("FCSErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, FCSErrors), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.SingleCollisionFrames */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_SingleCollisionFrames_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00737315, /* code */
    MI_T("SingleCollisionFrames"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, SingleCollisionFrames), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.MultipleCollisionFrames */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_MultipleCollisionFrames_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D7317, /* code */
    MI_T("MultipleCollisionFrames"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, MultipleCollisionFrames), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.SQETestErrors */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_SQETestErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0073730D, /* code */
    MI_T("SQETestErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, SQETestErrors), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.DeferredTransmissions */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_DeferredTransmissions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00647315, /* code */
    MI_T("DeferredTransmissions"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, DeferredTransmissions), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.LateCollisions */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_LateCollisions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C730E, /* code */
    MI_T("LateCollisions"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, LateCollisions), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.ExcessiveCollisions */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_ExcessiveCollisions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00657313, /* code */
    MI_T("ExcessiveCollisions"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, ExcessiveCollisions), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.InternalMACTransmitErrors */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_InternalMACTransmitErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00697319, /* code */
    MI_T("InternalMACTransmitErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, InternalMACTransmitErrors), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.InternalMACReceiveErrors */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_InternalMACReceiveErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00697318, /* code */
    MI_T("InternalMACReceiveErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, InternalMACReceiveErrors), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.CarrierSenseErrors */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_CarrierSenseErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00637312, /* code */
    MI_T("CarrierSenseErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, CarrierSenseErrors), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property CIM_EthernetPortStatistics.FrameTooLongs */
static MI_CONST MI_PropertyDecl CIM_EthernetPortStatistics_FrameTooLongs_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0066730D, /* code */
    MI_T("FrameTooLongs"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_EthernetPortStatistics, FrameTooLongs), /* offset */
    MI_T("CIM_EthernetPortStatistics"), /* origin */
    MI_T("CIM_EthernetPortStatistics"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_EthernetPortStatistics_props[] =
{
    &CIM_StatisticalData_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_StatisticalData_ElementName_prop,
    &CIM_StatisticalData_StartStatisticTime_prop,
    &CIM_StatisticalData_StatisticTime_prop,
    &CIM_StatisticalData_SampleInterval_prop,
    &CIM_NetworkPortStatistics_BytesTransmitted_prop,
    &CIM_NetworkPortStatistics_BytesReceived_prop,
    &CIM_EthernetPortStatistics_PacketsTransmitted_prop,
    &CIM_EthernetPortStatistics_PacketsReceived_prop,
    &CIM_EthernetPortStatistics_SymbolErrors_prop,
    &CIM_EthernetPortStatistics_AlignmentErrors_prop,
    &CIM_EthernetPortStatistics_FCSErrors_prop,
    &CIM_EthernetPortStatistics_SingleCollisionFrames_prop,
    &CIM_EthernetPortStatistics_MultipleCollisionFrames_prop,
    &CIM_EthernetPortStatistics_SQETestErrors_prop,
    &CIM_EthernetPortStatistics_DeferredTransmissions_prop,
    &CIM_EthernetPortStatistics_LateCollisions_prop,
    &CIM_EthernetPortStatistics_ExcessiveCollisions_prop,
    &CIM_EthernetPortStatistics_InternalMACTransmitErrors_prop,
    &CIM_EthernetPortStatistics_InternalMACReceiveErrors_prop,
    &CIM_EthernetPortStatistics_CarrierSenseErrors_prop,
    &CIM_EthernetPortStatistics_FrameTooLongs_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_EthernetPortStatistics_meths[] =
{
    &CIM_StatisticalData_ResetSelectedStats_rtti,
};

static MI_CONST MI_Char* CIM_EthernetPortStatistics_UMLPackagePath_qual_value = MI_T("CIM::Device::Ports");

static MI_CONST MI_Qualifier CIM_EthernetPortStatistics_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_EthernetPortStatistics_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_EthernetPortStatistics_Version_qual_value = MI_T("2.10.0");

static MI_CONST MI_Qualifier CIM_EthernetPortStatistics_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_EthernetPortStatistics_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_EthernetPortStatistics_quals[] =
{
    &CIM_EthernetPortStatistics_UMLPackagePath_qual,
    &CIM_EthernetPortStatistics_Version_qual,
};

/* class CIM_EthernetPortStatistics */
MI_CONST MI_ClassDecl CIM_EthernetPortStatistics_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0063731A, /* code */
    MI_T("CIM_EthernetPortStatistics"), /* name */
    CIM_EthernetPortStatistics_quals, /* qualifiers */
    MI_COUNT(CIM_EthernetPortStatistics_quals), /* numQualifiers */
    CIM_EthernetPortStatistics_props, /* properties */
    MI_COUNT(CIM_EthernetPortStatistics_props), /* numProperties */
    sizeof(CIM_EthernetPortStatistics), /* size */
    MI_T("CIM_NetworkPortStatistics"), /* superClass */
    &CIM_NetworkPortStatistics_rtti, /* superClassDecl */
    CIM_EthernetPortStatistics_meths, /* methods */
    MI_COUNT(CIM_EthernetPortStatistics_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_EthernetPortStatistics
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_EthernetPortStatistics_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_EthernetPortStatistics_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_EthernetPortStatistics_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_EthernetPortStatistics_Caption_quals[] =
{
    &SCX_EthernetPortStatistics_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_EthernetPortStatistics_Caption_value = MI_T("Ethernet port information");

/* property SCX_EthernetPortStatistics.Caption */
static MI_CONST MI_PropertyDecl SCX_EthernetPortStatistics_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_EthernetPortStatistics_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_EthernetPortStatistics_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_EthernetPortStatistics"), /* propagator */
    &SCX_EthernetPortStatistics_Caption_value,
};

static MI_CONST MI_Char* SCX_EthernetPortStatistics_Description_value = MI_T("Statistics on transfer performance for a port");

/* property SCX_EthernetPortStatistics.Description */
static MI_CONST MI_PropertyDecl SCX_EthernetPortStatistics_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_EthernetPortStatistics"), /* propagator */
    &SCX_EthernetPortStatistics_Description_value,
};

static MI_CONST MI_Char* SCX_EthernetPortStatistics_BytesTotal_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier SCX_EthernetPortStatistics_BytesTotal_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_EthernetPortStatistics_BytesTotal_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_EthernetPortStatistics_BytesTotal_quals[] =
{
    &SCX_EthernetPortStatistics_BytesTotal_Units_qual,
};

/* property SCX_EthernetPortStatistics.BytesTotal */
static MI_CONST MI_PropertyDecl SCX_EthernetPortStatistics_BytesTotal_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00626C0A, /* code */
    MI_T("BytesTotal"), /* name */
    SCX_EthernetPortStatistics_BytesTotal_quals, /* qualifiers */
    MI_COUNT(SCX_EthernetPortStatistics_BytesTotal_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics, BytesTotal), /* offset */
    MI_T("SCX_EthernetPortStatistics"), /* origin */
    MI_T("SCX_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property SCX_EthernetPortStatistics.TotalRxErrors */
static MI_CONST MI_PropertyDecl SCX_EthernetPortStatistics_TotalRxErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730D, /* code */
    MI_T("TotalRxErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics, TotalRxErrors), /* offset */
    MI_T("SCX_EthernetPortStatistics"), /* origin */
    MI_T("SCX_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property SCX_EthernetPortStatistics.TotalTxErrors */
static MI_CONST MI_PropertyDecl SCX_EthernetPortStatistics_TotalTxErrors_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730D, /* code */
    MI_T("TotalTxErrors"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics, TotalTxErrors), /* offset */
    MI_T("SCX_EthernetPortStatistics"), /* origin */
    MI_T("SCX_EthernetPortStatistics"), /* propagator */
    NULL,
};

/* property SCX_EthernetPortStatistics.TotalCollisions */
static MI_CONST MI_PropertyDecl SCX_EthernetPortStatistics_TotalCollisions_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074730F, /* code */
    MI_T("TotalCollisions"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics, TotalCollisions), /* offset */
    MI_T("SCX_EthernetPortStatistics"), /* origin */
    MI_T("SCX_EthernetPortStatistics"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_EthernetPortStatistics_props[] =
{
    &CIM_StatisticalData_InstanceID_prop,
    &SCX_EthernetPortStatistics_Caption_prop,
    &SCX_EthernetPortStatistics_Description_prop,
    &CIM_StatisticalData_ElementName_prop,
    &CIM_StatisticalData_StartStatisticTime_prop,
    &CIM_StatisticalData_StatisticTime_prop,
    &CIM_StatisticalData_SampleInterval_prop,
    &CIM_NetworkPortStatistics_BytesTransmitted_prop,
    &CIM_NetworkPortStatistics_BytesReceived_prop,
    &CIM_EthernetPortStatistics_PacketsTransmitted_prop,
    &CIM_EthernetPortStatistics_PacketsReceived_prop,
    &CIM_EthernetPortStatistics_SymbolErrors_prop,
    &CIM_EthernetPortStatistics_AlignmentErrors_prop,
    &CIM_EthernetPortStatistics_FCSErrors_prop,
    &CIM_EthernetPortStatistics_SingleCollisionFrames_prop,
    &CIM_EthernetPortStatistics_MultipleCollisionFrames_prop,
    &CIM_EthernetPortStatistics_SQETestErrors_prop,
    &CIM_EthernetPortStatistics_DeferredTransmissions_prop,
    &CIM_EthernetPortStatistics_LateCollisions_prop,
    &CIM_EthernetPortStatistics_ExcessiveCollisions_prop,
    &CIM_EthernetPortStatistics_InternalMACTransmitErrors_prop,
    &CIM_EthernetPortStatistics_InternalMACReceiveErrors_prop,
    &CIM_EthernetPortStatistics_CarrierSenseErrors_prop,
    &CIM_EthernetPortStatistics_FrameTooLongs_prop,
    &SCX_EthernetPortStatistics_BytesTotal_prop,
    &SCX_EthernetPortStatistics_TotalRxErrors_prop,
    &SCX_EthernetPortStatistics_TotalTxErrors_prop,
    &SCX_EthernetPortStatistics_TotalCollisions_prop,
};

/* parameter SCX_EthernetPortStatistics.ResetSelectedStats(): SelectedStatistics */
static MI_CONST MI_ParameterDecl SCX_EthernetPortStatistics_ResetSelectedStats_SelectedStatistics_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00737312, /* code */
    MI_T("SelectedStatistics"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics_ResetSelectedStats, SelectedStatistics), /* offset */
};

/* parameter SCX_EthernetPortStatistics.ResetSelectedStats(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_EthernetPortStatistics_ResetSelectedStats_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_EthernetPortStatistics_ResetSelectedStats, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_EthernetPortStatistics_ResetSelectedStats_params[] =
{
    &SCX_EthernetPortStatistics_ResetSelectedStats_MIReturn_param,
    &SCX_EthernetPortStatistics_ResetSelectedStats_SelectedStatistics_param,
};

/* method SCX_EthernetPortStatistics.ResetSelectedStats() */
MI_CONST MI_MethodDecl SCX_EthernetPortStatistics_ResetSelectedStats_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727312, /* code */
    MI_T("ResetSelectedStats"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_EthernetPortStatistics_ResetSelectedStats_params, /* parameters */
    MI_COUNT(SCX_EthernetPortStatistics_ResetSelectedStats_params), /* numParameters */
    sizeof(SCX_EthernetPortStatistics_ResetSelectedStats), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_StatisticalData"), /* origin */
    MI_T("CIM_StatisticalData"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_EthernetPortStatistics_Invoke_ResetSelectedStats, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_EthernetPortStatistics_meths[] =
{
    &SCX_EthernetPortStatistics_ResetSelectedStats_rtti,
};

static MI_CONST MI_ProviderFT SCX_EthernetPortStatistics_funcs =
{
  (MI_ProviderFT_Load)SCX_EthernetPortStatistics_Load,
  (MI_ProviderFT_Unload)SCX_EthernetPortStatistics_Unload,
  (MI_ProviderFT_GetInstance)SCX_EthernetPortStatistics_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_EthernetPortStatistics_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_EthernetPortStatistics_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_EthernetPortStatistics_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_EthernetPortStatistics_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_EthernetPortStatistics_UMLPackagePath_qual_value = MI_T("CIM::Device::Ports");

static MI_CONST MI_Qualifier SCX_EthernetPortStatistics_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_EthernetPortStatistics_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_EthernetPortStatistics_Version_qual_value = MI_T("1.4.4");

static MI_CONST MI_Qualifier SCX_EthernetPortStatistics_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_EthernetPortStatistics_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_EthernetPortStatistics_quals[] =
{
    &SCX_EthernetPortStatistics_UMLPackagePath_qual,
    &SCX_EthernetPortStatistics_Version_qual,
};

/* class SCX_EthernetPortStatistics */
MI_CONST MI_ClassDecl SCX_EthernetPortStatistics_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0073731A, /* code */
    MI_T("SCX_EthernetPortStatistics"), /* name */
    SCX_EthernetPortStatistics_quals, /* qualifiers */
    MI_COUNT(SCX_EthernetPortStatistics_quals), /* numQualifiers */
    SCX_EthernetPortStatistics_props, /* properties */
    MI_COUNT(SCX_EthernetPortStatistics_props), /* numProperties */
    sizeof(SCX_EthernetPortStatistics), /* size */
    MI_T("CIM_EthernetPortStatistics"), /* superClass */
    &CIM_EthernetPortStatistics_rtti, /* superClassDecl */
    SCX_EthernetPortStatistics_meths, /* methods */
    MI_COUNT(SCX_EthernetPortStatistics_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_EthernetPortStatistics_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_ServiceAccessPoint
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_ServiceAccessPoint_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ServiceAccessPoint_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_ServiceAccessPoint_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ServiceAccessPoint_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ServiceAccessPoint_Name_quals[] =
{
    &CIM_ServiceAccessPoint_Name_MaxLen_qual,
    &CIM_ServiceAccessPoint_Name_Override_qual,
};

/* property CIM_ServiceAccessPoint.Name */
static MI_CONST MI_PropertyDecl CIM_ServiceAccessPoint_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_ServiceAccessPoint_Name_quals, /* qualifiers */
    MI_COUNT(CIM_ServiceAccessPoint_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ServiceAccessPoint, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ServiceAccessPoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ServiceAccessPoint_SystemCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_SystemCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ServiceAccessPoint_SystemCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_ServiceAccessPoint_SystemCreationClassName_Propagated_qual_value = MI_T("CIM_System.CreationClassName");

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_SystemCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_ServiceAccessPoint_SystemCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ServiceAccessPoint_SystemCreationClassName_quals[] =
{
    &CIM_ServiceAccessPoint_SystemCreationClassName_MaxLen_qual,
    &CIM_ServiceAccessPoint_SystemCreationClassName_Propagated_qual,
};

/* property CIM_ServiceAccessPoint.SystemCreationClassName */
static MI_CONST MI_PropertyDecl CIM_ServiceAccessPoint_SystemCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00736517, /* code */
    MI_T("SystemCreationClassName"), /* name */
    CIM_ServiceAccessPoint_SystemCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_ServiceAccessPoint_SystemCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ServiceAccessPoint, SystemCreationClassName), /* offset */
    MI_T("CIM_ServiceAccessPoint"), /* origin */
    MI_T("CIM_ServiceAccessPoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ServiceAccessPoint_SystemName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_SystemName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ServiceAccessPoint_SystemName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_ServiceAccessPoint_SystemName_Propagated_qual_value = MI_T("CIM_System.Name");

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_SystemName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_ServiceAccessPoint_SystemName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ServiceAccessPoint_SystemName_quals[] =
{
    &CIM_ServiceAccessPoint_SystemName_MaxLen_qual,
    &CIM_ServiceAccessPoint_SystemName_Propagated_qual,
};

/* property CIM_ServiceAccessPoint.SystemName */
static MI_CONST MI_PropertyDecl CIM_ServiceAccessPoint_SystemName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x0073650A, /* code */
    MI_T("SystemName"), /* name */
    CIM_ServiceAccessPoint_SystemName_quals, /* qualifiers */
    MI_COUNT(CIM_ServiceAccessPoint_SystemName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ServiceAccessPoint, SystemName), /* offset */
    MI_T("CIM_ServiceAccessPoint"), /* origin */
    MI_T("CIM_ServiceAccessPoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ServiceAccessPoint_CreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_CreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ServiceAccessPoint_CreationClassName_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ServiceAccessPoint_CreationClassName_quals[] =
{
    &CIM_ServiceAccessPoint_CreationClassName_MaxLen_qual,
};

/* property CIM_ServiceAccessPoint.CreationClassName */
static MI_CONST MI_PropertyDecl CIM_ServiceAccessPoint_CreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636511, /* code */
    MI_T("CreationClassName"), /* name */
    CIM_ServiceAccessPoint_CreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_ServiceAccessPoint_CreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ServiceAccessPoint, CreationClassName), /* offset */
    MI_T("CIM_ServiceAccessPoint"), /* origin */
    MI_T("CIM_ServiceAccessPoint"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_ServiceAccessPoint_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ServiceAccessPoint_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_ServiceAccessPoint_SystemCreationClassName_prop,
    &CIM_ServiceAccessPoint_SystemName_prop,
    &CIM_ServiceAccessPoint_CreationClassName_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_ServiceAccessPoint_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_ServiceAccessPoint_UMLPackagePath_qual_value = MI_T("CIM::Core::Service");

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_ServiceAccessPoint_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_ServiceAccessPoint_Version_qual_value = MI_T("2.10.0");

static MI_CONST MI_Qualifier CIM_ServiceAccessPoint_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_ServiceAccessPoint_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ServiceAccessPoint_quals[] =
{
    &CIM_ServiceAccessPoint_UMLPackagePath_qual,
    &CIM_ServiceAccessPoint_Version_qual,
};

/* class CIM_ServiceAccessPoint */
MI_CONST MI_ClassDecl CIM_ServiceAccessPoint_rtti =
{
    MI_FLAG_CLASS|MI_FLAG_ABSTRACT, /* flags */
    0x00637416, /* code */
    MI_T("CIM_ServiceAccessPoint"), /* name */
    CIM_ServiceAccessPoint_quals, /* qualifiers */
    MI_COUNT(CIM_ServiceAccessPoint_quals), /* numQualifiers */
    CIM_ServiceAccessPoint_props, /* properties */
    MI_COUNT(CIM_ServiceAccessPoint_props), /* numProperties */
    sizeof(CIM_ServiceAccessPoint), /* size */
    MI_T("CIM_EnabledLogicalElement"), /* superClass */
    &CIM_EnabledLogicalElement_rtti, /* superClassDecl */
    CIM_ServiceAccessPoint_meths, /* methods */
    MI_COUNT(CIM_ServiceAccessPoint_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_ProtocolEndpoint
**
**==============================================================================
*/

static MI_CONST MI_Char* CIM_ProtocolEndpoint_Description_Override_qual_value = MI_T("Description");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_Description_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ProtocolEndpoint_Description_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_Description_quals[] =
{
    &CIM_ProtocolEndpoint_Description_Override_qual,
};

/* property CIM_ProtocolEndpoint.Description */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    CIM_ProtocolEndpoint_Description_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_Description_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ProtocolEndpoint_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ProtocolEndpoint_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ProtocolEndpoint_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_Name_quals[] =
{
    &CIM_ProtocolEndpoint_Name_MaxLen_qual,
    &CIM_ProtocolEndpoint_Name_Override_qual,
};

/* property CIM_ProtocolEndpoint.Name */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_ProtocolEndpoint_Name_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_OperationalStatus_ArrayType_qual_value = MI_T("Indexed");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_OperationalStatus_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_ProtocolEndpoint_OperationalStatus_ArrayType_qual_value
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_OperationalStatus_Override_qual_value = MI_T("OperationalStatus");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_OperationalStatus_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ProtocolEndpoint_OperationalStatus_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_OperationalStatus_quals[] =
{
    &CIM_ProtocolEndpoint_OperationalStatus_ArrayType_qual,
    &CIM_ProtocolEndpoint_OperationalStatus_Override_qual,
};

/* property CIM_ProtocolEndpoint.OperationalStatus */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_OperationalStatus_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F7311, /* code */
    MI_T("OperationalStatus"), /* name */
    CIM_ProtocolEndpoint_OperationalStatus_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_OperationalStatus_quals), /* numQualifiers */
    MI_UINT16A, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, OperationalStatus), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_EnabledState_Override_qual_value = MI_T("EnabledState");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_EnabledState_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ProtocolEndpoint_EnabledState_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_EnabledState_quals[] =
{
    &CIM_ProtocolEndpoint_EnabledState_Override_qual,
};

/* property CIM_ProtocolEndpoint.EnabledState */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_EnabledState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065650C, /* code */
    MI_T("EnabledState"), /* name */
    CIM_ProtocolEndpoint_EnabledState_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_EnabledState_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, EnabledState), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_TimeOfLastStateChange_Override_qual_value = MI_T("TimeOfLastStateChange");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_TimeOfLastStateChange_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ProtocolEndpoint_TimeOfLastStateChange_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_TimeOfLastStateChange_quals[] =
{
    &CIM_ProtocolEndpoint_TimeOfLastStateChange_Override_qual,
};

/* property CIM_ProtocolEndpoint.TimeOfLastStateChange */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_TimeOfLastStateChange_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746515, /* code */
    MI_T("TimeOfLastStateChange"), /* name */
    CIM_ProtocolEndpoint_TimeOfLastStateChange_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_TimeOfLastStateChange_quals), /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, TimeOfLastStateChange), /* offset */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ProtocolEndpoint_NameFormat_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_NameFormat_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ProtocolEndpoint_NameFormat_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_NameFormat_quals[] =
{
    &CIM_ProtocolEndpoint_NameFormat_MaxLen_qual,
};

/* property CIM_ProtocolEndpoint.NameFormat */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_NameFormat_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E740A, /* code */
    MI_T("NameFormat"), /* name */
    CIM_ProtocolEndpoint_NameFormat_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_NameFormat_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, NameFormat), /* offset */
    MI_T("CIM_ProtocolEndpoint"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_ProtocolType_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ProtocolEndpoint.ProtocolIFType"),
};

static MI_CONST MI_ConstStringA CIM_ProtocolEndpoint_ProtocolType_Deprecated_qual_value =
{
    CIM_ProtocolEndpoint_ProtocolType_Deprecated_qual_data_value,
    MI_COUNT(CIM_ProtocolEndpoint_ProtocolType_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_ProtocolType_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_ProtocolEndpoint_ProtocolType_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_ProtocolType_quals[] =
{
    &CIM_ProtocolEndpoint_ProtocolType_Deprecated_qual,
};

/* property CIM_ProtocolEndpoint.ProtocolType */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_ProtocolType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650C, /* code */
    MI_T("ProtocolType"), /* name */
    CIM_ProtocolEndpoint_ProtocolType_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_ProtocolType_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, ProtocolType), /* offset */
    MI_T("CIM_ProtocolEndpoint"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

/* property CIM_ProtocolEndpoint.ProtocolIFType */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_ProtocolIFType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650E, /* code */
    MI_T("ProtocolIFType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, ProtocolIFType), /* offset */
    MI_T("CIM_ProtocolEndpoint"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_ProtocolEndpoint_OtherTypeDescription_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_OtherTypeDescription_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_ProtocolEndpoint_OtherTypeDescription_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_OtherTypeDescription_quals[] =
{
    &CIM_ProtocolEndpoint_OtherTypeDescription_MaxLen_qual,
};

/* property CIM_ProtocolEndpoint.OtherTypeDescription */
static MI_CONST MI_PropertyDecl CIM_ProtocolEndpoint_OtherTypeDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6E14, /* code */
    MI_T("OtherTypeDescription"), /* name */
    CIM_ProtocolEndpoint_OtherTypeDescription_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_OtherTypeDescription_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_ProtocolEndpoint, OtherTypeDescription), /* offset */
    MI_T("CIM_ProtocolEndpoint"), /* origin */
    MI_T("CIM_ProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_ProtocolEndpoint_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ProtocolEndpoint_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ProtocolEndpoint_Name_prop,
    &CIM_ProtocolEndpoint_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_ProtocolEndpoint_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_ProtocolEndpoint_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_ServiceAccessPoint_SystemCreationClassName_prop,
    &CIM_ServiceAccessPoint_SystemName_prop,
    &CIM_ServiceAccessPoint_CreationClassName_prop,
    &CIM_ProtocolEndpoint_NameFormat_prop,
    &CIM_ProtocolEndpoint_ProtocolType_prop,
    &CIM_ProtocolEndpoint_ProtocolIFType_prop,
    &CIM_ProtocolEndpoint_OtherTypeDescription_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_ProtocolEndpoint_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_UMLPackagePath_qual_value = MI_T("CIM::Core::Service");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_ProtocolEndpoint_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_ProtocolEndpoint_Version_qual_value = MI_T("2.15.0");

static MI_CONST MI_Qualifier CIM_ProtocolEndpoint_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_ProtocolEndpoint_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_ProtocolEndpoint_quals[] =
{
    &CIM_ProtocolEndpoint_UMLPackagePath_qual,
    &CIM_ProtocolEndpoint_Version_qual,
};

/* class CIM_ProtocolEndpoint */
MI_CONST MI_ClassDecl CIM_ProtocolEndpoint_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00637414, /* code */
    MI_T("CIM_ProtocolEndpoint"), /* name */
    CIM_ProtocolEndpoint_quals, /* qualifiers */
    MI_COUNT(CIM_ProtocolEndpoint_quals), /* numQualifiers */
    CIM_ProtocolEndpoint_props, /* properties */
    MI_COUNT(CIM_ProtocolEndpoint_props), /* numProperties */
    sizeof(CIM_ProtocolEndpoint), /* size */
    MI_T("CIM_ServiceAccessPoint"), /* superClass */
    &CIM_ServiceAccessPoint_rtti, /* superClassDecl */
    CIM_ProtocolEndpoint_meths, /* methods */
    MI_COUNT(CIM_ProtocolEndpoint_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_LANEndpoint
**
**==============================================================================
*/

/* property CIM_LANEndpoint.LANID */
static MI_CONST MI_PropertyDecl CIM_LANEndpoint_LANID_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C6405, /* code */
    MI_T("LANID"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LANEndpoint, LANID), /* offset */
    MI_T("CIM_LANEndpoint"), /* origin */
    MI_T("CIM_LANEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LANEndpoint_LANType_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ProtocolEndpoint.ProtocolType"),
};

static MI_CONST MI_ConstStringA CIM_LANEndpoint_LANType_Deprecated_qual_value =
{
    CIM_LANEndpoint_LANType_Deprecated_qual_data_value,
    MI_COUNT(CIM_LANEndpoint_LANType_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LANEndpoint_LANType_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LANEndpoint_LANType_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LANEndpoint_LANType_quals[] =
{
    &CIM_LANEndpoint_LANType_Deprecated_qual,
};

/* property CIM_LANEndpoint.LANType */
static MI_CONST MI_PropertyDecl CIM_LANEndpoint_LANType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C6507, /* code */
    MI_T("LANType"), /* name */
    CIM_LANEndpoint_LANType_quals, /* qualifiers */
    MI_COUNT(CIM_LANEndpoint_LANType_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LANEndpoint, LANType), /* offset */
    MI_T("CIM_LANEndpoint"), /* origin */
    MI_T("CIM_LANEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LANEndpoint_OtherLANType_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ProtocolEndpoint.OtherTypeDescription"),
};

static MI_CONST MI_ConstStringA CIM_LANEndpoint_OtherLANType_Deprecated_qual_value =
{
    CIM_LANEndpoint_OtherLANType_Deprecated_qual_data_value,
    MI_COUNT(CIM_LANEndpoint_OtherLANType_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_LANEndpoint_OtherLANType_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LANEndpoint_OtherLANType_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LANEndpoint_OtherLANType_quals[] =
{
    &CIM_LANEndpoint_OtherLANType_Deprecated_qual,
};

/* property CIM_LANEndpoint.OtherLANType */
static MI_CONST MI_PropertyDecl CIM_LANEndpoint_OtherLANType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F650C, /* code */
    MI_T("OtherLANType"), /* name */
    CIM_LANEndpoint_OtherLANType_quals, /* qualifiers */
    MI_COUNT(CIM_LANEndpoint_OtherLANType_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LANEndpoint, OtherLANType), /* offset */
    MI_T("CIM_LANEndpoint"), /* origin */
    MI_T("CIM_LANEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LANEndpoint_MACAddress_MaxLen_qual_value = 12U;

static MI_CONST MI_Qualifier CIM_LANEndpoint_MACAddress_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LANEndpoint_MACAddress_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LANEndpoint_MACAddress_quals[] =
{
    &CIM_LANEndpoint_MACAddress_MaxLen_qual,
};

/* property CIM_LANEndpoint.MACAddress */
static MI_CONST MI_PropertyDecl CIM_LANEndpoint_MACAddress_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D730A, /* code */
    MI_T("MACAddress"), /* name */
    CIM_LANEndpoint_MACAddress_quals, /* qualifiers */
    MI_COUNT(CIM_LANEndpoint_MACAddress_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LANEndpoint, MACAddress), /* offset */
    MI_T("CIM_LANEndpoint"), /* origin */
    MI_T("CIM_LANEndpoint"), /* propagator */
    NULL,
};

/* property CIM_LANEndpoint.AliasAddresses */
static MI_CONST MI_PropertyDecl CIM_LANEndpoint_AliasAddresses_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061730E, /* code */
    MI_T("AliasAddresses"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LANEndpoint, AliasAddresses), /* offset */
    MI_T("CIM_LANEndpoint"), /* origin */
    MI_T("CIM_LANEndpoint"), /* propagator */
    NULL,
};

/* property CIM_LANEndpoint.GroupAddresses */
static MI_CONST MI_PropertyDecl CIM_LANEndpoint_GroupAddresses_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0067730E, /* code */
    MI_T("GroupAddresses"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LANEndpoint, GroupAddresses), /* offset */
    MI_T("CIM_LANEndpoint"), /* origin */
    MI_T("CIM_LANEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LANEndpoint_MaxDataSize_Units_qual_value = MI_T("Bits");

static MI_CONST MI_Qualifier CIM_LANEndpoint_MaxDataSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_LANEndpoint_MaxDataSize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LANEndpoint_MaxDataSize_quals[] =
{
    &CIM_LANEndpoint_MaxDataSize_Units_qual,
};

/* property CIM_LANEndpoint.MaxDataSize */
static MI_CONST MI_PropertyDecl CIM_LANEndpoint_MaxDataSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D650B, /* code */
    MI_T("MaxDataSize"), /* name */
    CIM_LANEndpoint_MaxDataSize_quals, /* qualifiers */
    MI_COUNT(CIM_LANEndpoint_MaxDataSize_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LANEndpoint, MaxDataSize), /* offset */
    MI_T("CIM_LANEndpoint"), /* origin */
    MI_T("CIM_LANEndpoint"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_LANEndpoint_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ProtocolEndpoint_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ProtocolEndpoint_Name_prop,
    &CIM_ProtocolEndpoint_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_ProtocolEndpoint_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_ProtocolEndpoint_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_ServiceAccessPoint_SystemCreationClassName_prop,
    &CIM_ServiceAccessPoint_SystemName_prop,
    &CIM_ServiceAccessPoint_CreationClassName_prop,
    &CIM_ProtocolEndpoint_NameFormat_prop,
    &CIM_ProtocolEndpoint_ProtocolType_prop,
    &CIM_ProtocolEndpoint_ProtocolIFType_prop,
    &CIM_ProtocolEndpoint_OtherTypeDescription_prop,
    &CIM_LANEndpoint_LANID_prop,
    &CIM_LANEndpoint_LANType_prop,
    &CIM_LANEndpoint_OtherLANType_prop,
    &CIM_LANEndpoint_MACAddress_prop,
    &CIM_LANEndpoint_AliasAddresses_prop,
    &CIM_LANEndpoint_GroupAddresses_prop,
    &CIM_LANEndpoint_MaxDataSize_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_LANEndpoint_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_LANEndpoint_UMLPackagePath_qual_value = MI_T("CIM::Network::ProtocolEndpoints");

static MI_CONST MI_Qualifier CIM_LANEndpoint_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_LANEndpoint_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_LANEndpoint_Version_qual_value = MI_T("2.7.0");

static MI_CONST MI_Qualifier CIM_LANEndpoint_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_LANEndpoint_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LANEndpoint_quals[] =
{
    &CIM_LANEndpoint_UMLPackagePath_qual,
    &CIM_LANEndpoint_Version_qual,
};

/* class CIM_LANEndpoint */
MI_CONST MI_ClassDecl CIM_LANEndpoint_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0063740F, /* code */
    MI_T("CIM_LANEndpoint"), /* name */
    CIM_LANEndpoint_quals, /* qualifiers */
    MI_COUNT(CIM_LANEndpoint_quals), /* numQualifiers */
    CIM_LANEndpoint_props, /* properties */
    MI_COUNT(CIM_LANEndpoint_props), /* numProperties */
    sizeof(CIM_LANEndpoint), /* size */
    MI_T("CIM_ProtocolEndpoint"), /* superClass */
    &CIM_ProtocolEndpoint_rtti, /* superClassDecl */
    CIM_LANEndpoint_meths, /* methods */
    MI_COUNT(CIM_LANEndpoint_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_LANEndpoint
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_LANEndpoint_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_LANEndpoint_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_LANEndpoint_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_LANEndpoint_Caption_quals[] =
{
    &SCX_LANEndpoint_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_LANEndpoint_Caption_value = MI_T("LAN Endpoint caption information");

/* property SCX_LANEndpoint.Caption */
static MI_CONST MI_PropertyDecl SCX_LANEndpoint_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_LANEndpoint_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_LANEndpoint_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LANEndpoint, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_LANEndpoint"), /* propagator */
    &SCX_LANEndpoint_Caption_value,
};

static MI_CONST MI_Char* SCX_LANEndpoint_Description_value = MI_T("LAN Endpoint description information");

/* property SCX_LANEndpoint.Description */
static MI_CONST MI_PropertyDecl SCX_LANEndpoint_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LANEndpoint, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_LANEndpoint"), /* propagator */
    &SCX_LANEndpoint_Description_value,
};

/* property SCX_LANEndpoint.FormattedMACAddress */
static MI_CONST MI_PropertyDecl SCX_LANEndpoint_FormattedMACAddress_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00667313, /* code */
    MI_T("FormattedMACAddress"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LANEndpoint, FormattedMACAddress), /* offset */
    MI_T("SCX_LANEndpoint"), /* origin */
    MI_T("SCX_LANEndpoint"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_LANEndpoint_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_LANEndpoint_Caption_prop,
    &SCX_LANEndpoint_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ProtocolEndpoint_Name_prop,
    &CIM_ProtocolEndpoint_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_ProtocolEndpoint_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_ProtocolEndpoint_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_ServiceAccessPoint_SystemCreationClassName_prop,
    &CIM_ServiceAccessPoint_SystemName_prop,
    &CIM_ServiceAccessPoint_CreationClassName_prop,
    &CIM_ProtocolEndpoint_NameFormat_prop,
    &CIM_ProtocolEndpoint_ProtocolType_prop,
    &CIM_ProtocolEndpoint_ProtocolIFType_prop,
    &CIM_ProtocolEndpoint_OtherTypeDescription_prop,
    &CIM_LANEndpoint_LANID_prop,
    &CIM_LANEndpoint_LANType_prop,
    &CIM_LANEndpoint_OtherLANType_prop,
    &CIM_LANEndpoint_MACAddress_prop,
    &CIM_LANEndpoint_AliasAddresses_prop,
    &CIM_LANEndpoint_GroupAddresses_prop,
    &CIM_LANEndpoint_MaxDataSize_prop,
    &SCX_LANEndpoint_FormattedMACAddress_prop,
};

/* parameter SCX_LANEndpoint.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl SCX_LANEndpoint_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LANEndpoint_RequestStateChange, RequestedState), /* offset */
};

/* parameter SCX_LANEndpoint.RequestStateChange(): Job */
static MI_CONST MI_ParameterDecl SCX_LANEndpoint_RequestStateChange_Job_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006A6203, /* code */
    MI_T("Job"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REFERENCE, /* type */
    MI_T("CIM_ConcreteJob"), /* className */
    0, /* subscript */
    offsetof(SCX_LANEndpoint_RequestStateChange, Job), /* offset */
};

/* parameter SCX_LANEndpoint.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl SCX_LANEndpoint_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LANEndpoint_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter SCX_LANEndpoint.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_LANEndpoint_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LANEndpoint_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_LANEndpoint_RequestStateChange_params[] =
{
    &SCX_LANEndpoint_RequestStateChange_MIReturn_param,
    &SCX_LANEndpoint_RequestStateChange_RequestedState_param,
    &SCX_LANEndpoint_RequestStateChange_Job_param,
    &SCX_LANEndpoint_RequestStateChange_TimeoutPeriod_param,
};

/* method SCX_LANEndpoint.RequestStateChange() */
MI_CONST MI_MethodDecl SCX_LANEndpoint_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_LANEndpoint_RequestStateChange_params, /* parameters */
    MI_COUNT(SCX_LANEndpoint_RequestStateChange_params), /* numParameters */
    sizeof(SCX_LANEndpoint_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_LANEndpoint_Invoke_RequestStateChange, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_LANEndpoint_meths[] =
{
    &SCX_LANEndpoint_RequestStateChange_rtti,
};

static MI_CONST MI_ProviderFT SCX_LANEndpoint_funcs =
{
  (MI_ProviderFT_Load)SCX_LANEndpoint_Load,
  (MI_ProviderFT_Unload)SCX_LANEndpoint_Unload,
  (MI_ProviderFT_GetInstance)SCX_LANEndpoint_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_LANEndpoint_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_LANEndpoint_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_LANEndpoint_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_LANEndpoint_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_LANEndpoint_UMLPackagePath_qual_value = MI_T("CIM::Network::ProtocolEndpoints");

static MI_CONST MI_Qualifier SCX_LANEndpoint_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_LANEndpoint_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_LANEndpoint_Version_qual_value = MI_T("1.4.0");

static MI_CONST MI_Qualifier SCX_LANEndpoint_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_LANEndpoint_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_LANEndpoint_quals[] =
{
    &SCX_LANEndpoint_UMLPackagePath_qual,
    &SCX_LANEndpoint_Version_qual,
};

/* class SCX_LANEndpoint */
MI_CONST MI_ClassDecl SCX_LANEndpoint_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0073740F, /* code */
    MI_T("SCX_LANEndpoint"), /* name */
    SCX_LANEndpoint_quals, /* qualifiers */
    MI_COUNT(SCX_LANEndpoint_quals), /* numQualifiers */
    SCX_LANEndpoint_props, /* properties */
    MI_COUNT(SCX_LANEndpoint_props), /* numProperties */
    sizeof(SCX_LANEndpoint), /* size */
    MI_T("CIM_LANEndpoint"), /* superClass */
    &CIM_LANEndpoint_rtti, /* superClassDecl */
    SCX_LANEndpoint_meths, /* methods */
    MI_COUNT(SCX_LANEndpoint_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_LANEndpoint_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_IPProtocolEndpoint
**
**==============================================================================
*/

static MI_CONST MI_Char* CIM_IPProtocolEndpoint_ProtocolIFType_Override_qual_value = MI_T("ProtocolIFType");

static MI_CONST MI_Qualifier CIM_IPProtocolEndpoint_ProtocolIFType_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_IPProtocolEndpoint_ProtocolIFType_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_IPProtocolEndpoint_ProtocolIFType_quals[] =
{
    &CIM_IPProtocolEndpoint_ProtocolIFType_Override_qual,
};

static MI_CONST MI_Uint16 CIM_IPProtocolEndpoint_ProtocolIFType_value = 4096;

/* property CIM_IPProtocolEndpoint.ProtocolIFType */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_ProtocolIFType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650E, /* code */
    MI_T("ProtocolIFType"), /* name */
    CIM_IPProtocolEndpoint_ProtocolIFType_quals, /* qualifiers */
    MI_COUNT(CIM_IPProtocolEndpoint_ProtocolIFType_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, ProtocolIFType), /* offset */
    MI_T("CIM_ProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    &CIM_IPProtocolEndpoint_ProtocolIFType_value,
};

/* property CIM_IPProtocolEndpoint.IPv4Address */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_IPv4Address_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069730B, /* code */
    MI_T("IPv4Address"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, IPv4Address), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

/* property CIM_IPProtocolEndpoint.IPv6Address */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_IPv6Address_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069730B, /* code */
    MI_T("IPv6Address"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, IPv6Address), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_IPProtocolEndpoint_Address_Deprecated_qual_data_value[] =
{
    MI_T("CIM_IPProtocolEndpoint.IPv4Address"),
    MI_T("CIM_IPProtocolEndpoint.IPv6Address"),
};

static MI_CONST MI_ConstStringA CIM_IPProtocolEndpoint_Address_Deprecated_qual_value =
{
    CIM_IPProtocolEndpoint_Address_Deprecated_qual_data_value,
    MI_COUNT(CIM_IPProtocolEndpoint_Address_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_IPProtocolEndpoint_Address_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_IPProtocolEndpoint_Address_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_IPProtocolEndpoint_Address_quals[] =
{
    &CIM_IPProtocolEndpoint_Address_Deprecated_qual,
};

/* property CIM_IPProtocolEndpoint.Address */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_Address_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00617307, /* code */
    MI_T("Address"), /* name */
    CIM_IPProtocolEndpoint_Address_quals, /* qualifiers */
    MI_COUNT(CIM_IPProtocolEndpoint_Address_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, Address), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

/* property CIM_IPProtocolEndpoint.SubnetMask */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_SubnetMask_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736B0A, /* code */
    MI_T("SubnetMask"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, SubnetMask), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

/* property CIM_IPProtocolEndpoint.PrefixLength */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_PrefixLength_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070680C, /* code */
    MI_T("PrefixLength"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, PrefixLength), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_IPProtocolEndpoint_AddressType_Deprecated_qual_data_value[] =
{
    MI_T("No value"),
};

static MI_CONST MI_ConstStringA CIM_IPProtocolEndpoint_AddressType_Deprecated_qual_value =
{
    CIM_IPProtocolEndpoint_AddressType_Deprecated_qual_data_value,
    MI_COUNT(CIM_IPProtocolEndpoint_AddressType_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_IPProtocolEndpoint_AddressType_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_IPProtocolEndpoint_AddressType_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_IPProtocolEndpoint_AddressType_quals[] =
{
    &CIM_IPProtocolEndpoint_AddressType_Deprecated_qual,
};

/* property CIM_IPProtocolEndpoint.AddressType */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_AddressType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061650B, /* code */
    MI_T("AddressType"), /* name */
    CIM_IPProtocolEndpoint_AddressType_quals, /* qualifiers */
    MI_COUNT(CIM_IPProtocolEndpoint_AddressType_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, AddressType), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_IPProtocolEndpoint_IPVersionSupport_Deprecated_qual_data_value[] =
{
    MI_T("CIM_ProtocolEndpoint.ProtocolIFType"),
};

static MI_CONST MI_ConstStringA CIM_IPProtocolEndpoint_IPVersionSupport_Deprecated_qual_value =
{
    CIM_IPProtocolEndpoint_IPVersionSupport_Deprecated_qual_data_value,
    MI_COUNT(CIM_IPProtocolEndpoint_IPVersionSupport_Deprecated_qual_data_value),
};

static MI_CONST MI_Qualifier CIM_IPProtocolEndpoint_IPVersionSupport_Deprecated_qual =
{
    MI_T("Deprecated"),
    MI_STRINGA,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_IPProtocolEndpoint_IPVersionSupport_Deprecated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_IPProtocolEndpoint_IPVersionSupport_quals[] =
{
    &CIM_IPProtocolEndpoint_IPVersionSupport_Deprecated_qual,
};

/* property CIM_IPProtocolEndpoint.IPVersionSupport */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_IPVersionSupport_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00697410, /* code */
    MI_T("IPVersionSupport"), /* name */
    CIM_IPProtocolEndpoint_IPVersionSupport_quals, /* qualifiers */
    MI_COUNT(CIM_IPProtocolEndpoint_IPVersionSupport_quals), /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, IPVersionSupport), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint16 CIM_IPProtocolEndpoint_AddressOrigin_value = 0;

/* property CIM_IPProtocolEndpoint.AddressOrigin */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_AddressOrigin_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00616E0D, /* code */
    MI_T("AddressOrigin"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, AddressOrigin), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    &CIM_IPProtocolEndpoint_AddressOrigin_value,
};

/* property CIM_IPProtocolEndpoint.IPv6AddressType */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_IPv6AddressType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069650F, /* code */
    MI_T("IPv6AddressType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, IPv6AddressType), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

/* property CIM_IPProtocolEndpoint.IPv6SubnetPrefixLength */
static MI_CONST MI_PropertyDecl CIM_IPProtocolEndpoint_IPv6SubnetPrefixLength_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00696816, /* code */
    MI_T("IPv6SubnetPrefixLength"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_IPProtocolEndpoint, IPv6SubnetPrefixLength), /* offset */
    MI_T("CIM_IPProtocolEndpoint"), /* origin */
    MI_T("CIM_IPProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_IPProtocolEndpoint_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ProtocolEndpoint_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ProtocolEndpoint_Name_prop,
    &CIM_ProtocolEndpoint_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_ProtocolEndpoint_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_ProtocolEndpoint_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_ServiceAccessPoint_SystemCreationClassName_prop,
    &CIM_ServiceAccessPoint_SystemName_prop,
    &CIM_ServiceAccessPoint_CreationClassName_prop,
    &CIM_ProtocolEndpoint_NameFormat_prop,
    &CIM_ProtocolEndpoint_ProtocolType_prop,
    &CIM_IPProtocolEndpoint_ProtocolIFType_prop,
    &CIM_ProtocolEndpoint_OtherTypeDescription_prop,
    &CIM_IPProtocolEndpoint_IPv4Address_prop,
    &CIM_IPProtocolEndpoint_IPv6Address_prop,
    &CIM_IPProtocolEndpoint_Address_prop,
    &CIM_IPProtocolEndpoint_SubnetMask_prop,
    &CIM_IPProtocolEndpoint_PrefixLength_prop,
    &CIM_IPProtocolEndpoint_AddressType_prop,
    &CIM_IPProtocolEndpoint_IPVersionSupport_prop,
    &CIM_IPProtocolEndpoint_AddressOrigin_prop,
    &CIM_IPProtocolEndpoint_IPv6AddressType_prop,
    &CIM_IPProtocolEndpoint_IPv6SubnetPrefixLength_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_IPProtocolEndpoint_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_IPProtocolEndpoint_UMLPackagePath_qual_value = MI_T("CIM::Network::ProtocolEndpoints");

static MI_CONST MI_Qualifier CIM_IPProtocolEndpoint_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_IPProtocolEndpoint_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_IPProtocolEndpoint_Version_qual_value = MI_T("2.32.0");

static MI_CONST MI_Qualifier CIM_IPProtocolEndpoint_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_IPProtocolEndpoint_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_IPProtocolEndpoint_quals[] =
{
    &CIM_IPProtocolEndpoint_UMLPackagePath_qual,
    &CIM_IPProtocolEndpoint_Version_qual,
};

/* class CIM_IPProtocolEndpoint */
MI_CONST MI_ClassDecl CIM_IPProtocolEndpoint_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00637416, /* code */
    MI_T("CIM_IPProtocolEndpoint"), /* name */
    CIM_IPProtocolEndpoint_quals, /* qualifiers */
    MI_COUNT(CIM_IPProtocolEndpoint_quals), /* numQualifiers */
    CIM_IPProtocolEndpoint_props, /* properties */
    MI_COUNT(CIM_IPProtocolEndpoint_props), /* numProperties */
    sizeof(CIM_IPProtocolEndpoint), /* size */
    MI_T("CIM_ProtocolEndpoint"), /* superClass */
    &CIM_ProtocolEndpoint_rtti, /* superClassDecl */
    CIM_IPProtocolEndpoint_meths, /* methods */
    MI_COUNT(CIM_IPProtocolEndpoint_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_IPProtocolEndpoint
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_IPProtocolEndpoint_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_IPProtocolEndpoint_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_IPProtocolEndpoint_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_IPProtocolEndpoint_Caption_quals[] =
{
    &SCX_IPProtocolEndpoint_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_IPProtocolEndpoint_Caption_value = MI_T("IP protocol endpoint information");

/* property SCX_IPProtocolEndpoint.Caption */
static MI_CONST MI_PropertyDecl SCX_IPProtocolEndpoint_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_IPProtocolEndpoint_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_IPProtocolEndpoint_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_IPProtocolEndpoint, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_IPProtocolEndpoint"), /* propagator */
    &SCX_IPProtocolEndpoint_Caption_value,
};

static MI_CONST MI_Char* SCX_IPProtocolEndpoint_Description_value = MI_T("Properties of an IP protocol connection endpoint");

/* property SCX_IPProtocolEndpoint.Description */
static MI_CONST MI_PropertyDecl SCX_IPProtocolEndpoint_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_IPProtocolEndpoint, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_IPProtocolEndpoint"), /* propagator */
    &SCX_IPProtocolEndpoint_Description_value,
};

/* property SCX_IPProtocolEndpoint.IPv4BroadcastAddress */
static MI_CONST MI_PropertyDecl SCX_IPProtocolEndpoint_IPv4BroadcastAddress_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00697314, /* code */
    MI_T("IPv4BroadcastAddress"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_IPProtocolEndpoint, IPv4BroadcastAddress), /* offset */
    MI_T("SCX_IPProtocolEndpoint"), /* origin */
    MI_T("SCX_IPProtocolEndpoint"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_IPProtocolEndpoint_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_IPProtocolEndpoint_Caption_prop,
    &SCX_IPProtocolEndpoint_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_ProtocolEndpoint_Name_prop,
    &CIM_ProtocolEndpoint_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_ProtocolEndpoint_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_ProtocolEndpoint_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_ServiceAccessPoint_SystemCreationClassName_prop,
    &CIM_ServiceAccessPoint_SystemName_prop,
    &CIM_ServiceAccessPoint_CreationClassName_prop,
    &CIM_ProtocolEndpoint_NameFormat_prop,
    &CIM_ProtocolEndpoint_ProtocolType_prop,
    &CIM_IPProtocolEndpoint_ProtocolIFType_prop,
    &CIM_ProtocolEndpoint_OtherTypeDescription_prop,
    &CIM_IPProtocolEndpoint_IPv4Address_prop,
    &CIM_IPProtocolEndpoint_IPv6Address_prop,
    &CIM_IPProtocolEndpoint_Address_prop,
    &CIM_IPProtocolEndpoint_SubnetMask_prop,
    &CIM_IPProtocolEndpoint_PrefixLength_prop,
    &CIM_IPProtocolEndpoint_AddressType_prop,
    &CIM_IPProtocolEndpoint_IPVersionSupport_prop,
    &CIM_IPProtocolEndpoint_AddressOrigin_prop,
    &CIM_IPProtocolEndpoint_IPv6AddressType_prop,
    &CIM_IPProtocolEndpoint_IPv6SubnetPrefixLength_prop,
    &SCX_IPProtocolEndpoint_IPv4BroadcastAddress_prop,
};

/* parameter SCX_IPProtocolEndpoint.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl SCX_IPProtocolEndpoint_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_IPProtocolEndpoint_RequestStateChange, RequestedState), /* offset */
};

/* parameter SCX_IPProtocolEndpoint.RequestStateChange(): Job */
static MI_CONST MI_ParameterDecl SCX_IPProtocolEndpoint_RequestStateChange_Job_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006A6203, /* code */
    MI_T("Job"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REFERENCE, /* type */
    MI_T("CIM_ConcreteJob"), /* className */
    0, /* subscript */
    offsetof(SCX_IPProtocolEndpoint_RequestStateChange, Job), /* offset */
};

/* parameter SCX_IPProtocolEndpoint.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl SCX_IPProtocolEndpoint_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_IPProtocolEndpoint_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter SCX_IPProtocolEndpoint.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_IPProtocolEndpoint_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_IPProtocolEndpoint_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_IPProtocolEndpoint_RequestStateChange_params[] =
{
    &SCX_IPProtocolEndpoint_RequestStateChange_MIReturn_param,
    &SCX_IPProtocolEndpoint_RequestStateChange_RequestedState_param,
    &SCX_IPProtocolEndpoint_RequestStateChange_Job_param,
    &SCX_IPProtocolEndpoint_RequestStateChange_TimeoutPeriod_param,
};

/* method SCX_IPProtocolEndpoint.RequestStateChange() */
MI_CONST MI_MethodDecl SCX_IPProtocolEndpoint_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_IPProtocolEndpoint_RequestStateChange_params, /* parameters */
    MI_COUNT(SCX_IPProtocolEndpoint_RequestStateChange_params), /* numParameters */
    sizeof(SCX_IPProtocolEndpoint_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_IPProtocolEndpoint_Invoke_RequestStateChange, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_IPProtocolEndpoint_meths[] =
{
    &SCX_IPProtocolEndpoint_RequestStateChange_rtti,
};

static MI_CONST MI_ProviderFT SCX_IPProtocolEndpoint_funcs =
{
  (MI_ProviderFT_Load)SCX_IPProtocolEndpoint_Load,
  (MI_ProviderFT_Unload)SCX_IPProtocolEndpoint_Unload,
  (MI_ProviderFT_GetInstance)SCX_IPProtocolEndpoint_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_IPProtocolEndpoint_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_IPProtocolEndpoint_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_IPProtocolEndpoint_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_IPProtocolEndpoint_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_IPProtocolEndpoint_UMLPackagePath_qual_value = MI_T("CIM::Network::ProtocolEndpoints");

static MI_CONST MI_Qualifier SCX_IPProtocolEndpoint_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_IPProtocolEndpoint_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_IPProtocolEndpoint_Version_qual_value = MI_T("1.4.0");

static MI_CONST MI_Qualifier SCX_IPProtocolEndpoint_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_IPProtocolEndpoint_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_IPProtocolEndpoint_quals[] =
{
    &SCX_IPProtocolEndpoint_UMLPackagePath_qual,
    &SCX_IPProtocolEndpoint_Version_qual,
};

/* class SCX_IPProtocolEndpoint */
MI_CONST MI_ClassDecl SCX_IPProtocolEndpoint_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00737416, /* code */
    MI_T("SCX_IPProtocolEndpoint"), /* name */
    SCX_IPProtocolEndpoint_quals, /* qualifiers */
    MI_COUNT(SCX_IPProtocolEndpoint_quals), /* numQualifiers */
    SCX_IPProtocolEndpoint_props, /* properties */
    MI_COUNT(SCX_IPProtocolEndpoint_props), /* numProperties */
    sizeof(SCX_IPProtocolEndpoint), /* size */
    MI_T("CIM_IPProtocolEndpoint"), /* superClass */
    &CIM_IPProtocolEndpoint_rtti, /* superClassDecl */
    SCX_IPProtocolEndpoint_meths, /* methods */
    MI_COUNT(SCX_IPProtocolEndpoint_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_IPProtocolEndpoint_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_LogicalFile
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_LogicalFile_Name_MaxLen_qual_value = 1024U;

static MI_CONST MI_Qualifier CIM_LogicalFile_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalFile_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_LogicalFile_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_LogicalFile_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_LogicalFile_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_Name_quals[] =
{
    &CIM_LogicalFile_Name_MaxLen_qual,
    &CIM_LogicalFile_Name_Override_qual,
};

/* property CIM_LogicalFile.Name */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_LogicalFile_Name_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalFile_CSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalFile_CSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalFile_CSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_LogicalFile_CSCreationClassName_Propagated_qual_value = MI_T("CIM_FileSystem.CSCreationClassName");

static MI_CONST MI_Qualifier CIM_LogicalFile_CSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalFile_CSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_CSCreationClassName_quals[] =
{
    &CIM_LogicalFile_CSCreationClassName_MaxLen_qual,
    &CIM_LogicalFile_CSCreationClassName_Propagated_qual,
};

/* property CIM_LogicalFile.CSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_CSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636513, /* code */
    MI_T("CSCreationClassName"), /* name */
    CIM_LogicalFile_CSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_CSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, CSCreationClassName), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalFile_CSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalFile_CSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalFile_CSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_LogicalFile_CSName_Propagated_qual_value = MI_T("CIM_FileSystem.CSName");

static MI_CONST MI_Qualifier CIM_LogicalFile_CSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalFile_CSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_CSName_quals[] =
{
    &CIM_LogicalFile_CSName_MaxLen_qual,
    &CIM_LogicalFile_CSName_Propagated_qual,
};

/* property CIM_LogicalFile.CSName */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_CSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636506, /* code */
    MI_T("CSName"), /* name */
    CIM_LogicalFile_CSName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_CSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, CSName), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalFile_FSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalFile_FSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalFile_FSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_LogicalFile_FSCreationClassName_Propagated_qual_value = MI_T("CIM_FileSystem.CreationClassName");

static MI_CONST MI_Qualifier CIM_LogicalFile_FSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalFile_FSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_FSCreationClassName_quals[] =
{
    &CIM_LogicalFile_FSCreationClassName_MaxLen_qual,
    &CIM_LogicalFile_FSCreationClassName_Propagated_qual,
};

/* property CIM_LogicalFile.FSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_FSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00666513, /* code */
    MI_T("FSCreationClassName"), /* name */
    CIM_LogicalFile_FSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_FSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, FSCreationClassName), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalFile_FSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalFile_FSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalFile_FSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_LogicalFile_FSName_Propagated_qual_value = MI_T("CIM_FileSystem.Name");

static MI_CONST MI_Qualifier CIM_LogicalFile_FSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_LogicalFile_FSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_FSName_quals[] =
{
    &CIM_LogicalFile_FSName_MaxLen_qual,
    &CIM_LogicalFile_FSName_Propagated_qual,
};

/* property CIM_LogicalFile.FSName */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_FSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00666506, /* code */
    MI_T("FSName"), /* name */
    CIM_LogicalFile_FSName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_FSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, FSName), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_LogicalFile_CreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_LogicalFile_CreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_LogicalFile_CreationClassName_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_CreationClassName_quals[] =
{
    &CIM_LogicalFile_CreationClassName_MaxLen_qual,
};

/* property CIM_LogicalFile.CreationClassName */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_CreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636511, /* code */
    MI_T("CreationClassName"), /* name */
    CIM_LogicalFile_CreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_CreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, CreationClassName), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_LogicalFile_FileSize_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_LogicalFile_FileSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_LogicalFile_FileSize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_FileSize_quals[] =
{
    &CIM_LogicalFile_FileSize_Units_qual,
};

/* property CIM_LogicalFile.FileSize */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_FileSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00666508, /* code */
    MI_T("FileSize"), /* name */
    CIM_LogicalFile_FileSize_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_FileSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, FileSize), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.CreationDate */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_CreationDate_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063650C, /* code */
    MI_T("CreationDate"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, CreationDate), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.LastModified */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_LastModified_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C640C, /* code */
    MI_T("LastModified"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, LastModified), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.LastAccessed */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_LastAccessed_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C640C, /* code */
    MI_T("LastAccessed"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, LastAccessed), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.Readable */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_Readable_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726508, /* code */
    MI_T("Readable"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, Readable), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.Writeable */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_Writeable_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00776509, /* code */
    MI_T("Writeable"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, Writeable), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.Executable */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_Executable_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065650A, /* code */
    MI_T("Executable"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, Executable), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.CompressionMethod */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_CompressionMethod_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636411, /* code */
    MI_T("CompressionMethod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, CompressionMethod), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.EncryptionMethod */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_EncryptionMethod_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00656410, /* code */
    MI_T("EncryptionMethod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, EncryptionMethod), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

/* property CIM_LogicalFile.InUseCount */
static MI_CONST MI_PropertyDecl CIM_LogicalFile_InUseCount_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0069740A, /* code */
    MI_T("InUseCount"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_LogicalFile, InUseCount), /* offset */
    MI_T("CIM_LogicalFile"), /* origin */
    MI_T("CIM_LogicalFile"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_LogicalFile_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_LogicalFile_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_LogicalFile_CSCreationClassName_prop,
    &CIM_LogicalFile_CSName_prop,
    &CIM_LogicalFile_FSCreationClassName_prop,
    &CIM_LogicalFile_FSName_prop,
    &CIM_LogicalFile_CreationClassName_prop,
    &CIM_LogicalFile_FileSize_prop,
    &CIM_LogicalFile_CreationDate_prop,
    &CIM_LogicalFile_LastModified_prop,
    &CIM_LogicalFile_LastAccessed_prop,
    &CIM_LogicalFile_Readable_prop,
    &CIM_LogicalFile_Writeable_prop,
    &CIM_LogicalFile_Executable_prop,
    &CIM_LogicalFile_CompressionMethod_prop,
    &CIM_LogicalFile_EncryptionMethod_prop,
    &CIM_LogicalFile_InUseCount_prop,
};

static MI_CONST MI_Char* CIM_LogicalFile_UMLPackagePath_qual_value = MI_T("CIM::System::FileElements");

static MI_CONST MI_Qualifier CIM_LogicalFile_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_LogicalFile_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_LogicalFile_Version_qual_value = MI_T("2.6.0");

static MI_CONST MI_Qualifier CIM_LogicalFile_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_LogicalFile_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_LogicalFile_quals[] =
{
    &CIM_LogicalFile_UMLPackagePath_qual,
    &CIM_LogicalFile_Version_qual,
};

/* class CIM_LogicalFile */
MI_CONST MI_ClassDecl CIM_LogicalFile_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0063650F, /* code */
    MI_T("CIM_LogicalFile"), /* name */
    CIM_LogicalFile_quals, /* qualifiers */
    MI_COUNT(CIM_LogicalFile_quals), /* numQualifiers */
    CIM_LogicalFile_props, /* properties */
    MI_COUNT(CIM_LogicalFile_props), /* numProperties */
    sizeof(CIM_LogicalFile), /* size */
    MI_T("CIM_LogicalElement"), /* superClass */
    &CIM_LogicalElement_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_LogFile
**
**==============================================================================
*/

static MI_PropertyDecl MI_CONST* MI_CONST SCX_LogFile_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_LogicalFile_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_LogicalFile_CSCreationClassName_prop,
    &CIM_LogicalFile_CSName_prop,
    &CIM_LogicalFile_FSCreationClassName_prop,
    &CIM_LogicalFile_FSName_prop,
    &CIM_LogicalFile_CreationClassName_prop,
    &CIM_LogicalFile_FileSize_prop,
    &CIM_LogicalFile_CreationDate_prop,
    &CIM_LogicalFile_LastModified_prop,
    &CIM_LogicalFile_LastAccessed_prop,
    &CIM_LogicalFile_Readable_prop,
    &CIM_LogicalFile_Writeable_prop,
    &CIM_LogicalFile_Executable_prop,
    &CIM_LogicalFile_CompressionMethod_prop,
    &CIM_LogicalFile_EncryptionMethod_prop,
    &CIM_LogicalFile_InUseCount_prop,
};

/* parameter SCX_LogFile.GetMatchedRows(): filename */
static MI_CONST MI_ParameterDecl SCX_LogFile_GetMatchedRows_filename_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00666508, /* code */
    MI_T("filename"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LogFile_GetMatchedRows, filename), /* offset */
};

/* parameter SCX_LogFile.GetMatchedRows(): regexps */
static MI_CONST MI_ParameterDecl SCX_LogFile_GetMatchedRows_regexps_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00727307, /* code */
    MI_T("regexps"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LogFile_GetMatchedRows, regexps), /* offset */
};

/* parameter SCX_LogFile.GetMatchedRows(): qid */
static MI_CONST MI_ParameterDecl SCX_LogFile_GetMatchedRows_qid_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00716403, /* code */
    MI_T("qid"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LogFile_GetMatchedRows, qid), /* offset */
};

static MI_CONST MI_Char* SCX_LogFile_GetMatchedRows_rows_ArrayType_qual_value = MI_T("Ordered");

static MI_CONST MI_Qualifier SCX_LogFile_GetMatchedRows_rows_ArrayType_qual =
{
    MI_T("ArrayType"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &SCX_LogFile_GetMatchedRows_rows_ArrayType_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_LogFile_GetMatchedRows_rows_quals[] =
{
    &SCX_LogFile_GetMatchedRows_rows_ArrayType_qual,
};

/* parameter SCX_LogFile.GetMatchedRows(): rows */
static MI_CONST MI_ParameterDecl SCX_LogFile_GetMatchedRows_rows_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00727304, /* code */
    MI_T("rows"), /* name */
    SCX_LogFile_GetMatchedRows_rows_quals, /* qualifiers */
    MI_COUNT(SCX_LogFile_GetMatchedRows_rows_quals), /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LogFile_GetMatchedRows, rows), /* offset */
};

/* parameter SCX_LogFile.GetMatchedRows(): elevationType */
static MI_CONST MI_ParameterDecl SCX_LogFile_GetMatchedRows_elevationType_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0065650D, /* code */
    MI_T("elevationType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LogFile_GetMatchedRows, elevationType), /* offset */
};

/* parameter SCX_LogFile.GetMatchedRows(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_LogFile_GetMatchedRows_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_LogFile_GetMatchedRows, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_LogFile_GetMatchedRows_params[] =
{
    &SCX_LogFile_GetMatchedRows_MIReturn_param,
    &SCX_LogFile_GetMatchedRows_filename_param,
    &SCX_LogFile_GetMatchedRows_regexps_param,
    &SCX_LogFile_GetMatchedRows_qid_param,
    &SCX_LogFile_GetMatchedRows_rows_param,
    &SCX_LogFile_GetMatchedRows_elevationType_param,
};

/* method SCX_LogFile.GetMatchedRows() */
MI_CONST MI_MethodDecl SCX_LogFile_GetMatchedRows_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x0067730E, /* code */
    MI_T("GetMatchedRows"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_LogFile_GetMatchedRows_params, /* parameters */
    MI_COUNT(SCX_LogFile_GetMatchedRows_params), /* numParameters */
    sizeof(SCX_LogFile_GetMatchedRows), /* size */
    MI_UINT32, /* returnType */
    MI_T("SCX_LogFile"), /* origin */
    MI_T("SCX_LogFile"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_LogFile_Invoke_GetMatchedRows, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_LogFile_meths[] =
{
    &SCX_LogFile_GetMatchedRows_rtti,
};

static MI_CONST MI_ProviderFT SCX_LogFile_funcs =
{
  (MI_ProviderFT_Load)SCX_LogFile_Load,
  (MI_ProviderFT_Unload)SCX_LogFile_Unload,
  (MI_ProviderFT_GetInstance)SCX_LogFile_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_LogFile_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_LogFile_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_LogFile_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_LogFile_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_LogFile_UMLPackagePath_qual_value = MI_T("CIM::System::FileElements");

static MI_CONST MI_Qualifier SCX_LogFile_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_LogFile_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_LogFile_Version_qual_value = MI_T("1.3.0");

static MI_CONST MI_Qualifier SCX_LogFile_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_LogFile_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_LogFile_quals[] =
{
    &SCX_LogFile_UMLPackagePath_qual,
    &SCX_LogFile_Version_qual,
};

/* class SCX_LogFile */
MI_CONST MI_ClassDecl SCX_LogFile_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0073650B, /* code */
    MI_T("SCX_LogFile"), /* name */
    SCX_LogFile_quals, /* qualifiers */
    MI_COUNT(SCX_LogFile_quals), /* numQualifiers */
    SCX_LogFile_props, /* properties */
    MI_COUNT(SCX_LogFile_props), /* numProperties */
    sizeof(SCX_LogFile), /* size */
    MI_T("CIM_LogicalFile"), /* superClass */
    &CIM_LogicalFile_rtti, /* superClassDecl */
    SCX_LogFile_meths, /* methods */
    MI_COUNT(SCX_LogFile_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_LogFile_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_MemoryStatisticalInformation
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_MemoryStatisticalInformation_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_MemoryStatisticalInformation_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_Caption_quals[] =
{
    &SCX_MemoryStatisticalInformation_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_Caption_value = MI_T("Memory information");

/* property SCX_MemoryStatisticalInformation.Caption */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_MemoryStatisticalInformation_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    &SCX_MemoryStatisticalInformation_Caption_value,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_Description_value = MI_T("Memory usage and performance statistics");

/* property SCX_MemoryStatisticalInformation.Description */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    &SCX_MemoryStatisticalInformation_Description_value,
};

static MI_CONST MI_Uint32 SCX_MemoryStatisticalInformation_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_MemoryStatisticalInformation_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_MemoryStatisticalInformation_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_Name_quals[] =
{
    &SCX_MemoryStatisticalInformation_Name_MaxLen_qual,
    &SCX_MemoryStatisticalInformation_Name_Override_qual,
};

/* property SCX_MemoryStatisticalInformation.Name */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    SCX_MemoryStatisticalInformation_Name_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, Name), /* offset */
    MI_T("CIM_StatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_AvailableMemory_Units_qual_value = MI_T("MegaBytes");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_AvailableMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_AvailableMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_AvailableMemory_quals[] =
{
    &SCX_MemoryStatisticalInformation_AvailableMemory_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.AvailableMemory */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_AvailableMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061790F, /* code */
    MI_T("AvailableMemory"), /* name */
    SCX_MemoryStatisticalInformation_AvailableMemory_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_AvailableMemory_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, AvailableMemory), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PercentAvailableMemory_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PercentAvailableMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PercentAvailableMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PercentAvailableMemory_quals[] =
{
    &SCX_MemoryStatisticalInformation_PercentAvailableMemory_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PercentAvailableMemory */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PercentAvailableMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707916, /* code */
    MI_T("PercentAvailableMemory"), /* name */
    SCX_MemoryStatisticalInformation_PercentAvailableMemory_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PercentAvailableMemory_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PercentAvailableMemory), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_UsedMemory_Units_qual_value = MI_T("MegaBytes");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_UsedMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_UsedMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_UsedMemory_quals[] =
{
    &SCX_MemoryStatisticalInformation_UsedMemory_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.UsedMemory */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_UsedMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0075790A, /* code */
    MI_T("UsedMemory"), /* name */
    SCX_MemoryStatisticalInformation_UsedMemory_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_UsedMemory_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, UsedMemory), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PercentUsedMemory_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PercentUsedMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PercentUsedMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PercentUsedMemory_quals[] =
{
    &SCX_MemoryStatisticalInformation_PercentUsedMemory_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PercentUsedMemory */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PercentUsedMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707911, /* code */
    MI_T("PercentUsedMemory"), /* name */
    SCX_MemoryStatisticalInformation_PercentUsedMemory_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PercentUsedMemory_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PercentUsedMemory), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PercentUsedByCache_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PercentUsedByCache_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PercentUsedByCache_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PercentUsedByCache_quals[] =
{
    &SCX_MemoryStatisticalInformation_PercentUsedByCache_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PercentUsedByCache */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PercentUsedByCache_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706512, /* code */
    MI_T("PercentUsedByCache"), /* name */
    SCX_MemoryStatisticalInformation_PercentUsedByCache_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PercentUsedByCache_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PercentUsedByCache), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PagesPerSec_Units_qual_value = MI_T("Pages per Second");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PagesPerSec_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PagesPerSec_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PagesPerSec_quals[] =
{
    &SCX_MemoryStatisticalInformation_PagesPerSec_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PagesPerSec */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PagesPerSec_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070630B, /* code */
    MI_T("PagesPerSec"), /* name */
    SCX_MemoryStatisticalInformation_PagesPerSec_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PagesPerSec_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PagesPerSec), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PagesReadPerSec_Units_qual_value = MI_T("Pages per Second");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PagesReadPerSec_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PagesReadPerSec_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PagesReadPerSec_quals[] =
{
    &SCX_MemoryStatisticalInformation_PagesReadPerSec_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PagesReadPerSec */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PagesReadPerSec_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070630F, /* code */
    MI_T("PagesReadPerSec"), /* name */
    SCX_MemoryStatisticalInformation_PagesReadPerSec_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PagesReadPerSec_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PagesReadPerSec), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PagesWrittenPerSec_Units_qual_value = MI_T("Pages per Second");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PagesWrittenPerSec_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PagesWrittenPerSec_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PagesWrittenPerSec_quals[] =
{
    &SCX_MemoryStatisticalInformation_PagesWrittenPerSec_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PagesWrittenPerSec */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PagesWrittenPerSec_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706312, /* code */
    MI_T("PagesWrittenPerSec"), /* name */
    SCX_MemoryStatisticalInformation_PagesWrittenPerSec_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PagesWrittenPerSec_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PagesWrittenPerSec), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_AvailableSwap_Units_qual_value = MI_T("MegaBytes");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_AvailableSwap_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_AvailableSwap_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_AvailableSwap_quals[] =
{
    &SCX_MemoryStatisticalInformation_AvailableSwap_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.AvailableSwap */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_AvailableSwap_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0061700D, /* code */
    MI_T("AvailableSwap"), /* name */
    SCX_MemoryStatisticalInformation_AvailableSwap_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_AvailableSwap_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, AvailableSwap), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PercentAvailableSwap_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PercentAvailableSwap_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PercentAvailableSwap_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PercentAvailableSwap_quals[] =
{
    &SCX_MemoryStatisticalInformation_PercentAvailableSwap_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PercentAvailableSwap */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PercentAvailableSwap_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707014, /* code */
    MI_T("PercentAvailableSwap"), /* name */
    SCX_MemoryStatisticalInformation_PercentAvailableSwap_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PercentAvailableSwap_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PercentAvailableSwap), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_UsedSwap_Units_qual_value = MI_T("MegaBytes");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_UsedSwap_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_UsedSwap_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_UsedSwap_quals[] =
{
    &SCX_MemoryStatisticalInformation_UsedSwap_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.UsedSwap */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_UsedSwap_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00757008, /* code */
    MI_T("UsedSwap"), /* name */
    SCX_MemoryStatisticalInformation_UsedSwap_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_UsedSwap_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, UsedSwap), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_PercentUsedSwap_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_PercentUsedSwap_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_MemoryStatisticalInformation_PercentUsedSwap_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_PercentUsedSwap_quals[] =
{
    &SCX_MemoryStatisticalInformation_PercentUsedSwap_Units_qual,
};

/* property SCX_MemoryStatisticalInformation.PercentUsedSwap */
static MI_CONST MI_PropertyDecl SCX_MemoryStatisticalInformation_PercentUsedSwap_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070700F, /* code */
    MI_T("PercentUsedSwap"), /* name */
    SCX_MemoryStatisticalInformation_PercentUsedSwap_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_PercentUsedSwap_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_MemoryStatisticalInformation, PercentUsedSwap), /* offset */
    MI_T("SCX_MemoryStatisticalInformation"), /* origin */
    MI_T("SCX_MemoryStatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_MemoryStatisticalInformation_Caption_prop,
    &SCX_MemoryStatisticalInformation_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &SCX_MemoryStatisticalInformation_Name_prop,
    &SCX_StatisticalInformation_IsAggregate_prop,
    &SCX_MemoryStatisticalInformation_AvailableMemory_prop,
    &SCX_MemoryStatisticalInformation_PercentAvailableMemory_prop,
    &SCX_MemoryStatisticalInformation_UsedMemory_prop,
    &SCX_MemoryStatisticalInformation_PercentUsedMemory_prop,
    &SCX_MemoryStatisticalInformation_PercentUsedByCache_prop,
    &SCX_MemoryStatisticalInformation_PagesPerSec_prop,
    &SCX_MemoryStatisticalInformation_PagesReadPerSec_prop,
    &SCX_MemoryStatisticalInformation_PagesWrittenPerSec_prop,
    &SCX_MemoryStatisticalInformation_AvailableSwap_prop,
    &SCX_MemoryStatisticalInformation_PercentAvailableSwap_prop,
    &SCX_MemoryStatisticalInformation_UsedSwap_prop,
    &SCX_MemoryStatisticalInformation_PercentUsedSwap_prop,
};

static MI_CONST MI_ProviderFT SCX_MemoryStatisticalInformation_funcs =
{
  (MI_ProviderFT_Load)SCX_MemoryStatisticalInformation_Load,
  (MI_ProviderFT_Unload)SCX_MemoryStatisticalInformation_Unload,
  (MI_ProviderFT_GetInstance)SCX_MemoryStatisticalInformation_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_MemoryStatisticalInformation_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_MemoryStatisticalInformation_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_MemoryStatisticalInformation_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_MemoryStatisticalInformation_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::Core::Statistics");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_MemoryStatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_MemoryStatisticalInformation_Version_qual_value = MI_T("1.3.0");

static MI_CONST MI_Qualifier SCX_MemoryStatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_MemoryStatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_MemoryStatisticalInformation_quals[] =
{
    &SCX_MemoryStatisticalInformation_UMLPackagePath_qual,
    &SCX_MemoryStatisticalInformation_Version_qual,
};

/* class SCX_MemoryStatisticalInformation */
MI_CONST MI_ClassDecl SCX_MemoryStatisticalInformation_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736E20, /* code */
    MI_T("SCX_MemoryStatisticalInformation"), /* name */
    SCX_MemoryStatisticalInformation_quals, /* qualifiers */
    MI_COUNT(SCX_MemoryStatisticalInformation_quals), /* numQualifiers */
    SCX_MemoryStatisticalInformation_props, /* properties */
    MI_COUNT(SCX_MemoryStatisticalInformation_props), /* numProperties */
    sizeof(SCX_MemoryStatisticalInformation), /* size */
    MI_T("SCX_StatisticalInformation"), /* superClass */
    &SCX_StatisticalInformation_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &SCX_MemoryStatisticalInformation_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_OperatingSystem
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_OperatingSystem_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_OperatingSystem_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_OperatingSystem_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_OperatingSystem_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_OperatingSystem_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_OperatingSystem_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_Name_quals[] =
{
    &CIM_OperatingSystem_Name_MaxLen_qual,
    &CIM_OperatingSystem_Name_Override_qual,
};

/* property CIM_OperatingSystem.Name */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_OperatingSystem_Name_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_OperatingSystem_CSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_OperatingSystem_CSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_OperatingSystem_CSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_OperatingSystem_CSCreationClassName_Propagated_qual_value = MI_T("CIM_ComputerSystem.CreationClassName");

static MI_CONST MI_Qualifier CIM_OperatingSystem_CSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_OperatingSystem_CSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_CSCreationClassName_quals[] =
{
    &CIM_OperatingSystem_CSCreationClassName_MaxLen_qual,
    &CIM_OperatingSystem_CSCreationClassName_Propagated_qual,
};

/* property CIM_OperatingSystem.CSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_CSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636513, /* code */
    MI_T("CSCreationClassName"), /* name */
    CIM_OperatingSystem_CSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_CSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, CSCreationClassName), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_OperatingSystem_CSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_OperatingSystem_CSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_OperatingSystem_CSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_OperatingSystem_CSName_Propagated_qual_value = MI_T("CIM_ComputerSystem.Name");

static MI_CONST MI_Qualifier CIM_OperatingSystem_CSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_OperatingSystem_CSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_CSName_quals[] =
{
    &CIM_OperatingSystem_CSName_MaxLen_qual,
    &CIM_OperatingSystem_CSName_Propagated_qual,
};

/* property CIM_OperatingSystem.CSName */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_CSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636506, /* code */
    MI_T("CSName"), /* name */
    CIM_OperatingSystem_CSName_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_CSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, CSName), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_OperatingSystem_CreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_OperatingSystem_CreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_OperatingSystem_CreationClassName_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_CreationClassName_quals[] =
{
    &CIM_OperatingSystem_CreationClassName_MaxLen_qual,
};

/* property CIM_OperatingSystem.CreationClassName */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_CreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636511, /* code */
    MI_T("CreationClassName"), /* name */
    CIM_OperatingSystem_CreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_CreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, CreationClassName), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.OSType */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_OSType_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6506, /* code */
    MI_T("OSType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, OSType), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_OperatingSystem_OtherTypeDescription_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier CIM_OperatingSystem_OtherTypeDescription_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_OperatingSystem_OtherTypeDescription_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_OtherTypeDescription_quals[] =
{
    &CIM_OperatingSystem_OtherTypeDescription_MaxLen_qual,
};

/* property CIM_OperatingSystem.OtherTypeDescription */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_OtherTypeDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6E14, /* code */
    MI_T("OtherTypeDescription"), /* name */
    CIM_OperatingSystem_OtherTypeDescription_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_OtherTypeDescription_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, OtherTypeDescription), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.Version */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_Version_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00766E07, /* code */
    MI_T("Version"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, Version), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.LastBootUpTime */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_LastBootUpTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C650E, /* code */
    MI_T("LastBootUpTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, LastBootUpTime), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.LocalDateTime */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_LocalDateTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006C650D, /* code */
    MI_T("LocalDateTime"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, LocalDateTime), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_CurrentTimeZone_Units_qual_value = MI_T("Minutes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_CurrentTimeZone_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_CurrentTimeZone_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_CurrentTimeZone_quals[] =
{
    &CIM_OperatingSystem_CurrentTimeZone_Units_qual,
};

/* property CIM_OperatingSystem.CurrentTimeZone */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_CurrentTimeZone_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063650F, /* code */
    MI_T("CurrentTimeZone"), /* name */
    CIM_OperatingSystem_CurrentTimeZone_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_CurrentTimeZone_quals), /* numQualifiers */
    MI_SINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, CurrentTimeZone), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.NumberOfLicensedUsers */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_NumberOfLicensedUsers_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E7315, /* code */
    MI_T("NumberOfLicensedUsers"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, NumberOfLicensedUsers), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.NumberOfUsers */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_NumberOfUsers_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E730D, /* code */
    MI_T("NumberOfUsers"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, NumberOfUsers), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.NumberOfProcesses */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_NumberOfProcesses_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E7311, /* code */
    MI_T("NumberOfProcesses"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, NumberOfProcesses), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.MaxNumberOfProcesses */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_MaxNumberOfProcesses_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D7314, /* code */
    MI_T("MaxNumberOfProcesses"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, MaxNumberOfProcesses), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_TotalSwapSpaceSize_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_TotalSwapSpaceSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_TotalSwapSpaceSize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_TotalSwapSpaceSize_quals[] =
{
    &CIM_OperatingSystem_TotalSwapSpaceSize_Units_qual,
};

/* property CIM_OperatingSystem.TotalSwapSpaceSize */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_TotalSwapSpaceSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746512, /* code */
    MI_T("TotalSwapSpaceSize"), /* name */
    CIM_OperatingSystem_TotalSwapSpaceSize_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_TotalSwapSpaceSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, TotalSwapSpaceSize), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_TotalVirtualMemorySize_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_TotalVirtualMemorySize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_TotalVirtualMemorySize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_TotalVirtualMemorySize_quals[] =
{
    &CIM_OperatingSystem_TotalVirtualMemorySize_Units_qual,
};

/* property CIM_OperatingSystem.TotalVirtualMemorySize */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_TotalVirtualMemorySize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746516, /* code */
    MI_T("TotalVirtualMemorySize"), /* name */
    CIM_OperatingSystem_TotalVirtualMemorySize_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_TotalVirtualMemorySize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, TotalVirtualMemorySize), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_FreeVirtualMemory_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_FreeVirtualMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_FreeVirtualMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_FreeVirtualMemory_quals[] =
{
    &CIM_OperatingSystem_FreeVirtualMemory_Units_qual,
};

/* property CIM_OperatingSystem.FreeVirtualMemory */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_FreeVirtualMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00667911, /* code */
    MI_T("FreeVirtualMemory"), /* name */
    CIM_OperatingSystem_FreeVirtualMemory_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_FreeVirtualMemory_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, FreeVirtualMemory), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_FreePhysicalMemory_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_FreePhysicalMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_FreePhysicalMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_FreePhysicalMemory_quals[] =
{
    &CIM_OperatingSystem_FreePhysicalMemory_Units_qual,
};

/* property CIM_OperatingSystem.FreePhysicalMemory */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_FreePhysicalMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00667912, /* code */
    MI_T("FreePhysicalMemory"), /* name */
    CIM_OperatingSystem_FreePhysicalMemory_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_FreePhysicalMemory_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, FreePhysicalMemory), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_TotalVisibleMemorySize_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_TotalVisibleMemorySize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_TotalVisibleMemorySize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_TotalVisibleMemorySize_quals[] =
{
    &CIM_OperatingSystem_TotalVisibleMemorySize_Units_qual,
};

/* property CIM_OperatingSystem.TotalVisibleMemorySize */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_TotalVisibleMemorySize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00746516, /* code */
    MI_T("TotalVisibleMemorySize"), /* name */
    CIM_OperatingSystem_TotalVisibleMemorySize_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_TotalVisibleMemorySize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, TotalVisibleMemorySize), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_SizeStoredInPagingFiles_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_SizeStoredInPagingFiles_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_SizeStoredInPagingFiles_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_SizeStoredInPagingFiles_quals[] =
{
    &CIM_OperatingSystem_SizeStoredInPagingFiles_Units_qual,
};

/* property CIM_OperatingSystem.SizeStoredInPagingFiles */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_SizeStoredInPagingFiles_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00737317, /* code */
    MI_T("SizeStoredInPagingFiles"), /* name */
    CIM_OperatingSystem_SizeStoredInPagingFiles_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_SizeStoredInPagingFiles_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, SizeStoredInPagingFiles), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_FreeSpaceInPagingFiles_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_FreeSpaceInPagingFiles_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_FreeSpaceInPagingFiles_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_FreeSpaceInPagingFiles_quals[] =
{
    &CIM_OperatingSystem_FreeSpaceInPagingFiles_Units_qual,
};

/* property CIM_OperatingSystem.FreeSpaceInPagingFiles */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_FreeSpaceInPagingFiles_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00667316, /* code */
    MI_T("FreeSpaceInPagingFiles"), /* name */
    CIM_OperatingSystem_FreeSpaceInPagingFiles_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_FreeSpaceInPagingFiles_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, FreeSpaceInPagingFiles), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_OperatingSystem_MaxProcessMemorySize_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_OperatingSystem_MaxProcessMemorySize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_OperatingSystem_MaxProcessMemorySize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_MaxProcessMemorySize_quals[] =
{
    &CIM_OperatingSystem_MaxProcessMemorySize_Units_qual,
};

/* property CIM_OperatingSystem.MaxProcessMemorySize */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_MaxProcessMemorySize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D6514, /* code */
    MI_T("MaxProcessMemorySize"), /* name */
    CIM_OperatingSystem_MaxProcessMemorySize_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_MaxProcessMemorySize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, MaxProcessMemorySize), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.Distributed */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_Distributed_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0064640B, /* code */
    MI_T("Distributed"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, Distributed), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

/* property CIM_OperatingSystem.MaxProcessesPerUser */
static MI_CONST MI_PropertyDecl CIM_OperatingSystem_MaxProcessesPerUser_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D7213, /* code */
    MI_T("MaxProcessesPerUser"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem, MaxProcessesPerUser), /* offset */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_OperatingSystem_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_OperatingSystem_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_OperatingSystem_CSCreationClassName_prop,
    &CIM_OperatingSystem_CSName_prop,
    &CIM_OperatingSystem_CreationClassName_prop,
    &CIM_OperatingSystem_OSType_prop,
    &CIM_OperatingSystem_OtherTypeDescription_prop,
    &CIM_OperatingSystem_Version_prop,
    &CIM_OperatingSystem_LastBootUpTime_prop,
    &CIM_OperatingSystem_LocalDateTime_prop,
    &CIM_OperatingSystem_CurrentTimeZone_prop,
    &CIM_OperatingSystem_NumberOfLicensedUsers_prop,
    &CIM_OperatingSystem_NumberOfUsers_prop,
    &CIM_OperatingSystem_NumberOfProcesses_prop,
    &CIM_OperatingSystem_MaxNumberOfProcesses_prop,
    &CIM_OperatingSystem_TotalSwapSpaceSize_prop,
    &CIM_OperatingSystem_TotalVirtualMemorySize_prop,
    &CIM_OperatingSystem_FreeVirtualMemory_prop,
    &CIM_OperatingSystem_FreePhysicalMemory_prop,
    &CIM_OperatingSystem_TotalVisibleMemorySize_prop,
    &CIM_OperatingSystem_SizeStoredInPagingFiles_prop,
    &CIM_OperatingSystem_FreeSpaceInPagingFiles_prop,
    &CIM_OperatingSystem_MaxProcessMemorySize_prop,
    &CIM_OperatingSystem_Distributed_prop,
    &CIM_OperatingSystem_MaxProcessesPerUser_prop,
};

/* parameter CIM_OperatingSystem.Reboot(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_OperatingSystem_Reboot_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem_Reboot, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_OperatingSystem_Reboot_params[] =
{
    &CIM_OperatingSystem_Reboot_MIReturn_param,
};

/* method CIM_OperatingSystem.Reboot() */
MI_CONST MI_MethodDecl CIM_OperatingSystem_Reboot_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727406, /* code */
    MI_T("Reboot"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_OperatingSystem_Reboot_params, /* parameters */
    MI_COUNT(CIM_OperatingSystem_Reboot_params), /* numParameters */
    sizeof(CIM_OperatingSystem_Reboot), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

/* parameter CIM_OperatingSystem.Shutdown(): MIReturn */
static MI_CONST MI_ParameterDecl CIM_OperatingSystem_Shutdown_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_OperatingSystem_Shutdown, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST CIM_OperatingSystem_Shutdown_params[] =
{
    &CIM_OperatingSystem_Shutdown_MIReturn_param,
};

/* method CIM_OperatingSystem.Shutdown() */
MI_CONST MI_MethodDecl CIM_OperatingSystem_Shutdown_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00736E08, /* code */
    MI_T("Shutdown"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    CIM_OperatingSystem_Shutdown_params, /* parameters */
    MI_COUNT(CIM_OperatingSystem_Shutdown_params), /* numParameters */
    sizeof(CIM_OperatingSystem_Shutdown), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    &schemaDecl, /* schema */
    NULL, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_OperatingSystem_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
    &CIM_OperatingSystem_Reboot_rtti,
    &CIM_OperatingSystem_Shutdown_rtti,
};

static MI_CONST MI_Char* CIM_OperatingSystem_UMLPackagePath_qual_value = MI_T("CIM::System::OperatingSystem");

static MI_CONST MI_Qualifier CIM_OperatingSystem_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_OperatingSystem_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_OperatingSystem_Version_qual_value = MI_T("2.23.0");

static MI_CONST MI_Qualifier CIM_OperatingSystem_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_OperatingSystem_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_OperatingSystem_quals[] =
{
    &CIM_OperatingSystem_UMLPackagePath_qual,
    &CIM_OperatingSystem_Version_qual,
};

/* class CIM_OperatingSystem */
MI_CONST MI_ClassDecl CIM_OperatingSystem_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00636D13, /* code */
    MI_T("CIM_OperatingSystem"), /* name */
    CIM_OperatingSystem_quals, /* qualifiers */
    MI_COUNT(CIM_OperatingSystem_quals), /* numQualifiers */
    CIM_OperatingSystem_props, /* properties */
    MI_COUNT(CIM_OperatingSystem_props), /* numProperties */
    sizeof(CIM_OperatingSystem), /* size */
    MI_T("CIM_EnabledLogicalElement"), /* superClass */
    &CIM_EnabledLogicalElement_rtti, /* superClassDecl */
    CIM_OperatingSystem_meths, /* methods */
    MI_COUNT(CIM_OperatingSystem_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_OperatingSystem
**
**==============================================================================
*/

/* property SCX_OperatingSystem.OperatingSystemCapability */
static MI_CONST MI_PropertyDecl SCX_OperatingSystem_OperatingSystemCapability_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F7919, /* code */
    MI_T("OperatingSystemCapability"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem, OperatingSystemCapability), /* offset */
    MI_T("SCX_OperatingSystem"), /* origin */
    MI_T("SCX_OperatingSystem"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_OperatingSystem_SystemUpTime_Units_qual_value = MI_T("Seconds");

static MI_CONST MI_Qualifier SCX_OperatingSystem_SystemUpTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_OperatingSystem_SystemUpTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_OperatingSystem_SystemUpTime_quals[] =
{
    &SCX_OperatingSystem_SystemUpTime_Units_qual,
};

/* property SCX_OperatingSystem.SystemUpTime */
static MI_CONST MI_PropertyDecl SCX_OperatingSystem_SystemUpTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0073650C, /* code */
    MI_T("SystemUpTime"), /* name */
    SCX_OperatingSystem_SystemUpTime_quals, /* qualifiers */
    MI_COUNT(SCX_OperatingSystem_SystemUpTime_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem, SystemUpTime), /* offset */
    MI_T("SCX_OperatingSystem"), /* origin */
    MI_T("SCX_OperatingSystem"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_OperatingSystem_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_OperatingSystem_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_OperatingSystem_CSCreationClassName_prop,
    &CIM_OperatingSystem_CSName_prop,
    &CIM_OperatingSystem_CreationClassName_prop,
    &CIM_OperatingSystem_OSType_prop,
    &CIM_OperatingSystem_OtherTypeDescription_prop,
    &CIM_OperatingSystem_Version_prop,
    &CIM_OperatingSystem_LastBootUpTime_prop,
    &CIM_OperatingSystem_LocalDateTime_prop,
    &CIM_OperatingSystem_CurrentTimeZone_prop,
    &CIM_OperatingSystem_NumberOfLicensedUsers_prop,
    &CIM_OperatingSystem_NumberOfUsers_prop,
    &CIM_OperatingSystem_NumberOfProcesses_prop,
    &CIM_OperatingSystem_MaxNumberOfProcesses_prop,
    &CIM_OperatingSystem_TotalSwapSpaceSize_prop,
    &CIM_OperatingSystem_TotalVirtualMemorySize_prop,
    &CIM_OperatingSystem_FreeVirtualMemory_prop,
    &CIM_OperatingSystem_FreePhysicalMemory_prop,
    &CIM_OperatingSystem_TotalVisibleMemorySize_prop,
    &CIM_OperatingSystem_SizeStoredInPagingFiles_prop,
    &CIM_OperatingSystem_FreeSpaceInPagingFiles_prop,
    &CIM_OperatingSystem_MaxProcessMemorySize_prop,
    &CIM_OperatingSystem_Distributed_prop,
    &CIM_OperatingSystem_MaxProcessesPerUser_prop,
    &SCX_OperatingSystem_OperatingSystemCapability_prop,
    &SCX_OperatingSystem_SystemUpTime_prop,
};

/* parameter SCX_OperatingSystem.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_RequestStateChange, RequestedState), /* offset */
};

/* parameter SCX_OperatingSystem.RequestStateChange(): Job */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_RequestStateChange_Job_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006A6203, /* code */
    MI_T("Job"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REFERENCE, /* type */
    MI_T("CIM_ConcreteJob"), /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_RequestStateChange, Job), /* offset */
};

/* parameter SCX_OperatingSystem.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter SCX_OperatingSystem.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_OperatingSystem_RequestStateChange_params[] =
{
    &SCX_OperatingSystem_RequestStateChange_MIReturn_param,
    &SCX_OperatingSystem_RequestStateChange_RequestedState_param,
    &SCX_OperatingSystem_RequestStateChange_Job_param,
    &SCX_OperatingSystem_RequestStateChange_TimeoutPeriod_param,
};

/* method SCX_OperatingSystem.RequestStateChange() */
MI_CONST MI_MethodDecl SCX_OperatingSystem_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_OperatingSystem_RequestStateChange_params, /* parameters */
    MI_COUNT(SCX_OperatingSystem_RequestStateChange_params), /* numParameters */
    sizeof(SCX_OperatingSystem_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_OperatingSystem_Invoke_RequestStateChange, /* method */
};

/* parameter SCX_OperatingSystem.Reboot(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_Reboot_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_Reboot, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_OperatingSystem_Reboot_params[] =
{
    &SCX_OperatingSystem_Reboot_MIReturn_param,
};

/* method SCX_OperatingSystem.Reboot() */
MI_CONST MI_MethodDecl SCX_OperatingSystem_Reboot_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00727406, /* code */
    MI_T("Reboot"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_OperatingSystem_Reboot_params, /* parameters */
    MI_COUNT(SCX_OperatingSystem_Reboot_params), /* numParameters */
    sizeof(SCX_OperatingSystem_Reboot), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_OperatingSystem_Invoke_Reboot, /* method */
};

/* parameter SCX_OperatingSystem.Shutdown(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_Shutdown_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_Shutdown, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_OperatingSystem_Shutdown_params[] =
{
    &SCX_OperatingSystem_Shutdown_MIReturn_param,
};

/* method SCX_OperatingSystem.Shutdown() */
MI_CONST MI_MethodDecl SCX_OperatingSystem_Shutdown_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00736E08, /* code */
    MI_T("Shutdown"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_OperatingSystem_Shutdown_params, /* parameters */
    MI_COUNT(SCX_OperatingSystem_Shutdown_params), /* numParameters */
    sizeof(SCX_OperatingSystem_Shutdown), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_OperatingSystem"), /* origin */
    MI_T("CIM_OperatingSystem"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_OperatingSystem_Invoke_Shutdown, /* method */
};

/* parameter SCX_OperatingSystem.ExecuteCommand(): Command */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteCommand_Command_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00636407, /* code */
    MI_T("Command"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteCommand, Command), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteCommand(): ReturnCode */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteCommand_ReturnCode_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x0072650A, /* code */
    MI_T("ReturnCode"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_SINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteCommand, ReturnCode), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteCommand(): StdOut */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteCommand_StdOut_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00737406, /* code */
    MI_T("StdOut"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteCommand, StdOut), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteCommand(): StdErr */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteCommand_StdErr_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00737206, /* code */
    MI_T("StdErr"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteCommand, StdErr), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteCommand(): timeout */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteCommand_timeout_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00747407, /* code */
    MI_T("timeout"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteCommand, timeout), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteCommand(): ElevationType */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteCommand_ElevationType_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0065650D, /* code */
    MI_T("ElevationType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteCommand, ElevationType), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteCommand(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteCommand_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteCommand, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_OperatingSystem_ExecuteCommand_params[] =
{
    &SCX_OperatingSystem_ExecuteCommand_MIReturn_param,
    &SCX_OperatingSystem_ExecuteCommand_Command_param,
    &SCX_OperatingSystem_ExecuteCommand_ReturnCode_param,
    &SCX_OperatingSystem_ExecuteCommand_StdOut_param,
    &SCX_OperatingSystem_ExecuteCommand_StdErr_param,
    &SCX_OperatingSystem_ExecuteCommand_timeout_param,
    &SCX_OperatingSystem_ExecuteCommand_ElevationType_param,
};

/* method SCX_OperatingSystem.ExecuteCommand() */
MI_CONST MI_MethodDecl SCX_OperatingSystem_ExecuteCommand_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x0065640E, /* code */
    MI_T("ExecuteCommand"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_OperatingSystem_ExecuteCommand_params, /* parameters */
    MI_COUNT(SCX_OperatingSystem_ExecuteCommand_params), /* numParameters */
    sizeof(SCX_OperatingSystem_ExecuteCommand), /* size */
    MI_BOOLEAN, /* returnType */
    MI_T("SCX_OperatingSystem"), /* origin */
    MI_T("SCX_OperatingSystem"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_OperatingSystem_Invoke_ExecuteCommand, /* method */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): Command */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_Command_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00636407, /* code */
    MI_T("Command"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, Command), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): ReturnCode */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_ReturnCode_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x0072650A, /* code */
    MI_T("ReturnCode"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_SINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, ReturnCode), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): StdOut */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_StdOut_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00737406, /* code */
    MI_T("StdOut"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, StdOut), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): StdErr */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_StdErr_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00737206, /* code */
    MI_T("StdErr"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, StdErr), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): timeout */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_timeout_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00747407, /* code */
    MI_T("timeout"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, timeout), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): ElevationType */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_ElevationType_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0065650D, /* code */
    MI_T("ElevationType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, ElevationType), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): b64encoded */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_b64encoded_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0062640A, /* code */
    MI_T("b64encoded"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, b64encoded), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteShellCommand(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteShellCommand_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteShellCommand, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_OperatingSystem_ExecuteShellCommand_params[] =
{
    &SCX_OperatingSystem_ExecuteShellCommand_MIReturn_param,
    &SCX_OperatingSystem_ExecuteShellCommand_Command_param,
    &SCX_OperatingSystem_ExecuteShellCommand_ReturnCode_param,
    &SCX_OperatingSystem_ExecuteShellCommand_StdOut_param,
    &SCX_OperatingSystem_ExecuteShellCommand_StdErr_param,
    &SCX_OperatingSystem_ExecuteShellCommand_timeout_param,
    &SCX_OperatingSystem_ExecuteShellCommand_ElevationType_param,
    &SCX_OperatingSystem_ExecuteShellCommand_b64encoded_param,
};

/* method SCX_OperatingSystem.ExecuteShellCommand() */
MI_CONST MI_MethodDecl SCX_OperatingSystem_ExecuteShellCommand_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x00656413, /* code */
    MI_T("ExecuteShellCommand"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_OperatingSystem_ExecuteShellCommand_params, /* parameters */
    MI_COUNT(SCX_OperatingSystem_ExecuteShellCommand_params), /* numParameters */
    sizeof(SCX_OperatingSystem_ExecuteShellCommand), /* size */
    MI_BOOLEAN, /* returnType */
    MI_T("SCX_OperatingSystem"), /* origin */
    MI_T("SCX_OperatingSystem"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_OperatingSystem_Invoke_ExecuteShellCommand, /* method */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): Script */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_Script_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00737406, /* code */
    MI_T("Script"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, Script), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): Arguments */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_Arguments_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00617309, /* code */
    MI_T("Arguments"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, Arguments), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): ReturnCode */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_ReturnCode_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x0072650A, /* code */
    MI_T("ReturnCode"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_SINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, ReturnCode), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): StdOut */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_StdOut_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00737406, /* code */
    MI_T("StdOut"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, StdOut), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): StdErr */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_StdErr_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x00737206, /* code */
    MI_T("StdErr"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, StdErr), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): timeout */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_timeout_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00747407, /* code */
    MI_T("timeout"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, timeout), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): ElevationType */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_ElevationType_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0065650D, /* code */
    MI_T("ElevationType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, ElevationType), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): b64encoded */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_b64encoded_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0062640A, /* code */
    MI_T("b64encoded"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, b64encoded), /* offset */
};

/* parameter SCX_OperatingSystem.ExecuteScript(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_OperatingSystem_ExecuteScript_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_OperatingSystem_ExecuteScript, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_OperatingSystem_ExecuteScript_params[] =
{
    &SCX_OperatingSystem_ExecuteScript_MIReturn_param,
    &SCX_OperatingSystem_ExecuteScript_Script_param,
    &SCX_OperatingSystem_ExecuteScript_Arguments_param,
    &SCX_OperatingSystem_ExecuteScript_ReturnCode_param,
    &SCX_OperatingSystem_ExecuteScript_StdOut_param,
    &SCX_OperatingSystem_ExecuteScript_StdErr_param,
    &SCX_OperatingSystem_ExecuteScript_timeout_param,
    &SCX_OperatingSystem_ExecuteScript_ElevationType_param,
    &SCX_OperatingSystem_ExecuteScript_b64encoded_param,
};

/* method SCX_OperatingSystem.ExecuteScript() */
MI_CONST MI_MethodDecl SCX_OperatingSystem_ExecuteScript_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x0065740D, /* code */
    MI_T("ExecuteScript"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_OperatingSystem_ExecuteScript_params, /* parameters */
    MI_COUNT(SCX_OperatingSystem_ExecuteScript_params), /* numParameters */
    sizeof(SCX_OperatingSystem_ExecuteScript), /* size */
    MI_BOOLEAN, /* returnType */
    MI_T("SCX_OperatingSystem"), /* origin */
    MI_T("SCX_OperatingSystem"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_OperatingSystem_Invoke_ExecuteScript, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_OperatingSystem_meths[] =
{
    &SCX_OperatingSystem_RequestStateChange_rtti,
    &SCX_OperatingSystem_Reboot_rtti,
    &SCX_OperatingSystem_Shutdown_rtti,
    &SCX_OperatingSystem_ExecuteCommand_rtti,
    &SCX_OperatingSystem_ExecuteShellCommand_rtti,
    &SCX_OperatingSystem_ExecuteScript_rtti,
};

static MI_CONST MI_ProviderFT SCX_OperatingSystem_funcs =
{
  (MI_ProviderFT_Load)SCX_OperatingSystem_Load,
  (MI_ProviderFT_Unload)SCX_OperatingSystem_Unload,
  (MI_ProviderFT_GetInstance)SCX_OperatingSystem_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_OperatingSystem_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_OperatingSystem_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_OperatingSystem_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_OperatingSystem_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_OperatingSystem_UMLPackagePath_qual_value = MI_T("CIM::System::OperatingSystem");

static MI_CONST MI_Qualifier SCX_OperatingSystem_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_OperatingSystem_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_OperatingSystem_Version_qual_value = MI_T("1.3.7");

static MI_CONST MI_Qualifier SCX_OperatingSystem_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_OperatingSystem_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_OperatingSystem_quals[] =
{
    &SCX_OperatingSystem_UMLPackagePath_qual,
    &SCX_OperatingSystem_Version_qual,
};

/* class SCX_OperatingSystem */
MI_CONST MI_ClassDecl SCX_OperatingSystem_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736D13, /* code */
    MI_T("SCX_OperatingSystem"), /* name */
    SCX_OperatingSystem_quals, /* qualifiers */
    MI_COUNT(SCX_OperatingSystem_quals), /* numQualifiers */
    SCX_OperatingSystem_props, /* properties */
    MI_COUNT(SCX_OperatingSystem_props), /* numProperties */
    sizeof(SCX_OperatingSystem), /* size */
    MI_T("CIM_OperatingSystem"), /* superClass */
    &CIM_OperatingSystem_rtti, /* superClassDecl */
    SCX_OperatingSystem_meths, /* methods */
    MI_COUNT(SCX_OperatingSystem_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_OperatingSystem_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_ProcessorStatisticalInformation
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_ProcessorStatisticalInformation_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_ProcessorStatisticalInformation_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_Caption_quals[] =
{
    &SCX_ProcessorStatisticalInformation_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_Caption_value = MI_T("Processor information");

/* property SCX_ProcessorStatisticalInformation.Caption */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_ProcessorStatisticalInformation_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    &SCX_ProcessorStatisticalInformation_Caption_value,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_Description_value = MI_T("CPU usage statistics");

/* property SCX_ProcessorStatisticalInformation.Description */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    &SCX_ProcessorStatisticalInformation_Description_value,
};

static MI_CONST MI_Uint32 SCX_ProcessorStatisticalInformation_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_ProcessorStatisticalInformation_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &SCX_ProcessorStatisticalInformation_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_Name_quals[] =
{
    &SCX_ProcessorStatisticalInformation_Name_MaxLen_qual,
    &SCX_ProcessorStatisticalInformation_Name_Override_qual,
};

/* property SCX_ProcessorStatisticalInformation.Name */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    SCX_ProcessorStatisticalInformation_Name_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, Name), /* offset */
    MI_T("CIM_StatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentIdleTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentIdleTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentIdleTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentIdleTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentIdleTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentIdleTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentIdleTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentIdleTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentIdleTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentIdleTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentIdleTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentUserTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentUserTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentUserTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentUserTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentUserTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentUserTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentUserTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentUserTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentUserTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentUserTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentUserTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentNiceTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentNiceTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentNiceTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentNiceTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentNiceTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentNiceTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentNiceTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentNiceTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentNiceTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentNiceTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentNiceTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentPrivilegedTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706515, /* code */
    MI_T("PercentPrivilegedTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentPrivilegedTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentInterruptTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentInterruptTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentInterruptTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentInterruptTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentInterruptTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentInterruptTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentInterruptTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706514, /* code */
    MI_T("PercentInterruptTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentInterruptTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentInterruptTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentInterruptTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentDPCTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentDPCTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentDPCTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentDPCTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentDPCTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentDPCTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentDPCTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650E, /* code */
    MI_T("PercentDPCTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentDPCTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentDPCTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentDPCTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentProcessorTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentProcessorTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentProcessorTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentProcessorTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentProcessorTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentProcessorTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentProcessorTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706514, /* code */
    MI_T("PercentProcessorTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentProcessorTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentProcessorTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentProcessorTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_PercentIOWaitTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_PercentIOWaitTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_ProcessorStatisticalInformation_PercentIOWaitTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_PercentIOWaitTime_quals[] =
{
    &SCX_ProcessorStatisticalInformation_PercentIOWaitTime_Units_qual,
};

/* property SCX_ProcessorStatisticalInformation.PercentIOWaitTime */
static MI_CONST MI_PropertyDecl SCX_ProcessorStatisticalInformation_PercentIOWaitTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706511, /* code */
    MI_T("PercentIOWaitTime"), /* name */
    SCX_ProcessorStatisticalInformation_PercentIOWaitTime_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_PercentIOWaitTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_ProcessorStatisticalInformation, PercentIOWaitTime), /* offset */
    MI_T("SCX_ProcessorStatisticalInformation"), /* origin */
    MI_T("SCX_ProcessorStatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_ProcessorStatisticalInformation_Caption_prop,
    &SCX_ProcessorStatisticalInformation_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &SCX_ProcessorStatisticalInformation_Name_prop,
    &SCX_StatisticalInformation_IsAggregate_prop,
    &SCX_ProcessorStatisticalInformation_PercentIdleTime_prop,
    &SCX_ProcessorStatisticalInformation_PercentUserTime_prop,
    &SCX_ProcessorStatisticalInformation_PercentNiceTime_prop,
    &SCX_ProcessorStatisticalInformation_PercentPrivilegedTime_prop,
    &SCX_ProcessorStatisticalInformation_PercentInterruptTime_prop,
    &SCX_ProcessorStatisticalInformation_PercentDPCTime_prop,
    &SCX_ProcessorStatisticalInformation_PercentProcessorTime_prop,
    &SCX_ProcessorStatisticalInformation_PercentIOWaitTime_prop,
};

static MI_CONST MI_ProviderFT SCX_ProcessorStatisticalInformation_funcs =
{
  (MI_ProviderFT_Load)SCX_ProcessorStatisticalInformation_Load,
  (MI_ProviderFT_Unload)SCX_ProcessorStatisticalInformation_Unload,
  (MI_ProviderFT_GetInstance)SCX_ProcessorStatisticalInformation_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_ProcessorStatisticalInformation_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_ProcessorStatisticalInformation_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_ProcessorStatisticalInformation_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_ProcessorStatisticalInformation_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::Core::Statistics");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_ProcessorStatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_ProcessorStatisticalInformation_Version_qual_value = MI_T("1.3.0");

static MI_CONST MI_Qualifier SCX_ProcessorStatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_ProcessorStatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_ProcessorStatisticalInformation_quals[] =
{
    &SCX_ProcessorStatisticalInformation_UMLPackagePath_qual,
    &SCX_ProcessorStatisticalInformation_Version_qual,
};

/* class SCX_ProcessorStatisticalInformation */
MI_CONST MI_ClassDecl SCX_ProcessorStatisticalInformation_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736E23, /* code */
    MI_T("SCX_ProcessorStatisticalInformation"), /* name */
    SCX_ProcessorStatisticalInformation_quals, /* qualifiers */
    MI_COUNT(SCX_ProcessorStatisticalInformation_quals), /* numQualifiers */
    SCX_ProcessorStatisticalInformation_props, /* properties */
    MI_COUNT(SCX_ProcessorStatisticalInformation_props), /* numProperties */
    sizeof(SCX_ProcessorStatisticalInformation), /* size */
    MI_T("SCX_StatisticalInformation"), /* superClass */
    &SCX_StatisticalInformation_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &SCX_ProcessorStatisticalInformation_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_Process
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_Process_Name_MaxLen_qual_value = 1024U;

static MI_CONST MI_Qualifier CIM_Process_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_Process_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_Process_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_Process_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_Process_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_Name_quals[] =
{
    &CIM_Process_Name_MaxLen_qual,
    &CIM_Process_Name_Override_qual,
};

/* property CIM_Process.Name */
static MI_CONST MI_PropertyDecl CIM_Process_Name_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_Process_Name_quals, /* qualifiers */
    MI_COUNT(CIM_Process_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, Name), /* offset */
    MI_T("CIM_ManagedSystemElement"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_Process_CSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_Process_CSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_Process_CSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_Process_CSCreationClassName_Propagated_qual_value = MI_T("CIM_OperatingSystem.CSCreationClassName");

static MI_CONST MI_Qualifier CIM_Process_CSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_Process_CSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_CSCreationClassName_quals[] =
{
    &CIM_Process_CSCreationClassName_MaxLen_qual,
    &CIM_Process_CSCreationClassName_Propagated_qual,
};

/* property CIM_Process.CSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_Process_CSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636513, /* code */
    MI_T("CSCreationClassName"), /* name */
    CIM_Process_CSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_Process_CSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, CSCreationClassName), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_Process_CSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_Process_CSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_Process_CSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_Process_CSName_Propagated_qual_value = MI_T("CIM_OperatingSystem.CSName");

static MI_CONST MI_Qualifier CIM_Process_CSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_Process_CSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_CSName_quals[] =
{
    &CIM_Process_CSName_MaxLen_qual,
    &CIM_Process_CSName_Propagated_qual,
};

/* property CIM_Process.CSName */
static MI_CONST MI_PropertyDecl CIM_Process_CSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636506, /* code */
    MI_T("CSName"), /* name */
    CIM_Process_CSName_quals, /* qualifiers */
    MI_COUNT(CIM_Process_CSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, CSName), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_Process_OSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_Process_OSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_Process_OSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_Process_OSCreationClassName_Propagated_qual_value = MI_T("CIM_OperatingSystem.CreationClassName");

static MI_CONST MI_Qualifier CIM_Process_OSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_Process_OSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_OSCreationClassName_quals[] =
{
    &CIM_Process_OSCreationClassName_MaxLen_qual,
    &CIM_Process_OSCreationClassName_Propagated_qual,
};

/* property CIM_Process.OSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_Process_OSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006F6513, /* code */
    MI_T("OSCreationClassName"), /* name */
    CIM_Process_OSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_Process_OSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, OSCreationClassName), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_Process_OSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_Process_OSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_Process_OSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_Process_OSName_Propagated_qual_value = MI_T("CIM_OperatingSystem.Name");

static MI_CONST MI_Qualifier CIM_Process_OSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_Process_OSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_OSName_quals[] =
{
    &CIM_Process_OSName_MaxLen_qual,
    &CIM_Process_OSName_Propagated_qual,
};

/* property CIM_Process.OSName */
static MI_CONST MI_PropertyDecl CIM_Process_OSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006F6506, /* code */
    MI_T("OSName"), /* name */
    CIM_Process_OSName_quals, /* qualifiers */
    MI_COUNT(CIM_Process_OSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, OSName), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_Process_CreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_Process_CreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_Process_CreationClassName_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_CreationClassName_quals[] =
{
    &CIM_Process_CreationClassName_MaxLen_qual,
};

/* property CIM_Process.CreationClassName */
static MI_CONST MI_PropertyDecl CIM_Process_CreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636511, /* code */
    MI_T("CreationClassName"), /* name */
    CIM_Process_CreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_Process_CreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, CreationClassName), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_Process_Handle_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_Process_Handle_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_Process_Handle_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_Handle_quals[] =
{
    &CIM_Process_Handle_MaxLen_qual,
};

/* property CIM_Process.Handle */
static MI_CONST MI_PropertyDecl CIM_Process_Handle_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00686506, /* code */
    MI_T("Handle"), /* name */
    CIM_Process_Handle_quals, /* qualifiers */
    MI_COUNT(CIM_Process_Handle_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, Handle), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

/* property CIM_Process.Priority */
static MI_CONST MI_PropertyDecl CIM_Process_Priority_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707908, /* code */
    MI_T("Priority"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, Priority), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

/* property CIM_Process.ExecutionState */
static MI_CONST MI_PropertyDecl CIM_Process_ExecutionState_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0065650E, /* code */
    MI_T("ExecutionState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, ExecutionState), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

/* property CIM_Process.OtherExecutionDescription */
static MI_CONST MI_PropertyDecl CIM_Process_OtherExecutionDescription_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006F6E19, /* code */
    MI_T("OtherExecutionDescription"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, OtherExecutionDescription), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

/* property CIM_Process.CreationDate */
static MI_CONST MI_PropertyDecl CIM_Process_CreationDate_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0063650C, /* code */
    MI_T("CreationDate"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, CreationDate), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

/* property CIM_Process.TerminationDate */
static MI_CONST MI_PropertyDecl CIM_Process_TerminationDate_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0074650F, /* code */
    MI_T("TerminationDate"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, TerminationDate), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_Process_KernelModeTime_Units_qual_value = MI_T("MilliSeconds");

static MI_CONST MI_Qualifier CIM_Process_KernelModeTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_Process_KernelModeTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_KernelModeTime_quals[] =
{
    &CIM_Process_KernelModeTime_Units_qual,
};

/* property CIM_Process.KernelModeTime */
static MI_CONST MI_PropertyDecl CIM_Process_KernelModeTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006B650E, /* code */
    MI_T("KernelModeTime"), /* name */
    CIM_Process_KernelModeTime_quals, /* qualifiers */
    MI_COUNT(CIM_Process_KernelModeTime_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, KernelModeTime), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_Process_UserModeTime_Units_qual_value = MI_T("MilliSeconds");

static MI_CONST MI_Qualifier CIM_Process_UserModeTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_Process_UserModeTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_UserModeTime_quals[] =
{
    &CIM_Process_UserModeTime_Units_qual,
};

/* property CIM_Process.UserModeTime */
static MI_CONST MI_PropertyDecl CIM_Process_UserModeTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0075650C, /* code */
    MI_T("UserModeTime"), /* name */
    CIM_Process_UserModeTime_quals, /* qualifiers */
    MI_COUNT(CIM_Process_UserModeTime_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, UserModeTime), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_Process_WorkingSetSize_Units_qual_value = MI_T("Bytes");

static MI_CONST MI_Qualifier CIM_Process_WorkingSetSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_Process_WorkingSetSize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_WorkingSetSize_quals[] =
{
    &CIM_Process_WorkingSetSize_Units_qual,
};

/* property CIM_Process.WorkingSetSize */
static MI_CONST MI_PropertyDecl CIM_Process_WorkingSetSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0077650E, /* code */
    MI_T("WorkingSetSize"), /* name */
    CIM_Process_WorkingSetSize_quals, /* qualifiers */
    MI_COUNT(CIM_Process_WorkingSetSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_Process, WorkingSetSize), /* offset */
    MI_T("CIM_Process"), /* origin */
    MI_T("CIM_Process"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_Process_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_Process_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_Process_CSCreationClassName_prop,
    &CIM_Process_CSName_prop,
    &CIM_Process_OSCreationClassName_prop,
    &CIM_Process_OSName_prop,
    &CIM_Process_CreationClassName_prop,
    &CIM_Process_Handle_prop,
    &CIM_Process_Priority_prop,
    &CIM_Process_ExecutionState_prop,
    &CIM_Process_OtherExecutionDescription_prop,
    &CIM_Process_CreationDate_prop,
    &CIM_Process_TerminationDate_prop,
    &CIM_Process_KernelModeTime_prop,
    &CIM_Process_UserModeTime_prop,
    &CIM_Process_WorkingSetSize_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_Process_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_Process_UMLPackagePath_qual_value = MI_T("CIM::System::Processing");

static MI_CONST MI_Qualifier CIM_Process_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_Process_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_Process_Version_qual_value = MI_T("2.10.0");

static MI_CONST MI_Qualifier CIM_Process_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_Process_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_Process_quals[] =
{
    &CIM_Process_UMLPackagePath_qual,
    &CIM_Process_Version_qual,
};

/* class CIM_Process */
MI_CONST MI_ClassDecl CIM_Process_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0063730B, /* code */
    MI_T("CIM_Process"), /* name */
    CIM_Process_quals, /* qualifiers */
    MI_COUNT(CIM_Process_quals), /* numQualifiers */
    CIM_Process_props, /* properties */
    MI_COUNT(CIM_Process_props), /* numProperties */
    sizeof(CIM_Process), /* size */
    MI_T("CIM_EnabledLogicalElement"), /* superClass */
    &CIM_EnabledLogicalElement_rtti, /* superClassDecl */
    CIM_Process_meths, /* methods */
    MI_COUNT(CIM_Process_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_UnixProcess
**
**==============================================================================
*/

/* property CIM_UnixProcess.ParentProcessID */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_ParentProcessID_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_REQUIRED, /* flags */
    0x0070640F, /* code */
    MI_T("ParentProcessID"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, ParentProcessID), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.RealUserID */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_RealUserID_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_REQUIRED, /* flags */
    0x0072640A, /* code */
    MI_T("RealUserID"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, RealUserID), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.ProcessGroupID */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_ProcessGroupID_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_REQUIRED, /* flags */
    0x0070640E, /* code */
    MI_T("ProcessGroupID"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, ProcessGroupID), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.ProcessSessionID */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_ProcessSessionID_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706410, /* code */
    MI_T("ProcessSessionID"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, ProcessSessionID), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.ProcessTTY */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_ProcessTTY_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070790A, /* code */
    MI_T("ProcessTTY"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, ProcessTTY), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.ModulePath */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_ModulePath_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D680A, /* code */
    MI_T("ModulePath"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, ModulePath), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.Parameters */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_Parameters_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070730A, /* code */
    MI_T("Parameters"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRINGA, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, Parameters), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.ProcessNiceValue */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_ProcessNiceValue_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706510, /* code */
    MI_T("ProcessNiceValue"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, ProcessNiceValue), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

/* property CIM_UnixProcess.ProcessWaitingForEvent */
static MI_CONST MI_PropertyDecl CIM_UnixProcess_ProcessWaitingForEvent_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707416, /* code */
    MI_T("ProcessWaitingForEvent"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcess, ProcessWaitingForEvent), /* offset */
    MI_T("CIM_UnixProcess"), /* origin */
    MI_T("CIM_UnixProcess"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_UnixProcess_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_Process_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_Process_CSCreationClassName_prop,
    &CIM_Process_CSName_prop,
    &CIM_Process_OSCreationClassName_prop,
    &CIM_Process_OSName_prop,
    &CIM_Process_CreationClassName_prop,
    &CIM_Process_Handle_prop,
    &CIM_Process_Priority_prop,
    &CIM_Process_ExecutionState_prop,
    &CIM_Process_OtherExecutionDescription_prop,
    &CIM_Process_CreationDate_prop,
    &CIM_Process_TerminationDate_prop,
    &CIM_Process_KernelModeTime_prop,
    &CIM_Process_UserModeTime_prop,
    &CIM_Process_WorkingSetSize_prop,
    &CIM_UnixProcess_ParentProcessID_prop,
    &CIM_UnixProcess_RealUserID_prop,
    &CIM_UnixProcess_ProcessGroupID_prop,
    &CIM_UnixProcess_ProcessSessionID_prop,
    &CIM_UnixProcess_ProcessTTY_prop,
    &CIM_UnixProcess_ModulePath_prop,
    &CIM_UnixProcess_Parameters_prop,
    &CIM_UnixProcess_ProcessNiceValue_prop,
    &CIM_UnixProcess_ProcessWaitingForEvent_prop,
};

static MI_MethodDecl MI_CONST* MI_CONST CIM_UnixProcess_meths[] =
{
    &CIM_EnabledLogicalElement_RequestStateChange_rtti,
};

static MI_CONST MI_Char* CIM_UnixProcess_UMLPackagePath_qual_value = MI_T("CIM::System::Unix");

static MI_CONST MI_Qualifier CIM_UnixProcess_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_UnixProcess_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcess_Version_qual_value = MI_T("2.6.0");

static MI_CONST MI_Qualifier CIM_UnixProcess_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_UnixProcess_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcess_quals[] =
{
    &CIM_UnixProcess_UMLPackagePath_qual,
    &CIM_UnixProcess_Version_qual,
};

/* class CIM_UnixProcess */
MI_CONST MI_ClassDecl CIM_UnixProcess_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0063730F, /* code */
    MI_T("CIM_UnixProcess"), /* name */
    CIM_UnixProcess_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcess_quals), /* numQualifiers */
    CIM_UnixProcess_props, /* properties */
    MI_COUNT(CIM_UnixProcess_props), /* numProperties */
    sizeof(CIM_UnixProcess), /* size */
    MI_T("CIM_Process"), /* superClass */
    &CIM_Process_rtti, /* superClassDecl */
    CIM_UnixProcess_meths, /* methods */
    MI_COUNT(CIM_UnixProcess_meths), /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_UnixProcess
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_UnixProcess_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_UnixProcess_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_UnixProcess_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcess_Caption_quals[] =
{
    &SCX_UnixProcess_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_UnixProcess_Caption_value = MI_T("Unix process information");

/* property SCX_UnixProcess.Caption */
static MI_CONST MI_PropertyDecl SCX_UnixProcess_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_UnixProcess_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcess_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_UnixProcess"), /* propagator */
    &SCX_UnixProcess_Caption_value,
};

static MI_CONST MI_Char* SCX_UnixProcess_Description_value = MI_T("A snapshot of a current process");

/* property SCX_UnixProcess.Description */
static MI_CONST MI_PropertyDecl SCX_UnixProcess_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_UnixProcess"), /* propagator */
    &SCX_UnixProcess_Description_value,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_UnixProcess_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_UnixProcess_Caption_prop,
    &SCX_UnixProcess_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_ManagedSystemElement_InstallDate_prop,
    &CIM_Process_Name_prop,
    &CIM_ManagedSystemElement_OperationalStatus_prop,
    &CIM_ManagedSystemElement_StatusDescriptions_prop,
    &CIM_ManagedSystemElement_Status_prop,
    &CIM_ManagedSystemElement_HealthState_prop,
    &CIM_ManagedSystemElement_CommunicationStatus_prop,
    &CIM_ManagedSystemElement_DetailedStatus_prop,
    &CIM_ManagedSystemElement_OperatingStatus_prop,
    &CIM_ManagedSystemElement_PrimaryStatus_prop,
    &CIM_EnabledLogicalElement_EnabledState_prop,
    &CIM_EnabledLogicalElement_OtherEnabledState_prop,
    &CIM_EnabledLogicalElement_RequestedState_prop,
    &CIM_EnabledLogicalElement_EnabledDefault_prop,
    &CIM_EnabledLogicalElement_TimeOfLastStateChange_prop,
    &CIM_EnabledLogicalElement_AvailableRequestedStates_prop,
    &CIM_EnabledLogicalElement_TransitioningToState_prop,
    &CIM_Process_CSCreationClassName_prop,
    &CIM_Process_CSName_prop,
    &CIM_Process_OSCreationClassName_prop,
    &CIM_Process_OSName_prop,
    &CIM_Process_CreationClassName_prop,
    &CIM_Process_Handle_prop,
    &CIM_Process_Priority_prop,
    &CIM_Process_ExecutionState_prop,
    &CIM_Process_OtherExecutionDescription_prop,
    &CIM_Process_CreationDate_prop,
    &CIM_Process_TerminationDate_prop,
    &CIM_Process_KernelModeTime_prop,
    &CIM_Process_UserModeTime_prop,
    &CIM_Process_WorkingSetSize_prop,
    &CIM_UnixProcess_ParentProcessID_prop,
    &CIM_UnixProcess_RealUserID_prop,
    &CIM_UnixProcess_ProcessGroupID_prop,
    &CIM_UnixProcess_ProcessSessionID_prop,
    &CIM_UnixProcess_ProcessTTY_prop,
    &CIM_UnixProcess_ModulePath_prop,
    &CIM_UnixProcess_Parameters_prop,
    &CIM_UnixProcess_ProcessNiceValue_prop,
    &CIM_UnixProcess_ProcessWaitingForEvent_prop,
};

/* parameter SCX_UnixProcess.RequestStateChange(): RequestedState */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_RequestStateChange_RequestedState_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0072650E, /* code */
    MI_T("RequestedState"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_RequestStateChange, RequestedState), /* offset */
};

/* parameter SCX_UnixProcess.RequestStateChange(): Job */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_RequestStateChange_Job_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006A6203, /* code */
    MI_T("Job"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_REFERENCE, /* type */
    MI_T("CIM_ConcreteJob"), /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_RequestStateChange, Job), /* offset */
};

/* parameter SCX_UnixProcess.RequestStateChange(): TimeoutPeriod */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_RequestStateChange_TimeoutPeriod_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0074640D, /* code */
    MI_T("TimeoutPeriod"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_DATETIME, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_RequestStateChange, TimeoutPeriod), /* offset */
};

/* parameter SCX_UnixProcess.RequestStateChange(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_RequestStateChange_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_RequestStateChange, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_UnixProcess_RequestStateChange_params[] =
{
    &SCX_UnixProcess_RequestStateChange_MIReturn_param,
    &SCX_UnixProcess_RequestStateChange_RequestedState_param,
    &SCX_UnixProcess_RequestStateChange_Job_param,
    &SCX_UnixProcess_RequestStateChange_TimeoutPeriod_param,
};

/* method SCX_UnixProcess.RequestStateChange() */
MI_CONST MI_MethodDecl SCX_UnixProcess_RequestStateChange_rtti =
{
    MI_FLAG_METHOD, /* flags */
    0x00726512, /* code */
    MI_T("RequestStateChange"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_UnixProcess_RequestStateChange_params, /* parameters */
    MI_COUNT(SCX_UnixProcess_RequestStateChange_params), /* numParameters */
    sizeof(SCX_UnixProcess_RequestStateChange), /* size */
    MI_UINT32, /* returnType */
    MI_T("CIM_EnabledLogicalElement"), /* origin */
    MI_T("CIM_EnabledLogicalElement"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_UnixProcess_Invoke_RequestStateChange, /* method */
};

/* parameter SCX_UnixProcess.TopResourceConsumers(): resource */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_TopResourceConsumers_resource_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00726508, /* code */
    MI_T("resource"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_TopResourceConsumers, resource), /* offset */
};

/* parameter SCX_UnixProcess.TopResourceConsumers(): count */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_TopResourceConsumers_count_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x00637405, /* code */
    MI_T("count"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT16, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_TopResourceConsumers, count), /* offset */
};

/* parameter SCX_UnixProcess.TopResourceConsumers(): elevationType */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_TopResourceConsumers_elevationType_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_IN, /* flags */
    0x0065650D, /* code */
    MI_T("elevationType"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_TopResourceConsumers, elevationType), /* offset */
};

/* parameter SCX_UnixProcess.TopResourceConsumers(): MIReturn */
static MI_CONST MI_ParameterDecl SCX_UnixProcess_TopResourceConsumers_MIReturn_param =
{
    MI_FLAG_PARAMETER|MI_FLAG_OUT, /* flags */
    0x006D6E08, /* code */
    MI_T("MIReturn"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcess_TopResourceConsumers, MIReturn), /* offset */
};

static MI_ParameterDecl MI_CONST* MI_CONST SCX_UnixProcess_TopResourceConsumers_params[] =
{
    &SCX_UnixProcess_TopResourceConsumers_MIReturn_param,
    &SCX_UnixProcess_TopResourceConsumers_resource_param,
    &SCX_UnixProcess_TopResourceConsumers_count_param,
    &SCX_UnixProcess_TopResourceConsumers_elevationType_param,
};

/* method SCX_UnixProcess.TopResourceConsumers() */
MI_CONST MI_MethodDecl SCX_UnixProcess_TopResourceConsumers_rtti =
{
    MI_FLAG_METHOD|MI_FLAG_STATIC, /* flags */
    0x00747314, /* code */
    MI_T("TopResourceConsumers"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    SCX_UnixProcess_TopResourceConsumers_params, /* parameters */
    MI_COUNT(SCX_UnixProcess_TopResourceConsumers_params), /* numParameters */
    sizeof(SCX_UnixProcess_TopResourceConsumers), /* size */
    MI_STRING, /* returnType */
    MI_T("SCX_UnixProcess"), /* origin */
    MI_T("SCX_UnixProcess"), /* propagator */
    &schemaDecl, /* schema */
    (MI_ProviderFT_Invoke)SCX_UnixProcess_Invoke_TopResourceConsumers, /* method */
};

static MI_MethodDecl MI_CONST* MI_CONST SCX_UnixProcess_meths[] =
{
    &SCX_UnixProcess_RequestStateChange_rtti,
    &SCX_UnixProcess_TopResourceConsumers_rtti,
};

static MI_CONST MI_ProviderFT SCX_UnixProcess_funcs =
{
  (MI_ProviderFT_Load)SCX_UnixProcess_Load,
  (MI_ProviderFT_Unload)SCX_UnixProcess_Unload,
  (MI_ProviderFT_GetInstance)SCX_UnixProcess_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_UnixProcess_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_UnixProcess_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_UnixProcess_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_UnixProcess_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_UnixProcess_UMLPackagePath_qual_value = MI_T("CIM::System::Unix");

static MI_CONST MI_Qualifier SCX_UnixProcess_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_UnixProcess_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_UnixProcess_Version_qual_value = MI_T("1.3.0");

static MI_CONST MI_Qualifier SCX_UnixProcess_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_UnixProcess_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcess_quals[] =
{
    &SCX_UnixProcess_UMLPackagePath_qual,
    &SCX_UnixProcess_Version_qual,
};

/* class SCX_UnixProcess */
MI_CONST MI_ClassDecl SCX_UnixProcess_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x0073730F, /* code */
    MI_T("SCX_UnixProcess"), /* name */
    SCX_UnixProcess_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcess_quals), /* numQualifiers */
    SCX_UnixProcess_props, /* properties */
    MI_COUNT(SCX_UnixProcess_props), /* numProperties */
    sizeof(SCX_UnixProcess), /* size */
    MI_T("CIM_UnixProcess"), /* superClass */
    &CIM_UnixProcess_rtti, /* superClassDecl */
    SCX_UnixProcess_meths, /* methods */
    MI_COUNT(SCX_UnixProcess_meths), /* numMethods */
    &schemaDecl, /* schema */
    &SCX_UnixProcess_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** CIM_UnixProcessStatisticalInformation
**
**==============================================================================
*/

static MI_CONST MI_Uint32 CIM_UnixProcessStatisticalInformation_Name_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_Name_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_UnixProcessStatisticalInformation_Name_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_Name_Override_qual_value = MI_T("Name");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_Name_Override_qual =
{
    MI_T("Override"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_RESTRICTED,
    &CIM_UnixProcessStatisticalInformation_Name_Override_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_Name_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_Name_MaxLen_qual,
    &CIM_UnixProcessStatisticalInformation_Name_Override_qual,
};

/* property CIM_UnixProcessStatisticalInformation.Name */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_Name_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006E6504, /* code */
    MI_T("Name"), /* name */
    CIM_UnixProcessStatisticalInformation_Name_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_Name_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, Name), /* offset */
    MI_T("CIM_StatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_UnixProcessStatisticalInformation_CSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_CSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_UnixProcessStatisticalInformation_CSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_CSCreationClassName_Propagated_qual_value = MI_T("CIM_Process.CSCreationClassName");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_CSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_UnixProcessStatisticalInformation_CSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_CSCreationClassName_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_CSCreationClassName_MaxLen_qual,
    &CIM_UnixProcessStatisticalInformation_CSCreationClassName_Propagated_qual,
};

/* property CIM_UnixProcessStatisticalInformation.CSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_CSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636513, /* code */
    MI_T("CSCreationClassName"), /* name */
    CIM_UnixProcessStatisticalInformation_CSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_CSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, CSCreationClassName), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_UnixProcessStatisticalInformation_CSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_CSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_UnixProcessStatisticalInformation_CSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_CSName_Propagated_qual_value = MI_T("CIM_Process.CSName");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_CSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_UnixProcessStatisticalInformation_CSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_CSName_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_CSName_MaxLen_qual,
    &CIM_UnixProcessStatisticalInformation_CSName_Propagated_qual,
};

/* property CIM_UnixProcessStatisticalInformation.CSName */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_CSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00636506, /* code */
    MI_T("CSName"), /* name */
    CIM_UnixProcessStatisticalInformation_CSName_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_CSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, CSName), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_UnixProcessStatisticalInformation_OSCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_OSCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_UnixProcessStatisticalInformation_OSCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_OSCreationClassName_Propagated_qual_value = MI_T("CIM_Process.OSCreationClassName");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_OSCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_UnixProcessStatisticalInformation_OSCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_OSCreationClassName_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_OSCreationClassName_MaxLen_qual,
    &CIM_UnixProcessStatisticalInformation_OSCreationClassName_Propagated_qual,
};

/* property CIM_UnixProcessStatisticalInformation.OSCreationClassName */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_OSCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006F6513, /* code */
    MI_T("OSCreationClassName"), /* name */
    CIM_UnixProcessStatisticalInformation_OSCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_OSCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, OSCreationClassName), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_UnixProcessStatisticalInformation_OSName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_OSName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_UnixProcessStatisticalInformation_OSName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_OSName_Propagated_qual_value = MI_T("CIM_Process.OSName");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_OSName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_UnixProcessStatisticalInformation_OSName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_OSName_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_OSName_MaxLen_qual,
    &CIM_UnixProcessStatisticalInformation_OSName_Propagated_qual,
};

/* property CIM_UnixProcessStatisticalInformation.OSName */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_OSName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x006F6506, /* code */
    MI_T("OSName"), /* name */
    CIM_UnixProcessStatisticalInformation_OSName_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_OSName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, OSName), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_UnixProcessStatisticalInformation_Handle_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_Handle_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_UnixProcessStatisticalInformation_Handle_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_Handle_Propagated_qual_value = MI_T("CIM_Process.Handle");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_Handle_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_UnixProcessStatisticalInformation_Handle_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_Handle_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_Handle_MaxLen_qual,
    &CIM_UnixProcessStatisticalInformation_Handle_Propagated_qual,
};

/* property CIM_UnixProcessStatisticalInformation.Handle */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_Handle_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00686506, /* code */
    MI_T("Handle"), /* name */
    CIM_UnixProcessStatisticalInformation_Handle_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_Handle_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, Handle), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Uint32 CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_MaxLen_qual_value = 256U;

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_MaxLen_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_Propagated_qual_value = MI_T("CIM_Process.CreationClassName");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_Propagated_qual =
{
    MI_T("Propagated"),
    MI_STRING,
    MI_FLAG_DISABLEOVERRIDE|MI_FLAG_TOSUBCLASS,
    &CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_Propagated_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_MaxLen_qual,
    &CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_Propagated_qual,
};

/* property CIM_UnixProcessStatisticalInformation.ProcessCreationClassName */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00706518, /* code */
    MI_T("ProcessCreationClassName"), /* name */
    CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, ProcessCreationClassName), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_CPUTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_CPUTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_CPUTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_CPUTime_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_CPUTime_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.CPUTime */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_CPUTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636507, /* code */
    MI_T("CPUTime"), /* name */
    CIM_UnixProcessStatisticalInformation_CPUTime_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_CPUTime_quals), /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, CPUTime), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_RealText_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_RealText_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_RealText_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_RealText_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_RealText_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.RealText */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_RealText_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00727408, /* code */
    MI_T("RealText"), /* name */
    CIM_UnixProcessStatisticalInformation_RealText_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_RealText_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, RealText), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_RealData_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_RealData_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_RealData_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_RealData_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_RealData_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.RealData */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_RealData_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726108, /* code */
    MI_T("RealData"), /* name */
    CIM_UnixProcessStatisticalInformation_RealData_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_RealData_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, RealData), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_RealStack_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_RealStack_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_RealStack_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_RealStack_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_RealStack_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.RealStack */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_RealStack_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00726B09, /* code */
    MI_T("RealStack"), /* name */
    CIM_UnixProcessStatisticalInformation_RealStack_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_RealStack_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, RealStack), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_VirtualText_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_VirtualText_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_VirtualText_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_VirtualText_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_VirtualText_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.VirtualText */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_VirtualText_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0076740B, /* code */
    MI_T("VirtualText"), /* name */
    CIM_UnixProcessStatisticalInformation_VirtualText_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_VirtualText_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, VirtualText), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_VirtualData_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_VirtualData_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_VirtualData_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_VirtualData_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_VirtualData_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.VirtualData */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_VirtualData_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0076610B, /* code */
    MI_T("VirtualData"), /* name */
    CIM_UnixProcessStatisticalInformation_VirtualData_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_VirtualData_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, VirtualData), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_VirtualStack_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_VirtualStack_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_VirtualStack_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_VirtualStack_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_VirtualStack_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.VirtualStack */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_VirtualStack_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00766B0C, /* code */
    MI_T("VirtualStack"), /* name */
    CIM_UnixProcessStatisticalInformation_VirtualStack_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_VirtualStack_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, VirtualStack), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.VirtualMemoryMappedFileSize */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0076651B, /* code */
    MI_T("VirtualMemoryMappedFileSize"), /* name */
    CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, VirtualMemoryMappedFileSize), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.VirtualSharedMemory */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00767913, /* code */
    MI_T("VirtualSharedMemory"), /* name */
    CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, VirtualSharedMemory), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_Units_qual_value = MI_T("Clock Ticks");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.CpuTimeDeadChildren */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E13, /* code */
    MI_T("CpuTimeDeadChildren"), /* name */
    CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, CpuTimeDeadChildren), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_Units_qual_value = MI_T("Clock Ticks");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_Units_qual,
};

/* property CIM_UnixProcessStatisticalInformation.SystemTimeDeadChildren */
static MI_CONST MI_PropertyDecl CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736E16, /* code */
    MI_T("SystemTimeDeadChildren"), /* name */
    CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(CIM_UnixProcessStatisticalInformation, SystemTimeDeadChildren), /* offset */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* origin */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &CIM_ManagedElement_Caption_prop,
    &CIM_ManagedElement_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_UnixProcessStatisticalInformation_Name_prop,
    &CIM_UnixProcessStatisticalInformation_CSCreationClassName_prop,
    &CIM_UnixProcessStatisticalInformation_CSName_prop,
    &CIM_UnixProcessStatisticalInformation_OSCreationClassName_prop,
    &CIM_UnixProcessStatisticalInformation_OSName_prop,
    &CIM_UnixProcessStatisticalInformation_Handle_prop,
    &CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_prop,
    &CIM_UnixProcessStatisticalInformation_CPUTime_prop,
    &CIM_UnixProcessStatisticalInformation_RealText_prop,
    &CIM_UnixProcessStatisticalInformation_RealData_prop,
    &CIM_UnixProcessStatisticalInformation_RealStack_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualText_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualData_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualStack_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_prop,
    &CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_prop,
    &CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_prop,
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::System::Unix");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &CIM_UnixProcessStatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* CIM_UnixProcessStatisticalInformation_Version_qual_value = MI_T("2.6.0");

static MI_CONST MI_Qualifier CIM_UnixProcessStatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &CIM_UnixProcessStatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST CIM_UnixProcessStatisticalInformation_quals[] =
{
    &CIM_UnixProcessStatisticalInformation_UMLPackagePath_qual,
    &CIM_UnixProcessStatisticalInformation_Version_qual,
};

/* class CIM_UnixProcessStatisticalInformation */
MI_CONST MI_ClassDecl CIM_UnixProcessStatisticalInformation_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00636E25, /* code */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* name */
    CIM_UnixProcessStatisticalInformation_quals, /* qualifiers */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_quals), /* numQualifiers */
    CIM_UnixProcessStatisticalInformation_props, /* properties */
    MI_COUNT(CIM_UnixProcessStatisticalInformation_props), /* numProperties */
    sizeof(CIM_UnixProcessStatisticalInformation), /* size */
    MI_T("CIM_StatisticalInformation"), /* superClass */
    &CIM_StatisticalInformation_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    NULL, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** SCX_UnixProcessStatisticalInformation
**
**==============================================================================
*/

static MI_CONST MI_Uint32 SCX_UnixProcessStatisticalInformation_Caption_MaxLen_qual_value = 64U;

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_Caption_MaxLen_qual =
{
    MI_T("MaxLen"),
    MI_UINT32,
    0,
    &SCX_UnixProcessStatisticalInformation_Caption_MaxLen_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_Caption_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_Caption_MaxLen_qual,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_Caption_value = MI_T("Unix process information");

/* property SCX_UnixProcessStatisticalInformation.Caption */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_Caption_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00636E07, /* code */
    MI_T("Caption"), /* name */
    SCX_UnixProcessStatisticalInformation_Caption_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_Caption_quals), /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, Caption), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    &SCX_UnixProcessStatisticalInformation_Caption_value,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_Description_value = MI_T("Performance statistics for an individual Unix process");

/* property SCX_UnixProcessStatisticalInformation.Description */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_Description_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00646E0B, /* code */
    MI_T("Description"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, Description), /* offset */
    MI_T("CIM_ManagedElement"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    &SCX_UnixProcessStatisticalInformation_Description_value,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.BlockReadsPerSecond */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00626413, /* code */
    MI_T("BlockReadsPerSecond"), /* name */
    SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, BlockReadsPerSecond), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.BlockWritesPerSecond */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00626414, /* code */
    MI_T("BlockWritesPerSecond"), /* name */
    SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, BlockWritesPerSecond), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_Units_qual_value = MI_T("Transfers per Second");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.BlockTransfersPerSecond */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00626417, /* code */
    MI_T("BlockTransfersPerSecond"), /* name */
    SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, BlockTransfersPerSecond), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_PercentUserTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_PercentUserTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_PercentUserTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_PercentUserTime_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_PercentUserTime_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.PercentUserTime */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_PercentUserTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650F, /* code */
    MI_T("PercentUserTime"), /* name */
    SCX_UnixProcessStatisticalInformation_PercentUserTime_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_PercentUserTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, PercentUserTime), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.PercentPrivilegedTime */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00706515, /* code */
    MI_T("PercentPrivilegedTime"), /* name */
    SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, PercentPrivilegedTime), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_UsedMemory_Units_qual_value = MI_T("KiloBytes");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_UsedMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_UsedMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_UsedMemory_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_UsedMemory_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.UsedMemory */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_UsedMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0075790A, /* code */
    MI_T("UsedMemory"), /* name */
    SCX_UnixProcessStatisticalInformation_UsedMemory_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_UsedMemory_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, UsedMemory), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_PercentUsedMemory_Units_qual_value = MI_T("Percent");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_PercentUsedMemory_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_PercentUsedMemory_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_PercentUsedMemory_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_PercentUsedMemory_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.PercentUsedMemory */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_PercentUsedMemory_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00707911, /* code */
    MI_T("PercentUsedMemory"), /* name */
    SCX_UnixProcessStatisticalInformation_PercentUsedMemory_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_PercentUsedMemory_quals), /* numQualifiers */
    MI_UINT8, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, PercentUsedMemory), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_PagesReadPerSec_Units_qual_value = MI_T("Pages per Second");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_PagesReadPerSec_Units_qual =
{
    MI_T("Units"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TOSUBCLASS|MI_FLAG_TRANSLATABLE,
    &SCX_UnixProcessStatisticalInformation_PagesReadPerSec_Units_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_PagesReadPerSec_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_PagesReadPerSec_Units_qual,
};

/* property SCX_UnixProcessStatisticalInformation.PagesReadPerSec */
static MI_CONST MI_PropertyDecl SCX_UnixProcessStatisticalInformation_PagesReadPerSec_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070630F, /* code */
    MI_T("PagesReadPerSec"), /* name */
    SCX_UnixProcessStatisticalInformation_PagesReadPerSec_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_PagesReadPerSec_quals), /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(SCX_UnixProcessStatisticalInformation, PagesReadPerSec), /* offset */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* origin */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_props[] =
{
    &CIM_ManagedElement_InstanceID_prop,
    &SCX_UnixProcessStatisticalInformation_Caption_prop,
    &SCX_UnixProcessStatisticalInformation_Description_prop,
    &CIM_ManagedElement_ElementName_prop,
    &CIM_UnixProcessStatisticalInformation_Name_prop,
    &CIM_UnixProcessStatisticalInformation_CSCreationClassName_prop,
    &CIM_UnixProcessStatisticalInformation_CSName_prop,
    &CIM_UnixProcessStatisticalInformation_OSCreationClassName_prop,
    &CIM_UnixProcessStatisticalInformation_OSName_prop,
    &CIM_UnixProcessStatisticalInformation_Handle_prop,
    &CIM_UnixProcessStatisticalInformation_ProcessCreationClassName_prop,
    &CIM_UnixProcessStatisticalInformation_CPUTime_prop,
    &CIM_UnixProcessStatisticalInformation_RealText_prop,
    &CIM_UnixProcessStatisticalInformation_RealData_prop,
    &CIM_UnixProcessStatisticalInformation_RealStack_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualText_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualData_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualStack_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualMemoryMappedFileSize_prop,
    &CIM_UnixProcessStatisticalInformation_VirtualSharedMemory_prop,
    &CIM_UnixProcessStatisticalInformation_CpuTimeDeadChildren_prop,
    &CIM_UnixProcessStatisticalInformation_SystemTimeDeadChildren_prop,
    &SCX_UnixProcessStatisticalInformation_BlockReadsPerSecond_prop,
    &SCX_UnixProcessStatisticalInformation_BlockWritesPerSecond_prop,
    &SCX_UnixProcessStatisticalInformation_BlockTransfersPerSecond_prop,
    &SCX_UnixProcessStatisticalInformation_PercentUserTime_prop,
    &SCX_UnixProcessStatisticalInformation_PercentPrivilegedTime_prop,
    &SCX_UnixProcessStatisticalInformation_UsedMemory_prop,
    &SCX_UnixProcessStatisticalInformation_PercentUsedMemory_prop,
    &SCX_UnixProcessStatisticalInformation_PagesReadPerSec_prop,
};

static MI_CONST MI_ProviderFT SCX_UnixProcessStatisticalInformation_funcs =
{
  (MI_ProviderFT_Load)SCX_UnixProcessStatisticalInformation_Load,
  (MI_ProviderFT_Unload)SCX_UnixProcessStatisticalInformation_Unload,
  (MI_ProviderFT_GetInstance)SCX_UnixProcessStatisticalInformation_GetInstance,
  (MI_ProviderFT_EnumerateInstances)SCX_UnixProcessStatisticalInformation_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)SCX_UnixProcessStatisticalInformation_CreateInstance,
  (MI_ProviderFT_ModifyInstance)SCX_UnixProcessStatisticalInformation_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)SCX_UnixProcessStatisticalInformation_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_UMLPackagePath_qual_value = MI_T("CIM::System::Unix");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_UMLPackagePath_qual =
{
    MI_T("UMLPackagePath"),
    MI_STRING,
    0,
    &SCX_UnixProcessStatisticalInformation_UMLPackagePath_qual_value
};

static MI_CONST MI_Char* SCX_UnixProcessStatisticalInformation_Version_qual_value = MI_T("1.4.17");

static MI_CONST MI_Qualifier SCX_UnixProcessStatisticalInformation_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &SCX_UnixProcessStatisticalInformation_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST SCX_UnixProcessStatisticalInformation_quals[] =
{
    &SCX_UnixProcessStatisticalInformation_UMLPackagePath_qual,
    &SCX_UnixProcessStatisticalInformation_Version_qual,
};

/* class SCX_UnixProcessStatisticalInformation */
MI_CONST MI_ClassDecl SCX_UnixProcessStatisticalInformation_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x00736E25, /* code */
    MI_T("SCX_UnixProcessStatisticalInformation"), /* name */
    SCX_UnixProcessStatisticalInformation_quals, /* qualifiers */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_quals), /* numQualifiers */
    SCX_UnixProcessStatisticalInformation_props, /* properties */
    MI_COUNT(SCX_UnixProcessStatisticalInformation_props), /* numProperties */
    sizeof(SCX_UnixProcessStatisticalInformation), /* size */
    MI_T("CIM_UnixProcessStatisticalInformation"), /* superClass */
    &CIM_UnixProcessStatisticalInformation_rtti, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &SCX_UnixProcessStatisticalInformation_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** __mi_server
**
**==============================================================================
*/

MI_Server* __mi_server;
/*
**==============================================================================
**
** Schema
**
**==============================================================================
*/

static MI_ClassDecl MI_CONST* MI_CONST classes[] =
{
    &CIM_ConcreteJob_rtti,
    &CIM_DiskDrive_rtti,
    &CIM_EnabledLogicalElement_rtti,
    &CIM_Error_rtti,
    &CIM_EthernetPortStatistics_rtti,
    &CIM_FileSystem_rtti,
    &CIM_IPProtocolEndpoint_rtti,
    &CIM_Job_rtti,
    &CIM_LANEndpoint_rtti,
    &CIM_LogicalDevice_rtti,
    &CIM_LogicalElement_rtti,
    &CIM_LogicalFile_rtti,
    &CIM_ManagedElement_rtti,
    &CIM_ManagedSystemElement_rtti,
    &CIM_MediaAccessDevice_rtti,
    &CIM_NetworkPortStatistics_rtti,
    &CIM_OperatingSystem_rtti,
    &CIM_Process_rtti,
    &CIM_ProtocolEndpoint_rtti,
    &CIM_ServiceAccessPoint_rtti,
    &CIM_StatisticalData_rtti,
    &CIM_StatisticalInformation_rtti,
    &CIM_UnixProcess_rtti,
    &CIM_UnixProcessStatisticalInformation_rtti,
    &SCX_Agent_rtti,
    &SCX_Application_Server_rtti,
    &SCX_DiskDrive_rtti,
    &SCX_DiskDriveStatisticalInformation_rtti,
    &SCX_EthernetPortStatistics_rtti,
    &SCX_FileSystem_rtti,
    &SCX_FileSystemStatisticalInformation_rtti,
    &SCX_IPProtocolEndpoint_rtti,
    &SCX_LANEndpoint_rtti,
    &SCX_LogFile_rtti,
    &SCX_MemoryStatisticalInformation_rtti,
    &SCX_OperatingSystem_rtti,
    &SCX_ProcessorStatisticalInformation_rtti,
    &SCX_StatisticalInformation_rtti,
    &SCX_UnixProcess_rtti,
    &SCX_UnixProcessStatisticalInformation_rtti,
};

MI_SchemaDecl schemaDecl =
{
    NULL, /* qualifierDecls */
    0, /* numQualifierDecls */
    classes, /* classDecls */
    MI_COUNT(classes), /* classDecls */
};

/*
**==============================================================================
**
** MI_Server Methods
**
**==============================================================================
*/

MI_Result MI_CALL MI_Server_GetVersion(
    MI_Uint32* version){
    return __mi_server->serverFT->GetVersion(version);
}

MI_Result MI_CALL MI_Server_GetSystemName(
    const MI_Char** systemName)
{
    return __mi_server->serverFT->GetSystemName(systemName);
}

