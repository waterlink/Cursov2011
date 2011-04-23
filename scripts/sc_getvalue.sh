#!/bin/bash
usage="Usage: sc_getvalue.sh file var"

if [ $# -lt 2 ]
then
	echo "$usage"
	exit
fi

pfile="$1"
pvar="$2"

cat "$pfile" | while :
do

	read instr

	a3=`echo "$instr" | grep "#end"`
	if [ "$a3" != "" ] 
	then
		break;
	fi

	a1=`echo "$instr" | grep "${pvar}="`
	if [ "$a1" != "" ] 
	then
		echo " $instr " | sed s/"${pvar}="//g
	fi
done


