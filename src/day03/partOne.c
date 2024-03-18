#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/file.h"

size_t lineLength;
size_t bufferLength;

size_t lengthOfLine(char *line){
    if(line == NULL){
        return -1;
    }

    size_t i = 0;
    while(line[i] != '\n'){
        i++;
    }

    return ++i;
}

bool searchDigit(char **curr){
    printf("The char value is %c\n", **curr);
    while(**curr < '0' || **curr > '9'){
        if(**curr == '\0'){
            return false;
        }

        (*curr)++;
        printf("The char value is %c\n", **curr);
    }

    return true;
}

bool isNumeric(char c){
    return c >= '0' && c <= '9';
}

bool lookAround(int pos, char *buffer){
    int surroundingPositions[] = {
        pos - lineLength - 1,
        pos - lineLength,
        pos - lineLength + 1,
        pos - 1,
        pos + 1,
        pos + lineLength - 1,
        pos + lineLength,
        pos + lineLength + 1
    };

    for(int i = 0; i < 8; i++){
        int surrPos = surroundingPositions[i];
        printf("surrounding pos is %d\n", surrPos);
        if(surrPos >= 0 && surrPos <= bufferLength){
            char surrChar = buffer[surrPos];
            printf("surrounding char is %c\n", surrChar);
            bool isSymbolic = !(isNumeric(surrChar) || surrChar == '.' || surrChar == '\n');
            if(isSymbolic) return true;
        }
    }

    return false;
}

//  if symbol was found move to next non numeric char and return true
//  if not found go to next digit and repeat the look around
//  if non numeric char is reached then return false
bool isAdjacent(char **curr, char* buffer){
    while (isNumeric(**curr)){
        int pos = *curr - buffer;
        printf("position for look around is %d\n", pos);
        bool found = lookAround(pos, buffer);
        if(found){
            printf("symbol found");
            while(isNumeric(**curr)){
                (*curr)++;
            }

            return true;
        }

        (*curr)++;
    }

    return false;
}

char *substring(char *str, char *start, char* end) {
    int substringLen = end - start;
    char *substr = calloc(substringLen + 1, 1);

    strncpy(substr, start, substringLen);

    return substr;
}

int partOne(FILE *fptr) {
    int result = 0;
    char *buffer = readFile(fptr, &bufferLength);

    lineLength = lengthOfLine(buffer);
    printf("length of line is %lu\n", lineLength);

    char *curr = buffer;
    char *succ = NULL;
    while(*curr != '\0'){
        //search digit
        if(!searchDigit(&curr)) {
            free(buffer);
            return result;
        }
        succ = curr;

        printf("look around\n");
        //look around this digit for symbols
        bool adjacent = isAdjacent(&curr, buffer);
        if(adjacent){
            printf("is adjacent\n");
            //if symbol was found then extract the substring containing the digits of the number
            char *substr = substring(buffer, succ, curr);
            int num = strtol(substr, NULL, 10);
            if(errno == ERANGE){
                free(substr);
                free(buffer);

                fprintf(stderr, "Error converting substring to int");
                exit(EXIT_FAILURE);
            }

            //add the number to the result accumulator
            result += num;
            printf("The result now is %d\n", result);
            free(substr);
        }
    }

    free(buffer);
    return result;
}
