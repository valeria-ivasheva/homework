#include "arifmeticNode.h"
#include<iostream>
#include <stdlib.h>

struct Node
{
	char value[5];
	Node* leftChild;
	Node* rightChild;
	Node* parent;
};

Node *createNode()
{
	Node* node = {};
	return node;
}

bool itRoot(Node* node)
{
	return node == nullptr || node->parent == nullptr;
}

bool isOperation(char string[5])
{
	return (string[0] == '-' || string[0] == '+' || string[0] == '*' || string[0] == '/');
}
Node *insertNode(Node *node, char newElement[5])
{
	Node* nodeNew = new Node;
	for (int i = 0; i < 5; i++)
	{
		nodeNew->value[i] = 0;
	}
	for (int i = 0; i < strlen(newElement); i++)
	{
		nodeNew->value[i] = newElement[i];
	}
	nodeNew->leftChild = nullptr;
	nodeNew->rightChild = nullptr;
	nodeNew->parent = node;
	if (node == nullptr)
	{
		return node = nodeNew;
	}
	else if (node->leftChild == nullptr)
	{
		if (!isOperation(newElement))
		{
			node->leftChild = nodeNew;
			return node;
		}
		else
		{
			return node->leftChild = nodeNew;
		}
	}
	else
	{
		if (!isOperation(newElement))
		{
			node->rightChild = nodeNew;
			return node;
		}
		else
		{
			return node->rightChild = nodeNew;
		}
	}
}

Node* deleteAllNode(Node* node)
{
	if (node == nullptr)
	{
		return node;
	}
	while (node->leftChild != nullptr || node->rightChild != nullptr)
	{
		if (node->leftChild != nullptr)
		{
			deleteAllNode(node->leftChild);
		}
		else
		{
			deleteAllNode(node->rightChild);
		}
	}
	if (node->parent == nullptr)
	{
		delete node->value;
		return node;
	}
	node = node->parent;
	if (node->leftChild != nullptr)
	{
		node->leftChild->parent = nullptr;
		delete node->leftChild;
		node->leftChild = nullptr;
		return node;
	}
	node->rightChild->parent = nullptr;
	delete node->rightChild;
	node->rightChild = nullptr;
	return node;
}

bool twoChild(Node* node)
{
	if (node == nullptr)
	{
		return false;
	}
	return (node->leftChild != nullptr && node->rightChild != nullptr);
}

Node* parent(Node* node)
{
	return node->parent;
}

void printNode(Node *node)
{
	if (node == nullptr)
	{
		return;
	}
	if (twoChild(node))
	{
		printf("%s", "( ");
	}
	printf("%s%s", node->value, " ");
	printNode(node->leftChild);
	printNode(node->rightChild);
	if (twoChild(node))
	{
		printf("%s", ") ");
	}
}

int arifmarithmetic(char symbol, int a, int b)
{
	int result = 0;
	switch (symbol)
	{
	case '-':
	{
		result = a - b;
		break;
	}
	case '+':
	{
		result = a + b;
		break;
	}
	case '*':
	{
		result = a * b;
		break;
	}
	case '/':
	{
		result = a / b;
		break;
	}
	}
	return result;
}
int resultNode(Node* node)
{
	if (isOperation(node->value))
	{
		return arifmarithmetic(node->value[0], resultNode(node->leftChild), resultNode(node->rightChild));
	}
	return atoi(node->value);
}