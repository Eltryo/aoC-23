#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST
#define PASSED_COLOR "\x1B[32m"
#define RESET "\x1B[0m"

#include "../../include/list.h"

void testListInit(){
    List *list = listInit();

    assert(list != NULL);
    assert(sizeof(List) == 16);
    assert(list->head == NULL);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeList(list);
}

void testPushOne(){
    List *list = listInit();

    listPush(&list, 1);

    assert(list->head->val == 1);
    assert(list->head->next == NULL);
    assert(list->size == 1);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeList(list);
}

void testPushTwo(){
    List *list = listInit();

    listPush(&list, 1);
    listPush(&list, 2);

    assert(list->head->val == 2);
    assert(list->head->next->val == 1);
    assert(list->head->next->next == NULL);
    assert(list->size == 2);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeList(list);
}

void testPopOne(){
    List *list = listInit();

    listPush(&list, 1);
    listPush(&list, 2);

    int *popVal = malloc(sizeof(int));
    bool popResult = listPop(list, popVal);

    assert(popResult);
    assert(*popVal == 2);
    assert(list->size == 1);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    free(popVal);
    freeList(list);
}

void testPopEmptyList(){
    List *list = listInit();

    int *popVal = calloc(1, sizeof(int));
    bool popResult = listPop(list, popVal);

    assert(!popResult);
    assert(*popVal == 0);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    free(popVal);
    freeList(list);
}

void testPrintList(){
    List *list = listInit();

    listPush(&list, 1);
    listPush(&list, 2);

    printList(list);

    freeList(list);
}

int main(){
    testListInit();
    testPushOne();
    testPushTwo();
    testPopOne();
    testPopEmptyList();
    testPrintList();
}
