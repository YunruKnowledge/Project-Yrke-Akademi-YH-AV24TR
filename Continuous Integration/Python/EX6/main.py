import os

_path = os.getcwd()
files = []

def checkAnotherDir(path, dirName):
    newPath = os.path.join(path, dirName)
    checkForC(newPath, dirName)
    

def checkForC(path, _file = None):
    for file in os.listdir(path):
        if (file.endswith(".c")):
                if _path == path:     
                    files.append(file)
                else:
                     files.append(os.path.join(_file + '/', file))
        elif os.path.isdir(os.path.join(_path, file)):
             checkAnotherDir(path, file)


print("Current directory is: {}".format(_path))
print(os.listdir(_path))
checkForC(_path)
print(files)
os.system("gcc -c " + " ".join(files))