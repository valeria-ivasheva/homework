#include <iostream>
#include"list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int now = 1;
	cout << "¬ведите список чисел" << endl;
	cin >> now;
	List *list = createList();
	while (now != 0)
	{
		insert(list, now);
		cin >> now;
	}
	printList(list);
	deleteList(list);
	return 0;
}