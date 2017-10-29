#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	List *list = createList();
	int key = 1;
	cout << "Познакомьтесь с командами\n" << "0 Выход\n" << "1 Добавить элемент в список\n";
	cout << "2 Удалить элемент из списка\n" << "3 Распечатать весь список\n";
	while (key != 0)
	{
		cout << "Выберите команду и напишите соответсвующий ключ от 0 до 3, пожалуйста\n";
		cin >> key;
		switch (key)
		{
		case 1:
		{
			cout << "Введите число, которое Вы хотите добавить в список\n";
			int value = 0;
			cin >> value;
			insert(list, value);
			break;
		}
		case 2:
		{
			cout << "Введите число, которое Вы хотите удалить из списка\n";
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
			cout << "Упс, мы не знаем такой команды, пожалуйста, выберите цифру от 0 до 3 " << endl;
			cout << "И еще раз ознакомьтесь с командами\n" << "0 Выход\n" << "1 Добавить элемент в список\n";
			cout << "2 Удалить элемент из списка\n" << "3 Распечатать весь список\n";
		}
		}
		cout << endl;
	}
	deleteList(list);
	return 0;
}