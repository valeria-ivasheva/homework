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

//Создать циклический список
List* createCyclicList();

//Удалить список 
void deleteList(List *list);

//Заполнить список числами от 1 до n по порядку
List* fillList(List* list, int n);

// Удалить m-тый элемент после start 
ListElement* deleteElement(List* list, ListElement *start, int m);

// Подсчет количества элемента
int countElement(List* list);

// Вывести весь список
void printList(List* list);
