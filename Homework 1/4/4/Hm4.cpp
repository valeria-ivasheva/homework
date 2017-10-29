#include <iostream>

using namespace std;

int main()
{
	int count[28]{};
	int j, i, k, sum;
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			for (k = 0; k < 10; ++k)
			{
				sum = i + j + k;
				++count[sum];
			}
		}
	}
	sum = 0;
	for (i = 0; i < 28; ++i)
	{
		sum = sum + count[i] * count[i];
	}
	cout << sum << "\n";
	return 0;
}
