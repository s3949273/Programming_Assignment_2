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
Price::Price(unsigned dollars, unsigned cents){
    this->dollars = dollars;
    this->cents = cents;
}
void Price::display(){
    cout<<"$"<<this->dollars<<".";
    if (this->cents < 10){
        cout<<"0";
    }
    cout<<cents<<endl;
}

Stock::Stock(string id, string name, string description, Price price, unsigned on_hand):id(id), name(name), description(description),price(price), on_hand(on_hand){
    
    // this->id = id;
    // this->name = name;
    // this->description = description;
    // this->price = price;
    // this->on_hand = on_hand;
};

// };

Node::Node(Stock* stock):data(stock), next(nullptr){
    // this->data = stock;
    // this->next = nullptr;
};

Node::~Node(){
    cout<<"destructor was called"<<endl;
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