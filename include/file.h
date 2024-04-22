#ifndef FILE_H
#define FILE_H

#include <stdio.h>

char *readFile(FILE *fptr, size_t *bufferLength);
void getInputFile(FILE **fptr, char *execPath, char *inputFilePath);

#endif /* string.h */
