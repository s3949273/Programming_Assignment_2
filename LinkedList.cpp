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
using std::vector;
using std::string;

LinkedList::LinkedList() {
   head = nullptr;
   count = 0;
}

LinkedList::~LinkedList() {
    Node* head = this->head;
    while(head->next != nullptr){
        Node* cur = head;
        head = head->next;
        delete cur;
        cur = nullptr;
    }
};

void LinkedList::open_stock_file(string filepath){
    try{
        ifstream stocks(filepath);
        string line_stock;
        vector<string> output_stock;
        while (getline(stocks, line_stock)){
            Helper::splitString(line_stock, output_stock, "|");
            if(output_stock.size() >5){
                throw std::invalid_argument("too many attributes given to build a stock object");
            }else{
                vector<string> given_price;
                Helper::splitString(output_stock[3],given_price, ".");
                if(given_price.size()>2){
                    throw std::invalid_argument("Price had too many values when split");
                }else{
                    try{
                        cout<<output_stock[0]<<endl;
                        Stock* stock = new Stock(output_stock[0],output_stock[1],output_stock[2],Price(stoi(given_price[0]), stoi(given_price[1])),std::make_unsigned_t<int>(stoi(output_stock[4])));
                        Node* new_node = new Node(stock);
                        this->append(new_node);
                        this->count ++;
                    }catch(std::exception& e){
                        cout<<e.what()<<endl;
                    }
                }
            }
            output_stock.clear();
        }
        stocks.close();
    }catch(std::exception& e){
        cout<<e.what()<<endl;
    }
};

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
//REQ 7
bool LinkedList::add_item(){
    bool ret = false;  
    string id = Helper::generate_ID(count); 
    //name input
    cout<<"Enter item name: ";
    string name_input = Helper::readInput();
    cout<<name_input<<endl; 
    //item description input
    cout<<"Enter item description: ";
    string desc_input = Helper::readInput();
    cout<<desc_input<<endl; 
    //item price input
    cout<<"Enter the price for the item: ";
    string price_input = Helper::readInput();
    vector<string> price_split;
    Helper::splitString(price_input, price_split, ".");
    if (price_split.size() < 2|| price_split.size() > 2){
        cout<<"Sorry, price was not correctly formatted";
    }else{
        Stock* new_stock = new Stock(id, name_input, desc_input, Price(stoi(price_split[0]), stoi(price_split[1])), 50);
        Node* new_node = new Node(new_stock);
        this->append(new_node);
        this->count ++;
    }



    return ret;
};

//REQ 5
bool LinkedList::purchase_item(string ID){
    return false;
}

Node* LinkedList::get_node(size_t index){
    Node* ret = nullptr;
    if (index < this->count){
        //only do something if the index the person wants to 
        //get to is less than the size of the linkedlist
        Node* ret = this->head;
        while (ret->next!= nullptr && index > 0){
            ret = ret->next;
            index --;
        }
    }
    return ret;
}


bool LinkedList::remove_item(){
    bool ret = false;
    cout<<"Please enter the ID of the item you'd like to remove: ";
    string id = Helper::readInput();
    if (id.find("I") != string::npos){
        //there was an I in the Id like there's supposed to be so we strip it to get just the number
        id = Helper::strip_ID(id);
        if(Helper::is_int(id)){
            //the remaining id is an integer
            /*
                we want to get to the node before the one we want to remove,
                so that we can destroy the link from the before node to the 
                node afer
            */
            Node* node_to_remove = this->get_node(stoi(id)-1);
            //delete the one we want to delete
            delete node_to_remove->next;
            //create the new link to the one after;
            node_to_remove->next = node_to_remove->next->next;
        }else{
            cout<<"ID was either a letter or a float (it had a decimal point in it)"<<endl;
        }
    }
    return ret;
}
bool LinkedList::append(Node* node){
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

bool LinkedList::remove(Node* node_before_delete){
    bool ret = false; 
    try{
        Node* head = node_before_delete;
        Node* temp = head->next;
        // delete head->next;
        head->next = head->next->next;
        delete temp;
        this->count--;
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