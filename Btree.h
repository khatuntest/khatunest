#include <iostream>
using namespace std;
#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H

template <class T, int Order>
class BtreeNode {
public:
    bool isLeaf;          // true if leaf node, false otherwise
    int countKeys;        // Number of keys in the node
    T keys[Order];        // Array of keys in the node
    BtreeNode<T, Order>* children[Order + 1];  // Array of child pointers
    BtreeNode<T, Order>* parent;  // Parent pointer

    BtreeNode(bool leaf = true);
};
template <class T, int Order >
class Btree {
private:
    BtreeNode<T , Order>* root;
public:
    Btree();
    void PrintHelper(BtreeNode<T,Order>* root , int level );
    void InsertNonFull(BtreeNode<T,Order>* node , T key);
    void SplitChild(BtreeNode<T, Order>* parent, int index);
    void Insert(T key);
    void Print();
    int GetHeight(BtreeNode<T,Order>* node);
};


#endif //BTREE_BTREE_H