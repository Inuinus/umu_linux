#!/bin/bash

curr_time=$(date "+%s")
calculate_time_difference () {
	var_time=$(< ./timeStart)
	diff=$((curr_time - var_time))
	echo "$diff"
}


if [ "$1" == "start" ]; then
	echo "$curr_time" > timeStart
elif [ "$1" == "status" ] && [ -f ./timeStart ]; then
	calculate_time_difference
elif [ "$1" == "stop" ] && [ -f ./timeStart ]; then
	calculate_time_difference
	rm ./timeStart
elif [ "$1" == "status" ] || [ "$1" == "stop" ]; then
	echo "Timetrack ej aktiv" 
fi
