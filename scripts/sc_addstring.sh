#!/bin/bash
usage="Usage: sc_addstring.sh file string"
if [ $# -lt 2 ]
then
	echo "${usage}"
	exit
fi

mfile="$1"
mstr="$2"

rm temp
cat "${mfile}" | while :
do

	read instr

	e=`echo "${instr}" | grep "#end"`
	if [ "$e" != "" ]
	then
		echo "${mstr}" >> temp
		echo "${instr}" >> temp
		break
	fi
	
	echo "${instr}" >> temp

done
cp temp "${mfile}"

