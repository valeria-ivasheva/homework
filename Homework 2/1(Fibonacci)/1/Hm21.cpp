#include <iostream>
using namespace std;

int fib(int i)
{
	if (i == 1 || i == 2)
		return 1;
	return fib(i - 2) + fib(i - 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cin >> n;
	int f1 = 1; 
	int f2 = 1;
	int k = 0;
	for (int j = 3; j < n + 1;++j)
	{
		k = f2;
		f2 = f1 + f2;
		f1 = k;
	}
	cout << "Число Фибоначчи номер " << n << " равно ";
	cout << f2 << "\n";
	f1 = fib(n);
	cout << f1 << "\n";
	return 0;
}