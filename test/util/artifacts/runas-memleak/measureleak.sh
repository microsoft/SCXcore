#!/bin/bash 

os=`uname`
case $os in
'AIX')
	me=`whoami`
	pid=`ps -ef |grep omiagent |grep $me |grep -v grep |awk '{print $2}'`
	tc=`ps -o thcount -p $pid | grep -v THCNT`
	fdc=`lsof -p $pid |wc -l`
	echo "PID $pid"
	echo "Thread count $tc"
	echo "FD count $fdc"

	echo "Memstats:"
	ps u $pid
	;;
'HP-UX')
	me=`whoami`
	pid=`ps -ef |grep omiagent |grep $me |grep -v grep |awk '{print $2}'`
	fdc=`lsof -p $pid |wc -l`
	echo "PID $pid"
	echo "Thread count N/A"
	echo "FD count $fdc"

	echo "Memstats:"
	UNIX95= ps -C omiagent -o pid,sz,vsz,comm
	;;
'Linux')
	me=`whoami`
	pid=`ps aux |grep omiagent |grep $me |grep -v grep |awk '{print $2}'`
	tc=`ps huH p $pid | wc -l`
	fdc=`lsof -p $pid |wc -l`
	echo "PID $pid"
	echo "Thread count $tc"
	echo "FD count $fdc"

	echo "Memstats:"
	ps p $pid o pid,rss,vsz,comm
	;;
'SunOS')
	me=`/opt/sfw/bin/whoami`
	pid=`ps -ef |grep omiagent |grep $me |grep -v grep |awk '{print $2}'`
	tc=`ps -eLf  | grep omiagent | grep -v grep | wc -l`
	fdc=`lsof -p $pid |wc -l`
	echo "PID $pid"
	echo "Thread count $tc"
	echo "FD count $fdc"

	echo "Memstats:"
	ps -p $pid -o pid,rss,vsz,comm
	;;
*)
	echo "Unsupported OS"
	exit 1
	;;
esac

exit 0
