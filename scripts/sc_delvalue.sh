#!/bin/bash
if [ $# -lt 3 ]
then 
	echo "Usage: sc_delvalue file var value"
	exit
fi
counter=-1
tabul=""
rm temp
cat $1 | while :
do
	read instr
	a1=`echo "$instr" | grep "${2}="`
	a2=`echo "$instr"`
	a3=`echo "$instr" | grep "#end"`
	a4=`echo "$instr" | grep "$3"`
	a5=`echo "$instr" | grep "#tab"`
	if [ "$a5" != "" ]
	then
		counter=3
	fi
	if [ "${counter}" != "-1" ]
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
		if [ "$a4" != "" ]
		then
			echo "${tabul}${instr} " | sed s/" $3 "/" "/g >> temp
		else
			echo "${tabul}${instr} " >> temp
		fi
	elif [ "$a3" != "" ] 
	then
		echo "#end" >> temp
		break;
	else
		echo "${tabul}${instr} " >> temp
	fi
done
cp temp "$1"

