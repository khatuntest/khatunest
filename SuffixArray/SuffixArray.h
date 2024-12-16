#include<iostream>
#include<deque>
using namespace std;

#ifndef SUFFIXARRAY_SUFFIXARRAY_H
#define SUFFIXARRAY_SUFFIXARRAY_H


class SuffixArray {
private:
    int size;       // Size of the input string
    char* str;      // Pointer to the input string
    int* rank;      // Array to store the rank of each suffix
    int* suf;       // Array to store the suffix indices (suffix array)
    int* temp;      // Temporary array for rank updates
    int* sufTemp;   // Temporary array for merge sort operations
public:
    SuffixArray(const char* s);
    void ConstructUsingPrefixDoubling();
    void MergeSort(int* array, int left, int right, int len);
    void Merge(int* array, int left, int mid, int right, int len);
    bool compare(int a, int b, int len);
    void Print();
    ~SuffixArray(); // Destructor to free memory
};


#endif //SUFFIXARRAY_SUFFIXARRAY_H
