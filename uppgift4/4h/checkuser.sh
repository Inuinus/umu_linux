#!/bin/bash

logged_in_users=$(who | cut -d' ' -f1)

#ifall man inte ger en input direkt
if [ -z "$1" ]; then
	echo "skriv ett användarnamn:"
	read user_input

	if [ "$logged_in_users" == "$user_input" ]; then
		echo "inloggad"
		exit 0
	else
		echo "användaren är inte inloggad"
		exit 1
	fi
else #om inputen ges direkt
	if [ "$logged_in_users" == "$1" ]; then
                echo "inloggad"
                exit 0
        else
                echo "användaren är inte inloggad"
                exit 1
	fi
fi
