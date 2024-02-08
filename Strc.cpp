#include <iostream>
#include "struct.cpp"
using namespace std ;

int main(){
    cout<<"Hello! Welcome to your list \n";
    Linked_list<string> my_list;
    cout<<"IF you want to Insert in front of  the List enter 1\n"
          "IF you want to Insert in Back of the List enter 2\n"
          "IF you want to Insert special item before another item on  the List enter 3\n"
          "IF you want to know the size of the List enter 4\n"
          "IF you want to Delete the first item of the List enter 5\n"
          "IF you want to Delete special item on the List enter 6\n"
          "IF you want to Delete the last item on the List enter 7\n"
          "IF you want to know the item exists or not on the List enter 8\n"
          "IF you want to Print the List enter 9\n"
          "IF you want to close the List enter 10\n";
    int option;
    string new_item,old_item , item;
    while (option != 10){
        cout<<"Enter the number of  operation you want  \n";
        cin>>option;
        if (option == 1){
            cout<<"Please enter item\n";
            cin>>new_item;
            my_list.Insert_First(new_item);
        }
        else if (option == 2){
            cout<<"Please enter item\n";
            cin>>new_item;
            my_list.Insert_Last(new_item);
        }
        else if (option == 3){
            cout<<"Please enter old item and new item \n";
            cin>>old_item>>new_item;
            my_list.InsertBefore(old_item , new_item);
        }
        else if (option == 4){
            cout<<"The Size of list is "<<my_list.Size()<<"\n";
        }
        else if (option == 5){
            my_list.Delete_front();
        }
        else if (option == 6){
            cout<<"Enter the item you want to delete it \n";
            cin>>item;
            my_list.Delete_item(item);
        }
        else if (option == 7){
            my_list.Delete_back();
        }
        else if (option == 8){
            cout<<"Enter the item\n";
            cin>>item;
            bool test =my_list.found(item);
            if (test)
                cout<<"The item is found \n";
            else
                cout<<"The item is not found \n";
        }
        else if (option == 9){
            my_list.print();
        }
    }
    return 0;
}