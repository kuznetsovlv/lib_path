#! /bin/sh

str=`cat $1 | grep $2`

if [ -z $str ]
then
	echo $2 >> $1
	ldconfig
else
	echo "The path to the library is already configured"
fi
