#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    bool Append(Node* node);
    bool Insert(Node node, unsigned index);
    /*
        params: Node* node: the node before the node you want to delete
    */
    bool Remove(Node* node);
    bool pop();
    void print();

private:
    // the beginning of the list
    Node* head;
    Node* tail;
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H


