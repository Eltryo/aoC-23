#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST
#define PASSED_COLOR "\x1B[32m"
//todo: reset does not work, must be fixed
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

int main(){
    testInitList();
}
