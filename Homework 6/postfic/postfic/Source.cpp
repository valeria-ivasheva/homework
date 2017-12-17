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

void postfic(char symbol, Stack *stack)
{
	if (symbol != ' ')
	{
		if (isdigit(symbol))
		{
			push(symbol - 48, stack);
		}
		else
		{
			int a = 0; 
			int b = 0;
			if (!isEmpty(stack))
			{
				b = pop(stack);
			}
			else
			{
				cout << "Error input\n";
				return;
			}
			if (!isEmpty(stack))
			{
				a = pop(stack);
			}
			else
			{
				cout << "Error input\n";
				return;
			}
			if (symbol == '/' && b == 0)
			{
				cout << "Division by zero\n";
				return;
			}
			int result = arifmarithmetic(symbol, a, b);
			push(result, stack);
		}
	}
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
		postfic(string[i], stack);
	}
	if (!isEmpty(stack))
	{
		cout << "Это равно " << pop(stack) << endl;
	}
	deleteStack(stack);
	return 0;
}