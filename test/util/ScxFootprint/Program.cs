/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Threading;
using WSManAutomation;

namespace ScxFootprint
{
    class Program
    {
        private static string ip;

        private static string availMem;
        private static string usedMem;
        private static string availSwap;
        private static string usedSwap;

        private static string strAvailMem = "AvailableMemory";
        private static string strUsedMem = "UsedMemory";
        private static string strAvailSwap = "AvailableSwap";
        private static string strUsedSwap = "UsedSwap";

        private static string percentIdleTime;
        private static string percentUserTime;
        private static string percentNiceTime;
        private static string percentPrivilegedTime;
        private static string percentInterruptTime;
        private static string percentDPCTime;
        private static string percentProcessorTime;
        private static string percentIOWaitTime;

        private static string strPercentIdleTime = "PercentIdleTime";
        private static string strPercentUserTime = "PercentUserTime";
        private static string strPercentNiceTime = "PercentNiceTime";
        private static string strPercentPrivilegedTime = "PercentPrivilegedTime";
        private static string strPercentInterruptTime = "PercentInterruptTime";
        private static string strPercentDPCTime = "PercentDPCTime";
        private static string strPercentProcessorTime = "PercentProcessorTime";
        private static string strPercentIOWaitTime = "PercentIOWaitTime";

        static void Main(string[] args)
        {
            string usage =  "Usage: ScxFootprint ipaddress -u:username -p:password";
            string provider1 = "http://schemas.microsoft.com/wbem/wscim/1/cim-schema/2/SCX_MemoryStatisticalInformation?__cimnamespace=root/scx";
            string provider2 = "http://schemas.microsoft.com/wbem/wscim/1/cim-schema/2/SCX_ProcessorStatisticalInformation?__cimnamespace=root/scx";
            string username = "";
            string password = "";

            if (args.Length != 3)
            {
                Console.WriteLine(usage);
                return;
            }
            ip = args[0];

            if (args[1].StartsWith("-u:"))
            {
                username = args[1].Substring(3);
            }
            else if (args[1].StartsWith("-p:"))
            {
                password = args[1].Substring(3);
            }
            else
            {
                Console.WriteLine(usage);
                return;
            }

            if (args[2].StartsWith("-u:"))
            {
                username = args[2].Substring(3);
            }
            else if (args[2].StartsWith("-p:"))
            {
                password = args[2].Substring(3);
            }
            else
            {
                Console.WriteLine(usage);
                return;
            }

            string host = "https://" + ip + ":1270";
            
            WSManClass WSMan = new WSManClass();

            IWSManConnectionOptions options = (IWSManConnectionOptions)WSMan.CreateConnectionOptions();
            options.Password = password;
            options.UserName = username;

            //Explicitly establish Basic Authentication in the call.
            int sessionFlags = WSMan.SessionFlagUseBasic() + WSMan.SessionFlagCredUsernamePassword()
                        + WSMan.SessionFlagSkipCACheck() + WSMan.SessionFlagSkipCNCheck()
                        + WSMan.SessionFlagUTF8();

            int enumFlag = WSMan.EnumerationFlagReturnObject();

            try
            {
                Console.Write("Get footprint information from " + ip + " and write to file.");

                //Create a session.
                IWSManSession session = (IWSManSession)WSMan.CreateSession(host, sessionFlags, options);

                //Construct the URIs to identify the resource.
                IWSManResourceLocator resourceLocator1 = (IWSManResourceLocator)WSMan.CreateResourceLocator(provider1);
                IWSManResourceLocator resourceLocator2 = (IWSManResourceLocator)WSMan.CreateResourceLocator(provider2);

                for (int i = 1; i <= 10; i++)
                {
                    try
                    {
                        //Start an enumeration.
                        IWSManEnumerator enumerator1 = (IWSManEnumerator)session.Enumerate(resourceLocator1, "", "", enumFlag);
                        IWSManEnumerator enumerator2 = (IWSManEnumerator)session.Enumerate(resourceLocator2, "", "", enumFlag);

                        while (!enumerator1.AtEndOfStream)
                        {
                            string reply = enumerator1.ReadItem();
                            SetMemoryData(reply);
                        }
                        while (!enumerator2.AtEndOfStream)
                        {
                            string reply = enumerator2.ReadItem();
                            SetProcessorData(reply);
                        }
                        //Console.Write(".");
                        WriteResult();
                    }
                    catch (System.Runtime.InteropServices.COMException e)
                    {
                        Console.WriteLine("The Enumeration failed:");
                        Console.WriteLine("e: " + e.Message);
                        Console.WriteLine("WSMan: " + WSMan.Error);
                    }
                    Thread.Sleep(60000); // wait a minute more
                }
            }
            catch (System.Runtime.InteropServices.COMException e)
            {
                Console.WriteLine("Create WSMan Session failed:");
                Console.WriteLine("e: " + e.Message);
                Console.WriteLine("WSMan: " + WSMan.Error);
            }
        }

        private static void WriteResult()
        {
            try
            {
                using (StreamWriter sw = new StreamWriter("Footprint" + ip + ".csv"))
                {
                    // Add some text to the file.
                    sw.WriteLine("Memory");

                    sw.WriteLine(strAvailMem);
                    sw.WriteLine(strUsedMem);
                    sw.WriteLine(strAvailSwap);
                    sw.WriteLine(strUsedSwap);
                    sw.WriteLine("");

                    sw.WriteLine("Processor");
                    sw.WriteLine(strPercentIdleTime);
                    sw.WriteLine(strPercentUserTime);
                    sw.WriteLine(strPercentNiceTime);
                    sw.WriteLine(strPercentPrivilegedTime);
                    sw.WriteLine(strPercentInterruptTime);
                    sw.WriteLine(strPercentDPCTime);
                    sw.WriteLine(strPercentProcessorTime);
                    sw.WriteLine(strPercentIOWaitTime);
                }
            }
            catch (Exception e)
            {
                // Let the user know what went wrong.
                Console.WriteLine("Write result failed:");
                Console.WriteLine(e.Message);
            }
        }

        private static string GetElement(string element, string stringData)
        {
            string startTag = "<p:" + element + ">";
            string endTag = "</p:" + element + ">";

            if (!stringData.Contains(startTag))
                return "0";

            int start = stringData.IndexOf(startTag);
                start = start + startTag.Length;
            int end = stringData.IndexOf(endTag);
            int length = end - start;

            string result = stringData.Substring(start, length);
            return result;
        }

        private static void SetProcessorData(string reply)
        {
            string name = GetElement("Name", reply);

            if (name.Contains("Total"))
            {
                percentIdleTime = GetElement("PercentIdleTime", reply);
                percentUserTime = GetElement("PercentUserTime", reply);
                percentNiceTime = GetElement("PercentNiceTime", reply);
                percentPrivilegedTime = GetElement("PercentPrivilegedTime", reply);
                percentInterruptTime = GetElement("PercentInterruptTime", reply);
                percentDPCTime = GetElement("PercentDPCTime", reply);
                percentProcessorTime = GetElement("PercentProcessorTime", reply);
                percentIOWaitTime = GetElement("PercentIOWaitTime", reply);

                strPercentIdleTime = strPercentIdleTime + ";" + percentIdleTime;
                strPercentUserTime = strPercentUserTime + ";" + percentUserTime;
                strPercentNiceTime = strPercentNiceTime + ";" + percentNiceTime;
                strPercentPrivilegedTime = strPercentPrivilegedTime + ";" + percentPrivilegedTime;
                strPercentInterruptTime = strPercentInterruptTime + ";" + percentInterruptTime;
                strPercentDPCTime = strPercentDPCTime + ";" + percentDPCTime;
                strPercentProcessorTime = strPercentProcessorTime + ";" + percentProcessorTime;
                strPercentIOWaitTime = strPercentIOWaitTime + ";" + percentIOWaitTime;
            }
        }

        private static void SetMemoryData(string reply)
        {
            availMem = GetElement("AvailableMemory", reply);
            usedMem = GetElement("UsedMemory", reply);
            availSwap = GetElement("AvailableSwap", reply);
            usedSwap = GetElement("UsedSwap", reply);

            strAvailMem = strAvailMem + ";" + availMem;
            strUsedMem = strUsedMem + ";" + usedMem;
            strAvailSwap = strAvailSwap + ";" + availSwap;
            strUsedSwap = strUsedSwap + ";" + usedSwap;
        }
    }
}

