#include<iostream>
#include <string>

using namespace std;

bool dayLate(int day, int month, int year, int dayTemp, int monthTemp, int yearTemp)
{
	return ((yearTemp > year) || ((yearTemp == year) && (monthTemp > month)) || ((yearTemp == year) && (monthTemp == month) && (dayTemp > day)));
}
int main()
{

	FILE *text = fopen("data.txt", "r");
	char value[100] = "";
	int temp = 10000;
	int day = 0;
	int month = 0;
	int year = 0;
	while (fscanf(text, "%s", value) != EOF)
	{
		int count = 0;
		int i = 0;
		int dayNow = 0;
		int monthNow = 0;
		int yearNow = 0;
		while (i < strlen(value))
		{
			char temp[10] = "";
			int j = 0;
			while (value[i+1] != '.' && i < strlen(value))
			{
				i++;
				temp[j] = value[i];
				j++;
			}
			switch (count)
			{
			case 0:
				dayNow = atoi(temp);
				break;
			case 1:
				monthNow = atoi(temp);
				break;
			case 2:
				yearNow = atoi(temp);
				break;
			}
			count++;
			i++;
		}
		if (dayLate(day, month, year, dayNow, monthNow, yearNow))
		{
			day = dayNow;
			month = monthNow;
			year = yearNow;
		}
	}
	fclose(text);
	cout << day << "." << month << "." << year << endl;
	return 0;
}