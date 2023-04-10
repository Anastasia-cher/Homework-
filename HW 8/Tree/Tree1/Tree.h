#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree tree;

Tree* createTree();
// Создание дерева
// функция возвращает указатель на дерево.

void addValue(Tree* tree, int key, char* value);
// Функция добавляет значение в дерево

char* getValue(Tree* tree, int key);
// Функция возвращает копию значения по ключу

bool contains(Tree* tree, int key);
// Проверка наличия ключа

void deleteValue(Tree* tree, int key);
// Удаление значения по ключу

void deleteTree(Tree* tree);
// Удаление дерева