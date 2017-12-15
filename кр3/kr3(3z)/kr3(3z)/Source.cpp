#include <iostream>

using namespace std;

enum class Status
{
	start,
	readFirstCondition,
	readSymbolDog,
	readSecondCondition,
	readDot,
	readLetter,
	fail
};

bool firstCondition(char ch)
{
	return (isdigit(ch) || isalpha(ch) || ch == '_' || ch == '.' || ch == '%' || ch == '-' || ch == '+');
}

bool secondCondition(char ch)
{
	return (isdigit(ch) || isalpha(ch));
}

int main()
{
	string str = "ler99.-+%@yandex.com.ua";
	int i = 0;
	Status state = Status::start;
	while (str[i] != '\0')
	{
		switch (state)
		{
		case Status::start:
		{
			if (firstCondition(str[i]))
			{
				state = Status::readFirstCondition;
				i++;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}
		case Status::readFirstCondition:
		{
			if (str[i] == '@')
			{
				state = Status::readSymbolDog;
				i++;
				break;
			}
			if (!firstCondition(str[i]))
			{
				state = Status::fail;
			}
			i++;
			break;
		}
		case Status::readSymbolDog:
		{
			if (secondCondition(str[i]))
			{
				state = Status::readSecondCondition;
				i++;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}
		case Status::readSecondCondition:
		{
			if (str[i] == '.')
			{
				state = Status::readDot;
				i++;
				break;
			}
			if (!secondCondition(str[i]))
			{
				state = Status::fail;
			}
			i++;
			break;
		}
		case Status::readDot:
		{
			if (isalpha(str[i]))
			{
				state = Status::readLetter;
				i++;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}
		case Status::readLetter:
		{
			if (isdigit(str[i]) || str[i] == '-' || isalpha(str[i]))
			{
				state = Status::readSecondCondition;
				i++;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}
		default:
			break;
		}
		if (state == Status::fail)
		{
			break;
		}
	}
	if (state == Status::readLetter)
	{
		cout << "String is right" << endl;
	}
	else
	{
		cout << "String is not right" << endl;
	}
	return 0;
}