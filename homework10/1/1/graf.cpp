#include <iostream>

using namespace std;

const int maxCount = 100;

void dijkstra(int number, int countOfCity, int arrayOfRoads[100][maxCount], int arrayOfState[2][maxCount])
{
	bool visits[maxCount] = { false };
	int length[maxCount] = { 0 };
	for (int i = 0; i < countOfCity; i++)
	{
		length[i] = INT_MAX;
	}
	length[number] = 0;
	int now = -1;
	for (int count = 0; count < countOfCity; count++)
	{
		int min = INT_MAX;
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
			if (!visits[i] && arrayOfRoads[now][i] > 0 && length[now] != INT_MAX &&
				(length[now] + arrayOfRoads[now][i] < length[i]))
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

void printResult(int countOfCity, int arrayOfState[2][maxCount])
{
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
}

void locationOfTheCapital(int countOfCity, int arrayOfState[2][maxCount], int arrayOfRoads[maxCount][maxCount])
{
	for (int i = 0; i < countOfCity; i++)
	{
		arrayOfState[1][i] = INT_MAX;
	}
	for (int i = 0; i < countOfCity; i++)
	{
		if (arrayOfState[0][i] != -1)
		{
			continue;
		}
		dijkstra(i, countOfCity, arrayOfRoads, arrayOfState);
	}
}

int main()
{
	int arrayOfRoads[maxCount][maxCount] = { 0 };
	int arrayOfState[2][maxCount] = { 0 };
	int countOfCity = 0;
	int countOfRoads = 0;
	int countOfCapital = 0;
	FILE *text = fopen("text.txt", "r");
	if (text == nullptr)
	{
		cout << "Can't open file" << endl;
		return -1;
	}
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
	fclose(text);
	locationOfTheCapital(countOfCity, arrayOfState, arrayOfRoads);
	printResult(countOfCity, arrayOfState);
	return 0;
}