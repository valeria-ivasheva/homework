#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int divindend, divisor, quotient;
	cout << "Write a, b >> ";
	cin >> divindend >> divisor;
	if (divindend == 0 || divisor == 0)
	{
		if (divindend == 0)
		{
			cout << 0;
		}
		else
		{
			cout << "Wrong!!!";
		}
	}
	else
	{
		int sign = divindend * divisor / (abs(divindend) * abs(divisor));
		divindend = abs(divindend);
		divisor = abs(divisor);
		quotient = 0;
		while (divisor * quotient <= divindend)
		{
			++quotient;
		}
		quotient = (quotient - 1) * sign;
		cout << quotient << "\n";
	}
	return 0;
}