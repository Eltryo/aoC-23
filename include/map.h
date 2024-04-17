#ifndef MAP_H
#define MAP_H

#include "../include/llist.h"

struct Map;
typedef struct Map Map;

struct MapNode;
typedef struct MapNode MapNode;

Map *mapInit();
void add(Map *map, int key, int value);
Llist *get(Map *map, int key);
void freeMap(Map *map);

#ifdef TEST

struct Map{
    MapNode *head;
};

struct MapNode{
    int key;
    unsigned nbuckets;
    Llist *list;
    MapNode *next;
};

#endif

#endif
