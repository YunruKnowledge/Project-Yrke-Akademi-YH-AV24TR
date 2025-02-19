import os

os.system("echo \"Starting...\" && cd ../class/example && echo \"Files: ../class/example/*.cpp\" && ls *.cpp")
os.system("cd ../class/example && g++ -c data.cpp")
os.system("cd ../class/example && g++ -c display.cpp")
os.system("cd ../class/example && g++ -c main.cpp")
os.system("cd ../class/example && g++ main.o data.o display.o -o ../../python/temp.exe")

os.system("cd ../class/example && rm -f data.o")
os.system("cd ../class/example && rm -f display.o")
os.system("cd ../class/example && rm -f main.o")
os.system("echo \"Finished. (Output ./temp.exe)\"")

os.system("ls *.exe")