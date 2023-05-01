#include "LinkedList.h"
#include "Node.h"
#include "Coin.h"
#include "helper.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
    // int* a = new int(1);
    // int* b = new int(2);



    LinkedList* ll = new LinkedList();
    unsigned a = 1;
    Node* n = new Node(new Stock(string("ID1"), string("node"), string("1 node in linkedlist"), Price(1,1), a));
    Node* n1 = new Node(new Stock(string("ID2"), string("node 1"), string("2 node in linkedlist"), Price(1,3), a+1));
    Node* n2 = new Node(new Stock(string("ID3"), string("node 2"), string("3 node in linkedlist"), Price(1,4), a+2));
    ll->Append(n);
    ll->Append(n1);
    ll->Append(n2);
    ll->display();
    delete ll;
}