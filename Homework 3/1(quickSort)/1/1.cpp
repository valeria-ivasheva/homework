#include <iostream>

using namespace std;

void insertionSort(int x[], int leftIn, int rightIn)
{
	for (int i = leftIn; i <= rightIn; ++i)
	{
		int j = i;
		while ((j > 0) && (x[j - 1] > x[j]))
		{
			int b = x[j];
			x[j] = x[j - 1];
			x[j - 1] = b;
			j--;
		}
	}
}

void quicksort(int x[], int left, int right)
{
	if (right - left + 1 <= 10)
	{
		insertionSort(x, left, right);
	}
	else
	{
		int numberMiddle = (right + left ) / 2;
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
		if (rightnow > left)
		{
			quicksort(x, left, rightnow);
		}
		if (right > leftnow)
		{
			quicksort(x, leftnow, right);
		}
	}
}

int main()
{
	int length;
	cout << "Write a length of array >> " << "\n";
	cin >> length;
	int x[100]{ 0 };
	cout << "Write an array >> " << "\n";
	for (int i = 0; i < length; i++)
	{
		cin >> x[i];
	}
	quicksort(x, 0, length - 1);
	for (int i = 0; i < length; ++i)
	{
		cout << x[i] << " ";
	}
	return 0;
}