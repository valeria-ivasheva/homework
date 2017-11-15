#pragma once
#include <string>

struct HashTable;

//������� ���-�������
HashTable* makeHashTable();

//�������� ������� � ���-�������
void addElement(HashTable* hash, char element[100]);

//������� ������� �� �������
void deleteElement(HashTable* hash, char element[100]);

//������� �������
void deleteHash(HashTable* hash);

//�������� ������� �������� � �������
bool isInclude(HashTable* hash, char element[100]);

//
void printHash(HashTable* hash);