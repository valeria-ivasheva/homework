#pragma once
#include <string>

struct Tree;

//������� ������������� ������
Tree* createTree();

//�������� ������� � ������ � ��������� 
Tree* insertValue(Tree* tree, const std::string &key, const std::string &value);

//����� ������� �� �����
std::string findValue(Tree* tree, const std::string &key);

//��������� ���� �� ����� ����
bool hasKey(Tree* tree, const std::string &key);

//������� ������� �� �����
void deleteElement(Tree* tree, const std::string &key);

//������� ������������� ������
void deleteTree(Tree* tree);
