#include "../include/llist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int val;
    Node *next;
};

struct Llist {
    Node *head;
};

Llist *initLlist(){
    Llist *list = malloc(sizeof(Llist));
    memset(list, 0, sizeof(*list));
    if(list == NULL){
        perror(__func__);
        exit(EXIT_FAILURE);
    }

    return list;
}
