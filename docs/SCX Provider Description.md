***Providers for Linux and UNIX (XPlatProviders)***

**Table of Contents**

1 Introduction  
1.1 License  
1.2 Platforms  
1.3 About the Providers  
1.4 Installing and Using the Providers  
2 Provider Classes  
2.1 SCX\_Agent  
2.1.1 Name  
2.1.2 Caption  
2.1.3 Description  
2.1.4 VersionString  
2.1.5 MajorVersion  
2.1.6 MinorVersion  
2.1.7 RevisionNumber  
2.1.8 BuildNumber  
2.1.9 BuildDate  
2.1.10 Architecture  
2.1.11 OSName  
2.1.12 OSType  
2.1.13 OSVersion  
2.1.14 KitVersionString  
2.1.15 Hostname  
2.1.16 OSAlias  
2.1.17 UnameArchitecture  
2.1.18 MinActiveLogSeverityThreshold  
2.1.19 MachineType  
2.1.20 PhysicalProcessors  
2.1.21 LogicalProcessors  
2.2 SCX\_DiskDrive  
2.2.1 Caption  
2.2.2 Description  
2.2.3 Name  
2.2.4 IsOnline  
2.2.5 InterfaceType  
2.2.6 Manufacturer  
2.2.7 Model  
2.2.8 TotalCylinders  
2.2.9 TotalHeads  
2.2.10 TotalSectors  
2.2.11 TotalTracks  
2.2.12 TracksPerCylinder  
2.2.13 RemoveByName()  
2.3 SCX\_FileSystem  
2.3.1 Caption  
2.3.2 Description  
2.3.3 IsOnline  
2.3.4 TotalInodes  
2.3.5 FreeInodes  
2.3.6 RemoveByName  
2.4 SCX\_LogFile  
2.4.1 GetMatchedRows  
2.5 SCX\_UnixProcess  
2.5.1 Caption  
2.5.2 Description  
2.5.3 TopResourceConsumers()  
2.6 SCX\_IPProtocolEndpoint  
2.6.1 Caption  
2.6.2 Description  
2.6.3 IPv4BroadcastAddress  
2.7 SCX\_OperatingSystem  
2.7.1 Caption  
2.7.2 Description  
2.7.3 OperatingSystemCapability  
2.7.4 SystemUpTime  
2.7.5 ExecuteCommand()  
2.7.6 ExecuteShellCommand()  
2.7.7 ExecuteScript()  
2.8 SCX\_StatisticalInformation  
2.8.1 IsAggregate  
2.9 SCX\_ProcessorStatisticalInformation  
2.9.1 Caption  
2.9.2 Description  
2.9.3 Name  
2.9.4 PercentIdleTime  
2.9.5 PercentUserTime  
2.9.6 PercentNiceTime  
2.9.7 PercentPrivilegedTime  
2.9.8 PercentDPCTime  
2.9.9 PercentProcessorTime  
2.9.10 PercentIOWaitTime  
2.10 SCX\_MemoryStatisticalInformation  
2.10.1 Caption  
2.10.2 Description  
2.10.3 Name  
2.10.4 AvailableMemory  
2.10.5 PercentAvailableMemory  
2.10.6 UsedMemory  
2.10.7 PercentUsedMemory  
2.10.8 PagesPerSec  
2.10.9 PagesReadPerSec  
2.10.10 PagesWrittenPerSec  
2.10.11 AvailableSwap  
2.10.12 PercentAvailableSwap  
2.10.13 UsedSwap  
2.10.14 PercentUsedSwap  
2.11 SCX\_EthernetPortStatistics  
2.11.1 Caption  
2.11.2 Description  
2.11.3 BytesTotal  
2.11.4 TotalRxErrors  
2.11.5 TotalTxErrors  
2.11.6 TotalCollisions  
2.12 SCX\_DiskDriveStatisticalInformation  
2.12.1 Caption  
2.12.2 Description  
2.12.3 Name  
2.12.4 IsOnline  
2.12.5 PercentBusyTime  
2.12.6 PercentIdleTime  
2.12.7 BytesPerSecond  
2.12.8 ReadBytesPerSecond  
2.12.9 WriteBytesPerSecond  
2.12.10 TransfersPerSecond  
2.12.11 ReadsPerSecond  
2.12.12 WritePerSecond  
2.12.13 AverageReadTime  
2.12.14 AverageWriteTime  
2.12.15 AverageTransferTime  
2.12.16 AverageDiskQueueLength  
2.13 SCX\_FileSystemStatisticalInformation  
2.13.1 Caption  
2.13.2 Description  
2.13.3 Name  
2.13.4 IsOnline  
2.13.5 FreeMegabytes  
2.13.6 UsedMegabytes  
2.13.7 PercentFreeSpace  
2.13.8 PercentUsedSpace  
2.13.9 PercentFreeInodes  
2.13.10 PercentUsedInodes  
2.13.11 PercentBusyTime  
2.13.12 PercentIdleTime  
2.13.13 BytesPerSecond  
2.13.14 ReadBytesPerSecond  
2.13.15 WriteBytesPerSecond  
2.13.16 TransfersPerSecond  
2.13.17 ReadsPerSecond  
2.13.18 WritesPerSecond  
2.13.19 AverageTransferTime  
2.13.20 AverageDiskQueueLength  
2.14 SCX\_UnixProcessStatisticalInformation  
2.14.1 Caption  
2.14.2 Description  
2.14.3 BlockReadsPerSecond  
2.14.4 BlockWritesPerSecond  
2.14.5 BlockTransfersPerSecond  
2.14.6 PercentUserTime  
2.14.7 PercentPrivilegedTime  
2.14.8 UsedMemory  
2.14.9 PercentUsedMemory  
2.14.10 PagesReadPerSec  
2.15 SCX\_LANEndpoint  
2.15.1 Caption   
2.15.2 Description  
2.15.3 Name  
2.15.4 MACAddress  
2.15.5 FormattedMACAddress  
  
  
3 Configuration Files  
3.1 scxlog.conf  
3.2 scxrunas.conf

**1 Introduction**

Welcome to the Providers for Linux and UNIX, a set of providers for
Linux and UNIX operating systems as used in System Center 2012 R2
Operations Manager. This document describes the classes, properties, and
methods implemented by these providers.  
  
1.1 License  
The Providers for Linux and UNIX are published under the Microsoft
Public License, which is described here
http://opensource.org/licenses/ms-pl.html.  
  
1.2 Platforms  
The Providers for Linux and UNIX have been tested on the following
operating systems:

-   Red Hat Enterprise Linux 4, 5, and 6 (x86/x64)

-   SUSE Linux Enterprise Server 9 (x86), 10 SP1 (x86/x64), and
    11 (x86/64)

-   CentOS Linux 5 and 6 (x86/64)

-   Debian GNU/Linux 5, 6, and 7 (x86/x64)

-   Oracle Linux 5 and 6 (x86/x64)

-   Ubuntu Linux Server 10.04 and 12.04 (x86/x64)

-   IBM AIX 5.3, 6.1, and 7.1 (POWER)

-   HP-UX 11i v2 and v3 (PA-RISC and IA64)

-   Oracle Solaris 9 (SPARC), Solaris 10 (SPARC and x86), and Solaris 11
    (SPARC and x86)

1.3 About the Providers  
The Providers for Linux and UNIX are intended for use with Open
Management Infras- tructure(OMI):
[*https://collaboration.opengroup.org/omi/*](https://collaboration.opengroup.org/omi/).  
  
1.4 Installing and Using the Providers  
Details on unpacking the source code, building the providers, and
creating a working version of the Operations Manager agent for Linux and
UNIX is described in a separate document entitled "Building Linux UNIX
Agents.pdf". That document is available for download on the
http://scx.codeplex.com site.

**2 Provider Classes**

This chapter discusses the CIM classes and methods implemented by
XPlatProviders. See scx.mof, located in the MOF installation directory
(--mofdir) for more details.  
  
2.1 SCX\_Agent  
There is a single instance of this class. It provides information about
the XPlatProviders package and the system it is installed on. The
following instance was obtained from a Suse 10.1 system.  
  
Name = "scx"  
Caption = "SCX Agent meta-information"  
Description = "Developer\_Build - 20090426"  
VersionString = "1.0.4-249"  
MajorVersion = 1  
MinorVersion = 0  
RevisionNumber = 4  
BuildNumber = 249  
BuildDate = "2009-04-26T00:00:00Z"  
Architecture = "x86";  
OSName = "SUSE Linux Enterprise Server"  
OSType = "Linux"  
OSVersion = "10.1"  
Hostname = "scxcore-suse01.scx.com"  
OSAlias = "SLES"  
UnameArchitecture = "i686"  
MinActiveLogSeverityThreshold = "INFO"  
MachineType = "Virtual"  
PhysicalProcessors = 2  
LogicalProcessors = 4  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.1.1 Name  
This key property uniquely identifies the single instance of this class.
The value is always "scx", which stands for "System-Center
X-Platform".  
  
2.1.2 Caption  
A human readable name for this instance.  
  
2.1.3 Description  
The build date of XPlatProviders.  
  
2.1.4 VersionString  
The version of XPlatProviders (major, minor, revision, and build
number).  
  
2.1.5 MajorVersion  
The major version number of the XPlatProviders package.  
  
2.1.6 MinorVersion  
The minor version number of the XPlatProviders package.  
  
2.1.7 RevisionNumber  
The revision number of the XPlatProviders package.  
  
2.1.8 BuildNumber  
The build number of the XPlatProviders package.  
  
2.1.9 BuildDate  
The build date of the XPlatProviders package.  
  
2.1.10 Architecture  
The system architecture (e.g., x86 or IA64)  
  
2.1.11 OSName  
The system's operating system type (e.g., Linux or SunOS)  
  
2.1.12 OSType  
The system operating system version (e.g. 10 or 5.10)  
  
2.1.13 OSVersion  
The system operating system version (e.g. 10 or 5.10)  
  
2.1.14 KitVersionString  
A string representing the complete software version of the installed
kit.  
  
2.1.15 Hostname  
The hostname of the machine (including domain name if available).  
  
2.1.16 OSAlias  
Short name version of the OSName that provides an abbreviated name of OS
without formating.  
  
2.1.17 UnameArchitecture  
Output of uname -m or uname -p.  
  
2.1.18 MinActiveLogSeverityThreshold  
Lowest log severity threshold currently in use in the agent, which is
one of the following: "HYSTERICAL", "TRACE", "INFO", "WARNING", "ERROR",
"SUPPRESS".  
  
2.1.19 MachineType  
An indicator of whether the hardware running the monitored operating
system is physical or virtual. Possible valuesof this field are:
"Physical", "Virtual", and "Unknown".  
  
2.1.20 PhysicalProcessors  
The number of physical processors in the hardware, as seen by the
monitored operating system.  
  
2.1.21 LogicalProcessors  
The number of logical processors in the hardware, as seen by the
monitored operating system.  
  
2.2 SCX\_DiskDrive  
Each instance of this class provides information about a disk drive
attached to the current system. A typical instance looks like this.  
  
EnabledState = 5  
RequestedState = 12  
EnabledDefault = 2  
SystemCreationClassName = "SCX\_ComputerSystem"  
SystemName = "scxcore-suse01.scx.com"  
CreationClassName = "SCX\_DiskDrive"  
DeviceID = "sda"  
MaxMediaSize = 17179869184  
Caption = "Disk drive information"  
Description = "Information pertaining to a physical unit of secondary
storage"  
Name = "sda"  
IsOnline = TRUE  
InterfaceType = "SCSI"  
Model = ""  
TotalCylinders = 2088  
TotalHeads = 255  
TotalSectors = 63  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.2.1 Caption  
A human readable caption for this disk.  
  
2.2.2 Description  
A textual description of this disk.  
  
2.2.3 Name  
A unique key property that uniquely identifies this disk.  
  
2.2.4 IsOnline  
True if the disk is online.  
  
2.2.5 InterfaceType  
Type of interface (e.g., SCSI, IDE).  
  
2.2.6 Manufacturer  
Name of the disk manufacturer if available.  
  
2.2.7 Model  
Model of the disk if available.  
  
2.2.8 TotalCylinders  
Total number of cylinders on this disk.  
  
2.2.9 TotalHeads  
Total number of heads on this disk.  
  
2.2.10 TotalSectors  
Total number of sectors on this disk.  
  
2.2.11 TotalTracks  
Total number of tracks on this disk.  
  
2.2.12 TracksPerCylinder  
The number of tracks per cyclinder if available.  
  
2.2.13 RemoveByName()  
boolean SCX\_DiskDrive.RemoveByName(  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string Name)  
  
Remove the disk with the given Name from the list of monitored disks.  
  
2.3 SCX\_FileSystem  
Each instance of this class provides information about a file system on
this computer. Here is an example instance obtained from a Linux system.
This instance represents the root file system.  
  
EnabledState = 5;  
RequestedState = 12;  
EnabledDefault = 2;  
CSCreationClassName = "SCX\_ComputerSystem";  
CSName = "scxcore-suse01.scx.com";  
CreationClassName = "SCX\_FileSystem";  
Name = "/";  
Root = "/";  
BlockSize = 4096;  
FileSystemSize = 16376020992;  
AvailableSpace = 6574993408;  
ReadOnly = FALSE;  
EncryptionMethod = "Not Encrypted";  
CompressionMethod = "Not Compressed";  
CaseSensitive = TRUE;  
CasePreserved = TRUE;  
MaxFileNameLength = 255;  
FileSystemType = "reiserfs";  
PersistenceType = 2;  
Caption = "File system information";  
Description = "Information about a logical unit of secondary storage";  
IsOnline = TRUE;  
TotalInodes = 2048000;  
FreeInodes = 1984563;  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.3.1 Caption  
A human-readable caption for this insatnce.  
  
2.3.2 Description  
A human-readable description of this instance.  
  
2.3.3 IsOnline  
True if this file system is online (mounted).  
  
2.3.4 TotalInodes  
The total number of inodes allocated in this file system. A value of
zero indicates that this file system does not have a preset number of
inodes.  
  
2.3.5 FreeInodes  
The number of inodes in this file system that are currently free and
hence available for creating a new file.  
  
2.3.6 RemoveByName  
boolean RemoveByName(  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string Name)  
  
Removes from the list of monitored file systems.  
  
2.4 SCX\_LogFile  
Each instance of this class provides information about a \`log' file, on
which SCX\_LogFile.GetMatchedRows() has been called. It defines a single
static method, described below.  
  
2.4.1 GetMatchedRows  
uint32 GetMatchedRows(  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string filename,  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string regexps\[\],  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string qid,  
[*OUT,
ArrayType("Ordered")*](https://scx.codeplex.com/wikipage?title=OUT%2c%20ArrayType%28%22Ordered%22%29&referringTitle=xplatproviders)
string rows\[\]);  
  
Gets rows from the named file that match any of the supplied regular
expressions. On the first invocation, it returns all matching lines in
the file. On subsequent calls, only lines that appeared since the
previous call are returned. After the first call, a CIM instance of
SCX\_LogFile is created. To begin where the previous call left off, you
must pass in exactlyt he same values for the filename, regexps, and qid
parameters.  
  
2.5 SCX\_UnixProcess  
Each instance of this class provides information about a Unix (or Linux)
process. The following instance provides information about the Unix init
process obtained from a Linux system.  
  
EnabledState = 5  
RequestedState = 12  
EnabledDefault = 2  
CSCreationClassName = "SCX\_ComputerSystem"  
CSName = "scxcore-suse01.scx.com"  
OSCreationClassName = "SCX\_OperatingSystem"  
OSName = "SuSE Distribution"  
CreationClassName = "SCX\_UnixProcess"  
Handle = "1"  
Name = "init"  
Priority = 76  
ExecutionState = 6  
CreationDate = "20090416105118.035100-420"  
KernelModeTime = 19300  
UserModeTime = 2000  
ParentProcessID = "0"  
RealUserID = 0  
ProcessGroupID = 0  
ProcessSessionID = 0  
ModulePath = "/sbin/init"  
Parameters = "init
[*3*](https://scx.codeplex.com/wikipage?title=3&referringTitle=xplatproviders)"  
ProcessNiceValue = 20  
ProcessWaitingForEvent = "\_stext"  
Caption = "Unix process information"  
Description = "A snapshot of a current process"  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.5.1 Caption  
A human-readable caption for this instance.  
  
2.5.2 Description  
A human-readable description of this instance.  
  
2.5.3 TopResourceConsumers()  
string TopResourceConsumers(  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string resource,  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
uint16 count)  
  
Returns a list of processes that are the top count consumers of the
given resource. The resoure parameter is one of the following.  
  
"CPUTime"  
"BlockReadsPerSecond"  
"BlockWritesPerSecond"  
"BlockTransfersPerSecond"  
"PercentUserTime"  
"PercentPrivilegedTime"  
"UsedMemory"  
"PercentUsedMemory"  
"PagesReadPerSec"  
The returned string is formatted with one process per line (includes the
pid and process name).  
  
The following call, finds the top 10 consumers of memory.  
  
TopResourceConsumers("UsedMemory", 10)  
  
2.6 SCX\_IPProtocolEndpoint  
Each instance of this class provides information about an IP protocol
endpoint. The following instance provides information about Ethernet
interface eth1.  
  
ElementName = "eth1"  
RequestedState = 12  
EnabledDefault = 2  
SystemCreationClassName = "SCX\_ComputerSystem"  
SystemName = "scxcore-suse01.scx.com"  
CreationClassName = "SCX\_IPProtocolEndpoint"  
EnabledState = 2  
Name = "eth1";  
IPv4Address = "10.195.173.73"  
SubnetMask = "255.255.254.0"  
ProtocolIFType = 4096  
Caption = "IP protocol endpoint information"  
Description = "Properties of an IP protocol connection endpoint"  
IPv4BroadcastAddress = "10.195.173.255"  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.6.1 Caption  
A human-readable caption for this instance.  
  
2.6.2 Description  
A human-readable description of this instance.  
  
2.6.3 IPv4BroadcastAddress  
The IPV4 broadcast IP for this ProtocolEndpoint.  
  
2.7 SCX\_OperatingSystem  
The instance of this class represents the operating system on the
current system. The following instance was obtained from a Linux Suse
10.1 system.  
  
Caption = "SUSE Linux Enterprise Server 10 (i586)"  
Description = "SUSE Linux Enterprise Server 10 (i586)"  
EnabledState = 5  
RequestedState = 12  
EnabledDefault = 2  
CSCreationClassName = "SCX\_ComputerSystem"  
CSName = "scxcore-suse01.scx.com"  
CreationClassName = "SCX\_OperatingSystem"  
Name = "SuSE Distribution"  
OSType = 36  
OtherTypeDescription = "2.6.16.54-0.2.8-smp \#1 SMP Mon Jun 23 13:41:12
UTC 2008"  
Version = "2.6.16.54-0.2.8-smp"  
LastBootUpTime = "20090416105118.029909-420"  
LocalDateTime = "20090610135832.699909-420"  
CurrentTimeZone = -420  
NumberOfLicensedUsers = 0  
NumberOfUsers = 13  
NumberOfProcesses = 114  
MaxNumberOfProcesses = 8192  
TotalSwapSpaceSize = 778240  
TotalVirtualMemorySize = 1292288  
FreeVirtualMemory = 1157120  
FreePhysicalMemory = 386048  
TotalVisibleMemorySize = 514048  
SizeStoredInPagingFiles = 778240  
FreeSpaceInPagingFiles = 771072  
MaxProcessMemorySize = 0  
MaxProcessesPerUser = 4096  
OperatingSystemCapability = "32 bit"  
SystemUpTime = 4763234  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.7.1 Caption  
A human-readable caption for this instance.  
  
2.7.2 Description  
A human-readable description of this instance.  
  
2.7.3 OperatingSystemCapability  
The capability of this operating system, either '32 bit' or '64 bit'.  
  
2.7.4 SystemUpTime  
The elapsed time, in seconds, since the OS was booted. A convenience
property, versus having to calculate the time delta from LastBootUpTime
to LocalDateTime.  
  
2.7.5 ExecuteCommand()  
boolean ExecuteCommand(  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string Command,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
sint32 ReturnCode,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
string StdOut,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
string StdErr,  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
uint32 timeout)  
  
Execute a command, with the option of terminating the command after a
timeout specified in seconds. Never times out if timeout is zero.  
  
2.7.6 ExecuteShellCommand()  
boolean ExecuteShellCommand(  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string Command,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
sint32 ReturnCode,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
string StdOut,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
string StdErr,  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
uint32 timeout)  
  
Execute a command in the default shell, with the option of terminating
the command after a timeout specified in seconds. Never times out if
timeout is zero.  
  
2.7.7 ExecuteScript()  
boolean ExecuteScript(  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string Script,  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
string Arguments,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
sint32 ReturnCode,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
string StdOut,  
[*OUT*](https://scx.codeplex.com/wikipage?title=OUT&referringTitle=xplatproviders)
string StdErr,  
[*IN*](https://scx.codeplex.com/wikipage?title=IN&referringTitle=xplatproviders)
uint32 timeout)  
  
Execute a script, with the option of terminating the script after a
timeout specified in seconds. Never times out if timeout is zero.  
  
2.8 SCX\_StatisticalInformation  
This is a base class for two other classes defined below. It defines one
local property defined below. See the superclass for a description of
inherited features.  
  
2.8.1 IsAggregate  
True if data is aggregated from several instances.  
  
2.9 SCX\_ProcessorStatisticalInformation  
Instances of this class capture statistical information about processors
on the current system. An instance is defined for each processor and an
additional instance is defined that aggregates statiscial information
about all processors. The following instance was obtained from a
dual-processor Linux system and has statistical information about the
first processor.  
  
IsAggregate = FALSE  
Caption = "Processor information"  
Description = "CPU usage statistics"  
Name = "0"  
PercentIdleTime = 0  
PercentUserTime = 0  
PercentNiceTime = 0  
PercentPrivilegedTime = 0  
PercentInterruptTime = 0  
PercentDPCTime = 0  
PercentProcessorTime = 100  
PercentIOWaitTime = 0  
  
A second instance has the following properties.  
  
IsAggregate = FALSE  
Caption = "Processor information"  
Description = "CPU usage statistics"  
Name = "1"  
PercentIdleTime = 0  
PercentUserTime = 0  
PercentNiceTime = 0  
PercentPrivilegedTime = 0  
PercentInterruptTime = 0  
PercentDPCTime = 0  
PercentProcessorTime = 100  
PercentIOWaitTime = 0  
  
And finally, a third instance aggregates these two instances and is
shown below (note that IsAggregate is TRUE).  
  
IsAggregate = TRUE  
Caption = "Processor information"  
Description = "CPU usage statistics"  
Name = "\_Total"  
PercentIdleTime = 0  
PercentUserTime = 0  
PercentNiceTime = 0  
PercentPrivilegedTime = 0  
PercentInterruptTime = 0  
PercentDPCTime = 0  
PercentProcessorTime = 100  
PercentIOWaitTime = 0  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.9.1 Caption  
A human-readable caption for this instance.  
  
2.9.2 Description  
A human-readable description of this instance.  
  
2.9.3 Name  
This key property uniquely identifies this instance. It holds the
processor number.  
  
2.9.4 PercentIdleTime  
Percentage of time during the sample interval that the processor was
idle.  
  
2.9.5 PercentUserTime  
Percentage of non-idle processor time spent in user mode.  
  
2.9.6 PercentNiceTime  
Percentage of non-idle processor time spent in user mode.  
  
2.9.7 PercentPrivilegedTime  
Percentage of non-idle processor time spent in privileged.  
  
2.9.8 PercentDPCTime  
Percentage of time spent receiving and servicing DPC (Deferred Procedure
Calls).  
  
2.9.9 PercentProcessorTime  
Percentage of time that the processor spent executing a non-idle
thread.  
  
2.9.10 PercentIOWaitTime  
Percentage of time that the processor spent waiting for IO operations to
complete.  
  
2.10 SCX\_MemoryStatisticalInformation  
A single instance of this class provides memory statistics for the
current system. The following instance was obtained from a Linux
system.  
  
IsAggregate = TRUE  
Caption = "Memory information"  
Description = "Memory usage and performance statistics"  
Name = "Memory"  
AvailableMemory = 378  
PercentAvailableMemory = 75  
UsedMemory = 124  
PercentUsedMemory = 25  
PagesPerSec = 0  
PagesReadPerSec = 0  
PagesWrittenPerSec = 0  
AvailableSwap = 753  
PercentAvailableSwap = 99  
UsedSwap = 7  
PercentUsedSwap = 1  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.10.1 Caption  
A human-readable caption for this instance.  
  
2.10.2 Description  
A human-readable description of instance.  
  
2.10.3 Name  
This key property uniquely identifies the memory instance.  
  
2.10.4 AvailableMemory  
Available physical memory in megabytes.  
  
2.10.5 PercentAvailableMemory  
Available physical memory in percent.  
  
2.10.6 UsedMemory  
Used physical memory in megabytes.  
  
2.10.7 PercentUsedMemory  
Used physical memory in percent.  
  
2.10.8 PagesPerSec  
Pages read or written from/to disk per second to resolve hard page
faults.  
  
2.10.9 PagesReadPerSec  
Pages read from disk per second to resolve hard page faults.  
  
2.10.10 PagesWrittenPerSec  
Pages written to disk per second to resolve hard page faults.  
  
2.10.11 AvailableSwap  
Available swap space in megabytes.  
  
2.10.12 PercentAvailableSwap  
Available swap space in percent.  
  
2.10.13 UsedSwap  
Used swap space in megabytes.  
  
2.10.14 PercentUsedSwap  
Used swap space in percent.  
  
2.11 SCX\_EthernetPortStatistics  
Each instance of this class provides statiscial information about an
Ethernet port. For example, the following instance provides statistics
for the Ethernet interface eth1.  
  
InstanceID = "eth1"  
SampleInterval = "00000000000000.000000:000"  
BytesTransmitted = 1634798148  
BytesReceived = 2938050399  
PacketsTransmitted = 40129891  
PacketsReceived = 72116482  
Caption = "Ethernet port information"  
Description = "Statistics on transfer performance for a port"  
BytesTotal = 4572848547  
TotalRxErrors = 147  
TotalTxErrors = 0  
TotalCollisions = 0  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.11.1 Caption  
A human-readable caption for this instance.  
  
2.11.2 Description  
A human-readable description of instance.  
  
2.11.3 BytesTotal  
The total number of bytes sent or received through the port.  
  
2.11.4 TotalRxErrors  
The aggregated number of receive errors.  
  
2.11.5 TotalTxErrors  
The aggregated number of transmit errors.  
  
2.11.6 TotalCollisions  
The aggregated number of collisions.  
  
2.12 SCX\_DiskDriveStatisticalInformation  
Each instance of this class provides statiscial information about a disk
drive. For example, consider the following instance.  
  
IsAggregate = TRUE  
Caption = "Disk drive information"  
Description = "Performance statistics related to a physical unit of
secondary storage"  
Name = "\_Total"  
IsOnline = TRUE  
BytesPerSecond = 0  
ReadBytesPerSecond = 0  
WriteBytesPerSecond = 0  
TransfersPerSecond = 0  
ReadsPerSecond = 0  
WritesPerSecond = 0  
AverageReadTime = 0.0000000000000000e+00  
AverageWriteTime = 0.0000000000000000e+00  
AverageTransferTime = 0.0000000000000000e+00  
AverageDiskQueueLength = 0.0000000000000000e+00  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.12.1 Caption  
A human-readable caption for this instance.  
  
2.12.2 Description  
A human-readable description of instance.  
  
2.12.3 Name  
A key property that uniquely identifies this instance.  
  
2.12.4 IsOnline  
True if this disk is online.  
  
2.12.5 PercentBusyTime  
Percent of time the disk is busy.  
  
2.12.6 PercentIdleTime  
Percent of time the disk is idle.  
  
2.12.7 BytesPerSecond  
Total Disk bytes per second.  
  
2.12.8 ReadBytesPerSecond  
Bytes read from disk per second.  
  
2.12.9 WriteBytesPerSecond  
Bytes written to from disk per second.  
  
2.12.10 TransfersPerSecond  
Total I/Os per second.  
  
2.12.11 ReadsPerSecond  
Read I/Os per second.  
  
2.12.12 WritePerSecond  
Write I/Os per second.  
  
2.12.13 AverageReadTime  
Average time, in seconds, of a read of data from the disk.  
  
2.12.14 AverageWriteTime  
Average time, in seconds, of a write of data to the disk.  
  
2.12.15 AverageTransferTime  
Average time, in seconds, of a disk transfer.  
  
2.12.16 AverageDiskQueueLength  
Average number of queued read/write requests.  
  
2.13 SCX\_FileSystemStatisticalInformation  
Each instance of this class provides statiscial information about a file
system. The following instance provides statistics for the root files
sytem.  
  
IsAggregate = FALSE  
Caption = "File system information"  
Description = "Performance statistics related to a logical unit of
secondary storage"  
Name = "/"  
IsOnline = TRUE  
FreeMegabytes = 6271  
UsedMegabytes = 9347  
PercentFreeSpace = 40  
PercentUsedSpace = 60  
PercentFreeInodes = 83  
PercentUsedInodes = 17  
PercentBusyTime = NULL  
PercentIdleTime = NULL  
BytesPerSecond = 1583  
ReadBytesPerSecond = 0  
WriteBytesPerSecond = 1583  
TransfersPerSecond = 0  
ReadsPerSecond = 0  
WritesPerSecond = 0  
AverageTransferTime = NULL  
AverageDiskQueueLength = NULL  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.13.1 Caption  
A human-readable caption for this instance.  
  
2.13.2 Description  
A human-readable description of instance.  
  
2.13.3 Name  
A key property that uniquely identifies this instance.  
  
2.13.4 IsOnline  
True if this file system is online (mounted).  
  
2.13.5 FreeMegabytes  
Available space in megabytes.  
  
2.13.6 UsedMegabytes  
Used space in megabytes.  
  
2.13.7 PercentFreeSpace  
Available space in percent.  
  
2.13.8 PercentUsedSpace  
Used space in percent.  
  
2.13.9 PercentFreeInodes  
Available inodes in percent.  
  
2.13.10 PercentUsedInodes  
Used inodes in percent.  
  
2.13.11 PercentBusyTime  
Percent of time filesystem is busy.  
  
2.13.12 PercentIdleTime  
Percent of time filesystem is idle.  
  
2.13.13 BytesPerSecond  
Total bytes per second.  
  
2.13.14 ReadBytesPerSecond  
Bytes read per second.  
  
2.13.15 WriteBytesPerSecond  
Bytes written per second.  
  
2.13.16 TransfersPerSecond  
Total I/Os per second.  
  
2.13.17 ReadsPerSecond  
Read I/Os per second.  
  
2.13.18 WritesPerSecond  
Write I/Os per second.  
  
2.13.19 AverageTransferTime  
Average time of transfer in seconds.  
  
2.13.20 AverageDiskQueueLength  
Average number of queued read/write requests.  
  
2.14 SCX\_UnixProcessStatisticalInformation  
Each instance of this class provides statiscial information about a Unix
process. The following instance provides statistics for the init
process.  
  
CSCreationClassName = "SCX\_ComputerSystem"  
CSName = "scxcore-suse01.scx.com"  
OSCreationClassName = "SCX\_OperatingSystem"  
OSName = "SuSE Distribution"  
Handle = "1"  
ProcessCreationClassName = "SCX\_UnixProcessStatisticalInformation"  
Name = "init"  
CPUTime = 0  
VirtualText = 499712  
VirtualData = 233472  
VirtualSharedMemory = 40  
CpuTimeDeadChildren = 3170331  
SystemTimeDeadChildren = 1418717  
Caption = "Unix process information"  
Description = "Performance statistics for an individual Unix process"  
PercentUserTime = 0  
PercentPrivilegedTime = 0  
UsedMemory = 64  
PercentUsedMemory = 8  
PagesReadPerSec = 0  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.14.1 Caption  
A human-readable caption for this instance.  
  
2.14.2 Description  
A human-readable description of instance.  
  
2.14.3 BlockReadsPerSecond  
Block reads per second.  
  
2.14.4 BlockWritesPerSecond  
Block writes per second.  
  
2.14.5 BlockTransfersPerSecond  
Block transfers per second.  
  
2.14.6 PercentUserTime  
Percentage of non-idle processor time spent in user mode.  
  
2.14.7 PercentPrivilegedTime  
Percentage of non-idle processor time spent in privileged mode.  
  
2.14.8 UsedMemory  
Used physical memory in kilobytes.  
  
2.14.9 PercentUsedMemory  
Ratio of Resident Set Size to Virtual Memory for process (essentially
percentage of process loaded into memory).  
  
2.14.10 PagesReadPerSec  
Pages read from disk per second to resolve hard page faults.

2.15 SCX\_LanEndpoint

Each instance of this class provides information about an Ethernet
endpoint on this com- puter. Here is an example instance obtained from a
Linux system. This instance represents the eth0 endpoint.

InstanceID=eth0  
Caption=LAN endpoint caption information  
Description=LAN Endpoint description information  
ElementName=eth0 \[Key\]  
Name=eth0 \[Key\]  
SystemCreationClassName=SCX\_ComputerSystem  
\[Key\] SystemName=lab-nx-02.contosolab.com  
\[Key\] CreationClassName=SCX\_LANEndpoint  
MACAddress=00155d84495b  
FormattedMACAddress=00-15-5D-84-49-5B  
  
The following subsections describe the local properties and methods of
this class. See the superclass for a description of inherited
features.  
  
2.15.1 Caption  
A human-readable caption for this instance.

2.15.2 Description  
A human-readable description of instance.

2.15.3 Name  
The name of the LAN endpoint.

2.15.4 MACAddress  
The MAC address of the LAN endpoint.

2.15.5 FormattedMACAddress  
The formatted MAC address of the LAN endpoint.

**3 Configuration Files**

XPlatProviders uses the following two configuration files.  
  
{confdir}/scxlog.conf  
{confdir}/scxrunas.conf  
  
These are discussed in the sections below.  
  
3.1 scxlog.conf  
This configuration file controls the provider logging facility. By
default, all provider logging is directed to {logdir}/log/scx.log. The
default logging threshold is \`WARNING'. The scxlog.conf file can
redirect logging to multiple files and it may control the logging
threshold for those files. For example, consider the following file.  
  
FILE (  
PATH: /opt/xplatproviders/log/log1  
MODULE: WARNING  
MODULE: scx.core.providers TRACE  
)  
FILE (  
PATH: /opt/xplatproviders/log/log2  
MODULE: WARNING  
MODULE: scx.core.common TRACE  
)  
  
This log has two sections. Each section sends logging output to a
specific file. The first section directs log output to
/opt/xplatproviders/log/myfile. TRACE severity log messages are logged
for the logging module called scx.core.providers. For the \`root' module
(everything else), only WARNING severity log messages are logged. Any
section may have multiple module lines.  
  
The logging severities are as follows.  
  
ERROR - The system could not perform the task it was supposed to
perform. Contact support.  
WARNING - Abnormal behavior that could be handled.  
INFORMATION - Information that is useful to someone trying to figure out
the general state of the application. Example: Successful
initialization.  
TRACE - Information that is useful to someone trying to follow general
program execution flow.  
HYSTERICAL - Information that is useful to someone trying to follow very
detailed program execution flow. This level will normally only be used
for finding and fixing bugs and in those cases only for small modules.  
SUPPRESS - It must be possible to suppress messages using a severity
threshold that is higher than any log message can have.  
The logging modules are listed here.  
  
scx  
scx.core  
scx.core.common  
scx.core.common.pal  
scx.core.common.pal.os  
scx.core.common.pal.os.filepath  
scx.core.common.pal.os.filestream  
scx.core.common.pal.system  
scx.core.common.pal.system.common  
scx.core.common.pal.system.common.entityenumeration  
scx.core.common.pal.system.common.entityinstance  
scx.core.common.pal.system.cpu.cpuenumeration  
scx.core.common.pal.system.cpu.cpuinstance  
scx.core.common.util  
scx.core.common.util.math  
scx.core.common.util.stringaid  
scx.core.providers  
scx.core.providers.cpu  
scx.core.providersupport  
scx.core.providersupport.cmpibase  
  
These are arranged in a hierarcy, so specifiying scx.core.providers also
affects the following modules (of which scx.core.providers is a
prefix).  
  
scx.core.providers  
scx.core.providers.cpu  
scx.core.providersupport  
scx.core.providersupport.cmpibase  
  
3.2 scxrunas.conf  
This configuration file controls the execution of the following
extrinsic methods (described above).  
  
SCX\_OperatingSystem.ExecuteCommand()  
SCX\_OperatingSystem.ExecuteShellCommand()  
SCX\_OperatingSystem.ExecuteScript()  
  
The SCX\_OperatingSystem provider runs in its own agent process. The
process owner is the same as the user that initiated the CIM client
request. The three methods above spawn a new process to execute the
command or script. This configuration file controls three options that
affect this new process. The following scxrunas.conf file has the
default settings (the settings used if the file is empty or missing).  
  
AllowRoot=false  
ChRootPath=  
CWD=/opt/xplatproviders/run  
  
The AllowRoot option indicates whether the process may execute as root.
By default it cannot. The ChRootPath, if non-empty, is the path on which
a chroot system call is performed immediately after creating the process
but before executing the command or script. By default ChRootPath is
empty, indicating that no chroot is performed. The CWD option is the
directory that the process executes in. By default it is the same as the
{rundir} configured during installation.
