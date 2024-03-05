#include <stdio.h>
#include <string.h>

#include "../include/string.h"

void chomp(char *line){
    if (strlen(line) == 0)
        return;

    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
        return;
    }
}

void printAscii(char *line){
    for(int i = 0; i <= strlen(line); i++){
        printf("Char of position %d is %02X\n", i, line[i]);
    }
}
