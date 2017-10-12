//
// Created by Fabian Terhorst on 11.10.17.
//

#include "single_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

#include <limits.h>

//Todo: move next = null to the end

//Todo: doppelt verkettete
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

void single_linked_list_insert(struct Node* singleLinkedList, int key) {
    if (isInvalidKey(key)) {
        printf("Bitte geben Sie eine valide Zahl ein\n");
        return;
    }
    struct Node* prev = singleLinkedList;
    while (singleLinkedList != NULL) {
        if (key < singleLinkedList->key) {
            prev->next = createNode(key, prev->next);
            break;
        } else if (singleLinkedList->next == NULL) {
            singleLinkedList->next = createNode(key, NULL);
            break;
        }
        prev = singleLinkedList;
        singleLinkedList = singleLinkedList->next;
    }
}

bool single_linked_list_delete(struct Node* singleLinkedList, int key) {
    if (isInvalidKey(key)) {
        printf("Bitte geben Sie eine valide Zahl ein\n");
        return false;
    }
    struct Node* prev = singleLinkedList;
    while (singleLinkedList != NULL) {
        if (singleLinkedList->key == key) {
            prev->next = singleLinkedList->next;
            free(singleLinkedList);
            return true;
        }
        prev = singleLinkedList;
        singleLinkedList = singleLinkedList->next;
    }
    return false;
}

bool single_linked_list_is_empty(struct Node* singleLinkedList) {
    return singleLinkedList->next == NULL;
}

void single_linked_list_print(struct Node* singleLinkedList) {
    //Skip list element
    singleLinkedList = singleLinkedList->next;
    if (singleLinkedList == NULL) {
        printf("Liste ist leer\n");
    }
    int i = 1;
    while (singleLinkedList != NULL) {
        printf("%d=%d\n", i++, singleLinkedList->key);
        singleLinkedList = singleLinkedList->next;
    }
}
