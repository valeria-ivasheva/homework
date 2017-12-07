#include "list.h"
#include <iostream>

using namespace std;

void stopSymbol(List* list, char string[100])
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


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	FILE *text = fopen("text.txt", "r");
	if (text == nullptr)
	{
		cout << "Файл не найден" << endl;
	}
	char string[200] = "";
	char findString[100] = "";
	cin >> findString;
	bool findNot = true;
	List* list = createList();
	int countLine = 0;
	stopSymbol(list, findString);
	while  (findNot && (fgets(string, 200, text) != nullptr))
	{
		countLine++;
		int i = strlen(findString) - 1;
		int lengthFind = strlen(findString);
		int lengthStrinf = strlen(string);
		while (i < lengthStrinf)
		{
			int j = 0;
			while (i <lengthStrinf &&j < lengthFind && findString[lengthFind - j - 1] == string[i - j])
			{
				j++;
			}
			if (j == lengthFind)
			{
				cout << "Совпадение с " << countLine << "строка от " << i - lengthFind + 2 << " символа " ;
				return 0;
			}
			char key = string[i];
			if (!haveElement(list, key))
			{
				key = '@';
			}
			i += numberOfJump(list, key);
		}
	}
	return 0;
}