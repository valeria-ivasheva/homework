#include "stack.h"
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int arifmarithmetic(char symbol, int a, int b)
{
	int result = 0;
	switch (symbol)
	{
	case '-':
	{
		result = a - b;
		break;
	}
	case '+':
	{
		result = a + b;
		break;
	}
	case '*':
	{
		result = a * b;
		break;
	}
	case '/':
	{
		result = a / b;
		break;
	}
	}
	return result;
}

int main()
{
	Stack *stack = createStack();
	char string[100] = "";
	setlocale(LC_ALL, "Russian");
	cout << "Что нам нужно посчитать?\n";
	fgets(string, 100, stdin);
	int length = strlen(string);
	for (int i = 0; i < length - 1; ++i)
	{
		if (string[i] != ' ')
		{
			if (isdigit(string[i]))
			{
				push(string[i] - 48, stack);
			}
			else
			{
				int b = pop(stack);
				int a = pop(stack);
				if (string[i] == '/' && b == 0)
				{
					cout << "Division by zero\n";
					return -1;
				}
				int result = arifmarithmetic(string[i], a, b);
				push(result, stack);
			}
		}
	}
	if (!isEmpty(stack))
	{
		cout << pop(stack);
	}
	delete stack;
	return 0;
}