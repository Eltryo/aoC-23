#include <stdio.h>

#define LINE_SIZE 1024

int partOne(FILE *fptr) {
  int result = 0;
  char line[LINE_SIZE];

  while (fgets(line, LINE_SIZE, fptr)) {}

  return result;
}
