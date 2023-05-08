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
    CashRegister* cr = new CashRegister(string(argv[2]));
    ll->open_stock_file(string(argv[1]));
    ll->display_stock();
    // ll->add_item();
    ll->purchaseItem(cr);
    // ll->display_stock();
    // cr->display_coins();
    ll->write_to_stock_file(argv[1]);
    delete ll;
    // cout<<"done";
    return 0;
}