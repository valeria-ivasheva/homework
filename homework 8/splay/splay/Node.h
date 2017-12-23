#pragma once
#include <string>

using std::string;

struct Tree;

//Создать ассоциативный массив
Tree* createTree();

//Добавить элемент с ключом и значением 
Tree* insertValue(Tree* tree, const string &key, const string &value);

//Найти элемент по ключу
string findValue(Tree* tree, const string &key);

//Проверить есть ли такой ключ
bool isHaveKey(Tree* tree, const string &key);

//Удалить элемент по ключу
void deleteElement(Tree* tree, const string &key);

//void printTree(Tree* tree);

//Удалить ассоциативный массив
void deleteTree(Tree* tree);
