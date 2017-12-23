#pragma once
#include <string>
struct ListElement;

struct List;

//������� ������
List *createList();

//������� ������ list ��� ������� number
ListElement* elementNumber(List *list, int number);

//��������� ����� ������� � ����� ������
void newElement(List* input,const std::string &name,const std::string &phone);

//���������� ��������� � ������
int countElement(List *list);

//�� ����� �������� � ������ output ��� ������� outputLast ������������ ������ �������� �� ������ input ��� ������� inputNew
void replace(List *output, int outputLast, List *input, int inputNew);

//������� ������
void deleteList(List *list);

//������� ��� ��������
std::string returnName(ListElement *element);

//������� ����� ��������
std::string returnPhone(ListElement *element);