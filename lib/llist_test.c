#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST
#define PASSED_COLOR "\x1B[32m"
#define RESET "\x1B[0m"

#include "../include/llist.h"

void testInitList(){
    Llist *list = initLlist();

    assert(list != NULL);
    assert(sizeof(Llist) == 8);
    assert(list->head == NULL);

    printf("%s " PASSED_COLOR "passed\n" RESET, __func__);
    freeList(list);
}

void testPushOne(){
    Llist *list = initLlist();

    push(&list->head, 1);

    assert(list->head->val == 1);
    assert(list->head->next == NULL);

    printf("%s " PASSED_COLOR "passed\n" RESET, __func__);
    freeList(list);
}

void testPushTwo(){
    Llist *list = initLlist();

    push(&list->head, 1);
    push(&list->head, 2);

    assert(list->head->val == 2);
    assert(list->head->next->val == 1);
    assert(list->head->next->next == NULL);

    printf("%s " PASSED_COLOR "passed\n" RESET, __func__);
    freeList(list);
}

//how to programmaticly test that there are no memory leaks

int main(){
    testInitList();
    testPushOne();
    testPushTwo();
}
