#pragma once

struct ListElement;

struct List;

// Создаем пустой список
List* createList();

// Добавляем элемент value в список
void insert(List *list, char key, int value);

//Проверка существования элемента в списке
bool haveElement(List* list, char key);

// Количество прыжка для символа( алгоритм Бойера-Мура-Хорспула)
int numberOfJump(List* list, char key);

// Выводим весь список
void printList(List *list);

// Удаляем список
void deleteList(List *list);