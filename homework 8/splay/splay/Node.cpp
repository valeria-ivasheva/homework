#include "Node.h"

using namespace std;

struct Node
{
	string key;
	string value;
	Node* parent;
	Node* leftChild;
	Node* rightChild;
};

struct Tree
{
	Node* root;
};

void zig(Node* node)
{
	Node* parent = node->parent;
	if (parent == nullptr)
	{
		return;
	}
	if (node->parent->leftChild == node)
	{
		Node* temp = node->rightChild;
		node->parent = node->parent->parent;
		node->rightChild = parent;
		parent->parent = node;
		parent->leftChild = temp;
		if (temp != nullptr)
		{
			temp->parent = parent;
		}
		return;
	}
	Node* temp = node->leftChild;
	node->parent = node->parent->parent;
	node->leftChild = parent;
	parent->parent = node;
	parent->rightChild = temp;
	if (temp != nullptr)
	{
		temp->parent = parent;
	}
}

void zigZig(Node* node)
{
	Node* grandparent = node->parent->parent;
	if (grandparent->parent != nullptr)
	{
		if (grandparent->parent->leftChild == grandparent)
		{
			grandparent->parent->leftChild = node;
		}
		else
		{
			grandparent->parent->rightChild = node;
		}
	}
	node->parent->parent = grandparent->parent;
	grandparent->parent = node->parent;
	if (node->parent->leftChild == node)
	{
		Node* temp = node->parent->rightChild;
		node->parent->rightChild = grandparent;
		grandparent->leftChild = temp;
		zig(node);
		return;
	}
	Node* temp = node->parent->leftChild;
	node->parent->leftChild = grandparent;
	grandparent->rightChild = temp;
	zig(node);
}

void zigzag(Node* node)
{
	Node* grandparent = node->parent->parent;
	if (grandparent->parent != nullptr)
	{
		if (grandparent->parent->leftChild == grandparent)
		{
			grandparent->parent->leftChild = node;
		}
		else
		{
			grandparent->parent->rightChild = node;
		}
	}
	if (node->parent->rightChild == node)
	{
		grandparent->leftChild = node;
		zig(node);
		node->parent = grandparent;
		zig(node);
		return;
	}
	grandparent->rightChild = node;
	zig(node);
	node->parent = grandparent;
	zig(node);
	return;
}

void splay(Tree* tree, Node* node)
{
	if (node == nullptr || node->parent == nullptr)
	{
		return;
	}
	if (node->parent->parent == nullptr)
	{
		zig(node);
		tree->root = node;
		return;
	}
	Node* parent = node->parent;
	Node* grandparent = parent->parent;
	bool isZigzig = (grandparent->leftChild == parent && parent->leftChild == node) || (grandparent->rightChild == parent && parent->rightChild == node);
	if (isZigzig)
	{
		zigZig(node);
		splay(tree, node);
		tree->root = node;
		return;
	}
	zigzag(node);
	splay(tree, node);
	tree->root = node;
	return;
}


Tree* createTree()
{
	Tree* tree = new Tree;
	Node* node = new Node;
	node->parent = nullptr;
	tree->root = node;
	return tree;
}

void insertValueParent(Node* node, Node* parent, const string &key, const string &temp, bool left)
{
	if (node == nullptr)
	{
		Node *tmp = new Node{ key, temp, parent, nullptr, nullptr };
		node = tmp;
		if (left)
		{
			parent->leftChild = node;
		}
		else
		{
			parent->rightChild = node;
		}
		return;
	}
	else if (key == node->key)
	{
		node->value = temp;
		return;
	}
	else if (key < node->key)
	{
		insertValueParent(node->leftChild, node, key, temp, true);
	}
	else
	{
		insertValueParent(node->rightChild, node, key, temp, false);
	}
}

Node* findNode(Node* node, const string &key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (key.compare(node->key) == 0)
	{
		return node;
	}
	else if (key.compare(node->key) > 0 && node->rightChild != nullptr)
	{

		return findNode(node->rightChild, key);
	}
	else
	{
		return findNode(node->leftChild, key);
	}
}

Tree* insertValue(Tree* tree, const string &key, const string &value)
{
	if (tree->root->key == "")
	{
		Node *tmp = new Node{ key, value, nullptr, nullptr, nullptr };
		tree->root = tmp;
		return tree;
	}
	insertValueParent(tree->root, nullptr, key, value, true);
	Node* now = findNode(tree->root, key);
	splay(tree, now);
	return tree;
}

string findValue(Tree* tree, const string &key)
{
	Node* node = findNode(tree->root, key);
	string value = "";
	if (node != nullptr)
	{
		value = node->value;
	}
	splay(tree, node);
	return value;
}

bool isHaveKey(Tree* tree, const string &key)
{
	Node* node = findNode(tree->root, key);
	splay(tree, node);
	return (node != nullptr);
}

Node* minNode(Node* node)
{
	while (node->leftChild != nullptr)
	{
		node = node->leftChild;
	}
	return node;
}

void deleteElement(Tree* tree, const string &key)
{
	Node* node = findNode(tree->root, key);
	if (node == nullptr)
	{
		return;
	}
	Node* parent = node->parent;
	if (node->leftChild == nullptr && node->rightChild == nullptr)
	{
		if (node->parent != nullptr)
		{
			if (node->parent->leftChild == node)
			{
				node->parent->leftChild = nullptr;
			}
			else
			{
				node->parent->rightChild = nullptr;
			}
		}
		else
		{
			tree->root = nullptr;
			delete node;
			return;
		}
		node->parent = nullptr;
		delete node;
	}
	else if (node->leftChild != nullptr && node->rightChild != nullptr)
	{
		Node* min = minNode(node);
		min->parent->leftChild = nullptr;
		node->key = min->key;
		node->value = min->value;
		min->parent = nullptr;
		delete min;
	}
	else if (node->leftChild == nullptr)
	{
		Node *tempNode = node;
		if (node->parent != nullptr)
		{
			if (node->parent->rightChild == node)
			{
				node->parent->rightChild = node->rightChild;
			}
			else
			{
				node->parent->leftChild = node->rightChild;
			}
		}
		else
		{
			tree->root = node->rightChild;
			node->rightChild->parent = nullptr;
			node->rightChild = nullptr;
			delete node;
			return;
		}
		node->rightChild->parent = node->parent;
		tempNode->parent = nullptr;
		delete tempNode;
	}
	else
	{
		Node *tempNode = node;
		if (node->parent != nullptr)
		{
			if (node->parent->leftChild == node)
			{
				node->parent->leftChild = node->leftChild;
			}
			else
			{
				node->parent->rightChild = node->leftChild;
			}
		}
		else
		{
			tree->root = node->leftChild;
			node->leftChild->parent = nullptr;
			node->leftChild = nullptr;
			delete node;
			return;
		}
		node->leftChild->parent = node->parent;
		tempNode->parent = nullptr;
		delete tempNode;
	}
	splay(tree, parent);
}

void deleteTree(Tree* tree)
{
	while (tree->root != nullptr)
	{
		deleteElement(tree, tree->root->key);
	}
	delete tree;
}
