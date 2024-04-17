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
    Llist *list;
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

//todo: complete and test method
void add(Map *map, int key, int value){
    if(!map) return;

    MapNode *curr = map->head;
    for (int i = 0; i < size; i++) {
        if (curr->key == key) {
            if(!push(&(curr->list), value)){
                fprintf(stderr, "push was not successful\n");
                exit(EXIT_FAILURE);
            }

            return;
        }

        curr = curr->next;
    }

    MapNode *node = malloc(sizeof(MapNode));
    node->key = key;

    Llist *list = initLlist();
    push(&list, value);
    node->list = list;

    node->next = map->head;
    map->head = node;
    size++;
}

//todo: test method
Llist *get(Map *map, int key){
    if(!(map)) {
        fprintf(stderr, "map must not be NULL\n");
        return NULL;
    }

    if(!(map->head)) {
        fprintf(stderr, "map is empty\n");
        return NULL;
    }

    MapNode *curr = map->head;
    for(int i = 0; i < size; i++){
        if (curr->key == key) {
            return curr->list;
        }

        curr = curr->next;
    }

    return NULL;
}

void freeMapNodes(MapNode *head){
    if(!head) return;
    if(head->next){
        freeMapNodes(head->next);
    }

    freeList(head->list);
    free(head);
}

void freeMap(Map *map){
    freeMapNodes(map->head);
    free(map);
}
