#pragma once

struct StackElement
{
	int value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};


Stack *createStack();
void push(int value, Stack *stack);
int pop(Stack *stack);
bool isEmpty(Stack *stack);
void deleteStack(Stack *stack);