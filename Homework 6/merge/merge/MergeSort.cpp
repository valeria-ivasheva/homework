#include "list.h"
#include <string.h>

using namespace std;

bool simileKey(ListElement *simileLeft, ListElement *simileRight, int k)
{
	if (k == 1)
	{
		return strcmp(simileLeft->name, simileRight->name) < 0;
	}
	return strcmp(simileLeft->phone, simileRight->phone) < 0;
}

void  mergeSort(int key, List *input, int left, int right)
{
	if (left == right)
	{
		return;
	}
	if (right - 1 == left)
	{
		if (!simileKey(elementNumber(input,left),elementNumber(input, right), key))
		{
			List * tempList = createList();
			newElement(tempList, elementNumber(input, left)->name, elementNumber(input, left)->phone);
			newElement(tempList, elementNumber(input, right)->name, elementNumber(input, right)->phone);
			replace(input, left, tempList, 2);
			replace(input, right, tempList, 1);
			deleteList(tempList);
		}
	}
	int middle = (left + right) / 2;
	mergeSort(key, input, left, middle);
	mergeSort(key, input, middle + 1, right);
	List *output = createList();
	int cursorLeft = 0;
	int cursorRight = 0;
	while (cursorLeft + left <= middle && right - cursorRight > middle)
	{
		ListElement *leftElement = elementNumber(input, cursorLeft + left);
		ListElement *rightElement = elementNumber(input, middle + 1 + cursorRight);
		if (simileKey(leftElement, rightElement, key))
		{
			newElement(output, leftElement->name, leftElement->phone);
			cursorLeft++;
		}
		else
		{
			newElement(output, rightElement->name, rightElement->phone);
			cursorRight++;
		}
	}
	for (cursorLeft;cursorLeft + left <= middle; cursorLeft++)
	{
		ListElement *leftElement = elementNumber(input, cursorLeft + left);
		newElement(output, leftElement->name, leftElement->phone);
	}
	for (cursorRight;cursorRight + middle + 1 <= right; cursorRight++)
	{
		ListElement * rightElement = elementNumber(input, middle + 1 + cursorRight);
		newElement(output, rightElement->name, rightElement->phone);
	}
	for (int i = 1; i <= cursorLeft + cursorRight; i++)
	{
		replace(input, left + i - 1,output, i);
		input->head->next;
	}
	delete output;
	return;
}
