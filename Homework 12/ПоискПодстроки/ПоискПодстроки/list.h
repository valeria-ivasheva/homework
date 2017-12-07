#pragma once

struct ListElement;

struct List;

// ������� ������ ������
List* createList();

// ��������� ������� value � ������
void insert(List *list, char key, int value);

//�������� ������������� �������� � ������
bool haveElement(List* list, char key);

// ���������� ������ ��� �������( �������� ������-����-��������)
int numberOfJump(List* list, char key);

// ������� ���� ������
void printList(List *list);

// ������� ������
void deleteList(List *list);