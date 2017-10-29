#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int i, k, l;
	string s;
	k = 0;
	cin >> s;
	l = s.length();
	i = 0;
	while ((k >= 0) && (i<l)) {
		if (s[i] == '(') {
			k++;
		}
		else {
			k--;
		}
		++i;
	} 
	if (k != 0)
		cout << "Faulse";
	else
		cout << "True";
	return 0;
}