#pragma once

struct Node;

//������� ������������� ������
Node* createNode();

//�������� ������� � ������ � ��������� 
void insertValue(Node* node, std::string key, std::string value);

//����� ������� �� �����
std::string findValue(Node* node, std::string key);

//��������� ���� �� ����� ����
bool isHaveKey(Node* node, std::string key);

//������� ������� �� �����
void deleteElement(Node* node, std::string key);

//������� ������������� ������
void deleteNode(Node* node);