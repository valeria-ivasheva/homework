#include "cyclicList.h"
#include <iostream>

List * createCyclicList()
{
	return new List{};
}

void deleteList(List * list)
{
	if (list->head == nullptr)
	{
		delete list;
	}
	else
	{
		ListElement *lastElement = list->head;
		while (list->head != lastElement->next)
		{
			lastElement = lastElement->next;
		}
		lastElement->next = nullptr;
		while (!list->head)
		{
			ListElement *nowElement = list->head;
			list->head = nowElement->next;
			delete nowElement;
		}
		delete list;
	}
}

List * fillList(List * list, int n)
{
	ListElement* newElement = new ListElement{ 1, nullptr };
	list->head = newElement;
	ListElement *previous = list->head;
	for (int i = 2; i <= n; ++i)
	{
		newElement = new ListElement{ i, nullptr };
		previous->next = newElement;
		previous = newElement;
	}
	previous->next = list->head;
	return list;
}

ListElement* deleteElement(List *list, ListElement *start, int m)
{
	if (m == 1)
	{
		ListElement *lastElement = start;
		while (lastElement->next != list->head)
		{
			lastElement = lastElement->next;
		}
		list->head = start->next;
		lastElement->next = start->next;
		delete start;
		return list->head;
	}
	ListElement *previous = start;
	for (int i = 1; i < m - 1; ++i)
	{
		previous = previous->next;
	}
	ListElement *nowElement = previous->next;
	previous->next = nowElement->next;
	if (nowElement == list->head)
	{
		list->head = nowElement->next;
	}
	delete nowElement;
	return previous->next;
}

int countElement(List * list)
{
	if (list->head == nullptr)
	{
		return 0;
	}
	int count = 1;
	ListElement *nowElement = list->head;
	while (nowElement->next != list->head)
	{
		count++;
		nowElement = nowElement->next;
	}
	return count;
}

void printList(List * list)
{
	ListElement *nowElement = list->head;
	while (list->head != nowElement->next)
	{
		printf("%d%s", nowElement->number, " ");
		nowElement = nowElement->next;
	}
	printf("%d%s", nowElement->number, " ");
}
