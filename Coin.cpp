#include "Coin.h"
#include <iostream>

Coin::Coin(){}

Coin::Coin(Denomination denom, unsigned count){
    this->denom = denom;
    this->count = count;
}

void Coin::print(){
    std::cout << "Denomination: " << this->denom << std::endl;
    std::cout << "Count: " << this->count << std::endl; 
}