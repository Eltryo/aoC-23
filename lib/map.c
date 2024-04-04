#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/llist.h"
#include "../include/map.h"

int size = 0;

struct Map{
    MapNode *head;
};

struct MapNode{
    int key;
    unsigned nbuckets;
    Llist *value;
    MapNode *next;
};

Map *mapInit(){
    Map *map = malloc(sizeof(Map));
    memset(map, 0, sizeof(*(map)));
    if(map == NULL){
        perror(__func__);
        exit(EXIT_FAILURE);
    }

    return map;
}

void freeMapNodes(MapNode *head){
    if(!head) return;
    if(head->next){
        freeMapNodes(head->next);
    }

    free(head);
}

void freeMap(Map *map){
    freeMapNodes(map->head);
    free(map);
}
