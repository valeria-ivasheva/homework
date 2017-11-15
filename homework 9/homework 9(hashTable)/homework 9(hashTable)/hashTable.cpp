#include "hashTable.h"
#include "list.h"
#include <iostream>
#include <string>
using namespace std;

struct HashTable
{
	List *buckets[100];
};

HashTable* makeHashTable()
{
	HashTable* hash = new HashTable;
	for (int i = 0; i < 100; i++)
	{
		hash->buckets[i] = createList();
	}
	return hash;
}

int hashFunction(char str[100])
{
	int result = 0;
	int p = 2;
	for (int i = 0; i < strlen(str); ++i)
	{
		result = result * p + str[i];
	}
	return result;
}

void addElement(HashTable* hash, char element[100])
{
	int number = hashFunction(element) % 100;
	insert(hash->buckets[number], element);
}

void deleteElement(HashTable* hash, char element[100])
{
	int number = hashFunction(element) % 100;
	deleteElementList(hash->buckets[number], element);
}

void deleteHash(HashTable* hash)
{
	for (int i = 0; i < 100; ++i)
	{
		deleteList(hash->buckets[i]);
	}
	delete hash;
}

bool isInclude(HashTable* hash, char element[100])
{
	int number = hashFunction(element) % 100;
	return isIncludeList(hash->buckets[number], element);
}

void printHash(HashTable* hash)
{
	for (int i = 0; i < 100; ++i)
	{
		printList(hash->buckets[i]);
	}
}

void characteristicHash(HashTable* hash)
{
	double countWord = 0;
	double countList = 0;
	int maxList = 0;
	for (int i = 0; i < 100; ++i)
	{
		if (sizeList(hash->buckets[i]) != 0)
		{
			countList++;
			countWord += sizeList(hash->buckets[i]);
			if (sizeList(hash->buckets[i]) > maxList)
			{
				maxList = sizeList(hash->buckets[i]);
			}
		}
	}
	setlocale(LC_ALL, "Russian");
	cout << "Свойства хэш-таблицы" << endl;
	cout << "Максимальная длина списка в сегменте таблицы " << maxList << endl;
	double averageLength = countWord / countList;
	cout << "Средняя длина списка в сегменте таблицы " << averageLength << endl;
	double coefficient = countList / 100;
	cout << "Коэффициент заполнения хеш-таблицы " << coefficient << endl;
}

