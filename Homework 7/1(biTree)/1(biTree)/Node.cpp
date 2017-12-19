#include "Node.h"
#include<iostream>

struct Node
{
	int value;
	Node* leftChild;
	Node* rightChild;
};

struct BiTree
{
	Node* root;
};

BiTree *createTree()
{
	BiTree* tree = new BiTree;
	tree->root = nullptr;
	return tree;
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

bool searchElement(BiTree* tree, int element)
{
	if (tree == nullptr)
	{
		return false;
	}
	return (searchElementNode(tree->root, element) != nullptr);
}

void insertNode(Node *&node, int newElement)
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
			insertNode(node->leftChild, newElement);
		}
		else
		{
			insertNode(node->rightChild, newElement);
		}
	}
	return;
}

BiTree *insertTree(BiTree* tree, int element)
{
	insertNode(tree->root, element);
	return tree;
}


void printSortAssending(Node *node)
{
	if (node == nullptr)
	{
		printf("%s\n", "Список пуст");
		return;
	}
	if (node->leftChild != nullptr)
	{
		printSortAssending(node->leftChild);
	}
	printf("%d%s", node->value, " ");
	if (node->rightChild != nullptr)
	{
		printSortAssending(node->rightChild);
	}
}

void printSortAssendingTree(BiTree *tree)
{
	printSortAssending(tree->root);
}

void printSortDescending(Node *node)
{
	if (node == nullptr)
	{
		printf("%s\n", "Список пуст");
		return;
	}
	if (node->rightChild != nullptr)
	{
		printSortDescending(node->rightChild);
	}
	printf("%d%s", node->value, " ");
	if (node->leftChild != nullptr)
	{
		printSortDescending(node->leftChild);
	}
}

void printSortDescendingTree(BiTree *tree)
{
	printSortDescending(tree->root);
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
		Node* temp = node;
		node = node->rightChild;
		delete temp;
	}
	else
	{
		Node* temp = node;
		node = node->leftChild;
		delete temp;
	}
	return node;
}

void deleteAllTree(BiTree* tree)
{
	while (tree->root != nullptr)
	{
		tree = deleteNodeTree(tree, tree->root->value);
	}
	delete tree;
	return;
}

BiTree* deleteNodeTree(BiTree* tree, int element)
{
	if (!searchElement(tree, element))
	{
		return tree;
	}
	if (tree != nullptr)
	{
		tree->root = deleteNode(tree->root, element);
	}
	return tree;
}