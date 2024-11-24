#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <stdio.h>

typedef struct 
{
    FILE *file;
} Log;

// Create a file in a read mode "Note: use .txt in file name"
Log createFile(FILE *file, const char *fileName);
// Append file "Note: use .txt in file name"
Log appendFile(FILE *file, const char *fileName);
// Write mode "Note: use .txt in file name"
Log writeFile(FILE *file, const char *fileName);
// Read file mode "Note: use .txt in file name"
Log readFile(FILE *file, const char *fileName);
// Delete file mode "Note: use .txt in file name"
Log deleteFile(FILE *file, const char *fileName);

#endif // !FILEHANDLER_H