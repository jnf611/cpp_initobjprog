#!/usr/bin/env bash
echo "The script you are running has basename `basename $0`, dirname `dirname $0`"
echo "The present working directory is `pwd`"
script_dir="`pwd`/`dirname $0`"
echo $script_dir

find . -exec file {} \; | grep -i elf | cut -d: -f1 | xargs rm -f -v
find "$script_dir/cpp" -name "*.o" -exec rm -f -v {} \;
find "$script_dir/cpp" -name "*.gch" -exec rm -f -v {} \;

