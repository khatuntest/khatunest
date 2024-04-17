#include <iostream>
#include <algorithm>
#include "sorting.h"
using namespace std;
template <typename  T>
Types_Sorting<T> :: Types_Sorting(int n){
    size=n;

}
template <typename  T>
void Types_Sorting<T> :: insert(int n){
    list_of_element.push_back(n);
}
template <typename  T>
void Types_Sorting<T> ::Insertion_sor(){
    int i,j;
    for ( i=1 ; i<size; ++i){
        int temp =list_of_element[i];
        for ( j=i ; j>0 ; --j){
            if (temp < list_of_element[j-1]){
                list_of_element[j]=list_of_element[j-1];
            }
            else
                break;
        }
        list_of_element[j]=temp;
    }
}
template <typename  T>
void Types_Sorting <T>:: Section_sor(){
    int least , i,j;
    for (i=0 ; i<size-1 ; ++i ){
        least=i;
        for (j=i+1 ; j<size ; ++j){
            if (list_of_element[j] < list_of_element[least])
                least=j;
        }
        swap(list_of_element[i],list_of_element[least]);
    }
}
template <typename  T>
void Types_Sorting<T> :: Bubble_sor(){
    int  i,j;
    for (i=0 ; i<size ; ++i ){
        for (j=size-1 ; j>=1 ; --j){
            if (list_of_element[j] < list_of_element[j-1])
                swap(list_of_element[j],list_of_element[j-1]);
        }
    }
}
template <typename  T>
void Types_Sorting<T> :: merge_sor(int first , int end ){
    if (first < end ){
        int mid =first +(end -first)/2;
        merge_sor(first , mid);
        merge_sor(mid+1 , end);
        sort_item(first , mid , end );
    }
}
template <typename  T>
void Types_Sorting<T> :: sort_item(int first , int mid , int end ){
    int nl=mid-first+1;
    int nr=end-mid;
    vector <int>vcl(nl),vcr(nr);
    for (int i=0 ; i<nl ; ++i )
        vcl[i]=list_of_element[first+i];
    for (int i=0 ; i<nr ; ++i )
        vcr[i]=list_of_element[mid+1+i];
    int i=0,j=0,k=first;
    while (i<nl && j<nr){
        if (vcl[i]<= vcr[j]){
            list_of_element[k]=vcl[i];
            i++;
        }
        else {
            list_of_element[k]=vcr[j];
            j++;
        }
        k++;
    }
    while (i<nl){
        list_of_element[k]=vcl[i];
        i++;
        k++;
    }
    while (j<nr){
        list_of_element[k]=vcr[j];
        j++;
        k++;
    }

}
template <typename  T>
void Types_Sorting<T> :: Quick_sor(int first , int end){
    if (first < end){
        int index= partition(first , end );
        Quick_sor(first , index-1);// Sort elements before the pivot
        Quick_sor(index+1 , end ) ;// Sort elements after the pivot
    }
    else
        return;
}
template <typename  T>
int  Types_Sorting<T> :: partition(int low , int high){
    T pivot =list_of_element[low];
    int index=low;
    for (int i=low+1; i<= high ; ++i){
        if (list_of_element[i] < pivot){
            index++;
            swap(list_of_element[index] , list_of_element[i]);
        }
    }
    swap (list_of_element[index] , list_of_element[low]);
    return index;
}
template <typename  T>
void Types_Sorting <T>:: counting_sor(){
    vector <T>temp;
    temp=list_of_element;
    int mx= *max_element(list_of_element.begin() , list_of_element.end());
    vector <int>count(mx+1,0);
    for (int i=0 ; i<size ; ++i)
        count[list_of_element[i]]++;

    for (int i=1 ; i<=mx ; ++i){
        count[i]+=count[i-1];
    }
    for (int i=size-1 ; i>=0 ; --i){
        list_of_element[count[temp[i]]-1]=temp[i];
        count[temp[i]]--;
    }
}
template <typename  T>
void Types_Sorting<T> :: print(){
    cout<<"List after sorting \n";
    for (int i=0 ; i<size; ++i)
        cout<<list_of_element[i]<<" ";
    cout<<"\n";
}
