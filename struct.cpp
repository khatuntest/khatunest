#include <iostream>
#include "struct.h"
using namespace std;
template <typename T>
Linked_list<T> :: Linked_list(){
    head = nullptr;
}
template <typename T>
bool Linked_list<T> :: isEmpty(){
    return (head == nullptr);
}
template <typename T>
void Linked_list<T> :: Insert_First(T new_item){
    if (isEmpty()){
        Node <T> *new_node=new Node<T> ();
        new_node->data =new_item;
        head=new_node;
        new_node->node=nullptr;
    }
    else {
        Node<T> *new_node=new Node<T> ();
        new_node->data =new_item;
        new_node->node=head;
        head=new_node;
    }
}
template <typename T>
void Linked_list<T> ::Insert_Last(T new_item){
    if (isEmpty())
        Insert_First(new_item);
    else {
        Node<T> *temp=head;
        while (temp->node !=nullptr)
            temp=temp->node;
        Node<T> *new_node=new Node<T>();
        new_node->data=new_item;
        temp->node=new_node ;
        new_node->node=nullptr;
    }
}
template <typename T>
void Linked_list<T> :: InsertBefore(T item , T new_item){
    if (isEmpty() || head->data == item ){
        Insert_First(new_item);
    }
    else if (!found(item))
        return void (cout<<"The item is not found \n");
    else {
        Node<T> *temp=new Node <T>();
        temp=head ;
        while (temp->node->data != item){
            temp=temp->node ;
        }
        Node<T> *nw_node=new Node <T>();
        nw_node->data=new_item;
        nw_node->node=temp->node;
        temp->node=nw_node;

    }
}
template <typename T>
int Linked_list<T> :: Size(){
    int count =0;
    Node <T>*temp=head;
    while (temp != nullptr){
       count++;
        temp=temp->node ;
    }
    return count;
}
template <typename T>
bool Linked_list<T> ::  found (T key){
    bool test =false ;
    Node<T> *temp=head ;
    while (temp != nullptr){
        if (temp->data == key){
            test =true;
            goto con;
        }
        temp=temp->node ;
    }
    con:
    if (test)
        return true;
    else
        return false;
}
template <typename T>
void Linked_list<T>:: Delete_front(){
    if (isEmpty()){
        return void (cout<<"The Linked list is empty\n");
    }
    else {
        Node<T> *delPtr=head;
        head =head->node ;
        delete delPtr ;
    }
}
template <typename T>
void Linked_list <T>:: Delete_item(T item){
    if (isEmpty()){
        return void (cout<<"The Linked list is empty\n");
    }
    else if (!found (item))
        return void (cout<<"The item is not found \n");
    else{
        Node<T> *Pre=nullptr,*delPtr=head;
        while (delPtr != nullptr && delPtr->data != item){
            Pre=delPtr;
            delPtr=delPtr->node;

        }
        Pre->node=delPtr->node;
        delete delPtr ;

    }
}
template <typename T>
void Linked_list<T> :: Delete_back(){
    if (isEmpty()){
        return void (cout<<"The Linked list is empty\n");
    }
    else if (head->node == nullptr){
        delete head;
        head =nullptr;
    }
    else{
        Node <T>*delPtr=head,*Pre=nullptr;
        while (delPtr->node != nullptr){
            Pre=delPtr;
            delPtr=delPtr->node;
        }
        Pre->node =nullptr;
        delete delPtr ;
    }
}
template <typename T>
void Linked_list<T> :: print(){
    Node<T> *temp=new Node<T> ();
    temp=head ;
    while (temp->node  != nullptr){
        cout<<temp->data <<" ";
        temp=temp->node ;
    }
    cout<<temp->data ;
    //delete temp;
    cout<<"\n";
}
template <typename T>
Linked_list <T>:: ~Linked_list(){
    Node<T> * delPtr=head;
    while (delPtr->node !=nullptr){
        head =head->node ;
        delete delPtr ;
        delPtr=head;
    }
    head=nullptr;
}