#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    bool append(Node* node);
    void insert(Node* node, Node* prevNode);
    Node* goToIndex(int Index);
    /*
        params: Node* node: the node before the node you want to delete
    */
    bool remove(Node* node);
    
    //handles the payment in purchase item
    void insertionsort(bool SortBy);
    int pay(int x,std::vector<Coin*> till);
    void write_to_stock_file();
    void write_to_coin_file();
    bool purchase_item(std::vector<Coin*> till);
    bool pop();
    void display_item(string ID);
    void display();
    void open_stock_file(string filepath);
    string get_Lowest_ID();
    bool add_item();
    Node* searchID(string ID);
    bool remove_item();
    Node* get_node(size_t index);
    unsigned get_count();
private:
    // the beginning of the list
    Node* head;
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H


