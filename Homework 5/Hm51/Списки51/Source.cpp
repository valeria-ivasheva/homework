#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	List *list = createList();
	int key = 1;
	cout << "������������� � ���������\n" << "0 �����\n" << "1 �������� ������� � ������\n";
	cout << "2 ������� ������� �� ������\n" << "3 ����������� ���� ������\n";
	while (key != 0)
	{
		cout << "�������� ������� � �������� �������������� ���� �� 0 �� 3, ����������\n";
		cin >> key;
		switch (key)
		{
		case 1:
		{
			cout << "������� �����, ������� �� ������ �������� � ������\n";
			int value = 0;
			cin >> value;
			insert(list, value);
			break;
		}
		case 2:
		{
			cout << "������� �����, ������� �� ������ ������� �� ������\n";
			int value = 0;
			cin >> value;
			deleteElement(list, value);
			break;
		}
		case 3:
		{
			cout << endl;
			printList(list);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "���, �� �� ����� ����� �������, ����������, �������� ����� �� 0 �� 3 " << endl;
			cout << "� ��� ��� ������������ � ���������\n" << "0 �����\n" << "1 �������� ������� � ������\n";
			cout << "2 ������� ������� �� ������\n" << "3 ����������� ���� ������\n";
		}
		}
		cout << endl;
	}
	deleteList(list);
	return 0;
}