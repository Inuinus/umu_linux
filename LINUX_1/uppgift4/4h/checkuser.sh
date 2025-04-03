#!/bin/bash

logged_in_users=$(who | cut -d' ' -f1)
#ifall man inte ger en input direkt
if [ -z "$1" ]; then
	echo "skriv ett användarnamn:"
	read user_input

	if [[ $(echo "$logged_in_users" | grep "^$user_input$") ]]; then
		exit 0
	else
		exit 1
	fi
else #om inputen ges direkt
	if [[ $(echo "$logged_in_users" | grep "^$1$") ]]; then
                exit 0
        else
		exit 1
	fi
fi
