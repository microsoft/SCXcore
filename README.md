# SCXcore [![Build Status](https://travis-ci.org/Microsoft/SCXcore.svg?branch=master)](https://travis-ci.org/Microsoft/SCXcore)

SCXcore, started as the [Microsoft Operations Manager][] UNIX/Linux Agent,
is now used in a host of products including
[Microsoft Operations Manager][].
[Microsoft Azure][], and
[Microsoft Operations Management Suite][].

[Microsoft Operations Manager]: https://technet.microsoft.com/library/hh205987.aspx
[Microsoft Azure]: https://azure.microsoft.com
[Microsoft Operations Management Suite]: https://www.microsoft.com/en-us/cloud-platform/operations-management-suite

The SCXcore provides a CIMOM provider, based on [OMI][], to return
logging and statistical information for a UNIX or Linux system. The
SCXcore provider runs on AIX 6.1 and later, HP/UX 11.31 and later,
Solaris 5.10 and later, and most versions of Linux as far back as
RedHat 5.0, SuSE 10.1, and Debian 5.0.

[OMI]: https://github.com/Microsoft/omi

The SCXcore provider provides the following classes (note that
performance measurements were taken on an idle machine, so performance
measurements were of little value):

- [SCX_Agent](#enumeration-of-scx_agent)
- [SCX_Application_Server](#enumeration-of-scx_application_server)
- [SCX_DiskDrive](#enumeration-of-scx_diskdrive)
- [SCX_DiskDriveStatisticalInformation](#enumeration-of-scx_diskdrivestatisticalinformation)
- [SCX_EthernetPortStatistics](#enumeration-of-scx_ethernetportstatistics)
- [SCX_FileSystem](#enumeration-of-scx_filesystem)
- [SCX_FileSystemStatisticalInformation](#enumeration-of-scx_filesystemstatisticalinformation)
- [SCX_IPProtocolEndpoint](#enumeration-of-scx_ipprotocolendpoint)
- [SCX_LANEndpoint](#enumeration-of-scx_lanendpoint)
- [SCX_LogFile](#enumeration-of-scx_logfile)
- [SCX_MemoryStatisticalInformation](#enumeration-of-scx_memorystatisticalinformation)
- [SCX_OperatingSystem](#enumeration-of-scx_operatingsystem)
- [SCX_ProcessorStatisticalInformation](#enumeration-of-scx_processorstatisticalinformation)
- [SCX_RTProcessorStatisticalInformation](#enumeration-of-scx_rtprocessorstatisticalinformation)
- [SCX_UnixProcess](#enumeration-of-scx_unixprocess)
- [SCX_UnixProcess TopResourceConsumers](#topresourceconsumers-provider)
- [SCX_UnixProcessStatisticalInformation](#enumeration-of-scx_unixprocessstatisticalinformation)

RunAs Provider:

- [ExecuteCommand](#runas-provider-executecommand)
- [ExecuteShellCommand](#runas-provider-executeshellcommand)
- [ExecuteScript](#runas-provider-executescript)

-----

The following output shows the results of enumeration of classes:


### Enumeration of SCX_Agent

```
> /opt/omi/bin/omicli ei root/scx SCX_Agent
instance of SCX_Agent
{
    Caption=SCX Agent meta-information
    Description=Release_Build - 20160901
    InstallDate=20160902085021.000000+000
    [Key] Name=scx
    VersionString=1.6.2-416
    MajorVersion=1
    MinorVersion=6
    RevisionNumber=2
    BuildNumber=416
    BuildDate=2016-09-01T00:00:00Z
    Architecture=x64
    OSName=CentOS Linux
    OSType=Linux
    OSVersion=7.0
    KitVersionString=1.6.2-416
    Hostname=jeffcof64-cent7x-01.scx.com
    OSAlias=UniversalR
    UnameArchitecture=x86_64
    MinActiveLogSeverityThreshold=INFO
    MachineType=Virtual
    PhysicalProcessors=1
    LogicalProcessors=2
}
```

### Enumeration of SCX_Application_Server

```
> /opt/omi/bin/omicli ei root/scx SCX_Application_Server
instance of SCX_Application_Server
{
    Caption=SCX Application Server
    Description=Represents a JEE Application Server
    [Key] Name=/root/tomcat/apache-tomcat-7.0.11/
    HttpPort=8080
    HttpsPort=8443
    Port=
    Protocol=
    Version=7.0.11
    MajorVersion=7
    DiskPath=/root/tomcat/apache-tomcat-7.0.11/
    Type=Tomcat
    Profile=
    Cell=
    Node=
    Server=
    IsDeepMonitored=false
    IsRunning=true
}
```

### Enumeration of SCX_DiskDrive

```
> /opt/omi/bin/omicli ei root/scx SCX_DiskDrive
instance of SCX_DiskDrive
{
    Caption=Disk drive information
    Description=Information pertaining to a physical unit of secondary storage
    Name=sda
    [Key] SystemCreationClassName=SCX_ComputerSystem
    [Key] SystemName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_DiskDrive
    [Key] DeviceID=sda
    MaxMediaSize=34359738368
    InterfaceType=SCSI
    Manufacturer=Msft
    Model=Virtual Disk
    TotalCylinders=4177
    TotalHeads=255
    TotalSectors=67108864
}
```

### Enumeration of SCX_DiskDriveStatisticalInformation

```
> /opt/omi/bin/omicli ei root/scx SCX_DiskDriveStatisticalInformation
instance of SCX_DiskDriveStatisticalInformation
{
    Caption=Disk drive information
    Description=Performance statistics related to a physical unit of secondary storage
    [Key] Name=sda
    IsAggregate=false
    IsOnline=true
    BytesPerSecond=0
    ReadBytesPerSecond=0
    WriteBytesPerSecond=0
    TransfersPerSecond=0
    ReadsPerSecond=0
    WritesPerSecond=0
    AverageReadTime=0
    AverageWriteTime=0
    AverageTransferTime=0
    AverageDiskQueueLength=0
}
instance of SCX_DiskDriveStatisticalInformation
{
    Caption=Disk drive information
    Description=Performance statistics related to a physical unit of secondary storage
    [Key] Name=_Total
    IsAggregate=true
    IsOnline=true
    BytesPerSecond=0
    ReadBytesPerSecond=0
    WriteBytesPerSecond=0
    TransfersPerSecond=0
    ReadsPerSecond=0
    WritesPerSecond=0
    AverageReadTime=0
    AverageWriteTime=0
    AverageTransferTime=0
    AverageDiskQueueLength=0
}
```

### Enumeration of SCX_EthernetPortStatistics

```
> /opt/omi/bin/omicli ei root/scx SCX_EthernetPortStatistics
instance of SCX_EthernetPortStatistics
{
    [Key] InstanceID=eth0
    Caption=Ethernet port information
    Description=Statistics on transfer performance for a port
    BytesTransmitted=1779042797
    BytesReceived=10709989843
    PacketsTransmitted=7899737
    PacketsReceived=67705882
    BytesTotal=12489032640
    TotalRxErrors=0
    TotalTxErrors=0
    TotalCollisions=0
}
instance of SCX_EthernetPortStatistics
{
    [Key] InstanceID=virbr0
    Caption=Ethernet port information
    Description=Statistics on transfer performance for a port
    BytesTransmitted=0
    BytesReceived=0
    PacketsTransmitted=0
    PacketsReceived=0
    BytesTotal=0
    TotalRxErrors=0
    TotalTxErrors=0
    TotalCollisions=0
}
```

### Enumeration of SCX_FileSystem

```
> /opt/omi/bin/omicli ei root/scx SCX_FileSystem
instance of SCX_FileSystem
{
    Caption=File system information
    Description=Information about a logical unit of secondary storage
    [Key] Name=/
    [Key] CSCreationClassName=SCX_ComputerSystem
    [Key] CSName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_FileSystem
    Root=/
    BlockSize=4096
    FileSystemSize=31622189056
    AvailableSpace=17586249728
    ReadOnly=false
    EncryptionMethod=Not Encrypted
    CompressionMethod=Not Compressed
    CaseSensitive=true
    CasePreserved=true
    MaxFileNameLength=255
    FileSystemType=xfs
    PersistenceType=2
    NumberOfFiles=322736
    IsOnline=true
    TotalInodes=30896128
    FreeInodes=30573392
}
instance of SCX_FileSystem
{
    Caption=File system information
    Description=Information about a logical unit of secondary storage
    [Key] Name=/boot
    [Key] CSCreationClassName=SCX_ComputerSystem
    [Key] CSName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_FileSystem
    Root=/boot
    BlockSize=4096
    FileSystemSize=517713920
    AvailableSpace=312877056
    ReadOnly=false
    EncryptionMethod=Not Encrypted
    CompressionMethod=Not Compressed
    CaseSensitive=true
    CasePreserved=true
    MaxFileNameLength=255
    FileSystemType=xfs
    PersistenceType=2
    NumberOfFiles=337
    IsOnline=true
    TotalInodes=512000
    FreeInodes=511663
}
```

### Enumeration of SCX_FileSystemStatisticalInformation

```
> /opt/omi/bin/omicli ei root/scx SCX_FileSystemStatisticalInformation
instance of SCX_FileSystemStatisticalInformation
{
    Caption=File system information
    Description=Performance statistics related to a logical unit of secondary storage
    [Key] Name=/
    IsAggregate=false
    IsOnline=true
    FreeMegabytes=16772
    UsedMegabytes=13386
    PercentFreeSpace=56
    PercentUsedSpace=44
    PercentFreeInodes=99
    PercentUsedInodes=1
    BytesPerSecond=0
    ReadBytesPerSecond=0
    WriteBytesPerSecond=0
    TransfersPerSecond=0
    ReadsPerSecond=0
    WritesPerSecond=0
}
instance of SCX_FileSystemStatisticalInformation
{
    Caption=File system information
    Description=Performance statistics related to a logical unit of secondary storage
    [Key] Name=/boot
    IsAggregate=false
    IsOnline=true
    FreeMegabytes=299
    UsedMegabytes=196
    PercentFreeSpace=60
    PercentUsedSpace=40
    PercentFreeInodes=100
    PercentUsedInodes=0
    BytesPerSecond=0
    ReadBytesPerSecond=0
    WriteBytesPerSecond=0
    TransfersPerSecond=0
    ReadsPerSecond=0
    WritesPerSecond=0
}
instance of SCX_FileSystemStatisticalInformation
{
    Caption=File system information
    Description=Performance statistics related to a logical unit of secondary storage
    [Key] Name=_Total
    IsAggregate=true
    IsOnline=true
    FreeMegabytes=17071
    UsedMegabytes=13582
    PercentFreeSpace=56
    PercentUsedSpace=44
    PercentFreeInodes=100
    PercentUsedInodes=0
    BytesPerSecond=0
    ReadBytesPerSecond=0
    WriteBytesPerSecond=0
    TransfersPerSecond=0
    ReadsPerSecond=0
    WritesPerSecond=0
}
```

### Enumeration of SCX_IPProtocolEndpoint

```
> /opt/omi/bin/omicli ei root/scx SCX_IPProtocolEndpoint
instance of SCX_IPProtocolEndpoint
{
    Caption=IP protocol endpoint information
    Description=Properties of an IP protocol connection endpoint
    ElementName=eth0
    [Key] Name=eth0
    EnabledState=2
    [Key] SystemCreationClassName=SCX_ComputerSystem
    [Key] SystemName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_IPProtocolEndpoint
    IPv4Address=157.59.154.35
    SubnetMask=255.255.252.0
    IPv4BroadcastAddress=157.59.155.255
}
instance of SCX_IPProtocolEndpoint
{
    Caption=IP protocol endpoint information
    Description=Properties of an IP protocol connection endpoint
    ElementName=virbr0
    [Key] Name=virbr0
    EnabledState=2
    [Key] SystemCreationClassName=SCX_ComputerSystem
    [Key] SystemName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_IPProtocolEndpoint
    IPv4Address=192.168.122.1
    SubnetMask=255.255.255.0
    IPv4BroadcastAddress=192.168.122.255
}
```

### Enumeration of SCX_LANEndpoint

```
> /opt/omi/bin/omicli ei root/scx SCX_LANEndpoint       
instance of SCX_LANEndpoint
{
    InstanceID=eth0
    Caption=LAN endpoint caption information
    Description=LAN Endpoint description information
    ElementName=eth0
    [Key] Name=eth0
    [Key] SystemCreationClassName=SCX_ComputerSystem
    [Key] SystemName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_LANEndpoint
    MACAddress=00155dae1c00
    FormattedMACAddress=00-15-5D-AE-1C-00
}
instance of SCX_LANEndpoint
{
    InstanceID=virbr0
    Caption=LAN endpoint caption information
    Description=LAN Endpoint description information
    ElementName=virbr0
    [Key] Name=virbr0
    [Key] SystemCreationClassName=SCX_ComputerSystem
    [Key] SystemName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_LANEndpoint
    MACAddress=525400235dce
    FormattedMACAddress=52-54-00-23-5D-CE
}
```

### Enumeration of SCX_LogFile

The LogFile provider uses a marker file to show differences in log
files between enumerations. Thus, the first enumeration returned no
matched rows, but created the marker file. Future enumerations
returned the proper results (log file lines since last enumeration).

```
> /opt/omi/bin/omicli iv root/scx { SCX_LogFile } GetMatchedRows { filename /var/log/cron regexps ".*" qid myQID } 
instance of GetMatchedRows
{
    ReturnValue=0
    rows={}
}

> crontab -l
@reboot         /home/jeffcof/dev/git/updatedns/updatedns.sh
*/15 * * * *    /home/jeffcof/dev/git/updatedns/updatedns.sh
2 0 * * 0       /usr/sbin/logrotate --state /home/jeffcof/dev/git/updatedns/.updatedns.logrotatestate /home/jeffcof/dev/git/updatedns/.updatedns.logrotate

> /opt/omi/bin/omicli iv root/scx { SCX_LogFile } GetMatchedRows { filename /var/log/cron regexps ".*" qid myQID }
instance of GetMatchedRows
{
    ReturnValue=1
    rows={0;Sep  2 09:14:16 jeffcof64-cent7x-01 crontab[2761]: (jeffcof) LIST (jeffcof)}
}
```

### Enumeration of SCX_MemoryStatisticalInformation

```
> /opt/omi/bin/omicli ei root/scx SCx_MemoryStatisticalInformation
instance of SCX_MemoryStatisticalInformation
{
    Caption=Memory information
    Description=Memory usage and performance statistics
    [Key] Name=Memory
    IsAggregate=true
    AvailableMemory=875
    PercentAvailableMemory=64
    UsedMemory=498
    PercentUsedMemory=36
    PercentUsedByCache=0
    PagesPerSec=0
    PagesReadPerSec=0
    PagesWrittenPerSec=0
    AvailableSwap=2038
    PercentAvailableSwap=100
    UsedSwap=9
    PercentUsedSwap=0
}
```

### Enumeration of SCX_OperatingSystem

```
> /opt/omi/bin/omicli ei root/scx SCX_OperatingSystem
instance of SCX_OperatingSystem
{
    Caption=CentOS Linux 7.0 (x86_64)
    Description=CentOS Linux 7.0 (x86_64)
    [Key] Name=Linux Distribution
    EnabledState=5
    RequestedState=12
    EnabledDefault=2
    [Key] CSCreationClassName=SCX_ComputerSystem
    [Key] CSName=jeffcof64-cent7x-01.scx.com
    [Key] CreationClassName=SCX_OperatingSystem
    OSType=36
    OtherTypeDescription=3.10.0-327.18.2.el7.x86_64 #1 SMP Thu May 12 11:03:55 UTC 2016 x86_64   
    Version=7.0
    LastBootUpTime=20160819060426.000000+000
    LocalDateTime=20160902092201.014880+000
    CurrentTimeZone=-420
    NumberOfLicensedUsers=0
    NumberOfUsers=5
    NumberOfProcesses=263
    MaxNumberOfProcesses=5633
    TotalSwapSpaceSize=2097148
    TotalVirtualMemorySize=3503828
    FreeVirtualMemory=2983252
    FreePhysicalMemory=896156
    TotalVisibleMemorySize=1406680
    SizeStoredInPagingFiles=2097148
    FreeSpaceInPagingFiles=2087096
    MaxProcessMemorySize=0
    MaxProcessesPerUser=2816
    OperatingSystemCapability=64 bit
    SystemUpTime=2584608
}
```

### Enumeration of SCX_ProcessorStatisticalInformation

```
> /opt/omi/bin/omicli ei root/scx SCX_ProcessorStatisticalInformation
instance of SCX_ProcessorStatisticalInformation
{
    Caption=Processor information
    Description=CPU usage statistics
    [Key] Name=0
    IsAggregate=false
    PercentIdleTime=0
    PercentUserTime=0
    PercentNiceTime=0
    PercentPrivilegedTime=0
    PercentInterruptTime=0
    PercentDPCTime=0
    PercentProcessorTime=0
    PercentIOWaitTime=0
}
instance of SCX_ProcessorStatisticalInformation
{
    Caption=Processor information
    Description=CPU usage statistics
    [Key] Name=1
    IsAggregate=false
    PercentIdleTime=0
    PercentUserTime=0
    PercentNiceTime=0
    PercentPrivilegedTime=0
    PercentInterruptTime=0
    PercentDPCTime=0
    PercentProcessorTime=0
    PercentIOWaitTime=0
}
instance of SCX_ProcessorStatisticalInformation
{
    Caption=Processor information
    Description=CPU usage statistics
    [Key] Name=_Total
    IsAggregate=true
    PercentIdleTime=0
    PercentUserTime=0
    PercentNiceTime=0
    PercentPrivilegedTime=0
    PercentInterruptTime=0
    PercentDPCTime=0
    PercentProcessorTime=0
    PercentIOWaitTime=0
}
```

### Enumeration of SCX_RTProcessorStatisticalInformation

```
> /opt/omi/bin/omicli ei root/scx SCX_RTProcessorStatisticalInformation
instance of SCX_RTProcessorStatisticalInformation
{
    Caption=Processor information
    Description=CPU usage statistics
    [Key] Name=0
    IsAggregate=false
    PercentIdleTime=0
    PercentUserTime=0
    PercentNiceTime=0
    PercentPrivilegedTime=0
    PercentInterruptTime=0
    PercentDPCTime=0
    PercentProcessorTime=0
    PercentIOWaitTime=0
}
instance of SCX_RTProcessorStatisticalInformation
{
    Caption=Processor information
    Description=CPU usage statistics
    [Key] Name=1
    IsAggregate=false
    PercentIdleTime=0
    PercentUserTime=0
    PercentNiceTime=0
    PercentPrivilegedTime=0
    PercentInterruptTime=0
    PercentDPCTime=0
    PercentProcessorTime=0
    PercentIOWaitTime=0
}
instance of SCX_RTProcessorStatisticalInformation
{
    Caption=Processor information
    Description=CPU usage statistics
    [Key] Name=_Total
    IsAggregate=true
    PercentIdleTime=0
    PercentUserTime=0
    PercentNiceTime=0
    PercentPrivilegedTime=0
    PercentInterruptTime=0
    PercentDPCTime=0
    PercentProcessorTime=0
    PercentIOWaitTime=0
}
```

### Enumeration of SCX_UnixProcess

Rather than enumerating all processes on the system (with **ei**
option to omicli), this will enumerate one single process for brevity:

```
> /opt/omi/bin/omicli gi root/scx { SCX_UnixProcess CSCreationClassName SCX_ComputerSystem CSName jeffcof64-cent7x-01.scx.com OSCreationClassName SCX_OperatingSystem OSName "Linux Distribution" CreationClassName SCX_UnixProcess Handle 1 }      
instance of SCX_UnixProcess
{
    Caption=Unix process information
    Description=A snapshot of a current process
    Name=systemd
    [Key] CSCreationClassName=SCX_ComputerSystem
    [Key] CSName=jeffcof64-cent7x-01.scx.com
    [Key] OSCreationClassName=SCX_OperatingSystem
    [Key] OSName=Linux Distribution
    [Key] CreationClassName=SCX_UnixProcess
    [Key] Handle=1
    Priority=7
    ExecutionState=6
    CreationDate=20160803112512.566494+000
    KernelModeTime=332600
    UserModeTime=376000
    ParentProcessID=0
    RealUserID=0
    ProcessGroupID=1
    ProcessSessionID=1
    ModulePath=/usr/lib/systemd/systemd
    Parameters={/usr/lib/systemd/systemd, --switched-root, --system, --deserialize, 21}
    ProcessNiceValue=20
    ProcessWaitingForEvent=ep_poll
    PercentBusyTime=0
    UsedMemory=9196
}
```

### TopResourceConsumers Provider

The TopResourceConsumers provider (part of SCX_UnixProcess provider)
will show the top resource consumers for any of:

- CPUTime
- BlockReadsPerSecond
- BlockWritesPerSecond
- BlockTransfersPerSecond
- PercentUserTime
- PercentPrivilegedTime
- UsedMemory
- PercentUsedMemory
- PagesReadPerSec

Since the test system didn't have any CPU load, CPUTime is of little
value:

```
> /opt/omi/bin/omicli iv root/scx { SCX_UnixProcess } TopResourceConsumers { resource "CPUTime" count 5 } 
instance of TopResourceConsumers
{
    ReturnValue=
PID   Name                 CPUTime
-------------------------------------------------------------
 1702 master                        0
 1717 qmgr                          0
 1902 dnsmasq                       0
 1903 dnsmasq                       0
 2204 tfprox                        0

}
```

However, UsedMemory is somewhat more useful:

```
> /opt/omi/bin/omicli iv root/scx { SCX_UnixProcess } TopResourceConsumers { resource "UsedMemory" count 5 }       
instance of TopResourceConsumers
{
    ReturnValue=
PID   Name                 UsedMemory
-------------------------------------------------------------
21951 emacs                     50464
18376 dhclient                  15792
 1069 tuned                     13052
  857 polkitd                   10984
 1073 libvirtd                   9864

}
```

### Enumeration of SCX_UnixProcessStatisticalInformation

Rather than enumerating all processes on the system (with **ei**
option to omicli), this will enumerate one single process for brevity:

```
> /opt/omi/bin/omicli gi root/scx { SCX_UnixProcessStatisticalInformation name systemd CSCreationClassName SCX_ComputerSystem CSName jeffcof64-cent7x-01.scx.com OSCreationClassName SCX_OperatingSystem OSName "Linux Distribution" ProcessCreationClassName SCX_UnixProcessStatisticalInformation Handle 1 }
instance of SCX_UnixProcessStatisticalInformation
{
    Caption=Unix process information
    Description=A snapshot of a current process
    [Key] Name=systemd
    [Key] CSCreationClassName=SCX_ComputerSystem
    [Key] CSName=jeffcof64-cent7x-01.scx.com
    [Key] OSCreationClassName=SCX_OperatingSystem
    [Key] OSName=Linux Distribution
    [Key] Handle=1
    [Key] ProcessCreationClassName=SCX_UnixProcessStatisticalInformation
    CPUTime=0
    VirtualText=1335296
    VirtualData=6676480
    VirtualSharedMemory=3216
    CpuTimeDeadChildren=142223
    SystemTimeDeadChildren=47871
    PercentUserTime=0
    PercentPrivilegedTime=0
    UsedMemory=9196
    PercentUsedMemory=19
    PagesReadPerSec=0
}
```

### RunAs Provider: ExecuteCommand

The `ExecuteComand` RunAs provider will execute any UNIX/Linux native
command:

```
> /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteCommand { command /bin/true timeout 0 }
instance of ExecuteCommand
{
    ReturnValue=true
    ReturnCode=0
    StdOut=
    StdErr=
}

> /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteCommand { command /bin/false timeout 0 }    
instance of ExecuteCommand
{
    ReturnValue=false
    ReturnCode=1
    StdOut=
    StdErr=
}
```

### RunAs Provider: ExecuteShellCommand

The `ExecuteShellCommand` RunAs provider will execute any UNIX/Linux
command using the /bin/sh shell:

```
> /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteShellCommand { command 'echo Hello World' timeout 0 }  
instance of ExecuteShellCommand
{
    ReturnValue=true
    ReturnCode=0
    StdOut=Hello World

    StdErr=
}
```

### RunAs Provider: ExecuteScript

The `ExecuteScript` RunAs provider will execute any UNIX/Linux script
using the /bin/sh shell.

Unfortunately, it is difficult to get a multi-line shell script
entered via the omicli test program (rather than the OMI
API). Fortunately, the `ExecuteScript` provider allows for scripts to
be passed via [Base64][] encoding.

The simple shell script:

```
echo ""
echo "Hello"
echo "Goodbye"
```

will yield `ZWNobyAiIg0KZWNobyAiSGVsbG8iDQplY2hvICJHb29kYnllIg==` when
converted to [Base64][]. As a result, the following is a simple invocation
of the `ExecuteScript` RunAs provider:

```
> /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteScript { Script "ZWNobyAiIg0KZWNobyAiSGVsbG8iDQplY2hvICJHb29kYnllIg==" Arguments "" timeout 0 b64encoded "true" }
instance of ExecuteScript
{
    ReturnValue=true
    ReturnCode=0
    StdOut=
Hello
Goodbye

    StdErr=
}
```

[Base64]: https://en.wikipedia.org/wiki/Base64

## Code of Conduct

This project has adopted the [Microsoft Open Source Code of Conduct]
(https://opensource.microsoft.com/codeofconduct/).  For more
information see the [Code of Conduct FAQ]
(https://opensource.microsoft.com/codeofconduct/faq/) or contact
[opencode@microsoft.com](mailto:opencode@microsoft.com) with any
additional questions or comments.
