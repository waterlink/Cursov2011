#!/bin/bash
usage="Usage: sc_addmodule.sh target/module comm"
if [ $# -lt 2 ]
then
	echo "${usage}"
	exit
fi

mfile="./config/modules"
pmodule="$1"
pcom="$2"

rm temp
cat "${mfile}" | while :
do

	read instr

	e=`echo ${instr} | grep "#end"`
	if [ "$e" != "" ] 
	then
		echo "[module ${pmodule}] - ${pcom}" >> temp
		echo ${instr} >> temp
		break
	fi

	echo ${instr} >> temp

done
cp temp "${mfile}"

