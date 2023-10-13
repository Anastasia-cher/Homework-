﻿#pragma once

// Список
struct List;

// Создание списка;
// функция возвращает указатель на список.
List* createList();

// Проверка списка на пустоту;
// функция принимает указатель на список.
bool isEmpty(List* list);

// Добавление значения в сортированный список;
// функция принимает указатель на список, значение элемента.
void addValue(List* list, int value);

// Удалние значения из списка;
// функция принимает указатель на список, значение элемента.
bool deleteValue(List* list, int value);

// Печать списка;
// функция принимает указатель на список.
void printList(List* list);

// Размер списка
// функция принимает указатель на список
int sizeList(List* list);

// Проверка списка на сортированность;
// функция принимает указатель на список.
bool checkSortedList(List* list);

// Удаление списка;
// функция принимает указатель на список.
void deleteList(List* list);