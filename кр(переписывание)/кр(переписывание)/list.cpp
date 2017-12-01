#include "list.h"
#include <iostream>

struct ListElement
{
	int value;
	ListElement* previsious;
	ListElement* next;
};

struct List
{
	ListElement *head;
};

List* createList()
{
	return new List{};
}

ListElement* listIndex(List* list, int key)
{
	if (list->head == nullptr)
	{
		return nullptr;
	}
	int i = 0;
	ListElement* result = list->head;
	while (i != key)
	{
		i++;
		result = result->next;
	}
	return result;
}

void insert(List *list, int key, int value)
{
	ListElement* newElement = new ListElement{ value, nullptr, nullptr };
	if (list->head == nullptr || key == 0)
	{
		newElement->next = list->head;
		list->head = newElement;
		if (newElement->next != nullptr)
		{
			newElement->next->previsious = newElement;
		}
	}
	else
	{
		ListElement *listPrev = listIndex(list, key - 1);
		ListElement *listNext = listIndex(list, key);
		newElement->previsious = listPrev;
		newElement->next = listNext;
		listPrev->next = newElement;
		if (listNext != nullptr)
		{
			listNext->previsious = newElement;
		}
	}
}

void deleteElement(List *list, int key)
{
	ListElement* deleteNow = listIndex(list, key);
	if (key == 0)
	{
		list->head = deleteNow->next;
		return;
	}
	if (deleteNow->next != nullptr)
	{
		deleteNow->next->previsious = deleteNow->previsious;
	}
	deleteNow->previsious->next = deleteNow->next;
	delete deleteNow;
}

void printList(List *list)
{
	ListElement *temp = list->head;
	if (temp == nullptr)
	{
		printf("%s\n", "Список пустой");
		return;
	}
	while (temp != nullptr)
	{
		printf("%d%s", temp->value, " ");
		temp = temp->next;
	}
	std::cout << "\n";
}

void deleteList(List *list)
{	
	while (list->head != nullptr)
	{
		ListElement *nowDelete = list->head;
		list->head = nowDelete->next;
		if (nowDelete->next->previsious != nullptr)
		{
			nowDelete->next->previsious = nullptr;
		}
		delete nowDelete;
	}
	delete list;
}
