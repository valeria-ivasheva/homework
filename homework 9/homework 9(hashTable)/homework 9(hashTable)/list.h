#pragma once

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement *head;
};

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