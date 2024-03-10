#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

#include "../../include/string.h"

#define LINE_SIZE 1024

int powerOfSet(){
    int redMax = 0;
    int greenMax = 0;
    int blueMax = 0;
    printf("Red: %d, Green: %d, Blue: %d\n", redMax, greenMax, blueMax);

    char *set = strtok(NULL, ":");
    //printf("sets is %s\n", set);

    char *savePtrSets, *savePtrSet;
    char *subset;
    for((subset = strtok_r(set, ";", &savePtrSets)); subset && *subset; subset = strtok_r(NULL, ";", &savePtrSets)){
        //printf("set is %s\n", subset);

        char *draft;
        for(draft = strtok_r(subset, ",", &savePtrSet); draft && *draft; draft = strtok_r(NULL, ",", &savePtrSet)){
            //printf("Draft is %s\n", draft);

            int amount = strtol(strtok(draft, " "), NULL, 10);
            //printf("amount is %d\n", amount);

            char *color = strtok(NULL, " ");
            //printf("color is %s\n", color);


            if(strcmp(color, "red") == 0) {
                if(amount > redMax){
                    redMax = amount;
                }
            } else if (strcmp(color, "green") == 0) {
                if(amount > greenMax){
                    greenMax = amount;
                }
            } else {
                if(amount > blueMax){
                    blueMax = amount;
                }
            }
        }
    }

    int power = redMax * greenMax * blueMax;
    printf("Red: %d, Green: %d, Blue: %d so the power is %d\n", redMax, greenMax, blueMax, power);
    return power;
}

int partTwo(FILE *fptr) {
    int result = 0;
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, fptr)) {
        //remove line feed char
        chomp(line);

        //remove game prefix
        strtok(line, ":");

        //check if game is valid
        int power = powerOfSet();

        result += power;
    }

    return result;
}
