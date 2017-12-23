#include <iostream>
#include "list.h"
#include "MergeSort.h"

using namespace std;
int main()
{
	FILE *phonebook = fopen("aphonebook.txt", "r");
	if (phonebook == nullptr)
	{
		cout << "ERROR, can't open file";
		return -1;
	}
	List *book = createList();
	int count = 1;
	char nameTemp[100] = "";
	char phoneTemp[100] = "";
	while (fscanf(phonebook, "%s%s", nameTemp, phoneTemp) != EOF)
	{
		newElement(book, nameTemp, phoneTemp);
		count++;
	}
	fclose(phonebook);
	int key = 0;
	cout << "Write key" << endl;
	cin >> key;
	mergeSort(key, book, 1, count - 1);
	for (int i = 1; i < count; i++)
	{
		cout << returnName(elementNumber(book, i)) << " " << returnPhone(elementNumber(book, i)) << endl;
	}
	deleteList(book);
	return 0;
}