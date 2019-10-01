#! /bin/sh
echo "#define __PATH__LIB__PATH__"
echo "#define __PATH__LIB__PATH__"
for header in $@
do
echo "#include \"$header\""
done
echo "#endif"
