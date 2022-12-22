#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//a wrapper for Node
typedef struct List List;

//function that creates a linked list
List* createList();

//inserts a new element to the beginning of the list
void listInsertBeginning(char* word, List* List);

//returns the value of the frequency field
int getFrequency(List* List);

//returns the value of the word field
const char* getWord(List* List);

//moves head forward by one element
bool listTraverse(List* List);

//cheeks to see if the word is in the list
bool isInTheList(List* List, char* word);

//increments a frequency by 1
void incrementFrequency(List* List, char* word);

//returns the length of the list
int listLength(List* List);

//sets "newFrequency" elements with the "word" field
void conveyFrequency(List* List, char* word, int newFrequency);

//checks to see if the head points to NULL
bool isEmpty(List* List);