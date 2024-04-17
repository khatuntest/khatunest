#include <iostream>
#include "sorting.cpp"
using namespace std ;

int main(){
    int num,item,option;
    cout<<"Please Enter The size of Your List\n";
    cin>>num;
    Types_Sorting <int>object (num);
    cout<<"Enter Your Items\n";
    for (int i=0 ; i<num ; ++i){
        cin>>item;
        object.insert(item);
    }
    cout<<"Option insertion sort 1\n"
          "Option Section sort 2  \n"
          "Option Bubble sort  3  \n"
          "Option Merge sort   4  \n"
          "Option Quick sort   5   \n"
          "Option Counting sort 6 \n";

    cout<<"Enter your Option \n";
    cin>>option;
    if (option == 1){
        object.Insertion_sor();
    }
    if (option == 2){
        object.Section_sor();
    }
    if (option == 3){
        object.Bubble_sor();
    }
    if (option == 4){
        object.merge_sor(0,num);
    }
    if (option == 5){
        object.Quick_sor(0,num);
    }
    if (option == 6){
        object.counting_sor();
    }
    object.print();

    return 0;
}
//5 3 8 9 1 7 0 2 6 4