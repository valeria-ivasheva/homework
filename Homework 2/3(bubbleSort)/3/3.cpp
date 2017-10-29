#include <iostream>
using namespace std;

void sortBubble(int arrayForBubble[], int length)
{
	int i = 0;
	bool flag = true;
	while ((i < length) && (flag))
	{
		flag = false;
		for (int j = 1; j <= length - i - 1; ++j)
		{
			if (arrayForBubble[j] < arrayForBubble[j - 1])
			{
				int a = arrayForBubble[j];
				arrayForBubble[j] = arrayForBubble[j - 1];
				arrayForBubble[j - 1] = a;
				flag = true;
			}
		}
		++i;
	}

}

int main()
{
	int anArray[100] = { 0 };
	int arrayForCountingSort[101] = { 0 };
	int length = 0;
	cin >> length;
	for (int i = 0; i < length; ++i)
	{
		cin >> anArray[i];
	}
	int copyArray[100] = { 0 };
	for (int i = 0; i < length; ++i)
	{
		copyArray[i] = anArray[i];
	}
	for (int i = 0; i < length; ++i)
	{
		arrayForCountingSort[anArray[i]]++;
	}
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < arrayForCountingSort[i]; ++j)
		{
			cout << i << " ";
		}
	}
	sortBubble(copyArray, length);
	for (int i = 0; i < length; ++i)
	{
		cout << copyArray[i] << " ";
	}	
	return 0;
}