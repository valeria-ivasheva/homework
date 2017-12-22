#include "Stack.h"
#include <iostream>

struct StackElement
{
	int value;
	int key;
	StackElement* next;
};

struct Stack
{
	StackElement* head;
	int maxKey;
};

Stack* createStack()
{
	Stack* stack = new Stack{};
	stack->maxKey = -1;
	return stack;
}

void enqueue(Stack *stack, int key, int value)
{
	StackElement* newElement = new StackElement;
	newElement->key = key;
	newElement->value = value;
	newElement->next = stack->head;
	stack->head = newElement;
	if (key > stack->maxKey)
	{
		stack->maxKey = key;
	}
	return;
}

int maxKeyStack(Stack* stack)
{
	if (stack->head == nullptr)
	{
		return -1;
	}
	StackElement* now = stack->head;
	int result = now->key;
	while (now->next != nullptr)
	{
		if (now->key > result)
		{
			result = now->key;
		}
		now = now->next;
	}
	return result;
}

int dequeue(Stack *stack)
{
	int result = -1;
	if (stack->maxKey == -1)
	{
		return result;
	}
	StackElement* now = stack->head;
	StackElement* prev = {};
	while (now->key != stack->maxKey)
	{
		prev = now;
		now = now->next;
	}
	result = now->value;
	if (stack->head == now)
	{
		stack->head = now->next;
		delete now;
		stack->maxKey = maxKeyStack(stack);
		return result;
	}
	prev->next = now->next;
	now->next = nullptr;
	delete now;
	stack->maxKey = maxKeyStack(stack);
	return result;
}

void printStack(Stack *stack)
{
	StackElement* now = stack->head;
	if (stack->head == nullptr)
	{
		printf("%s", "Stack is empty\n");
		return;
	}
	while (now != nullptr)
	{
		printf("%d%s", now->value, " ");
		now = now->next;
	}
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