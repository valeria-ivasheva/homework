#include "hashTable.h"
#include "list.h"
#include <string>
using namespace std;

struct HashTable
{
	List *buckets[100];
};

HashTable* makeHashTable()
{
	return new HashTable;
}

int hashFunction(string str)
{
	int result = 0;
	int p = 2;
	for (char ch : str)
	{
		result = result * p + int(ch);
	}
	return result;
}

void addElement(HashTable* hash, string& element)
{
	int number = hashFunction(element) % 100;
	if (hash->buckets[number] == nullptr)
	{
		hash->buckets[number] = createList();
	}
	insert(hash->buckets[number], element);
}

void deleteElement(HashTable* hash, string& element)
{
	int number = hashFunction(element) % 100;
	deleteElementList(hash->buckets[number], element);
}

void deleteHash(HashTable* hash)
{
	for (int i = 0; i < 100; ++i)
	{
		deleteList(hash->buckets[i]);
		delete hash;
	}
}

bool isInclude(HashTable* hash, std::string& element)
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

