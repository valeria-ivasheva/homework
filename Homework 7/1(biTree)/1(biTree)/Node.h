#pragma once

struct BiTree;

struct Node;

//Создать дерево
BiTree *createTree();

//Найти элемент в дереве
bool searchElement(BiTree* node, int searchElement);

//Вставить элемент в дерево
BiTree *insertTree(BiTree* tree, int element);

//Удалить элемент из дерева
BiTree* deleteNodeTree(BiTree* tree, int element);

//Распечатать элементы дерева по возрастанию
void printSortAssendingTree(BiTree *node);

//Распечатать по убыванию
void printSortDescendingTree(BiTree *node);

//Удалить дерево
void deleteAllTree(BiTree* tree);
