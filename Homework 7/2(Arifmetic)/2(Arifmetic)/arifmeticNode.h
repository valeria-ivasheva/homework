#pragma once

struct Node;

//������� ������
Node *createNode();

//�������� ������� � ������
Node *insertNode(Node *node, char newElement[5]);

//������� ������
Node* deleteAllNode(Node* tree);

//������� ��������
Node* parent(Node* node);

//�������� ���� ��� ����
bool twoChild(Node* node);

//�������� �������� �� ������
bool itRoot(Node* node);

//����������� ������
void printNode(Node *node);

//��������� ��������������� ������
int resultNode(Node* node);