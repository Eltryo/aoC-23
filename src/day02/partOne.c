#include <stdio.h>

#define LINE_SIZE 1024
#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14

int partOne(FILE *fptr) {
  int result = 0;
  char line[LINE_SIZE];
  int gameCount = 1;

  while (fgets(line, LINE_SIZE, fptr)) {


      gameCount++;
  }

  return result;
}
