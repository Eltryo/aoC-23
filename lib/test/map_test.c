#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST
#define PASSED_COLOR "\x1B[32m"
#define RESET "\x1B[0m"

#include "../../include/map.h"

void testMapInit(){
    Map *map = mapInit();

    assert(map != NULL);
    assert(sizeof(Map) == 16);
    assert(map->head == NULL);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeMap(map);
}

void testMapGetAdd(){
    Map *map = mapInit();

    mapAdd(map, 0, 10);
    mapAdd(map, 0, 20);
    mapAdd(map, 1, 11);

    List *list0 = mapGet(map, 0);
    List *list1 = mapGet(map, 1);

    assert(20 == list0->head->val);
    assert(10 == list0->head->next->val);
    assert(11 == list1->head->val);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeMap(map);
}

int main(){
    testMapInit();
    testMapGetAdd();
}
