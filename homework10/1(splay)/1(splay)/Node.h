#pragma once

struct Node;

//Создать ассоциативный массив
Node* createNode();

//Добавить элемент с ключом и значением 
void insertValue(Node* node, std::string key, std::string value);

//Найти элемент по ключу
std::string findValue(Node* node, std::string key);

//Проверить есть ли такой ключ
bool isHaveKey(Node* node, std::string key);

//Удалить элемент по ключу
void deleteElement(Node* node, std::string key);

//Удалить ассоциативный массив
void deleteNode(Node* node);