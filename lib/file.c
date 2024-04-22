#include <libgen.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/file.h"

char *readFile(FILE *fptr, size_t *bufferLength){
    if(fseek(fptr, 0L, SEEK_END) == 0){
        int buffSize = ftell(fptr);
        if(buffSize == -1) {
            fprintf(stderr, "Error determining size of file");
            exit(EXIT_FAILURE);
        }

        char *buffer = malloc(sizeof(char) * (buffSize + 1));

        rewind(fptr);

        *bufferLength = fread(buffer, sizeof(char), buffSize, fptr);
        if(ferror(fptr) != 0) {
            fprintf(stderr, "Error reading file");
            free(buffer);
            exit(EXIT_FAILURE);
        } else {
            buffer[(*bufferLength)++] = '\0';
        }

        return buffer;
    } else {
        fprintf(stderr, "Error seeking end of file");
        exit(EXIT_FAILURE);
    }
}

void getInputFile(FILE **fptr, char *execPath, char *inputFilePath){
    char relativePath[PATH_MAX];
    int written;

    written = snprintf(relativePath, sizeof(relativePath), "../input/%s", inputFilePath);
    if(written < 0){
        fprintf(stderr, "Error when building relative path\n");
        exit(EXIT_FAILURE);
    }

    char absolutePath[PATH_MAX];
    char *execPathCpy = calloc(strlen(execPath) + 1, sizeof(char));
    strcpy(execPathCpy, execPath);
    written = snprintf(absolutePath, sizeof(absolutePath), "%s/%s", dirname(execPathCpy), relativePath);
    if(written < 0){
        fprintf(stderr, "Error building absolute path\n");
        exit(EXIT_FAILURE);
    }
    free(execPathCpy);

    *fptr = fopen(absolutePath, "r");
    if(*fptr == NULL){
        perror("Error open input file");
        exit(EXIT_FAILURE);
    }
}

