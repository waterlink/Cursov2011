#!/bin/bash
usage="Usage: sc_ismoduleexist.sh target/module"
if [ $# -lt 1 ]
then
	echo "${usage}"
	exit
fi

mfile="./config/modules"
pmodule="$1"

cat "${mfile}" | while :
do

	read instr

	e=`echo ${instr} | grep "#end"`
	if [ "$e" != "" ] 
	then
		echo "0"
		break
	fi

	a1=`echo "${instr}" | grep "module ${pmodule}"`
	if [ "$a1" != "" ] 
	then
		echo "1"
		break
	fi

done

