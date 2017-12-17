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

//Создать стэк
Stack *createStack();

//Добавить элемент в стэк
void push(char symbol, Stack *stack);

//Забрать элемент со стэка
char pop(Stack *stack);

//Проверка на пустоту стэка
bool isEmpty(Stack *stack);

//Удалить стэк
void deleteStack(Stack *stack);