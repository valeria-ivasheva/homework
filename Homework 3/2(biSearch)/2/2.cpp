#include <iostream>
#include <stdlib.h>

using namespace std;

void quicksort(int x[], int left, int right)
{
	int numberMiddle = (right + left + 1) / 2;
	int middle = x[numberMiddle];
	int leftnow = left;
	int rightnow = right;
	while (leftnow <= rightnow)
	{
		while (x[leftnow] < middle)
		{
			leftnow++;
		}
		while (x[rightnow] > middle)
		{
			rightnow--;
		}
		if (leftnow <= rightnow)
		{
			int b = x[rightnow];
			x[rightnow] = x[leftnow];
			x[leftnow] = b;
			rightnow--;
			leftnow++;
		}
	}
	if (left < rightnow)
	{
		quicksort(x, left, rightnow);
	}
	if (leftnow < right)
	{
		quicksort(x, leftnow, right);
	}
}

bool bisearch(int key, int a[], int left, int right)
{
	if (left > right)
	{
		return false;
	}
	int middle = (left + right) / 2;
	if (a[middle] == key)
	{
		return true;
	}
	if (a[middle] > key)
	{
		bisearch(key, a, left, middle - 1);
	}
	else
	{
		bisearch(key, a, middle + 1, right);
	}
}

int main()
{
	int length, count;
	int a[5000]{ 0 };
	cout << "Write n and k " << "\n";
	cin >> length >> count;
	for (int i = 0; i < length; i++)
	{
		a[i] = rand();
		cout << a[i] << " ";
	}
	cout << "\n";
	quicksort(a, 0, length - 1);
	for (int j = 0; j < count; j++)
	{
		int key = rand();
		bool result = bisearch(key, a, 0, length - 1);
		cout << key << " " << result << "\n";
	}
	return 0;
}