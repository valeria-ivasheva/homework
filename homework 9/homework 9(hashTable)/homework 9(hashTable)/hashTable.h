#pragma once
#include <string>

struct HashTable;

//Создать хэш-таблицу
HashTable* makeHashTable();

//Добавить элемент в хэш-таблицу
void addElement(HashTable* hash, char element[100]);

//Удалить элемент из таблицы
void deleteElement(HashTable* hash, char element[100]);

//Удалить таблицу
void deleteHash(HashTable* hash);

//Проверка наличия элемента в таблице
bool isInclude(HashTable* hash, char element[100]);

//
void printHash(HashTable* hash);