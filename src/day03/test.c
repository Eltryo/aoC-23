#include <assert.h>
#include <libgen.h>
#include <linux/limits.h>
#include <stdbool.h>
#include <stdio.h>

#include "../../include/partOne.h"
#include "../../include/file.h"

void testPartOne(char *execPath, char *inputFilePath, int expected){
    FILE *fptr;

    getInputFile(&fptr, execPath, inputFilePath);

    int result = partOne(fptr);

    assert(result == 4361);
}

int main(int argc, char **argv){
    testPartOne(argv[0], "day03/example_input_1", 4361);
}
