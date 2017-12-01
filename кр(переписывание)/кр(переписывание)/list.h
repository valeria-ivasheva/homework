#pragma once

struct List;

struct ListElement;

// ������� ������ ������
List* createList();

// ��������� ������� value � ������
void insert(List *list, int key, int value);

// ������� ������� value �� ������
void deleteElement(List *list, int key);

// ������� ���� ������
void printList(List *list);

// ������� ������
void deleteList(List *list);
