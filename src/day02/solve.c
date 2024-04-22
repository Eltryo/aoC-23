#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/string.h"

#define LINE_SIZE 1024
#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14

int powerOfSet(){
    char *sets = strtok(NULL, ":");

    char *savePtrSets, *savePtrSet;
    char *set;
    for((set = strtok_r(sets, ";", &savePtrSets)); set && *set; set = strtok_r(NULL, ";", &savePtrSets)){
        char *draft;
        for(draft = strtok_r(set, ",", &savePtrSet); draft && *draft; draft = strtok_r(NULL, ",", &savePtrSet)){
            int amount = strtol(strtok(draft, " "), NULL, 10);
            char *color = strtok(NULL, " ");
            if(strcmp(color, "red") == 0) {
                if(amount > RED_MAX) return 0;
            } else if (strcmp(color, "green") == 0) {
                if(amount > GREEN_MAX) return 0;
            } else {
                if(amount > BLUE_MAX) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int powerOfSetRGB(){
    int redMax = 0;
    int greenMax = 0;
    int blueMax = 0;

    char *set = strtok(NULL, ":");

    char *savePtrSets, *savePtrSet;
    char *subset;
    for((subset = strtok_r(set, ";", &savePtrSets)); subset && *subset; subset = strtok_r(NULL, ";", &savePtrSets)){
        char *draft;
        for(draft = strtok_r(subset, ",", &savePtrSet); draft && *draft; draft = strtok_r(NULL, ",", &savePtrSet)){
            int amount = strtol(strtok(draft, " "), NULL, 10);
            char *color = strtok(NULL, " ");
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
    return power;
}

int partOne(FILE *fptr) {
    int result = 0;
    char line[LINE_SIZE];
    int gameCount = 1;

    while (fgets(line, LINE_SIZE, fptr)) {
        //remove line feed char
        chomp(line);

        //remove game prefix
        strtok(line, ":");

        //check if game is valid
        int isValid = powerOfSet();

        result += gameCount * isValid;

        gameCount++;
    }

    return result;
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
        int power = powerOfSetRGB();

        result += power;
    }

    return result;
}
