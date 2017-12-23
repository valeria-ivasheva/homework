#pragma once
#include <string>

using std::string;

struct Tree;

//������� ������������� ������
Tree* createTree();

//�������� ������� � ������ � ��������� 
Tree* insertValue(Tree* tree, const string &key, const string &value);

//����� ������� �� �����
string findValue(Tree* tree, const string &key);

//��������� ���� �� ����� ����
bool isHaveKey(Tree* tree, const string &key);

//������� ������� �� �����
void deleteElement(Tree* tree, const string &key);

//void printTree(Tree* tree);

//������� ������������� ������
void deleteTree(Tree* tree);
