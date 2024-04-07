#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST
#define PASSED_COLOR "\x1B[32m"
//todo: reset does not work, must be fixed
#define RESET "\x1B[0m"

#include "../include/llist.h"

void testInitList(){
    Llist *list = initLlist();

    assert(list != NULL);
    assert(sizeof(Llist) == 8);
    assert(list->head == NULL);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeList(list);
}

void testPushOne(){
    Llist *list = initLlist();

    push(list, 1);

    assert(list->head->val == 1);
    assert(list->head->next == NULL);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeList(list);
}

void testPushTwo(){
    Llist *list = initLlist();

    push(list, 1);
    push(list, 2);

    assert(list->head->val == 2);
    assert(list->head->next->val == 1);
    assert(list->head->next->next == NULL);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeList(list);
}

void testPopOne(){
    Llist *list = initLlist();

    push(list, 1);
    push(list, 2);

    int *popVal = malloc(sizeof(int));
    bool popResult = pop(list, popVal);

    assert(popResult);
    assert(*popVal == 2);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    free(popVal);
    freeList(list);
}

void testPopEmptyList(){
    Llist *list = initLlist();

    int *popVal = calloc(1, sizeof(int));
    bool popResult = pop(list, popVal);

    assert(!popResult);
    assert(*popVal == 0);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    free(popVal);
    freeList(list);

}

void testPrintList(){
    Llist *list = initLlist();

    push(list, 1);
    push(list, 2);

    printList(list);

    freeList(list);
}

//how to programmaticly test that there are no memory leaks

int main(){
    testInitList();
    testPushOne();
    testPushTwo();
    testPopOne();
    testPopEmptyList();
    testPrintList();
}
