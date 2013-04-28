/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifndef WIN32
#include <pthread.h>
#include <syslog.h>
#include <stdlib.h>
#include <ulimit.h>
#else
#include <windows.h>
#endif

#include "memdata.h"
#include "diskdata.h"

#ifdef WIN32
#define LOG_ERR 3
#endif

using namespace std;

const unsigned int defaultdiskfillpercent = 60;
const unsigned int defaultmemfillpercent = 96;
const string bigfilename = "bigfile.txt";
//Network load Parameters
const string NWFileSendPath = "/tmp/scx*";
const string NWFileRcvPath = "/tmp/junk";
string NWCompName;
unsigned int Nwmode;

const string defaultsyslogmessage = "Test Message";
int disk_fill_files=0;
void DoStopSyslog();
void DoStopPegasus();
void DoLoadCPU();
void DoLoadNetwork();
void DoLoadMemory();
void DoFillDisk();
void DoWriteToSyslog();

struct TestConfig
{
    bool StopSyslog;
    bool StopPegasus;
    bool LoadCPU;
    bool LoadNetwork;
    bool LoadMemory;
    bool FillDisk;
    bool WriteSyslog;
    unsigned int SyslogLevel;
    unsigned int NWLoadMode;
    string SyslogMessage;
    string CompName;
    unsigned int Seconds;
    unsigned int FillPercent;
    unsigned int Threads;
};

struct MenuItem
{
    string name;
    void (*function)();
};

const MenuItem mainmenu[] = { 
    { "Stop syslog", DoStopSyslog },
    { "Stop Pegasus", DoStopPegasus },
    { "Load CPU", DoLoadCPU },
    { "Load Memory", DoLoadMemory },
    { "Fill Disk", DoFillDisk },
    { "Write to syslog", DoWriteToSyslog },
    { "Load Network", DoLoadNetwork },
    { "", NULL }
    };

#ifdef WIN32
const string syslogstopcmd = "echo Execute Stop syslog";
const string pegasusstopcmd = "echo Execute Stop Pegasus";
const string deletefilecommand = "del ";
#else
const string syslogstopcmd = "/etc/init.d/syslog stop";
const string pegasusstopcmd = "/etc/init.d/scx-cimd stop";
const string deletefilecommand = "rm -f ";
#endif

void WaitForEnter(string txt="continue")
{
    char tmp[32];

    cout << endl << "Press ENTER to " << txt;
    cin.getline(tmp, 31);
}

void WaitForTime(unsigned int seconds)
{
    cout << "Sleeping for " << seconds << " seconds:" << endl;

    for (unsigned int i=0; i<seconds; i++)
    {
#ifdef WIN32
        Sleep(1000);
#else
        sleep(1);
#endif
        cout << ".";
        cout.flush();
    }
    cout << endl;
}

bool MenuChoice(const MenuItem *menu, int &choice)
{
    int count = 0;

    cout << endl;

    while (menu[count].name.length() > 0)
    {
        cout << count+1 << ". " << menu[count].name << endl;
        count++;
    }

    do
    {
        char tmp[256] = "";

        cout << endl << "Select [1-" << count << "] (Just ENTER to quit) ";
        cin.getline(tmp, 255);

        if (tmp[0] == '\0')
        {
            choice = 0;
            return false;
        }
        else
        {
            choice = atoi(tmp);
        }
    } 
    while (choice < 1 || choice > count);

    return true;
}

void ExecuteWriteToSyslog(unsigned int level, string message)
{
#ifndef WIN32

    cout << "Writing to message: '" << message << "' with level: " << level << " to syslog" << endl;

    openlog("MSTest", 0, LOG_USER);
    syslog(level, "%s", message.c_str());
    closelog();

    cout << "Done writing to syslog" << endl;

#endif
}

void DoWriteToSyslog()
{
    ExecuteWriteToSyslog(LOG_ERR, defaultsyslogmessage);
}

void DoStopSyslog()
{
    cout << endl << "Stopping syslog" << endl;
    system(syslogstopcmd.c_str());
}


void DoStopPegasus()
{
    cout << endl << "Stopping Pegasus" << endl;
    system(pegasusstopcmd.c_str());
}

extern "C" void *LoadCPUFunc(void *arg_p)
{
    bool *stopload = (bool*)arg_p;
    int i;
    long wrk = 4711;

    // Simulate some real work
    srandom(wrk);

    do {
        for(i = 0; i < 1000; i++) {
            
            wrk *= random();
            wrk /= 17;
            
        }
    } while (!(*stopload)) ;

    return (void*)wrk;
}

//Fucntion used to create scp for send and receive file in the network
void *LoadNetworkFunc(void *arg_p)
{
    bool *stopload = (bool*)arg_p;
    string SetUpCmd;
    string ExeCmd;
    string CleanUpCmd;
    if(Nwmode==1)
    {
        ExeCmd ="scp -B -r root@";
        ExeCmd +=NWCompName;
        ExeCmd +=":";
        ExeCmd +=NWFileSendPath;
        ExeCmd +=" ";
        ExeCmd +=NWFileRcvPath;
        CleanUpCmd = "rm -rf ";
        CleanUpCmd +=NWFileRcvPath;
    }
    else if(Nwmode==2)
    {
        SetUpCmd ="ssh root@";
        SetUpCmd +=NWCompName;
        SetUpCmd +=" ";
        SetUpCmd +=" 'mkdir ";
        SetUpCmd +=NWFileRcvPath;
        SetUpCmd +="' ";
        ExeCmd ="scp -B -r ";
        ExeCmd +=NWFileSendPath;
        ExeCmd +=" ";
        ExeCmd +="root@";
        ExeCmd +=NWCompName;
        ExeCmd +=":";
        ExeCmd +=NWFileRcvPath;
        CleanUpCmd ="ssh root@";
        CleanUpCmd +=NWCompName;
        CleanUpCmd +=" ";
        CleanUpCmd +="'rm -rf ";
        CleanUpCmd +=NWFileRcvPath;
        CleanUpCmd +=" '";
    }

    #ifdef WIN32
        Sleep(1000);
    #else
        sleep(1);
    #endif
    // Setup the client/server
    system(SetUpCmd.c_str());
    // Start transfer of files through scp
    while(!(*stopload)) 
    {    
        system(ExeCmd.c_str());
    }
    // Cleanup the transferred files
    system(CleanUpCmd.c_str());
    return NULL;
}
void ExecuteLoadCPU(unsigned int seconds, unsigned int threads)
{
    cout << endl << "Loading CPU" << endl;

#ifndef WIN32

    pthread_t* tn = new pthread_t[threads];

    bool stopload = false;

    for (unsigned int i = 0; i < threads; i++) {
        if (pthread_create(&tn[i], NULL, LoadCPUFunc, &stopload) != 0)
        {
        cout << endl << "Failed to create load thread" << endl;
        return;
        }
    }

#endif

    if (seconds == 0)
    {
        WaitForEnter("stop CPU load");
    }
    else
    {
        WaitForTime(seconds);
    }
    
#ifndef WIN32
    
    stopload = true;
    for (unsigned int j = 0; j < threads; j++) {
        pthread_join(tn[j], NULL);
    }
    delete [] tn;    

#endif

    if (seconds == 0)
    {
        WaitForEnter();
    }
}

void DoLoadCPU()
{
    // Note: You can't adjust the number of threads during interactive use.
    ExecuteLoadCPU(0, 1);
}

/* Function to start the network load . Creates thread and interleaves it .
   On user signal stops the thread and cleans up the dump
*/
void ExecuteLoadNetwork(unsigned int seconds,string CompName,unsigned int mode)
{
    if(mode == 1)
        cout << endl << "Loading Incoming Network" << endl;
    else if(mode == 2)
        cout << endl << "Loading Outgoing Network" << endl;

    NWCompName=CompName;
    Nwmode=mode;
    bool stopload = false;

#ifndef WIN32

    pthread_t t1;
    //Create thread to start network file transfer
    if (pthread_create(&t1, NULL, LoadNetworkFunc, &stopload ) != 0)
    {
        cout << endl << "Failed to create load thread" << endl;
    }
    else
    {

#endif

        if (seconds == 0)
        {
            char tmp[32];
            cin.getline(tmp, 31);
            WaitForEnter("stop Network load");
            stopload = true;
        }
        else
        {
            WaitForTime(seconds);
            stopload = true;
        }

#ifndef WIN32

        stopload = true;
        pthread_join(t1, NULL);
    }

#endif
    
    if (seconds == 0)
    {
        WaitForEnter();
    }
}
//Function used to get the parameters from user for network loading
void DoLoadNetwork()
{
    string CompName;
    cout << endl << " Another Temprary Machine with enabled RSA/DSA Certificates "<< endl ;
    cout <<" is required for performing this operation"<< endl ;
    cout << endl << " 1     --> To get help on Installing RSA/DSA Certificate"<< endl ;
            cout << " Enter --> To Continue Loading Network"<< endl ;
    cout << endl << " Enter Your Choice ::" ;
    if(getchar()=='1')
    {
        cout << endl << "................................................................." <<endl;
        cout << "Procedure : "<< endl ;
        cout << "................................................................." <<endl;
        cout << "1. In this instructions, the user name is the same in both machines.     "<< endl ;
        cout << "   Instructions for different user names could differ from these         "<< endl ;
        cout << "   (but see note below!)                                                 "<< endl ;
        cout << "2. The user keys will be stored in ~/.ssh in both machines.              "<< endl ;
        cout << "3. At the client, run 'ssh-keygen -t dsa' to generate a key pair. Accept "<< endl ;
        cout << "   default options by pressing return. Specially, do not enter any       "<< endl ;
        cout << "   passphrase. (Option -d seems to be an alias of -t dsa in some         "<< endl ;
        cout << "   platforms). "<< endl ;
        cout << "4. Change the permissions of the generated .pub file to 600 by commanding"<< endl ;
        cout << "   chmod 600 id_dsa.pub                                                  "<< endl ;
        cout << "5. Copy the public key to the server with"<< endl;                                 
        cout << "   scp id_dsa.pub 'user@server:~/.ssh/authorized_keys'. (Caution: if that"<< endl; 
        cout << "   destination file already exists on the server, copy first to a"<< endl;
        cout << "   different file foo and then append the contents with"<< endl;
        cout << "   cat foo >> authorized_keys executed on the server). "<< endl;
        cout << "6. Done! Verify that now you can connect directly from the client with ssh"<< endl;
        cout << "   user@server without being prompted for a password. "<< endl ;
        cout << "7. If it doesn't work, verify that in the server your home directory, the"<< endl;
        cout << "   .ssh subdirectory, and the authorized_keys file do not have writing"<< endl; 
        cout << "   permissions to others. If they do, they won't be considered to grant"<< endl;
        cout << "   access. You can correct this with something like: "<< endl ;
        cout << "   chmod 755 ~"<< endl ;
        cout << "   chmod 700 ~/.ssh"<< endl ;
        cout << "   chmod 600 ~/.ssh/authorized_keys"<< endl ;
        cout << "8. If it still doesn't work, try changing the authorized_keys file name to"<< endl;
        cout << "   authorized_keys2, or ask your system administrator what file name "<< endl ;
        cout << "   is ssh actually using. "<< endl ;
        cout << "9. If it worked, you can now run SCP in batch mode with the -B option, as"<< endl ;
        cout << "   in scp -B foofile 'user@server:~/foodir/'. "<< endl ;
        cout << endl << "................................................................" <<endl;
        cout << "Notes :"<< endl ;
        cout << "................................................................" <<endl;
        cout << "The name of the server must have been registered in the known_hosts. This"<< endl ; 
        cout << "can be done with a regular (with password) ssh connection, and accepting"<< endl ;
        cout << "the host as known. Then, the host name should be the same as the one"<< endl ; 
        cout << "accepted! If you used user@server first, do not use"<< endl ; 
        cout << "user@server.domain.tk later on! "<< endl ;
        cout << "SSH protocol 2 is assumed in this procedure (it uses dsa keys). If your ssh"<< endl ; 
        cout << "configuration files (at /etc/ssh/) do not establish this as a default, you may"<< endl ; 
        cout << "have to force it with the -2 option of the ssh and scp. Moreover, if the default"<< endl ; 
        cout << "public key is not configured to be 'id_dsa.pub' you can specify what key to use"<< endl ; 
        cout << "for identification with the -i option. "<< endl ;
        cout << "The same procedure worked fine when the username was different in both machines."<< endl ;
        cout << "I simply copied userA's public key at the end of userB's authorized_keys file, "<< endl ; 
        cout << "then I could login from my client as userA with ssh userB@server. "<< endl ;
        cout << "................................................................" <<endl;
   }
    cout << endl << "Enter Machine IP/HostName::";
    cin >> CompName; 
    unsigned int mode;
    cout << endl << "Select Network Load Mode"<< endl ;
    cout << endl << "1-- Load Incoming network"<< endl ;
    cout << endl << "2-- Load Outgoing network"<< endl ;
    cout << endl << "Enter Choice :: ";
    cin >>mode; 
    ExecuteLoadNetwork(0,CompName,mode);
}

void ExecuteLoadMemory(unsigned int seconds, unsigned int fillpercent)
{
    MEMData memdata;

    cout << endl << "Loading Memory" << endl;

    if (memdata.UpdateData() == 0)
    {
        cout << "Total Memory=" << memdata.MEMTotalMB << endl;
        cout << "Used Memory =" << memdata.MEMUsedMB << endl;
        cout << "Used Percent=" << memdata.MEMUsedPercent << endl;

        if (memdata.MEMUsedPercent < fillpercent)
        {
#if defined(aix)
            //Converting the unsigned int to long
            size_t alloc_bytes = (unsigned long)((fillpercent*memdata.MEMTotalMB)/100 - memdata.MEMUsedMB)*1024*1024;
            printf("Allocating %ld bytes \n",alloc_bytes);
            //Setting the Resource Limits
            int limitrc;
            errno=0;
            //Set Soft Data Resource limit
            if (limitrc=ulimit(SET_DATALIM,RLIM_INFINITY)<0)
            {
                if (errno == EPERM)
                {
                    cout<<"Attempting to increase the Data Resource limit without root user authority"<<endl;
                }
                else if(errno == EINVAL)
                {
                    cout<<"Invalid Command Parameter in ulimit()"<<endl;
                }
            }
            else
            {
                cout<<"Successful setting of Data Resource Limit to "<<RLIM_INFINITY<<endl;
            }
              
            //Set Soft Stack Resource limit
            if (limitrc=ulimit(SET_STACKLIM,RLIM_INFINITY)<0)
            {
                 if (errno == EPERM)
                 {
                      cout<<"Attempting to increase the Stack Resource limit without root user authority"<<endl;
                 }
                 else if(errno == EINVAL)
                 {
                      cout<<"Invalid Command Parameter in ulimit()"<<endl;
                 }
            }
            else
            {
                 cout<<"Successful setting of Stack Resource Limit to "<<RLIM_INFINITY<<endl;
            }
#else
            size_t alloc_bytes = ((fillpercent*memdata.MEMTotalMB)/100 - memdata.MEMUsedMB)*1024*1024;
            cout << "Allocating " << alloc_bytes << " bytes" << endl;
#endif
            if (seconds == 0)
            {
                WaitForEnter();
            }
            void *a = malloc(alloc_bytes);
            if (a == NULL)
            {
                cout << "Failed to allocate memory";
            }
            else
            {
                memset(a, 17, alloc_bytes);
                if (memdata.UpdateData() == 0)
                {
                    cout << "Used Percent is now: " << memdata.MEMUsedPercent << endl;
                }
                else
                {
                    cout << endl << "Failed to get Memory data" << endl;
                }
                if (seconds == 0)
                {
                    WaitForEnter("free the memory");
                }
                else
                {
                    WaitForTime(seconds);
                }
                free(a);
                cout << "Memory freed" << endl;
            }
        }
        else
        {
            cout << endl << "Already at least " << fillpercent << "% memory allocated" << endl;
        }

    }
    else
    {
        cout << endl << "Failed to get Memory data" << endl;
    }

    if (seconds == 0)
    {
        WaitForEnter();
    }
}

void ExecuteFillMemory(unsigned int seconds, unsigned int fillpercent)
{
    MEMData memdata;
      
    cout << endl << "Loading Memory using -fm option" << endl;
      
    if (memdata.UpdateData() == 0)
    {
        cout << "Total Memory=" << memdata.MEMTotalMB << endl;
        cout << "Used Memory =" << memdata.MEMUsedMB << endl;
        cout << "Used Percent=" << memdata.MEMUsedPercent << endl;
        
            if (memdata.MEMUsedPercent > fillpercent)
            {
                  cout << endl << "Already at least " << fillpercent << "% memory allocated" << endl;
                  cout <<"exiting Loading Memory -fm option"<<endl;
            }
            else
            {
                  //Temporary variables used for time slicing
                  unsigned int timeslice,remsec,loopcnt;

                  // To Allocate dynamic memory
                  void *a;

                  // time slicing for every 30 seconds
                  timeslice=30;

                  remsec=seconds%timeslice;
                  loopcnt = seconds/timeslice;
                  
                  for(unsigned int i=0;i<=loopcnt;i++)
                  {
                        if (memdata.MEMUsedPercent < fillpercent)
                        {
                              cout << "Memory used % < Target Memory % " << endl;

#if defined(aix)
                              //Converting the unsigned int to long
                              size_t alloc_bytes = (unsigned long)((fillpercent*memdata.MEMTotalMB)/100 - memdata.MEMUsedMB)*1024*1024;
                              printf("Allocating %ld bytes \n",alloc_bytes);
                              //Setting the Resource Limits
                              int limitrc;
                              errno=0;
                              //Set Soft Data Resource limit
                              if (limitrc=ulimit(SET_DATALIM,RLIM_INFINITY)<0)
                              {
                                  if (errno == EPERM)
                                  {
                                      cout<<"Attempting to increase the Data Resource limit without root user authority"<<endl;
                                  }
                                  else if(errno == EINVAL)
                                  {
                                      cout<<"Invalid Command Parameter in ulimit()"<<endl;
                                  }
                              }
                              else
                              {
                                  cout<<"Successful setting of Data Resource Limit to "<<RLIM_INFINITY<<endl;
                              }
                              
                              //Set Soft Stack Resource limit
                              if (limitrc=ulimit(SET_STACKLIM,RLIM_INFINITY)<0)
                              {
                                  if (errno == EPERM)
                                  {
                                      cout<<"Attempting to increase the Stack Resource limit without root user authority"<<endl;
                                  }
                                  else if(errno == EINVAL)
                                  {
                                      cout<<"Invalid Command Parameter in ulimit()"<<endl;
                                  }
                              }
                              else
                              {
                                  cout<<"Successful setting of Stack Resource Limit to "<<RLIM_INFINITY<<endl;
                              }
#else
                              size_t alloc_bytes = ((fillpercent*memdata.MEMTotalMB)/100 - memdata.MEMUsedMB)*1024*1024;
                              cout << "Allocating " << alloc_bytes << " bytes" << endl;
#endif
                              a = malloc(alloc_bytes);
                              if (a == NULL)
                              {
                                    cout << "Failed to allocate memory";
                              }
                              else
                              {
                                    memset(a, 17, alloc_bytes);
                              }
                        }

                        if ( i !=loopcnt)
                        {
                              WaitForTime(timeslice);
                        }
                        else
                        {
                        //Waiting for remaining time in the last timeslice
                              WaitForTime(remsec);
                        }
 
                        // Checking for used memory after the time slice
                        if (memdata.UpdateData() == 0)
                        {
                              cout << "Used Percent is now: " << memdata.MEMUsedPercent << endl;
                        }
                        else
                        {
                              cout << endl << "Failed to get Memory data" << endl;
                        }
                              
                  }
                  if (a != NULL)
                  {     
                        free(a);
                        cout << "Memory freed" << endl;
                  }
            }
     }
    else
    {
        cout << endl << "Failed to get Memory data" << endl;    
    }
 }

void DoLoadMemory()
{
    ExecuteLoadMemory(0, defaultmemfillpercent);
}

int CreateLargeFile(string filename, unsigned int mb_size)
{
    FILE *fileptr;
    char mb_buf[1024*1024+1];
    memset(mb_buf, 'a', 1024*1024);
    mb_buf[1024*1024] = '\0';
    disk_fill_files=0;
    //Open a file and write the buffer data to it
    fileptr = fopen(filename.c_str(), "w");
    if (fileptr== NULL)
    {
        cout << "Failed to open file '" << filename << "' for output" << endl;
        return -1;
    }

    // Split the files for sun machines if the file creating size is more than 2 GiB
    #if defined(sun)
    if(mb_size>2000)
    {
        int mb_chunks=mb_size/2000;
        disk_fill_files=mb_chunks;
        mb_size=mb_size%2000;
        for(unsigned int i=0;i<mb_chunks;i++)
         {
            std::string new_file;
            char temp[100];
            sprintf(temp,"%d",i);
            new_file +=filename;
            new_file +=temp;
            //Create files of 2 GiB each
            CreateLargeFile(new_file, 2000);
         }
    }
    #endif
    //Write the buffer data to the file.
    for (unsigned int i=0; i< mb_size; i++)
    {
        fprintf(fileptr, mb_buf);       
    }

    //Close the file 
    fclose(fileptr);
    return 1;
}

void DeleteLargeFile(string filename,int disk_fill_file)
{
    string command = deletefilecommand + " " + filename + "*";
    system(command.c_str());
    //Delete the files if more than one file is created with same name and different suffix(for sun compiler switch only)
    #if defined(sun)
    if(disk_fill_file>0)
    {
        for(unsigned int i=0;i<disk_fill_file;i++)
         {
            std::string new_file;
            char temp[100];
            sprintf(temp,"%d",i);
            new_file +=filename;
            new_file +=temp;
            DeleteLargeFile(new_file, 0);
         }
    }
    #endif

}

void ExecuteFillDisk(unsigned int seconds, unsigned int fillpercent)
{
    DiskData diskdata;
    vector<DiskInfo> disks;
    string filename;

    cout << endl << "Filling Disk" << endl;
    
    diskdata.GetDiskInfo(disks);

    if (disks.size() > 0)
    {
        cout << "Disk " << disks[0].physical << " mounted on " << disks[0].name << " is " << disks[0].size_kb << "kB large and has " << disks[0].free_kb << "kB free, which means " << disks[0].usage << "% used" << endl;

        filename = disks[0].name;
        if (filename[filename.length()-1] != '/')
        {
            filename += "/";
        }
        filename += bigfilename;

        if (disks[0].usage < fillpercent)
        {
            unsigned int alloc_mb = (unsigned int)(disks[0].free_kb/1024 - (((100-fillpercent)*(disks[0].size_kb/1024))/100));
            cout << "Trying to use up " << alloc_mb << "MB extra on disk " << disks[0].physical << endl;
#ifndef WIN32
            CreateLargeFile(filename, alloc_mb);
#endif
            disks.clear();
            diskdata.GetDiskInfo(disks);
            if (disks.size() > 0)
            {
                cout << "Used Percent is now: " << disks[0].usage << endl;
            }
            else
            {
                cout << endl << "Failed to get disk data" << endl;
            }

            if (seconds == 0)
            {
                WaitForEnter("delete the file");
            }
            else
            {
                WaitForTime(seconds);
            }
#ifndef WIN32
            DeleteLargeFile(filename,disk_fill_files);
#endif
            cout << "File deleted" << endl;
        }
        else
        {
            cout << "Disk " << disks[0].physical << " already at least " << fillpercent << "% used" << endl;
        }
    }
    else
    {
        cout << endl << "No disks found" << endl;
    }
    
    if (seconds == 0)
    {
        WaitForEnter();
    }
}

void DoFillDisk()
{
    ExecuteFillDisk(0, defaultdiskfillpercent);
}

void ShowMenu(const MenuItem *menu)
{
    int choice = 0;

    do
    {
        if (MenuChoice(menu, choice))
        {
            menu[choice-1].function();
        }
    }
    while (choice > 0);
}

void ResetConfig(TestConfig *config)
{
    config->StopSyslog = false;
    config->StopPegasus = false;
    config->LoadCPU = false;
    config->LoadNetwork = false;
    config->LoadMemory = false;
    config->FillDisk = false;
    config->WriteSyslog = false;
    config->SyslogLevel = 0;
    config->SyslogMessage = "";
    config->Seconds = 0;
    config->FillPercent = 0;
    config->Threads = 1;
}

bool ParseArgs(int argc, char *argv[], TestConfig *config)
{
    ResetConfig(config);

    if (argc < 2)
    {
        return false;
    }

    if (strcmp(argv[1], "-ss") == 0)
    {
        config->StopSyslog = true;
        return true;
    }

    if (strcmp(argv[1], "-sp") == 0)
    {
        config->StopPegasus = true;
        return true;
    }

    if (strcmp(argv[1], "-lc") == 0 && argc > 2)
    {
        config->LoadCPU = true;
        config->Seconds = atoi(argv[2]);

        if (argc > 3 && *argv[3] != '-')
        {
            config->Threads = atoi(argv[3]);
        }

        return true;
    }
    if (strcmp(argv[1], "-lni") == 0 && argc > 2)
    {
        config->LoadNetwork = true;
        config->Seconds = atoi(argv[2]);
        if (argc > 3)
        {
            config->CompName = argv[3];
        }
        else
        {
            config->CompName = "scxom-suse16";
        }
        config->NWLoadMode= 1;

        return true;
    }
    if (strcmp(argv[1], "-lno") == 0 && argc > 2)
    {
        config->LoadNetwork = true;
        config->Seconds = atoi(argv[2]);
        if (argc > 3)
        {
            config->CompName = argv[3];
        }
        else
        {
            config->CompName = "scxom-suse16";
        }
        config->NWLoadMode= 2;      
        return true;
    }
    if (strcmp(argv[1], "-sl") == 0)
    {
        config->WriteSyslog = true;
        if (argc > 2)
        {
            config->SyslogLevel = atoi(argv[2]);
            if (argc > 3)
            {
                config->SyslogMessage = argv[3];
            }
            else
            {
                config->SyslogMessage = defaultsyslogmessage;
            }
        }
        else
        {
            config->SyslogLevel = LOG_ERR;
            config->SyslogMessage = defaultsyslogmessage;
        }
        return true;
    }

    if (strcmp(argv[1], "-fm") == 0 && argc > 2)
    {
        config->LoadMemory = true;
        config->Seconds = atoi(argv[2]);
        if (argc > 3)
        {
            config->FillPercent = atoi(argv[3]);
        }
        else
        {
            config->FillPercent = defaultmemfillpercent;
        }
        return true;
    }

    if (strcmp(argv[1], "-fd") == 0 && argc > 2)
    {
        config->FillDisk = true;
        config->Seconds = atoi(argv[2]);
        if (argc > 3)
        {
            config->FillPercent = atoi(argv[3]);
        }
        else
        {
            config->FillPercent = defaultmemfillpercent;
        }
        return true;
    }

    return false;
}

void ExecuteTest(TestConfig *config)
{
    if (config->StopSyslog)
    {
        DoStopSyslog();
    }

    if (config->StopPegasus)
    {
        DoStopPegasus();
    }

    if (config->LoadCPU)
    {
        ExecuteLoadCPU(config->Seconds, config->Threads);
    }
    if (config->LoadNetwork)
    {
        ExecuteLoadNetwork(config->Seconds,config->CompName,config->NWLoadMode);
    }
    if (config->LoadMemory)
    {
        ExecuteFillMemory(config->Seconds, config->FillPercent);
    }

    if (config->FillDisk)
    {
        ExecuteFillDisk(config->Seconds, config->FillPercent);
    }

    if (config->WriteSyslog)
    {
        ExecuteWriteToSyslog(config->SyslogLevel, config->SyslogMessage);
    }
}

void PrintUsage(void)
{
    cout << endl;
    cout << "testapp [-ss|-sp|-lc <seconds> [<threads>] |-fm <seconds> [<percent>]" << endl;
    cout << "        |-fd <seconds> [<percent>]|-sl  [<level> <message>]" << endl;
    cout << "        |-lno <seconds> <File transfer machine name/IP>" << endl;
    cout << "        |-lni <seconds> <File transfer machine name/IP>" << endl;
    cout << endl;
    cout << "    -ss                        - Stop syslog" << endl;
    cout << "    -sp                        - Stop Pegasus" << endl;
    cout << "    -lc <seconds> [<threads>]  - Load CPU to 100% during the number of seconds given" << endl;
    cout << "                                 using the number of threads (default 1)" << endl;
    cout << "    -fm <seconds> [<percent>]  - Fill Memory to given percent (default " << defaultmemfillpercent << "%)" << endl;
    cout << "                                 during the number of seconds given" << endl;
    cout << "    -fd <seconds> [<percent>]  - Fill Disk to given percent (default " << defaultdiskfillpercent << "%)" << endl;
    cout << "                                 during the number of seconds given" << endl;
    cout << "    -sl  [<level> <message>]   - Write to syslog. If no message is given a" << endl;
    cout << "                                 default test message is written" << endl;
    cout << "                                 Level is a number between 0 (EMERG) and 7 (DEBUG)" << endl;
    cout << "                                 Default level is 3 (ERR)" << endl;
    cout << "    -lno <seconds> <Client IP>  -Load Outgoing Network to 100% during the" << endl;
    cout << "                                 number of seconds given" << endl;
    cout << "    -lni <seconds> <Client IP>  -Load incoming Network to 100% during the" << endl;
    cout << "                                  number of seconds given" << endl;
    cout << endl;
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        TestConfig config;
        if (ParseArgs(argc, argv, &config))
        {
            ExecuteTest(&config);
        }
        else
        {
            PrintUsage();
        }
    }
    else
    {
        ShowMenu(mainmenu);
    }

    cout << endl << "Bye!" << endl;

    return 0;
}
