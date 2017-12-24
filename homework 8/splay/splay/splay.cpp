#include <iostream>
#include "Node.h"
#include <string>

using namespace std;

void information()
{
	setlocale(LC_ALL, "Russian");
	cout << "1 Добавить значение по заданному ключу" << endl;
	cout << "2 Получить значение по заданному ключу" << endl;
	cout << "3 Проверить наличие заданного ключа" << endl;
	cout << "4 Удалить заданный ключ и связанное с ним значение" << endl;
	cout << "0 ВЫХОД" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Tree* tree = createTree();
	int key = 1;
	information();
	while (key != 0)
	{
		cout << "Введите ключ" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			cout << "Введите ключ и значение для добавления" << endl;
			string sKey = "1";
			string sValue = "1";
			cin >> sKey;
			cin >> sValue;
			tree = insertValue(tree, sKey, sValue);
			break;
		}
		case 2:
		{
			cout << "Введите ключ для поиска" << endl;
			string sKey = "1";
			string sValue = "1";
			cin >> sKey;
			sValue = findValue(tree, sKey);
			cout << sValue << endl;
			break;
		}
		case 3:
		{
			cout << "Введите ключ для проверки" << endl;
			string sKey = "1";
			cin >> sKey;
			if (hasKey(tree, sKey))
			{
				cout << "TRUE" << endl;
			}
			else
			{
				cout << "FALSE" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Введите ключ для удаления" << endl;
			string sKey = "";
			cin >> sKey;
			deleteElement(tree, sKey);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			information();
		}
		}
	}
	deleteTree(tree);
	return 0;
}