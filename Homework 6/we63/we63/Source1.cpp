#include <iostream>
#include <cstdio>
#include <string.h>
#include "stack.h"

using namespace std;
int priority(char op)
{
	if (op == '(')
	{
		return 0;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	return 1;
}

bool isArithmetic(char symbol)
{
	return (symbol == '-' || symbol == '+' || symbol == '/' || symbol == '*');
}

void putSymbol(char output[], char symbol)
{
	int cursor = strlen(output);
	output[cursor] = ' ';
	cursor++;
	output[cursor] = symbol;
}

void closingBkt(Stack* stack, char output[])
{
	bool noMistake = true;
	while (noMistake && !isEmpty(stack))
	{
		char symbol = pop(stack);
		if (symbol != '(')
		{
			putSymbol(output, symbol);
		}
		else
		{
			noMistake = false;
		}
	}
	if (noMistake && isEmpty(stack))
	{
		cout << "Error input\n";
	}
}

void algSortStation(Stack *stack, char result[], char symbol)
{
	if (symbol == '(')
	{
		push('(', stack);
	}
	if (symbol == ')')
	{
		closingBkt(stack, result);
	}
	if (isdigit(symbol))
	{
		putSymbol(result, symbol);
	}
	if (isArithmetic(symbol))
	{
		if (!isEmpty(stack))
		{
			bool flag = true;
			char op2 = pop(stack);
			while (flag && priority(op2) >= priority(symbol))
			{
				putSymbol(result, op2);
				if (isEmpty(stack))
				{
					flag = false;
				}
				else
				{
					op2 = pop(stack);
				}
			}
			if (priority(op2) < priority(symbol))
			{
				push(op2, stack);
			}
		}
		push(symbol, stack);
	}
}

int main()
{
	Stack *stack = createStack();
	char string[100] = "";
	setlocale(LC_ALL, "Russian");
	cout << "Что нам нужно перевести?\n";
	fgets(string, 100, stdin);
	int length = strlen(string);
	char result[100] = "";
	int coursor = 0;
	for (int i = 0; i < length - 1; i++)
	{
		algSortStation(stack, result, string[i]);
	}
	while (!isEmpty(stack))
	{
		putSymbol(result, pop(stack));
	}
	cout << result << endl;
	deleteStack(stack);
	return 0;
}