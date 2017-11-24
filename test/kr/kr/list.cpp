#include "list.h"
#include <iostream>

struct ListElement
{
	int value;
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

void deleteList(List *list)
{
	if (list->head != nullptr)
	{
		while (!list->head)
		{
			ListElement *nowDelete = list->head;
			list->head = nowDelete->next;
			delete nowDelete;
		}
	}
	delete list;
}

int countElementList(List* list)
{
	int result = 1;
	if (list->head == nullptr)
	{
		return 0;
	}
	ListElement* temp = list->head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		result++;
	}
	return result;
}

ListElement* listIndex(List* list, int key)
{
	if (list->head == nullptr)
	{
		return nullptr;
	}
	int i = 1;
	ListElement* result = list->head;
	while (i != key)
	{
		i++;
		result = result->next;
	}
	return result;
}



void insert(List *list, int number)
{
	if ((list->head == nullptr))
	{
		ListElement *newElement = new ListElement{ number, list->head };
		list->head = newElement;
	}
	else
	{
		ListElement* newElement = new ListElement{ number, nullptr };
		ListElement *temp = listIndex(list, countElementList(list));
		temp->next = newElement;
	}
}

void printList(List *list)
{
	ListElement *temp = list->head;
	if (temp == nullptr)
	{
		printf("%s\n", "Список пустой");
	}
	while (temp != nullptr)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

void deleteElement(List *list, int number)
{
	ListElement *temp = list->head;
	if (temp != nullptr)
	{
		if (temp->value == number)
		{
			list->head = temp->next;
			delete temp;
			return;
		}
		while ((temp->next != nullptr) && (temp->next->value != number))
		{
			temp = temp->next;
		}
		if (temp->next != nullptr)
		{
			ListElement *nowDelete = temp->next;
			temp->next = nowDelete->next;
			delete nowDelete;
		}
	}
}

bool isSymmetry(List* list)
{
	int count = countElementList(list);
	int i = 1;
	while (i*2 <= count && listIndex(list, i)->value == listIndex(list, count - i + 1)->value)
	{

		i++;
	}
	return i * 2 >= count;
}