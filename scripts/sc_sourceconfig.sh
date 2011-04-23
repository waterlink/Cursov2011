#!/bin/bash
usage="sc_sourceconfig.sh"

ctarget=`./scripts/sc_getvalue.sh "./config/source_config" "target"`
cmodule=`./scripts/sc_getvalue.sh "./config/source_config" "module"`

echo "${ctarget}" | sed 's/^ *//;s/ *$//'
echo "${cmodule}" | sed 's/^ *//;s/ *$//'


