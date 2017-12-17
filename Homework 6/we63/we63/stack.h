#pragma once

struct StackElement
{
	char symbol;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

//������� ����
Stack *createStack();

//�������� ������� � ����
void push(char symbol, Stack *stack);

//������� ������� �� �����
char pop(Stack *stack);

//�������� �� ������� �����
bool isEmpty(Stack *stack);

//������� ����
void deleteStack(Stack *stack);