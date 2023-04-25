#include "Node.h"

Price::Price(int total)
{   
    temp = std::split(total,".");
    unsigned dollars, cents = temp;   
};

/**
 * data structure to represent a stock item within the system
 **/
class Stock
{
public:
    //the unique id for this item
    std::string id;

    //the name of this item
    std::string name;
    
    //the description of this item   
    std::string description;
    
    //the price of this item
    Price price;
    
    // how many of this item do we have on hand? 
    unsigned on_hand;    
};





Node::Node(){
    data = NULL;
    next = NULL;
};
Node::Node(Stock Val):data(&Val), next(nullptr){
};

Node::~Node(){
    // delete Node;
};

bool Node::Update(Stock value){


}