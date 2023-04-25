#include "Node.h"
#include <iostream>


using std::cout;
using std::endl;
// Price::Price(int total, int something_else)
// {   
//     // std::split(total,".");
//     // vector<string> split;
//     // unsigned dollars, cents = temp;   
// };

/**
 * data structure to represent a stock item within the system
 **/


// class Stock
// {
// public:
//     //the unique id for this item
//     std::string id;

//     //the name of this item
//     std::string name;
    
//     //the description of this item   
//     std::string description;
    
//     //the price of this item
//     Price price;
    
//     // how many of this item do we have on hand? 
//     unsigned on_hand;    
// };



// Node::Node():data(new Stock()), next(nullptr){

// };

Node::Node(Stock* stock = new Stock()){
    this->data = stock;
    this->next = nullptr;
};

Node::~Node(){
    delete this->data;
    delete this->next;
};

bool Node::Update(Stock value){
    bool ret = false;
    try{
        this->data = &value;
        ret = true;
    }catch(std::exception& e){
        cout<<"failed to update Node value"<<endl;
    }
    return ret;
}