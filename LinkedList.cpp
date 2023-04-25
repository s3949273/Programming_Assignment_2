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

void LinkedList::print(){
    if (this->head == nullptr){
        cout<<"no nodes to show"<<endl;
    }else{
        Node* head = this->head;
        while (head->next != nullptr){
            Stock* cur = head->data;
            cout<<cur->id<<"|"<<cur->name<<"|"<<cur->description<<"|"<<cur->price.dollars<<"."<<cur->price.cents<<"|"<<cur->on_hand<<endl;
            head = head->next;
        }
        Stock* cur = head->data;
        cout<<cur->id<<"|"<<cur->name<<"|"<<cur->description<<"|"<<cur->price.dollars<<"."<<cur->price.cents<<"|"<<cur->on_hand<<endl;
    }
}