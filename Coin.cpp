#include "Coin.h"
#include <iostream>
#include <vector>

using std::vector; 
 // implement functions for managing coins; this may depend on your design.
Coin::Coin(unsigned cents, unsigned amount){
    //


    vector<int> denominations{5,10,20,50, 100, 200, 500, 1000};
    size_t index = 7;
    bool denom_found = false;   
    this->count = amount;
    
    while (!denom_found && index >=0){
        if(cents % denominations[index]==0){
            //use of static_cast referenced from: https://stackoverflow.com/questions/321801/enum-c-get-by-index 
            /*
                
            */
            
               this->denom = static_cast<Denomination>(index);
                denom_found = true;
        }
        else{
            index -=1;
        }
    }
    std::cout<<std::endl;
    std::cout<<float(cents / denominations[index])<<std::endl;


}