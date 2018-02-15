#pragma once
#include <string>

struct Tree;

//Создать ассоциативный массив
Tree* createTree();

//Добавить элемент с ключом и значением 
Tree* insertValue(Tree* tree, const std::string &key, const std::string &value);

//Найти элемент по ключу
std::string findValue(Tree* tree, const std::string &key);

//Проверить есть ли такой ключ
bool hasKey(Tree* tree, const std::string &key);

//Удалить элемент по ключу
void deleteElement(Tree* tree, const std::string &key);

//Удалить ассоциативный массив
void deleteTree(Tree* tree);
