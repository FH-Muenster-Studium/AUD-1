//
// Created by Fabian Terhorst on 11.10.17.
//

#include "single_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Node* createNode(int key, struct Node* next) {
    struct Node* node = malloc(sizeof(struct Node));
    node->key = key;
    node->next = next;
    return node;
}

struct Node* single_linked_list_init() {
    return createNode(INT_MIN, NULL);
}

void single_linked_list_deinit(struct Node* singleLinkedList) {
    struct Node* oldNext;
    while (singleLinkedList != NULL) {
        oldNext = singleLinkedList->next;
        free(singleLinkedList);
        singleLinkedList = oldNext;
    }
}

bool isInvalidKey(int key) {
    return key == INT_MIN;
}

//Todo: check if *singleLinkedList is same as the one that is getting replaced
void single_linked_list_insert(struct Node** singleLinkedList, int key) {
    if (isInvalidKey(key)) {
        printf("Bitte geben Sie eine valide Zahl ein\n");
        return;
    }
    struct Node* linkedList = *singleLinkedList;
    struct Node* prev = linkedList;
    while (linkedList != NULL) {
        if (key < linkedList->key) {
            prev->next = createNode(key, prev->next);
            break;
        } else if (linkedList->next == NULL) {
            linkedList->next = createNode(key, NULL);
            break;
        }
        prev = linkedList;
        linkedList = linkedList->next;
    }
}

//Todo: check if *singleLinkedList is same as the one that is getting deleted
bool single_linked_list_delete(struct Node** singleLinkedList, int key) {
    if (isInvalidKey(key)) {
        printf("Bitte geben Sie eine valide Zahl ein\n");
        return false;
    }
    struct Node* linkedList = *singleLinkedList;
    struct Node* prev = linkedList;
    while (linkedList != NULL) {
        if (linkedList->key == key) {
            prev->next = linkedList->next;
            free(linkedList);
            return true;
        }
        prev = linkedList;
        linkedList = linkedList->next;
    }
    return false;
}

bool single_linked_list_is_empty(struct Node* singleLinkedList) {
    return singleLinkedList == NULL;
}

void single_linked_list_print(struct Node* singleLinkedList) {
    //Skip list element
    singleLinkedList = singleLinkedList->next;
    int i = 1;
    while (singleLinkedList != NULL) {
        printf("%d=%d\n", i++, singleLinkedList->key);
        singleLinkedList = singleLinkedList->next;
    }
    if (i == 1) {
        printf("Die Liste ist leer\n");
    }
}
