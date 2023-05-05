#include "LinkedList.h"
// #include "Node.h"
// #include "Coin.h"
#include "helper.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;



int main(int argc, char* argv[]){
    // int* a = new int(1);
    // int* b = new int(2);
    // cout<<Helper::strip_ID(string("0"))<<endl;
    
    LinkedList* ll = new LinkedList();

    // ll->open_stock_file(string(argv[1]));
    // 
    // ll->display();
    // ll->add_item();
    // ll->display();
    // ll->add_item();
    Node* n = new Node(new Stock(string("I0001"), string("block"), string("1 node in linkedlist"), Price(1,1), 10));
    Node* n1 = new Node(new Stock(string("I0002"), string("crit"), string("2 node in linkedlist"), Price(1,3), 10));
    Node* n2 = new Node(new Stock(string("I0003"), string("attack"), string("3 node in linkedlist"), Price(1,4), 10));
    ll->append(n);
    ll->append(n1);
    ll->append(n2);
    // ll->test();
    ll->display();
    delete ll;
    return 0;
}