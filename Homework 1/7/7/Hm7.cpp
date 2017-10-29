#include <iostream>
#include <cmath>
using namespace std;

bool simple(int a) {
	int i, k;
	bool p;
	k = trunc(sqrt(a));
	i = 2;
	p = false;
	while ((a % i != 0) && (i <= k)) {
		++i;
	}
	if (i > k) {
		p = true;
	}
	return p;
}

int main() {
	int n, i;
	cout << "Natural number n: \n";
	cin >> n;
	if (n == 1) {
		cout << "Do not exist";
	}
	else {
		for (i = 2; i <= n; ++i) {
			if (simple(i)) {
				cout << i << " ";
			}
		}
	}
	cout << "\n";
	return 0;
}