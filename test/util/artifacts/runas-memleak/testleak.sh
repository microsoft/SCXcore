#! /bin/bash

# Note: /bin/bash is required for mathmatical computions in workflow below.

Provide_Load()
{
    # Run the RunAs provider 1000 times, printing a "." after 25 iterations
    # (We want to give some indication we're running, but not flood the screen)

    I=0
    while [ $I -lt 1000 ]; do
        R=$(($I % 25))
        [ $R -eq 0 ] && echo -n "."
        /opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteShellCommand { command "$FULLPATH" timeout 0 } > /dev/null
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

# Don't allow errors to be ignored
set -e

echo "Invoking RunAs provider (to insure it's running) ..."
/opt/omi/bin/omicli iv root/scx { SCX_OperatingSystem } ExecuteShellCommand { command "echo Hello World" timeout 0 }

echo
echo "Starting values for omiagent process:"
$FULLPATH

echo
echo "Will now exercise RunAs provider under load:"
Provide_Load

echo
echo "Intermediate values for RunAs provider:"
$FULLPATH

echo
echo "Will exercise RunAs provider again under load:"
Provide_Load

echo
echo "Current values for RunAs provider:"
$FULLPATH

echo
echo "Note: These values should be very close to intermediate values!"
echo "      If they are not very close, this must be investigated."

exit 0
