#pragma once

struct ListElement;

struct List;

// Создаем пустой список
List* createList();

// Добавляем элемент value в список
void insert(List *list, int value);

// Удаляем элемент value из списка
void deleteElement(List *list, int value);

// Выводим весь список
void printList(List *list);

// Удаляем список
void deleteList(List *list);

//Проверка на симметрию
bool isSymmetry(List* list);