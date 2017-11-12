#pragma once
#include <string>

struct HashTable;

//������� ���-�������
HashTable* makeHashTable();

//�������� ������� � ���-�������
void addElement(HashTable*, std::string element);

//������� ������� �� �������
void deleteElement(HashTable*, std::string element);

//������� �������
void deleteHash(HashTable*);

//�������� ������� �������� � �������
bool isInclude(HashTable*, std::string element);