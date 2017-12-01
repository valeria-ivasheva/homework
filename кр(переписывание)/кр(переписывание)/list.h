#pragma once

struct List;

struct ListElement;

// Создаем пустой список
List* createList();

// Добавляем элемент value в список
void insert(List *list, int key, int value);

// Удаляем элемент value из списка
void deleteElement(List *list, int key);

// Выводим весь список
void printList(List *list);

// Удаляем список
void deleteList(List *list);
