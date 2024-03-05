#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/string.h"

#define LINE_SIZE 1024
#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14

int isValidGame(){
    char *sets = strtok(NULL, ":");
    printf("sets is %s\n", sets);

    char *savePtrSets, *savePtrSet;
    char *set;
    for((set = strtok_r(sets, ";", &savePtrSets)); set && *set; set = strtok_r(NULL, ";", &savePtrSets)){
        printf("set is %s\n", set);

        char *draft;
        for(draft = strtok_r(set, ",", &savePtrSet); draft && *draft; draft = strtok_r(NULL, ",", &savePtrSet)){
            printf("Draft is %s\n", draft);

            int amount = strtol(strtok(draft, " "), NULL, 10);
            printf("amount is %d\n", amount);

            char *color = strtok(NULL, " ");
            printf("color is %s\n", color);


            if(strcmp(color, "red") == 0) {
                if(amount > RED_MAX) return 0;
            } else if (strcmp(color, "green") == 0) {
                if(amount > GREEN_MAX) return 0;
            } else {
                if(amount > BLUE_MAX) {
                    printf("blue is great than max val");
                    return 0;
                }
            }
        }
    }

    return 1;
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
      int isValid = isValidGame();

      result += gameCount * isValid;

      gameCount++;
  }

  return result;
}
