#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack* stack = createStack();
	for (int i = 0; i < 2; i++)
	{
		int value = 0;
		int key = 0;
		cout << "Write value, key\n";
		cin >> value >> key;
		enqueue(stack, key, value);
	}
	printStack(stack);
	int res = dequeue(stack);
	cout << "Value " << res;
	res = dequeue(stack);
	cout << "Value " << res;
	dequeue(stack);
	deleteStack(stack);
	return 0;
}