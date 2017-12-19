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
	BiTree *tree = createTree();
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
			if (!searchElement(tree, newElement))
			{
				tree = insertTree(tree, newElement);
			}
			break;
		}
		case 2:
		{
			int element = 0;
			cout << "������� �������, ������� ������ �������\n";
			cin >> element;
			tree = deleteNodeTree(tree, element);
			break;
		}
		case 3:
		{
			int element = 0;
			cout << "������� ������� ��� �������� ��������� �� ���������\n";
			cin >> element;
			if (!searchElement(tree, element))
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
			printSortAssendingTree(tree);
			break;
		}
		case 5:
		{
			printSortDescendingTree(tree);
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
	deleteAllTree(tree);
	return 0;
}