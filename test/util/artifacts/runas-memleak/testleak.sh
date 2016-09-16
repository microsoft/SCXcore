#! /bin/bash

# Note: /bin/bash is required for mathmatical computions in workflow below.

Provide_ExShell_Load()
{
    # Run the ExecuteShellCommand RunAs provider 350 times, printing a "." after 25 iterations
    # (We want to give some indication we're running, but not flood the screen)

    I=0
    while [ $I -lt 350 ]; do
        R=$(($I % 25))
        [ $R -eq 0 ] && echo -n "."
        /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteShellCommand { command "$FULLPATH" timeout 0 } > /dev/null
        I=$(( $I + 1 ))
    done

    echo
}

Provide_ExScript_Load()
{
    # Run the ExecuteScript RunAs provider 350 times, printing a "." after 25 iterations
    # (We want to give some indication we're running, but not flood the screen)
    #
    # The simple shell script:
    #
    # echo ""
    # echo "Hello"
    # echo "Goodbye"
    #
    # will yield ZWNobyAiIg0KZWNobyAiSGVsbG8iDQplY2hvICJHb29kYnllIg== when converted to Base64. As a result, the following is a simple invocation of the ExecuteScript 


    I=0
    while [ $I -lt 350 ]; do
        R=$(($I % 25))
        [ $R -eq 0 ] && echo -n "."
        /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteScript { Script "ZWNobyAiIg0KZWNobyAiSGVsbG8iDQplY2hvICJHb29kYnllIg==" Arguments "" timeout 0 b64encoded "true" } > /dev/null
        I=$(( $I + 1 ))
    done

    echo
}

Provide_ExCommand_Load()
{
    # Run the ExecuteCommand RunAs provider 350 times, printing a "." after 25 iterations
    # (We want to give some indication we're running, but not flood the screen)

    I=0
    while [ $I -lt 350 ]; do
        R=$(($I % 25))
        [ $R -eq 0 ] && echo -n "."
        /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteCommand { command hostname timeout 0 } > /dev/null
        I=$(( $I + 1 ))
    done

    echo
}

# Find out where we live ...
# Can't use something like 'readlink -e $0' because that doesn't work everywhere

case $0 in
    /*|~*)
        SCRIPT_INDIRECT="`dirname $0`"
        ;;
    *)
        PWD="`pwd`"
        SCRIPT_INDIRECT="`dirname $PWD/$0`"
        ;;
esac

BASEDIR="`(cd \"$SCRIPT_INDIRECT\"; pwd -P)`"
FULLPATH=$BASEDIR/measureleak.sh
ARRAY=( Provide_ExShell_Load Provide_ExScript_Load Provide_ExCommand_Load )

# Don't allow errors to be ignored
set -e

echo "Invoking RunAs provider (to insure it's running) ..."
/opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteShellCommand { command "echo Hello World" timeout 0 }

echo
echo "Starting values for omiagent process:"
$FULLPATH

# First run

for i in "${ARRAY[@]}"
do
   echo
   echo "Will now exercise $i RunAs provider under load:"
   $i

   echo
   echo "Intermediate values for $i RunAs provider:"
   $FULLPATH
done

# Second Run

for i in "${ARRAY[@]}"
do
   echo
   echo "Will exercise $i RunAs provider again under load:"
   $i

   echo
   echo "Current values for $i RunAs provider:"
   $FULLPATH
done

echo
echo "Note: These values should be very close to intermediate values!"
echo "      If they are not very close, this must be investigated."

exit 0
