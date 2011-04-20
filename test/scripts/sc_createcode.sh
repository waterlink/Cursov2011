#!/bin/bash
usage="Usage: sc_createcode.sh path comment shortname"

if [ $# -lt 2 ]
then
	echo ${usage}
	exit
fi

ppath="$1"
pcom="$2"
pname="$3"

./scripts/sc_copyright.sh c "${ppath}.hpp"
echo "
//
//	header file
//	${pcom}
//

#ifndef ${pname}_hpp
#define ${pname}_hpp



#endif

" >> "${ppath}.hpp"

./scripts/sc_copyright.sh c "${ppath}.cpp"
echo "
//
//	source file
//	${pcom}
//

#include \"${pname}.hpp\"


" >> "${ppath}.cpp"

a1=`echo ${ppath} | sed s/"source"/"objects"/g`
touch "$a1"


