#Linus Frisk 010809-2933 4/14/2025
#!/bin/bash
DIRECTORY=.

#origext samt newext
if [ $# -ne 2 ]; then
	logger -p user.alert "ALERT: Incorrect usage of the script. Excpeted 2 arguments got $#."
	exit 1
fi

logger -p user.info "INFO: Startar: Byter .$1 till .$2 i $DIRECTORY"
matched_files=false

for file in "$DIRECTORY"/*."$1"; do #kollar igenom current directory och letar efter argument 1
	if [ -e "$file" ]; then
		matched_files=true
		base="${file%.*}" #tar basfilernas namn utan ändelse
		newname="${base}.$2" #bytar ändelse till argument 2
		mv "$file" "$newname"  #bytar filens ändelse med det nya.
		logger -p user.info "INFO: Bytte: $file till $newname enligt överenskommelse"
	fi
done

$matched_files || logger -p user.warning "WARNING: Inga filer med ändelsen .$1 hittades"

logger -p user.info "INFO: Klar."


