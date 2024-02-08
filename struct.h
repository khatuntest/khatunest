#include <iostream>
#include <string>

using namespace std;
#ifndef DOC_TEST_H
#define DOC_TEST_H
template <typename T>
class Node{
public:
    T data;
    Node *node;
};
template <typename T>
class Linked_list{
private:
    Node<T> *head;
public:
    Linked_list();
    bool isEmpty();
    void Insert_First(T new_item);
    void Insert_Last(T new_item);
    void InsertBefore(T item , T new_item);
    int Size();
    void Delete_front();
    void Delete_item(T item);
    void Delete_back();
    bool found (T key);
    void print();
    ~Linked_list();
};
#endif //DOC_TEST_H

