#include <iostream>
#include "Node.h"

using namespace std;

void keyRule()
{
	cout << "�����:\n";
	cout << "1 �������� �������\n";
	cout << "2 ������� �������\n";
	cout << "3 ��������� ������� �� ��������� �� ���������\n";
	cout << "4 ����������� �� �����������\n";
	cout << "5 ����������� �� ��������\n";
	cout << "0 �����\n";
}

int main()
{
	int key = 1;
	Node *tree = createNode();
	setlocale(LC_ALL, "Russian");
	keyRule();
	while (key != 0)
	{
		cout << "������� ���� �� ������\n";
		cin >> key;
		switch (key)
		{
		case 1:
		{
			int newElement = 0;
			cout << "������� �������, ������� ������ ��������\n";
			cin >> newElement;
			if (searchElementNode(tree, newElement) == nullptr)
			{
				tree = insertNode(tree, newElement);
			}
			break;
		}
		case 2:
		{
			int element = 0;
			cout << "������� �������, ������� ������ �������\n";
			cin >> element;
			tree = deleteNode(tree, element);
			break;
		}
		case 3:
		{
			int element = 0;
			cout << "������� ������� ��� �������� ��������� �� ���������\n";
			cin >> element;
			if (searchElementNode(tree, element) == nullptr)
			{
				printf("%s", "���\n");
			}
			else
			{
				printf("%s", "����\n");
			}
			break;
		}
		case 4:
		{
			printSortAssending(tree);
			break;
		}
		case 5:
		{
			printSortDescending(tree);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "����������, �������� ���� �� 0 �� 5.\n";
			keyRule();
		}
		}
	}
	tree = deleteAllNode(tree);
	delete tree;
	return 0;
}