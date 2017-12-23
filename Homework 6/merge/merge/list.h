#pragma once
#include <string>
struct ListElement;

struct List;

//Создать список
List *createList();

//Элемент списка list под номером number
ListElement* elementNumber(List *list, int number);

//Добавляет новый элемент в конец списка
void newElement(List* input,const std::string &name,const std::string &phone);

//Количество элементов в списке
int countElement(List *list);

//На место элемента в списке output под номером outputLast записываются данные элемента из списка input под номером inputNew
void replace(List *output, int outputLast, List *input, int inputNew);

//Удалить список
void deleteList(List *list);

//Вернуть имя элемента
std::string returnName(ListElement *element);

//Вернуть номер элемента
std::string returnPhone(ListElement *element);