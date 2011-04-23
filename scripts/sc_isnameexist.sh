#!/bin/bash
usage="Usage: sc_isnameexist.sh type target/module name"
if [ $# -lt 3 ]
then
	echo "${usage}"
	exit
fi

ptype="$1"
pmodule="$2"
pname="$3"
mfile="./source/${pmodule}/list"

cat "${mfile}" | while :
do

	read instr

	e=`echo "${instr}" | grep "#end"`
	if [ "$e" != "" ]
	then
		echo "0"
		break
	fi
	
	a=`echo "${instr}" | grep "${ptype} ${pname}"`
	if [ "$a" != "" ]
	then
		echo "1"
		break
	fi

done

