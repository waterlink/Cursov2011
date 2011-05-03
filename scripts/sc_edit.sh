#!/bin/bash
usage="Usage: sc_edit.sh name"

if [ $# -lt 1 ]
then
	echo "$usage"
	exit
fi

pname="$1"

target=`./scripts/sc_getvalue.sh "./config/source_config" "target"`
module=`./scripts/sc_getvalue.sh "./config/source_config" "module"`
target=`echo ${target}`
module=`echo ${module}`

codeexist=`./scripts/sc_isnameexist.sh "${ptype}" "${target}/${module}" "${pname}"`
if [ "$codeexist" == "1" ]
then
	gedit "./source/${target}/${module}/${pname}.${target}.hpp" 2> "./log/geditlog.txt"
	gedit "./source/${target}/${module}/${pname}.${target}.cpp" 2> "./log/geditlog.txt"
else
	classexist=`./scripts/sc_isnameexist.sh "${ptype}" "${target}/${module}" "${pname}"`
	if [ "$classexist" == "1" ]
	then
		gedit "./source/${target}/${module}/${pname}.${target}.hpp" 2> "./log/geditlog.txt"
		gedit "./source/${target}/${module}/${pname}.${target}.cpp" 2> "./log/geditlog.txt"
	else
		echo "there is no ${pname} in ${target}/${module}"
	fi
fi

