#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#include "../include/solve.h"

int main(int argc, char **argv) {
  FILE *fptr;

  char *execPath = argv[0];
  char *day = argv[1];
  char *input = argv[2];

  char relativePath[PATH_MAX];
  int written = snprintf(relativePath, sizeof(relativePath), "../input/%s/%s", day, input);
  if(written < 0){
      fprintf(stderr, "Error when building relative path\n");
      exit(EXIT_FAILURE);
  } else if (written >= sizeof(relativePath)){
      fprintf(stderr, "File content exceeds buffer length");
      exit(EXIT_FAILURE);
  }

  char absolutePath[PATH_MAX];
  written = snprintf(absolutePath, sizeof(absolutePath), "%s/%s", dirname(execPath), relativePath);
  if(written < 0){
      fprintf(stderr, "Error building absolute path\n");
      exit(EXIT_FAILURE);
  } else if (written >= sizeof(relativePath)){
      fprintf(stderr, "File content exceeds buffer length");
      exit(EXIT_FAILURE);
  }

  fptr = fopen(absolutePath, "r");
  if (fptr != NULL) {
    //printf("The result of part one is %d\n", partOne(fptr));
    printf("The result of part two is %d\n", partTwo(fptr));

    fclose(fptr);
  } else {
    printf("Not able to open the file: %s\n", relativePath);
  }
}
