#include <assert.h>
#include <stdio.h>

#include "../../include/solve.h"
#include "../../include/file.h"

#define PASSED_COLOR "\x1B[32m"
#define RESET "\x1B[0m"

void testPartOne(char *execPath, char *inputFilePath, int expected){
    FILE *fptr;

    getInputFile(&fptr, execPath, inputFilePath);

    int result = partOne(fptr);

    assert(result == expected);
    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    fclose(fptr);
}

void testPartTwo(char *execPath, char *inputFilePath, int expected){
    FILE *fptr;

    getInputFile(&fptr, execPath, inputFilePath);

    int result = partTwo(fptr);

    assert(result == expected);
    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    fclose(fptr);
}

int main(int argc, char **argv){
    char *execPath = argv[0];
    testPartOne(execPath, "day03/example_input_1", 4361);
    testPartTwo(execPath, "day03/example_input_2", 467835);
    testPartTwo(execPath, "day03/input_2", 81296995);
}
