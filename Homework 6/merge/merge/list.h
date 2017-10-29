#pragma once

struct ListElement
{
	char name[100];
	char phone[20];
	ListElement* next;
};

struct List
{
	ListElement *head;
};

//������� ������
List *createList();

//������� ������ list ��� ������� number
ListElement* elementNumber(List *list, int number);

//��������� ����� ������� � ����� ������
void newElement(List* input, char name[100], char phone[20]);

//���������� ��������� � ������
int countElement(List *list);

//�� ����� �������� � ������ output ��� ������� outputLast ������������ ������ �������� �� ������ input ��� ������� inputNew
void replace(List *output, int outputLast, List *input, int inputNew);

//������� ������
void deleteList(List *list);

