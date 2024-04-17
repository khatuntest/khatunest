#include <iostream>
#include <vector>
#include <string>

using namespace std;
#ifndef DOC_TEST_H
#define DOC_TEST_H
template <typename  T>
class Types_Sorting {
private:
    int size;
    vector <T>list_of_element;
public:
    explicit Types_Sorting(int n);
    void insert(int n);
    void Insertion_sor();
    void Section_sor();
    void Bubble_sor();
    void merge_sor(int first , int end );
    void sort_item(int first , int mid , int end);
    void Quick_sor(int first , int end );
    int  partition(int low , int high);
    void counting_sor();
    void print();
};
#endif //DOC_TEST_H
