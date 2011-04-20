#!/bin/bash

rm -rf "./source"
rm -rf "./binary"
rm -rf "./objects"
rm -rf "./data"
rm -rf "./config"
rm -rf "./etc"
rm -rf "./log"

mkdir "./source"
mkdir "./source/linux"
mkdir "./source/win"
mkdir "./source/all"
mkdir "./objects"
mkdir "./objects/linux"
mkdir "./objects/win"
mkdir "./binary"
mkdir "./binary/linux"
mkdir "./binary/win"
mkdir "./data"
mkdir "./config"
mkdir "./etc"
mkdir "./log"

cp "./scripts/sc_makefile0" "makefile"
cp "./scripts/sc_source_config0" "./config/source_config"

echo "
Initialization of project completed
Enter here copyright/author information
sharp-end must not to be deleted

#end
" > "./etc/copyright"
gedit "./etc/copyright" 2> "./log/log_gedit"

touch "./config/modules"


