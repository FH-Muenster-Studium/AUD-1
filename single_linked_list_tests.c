//
// Created by Fabian Terhorst on 12.10.17.
//

#include "single_linked_list_tests.h"

#include "single_linked_list.h"

#include <stdlib.h>

#include <assert.h>

#include <limits.h>

bool contains(struct Node* singleLinkedList, int key) {
    while (singleLinkedList != NULL) {
        if (singleLinkedList->key == key) return true;
        singleLinkedList = singleLinkedList->next;
    }
    return false;
}

int index(struct Node* singleLinkedList, int key) {
    int i = 0;
    while (singleLinkedList != NULL) {
        if (singleLinkedList->key == key) return i;
        singleLinkedList = singleLinkedList->next;
        i++;
    }
    return -1;
}

void runTests() {
    struct Node* singleLinkedList = single_linked_list_init();

    // Should be empty after init
    assert(single_linked_list_is_empty(singleLinkedList));

    single_linked_list_insert(singleLinkedList, 12);

    // Test if 12 got added successfully
    assert(contains(singleLinkedList, 12));
    // And list should not be empty again
    assert(!single_linked_list_is_empty(singleLinkedList));

    single_linked_list_delete(singleLinkedList, 12);

    // Test if 12 got deleted
    assert(!contains(singleLinkedList, 12));
    // And list should be empty again
    assert(single_linked_list_is_empty(singleLinkedList));

    single_linked_list_insert(singleLinkedList, 42);
    single_linked_list_insert(singleLinkedList, 31337);
    single_linked_list_insert(singleLinkedList, 1337);

    // Test if all inserted elements are inside
    assert(contains(singleLinkedList, 42));
    assert(contains(singleLinkedList, 31337));
    assert(contains(singleLinkedList, 1337));

    single_linked_list_delete(singleLinkedList, 42);

    // Test if after deletion the other elements are still present
    assert(!contains(singleLinkedList, 42));
    assert(contains(singleLinkedList, 31337));
    assert(contains(singleLinkedList, 1337));

    // Cleanup
    single_linked_list_delete(singleLinkedList, 31337);
    single_linked_list_delete(singleLinkedList, 1337);

    // Should be empty now
    assert(single_linked_list_is_empty(singleLinkedList));

    single_linked_list_insert(singleLinkedList, 10 * 10);
    single_linked_list_insert(singleLinkedList, 10 * 1);
    single_linked_list_insert(singleLinkedList, 10 * 1000);
    single_linked_list_insert(singleLinkedList, 10 * 100);

    // Check if sorting works
    assert(index(singleLinkedList, 10) == 1);
    assert(index(singleLinkedList, 10 * 10) == 2);
    assert(index(singleLinkedList, 10 * 100) == 3);
    assert(index(singleLinkedList, 10 * 1000) == 4);

    // Check if deletion from invalid key is working
    assert(!single_linked_list_delete(singleLinkedList, INT_MIN));

    single_linked_list_deinit(singleLinkedList);
}
