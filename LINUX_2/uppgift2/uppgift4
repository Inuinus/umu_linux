#Linus Frisk 010809-2933 4/6/2025
#!/bin/bash
DIRECTORY=.

#origext samt newext

for file in "$DIRECTORY"/*."$1"; do #kollar igenom current directory och letar efter argument 1
	base="${file%.*}" #tar basfilernas namn utan ändelse
	newname="${base}.$2" #bytar ändelse till argument 2
	mv "$file" "$newname"  #bytar filens ändelse med det nya.
done

