#! /bin/sh

rel_path=`echo $1 | grep -Po "(?<=include/).*"`
mkdir -p `dirname $2$rel_path`
cp $1 $2$rel_path
