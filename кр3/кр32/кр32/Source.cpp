#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int arrayA[100][100] = { 0 };
	int countOfLine = 0;
	int countOfColumn = 0;
	int min[100] = { 100000 };
	int max[100] = { -100000 };
	cout << "Введите количество строк и столбцов " << endl;
	cin >> countOfLine;
	cin >> countOfColumn;
	cout << "Введите массив " << endl;
	for (int i = 0; i < countOfLine; i++)
	{
		for (int j = 0; j < countOfColumn; j++)
		{
			cin >> arrayA[i][j];
			if (min[i] > arrayA[i][j])
			{
				min[i] = arrayA[i][j];
			}
			if (max[j] < arrayA[i][j])
			{
				max[j] = arrayA[i][j];
			}
		}
	}
	for (int i = 0; i < countOfLine; i++)
	{
		for (int j = 0; j < countOfColumn; j++)
		{
			if (arrayA[i][j] == max[j] && arrayA[i][j] == min[i])
			{
				cout << "Седловая точка строки " << i << " столбца " << j << " " << arrayA[i][j] << endl;
			}
		}
	}
	return 0;
}