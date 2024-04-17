#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST
#define PASSED_COLOR "\x1B[32m"
#define RESET "\x1B[0m"

#include "../include/map.h"

void testInitList(){
    Map *map = mapInit();

    assert(map != NULL);
    assert(sizeof(Map) == 8);
    assert(map->head == NULL);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeMap(map);
}

void testGetAdd(){
    Map *map = mapInit();

    add(map, 0, 10);
    add(map, 0, 20);
    add(map, 1, 11);

    Llist *list0 = get(map, 0);
    Llist *list1 = get(map, 1);

    assert(20 == list0->head->val);
    assert(10 == list0->head->next->val);
    assert(11 == list1->head->val);

    printf("%s " PASSED_COLOR "passed" RESET "\n", __func__);
    freeMap(map);
}


int main(){
    testInitList();
    testGetAdd();
}
