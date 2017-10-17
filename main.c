//
// Created by Fabian Terhorst on 11.10.17.
//

#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"
#include "single_linked_list_tests.h"
#include <limits.h>

struct MenuItem {
    char* name;

    void (* fct)(struct Node*);
};

bool running = true;

void initMenuItem(struct MenuItem* menuItem, char* name, void(* fct)(struct Node*)) {
    menuItem->name = name;
    menuItem->fct = fct;
}

void printMenu(struct MenuItem menu[4]) {
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, menu[i].name);
    }
    printf("Bitte geben Sie die Ziffer der gewuenschten Funktion ein:\n");
}

void add(struct Node* singleLinkedList) {
    printf("Bitte geben Sie eine Zahl ein\n");
    char keyString[256];
    scanf("%s", keyString);
    char* endP = NULL;
    int key = (int) strtol(keyString, &endP, 10);
    if (endP == keyString) {
        printf("%s ist keine valide Zahl\n", keyString);
        return;
    }
    single_linked_list_insert(singleLinkedList, key);
    printf("%d erfolgreich hinzugefügt.\n", key);
}

void delete(struct Node* singleLinkedList) {
    printf("Bitte geben Sie die zu löschene Zahl ein\n");
    char keyString[256];
    scanf("%s", keyString);
    char* endP = NULL;
    int key = (int) strtol(keyString, &endP, 10);
    if (endP == keyString) {
        printf("%s ist keine valide Zahl\n", keyString);
        return;
    }
    if (single_linked_list_delete(singleLinkedList, key)) {
        printf("%d gelöscht.\n", key);
    } else {
        printf("%d konnte nicht gefunden werden.\n", key);
    }
}

void print(struct Node* singleLinkedList) {
    single_linked_list_print(singleLinkedList);
}

void close(struct Node* singleLinkedList) {
    running = false;
}

int main() {

    runTests();

    struct MenuItem menuItemCreate;
    initMenuItem(&menuItemCreate, "Sortiertes Einfuegen eines Elementes", &add);

    struct MenuItem menuItemDelete;
    initMenuItem(&menuItemDelete, "Loeschen und Ausgeben des Elementes mit Schluessel key", &delete);

    struct MenuItem menuItemPrint;
    initMenuItem(&menuItemPrint, "Ausgeben der Liste", &print);

    struct MenuItem menuItemExit;
    initMenuItem(&menuItemExit, "Beenden des Programms", &close);

    struct MenuItem menuItems[4] = {menuItemCreate, menuItemDelete, menuItemPrint, menuItemExit};

    struct Node* singleLinkedList = single_linked_list_init();

    long menuIndex;
    char menuIndexString[256];
    char* endP;
    int base = 0;
    while (running) {
        printMenu(menuItems);
        scanf("%s", menuIndexString);
        menuIndex = strtol(menuIndexString, &endP, base);
        if (menuIndex > 4 || menuIndex < 1) {
            printf("Bitte geben Sie eine Zahl zwischen 1 und 4 ein\n");
            continue;
        }
        menuItems[--menuIndex].fct(singleLinkedList);
    }

    single_linked_list_deinit(singleLinkedList);
    return 0;
}
