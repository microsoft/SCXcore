import sys
import os

def Get_sh_path(PF):
    if PF == "SunOS" or PF == "HPUX":
        return '#!/usr/bin/sh'
    else:
        return '#!/bin/sh'

def GenerateSetupScriptFile():
    shfile = open(os.path.join(outputDir, 'scx_setup.sh'), 'w')
    shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n')
    # Configure script to not complain if environment variable isn't currently set
    shfile.write('set +u\n')
    if Variables["PF"] == 'MacOS':
        shfile.write('PATH=/usr/libexec/microsoft/scx/bin:$PATH' + '\n')
    else:
        shfile.write('PATH=/opt/microsoft/scx/bin:$PATH' + '\n')
    shfile.write('export PATH' + '\n')
    if Variables["PF"] == 'MacOS':
        shfile.write('DYLD_LIBRARY_PATH=/usr/libexec/microsoft/scx/lib:$DYLD_LIBRARY_PATH' + '\n')
        shfile.write('export DYLD_LIBRARY_PATH' + '\n')
    elif Variables["PF"] == 'HPUX' and Variables["PFARCH"] == "pa-risc":
        shfile.write('SHLIB_PATH=/opt/microsoft/scx/lib:$SHLIB_PATH' + '\n')
        shfile.write('export SHLIB_PATH' + '\n')
    elif Variables["PF"] == "SunOS" and Variables["PFMAJOR"] == 5 and Variables["PFMINOR"] <= 9:
        shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:/usr/local/ssl/lib:/usr/local/lib:$LD_LIBRARY_PATH' + '\n')
        shfile.write('export LD_LIBRARY_PATH' + '\n')
    elif Variables["PF"] == "AIX":
        shfile.write('LIBPATH=/opt/microsoft/scx/lib:$LIBPATH\n')
        shfile.write('export LIBPATH\n')
        # Since AIX searches LIBPATH first, it is questionable whether we need to define LD_LIBRARY_PATH also, but 
        # in the interests of avoiding side effects of code that looks for it, we will set it here.
        shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH\n')
        shfile.write('export LD_LIBRARY_PATH\n')
    else:
        shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH\n')
        shfile.write('export LD_LIBRARY_PATH' + '\n')
    if Variables["BT"] == 'Bullseye':
        shfile.write('COVFILE=/var/opt/microsoft/scx/log/OpsMgr.cov' + '\n')
        shfile.write('export COVFILE' + '\n')
    shfile.close()

def GenerateToolsSetupScriptFile():
    shfile = open(os.path.join(outputDir, 'scx_setup_tools.sh'), 'w')
    shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n')
    # Configure script to not complain if environment variable isn't currently set
    shfile.write('set +u\n')
    if Variables["PF"] == 'MacOS':
        shfile.write('PATH=/usr/libexec/microsoft/scx/bin/tools:$PATH' + '\n')
    else:
        shfile.write('PATH=/opt/microsoft/scx/bin/tools:$PATH' + '\n')
    shfile.write('export PATH' + '\n')
    if Variables["PF"] == 'MacOS':
        shfile.write('DYLD_LIBRARY_PATH=/usr/libexec/microsoft/scx/lib:$DYLD_LIBRARY_PATH' + '\n')
        shfile.write('export DYLD_LIBRARY_PATH' + '\n')
    elif Variables["PF"] == 'HPUX' and Variables["PFARCH"] == "pa-risc":
        shfile.write('SHLIB_PATH=/opt/microsoft/scx/lib:$SHLIB_PATH' + '\n')
        shfile.write('export SHLIB_PATH' + '\n')
    elif Variables["PF"] == "SunOS" and Variables["PFMAJOR"] == 5 and Variables["PFMINOR"] <= 9:
        shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:/usr/local/ssl/lib:/usr/local/lib:$LD_LIBRARY_PATH' + '\n')
        shfile.write('export LD_LIBRARY_PATH' + '\n')
    elif Variables["PF"] == 'AIX':
        shfile.write('LIBPATH=/opt/microsoft/scx/lib:$LIBPATH\n')
        shfile.write('export LIBPATH' + '\n')
        # Since AIX searches LIBPATH first, it is questionable whether we need to define LD_LIBRARY_PATH also, but 
        # in the interests of avoiding side effects of code that looks for it, we will set it here.
        shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH\n')
        shfile.write('export LD_LIBRARY_PATH\n')
    else:
        shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH' + '\n')
        shfile.write('export LD_LIBRARY_PATH' + '\n')
    if Variables["BT"] == 'Bullseye':
        shfile.write('COVFILE=/var/opt/microsoft/scx/log/OpsMgr.cov' + '\n')
        shfile.write('export COVFILE' + '\n')
    shfile.close()

def GenerateAdminToolScriptFile():
    shfile = open(os.path.join(outputDir, 'scxadmin.sh'), 'w')
    shfile.write( Get_sh_path(Variables["PF"]) )
    shfile.write( '\n\n' );
    shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n\n')

    if Variables["PF"] == 'MacOS':
        scxpath = "/usr/libexec"
    else:
        scxpath = "/opt"

    shfile.write('. ' + scxpath + '/microsoft/scx/bin/tools/setup.sh\n')
    shfile.write('exec ' + scxpath + '/microsoft/scx/bin/tools/.scxadmin "$@"\n')
    shfile.close()

def GenerateSSLToolScriptFile():
    shfile = open(os.path.join(outputDir, 'scxsslconfig.sh'), 'w')
    shfile.write( Get_sh_path(Variables["PF"]) );
    shfile.write( '\n\n' );
    shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n\n')

    if Variables["PF"] == 'MacOS':
        scxpath = "/usr/libexec"
    else:
        scxpath = "/opt"

    shfile.write('. ' + scxpath + '/microsoft/scx/bin/tools/setup.sh\n')
    shfile.write('exec ' + scxpath + '/microsoft/scx/bin/tools/.scxsslconfig "$@"\n')
    shfile.close()

def GenerateScripts():
    GenerateSetupScriptFile()
    GenerateToolsSetupScriptFile()
    GenerateAdminToolScriptFile()
    GenerateSSLToolScriptFile()


Variables = dict()

# Parse command line arguments
args = []
optlist = []
for arg in sys.argv[1:]:
    if len(arg) < 2:
        # Must be a file
        args.append(arg)
        continue
    
    if arg[0:2] == "--":
        tokens = arg[2:].split("=",1)
        if len(tokens) == 1:
            tokens.append("")
        Variables[tokens[0]] = tokens[1]
    else:
        args.append(arg)

outputDir = Variables["OUTPUT_DIR"]

GenerateScripts()
