#!/bin/bash

me=`whoami`
pid=`ps aux |grep omiagent |grep $me |grep -v grep |awk '{print $2}'`
tc=`ps huH p $pid |wc -l`
fdc=`lsof -p $pid |wc -l`
echo "PID $pid"
echo "Thread count $tc"
echo "FD count $fdc"

echo "Memstats:"
ps p $pid o pid,rss,vsz,comm

exit 0
