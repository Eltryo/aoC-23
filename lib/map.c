#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

typedef struct{
    int value;
    struct Bucket *next;
} Bucket;

typedef struct MapNode MapNode;
struct MapNode{
    int key;
    unsigned nbuckets;
    Bucket *bucket;
    MapNode *next;
};

void mapInit(MapNode *mapNode){
    memset(mapNode, 0, sizeof(*(mapNode)));
}

int main(){
    MapNode mapNode;
    mapInit(&mapNode);
}
