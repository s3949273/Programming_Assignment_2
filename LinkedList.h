#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    bool append(Node* node);
    bool insert(Node node, unsigned index);
    /*
        params: Node* node: the node before the node you want to delete
    */
    bool remove(Node* node);
    
    //handles the payment in purchase item
    bool pay(unsigned cents, unsigned amount);
    bool purchase_item();
    bool pop();

    void display();
    void open_stock_file(string filepath);
    bool add_item();
    Stock* searchID(string ID);
    bool remove_item();
    Node* get_node(size_t index);
private:
    // the beginning of the list
    Node* head;
    Node* tail;
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H


