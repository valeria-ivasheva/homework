#include "list.h"
#include<iostream>

using namespace std;

void information()
{
	setlocale(LC_ALL, "Russian");
	cout << "����� � ����������� �������" << endl;
	cout << "0 - ����� " << endl;
	cout << "1 - �������� �������� � �������� ������� � ���������� ������" << endl;
	cout << "2 - ������� �������� � �������� ������� �� ������ " << endl;
	cout << "3 - ����������� ������" << endl;
}

int main()
{
	List* list = createList();
	information();
	int key = 1;
	while (key != 0)
	{
		cout << "������� ���� �� 0 �� 3" << endl;
		cin >> key;
		switch (key)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			cout << "������� ������� � �������� ��� ����������" << endl;
			int index = 0;
			int value = 0;
			cin >> index >> value;
			insert(list, index, value);
			break;
		}
		case 2:
		{
			cout << "������� ������� ��� ��������" << endl;
			int index = 0;
			cin >> index;
			deleteElement(list, index);
			break;
		}
		case 3:
		{
			printList(list);
			break;
		}
		default:
		{
			cout << "�� ������� �������������� ����!" << endl;
			information();
		}
		}
		cout << endl;
	}
	deleteList(list);
	return 0;
}