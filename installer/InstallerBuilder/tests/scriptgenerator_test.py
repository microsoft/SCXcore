import unittest
import os
import shutil
import re
import sys
sys.path.append('../')
from scriptgenerator import Script

##
# Simple utility class to create scripts
# that automatically delete themselves
# when we are done with them.
#
class SelfDeletingScript(Script):
    def __init__(self, path, configuration):
        Script.__init__(self, path, configuration)

    def __del__(self):
        os.remove(self.path)
        
##
# Class for easy testing of pam.conf file functionality.
# This class will delete the test file when disposed.
#
class PamConfFile:
    def __init__(self, path):
        self.path = path
        out = open(self.path, 'w')
        out.write('# Test PAM configuration\n')

    def __del__(self):
        os.remove(self.path)
        
    def ConfigureService(self, service):
        out = open(self.path, 'a')
        out.write(service + '    auth requisite          what.so.1\n')
        out.write(service + '    auth required           ever.so.1\n')
        out.write(service + '    auth required           i.so.1\n')
        out.write(service + '    auth required           do.so.1\n')
        out.write(service + '    account requisite       not.so.1\n')
        out.write(service + '    account required        care.so.1\n')
        
    def GetConf(self, service):
        conf = []
        regex = re.compile('^[#\s]*' + service)
        content = open(self.path)
        for line in content:
            if regex.match(line):
                conf.append(line.replace(service, ''))
        return conf

##
# Class for easy testing of pam.d directory functionality.
# This class will delete the directory when disposed.
#
class PamConfDir:
    def __init__(self, path):
        self.path = path
        os.mkdir(self.path)

    def __del__(self):
        shutil.rmtree(self.path, 1)

    def ConfigureService(self, service):
        out = open(os.path.join(self.path, service), 'w')
        out.write('#%PAM-1.0\n')
        out.write('auth requisite          what.so.1\n')
        out.write('auth required           ever.so.1\n')
        out.write('auth required           i.so.1\n')
        out.write('auth required           do.so.1\n')
        out.write('account requisite       not.so.1\n')
        out.write('account required        care.so.1\n')
        
    def GetConf(self, service):
        conf = []
        content = open(os.path.join(self.path, service))
        for line in content:
            if line[0] != '#':
                conf.append(line)
        return conf

##
# Tests PAM related functionality of the scriptgenerator.
#
class ScriptGeneratorPAMTestCase(unittest.TestCase):
    def setUp(self):
        self.pamconffile = './pam.conf'
        self.pamconfdir = './pam.d'
        self.configuration = {
            'pf' : 'SunOS',
            'pfminor' : '10' }
            
    def RunScript(self, script):
        os.system('sh ' + script.path)

    def GetPermissions(self, path):
        out = os.popen('ls -l ' + path).read()
        return out.split()[0]

    def GivenAScript(self, filename):
        script = SelfDeletingScript(filename, self.configuration)
        script.variableMap['PAM_CONF_FILE'] = self.pamconffile
        script.variableMap['PAM_CONF_DIR'] = self.pamconfdir
        return script

    def GivenAConfigureScript(self, filename):
        script = self.GivenAScript(filename)
        script.CallFunction(script.ConfigurePAM())
        script.Generate()
        return script
        
    def GivenAnUnconfigureScript(self, filename):
        script = self.GivenAScript(filename)
        script.CallFunction(script.UnconfigurePAM())
        script.Generate()
        return script
        
    def GivenAPamConfFile(self):
        conffile = PamConfFile(self.pamconffile)
        return conffile

    def GivenAPamConfDir(self):
        return PamConfDir(self.pamconfdir)

    def GivenAPamConfFileWithSshd(self):
        conffile = self.GivenAPamConfFile()
        conffile.ConfigureService('sshd')
        return conffile

    def GivenAPamConfFileWithScx(self):
        conffile = self.GivenAPamConfFile()
        conffile.ConfigureService('scx')
        return conffile

    def GivenAPamConfDirWithSshd(self):
        confdir = self.GivenAPamConfDir()
        confdir.ConfigureService('sshd')
        return confdir

    def GivenAPamConfDirWithScx(self):
        confdir = self.GivenAPamConfDir()
        confdir.ConfigureService('scx')
        return confdir

    def testConfigureWhenNoConf(self):
        script = self.GivenAConfigureScript('./script.sh')
        self.RunScript(script)
        self.assert_( not os.path.exists(self.pamconffile) )
    
    def testConfigureWhenNoSSH_file(self):
        pamConfFile = self.GivenAPamConfFile()
        script = self.GivenAConfigureScript('./script.sh')

        self.RunScript(script)

        self.assertEqual(pamConfFile.GetConf('scx'), [
            '    auth requisite          pam_authtok_get.so.1\n',
            '    auth required           pam_dhkeys.so.1\n',
            '    auth required           pam_unix_cred.so.1\n',
            '    auth required           pam_unix_auth.so.1\n',
            '    account requisite       pam_roles.so.1\n',
            '    account required        pam_unix_account.so.1\n'
            ])

    def testConfigureWhenNoSSH_dir(self):
        pamConfDir = self.GivenAPamConfDir()
        script = self.GivenAConfigureScript('./script.sh')

        self.RunScript(script)

        self.assertEqual(pamConfDir.GetConf('scx'), [
            'auth requisite          pam_authtok_get.so.1\n',
            'auth required           pam_dhkeys.so.1\n',
            'auth required           pam_unix_cred.so.1\n',
            'auth required           pam_unix_auth.so.1\n',
            'account requisite       pam_roles.so.1\n',
            'account required        pam_unix_account.so.1\n'
            ])
            
    def testConfigureCopiesSSH_file(self):
        pamConfFile = self.GivenAPamConfFileWithSshd()
        script = self.GivenAConfigureScript('./script.sh')

        self.RunScript(script)

        self.assertEqual(pamConfFile.GetConf('scx'), pamConfFile.GetConf('sshd'))

    def testConfigureCopiesSSH_dir(self):
        pamConfDir = self.GivenAPamConfDirWithSshd()
        script = self.GivenAConfigureScript('./script.sh')

        self.RunScript(script)

        self.assertEqual(pamConfDir.GetConf('scx'), pamConfDir.GetConf('sshd'))

    def testUnconfigureSolarisRemovesDefaultConfig_file(self):
        pamConfFile = self.GivenAPamConfFile()
        script1 = self.GivenAConfigureScript('./script1.sh')
        script2 = self.GivenAnUnconfigureScript('./script2.sh')

        self.RunScript(script1)
        self.RunScript(script2)
        
        self.assertEqual(pamConfFile.GetConf('scx'), [])

    def testUnconfigureSolarisRemovesDefaultConfig_dir(self):
        pamConfDir = self.GivenAPamConfDir()
        script1 = self.GivenAConfigureScript('./script1.sh')
        script2 = self.GivenAnUnconfigureScript('./script2.sh')
        self.RunScript(script1)
        self.RunScript(script2)
        self.assert_( os.path.exists(pamConfDir.path) )
        self.assert_( not os.path.exists(os.path.join(pamConfDir.path, 'scx')) )

    def testUnconfigureSolarisDoesNotRemoveCustomConfig_file(self):
        pamConfFile = self.GivenAPamConfFileWithScx()
        script = self.GivenAnUnconfigureScript('./script.sh')

        scxConfBefore = pamConfFile.GetConf('scx')
        self.RunScript(script)

        self.assertEqual(pamConfFile.GetConf('scx'), scxConfBefore)

    def testUnconfigureSolarisDoesNotRemoveCustomConfig_dir(self):
        pamConfDir = self.GivenAPamConfDir()
        scxconf = open(os.path.join(pamConfDir.path, 'scx'), 'w')
        scxconf.write('# Just a random line\nsomething something\n')
        scxconf.close()
        script = self.GivenAnUnconfigureScript('./script.sh')
        self.RunScript(script)
        self.assert_( os.path.exists(os.path.join(pamConfDir.path, 'scx')) )
        data = open(os.path.join(pamConfDir.path, 'scx')).read()
        self.assertEqual(data, '# Just a random line\nsomething something\n')

    def testUnconfigureNonSolarisDoesRemoveCustomConfig_file(self):
        self.configuration = {
            'pf' : 'HPUX'
            }
        pamConfFile = self.GivenAPamConfFileWithScx()
        script = self.GivenAnUnconfigureScript('./script.sh')

        self.RunScript(script)

        self.assertEqual(pamConfFile.GetConf('scx'), [])
        
    def testUnconfigureNonSolarisDoesRemoveCustomConfig_dir(self):
        self.configuration = {
            'pf' : 'HPUX'
            }
        pamConfDir = self.GivenAPamConfDirWithScx()
        script = self.GivenAnUnconfigureScript('./script.sh')

        self.RunScript(script)

        self.assert_( not os.path.exists(os.path.join(pamConfDir.path, 'scx')) )
        
    def testUnconfigureFilePreservesPermissions(self):
        pamConfFile = self.GivenAPamConfFile()
        os.chmod(self.pamconffile, 0644)
        self.assertEqual(self.GetPermissions(self.pamconffile), '-rw-r--r--')
        
        oldUmask = os.umask(0003)
        script1 = self.GivenAConfigureScript('./script1.sh')
        script2 = self.GivenAnUnconfigureScript('./script2.sh')

        self.RunScript(script1)
        self.RunScript(script2)
        
        os.umask(oldUmask)
        self.assertEqual(self.GetPermissions(self.pamconffile), '-rw-r--r--')

    def testConfigureFilePreservesPermissions(self):
        pamConfFile = self.GivenAPamConfFile()
        os.chmod(self.pamconffile, 0644)
        self.assertEqual(self.GetPermissions(self.pamconffile), '-rw-r--r--')

        oldUmask = os.umask(0003)
        script = self.GivenAConfigureScript('./script1.sh')

        self.RunScript(script)
        
        os.umask(oldUmask)
        self.assertEqual(self.GetPermissions(self.pamconffile), '-rw-r--r--')

##
# Tests service related functionality of the scriptgenerator.
#
class ScriptGeneratorServiceTestCase(unittest.TestCase):

    def GivenUbuntuConfiguration(self):
        return {
            'pf' : 'Linux',
            'pfdistro' : 'UBUNTU',
            'pfmajor' : 6 }

    def GivenSuse9Configuration(self):
        return {
            'pf' : 'Linux',
            'pfdistro' : 'SUSE',
            'pfmajor' : 9 }

    def GivenSuse10Configuration(self):
        return {
            'pf' : 'Linux',
            'pfdistro' : 'SUSE',
            'pfmajor' : 10 }
            
    def testUbuntuRegisterServiceCommand(self):
        configuration = self.GivenUbuntuConfiguration()
        shfunction = Script('.', configuration).ConfigurePegasusService()
        self.assertEqual(shfunction.body, ['update-rc.d scx-cimd defaults'])

    def testUbuntuStartServiceCommand(self):
        configuration = self.GivenUbuntuConfiguration()
        shfunction = Script('.', configuration).StartPegasusService()
        self.assertEqual(shfunction.body, ['invoke-rc.d scx-cimd start'])
        
    def testUbuntuStopServiceCommand(self):
        configuration = self.GivenUbuntuConfiguration()
        shfunction = Script('.', configuration).StopPegasusService()
        self.assertEqual(shfunction.body, ['invoke-rc.d scx-cimd stop'])
        
    def testUbuntuRemoveServiceCommand(self):
        configuration = self.GivenUbuntuConfiguration()
        shfunction = Script('.', configuration).RemovePegasusService()
        self.assertEqual(shfunction.body, ['update-rc.d -f scx-cimd remove'])

    def testSuse9StartServiceCommand(self):
        configuration = self.GivenSuse9Configuration()
        shfunction = Script('.', configuration).StartPegasusService()
        self.assertEqual(shfunction.body, ['/etc/init.d/scx-cimd start'])

    def testSuse10StartServiceCommand(self):
        configuration = self.GivenSuse10Configuration()
        shfunction = Script('.', configuration).StartPegasusService()
        self.assertEqual(shfunction.body, ['service scx-cimd start'])
        
    def testSuse9StopServiceCommand(self):
        configuration = self.GivenSuse9Configuration()
        shfunction = Script('.', configuration).StopPegasusService()
        self.assertEqual(shfunction.body, ['/etc/init.d/scx-cimd stop'])

    def testSuse10StopServiceCommand(self):
        configuration = self.GivenSuse10Configuration()
        shfunction = Script('.', configuration).StopPegasusService()
        self.assertEqual(shfunction.body, ['service scx-cimd stop'])
        