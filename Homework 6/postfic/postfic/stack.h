#pragma once

struct Stack;

//Создать стэк
Stack *createStack();

//Добавить элемент в стэк
void push(int value, Stack *stack);

//Забрать элемент со стэка
int pop(Stack *stack);

//Проверка на пустоту стэка
bool isEmpty(Stack *stack);

//Удалить стэк
void deleteStack(Stack *stack);