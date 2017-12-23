#include "list.h"
#include <string.h>
#include <string>

using namespace std;

bool compareKeys(ListElement *simileLeft, ListElement *simileRight, int k)
{
	if (k == 1)
	{
		string nameRight = returnName(simileRight);
		string nameLeft = returnName(simileLeft);
		return strcmp(nameLeft.c_str(), nameRight.c_str()) < 0;
	}
	string phoneRight = returnPhone(simileRight);
	string phoneLeft = returnPhone(simileLeft);
	return strcmp(phoneLeft.c_str(), phoneRight.c_str()) < 0;
}

void  mergeSort(int key, List *input, int left, int right)
{
	if (left == right)
	{
		return;
	}
	if (right - 1 == left)
	{
		if (!compareKeys(elementNumber(input, left), elementNumber(input, right), key))
		{
			List * tempList = createList();
			string nameLeft = returnName(elementNumber(input, left));
			string nameRight = returnName(elementNumber(input, right));
			string phoneLeft = returnPhone(elementNumber(input, left));
			newElement(tempList, nameLeft, phoneLeft);
			string phoneRight = returnPhone(elementNumber(input, right));
			newElement(tempList, nameRight, phoneRight);
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
	ListElement *leftElement = {};
	ListElement *rightElement{};
	while (cursorLeft + left <= middle && right - cursorRight > middle)
	{
		leftElement = elementNumber(input, cursorLeft + left);
		rightElement = elementNumber(input, middle + 1 + cursorRight);
		if (compareKeys(leftElement, rightElement, key))
		{
			string name = returnName(leftElement);
			string phone = returnPhone(leftElement);
			newElement(output, name, phone);
			cursorLeft++;
		}
		else
		{
			string name = returnName(rightElement);
			string phone = returnPhone(rightElement);
			newElement(output, name, phone);
			cursorRight++;
		}
	}
	for (; cursorLeft + left <= middle; cursorLeft++)
	{
		string name = returnName(leftElement);
		string phone = returnPhone(leftElement);
		ListElement *leftElement = elementNumber(input, cursorLeft + left);
		newElement(output, name, phone);
	}
	for (; cursorRight + middle + 1 <= right; cursorRight++)
	{
		string name = returnName(rightElement);
		string phone = returnPhone(rightElement);
		ListElement * rightElement = elementNumber(input, middle + 1 + cursorRight);
		newElement(output, name, phone);
	}
	for (int i = 1; i <= cursorLeft + cursorRight; i++)
	{
		replace(input, left + i - 1, output, i);
		elementNumber(input, 2);
	}
	deleteList(output);
}
