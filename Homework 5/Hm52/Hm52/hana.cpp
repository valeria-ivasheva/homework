#include "cyclicList.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ������\n";
	int n = 0;
	cin >> n;
	cout << "������� m-��� �� �������, ������� �� ��� m\n";
	int m = 0;
	cin >> m;
	List* list = createCyclicList();
	list = fillList(list, n);
	ListElement* previous = list->head;
	while (countElement(list) > 1)
	{
		previous = deleteElement(list, previous, m);
	}
	printf("� ��� � ��� �����������, ������� ������� � �����, �� ����\n");
	printList(list);
	deleteList(list);
	return 0;
}