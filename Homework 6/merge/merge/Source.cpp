#include <iostream>
#include"list.h"
#include "MergeSort.h"

using namespace std;
int main()
{
	FILE *phonebook = fopen("aphonebook.txt", "r");
	List *book = createList();
	int count = 1;
	char nameTemp[100] = "";
	char phoneTemp[100] = "";
	while (fscanf(phonebook, "%s%s", nameTemp, phoneTemp) != EOF)
	{
		newElement(book, nameTemp, phoneTemp);
		count++;
	}
	int key = 0;
	cout << "Write key" << endl;
	cin >> key;
	mergeSort(key, book, 1, count - 1);
	for (int i = 1; i < count; i++)
	{
		cout << elementNumber(book, i)->name << " " << elementNumber(book, i)->phone << endl;
	}
	deleteList(book);
	fclose(phonebook);
	return 0;
}