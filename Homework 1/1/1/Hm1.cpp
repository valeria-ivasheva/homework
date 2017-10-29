#include <iostream>;

using namespace std;

int main()
{
	int x, q, result;
	cin >> x;
	q = x*x;
	result = q * (q + 1) + q + x + 1;
	cout << result << endl;
	return 0;
}
