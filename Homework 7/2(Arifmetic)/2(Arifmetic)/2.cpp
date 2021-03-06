#include "arifmeticNode.h"
#include <iostream>

using namespace std;

int main()
{
	FILE *tree = fopen("arifmeticTree.txt", "r");
	if (tree == nullptr)
	{
		cout << "Don't open file" << endl;
	}
	Node* node = createNode();
	while (!feof(tree))
	{
		int symbol = getc(tree);
		if (symbol == ' ')
		{
			continue;
		}
		if (symbol != '(')
		{
			ungetc(symbol, tree);
		}
		else
		{
			char element[5] = "";
			fscanf(tree, "%s", element);
			node = insertNode(node, element);
			continue;
		}
		char element[5] = "";
		fscanf(tree, "%s", element);
		if (symbol == ')')
		{
			if (twoChild(node) && itRoot(node))
			{
				break;
			}
			node = parent(node);
		}
		else
		{
			node = insertNode(node, element);
		}
	}
	fclose(tree);
	printNode(node);
	cout << endl;
	int result = resultNode(node);
	printf("%s%d\n", "Result ", result);
	deleteNode(node);
	return 0;
}