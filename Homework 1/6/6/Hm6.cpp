#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int i, legth, matchingLettersCount, lengthSubstring, count, j;
	char s[100], s1[100];
	cout << "Write s >> ";
	cin >> s;
	cout << "Write s1 >> ";
	cin >> s1;
	count = 0;
	legth = strlen(s);
	lengthSubstring = strlen(s1);
	for (i = 0; i < legth; ++i)
	{
		matchingLettersCount = 0;
		j = 0;
		while ((s[i + j] == s1[j]) && (j < lengthSubstring))
		{
			++matchingLettersCount;
			++j;
		}
		if (matchingLettersCount == lengthSubstring)
		{
			count++;
			i += j - 1;
		}
	}
	cout << count << "\n";
	return 0;
}