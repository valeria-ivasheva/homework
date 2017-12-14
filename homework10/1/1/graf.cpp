#include <iostream>
using namespace std;

void dijkstra(int number, int countOfCity, int(&arrayOfRoads)[100][100], int(&arrayOfState)[2][100])
{
	bool visits[100] = { false };
	int length[100] = { 0 };
	for (int i = 0; i < countOfCity; i++)
	{
		length[i] = 2000000;
	}
	length[number] = 0;
	int now = -1;
	for (int count = 0; count < countOfCity; count++)
	{
		int min = 20000000;
		for (int i = 0; i< countOfCity; i++)
		{
			if (!visits[i] && length[i] <= min)
			{
				min = length[i];
				now = i;
			}
		}
		visits[now] = true;
		for (int i = 0; i < countOfCity; i++)
		{
			if (!visits[i] && arrayOfRoads[now][i] > 0 && length[now] != 2000000000 && (length[now] + arrayOfRoads[now][i] < length[i]))
			{
				length[i] = length[now] + arrayOfRoads[now][i];
			}
		}
	}
	for (int i = 0; i < countOfCity; i++)
	{
		if (arrayOfState[0][i] != -1 && arrayOfState[1][i] > length[i])
		{
			arrayOfState[0][i] = number;
			arrayOfState[1][i] = length[i];
		}
	}
}

int main()
{
	int arrayOfRoads[100][100] = { 0 };
	FILE *text = fopen("text.txt", "r");
	if (text == nullptr)
	{
		cout << "Don't open file" << endl;
	}
	int arrayOfState[2][100] = { 0 };
	int countOfCity = 0;
	int countOfRoads = 0;
	fscanf(text, "%d", &countOfCity);
	fscanf(text, "%d", &countOfRoads);
	for (int i = 0; i < countOfRoads; i++)
	{
		int cityA = 0;
		int cityB = 0;
		int length = 0;
		fscanf(text, "%d%d%d", &cityA, &cityB, &length);
		arrayOfRoads[cityA][cityB] = length;
		arrayOfRoads[cityB][cityA] = length;
	}
	int countOfCapital = 0;
	fscanf(text, "%d", &countOfCapital);
	for (int i = 0; i < countOfCapital; i++)
	{
		int capital = 0;
		fscanf(text, "%d", &capital);
		arrayOfState[0][capital] = -1;
		for (int i = 0; i < countOfCity; i++)
		{
			arrayOfRoads[i][capital] = 0;
		}
	}
	for (int i = 0; i < countOfCity; i++)
	{
		arrayOfState[1][i] = 2000000000;
	}
	fclose(text);
	for (int i = 0; i < countOfCity; i++)
	{
		if (arrayOfState[0][i] != -1)
		{
			continue;
		}
		dijkstra(i, countOfCity, arrayOfRoads, arrayOfState);
	}
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < countOfCity; i++)
	{
		if (arrayOfState[0][i] == -1)
		{
			cout << "Государств со столицей " << i << " ";
			bool flag = true;
			for (int j = 0; j < countOfCity; j++)
			{
				if (arrayOfState[0][j] == i)
				{
					if (flag)
					{
						cout << " и городами ";
						flag = false;
					}
					cout << j << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}