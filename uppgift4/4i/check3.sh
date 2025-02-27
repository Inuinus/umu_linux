#!/bin/bash

#kontrollscript för all och clean.
#scriptet kontrollerar så all producerar program1, utan komp,länk errors
#kontrollerar att clean städar upp på rätt sätt
#källkod och make-filen ska ligga i 3D, samma som check3.sh.
#sökvägen till makefilen ska vara 3D/makefile

search_path="./3D"
file="$search_path""/program1"

make -C "$search_path"

if [ -f "$file" ]; then
	echo "Filen finns: pass"
else
	echo "Filen finns inte: fail"
fi

make clean -C "$search_path"

o_files=$(find "$search_path" -name "*.o")
d_files=$(find "$search_path" -name "*.d")

if [ -f "$file" ] || [ -n "$o_files" ] || [ -n "$d_files" ]; then
	echo "Allting är inte rensat: fail"
else
	echo "Allting är rensat: pass"
fi
