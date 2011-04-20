#!/bin/bash
usage="Usage: sc_createsource.sh type name comment"

if [ $# -lt 3 ]
then
	echo "$usage"
	exit
fi

ptype="$1"
pname="$2"
pcom="$3"

target=`./scripts/sc_getvalue.sh "./config/source_config" "target"`
module=`./scripts/sc_getvalue.sh "./config/source_config" "module"`
target=`echo ${target}`
module=`echo ${module}`

case $ptype in

	code)
		./scripts/sc_isnameexist.sh "${ptype}" "${target}/${module}" "${pname}" | read codeexist
		if [ "$codeexist" == "0" ]
		then
			./scripts/sc_createcode.sh "./source/${target}/${module}/${pname}.${target}" "${pcom}" "${pname}"
			echo "[code ${pname}] - ${pcom}" >> "./source/${target}/${module}/list"
		else
			echo "code ${target}/${module}/${pname} exists"
		fi
		;;

	class)
		./scripts/sc_isnameexist.sh "${ptype}" "${target}/${module}" "${pname}" | read classexist
		if [ "$classexist" == "0" ]
		then
			./scripts/sc_createclass.sh "./source/${target}/${module}/${pname}.${target}" "${pcom}" "${pname}"
			echo "[class ${pname}] - ${pcom}" >> "./source/${target}/${module}/list"
		else
			echo "class ${target}/${module}/${pname} exists"
		fi
		;;

	module)
		module="${pname}"
		./scripts/sc_ismoduleexist.sh "${target}/${module}" | read moduleexist
		moduleexist=0
		if [ "$moduleexist" == "0" ]
		then
			mkdir "./source/${target}/${module}"
			mkdir "./objects/${target}/${module}"
			./scripts/sc_addvalue.sh "makefile" "${target}_spec_HEADERS" "./source/${target}/${module}/*.${target}.hpp"
			./scripts/sc_addvalue.sh "makefile" "${target}_spec_SOURCES" "./source/${target}/${module}/*.${target}.cpp"
			./scripts/sc_addvalue.sh "makefile" "${target}_spec_OBJECTS" "./objects/${target}/${module}/*.${target}.o"
			echo "[module ${target}/${module}] - ${pcom}" >> "./config/modules"
			./scripts/sc_changemodule.sh "${target}" "${module}"
		else
			echo "module ${target}/${module} exists"
		fi
		;;

esac

