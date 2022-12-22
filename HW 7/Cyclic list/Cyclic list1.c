#include "Cyclic list.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    Node* next;
}Node;

typedef struct List {
    Node* head = NULL;
    Node* tail = NULL;
}List;

List* createList(int* errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    List* list = malloc(sizeof(List));
    if (list == NULL) {
        if (errorCode != NULL) {
            *errorCode = -1;
        }
        return;
    }
    return list;
}

bool isEmpty(List* list) {
    return list->head == NULL;
}

bool onlyHeadInList(List* list) {
    return list->head == list->tail;
}

int headValue(List* list) {
    return list->head->value;
}

void addValue(List* list, int value) {
    if (isEmpty(list)) {
        list->head = new Node{ value, NULL };
        list->head->next = list->head;
        list->tail = list->head;
    }
    else {
        list->tail->next = new Node{ value, list->head };
        list->tail = list->tail->next;
    }
}

void deleteValue(List* list, int positionNumber) {
    Node* current = list->head;
    Node* previous = list->tail;
    for (int i = 1; i < positionNumber; ++i) {
        previous = current;
        current = current->next;
    }
    list->head = current->next;
    list->tail = previous;
    previous->next = current->next;
    free (current);
}

void deleteList(List* list) {
    while (list->head != list->tail) {
        deleteValue(list, 1);
    }
    free (list->head);
    free (list);
}