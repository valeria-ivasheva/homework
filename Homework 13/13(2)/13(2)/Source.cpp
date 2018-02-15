#include <iostream>

using namespace std;

int definer(char ch)
{
	if (ch == '/')
	{
		return 1;
	}
	if (ch == '*')
	{
		return 2;
	}
	return 0;
}

int main()
{
	                    // s  /    *
	int matrix[5][3] = {};
	FILE *textState = fopen("state.txt", "r");
	if (textState == nullptr)
	{
		cout << "Don't open file" << endl;
		return -1;
	}
	for (int i = 0; i < 5; i++)
	{
		fscanf(textState, "%d%d%d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
	}
	fclose(textState);
	FILE *text = fopen("text.txt", "r");
	if (text == nullptr)
	{
		cout << "Don't open file" << endl;
	}
	char str[200] = "";
	string kom = "";
	int state = 0;
	while (fgets(str, 200, text) != nullptr)
	{
		
		int i = 0;
		if (kom == "")
		{
			state = 0;
		}
		while (str[i] != '\0')
		{
			state = matrix[state][definer(str[i])];
			if (state != 0)
			{
				kom += str[i];
			}
			if (state == 4)
			{
				printf("%s\n", kom.c_str());
				kom = "";
			}
			i++;
		}
	}
	fclose(text);
	return 0;
}