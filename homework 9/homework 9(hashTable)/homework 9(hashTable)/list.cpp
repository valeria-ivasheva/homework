#include "list.h"
#include <iostream>
#include <string>
using namespace std;

struct ListElement
{
	string word;
	int count;
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

bool isIncludeList(List* list, std::string element)
{
	if (list->head == nullptr)
	{
		return false;
	}
	ListElement* nowElement = list->head;
	while (nowElement->next != nullptr && element.compare(nowElement->word) != 0)
	{
		nowElement = nowElement->next;
	}
	return element.compare(nowElement->word) == 0;
}


void insert(List *list, string element)
{
	if (!isIncludeList(list, element))
	{
		ListElement *newElement = new ListElement{ element, 1, list->head };
		list->head = newElement;
	}
	else
	{
		ListElement *temp = list->head;
		while (temp->word.compare(element) != 0)
		{
			temp = temp->next;
		}
		temp->count++;
	}
}

void deleteElementList(List* list, std::string element)
{
	if (isIncludeList(list, element))
	{
		return;
	}
	ListElement *temp = list->head;
	if (temp->word.compare(element) == 0)
	{
		list->head = temp->next;
		delete temp;
		return;
	}
	while (temp->next->word.compare(element) != 0)
	{
		temp = temp->next;
	}
	ListElement *delListElement = temp->next;
	temp->next = delListElement->next;
	delete delListElement;
	return;
}

void printList(List *list)
{
	ListElement *temp = list->head;
	while (temp != nullptr)
	{
		std::cout << temp->word << " " << temp->count << "\n";
		temp = temp->next;
	}
}

int sizeList(List* list)
{
	if (list->head == nullptr)
	{
		return 0;
	}
	ListElement* nowElement = list->head;
	int result = 1;
	while (nowElement->next != nullptr)
	{
		nowElement = nowElement->next;
		result++;
	}
	return result;
}
