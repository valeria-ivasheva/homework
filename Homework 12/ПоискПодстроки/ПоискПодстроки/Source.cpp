#include "list.h"
#include <iostream>

using namespace std;

void stopSymbol(List* list, char *string)
{
	int length = strlen(string);
	for (int i = length - 2; i >= 0; i--)
	{
		if (!haveElement(list, string[i]))
		{
			insert(list, string[i], length - i - 1);
		}
	}
	insert(list, '@', length);
}

int algBMX(char *string, char *findString)
{
	List* list = createList();
	stopSymbol(list, findString);
	int i = strlen(findString) - 1;
	const int lengthFind = strlen(findString);
	const int lengthString = strlen(string);
	while (i < lengthString)
	{
		int j = 0;
		while (i < lengthString && j < lengthFind && findString[lengthFind - j - 1] == string[i - j])
		{
			j++;
		}
		if (j == lengthFind)
		{
			deleteList(list);
			return i - lengthFind + 2;
		}
		char key = string[i];
		if (!haveElement(list, key))
		{
			key = '@';
		}
		i += numberOfJump(list, key);
	}
	deleteList(list);
	return -1;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	FILE *text = fopen("text.txt", "r");
	if (text == nullptr)
	{
		cout << "Файл не найден" << endl;
		return -1;
	}
	char string[200] = "";
	char findString[100] = "";
	cout << "Что мы будем искать?" << endl;
	cin >> findString;
	bool findNot = true;
	int countLine = 0;
	int pos = -1;
	while (findNot && (fgets(string, 200, text) != nullptr))
	{
		countLine++;
		pos = algBMX(string, findString);
		findNot = pos == -1;
	}
	fclose(text);
	cout << "Первое вхождение " << countLine << " строка от " << pos << " символа ";
	return 0;
}