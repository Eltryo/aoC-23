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

struct ListNode;
typedef struct ListNode ListNode;

struct Llist;
typedef struct Llist Llist;

Llist *initLlist();
bool push(Llist **list, int val);
void freeList(Llist *list);
bool pop(Llist *list, int *out);
void printList(Llist *list);

#ifdef TEST

struct ListNode {
    int val;
    ListNode *next;
};

struct Llist {
    ListNode *head;
};

#endif

#endif
