#include "LinkedList.h"
#include "CashRegister.h"
#include "Node.h"
#include "Coin.h"
#include "helper.h"
#include <iostream>

// using std::cout;
// using std::endl;
// using std::string;



using std::cout;
using std::endl;
using std::string;



int main(int argc, char* argv[]){
    // int* a = new int(1);
    // int* b = new int(2);
    // cout<<Helper::strip_ID(string("0"))<<endl;
    
    LinkedList* ll = new LinkedList();
    // CashRegister* cr = new CashRegister(string(argv[2]));
    ll->open_stock_file(string(argv[1]));
    Node* n = new Node(new Stock(string("I0001"), string("0002"), string("none"), Price(0,0), 0));
    Node* n1 = new Node(new Stock(string("I0002"), string("0004"), string("none"), Price(0,0), 0));
    Node* n2 = new Node(new Stock(string("I0003"), string("0001"), string("none"), Price(0,0), 0));
    Node* n3 = new Node(new Stock(string("I0004"), string("0003"), string("none"), Price(0,0), 0));
    
    ll->append(n);
    ll->append(n1);
    ll->append(n2);
    ll->append(n3);
    
    ll->display_stock();
    // ll->purchaseItem();
    
    delete ll;
    return 0;
}