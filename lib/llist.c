#include "../include/llist.h"

#include <stdbool.h>
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

Llist *initLlist() {
    Llist *list = malloc(sizeof(Llist));
    memset(list, 0, sizeof(*list));
    if (list == NULL) {
        perror(__func__);
        exit(EXIT_FAILURE);
    }

    return list;
}

void push(Llist *list, int val){
    Node *node;
    node = malloc(sizeof(Node));

    node->val = val;
    node->next = list->head;
    list->head = node;
}

bool pop(Llist *list, int *out){
    if(list == NULL){
        //todo: improve error messages
        fprintf(stderr, "List is NULL\n");
        return false;
    }

    if(list->head == NULL){
        //todo: improve error messages
        fprintf(stderr, "Cannot pop from empty list\n");
        return false;
    }

    Node *tmp = list->head->next;
    *out = list->head->val;
    free(list->head);

    list->head = tmp;

    return true;
}

void freeNodes(Node *head){
    if(!head) return;
    if(head->next) {
        freeNodes(head->next);
    }

    free(head);
}

void freeList(Llist *list){
    freeNodes(list->head);
    free(list);
}
