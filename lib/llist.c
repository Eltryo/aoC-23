#include "../include/llist.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    ListNode *next;
};

struct Llist {
    ListNode *head;
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

void printList(Llist *list){
    if(!list){
        fprintf(stderr, "list must not be NULL");
        return;
    }

    printf("-> ");
    if(!list->head){
        printf("\n");
        return;
    }

    ListNode *curr = list->head;
    while(curr){
        printf("%d -> ", curr->val);
        curr = curr->next;
    }

    printf("\n");
}

bool push(Llist *list, int val){
    if(!list) return false;

    ListNode *node;
    node = malloc(sizeof(ListNode));

    node->val = val;
    node->next = list->head;
    list->head = node;

    return true;
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

    ListNode *tmp = list->head->next;
    *out = list->head->val;
    free(list->head);

    list->head = tmp;

    return true;
}

void freeNodes(ListNode *head){
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
