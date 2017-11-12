#pragma once

struct ListElement;

struct List;

// Создаем пустой список
List* createList();

// Добавляем элемент value в список
void insert(List *list, std::string element);

bool isIncludeList(List* list, std::string element);

// Количество элементов в списке
int sizeList(List* list);

// Выводим весь список
void printList(List *list);

// Удаляем список
void deleteList(List *list);