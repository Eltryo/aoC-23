#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST
#define PASSED_COLOR "\x1B[32m"
#define RESET "\x1B[0m"

#include "../include/llist.h"

//Is there a possibility to catch failed assertions
void testInitList(){
    Llist *list = initLlist();

    assert(list != NULL);
    assert(sizeof(Llist) == 8);
    assert(list->head == NULL);

    printf("%s " PASSED_COLOR "passed\n" RESET, __func__);
    free(list);
}

int main(){
    testInitList();
}
