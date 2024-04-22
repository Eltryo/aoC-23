#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

struct ListNode;
typedef struct ListNode ListNode;
struct ListNode {
    int val;
    ListNode *next;
};

struct List;
typedef struct List List;
struct List {
    ListNode *head;
    unsigned size;
};

List *listInit();
bool listPush(List **list, int val);
bool listPop(List *list, int *out);
void printList(List *list);
void freeList(List *list);

#endif
