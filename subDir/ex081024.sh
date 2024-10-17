#!/bin/bash

loadCount=0
loadLimit=5
CScriptPhrase="Absolute Baller bashu :)"

clear
echo "[0/0] Script starting..."
((loadCount++))
sleep 0.2s

echo "[$loadCount/$loadLimit] Creating folder..."
((loadCount++))
mkdir -p ./output
cd ./output

echo "[$loadCount/$loadLimit] Cleanup..."
((loadCount++))
rm -f ./main
rm -f ./main.c

echo "[$loadCount/$loadLimit] Creating file..."
((loadCount++))
echo "#include <stdio.h>" >main.c
echo "#define PHRASE \"$CScriptPhrase\"" >>main.c
echo "int main () {" >>main.c
echo "  printf(\"Hewo world :3\n%s \n\", PHRASE);" >>main.c
echo "  return 0;" >>main.c
echo "}" >>main.c

# clear
echo "[$loadCount/$loadLimit] Compiling..."
((loadCount++))
gcc ./main.c -o main

echo "[$loadCount/$loadLimit] Running C script..."
((loadCount++))
echo "#---------OUTPUT---------#"
./main
echo "#------------------------#"

echo "Would you wish to open VSCode? (y/n)"
read answer
if [ "$answer" = "y" ]; then
    echo "Open .c script file only? (y/n)"
    read filanswr
    if [ "$filanswr" = "y" ]; then
        code ./main.c
    else
        code ./
        ls -la ../
    fi
fi
