#include "../include/list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *listInit() {
    List *list = malloc(sizeof(List));
    memset(list, 0, sizeof(*list));
    if (list == NULL) {
        perror(__func__);
        exit(EXIT_FAILURE);
    }

    return list;
}

void printList(List *list){
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

bool listPush(List **list, int val){
    if(!list) return false;

    ListNode *node;
    node = malloc(sizeof(ListNode));

    node->val = val;
    List *listPtr = *list;
    node->next = listPtr->head;
    listPtr->head = node;

    (*list)->size++;

    return true;
}

bool listPop(List *list, int *out){
    if(list == NULL){
        fprintf(stderr, "List is NULL\n");
        return false;
    }

    if(list->head == NULL){
        fprintf(stderr, "Cannot pop from empty list\n");
        return false;
    }

    ListNode *tmp = list->head->next;
    *out = list->head->val;
    free(list->head);

    list->head = tmp;

    list->size--;

    return true;
}

void freeNodes(ListNode *head){
    if(!head) return;
    if(head->next) {
        freeNodes(head->next);
    }

    free(head);
}

void freeList(List *list){
    freeNodes(list->head);
    free(list);
}
