#!/bin/bash
usage="Usage: sc_createcode.sh path comment shortname target"

if [ $# -lt 4 ]
then
	echo ${usage}
	exit
fi

ppath="$1"
pcom="$2"
pname="$3"
ptarget="$4"

./scripts/sc_copyright.sh c "${ppath}.hpp"
echo "
//
//	header file
//	${pcom}
//

#ifndef ${pname}_hpp
#define ${pname}_hpp



#endif

//#end" >> "${ppath}.hpp"

gedit "${ppath}.hpp" 2> "./log/gedit.log"

./scripts/sc_copyright.sh c "${ppath}.cpp"
echo "
//
//	source file
//	${pcom}
//

#include \"${pname}.${ptarget}.hpp\"


//#end" >> "${ppath}.cpp"

gedit "${ppath}.cpp" 2> "./log/gedit.log"

a1=""
a2=""
if [ "${ptarget}" == "all" ]
then
	a1=`echo "${ppath}.o" | sed s/"source"/"objects"/g | sed s/".all.o"/".linux.all.o"/g`
	touch "$a1"
	a2=`echo "${ppath}.o" | sed s/"source"/"objects"/g | sed s/".all.o"/".win.all.o"/g`
	touch "$a2"
	./scripts/sc_addstring.sh "makefile" " "
	./scripts/sc_addstring.sh "makefile" "#tab"
	./scripts/sc_addstring.sh "makefile" "${a1}: ${ppath}.cpp ${ppath}.hpp"
	./scripts/sc_addstring.sh "makefile" "	\$(linux_CC) ${ppath}.cpp \$(linux_CFLAGS) -o ${a1} \$(linux_DEFFS)"
	./scripts/sc_addstring.sh "makefile" "#tab"
	./scripts/sc_addstring.sh "makefile" " "
	./scripts/sc_addstring.sh "makefile" "	\$(win_CC) ${ppath}.cpp \$(win_CFLAGS) -o ${a2} \$(win_DEFFS)"
else
	a1=`echo "${ppath}.o" | sed s/"source"/"objects"/g`
	touch "$a1"
	./scripts/sc_addstring.sh "makefile" " "
	./scripts/sc_addstring.sh "makefile" "#tab"
	./scripts/sc_addstring.sh "makefile" "${a1}: ${ppath}.cpp ${ppath}.hpp"
	./scripts/sc_addstring.sh "makefile" "	\$(${ptarget}_CC) ${ppath}.cpp \$(${ptarget}_CFLAGS) -o ${a1} \$(${ptarget}_DEFFS)"
fi
#check for tabulations
./scripts/sc_addvalue.sh "makefile" "bgabgabgabga_1234567890" "oops"

make -B linux
make -B win

