#include "list.h"
#include <string.h>
#include <iostream>

List * createList()
{
	return new List{};
}

ListElement *elementNumber(List *list, int number)
{
	int i = 1;
	ListElement *now = list->head;
	while (i != number && now->next != nullptr)
	{
		now = now->next;
		i++;
	}
	return now;
}

void replace(List *output, int outputLast, List *input, int inputNew)
{
	ListElement *newElement = elementNumber(input, inputNew);
	ListElement *lastElement = elementNumber(output, outputLast);
	for (int i = 0; i < strlen(lastElement->name); i++)
	{
		lastElement->name[i] = 0;
	}
	for (int i = 0; i < strlen(lastElement->phone); i++)
	{
		lastElement->phone[i] = 0;
	}
	for (int i = 0; i < strlen(newElement->name); i++)
	{
		lastElement->name[i] = newElement->name[i];
	}
	for (int i = 0; i < strlen(newElement->phone); i++)
	{
		lastElement->phone[i] = newElement->phone[i];
	}
	return;
}

void newElement(List* input, char name[100], char phone[20])
{
	ListElement *temp = new ListElement{};
	for (int i = 0; i < strlen(name); i++)
	{
		temp->name[i] = name[i];
	}
	for (int i = 0; i < strlen(phone); i++)
	{
		temp->phone[i] = phone[i];
	}
	if (countElement(input) == 0)
	{
		input->head = temp;
		return;
	}
	elementNumber(input, countElement(input))->next = temp;
	return;
}

void pushElementList(List * input, ListElement* element)
{
	if (input->head == nullptr)
	{
		input->head = element;
		return;
	}
	ListElement *now = input->head;
	while (now->next != nullptr)
	{
		now = now->next;
	}
	now->next = element;
	return;
}

int countElement(List * list)
{
	int count = 0;
	if (list->head != nullptr)
	{
		count++;
		ListElement *now = list->head;
		while (now->next != nullptr)
		{
			now = now->next;
			count++;
		}
	}
	return count;
}

void deleteList(List * list)
{
	while (list->head != nullptr)
	{
		ListElement *nowDelete = list->head;
		list->head = nowDelete->next;
		delete nowDelete;
	}
	delete list;
}