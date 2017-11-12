#include "Node.h"
#include<iostream>
struct Node
{
	int value;
	Node* leftChild;
	Node* rightChild;
};

Node *createNode()
{
	Node* node = {};
	return node;
}

Node *searchElementNode(Node* node, int searchElement)
{
	if (node == nullptr || node->value == searchElement)
	{
		return node;
	}
	if (node->value > searchElement)
	{
		return searchElementNode(node->leftChild, searchElement);
	}
	else
	{
		return searchElementNode(node->rightChild, searchElement);
	}
}

Node *insertNode(Node *node, int newElement)
{
	if (node == nullptr)
	{
		node = new Node;
		node->value = newElement;
		node->leftChild = nullptr;
		node->rightChild = nullptr;
	}
	else
	{
		if (newElement < node->value)
		{
			node->leftChild = insertNode(node->leftChild, newElement);
		}
		else
		{
			node->rightChild = insertNode(node->rightChild, newElement);
		}
	}
	return node;
}

void printSortAssending(Node *node)
{
	if (node == nullptr)
	{
		return;
	}
	printSortAssending(node->leftChild);
	printf("%d%s", node->value, " ");
	printSortAssending(node->rightChild);
}

void printSortDescending(Node *node)
{
	if (node == nullptr)
	{
		return;
	}
	printSortDescending(node->rightChild);
	printf("%d%s", node->value, " ");
	printSortDescending(node->leftChild);
}

Node* minimum(Node* node)
{
	if (node->leftChild == nullptr)
	{
		return node;
	}
	return minimum(node->leftChild);
}

Node* deleteNode(Node* node, int element)
{
	if (node == nullptr)
	{
		return node;
	}
	if (element < node->value)
	{
		node->leftChild = deleteNode(node->leftChild, element);
	}
	else if (element > node->value)
	{
		node->rightChild = deleteNode(node->rightChild, element);
	}
	else if (node->leftChild != nullptr && node->rightChild != nullptr)
	{
		node->value = minimum(node->rightChild)->value;
		node->rightChild = deleteNode(node->rightChild, node->value);
	}
	else if (node->leftChild == nullptr)
	{
		node = node->rightChild;
	}
	else
	{
		node = node->leftChild;
	}
	return node;
}

Node* deleteAllNode(Node* node)
{
	while (node != nullptr)
	{
		node = deleteNode(node, node->value);
	}
	return node;
}

