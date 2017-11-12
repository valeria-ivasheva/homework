#pragma once

struct ListElement;

struct List;

// ������� ������ ������
List* createList();

// ��������� ������� value � ������
void insert(List *list, std::string element);

bool isIncludeList(List* list, std::string element);

// ���������� ��������� � ������
int sizeList(List* list);

// ������� ���� ������
void printList(List *list);

// ������� ������
void deleteList(List *list);