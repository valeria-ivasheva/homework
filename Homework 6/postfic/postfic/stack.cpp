#include "stack.h"

struct StackElement
{
	int value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

Stack *createStack()
{
	return new Stack{};
}

void push(int value, Stack *stack)
{
	StackElement *newElement = new StackElement{value, stack->head};
	stack->head = newElement;
}

int pop(Stack *stack)
{
	if (!isEmpty(stack))
	{
		int val = stack->head->value;
		StackElement *newHead = stack->head->next;
		delete stack->head;
		stack->head = newHead;
		return val;
	}
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
