#ifndef LLIST_H
#define LLIST_H

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

#ifdef TEST
Llist *initLlist();

struct Node {
    int val;
    Node *next;
};

struct Llist {
    Node *head;
};
#endif

#endif
