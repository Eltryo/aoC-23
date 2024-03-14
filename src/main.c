#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>

#include "../include/partOne.h"
#include "../include/partTwo.h"

int main(int argc, char **argv) {
  FILE *fptr;
  char relativePath[PATH_MAX];

  char *day = argv[1];
  char *execPath = argv[0];

  int trunc;
  //trunc = snprintf(relativePath, sizeof(relativePath), "../input/%s/example_input_1", day);
  //trunc = snprintf(relativePath, sizeof(relativePath), "../input/%s/example_input_2", day);
  trunc = snprintf(relativePath, sizeof(relativePath), "../input/%s/input_1", day);
  //trunc = snprintf(relativePath, sizeof(relativePath), "../input/%s/input_2", day);
  if(trunc < 0){
      fprintf(stderr, "Error when building relative path\n");
      exit(EXIT_FAILURE);
  }

  char absolutePath[PATH_MAX];
  trunc = snprintf(absolutePath, sizeof(absolutePath), "%s/%s", dirname(execPath), relativePath);
  if(trunc < 0){
      fprintf(stderr, "Error building absolute path\n");
      exit(EXIT_FAILURE);
  }

  fptr = fopen(absolutePath, "r");
  if (fptr != NULL) {
    printf("The result of part one is %d\n", partOne(fptr));
    //printf("The result of part two is %d\n", partTwo(fptr));

    fclose(fptr);
  } else {
    printf("Not able to open the file: %s\n", relativePath);
  }
}
