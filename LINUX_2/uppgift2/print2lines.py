#Linus Frisk 010809-2933 4/6/2025 
import glob, os, sys

#här är inputen vi får från första saken vi skiver dvs /home/linus/python för min del.
input_text = sys.argv[1]

try:
	os.chdir(f"{input_text}") #Går in i directoryt för input_text
except:
	print("not a correct directory")
	sys.exit(1)
#stänger ner programmet efter att detta directoryt inte finns eftersom annars fortsätter programmet
#i current directory och kommer ändå skriva ut .txt filernas innehåll dvs text1.txt o text2.txt

for file in glob.glob("*.txt"): #Går in i varje fil som slutar med .txt
        with open(file, "r") as f: #Öppnar varje fil och läser dessa samt sätter till filen mot f
                for i in range(2):
                        line = f.readline().strip() #tar bort whitespace
                        print(line, end=" ") #end=" ", gör så att vi inte får whitespace mellan 2 linjerna.
                print("\n")
