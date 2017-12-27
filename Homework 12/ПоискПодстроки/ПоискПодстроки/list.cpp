#include "list.h"
#include <iostream>

struct ListElement
{
	char key;
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
	while (list->head)
	{
		ListElement *nowDelete = list->head;
		list->head = nowDelete->next;
		delete nowDelete;
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
	int i = 0;
	ListElement* result = list->head;
	while (i != key)
	{
		i++;
		result = result->next;
	}
	return result;
}

void insert(List *list, char key, int value)
{
	if ((list->head == nullptr))
	{
		ListElement *newElement = new ListElement{ key, value, list->head };
		list->head = newElement;
	}
	else
	{
		ListElement* newElement = new ListElement{ key, value, nullptr };
		ListElement *temp = listIndex(list, countElementList(list) - 1);
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

bool haveElement(List* list, char key)
{
	int count = countElementList(list);
	int i = 0;
	bool result = false;
	while (!result && i < count)
	{
		result = listIndex(list, i)->key == key;
		i++;
	}
	return result;
}

int numberOfJump(List* list, char key)
{
	int i = 0;
	const int count = countElementList(list);
	while (listIndex(list, i)->key != key && i < count)
	{
		i++;
	}
	if (i == count)
	{
		i--;
	}
	return listIndex(list, i)->value;
}