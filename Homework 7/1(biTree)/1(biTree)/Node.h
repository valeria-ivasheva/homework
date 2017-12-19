#pragma once

struct BiTree;

struct Node;

//������� ������
BiTree *createTree();

//����� ������� � ������
bool searchElement(BiTree* node, int searchElement);

//�������� ������� � ������
BiTree *insertTree(BiTree* tree, int element);

//������� ������� �� ������
BiTree* deleteNodeTree(BiTree* tree, int element);

//����������� �������� ������ �� �����������
void printSortAssendingTree(BiTree *node);

//����������� �� ��������
void printSortDescendingTree(BiTree *node);

//������� ������
void deleteAllTree(BiTree* tree);
