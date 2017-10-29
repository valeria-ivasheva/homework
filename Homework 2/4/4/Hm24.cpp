#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int arrayRand[100] = { 0 };
	int lengthArray = 0;
	cin >> lengthArray;
	for (int i = 0; i < lengthArray; ++i)
	{
		arrayRand[i] = rand() % 100;
	}
	for (int i = 0; i < lengthArray; ++i)
	{
		cout << arrayRand[i] << " ";
	}
	cout << "\n";
	int left = 1;
	int right = lengthArray - 1;
	while ((left < lengthArray) && (right > 0) && (right != left))
	{
		while ((arrayRand[left] < arrayRand[0]) && (left != right))
		{
			left++;
		}
		while ((arrayRand[right] >= arrayRand[0]) && (left != right))
		{
			right--;
		}
		int temp = arrayRand[left];
		arrayRand[left] = arrayRand[right];
		arrayRand[right] = temp;
	}
	for (int i = 0; i < lengthArray; ++i)
	{
		cout << arrayRand[i] << " ";
	}
	cout << "\n";
	return 0;
}