#pragma once
#include <string>

struct HashTable;

//Создать хэш-таблицу
HashTable* makeHashTable();

//Добавить элемент в хэш-таблицу
void addElement(HashTable* hash, std::string& element);

//Удалить элемент из таблицы
void deleteElement(HashTable* hash, std::string& element);

//Удалить таблицу
void deleteHash(HashTable* hash);

//Проверка наличия элемента в таблице
bool isInclude(HashTable* hash, std::string& element);

//
void printHash(HashTable* hash);