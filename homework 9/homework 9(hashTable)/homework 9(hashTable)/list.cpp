#include "list.h"
#include <iostream>

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

void insert(List *list, int number)
{
	if ((list->head == nullptr) || (list->head->value > number))
	{
		ListElement *newElement = new ListElement{ number, list->head };
		list->head = newElement;
	}
	else
	{
		ListElement *temp = list->head;
		while ((temp->next != nullptr) && temp->next->value < number)
		{
			temp = temp->next;
		}
		ListElement *newElement = new ListElement{ number, temp->next };
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
