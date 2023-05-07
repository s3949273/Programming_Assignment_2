#include "LinkedList.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <dirent.h>
#include "helper.h"
#include <fstream> 
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;
using std::ofstream;
LinkedList::LinkedList() {
   this->head = nullptr;
   this->count = 0;
}

LinkedList::~LinkedList() {
    Node* head = this->head;
    if (this->head != nullptr){
        for(unsigned x = 0; x<this->count; x++){
            Node* cur = head;
            head = head->next;
            delete cur;
            cur = nullptr;
        }
    }
    
};

unsigned LinkedList::get_count(){
    return this->count;
}

void LinkedList::insert(Node* node, Node* prevNode){
    if (prevNode == nullptr){
        node->next  = this->head;
        this->head =  node;        
    }else{
        node->next  = prevNode->next;
        prevNode->next = node;        
    }
}

// string LinkedList::get_Lowest_ID(){
//     for i in range LinkedList

// }
void LinkedList::insertionsort(bool SortBy){
    Node* currentNode = this->head;
    for (size_t i = 1;i<this->count;i++){
        currentNode = currentNode->next;
        Node* comparisonNode = this->head;
        Node* previousNode = nullptr;
        size_t j = 0;
        if (SortBy){// sort by Name
        while (currentNode->data->name  > comparisonNode->data->name && j<i){
            previousNode = comparisonNode;
            comparisonNode = comparisonNode->next;
            j++;
        }
        }else{// sort by ID
            while (currentNode->data->id  > comparisonNode->data->id && j<i){
            previousNode = comparisonNode;
            comparisonNode = comparisonNode->next;
            j++;
        }
        }
        if (j != i){
            this->get_node(i-1)->next = currentNode->next;
            this->insert(currentNode,previousNode);
            currentNode = this->get_node(i);
        }
    }

} 

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
                        Stock* stock = new Stock(output_stock[0],output_stock[1],output_stock[2],Price(stoi(given_price[0]), stoi(given_price[1])),(stoi(output_stock[4])));
                        Node* new_node = new Node(stock);
                        this->append(new_node);
                    }catch(std::exception& e){
                        cout<<e.what()<<endl;
                    }
                }
            }
            output_stock.clear();
        }
        
        stocks.close();
        // cout<<"Successfully read stock file and created Linkedlist Nodes"<<endl;
    }catch(std::exception& e){
        cout<<e.what()<<endl;
    }
};

Node* LinkedList::searchID(std::string ID){
    Node* ret = nullptr;
    Node* head = this->head;
    //found used to prematurely break out of the while loop when the ID is found
    bool found = false;
    if (head != nullptr){
        while (head->next != nullptr && found == false){
            if (ID == head->data->id){
                found = true;
                ret = head;
            }
            head = head->next;
        }
        //in the case that the head is the tail
        if(ID == head->data->id){
                found = true;   
                ret = head;
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
int LinkedList::pay(int price, vector<Coin*> till){
    //valid denoms to check whether the payment being received is a valid denomination
    cout<<"Please hand over the money - type in the value of each note/coin in cents"<<endl;
    cout<<"Please press Enter or ctrl-d on a new line to cancel the payment"<<endl;
    int ret = price;
    // bool enough_money = false;
    bool enter_pressed = false;
    cout<<"You need to give us:"<<price/100.0<<endl;
    string input = Helper::strip(Helper::readInput());
    vector<unsigned> valid_denoms{5,10,20,50,100,200,500,1000};
    while(price > 0 && !enter_pressed){
        if(input.size() == 0){
            //if enter is pressed, we don't want to do anything else
            enter_pressed= true;
        }else{ 
            if(Helper::isNumber(input)){
                unsigned given = stoi(input);
                if(Helper::is_valid_denom(given)){
                    price -= given;
                }else{
                    cout<<given<<" was not a valid denomination"<<endl;
                }
            }else{
                cout<<"You entered"<<input<<"it is not a valid denominations"<<endl;
            }
            if(price > 0){
                cout<<"You still need to give us:"<<price/100.0<<endl;
                input = Helper::strip(Helper::readInput());
            }

        }
    }
    if (price == 0){
        ret = 0;
    }
    else if (price < 0){
        //the program needs to do change management
        cout<<"you are entitled to change!"<<endl;
        ret = price;
    }
    return ret;
}
bool LinkedList::purchase_item(vector<Coin*> till){
    //till represents the coins in the register
    bool ret = false;
    cout<<"please enter the ID of the item you'd like to buy:";
    string id = Helper::strip(Helper::readInput());
    try{
        Node* n = this->searchID(id);
        if(n->data->on_hand > 0){
            cout<<"Sorry there is not sufficient stock of the item you want to purchase"<<endl;
        cout<<"You have selected:"<<endl;
        cout<<"\tName: "<<n->data->name<<endl;
        cout<<"\tDescription: "<<n->data->description<<endl;
        cout<<"this will cost you:";
        n->data->price.display();
        unsigned price = n->data->price.dollars*100+ n->data->price.cents;
        int paid = this->pay(price, till);
            if(paid == 0){
                ret = true;
            }else if(paid <0){
                if(Helper::do_change(paid, till).size() != 0){
                    cout<<"Here is your"<<n->data->name<<" and your change: "<<paid<<": "+Helper::do_change(paid, till);
                    ret = true;
                }else{
                    cout<<"There wasn't enough coins in the register to give you your change, here's all of the coins you gave us"<<endl;
                    
                }
            }
        }else{
            cout<<"sorry there isn't sufficient stock for the item you want to purchase"<<endl;
        }
    }catch (std::out_of_range & e){
        cout<<e.what()<<endl;
    }
    return ret;
}

Node* LinkedList::get_node(size_t index){
    Node* ret = nullptr;
    if (index <= this->count){
        //only do something if the index the person wants to 
        //get to is less than the size of the linkedlist
        ret = this->head;
        while (ret->next!= nullptr && index > 0){
            ret = ret->next;
            index --;
        }
    }
    return ret;
}

//REQ 8
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
void LinkedList::write_to_stock_file(){
    insertionsort(false);
    Node* curNode = this->head;
    string s = "";
    while(curNode != nullptr){
        s += curNode->data->id + "|"+curNode->data->name + "|" + curNode->data->description + "|" + std::to_string(curNode->data->price.dollars);
        s += "." + std::to_string(curNode->data->price.cents) + "|" + std::to_string(curNode->data->on_hand) + "\n";
        curNode = curNode->next;
    }
    ofstream MyFile("stock.dat");
    MyFile << s;
    MyFile.close();
    
}
void LinkedList::write_to_coin_file(){

}

void LinkedList::display(){
    insertionsort(true);
    cout<<"Items Menu"<<endl;
    cout<<"----------"<<endl;
    cout.width(46);
    cout<<std::left<<"ID   | Name";
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