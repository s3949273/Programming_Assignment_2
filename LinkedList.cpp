#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;
LinkedList::LinkedList() {
   head = nullptr;
   count = 0;
}

LinkedList::~LinkedList() {
    delete head;
}

bool LinkedList::Append(Node* node){
    bool ret =false;
    if (this->head != nullptr){
        Node* head = this->head;
        while(head->next != nullptr){
            head = head->next;   
        }
        head->next = node;
    ret = true;
    }else{
        this->head = node;
    }
    return ret;
}
// bool LinkedList::Insert(Node node, unsigned index){
//     return false;
// }
bool LinkedList::Remove(Node* node_before_delete){
    bool ret = false; 
    try{
        Node* head = node_before_delete;
        Node* temp = head->next;
        // delete head->next;
        head->next = head->next->next;
        delete temp;
        ret = true;
    }
    catch(std::exception& e){
        cout<<e.what()<<endl;
    }
    return ret;
}

bool LinkedList::pop(){
    bool ret = false;
    try{
        Node* head = this->head;
        this->head = this->head->next;
        delete head;

    }catch(std::exception& e){
        cout<<e.what()<<endl;
    }
    return ret;
}

void LinkedList::display(){
    cout<<"Items Menu"<<endl;
    cout<<"----------"<<endl;
    cout.width(46);
    cout<<std::left<<"ID | Name";
    cout<<"| Available | Price"<<endl;
    for (unsigned x=0; x < 65; x++){
        cout<<"-";
    }
    cout<<endl;
    if (this->head == nullptr){
        cout<<"no items to show"<<endl;
    }else{
        Node* head = this->head;
        while (head->next != nullptr){
            Stock* cur = head->data;
            cout<<cur->id<<"|";
            cout.width(40);
            cout<<std::left<<cur->name<<"|";
            cout.width(11);
            cout<<std::left<<cur->on_hand;
            cout<<"| ";
            cur->price.display();
            head = head->next;
        }
        //print the tail
        Stock* cur = head->data;
        cout<<cur->id<<"|";
        cout.width(40);
        cout<<std::left<<cur->name<<"|";
        cout.width(11);
        cout<<std::left<<cur->on_hand;
        cout<<"| ";
        cur->price.display();
        cout<<endl;
    }
}