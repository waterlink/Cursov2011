#!/bin/bash
usage="Usage: sc_isnameexist.sh type target/module name comm"
if [ $# -lt 4 ]
then
	echo "${usage}"
	exit
fi

ptype="$1"
pmodule="$2"
pname="$3"
pcom="$4"
mfile="./source/${pmodule}/list"

rm temp
cat "${mfile}" | while :
do

	read instr

	e=`echo "${instr}" | grep "#end"`
	if [ "$e" != "" ]
	then
		echo "[${ptype} ${pname}] - ${pcom}" >> temp
		echo "${instr}" >> temp
		break
	fi
	
	echo "${instr}" >> temp

done
cp temp "${mfile}"

