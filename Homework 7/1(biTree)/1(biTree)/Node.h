#pragma once

struct Node;

//Создать дерево
Node *createNode();

//Найти элемент в дереве
Node *searchElementNode(Node* node, int searchElement);

//Вставить элемент в дерево
Node *insertNode(Node *node, int newElement);

//Удалить элемент из дерева
Node* deleteNode(Node* node, int element);

//Распечатать элементы дерева по возрастанию
void printSortAssending(Node *node);

//Распечатать по убыванию
void printSortDescending(Node *node);

//Удалить дерево
Node* deleteAllNode(Node* tree);
