/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */

using System;
using System.Collections.Generic;
using System.Text;

/// This file has been intentionally left without comments (for now).
/// It was not really intended to be checked in but you insisted...
/// Created: 2008-02-27

namespace RunLines
{
    class Program
    {
        static void Usage()
        {
            System.Console.Out.WriteLine("Usage: runlines file [options and/or vars]");
            System.Console.Out.WriteLine(" Options:");
            System.Console.Out.WriteLine("  -i\tIgnore errors and continue execution.");
            System.Console.Out.WriteLine("  -o\tRun file lines only once.");
            System.Console.Out.WriteLine("  -s\tSync with other instances using 'run.txt' file.");
            System.Console.Out.WriteLine("  -v\tVerbose output");
            System.Console.Out.WriteLine("  -vv\tVery verbose output");
            System.Console.Out.WriteLine(" Vars:");
            System.Console.Out.WriteLine("  <name>=<value>\tReplaced in lines (<name> replaced by <value>)");
        }

        static void Main(string[] args)
        {
            bool sync = false;
            bool errIgnore = false;
            bool runOnce = false;
            int verbose = 0;
            Dictionary<string, string> vars = new Dictionary<string,string>();
            bool firstArg = true;
            string file = "";
            foreach (string arg in args)
            {
                if (firstArg)
                {
                    file = arg;
                    firstArg = false;
                }
                else if (arg.Contains("="))
                {
                    char[] sep = { '=' };
                    string[] parts = arg.Split(sep, 2);
                    vars[parts[0]] = parts[1];
                }
                else if (arg == "-i")
                    errIgnore = true;
                else if (arg == "-o")
                    runOnce = true;
                else if (arg == "-s")
                    sync = true;
                else if (arg == "-v")
                    verbose = 1;
                else if (arg == "-vv")
                    verbose = 2;
                else
                {
                    Usage();
                    return;
                }
            }
            if (file.Length == 0)
            {
                Usage();
                return;
            }

            if (sync && !System.IO.File.Exists("run.txt"))
            {
                System.IO.File.WriteAllText("run.txt", "bzzt");
            }

            string[] cmds = GetLines(file);
            if (cmds.Length > 0)
            {
                for (int i=0; i<cmds.Length; ++i)
                {
                    cmds[i] = cmds[i].Trim();
                    foreach (string key in vars.Keys)
                    {
                        cmds[i] = cmds[i].Replace(key, vars[key]);
                    }
                }
                int numOK = 0;
                int numFAIL = 0;
                for (int i = 0; i < cmds.Length; i=runOnce?(i+1):((i+1)%cmds.Length) )
                {
                    if (cmds[i].Length == 0 || cmds[i][0] == '#')
                        continue;

                    if (sync && !System.IO.File.Exists("run.txt"))
                    {
                        if (verbose > 0)
                            System.Console.Out.WriteLine("Sync file (run.txt) does not exist");
                        break;
                    }

                    char[] sep = { ' ' };
                    string[] cmd_parts = cmds[i].Split(sep, 2);
                    System.Diagnostics.Process cmd = null;
                    try
                    {
                        if (verbose > 1)
                            System.Console.Out.WriteLine("Executing (" + (i+1) + "): " + cmds[i]);
                        else if (verbose > 0)
                            System.Console.Out.WriteLine("Executing " + (i + 1));
                        System.Diagnostics.ProcessStartInfo si = new System.Diagnostics.ProcessStartInfo();
                        si.FileName = cmd_parts[0];
                        if (cmd_parts.Length > 1)
                            si.Arguments = cmd_parts[1];
                        si.CreateNoWindow = true;
                        si.UseShellExecute = true;
                        si.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
                        cmd = System.Diagnostics.Process.Start(si);
                        
                        cmd.WaitForExit();
                        if (0 != cmd.ExitCode)
                            throw new Exception("Exit code = " + cmd.ExitCode);
                        System.Console.Out.WriteLine("OK=" + ++numOK + " FAIL=" + numFAIL);
                    }
                    catch (System.Exception e)
                    {
                        System.Console.Out.WriteLine(e.Message);
                        if (sync && System.IO.File.Exists("run.txt"))
                            System.IO.File.Delete("run.txt");
                       
                        System.Console.Out.WriteLine("OK=" + numOK + " FAIL=" + ++numFAIL);
                        if (!errIgnore)
                            break;
                    }
                }
            }
            else
            {
                System.Console.Out.WriteLine("No lines to execute");
            }
        }

        static string[] GetLines(string file)
        {
            try
            {
                return System.IO.File.ReadAllLines(file);
                
            }
            catch (System.IO.FileNotFoundException )
            {
                return new string[0];
            }
        }
        
    }
}
