#include "stack.h"
#include <iostream>

using namespace std;

Stack *createStack()
{
	return new Stack{};
}

void push(char symbol, Stack *stack)
{
	StackElement *newElement = new StackElement{ symbol, stack->head };
	stack->head = newElement;
}

char pop(Stack *stack)
{
	if (!isEmpty(stack))
	{
		int val = stack->head->symbol;
		StackElement *newHead = stack->head->next;
		delete stack->head;
		stack->head = newHead;
		return val;
	}
	cout <<  "Error, stack is empty\n" << endl;
	return -1;
}

bool isEmpty(Stack *stack)
{
	return !stack->head;
}

void deleteStack(Stack *stack)
{
	while (!isEmpty(stack))
	{
		StackElement *nowElement = stack->head;
		stack->head = stack->head->next;
		delete nowElement;
	}
	delete stack;
}
