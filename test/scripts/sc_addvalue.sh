#!/bin/bash
if [ $# -lt 3 ]
then 
	echo "Usage: sc_addvalue file var value"
	exit
fi
echo "sc_addvalue ${1} ${2} ${3}:"
counter=-1
tabul=""
rm temp
cat "$1" | while :
do
	read instr
	a1=`echo "$instr" | grep "${2}="`
	a2=`echo "$instr"`
	a3=`echo "$instr" | grep "#end"`
	a4=`echo "$instr" | grep "#tab"`
	if [ "$a4" != "" ]
	then
		counter=3
	fi
	if [ "$counter" != "-1" ]
	then
		counter=$((counter - 1))
	fi
	if [ "${counter}" == "0" ]
	then
		tabul="	"	#tabulation here
	else
		tabul=""
	fi
	if [ "$a1" != "" ] 
	then
		echo "${tabul}${instr} $3 " >> temp
	elif [ "$a3" != "" ] 
	then
		echo "#end" >> temp
		break;
	else
		echo "${tabul}${instr} " >> temp
	fi
done
cp temp "$1"

