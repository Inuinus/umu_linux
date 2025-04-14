#Linus Frisk 010809-2933 4/14/2025
#!/bin/bash
DIRECTORY=.
LOGFILE="bashlogs.log"

#origext samt newext
echo " " >> "$LOGFILE" #Använder denna som whitespace
if [ $# -ne 2 ]; then
	echo "$(date +"%Y-%m-%d %H:%M:%S") - ALERT: Ange <gamla ändelsen> <nya_ändelsen>" >> "$LOGFILE"
	exit 1
fi

echo "$(date +"%Y-%m-%d %H:%M:%S" - INFO: Startar: Byter .$1 till .$2 i $DIRECTORY" >> "$LOGFILE"
matched_files=false

for file in "$DIRECTORY"/*."$1"; do #kollar igenom current directory och letar efter argument 1
	if [ -e "$file" ]; then
		matched_files=true
		base="${file%.*}" #tar basfilernas namn utan ändelse
		newname="${base}.$2" #bytar ändelse till argument 2
		mv "$file" "$newname"  #bytar filens ändelse med det nya.
		echo "$(date +"%Y-%m-%d %H:%M:%S" - INFO: Bytte: $file till $newname enligt överenskommelse" >> "$LOGFILE"
	fi
done

$matched_files || echo "$(date +"%Y-%m-%d %H:%M:%S" - ALERT: Inga filer med ändelsen .$1 hittades" >> "$LOGFILE"

echo "$(date +"%Y-%m-%d %H:%M:%S" - INFO: Klar." >> "$LOGFILE"


