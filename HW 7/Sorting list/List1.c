#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct Node {
	int value;
	Node* next;
};

struct List {
	Node* head = NULL;
};

List* createList() {
	return new List;
}

bool isEmpty(List* list) {
	return list->head == NULL;
}

void addValue(List* list, int value) {
	Node* current = list->head;
	Node* previous = NULL;
	while (current != NULL && current->value < value) {
		previous = current;
		current = current->next;
	}
	Node* newNode = new Node{ value, current };
	if (previous == NULL) {
		list->head = newNode;
	}
	else {
		previous->next = newNode;
	}
}

bool deleteValue(List* list, int value) {
	Node* current = list->head;
	Node* previous = NULL;
	while (current != NULL && current->value != value) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		return false;
	}
	Node* temp = current->next;
	free (current);
	if (previous == NULL) {
		list->head = temp;
	}
	else {
		previous->next = temp;
	}
	return true;
}

void printList(List* list) {
	Node* current = list->head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
}

bool checkSortedList(List* list) {
	if (!isEmpty(list)) {
		Node* current = list->head->next;
		Node* previous = list->head;
		while (current != NULL) {
			if (current->value < previous->value) {
				return false;
			}
			previous = current;
			current = current->next;
		}
	}
	return true;
}

void deleteList(List* list) {
	while (!isEmpty(list)) {
		Node* temp = list->head->next;
		free (list->head);
		list->head = temp;
	}
	free (list);
}