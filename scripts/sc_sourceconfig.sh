#!/bin/bash
usage="sc_sourceconfig.sh"

ctarget=`./scripts/sc_getvalue.sh "./config/source_config" "target"`
cmodule=`./scripts/sc_getvalue.sh "./config/source_config" "module"`

echo "target: ${ctarget}" | sed 's/^ *//;s/ *$//'
echo "module: ${cmodule}" | sed 's/^ *//;s/ *$//'


