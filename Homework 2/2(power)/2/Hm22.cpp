#include <iostream>
using namespace std;

int powerLine(int a, int power)
{
	if (power == 0)
	{
		return 1;
	}
	return (a * powerLine(a, power - 1));
}

int logPower(int a, int power)
{
	if (power == 0)
	{
		return 1;
	}
	if (power % 2 == 0)
	{
		int sqrtPower = logPower(a, power / 2);
		return (sqrtPower * sqrtPower);
	}
	return (a * logPower(a, power - 1));
}

int main()
{
	int a = 0;
	int power = 0;
	cin >> a >> power;
	int result = powerLine(a, power);
	cout << result << "\n";
	int resultLog = logPower(a, power);
	cout << resultLog << "\n";
	return 0;
}