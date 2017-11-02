#pragma once

struct Node;

//Создать дерево
Node *createNode();

//Вставить элемент в дерево
Node *insertNode(Node *node, char newElement[5]);

//Удалить дерево
Node* deleteAllNode(Node* tree);

//Вернуть родителя
Node* parent(Node* node);

//Проверка есть два сына
bool twoChild(Node* node);

//Проверка является ли корнем
bool itRoot(Node* node);

//Распечатать дерево
void printNode(Node *node);

//Результат арифметического дерева
int resultNode(Node* node);