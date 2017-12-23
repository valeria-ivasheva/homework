#include "list.h"
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

struct ListElement
{
	string name;
	string phone;
	ListElement* next;
};

struct List
{
	ListElement *head;
};

List * createList()
{
	return new List{};
}

ListElement *elementNumber(List *list, int number)
{
	if (list->head == nullptr)
	{
		return 0;
	}
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
	for (int i = 0; i < lastElement->name.length(); i++)
	{
		lastElement->name[i] = 0;
	}
	for (int i = 0; i < lastElement->phone.length(); i++)
	{
		lastElement->phone[i] = 0;
	}
	for (int i = 0; i < newElement->name.length(); i++)
	{
		lastElement->name[i] = newElement->name[i];
	}
	for (int i = 0; i < newElement->phone.length(); i++)
	{
		lastElement->phone[i] = newElement->phone[i];
	}
	return;
}

void newElement(List* input, const string &name, const string &phone)
{
	ListElement *temp = new ListElement{};
	temp->name = name;
	temp->phone = phone;
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

string returnName(ListElement *element)
{
	string str = element->name;
	return str;
}

string returnPhone(ListElement *element)
{
	string str = element->phone;
	return str;
}