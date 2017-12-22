#pragma once

struct Stack;

// Создаем пустую очередь
Stack* createStack();

// Добавляем элемент value с приоритетом key в очередь 
void enqueue(Stack *stack, int key, int value);

// Удаляем элемент c наибольшим приоритетом из очереди
int dequeue(Stack *stack);

// Выводим всю очередь
void printStack(Stack *stack);

// Удаляем очередь
void deleteStack(Stack *stack);
