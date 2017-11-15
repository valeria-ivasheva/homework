#pragma once
#include <string>

struct HashTable;

//������� ���-�������
HashTable* makeHashTable();

//�������� ������� � ���-�������
void addElement(HashTable* hash, std::string& element);

//������� ������� �� �������
void deleteElement(HashTable* hash, std::string& element);

//������� �������
void deleteHash(HashTable* hash);

//�������� ������� �������� � �������
bool isInclude(HashTable* hash, std::string& element);

//
void printHash(HashTable* hash);