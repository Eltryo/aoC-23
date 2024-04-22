#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "../../include/solve.h"
#include "../../include/string.h"
#include "../../include/file.h"

#define PASSED_COLOR "\x1B[32m"
#define RESET "\x1B[0m"

void chompTest(){
    char testStr[] = "Test\n";

    chomp(testStr);

    assert(strcmp("Test", testStr) == 0);
    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
}

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
    testPartOne(execPath, "day02/example_input_1", 8);
    testPartTwo(execPath, "day02/example_input_2", 2286);

    testPartOne(execPath, "day02/input_1", 2085);
    testPartTwo(execPath, "day02/input_2", 79315);

    chompTest();
}
