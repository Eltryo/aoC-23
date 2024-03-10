#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

#define LINE_SIZE 1024

int partTwo(FILE *fptr) {
    int result = 0;
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, fptr)) {}

    return result;
}
