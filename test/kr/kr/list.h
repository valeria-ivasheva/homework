#pragma once

struct ListElement;

struct List;

// ������� ������ ������
List* createList();

// ��������� ������� value � ������
void insert(List *list, int value);

// ������� ������� value �� ������
void deleteElement(List *list, int value);

// ������� ���� ������
void printList(List *list);

// ������� ������
void deleteList(List *list);

//�������� �� ���������
bool isSymmetry(List* list);