//
// Created by Fabian Terhorst on 11.10.17.
//

#ifndef AUD_1_SINGLE_LINKED_LIST_H
#define AUD_1_SINGLE_LINKED_LIST_H

#include <stdbool.h>

struct Node {
    int key;
    struct Node* next;
};

struct Node* single_linked_list_init();

void single_linked_list_deinit(struct Node* singleLinkedList);

void single_linked_list_insert(struct Node* singleLinkedList, int key);

bool single_linked_list_delete(struct Node* singleLinkedList, int key);

bool single_linked_list_is_empty(struct Node* singleLinkedList);

void single_linked_list_print(struct Node* singleLinkedList);

#endif //AUD_1_SINGLE_LINKED_LIST_H
