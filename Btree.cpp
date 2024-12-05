#include "Btree.h"
template <class T, int Order>
BtreeNode<T, Order>::BtreeNode(bool leaf) {
    this->isLeaf = leaf;
    countKeys = 0;
    parent = nullptr;  // Initialize parent pointer to nullptr
    for (int i = 0; i < Order; ++i) {
        children[i] = nullptr; // Initialize all child pointers to nullptr
    }
}

template <class T, int Order>
Btree<T, Order>::Btree() {
    root = nullptr;
}

template <class T, int Order>
void Btree<T, Order>::Print() {
    if (root != nullptr) {
        PrintHelper(root, 0);
    } else {
        cout << "The tree is empty!" << endl;
    }
}

template <class T, int Order>
void Btree<T, Order>::PrintHelper(BtreeNode<T, Order> *node, int level) {
    if (node == nullptr) return;

    // Print all keys in the current node

    for (int i = 0; i < node->countKeys; ++i) {
        cout << node->keys[i] << " ";
    }
    cout << endl;

    // If this node is not a leaf, print all children recursively
    if (!node->isLeaf) {
        for (int i = 0; i <= node->countKeys; ++i) {
            PrintHelper(node->children[i], level + 1);
        }
    }
}

template <class T, int Order>
int Btree<T, Order>::GetHeight(BtreeNode<T, Order>* node) {
    if (!node) return 0;
    if (node->isLeaf) return 1;

    int height = 0;
    for (int i = 0; i <= node->countKeys; ++i) {
        int childHeight = GetHeight(node->children[i]);
        if (childHeight > height) {
            height = childHeight;
        }
    }
    return height + 1;
}


template <class T, int Order>
void Btree<T, Order>::InsertNonFull(BtreeNode<T, Order> *node, T key) {
    int i = node->countKeys - 1;
    if (node->isLeaf) {
        // Find the position to insert the new key
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;}
        node->keys[i + 1] = key;
        node->countKeys++;
        // Debug: Print keys in the current node after insertion
        cout << "Inserted " << key << " into leaf. Node keys: ";
        for (int j = 0; j < node->countKeys; ++j) {
            cout << node->keys[j] << " ";}cout << endl;
    } else {
        // Find the child to descend into
        while (i >= 0 && key < node->keys[i]) {i--;}
        i++;
        InsertNonFull(node->children[i], key);
        // If the child is full, split it
        if (node->children[i]->countKeys == Order ) {
            cout << "Child is full. Splitting..." << endl;
            SplitChild(node , i);
        }

    }
}

template <class T, int Order>
void Btree<T, Order>::SplitChild(BtreeNode<T, Order> *parent, int index) {
    cout << "Splitting child at index " << index << endl;
    if (parent == nullptr || parent->children[index] == nullptr) {
        cout << "Error: Parent or child node is null." << endl;
        return;
    }
    BtreeNode<T, Order> *fullChild = parent->children[index];
    int midIndex = (Order) / 2;  // Middle index for splitting the node
    // Create a new node for the second half of the full child
    BtreeNode<T, Order> *newNode = new BtreeNode<T, Order>(fullChild->isLeaf);
    // Move second half of keys to the new node
    newNode->countKeys = fullChild->countKeys - midIndex - 1;
    for (int i = 0; i < newNode->countKeys; ++i) {
        newNode->keys[i] = fullChild->keys[midIndex + 1 + i];
    }
    // Move children pointers if it's not a leaf
    if (!fullChild->isLeaf) {
        for (int i = 0; i <= newNode->countKeys; ++i) {
            newNode->children[i] = fullChild->children[midIndex + 1 + i];
            fullChild->children[midIndex + 1 + i] = nullptr;  // Clear child pointer in fullChild
        }
    }
    // Update the key count of the full child (now contains only the left half)
    fullChild->countKeys = midIndex;
    // Shift parent's children to make space for the new node
    for (int i = parent->countKeys ; i >= index + 1; --i) {
        parent->children[i + 1] = parent->children[i];
    }
    // Insert the new node as the child at index + 1
    parent->children[index + 1] = newNode;
    // Shift parent's keys to make space for the promoted key
    for (int i = parent->countKeys - 1; i >= index; --i) {
        parent->keys[i + 1] = parent->keys[i];
    }
    // Promote the middle key of the full child to the parent
    parent->keys[index] = fullChild->keys[midIndex];
    parent->countKeys++;
    if (parent->countKeys == Order) {
        cout << "Parent is full after split. Recursively splitting the root..." << endl;
        // If parent is full and is the root, we need to split the root
        if (parent == root) {
            BtreeNode<T, Order> *newRoot = new BtreeNode<T, Order>(false);
            newRoot->children[0] = parent;
            parent->parent = newRoot;
            SplitChild(newRoot , 0);
            root = newRoot;
        }
    }
    // Debug: Print the state of the parent and children after the split
    cout << "Split complete. Parent keys: ";
    for (int i = 0; i < parent->countKeys; ++i) {
        cout << parent->keys[i] << " ";
    }
    cout <<"\n"<<"Left child keys: ";
    for (int i = 0; i < fullChild->countKeys; ++i) {
        cout << fullChild->keys[i] << " ";
    }
    cout << endl<< "Right child keys: ";
    for (int i = 0; i < newNode->countKeys; ++i) {
        cout << newNode->keys[i] << " ";
    }
    cout << endl;

}

template <class T, int Order>
void Btree<T, Order>::Insert(T key) {
    cout << "Inserting key: " << key << endl;
    // Case when the tree is empty
    if (!root) {
        root = new BtreeNode<T, Order>(true);
        root->keys[0] = key;
        root->countKeys = 1;
        cout << "Created root and inserted key " << key << endl;
    } else {
        // Case when root is not full
        if (root->countKeys < Order) {
            InsertNonFull(root, key);
        }
        else {// Root is full, create a new root and split the old root
            BtreeNode<T, Order> *newNode = new BtreeNode<T, Order>(false);
            newNode->children[0] = root;
            root->parent = newNode; // Set the root's parent
            // Split the old root
            SplitChild(newNode, 0);
            // Insert the new key into the appropriate child
            int i = (newNode->keys[0] < key ? 1 : 0);
            InsertNonFull(newNode->children[i], key);
            // Set the new node as the root
            root = newNode;
            cout << "Created new root after split" << endl;
        }
    }
}