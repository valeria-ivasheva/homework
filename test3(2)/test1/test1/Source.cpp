#include <iostream>
#include <vector>
#include < stdlib.h > 

using namespace std;

int sum(int value)
{
	int result = value % 10;
	while (value / 10 != 0)
	{
		value = value / 10;
		result += value % 10;
	}
	return abs(result);
}

int main()
{
	int length;
	cin >> length;
	int max = -1;
	vector<int> arrayA(length);
	for (int i = 0; i < length; ++i)
	{
		cin >> arrayA[i];
		int temp = sum(arrayA[i]);
		if (temp > max)
		{
			max = temp;
		}
	}
	for (int i = 0; i < length; ++i)
	{
		if (max == sum(arrayA[i]))
		{
			cout << arrayA[i] << " ";
		}
	}
	return 0;
}