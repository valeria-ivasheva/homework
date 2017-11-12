#pragma once
#include <string>

struct HashTable;

//Создать хэш-таблицу
HashTable* makeHashTable();

//Добавить элемент в хэш-таблицу
void addElement(HashTable*, std::string element);

//Удалить элемент из таблицы
void deleteElement(HashTable*, std::string element);

//Удалить таблицу
void deleteHash(HashTable*);

//Проверка наличия элемента в таблице
bool isInclude(HashTable*, std::string element);