#include <iostream>

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
	int length;
	setlocale(LC_ALL, "Russian");
	cout << " Введите длину массива >> " << endl;
	cin >> length;
	int x[100]{ 0 };
	cout << " Введите массив >> " << endl;
	for (int i = 0; i < length; ++i)
	{
		cin >> x[i];
	}
	quicksort(x, 0, length - 1);
	cout << " Наиболее встречающийся элемент >> " << endl;
	int result = searchmaxcount(x, length);
	cout << result << endl;
	return 0;
}