#pragma once

struct Node;

//
Node *createNode();

//
Node *searchElementNode(Node* node, int searchElement);

//
Node *insertNode(Node *node, int newElement);

//
Node* deleteNode(Node* node, int element);

//
void printSortAssending(Node *node);

//
void printSortDescending(Node *node);

//
Node* deleteAllNode(Node* tree);


