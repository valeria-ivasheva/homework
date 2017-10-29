#pragma once

struct Stack;

//������� ����
Stack *createStack();

//�������� ������� � ����
void push(char symbol, Stack *stack);

//������� ������� �� �����
char pop(Stack *stack);

//�������� �� ������� �����
bool isEmpty(Stack *stack);

//������� ����
void deleteStack(Stack *stack);;