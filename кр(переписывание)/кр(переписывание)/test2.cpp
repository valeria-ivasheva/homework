#include "list.h"
#include<iostream>

using namespace std;

void information()
{
	setlocale(LC_ALL, "Russian");
	cout << "Ключи и выполняемые функции" << endl;
	cout << "0 - выйти " << endl;
	cout << "1 - добавить значение в заданную позицию в двусвязный список" << endl;
	cout << "2 - удалить значение в заданной позиции из списка " << endl;
	cout << "3 - распечатать список" << endl;
}

int main()
{
	List* list = createList();
	information();
	int key = 1;
	while (key != 0)
	{
		cout << "Введите ключ от 0 до 3" << endl;
		cin >> key;
		switch (key)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			cout << "Введите позицию и значение для добавления" << endl;
			int index = 0;
			int value = 0;
			cin >> index >> value;
			insert(list, index, value);
			break;
		}
		case 2:
		{
			cout << "Введите позицию для удаления" << endl;
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
			cout << "Вы выбрали несуществующий ключ!" << endl;
			information();
		}
		}
		cout << endl;
	}
	deleteList(list);
	return 0;
}