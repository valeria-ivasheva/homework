#include <iostream>
#include"list.h"
using namespace std;

int main()
{
	int temp = 0;
	FILE *text = fopen("text.txt", "r");
	List* list = createList();
	while (fscanf(text, "%d", &temp) != EOF)
	{
		insert(list, temp);
	}
	bool result = isSymmetry(list);
	deleteList(list);
	cout << result << endl;
	return 0;
}