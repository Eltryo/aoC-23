#include <assert.h>
#include <string.h>

#include "../../include/partOne.h"
#include "../../include/partOne.h"
#include "../../include/string.h"

void chompTest(){
    //setup
    char testStr[] = "Test\n";

    //exec
    chomp(testStr);

    //assertion
    assert(strcmp("Test", testStr) == 0);
}

int main(){
    chompTest();
}
