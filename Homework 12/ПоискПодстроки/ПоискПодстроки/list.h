#pragma once

struct ListElement;

struct List;

// Создаем пустой список
List* createList();

// Добавляем элемент value в список
void insert(List *list, char key, int value);

// Удаляем элемент value из списка
//void deleteElement(List *list, char key);

//
bool haveElement(List* list, char key);

// 
int numberOfJump(List* list, char key);

// Выводим весь список
void printList(List *list);

// Удаляем список
void deleteList(List *list);

//Проверка на симметрию
bool isSymmetry(List* list);