#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/file.h"
#include "../../include/map.h"

size_t lineLength;
size_t buffLen;

unsigned lengthOfLine(char *line){
    if(line == NULL || strlen(line) == 0){
        return -1;
    }

    unsigned i = 0;
    while(line[i] != '\n'){
        i++;
    }

    return ++i;
}

bool moveToDigit(char **curr){
    while(**curr < '0' || **curr > '9'){
        if(**curr == '\0'){
            return false;
        }

        (*curr)++;
    }

    return true;
}

bool isNumeric(char c){
    return c >= '0' && c <= '9';
}

int findSymbol(char **curr, char *buff, char symbol){
    while (isNumeric(**curr)){
        int pos = *curr - buff;
        int surroundings[] = {
            pos - lineLength - 1,
            pos - lineLength,
            pos - lineLength + 1,
            pos - 1,
            pos + 1,
            pos + lineLength - 1,
            pos + lineLength,
            pos + lineLength + 1
        };

        //iterate over all surrounding chars and check if they match with a symbol or a specific char
        for(int i = 0; i < 8; i++){
            int surrPos = surroundings[i];
            if(surrPos >= 0 && surrPos < buffLen){
                char surrChar = buff[surrPos];
                bool isSymbol;
                if(symbol == 0){
                    isSymbol = !(isNumeric(surrChar) || surrChar == '.' || surrChar == '\n');
                } else {
                    isSymbol = surrChar == symbol;
                }

                if(isSymbol) {
                    //adjust the pointer to point to the end of the digit sequence
                    while(isNumeric(**curr)){
                        (*curr)++;
                    }

                    return surrPos;
                }
            }
        }

        (*curr)++;
    }

    return -1;
}

char *substring(char *start, char* end) {
    int substringLen = end - start;
    char *substr = calloc(substringLen + 1, 1);

    strncpy(substr, start, substringLen);

    return substr;
}

int partOne(FILE *fptr) {
    int result = 0;
    char *buff = readFile(fptr, &buffLen);

    lineLength = lengthOfLine(buff);

    char *curr = buff;
    char *succ;
    while(*curr != '\0'){
        //move the curr pointer to the next digit
        if(!moveToDigit(&curr)) {
            free(buff);
            return result;
        }
        succ = curr;

        //find a symbol or a specific char surrounding a digit sequence (number)
        int posSymbol = findSymbol(&curr, buff, 0);
        if(posSymbol != -1){
            //if symbol was found then extract the substring containing the digits of the number
            char *substr = substring(succ, curr);
            long num = strtol(substr, NULL, 10);
            if(errno != 0){
                free(substr);
                free(buff);

                perror(__func__);
                exit(EXIT_FAILURE);
            }

            //add the number to the result accumulator
            result += num;

            free(substr);
        }
    }

    free(buff);
    return result;
}

int partTwo(FILE *fptr) {
    int result = 0;
    char *buffer = readFile(fptr, &buffLen);

    lineLength = lengthOfLine(buffer);

    char *curr = buffer;
    char *succ = NULL;
    Map *map = mapInit();
    while(*curr != '\0'){
        //move the curr pointer to the next digit
        if(!moveToDigit(&curr)) {
            free(buffer);
            break;
        }
        succ = curr;

        //find a symbol or a specific char surrounding a digit sequence (number)
        int posOfSymbol = findSymbol(&curr, buffer, '*');
        if(posOfSymbol != -1){
            //if symbol was found then extract the substring containing the digits of the number
            char *substr = substring(succ, curr);
            int num = strtol(substr, NULL, 10);
            if(errno != 0){
                free(substr);
                free(buffer);

                perror(__func__);
                exit(EXIT_FAILURE);
            }

            //store the number and the corresponding position of the asterisk
            mapAdd(map, posOfSymbol, num);

            free(substr);
        }
    }

    MapNode *currMapNode = map->head;
    while(currMapNode) {
        List *list = currMapNode->list;
        unsigned listSize = list->size;

        //which map entry has exactly two buckets entries
        if(listSize == 2) {
            int ratio = 1;
            ListNode *head = list->head;
            for (int i = 0; i < 2; i++) {
                //multiply these bucket entries to get the gear ratio
                ratio *= head->val;
                head = head->next;
            }

            //add up all gear ratios
            result += ratio;
        }

        currMapNode = currMapNode->next;
    }


    freeMap(map);
    return result;
}
