#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree tree;

Tree* createTree();
// �������� ������
// ������� ���������� ��������� �� ������.

void addValue(Tree* tree, int key, char* value);
// ������� ��������� �������� � ������

char* getValue(Tree* tree, int key);
// ������� ���������� ����� �������� �� �����

bool contains(Tree* tree, int key);
// �������� ������� �����

void deleteValue(Tree* tree, int key);
// �������� �������� �� �����

void deleteTree(Tree* tree);
// �������� ������