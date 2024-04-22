#ifndef MAP_H
#define MAP_H

#include "../include/list.h"

struct MapNode;
typedef struct MapNode MapNode;
struct MapNode{
    int key;
    List *list;
    MapNode *next;
};

struct Map;
typedef struct Map Map;
struct Map{
    MapNode *head;
    int size;
};


Map *mapInit();
void mapAdd(Map *map, int key, int value);
List *mapGet(Map *map, int key);
void freeMap(Map *map);

#endif
