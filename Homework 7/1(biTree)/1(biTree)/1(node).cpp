#include <iostream>
#include "Node.h"

using namespace std;

void keyRule()
{
	cout << "Ключи:\n";
	cout << "1 Добавить элемент\n";
	cout << "2 Удалить элемент\n";
	cout << "3 Проверить элемент на вхождение во множество\n";
	cout << "4 Распечатать по возрастанию\n";
	cout << "5 Распечатать по убыванию\n";
	cout << "0 ВЫХОД\n";
}

int main()
{
	int key = 1;
	BiTree *tree = createTree();
	setlocale(LC_ALL, "Russian");
	keyRule();
	while (key != 0)
	{
		cout << "Введите один из ключей\n";
		cin >> key;
		switch (key)
		{
		case 1:
		{
			int newElement = 0;
			cout << "Введите элемент, который хотите добавить\n";
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
			cout << "Введите элемент, который хотите удалить\n";
			cin >> element;
			tree = deleteNodeTree(tree, element);
			break;
		}
		case 3:
		{
			int element = 0;
			cout << "Введите элемент для проверки вхождения во множество\n";
			cin >> element;
			if (!searchElement(tree, element))
			{
				printf("%s", "НЕТ\n");
			}
			else
			{
				printf("%s", "ЕСТЬ\n");
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
			cout << "Пожалуйста, выберите ключ от 0 до 5.\n";
			keyRule();
		}
		}
	}
	deleteAllTree(tree);
	return 0;
}