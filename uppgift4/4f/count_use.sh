#!/bin/bash

curr=$(<count_file)


if [ "$1" == "in" ]; then
	echo $((curr + 1)) > count_file
	echo "Inloggad"
fi

curr=$(<count_file)

if [ "$1" == "ut" ] && [ "$curr" -gt 0 ]; then
	echo "Inloggad"
	echo $((curr - 1)) > count_file
elif [ "$curr" == 0 ]; then
	echo "Utloggad"
fi
