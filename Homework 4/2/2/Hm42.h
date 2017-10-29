#include <iostream>
#include <stdio.h>

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

int searchmaxcount(int a[], int length)
{
	int j = 0;
	int max = 0;
	int element = 0;
	while (j < length)
	{
		int now = a[j];
		int count = 0;
		while (j < length && now == a[j])
		{
			j++;
			count++;
		}
		if (count > max)
		{
			max = count;
			element = a[j - 1];
		}
	}
	return element;
}

int main()
{
	FILE *f = fopen("file1.txt", "r");
	if (f == nullptr)
	{
		return 1;
	}
	else
	{
		int length;
		fscanf(f, "%d", &length);
		int x[100]{ 0 };
		for (int i = 0; i < length; ++i)
		{
			fscanf(f, "%d", &x[i]);
		}
		fclose(f);
		quicksort(x, 0, length - 1);
		int result = searchmaxcount(x, length);
		cout << result << endl;
		return 0;
	}
}