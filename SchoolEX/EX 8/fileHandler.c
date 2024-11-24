#include "fileHandler.h"

Log createFile(FILE *file, const char *fileName){
    if (file == NULL)
        (void) printf("File dose not exist!");
    file = fopen(fileName, "r");
}

Log appendFile(FILE *file, const char *fileName){
    if (file == NULL)
        (void) printf("File dose not exist!");
    file = fopen(fileName, "a");
}

Log writeFile(FILE *file, const char *fileName){
    if (file == NULL)
        (void) printf("File dose not exist!");
    file = fopen(fileName, "w");
}

Log readFile(FILE *file, const char *fileName){ 
    if (file == NULL)
        (void) printf("File dose not exist!");
    file = fopen(fileName, "r");
}

Log deleteFile(FILE *file, const char *fileName){
    if (file == NULL)
        (void) printf("File dose not exist!");
    remove(fileName);
}