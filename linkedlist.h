#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    //added by me
    bool insert_node(Node* node, int position);
    
    bool delete_node(int position);


    bool pop();

private:
    // the beginning of the list
    Node* head;
    //added by me
    Node* tail;

    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H

