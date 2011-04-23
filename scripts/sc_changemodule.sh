#!/bin/bash
usage="sc_changemodule.sh target module"
if [ $# -lt 2 ]
then
	echo "${usage}"
	break
fi

ptarget="$1"
pmodule="$2"

ctarget=`./scripts/sc_getvalue.sh "./config/source_config" "target"`
cmodule=`./scripts/sc_getvalue.sh "./config/source_config" "module"`

ctarget=`echo "${ctarget}" | sed 's/^ *//;s/ *$//'`
cmodule=`echo "${cmodule}" | sed 's/^ *//;s/ *$//'`

./scripts/sc_delvalue.sh "./config/source_config" "target" "${ctarget}"
./scripts/sc_delvalue.sh "./config/source_config" "module" "${cmodule}"

./scripts/sc_addvalue.sh "./config/source_config" "target" "${ptarget}"
./scripts/sc_addvalue.sh "./config/source_config" "module" "${pmodule}"



