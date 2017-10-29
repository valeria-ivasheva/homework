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

//Создать список
List *createList();

//Элемент списка list под номером number
ListElement* elementNumber(List *list, int number);

//Добавляет новый элемент в конец списка
void newElement(List* input, char name[100], char phone[20]);

//Количество элементов в списке
int countElement(List *list);

//На место элемента в списке output под номером outputLast записываются данные элемента из списка input под номером inputNew
void replace(List *output, int outputLast, List *input, int inputNew);

//Удалить список
void deleteList(List *list);

