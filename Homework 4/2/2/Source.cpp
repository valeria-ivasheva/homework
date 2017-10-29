#include "sort.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int searchMaxCount(int a[], int length)
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
		quickSort(x, 0, length - 1);
		int result = searchMaxCount(x, length);
		cout << result << endl;
		return 0;
	}
}
