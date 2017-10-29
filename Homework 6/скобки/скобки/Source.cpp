#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

bool checkSymbol(char symbolA, char symbolB)
{
	return ((symbolB == '(' && symbolA == ')') || (symbolB == '{' && symbolA == '}') || (symbolB == '[' && symbolA == ']'));
}

int main()
{
	char string[100] = "";
	cout << "Write a string" << endl;
	cin >> string;
	Stack *stack = createStack();
	int length = strlen(string);
	bool result = true;
	for (int i = 0; i < length; ++i)
	{
		if (string[i] == '}' || string[i] == ')' || string[i] == ']')
		{
			if (!isEmpty(stack))
			{
				result = checkSymbol(string[i], pop(stack));
			}
			else
			{
				result = false;
			}
		}
		else
		{
			push(string[i], stack);
		}
		if (!result)
		{
			break;
		}
	}
	result = isEmpty(stack) && result;
	if (result)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	delete stack;
	return 0;
}