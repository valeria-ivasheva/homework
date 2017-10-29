#pragma once

struct ListElement
{
	int number;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

//������� ����������� ������
List* createCyclicList();

//������� ������ 
void deleteList(List *list);

//��������� ������ ������� �� 1 �� n �� �������
List* fillList(List* list, int n);

// ������� m-��� ������� ����� start 
ListElement* deleteElement(List* list, ListElement *start, int m);

// ������� ���������� ��������
int countElement(List* list);

// ������� ���� ������
void printList(List* list);
