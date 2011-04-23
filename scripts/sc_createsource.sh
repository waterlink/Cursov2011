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
		codeexist=`./scripts/sc_isnameexist.sh "${ptype}" "${target}/${module}" "${pname}"`
		if [ "$codeexist" == "0" ]
		then
			./scripts/sc_createcode.sh "./source/${target}/${module}/${pname}.${target}" "${pcom}" "${pname}" "${target}"
			#echo "[code ${pname}] - ${pcom}" >> "./source/${target}/${module}/list"
			./scripts/sc_addname.sh "code" "${target}/${module}" "${pname}" "${pcom}"
		else
			echo "code ${target}/${module}/${pname} exists"
		fi
		;;

	class)
		classexist=`./scripts/sc_isnameexist.sh "${ptype}" "${target}/${module}" "${pname}"`
		if [ "$classexist" == "0" ]
		then
			./scripts/sc_createclass.sh "./source/${target}/${module}/${pname}.${target}" "${pcom}" "${pname}" "${target}"
			./scripts/sc_addname.sh "class" "${target}/${module}" "${pname}" "${pcom}"
		else
			echo "class ${target}/${module}/${pname} exists"
		fi
		;;

	module)
		module="${pname}"
		moduleexist=`./scripts/sc_ismoduleexist.sh "${target}/${module}"`
		if [ "$moduleexist" == "0" ]
		then
			mkdir "./source/${target}/${module}"
			mkdir "./objects/${target}/${module}"
			if [ "${target}" != "all" ]
			then
				./scripts/sc_addvalue.sh "makefile" "${target}_spec_HEADERS" "./source/${target}/${module}/*.${target}.hpp"
				./scripts/sc_addvalue.sh "makefile" "${target}_spec_SOURCES" "./source/${target}/${module}/*.${target}.cpp"
				./scripts/sc_addvalue.sh "makefile" "${target}_spec_OBJECTS" "./objects/${target}/${module}/*.${target}.o"
			else
				./scripts/sc_addvalue.sh "makefile" "linux_spec_HEADERS" "./source/${target}/${module}/*.${target}.hpp"
				./scripts/sc_addvalue.sh "makefile" "linux_spec_SOURCES" "./source/${target}/${module}/*.${target}.cpp"
				./scripts/sc_addvalue.sh "makefile" "linux_spec_OBJECTS" "./objects/${target}/${module}/*.linux.${target}.o"

				./scripts/sc_addvalue.sh "makefile" "win_spec_HEADERS" "./source/${target}/${module}/*.${target}.hpp"
				./scripts/sc_addvalue.sh "makefile" "win_spec_SOURCES" "./source/${target}/${module}/*.${target}.cpp"
				./scripts/sc_addvalue.sh "makefile" "win_spec_OBJECTS" "./objects/${target}/${module}/*.win.${target}.o"
			fi
			#echo "[module ${target}/${module}] - ${pcom}" >> "./config/modules"
			./scripts/sc_addmodule.sh "${target}/${module}" "${pcom}"
			./scripts/sc_changemodule.sh "${target}" "${module}"
			echo "#end" > "./source/${target}/${module}/list"
			
		else
			echo "module ${target}/${module} exists"
		fi
		;;

esac

