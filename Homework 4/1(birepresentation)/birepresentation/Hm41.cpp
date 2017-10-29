#include <iostream>
#include <cmath>

using namespace std;

int const intSize = 32;
bool *biRepresentation(int num)
{
	bool *result = new bool[intSize];
	for (int i = 0; i < intSize; ++i)
	{
		result[i] = num >> i & 1;
	}
	return result;
}

void printBiNumber(bool *biNumber)
{
	for (int i = intSize - 1; i >= 0; --i)
	{
		printf("%d", biNumber[i]);
	}
	cout << endl;
}

int translateBi(bool *biNumberSum)
{
	int sum = 0;
	int power = 1;
	for (int i = 0; i < intSize; ++i)
	{
		if (biNumberSum[i])
		{
			sum += power;
		}
		power *= 2;
	}
	return sum;
}

bool *biSumNumbers(bool *biNumberA, bool *biNumberB)
{
	bool *sumAB = new bool[intSize];
	bool previous = false;
	for (int i = 0; i < intSize; ++i)
	{
		sumAB[i] = (biNumberA[i] | biNumberB[i] | previous) & ((biNumberA[i] & biNumberB[i] & previous) | (biNumberA[i] ^ biNumberB[i] ^ previous));
		previous = (biNumberA[i] & biNumberB[i]) | (biNumberA[i] & previous) | (previous & biNumberB[i]);
	}
	return sumAB;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите числа А и В >> " << endl;
	int a = 0;
	int b = 0;
	cin >> a >> b;
	cout << "Бинарное представление числа А >> " << endl;
	bool *biNumberA = biRepresentation(a);
	printBiNumber(biNumberA);
	cout << "Бинарное представление числа В >> " << endl;
	bool *biNumberB = biRepresentation(b);
	printBiNumber(biNumberB);
	cout << "Бинарное представление A + В >> " << endl;
	bool *biNumberAB = biSumNumbers(biNumberA, biNumberB);
	printBiNumber(biNumberAB);
	int sum = translateBi(biNumberAB);
	cout << "Это в десятичной равно " << sum << endl;
	delete[]biNumberA;
	delete[]biNumberB;
	delete[]biNumberAB;
	return 0;
}