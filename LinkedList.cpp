#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <dirent.h>
#include "helper.h"
#include <fstream> 
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

LinkedList::LinkedList() {
   head = nullptr;
   count = 0;
}

LinkedList::~LinkedList() {
    delete head;
};

// void Linkedlist::open_stock_file(string filepath){
//     try{
//         ifstream stocks(filepath);
//         string line_stock;
//         vector<string> output_stock;
//         while (getline(stocks, line_stock)){
//             Helper::splitString(line_stock, output_stock, "|");
//             if(output_stock.size() >5){
//                 throw std::invalid_argument("too many attributes given to build a stock object");
//             }else{
//                 vector<string> given_price;
//                 Helper::splitString(output_stock[3],given_price, ".");
//                 if(given_price.size()>2){
//                     throw std::invalid_argument("Price had too many values when split");
//                 }else{
//                     try{
//                         Price* p = new Price(stoi(given_price[0]), stoi(given_price[1]));
//                         Stock* stock = new Stock(output_stock[0],output_stock[1],output_stock[2],*p,std::make_unsigned_t<int>(stoi(output_stock[4])));
//                         Node* new_node = new Node(stock);
//                         this->Append(new_node);
//                     }catch(std::exception& e){
//                         cout<<e.what()<<endl;
//                     }
//                 }
//             }
//             output_stock.clear();
//         }
//         stocks.close();
//     }catch(std::exception& e){
//         cout<<e.what()<<endl;
//     }
// };


Stock* LinkedList::searchID(std::string ID){
    Stock* ret = nullptr;
    Node* head = this->head;
    //found used to prematurely break out of the while loop when the ID is found
    bool found = false;
    if (head != nullptr){
        while (head->next != nullptr && found == false){
            if (ID == head->data->id){
                found = true;
                ret->id = head->data->id;
                ret->description = head->data->description;
                ret->price = head->data->price;
                ret->on_hand = head->data->on_hand;
                ret->name = head->data->name;
            }
            head = head->next;
        }
        //in the case that the head is the tail
        if(ID == head->data->id){
                found = true;   
                ret->id = head->data->id;
                ret->description = head->data->description;
                ret->price = head->data->price;
                ret->on_hand = head->data->on_hand;
                ret->name = head->data->name;
        }
    };
    if (this->head == nullptr && !found){
        //there was literally no stock in the linkedlist
        throw std::out_of_range("No stock in the linkedlist");
    }if (!found){
        //there was stock in the linkedlist but the id wasn't found
        throw std::out_of_range("couldn't find the ID in the stock");
    }
    return ret;
};

bool LinkedList::Append(Node* node){
    bool ret =false;
    if (this->head != nullptr){
        Node* head = this->head;
        while(head->next != nullptr){
            head = head->next;   
        }
        head->next = node;
        this->count ++;
    ret = true;
    }else{
        this->head = node;
        this->count ++;
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