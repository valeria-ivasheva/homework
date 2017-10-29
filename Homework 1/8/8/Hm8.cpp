#include <iostream>
using namespace std;

int main() {
	int a[100]{ 0 };
	int n, i, count;
	count = 0;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (i = 0; i < n; ++i) {
		if (a[i] == 0) {
			++count;
		}
	}
	cout << count << "\n";
	return 0;
}