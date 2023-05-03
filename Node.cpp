#include "Node.h"
#include <iostream>


using std::cout;
using std::endl;

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

Stock::Stock(string id, string name, string description, Price price, unsigned int on_hand):id(id), name(name), description(description),price(price), on_hand(on_hand){
};
Stock::~Stock(){
    cout<<"deconstructor called for stock"<<endl;
}
Price::~Price(){
    cout<<"deconstructor called for price"<<endl;
}

// };

Node::Node(Stock* stock):data(stock), next(nullptr){
};

Node::~Node(){
    cout<<"destructor was called for node;"<<endl;
    
    delete this->data;  
    // if(this->next != nullptr){
    //     delete this->next;
    // }
    // cout<<this->data->id<<endl;
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