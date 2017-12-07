#pragma once

struct ListElement;

struct List;

// ������� ������ ������
List* createList();

// ��������� ������� value � ������
void insert(List *list, char key, int value);

// ������� ������� value �� ������
//void deleteElement(List *list, char key);

//
bool haveElement(List* list, char key);

// 
int numberOfJump(List* list, char key);

// ������� ���� ������
void printList(List *list);

// ������� ������
void deleteList(List *list);

//�������� �� ���������
bool isSymmetry(List* list);