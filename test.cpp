#include "LinkedList.h"
#include "CashRegister.h"
#include "Node.h"
#include "Coin.h"
#include "helper.h"
#include <iostream>

// using std::cout;
// using std::endl;
// using std::string;



// int main(int argc, char* argv[]){
//     // Coin c = Coin();
//     // CashRegister* cr = new CashRegister(string(argv[2]));   
//     LinkedList* ll = new LinkedList();
//     ll->open_stock_file(string(argv[1]));
//     // ll->insertionsort(false);
//     ll->display_stock();
//     // ll->purchaseItem(cr);
//     // cout<<cr->do_change(100)<<endl;
//     cout<<"back to main menu"<<endl;
    

//     delete ll;
//     return 0;
// }



using std::cout;
using std::endl;
using std::string;



int main(int argc, char* argv[]){
    // int* a = new int(1);
    // int* b = new int(2);
    // cout<<Helper::strip_ID(string("0"))<<endl;
    
    LinkedList* ll = new LinkedList();
    ll->open_stock_file(string(argv[1]));
    
    ll->display_stock();
    // ll->write_to_stock_file();
    
    delete ll;
    return 0;
}