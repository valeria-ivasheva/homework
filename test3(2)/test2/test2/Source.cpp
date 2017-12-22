#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack* stack = createStack();
	for (int i = 0; i < 5; i++)
	{
		int value = 0;
		int key = 0;
		cout << "Write value, key\n";
		cin >> value >> key;
		enqueue(stack, key, value);
	}
	printStack(stack);
	int res = dequeue(stack);
	cout << "Value " << res << endl;
	res = dequeue(stack);
	cout << "Value " << res << endl;
	dequeue(stack);
	int value = 0;
	int key = 0;
	cin >> value >> key;
	enqueue(stack, key, value);
	res = dequeue(stack);
	cout << "Value " << res << endl;
	cin >> value >> key;
	enqueue(stack, key, value);
	deleteStack(stack);
	return 0;
}