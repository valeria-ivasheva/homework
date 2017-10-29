#include <iostream>

using namespace std;

void swap(int x[], int left, int right)
{
	int j, c, middle;
	middle = (right - left + 1) / 2;
	j = 0;
	while (j < middle)
	{
		c = x[j + left];
		x[j + left] = x[right - j];
		x[right - j] = c;
		j++;
	}
}

int main()
{
	int x[100]{ 0 };
	int i, m, n;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	swap(x, 0, m - 1);
	swap(x, m, n - 1);
	swap(x, 0, n - 1);
	for (i = 0; i < n; ++i)
	{
		cout << x[i] << " ";
	}
	return 0;
}