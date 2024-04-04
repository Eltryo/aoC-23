#ifndef LLIST_H
#define LLIST_H

#include <stdbool.h>

//data:
//  node with value and next node
//
//operations:
//  push a node
//  pop a node
//  print all values of the list

struct Node;
typedef struct Node Node;

struct Llist;
typedef struct Llist Llist;

Llist *initLlist();
void push(Llist *head, int val);
void freeList(Llist *list);
bool pop(Llist *list, int *out);

#ifdef TEST

struct Node {
    int val;
    Node *next;
};

struct Llist {
    Node *head;
};

#endif

#endif
