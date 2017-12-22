#pragma once

struct Stack;

// ������� ������ �������
Stack* createStack();

// ��������� ������� value � ����������� key � ������� 
void enqueue(Stack *stack, int key, int value);

// ������� ������� c ���������� ����������� �� �������
int dequeue(Stack *stack);

// ������� ��� �������
void printStack(Stack *stack);

// ������� �������
void deleteStack(Stack *stack);
