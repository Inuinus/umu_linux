#!/bin/bash

old_1970=$(<datefile)
new_1970=$(date +%s)
subtract=$((new_1970-old_1970))
echo "$subtract"
