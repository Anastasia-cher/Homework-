#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LIST2.h"

typedef struct Node {
    char* word;
    int frequency;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

void printList(List* List) {
    Node* temp = List->head;
    if (temp == NULL) {
        printf("The list is empty!\n");
        return;
    }
    printf("The list is: ");
    while (temp->next != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("%s ", temp->word);
    printf("\n");
}

void listInsertBeginning(char* word, List* List) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->word = word;
    temp->frequency = 1;
    temp->next = NULL;
    if (List->head != NULL) {
        temp->next = List->head;
        List->head = temp;
    }
    else {
        List->head = temp;
    }
}

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

int getFrequency(List* List) {
    return List->head->frequency;
}

bool isEmpty(List* List) {
    return List == NULL;
}

const char* getWord(List* List) {
    return List->head->word;
}

bool listTraverse(List* List) {
    if (List->head->next == NULL) {
        return true;
    }
    List->head = List->head->next;
    return false;
}

bool isInTheList(List* list, char* word) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void incrementFrequency(List* List, char* word) {
    Node* temp = List->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            temp->frequency++;
            return;
        }
    }
}

void conveyFrequency(List* List, char* word, int newFrequency) {
    Node* temp = List->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            temp->frequency = newFrequency;
            return;
        }
    }
}

int listLength(List* List) {
    if (List == NULL) {
        return 0;
    }
    Node* temp = List->head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}