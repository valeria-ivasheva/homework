#pragma once

struct Stack;

//������� ����
Stack *createStack();

//�������� ������� � ����
void push(int value, Stack *stack);

//������� ������� �� �����
int pop(Stack *stack);

//�������� �� ������� �����
bool isEmpty(Stack *stack);

//������� ����
void deleteStack(Stack *stack);