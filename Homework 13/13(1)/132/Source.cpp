#include <iostream>

using namespace std;

enum class Status
{
	start,
	integerPart,
	readDot,
	fractionalPart,
	afterE,
	power,
	afterSign,
	fail
};

Status integerPartFun(char ch)
{
	Status result = Status::fail;
	if (ch == 'E')
	{
		result = Status::afterE;
	}
	if (ch == '.')
	{
		result = Status::readDot;
	}
	if (isdigit(ch))
	{
		result = Status::integerPart;
	}
	return result;
}

Status fractionalPartFun(char ch)
{
	Status result = Status::fail;
	if (ch == 'E')
	{
		result = Status::afterE;
	}
	if (isdigit(ch))
	{
		result = Status::fractionalPart;
	}
	return result;
}

Status afterEFun(char ch)
{
	Status result = Status::fail;
	if (isdigit(ch))
	{
		result = Status::power;
	}
	if (ch == '-' || ch == '+')
	{
		result = Status::afterSign;
	}
	return result;
}

int main()
{
	string str = "1";
	int i = 0;
	Status state = Status::start;
	while (str[i] != '\0')
	{
		switch (state)
		{
		case Status::start:
		{
			if (isdigit(str[i]))
			{
				state = Status::integerPart;
				i++;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}
		case Status::integerPart:
		{
			state = integerPartFun(str[i]);
			i++;
			break;
		}
		case Status::readDot:
		{
			if (isdigit(str[i]))
			{
				state = Status::fractionalPart;
				i++;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}
		case Status::fractionalPart:
		{
			state = fractionalPartFun(str[i]);
			i++;
			break;
		}
		case Status::afterE:
		{
			state = afterEFun(str[i]);
			i++;
			break;
		}
		case Status::power:
		{
			if (isdigit(str[i]))
			{
				state = Status::power;
				i++;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}
		case Status::afterSign:
		{
			if (isdigit(str[i]))
			{
				state = Status::power;
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
	if (state == Status::integerPart || state == Status::power || state == Status::fractionalPart)
	{
		cout << "String is right" << endl;
	}
	else
	{
		cout << "String is not right" << endl;
	}
	return 0;
}