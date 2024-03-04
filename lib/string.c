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
