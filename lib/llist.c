#include "../include/llist.h"
#include <stdlib.h>

struct Node {
    int val;
    Node *next;
};

struct Llist {
    Node *head;
};

Llist *initLlist(){
    Llist *list = malloc(sizeof(Llist));
    return list;
}
