#ifndef COIN_H
#define COIN_H

// Coin.h defines the coin structure for managing currency in the system. 
#define DELIM ","  // delimiter 

// enumeration representing the various types of currency available in the system. 
enum Denomination
{
    FIVE_CENTS=0, TEN_CENTS=1, TWENTY_CENTS=2, FIFTY_CENTS=3, ONE_DOLLAR=4, 
    TWO_DOLLARS=5, FIVE_DOLLARS=6, TEN_DOLLARS=7
};


// represents a coin type stored in the cash register perhaps. Each demonination
// will have exactly one of these in the cash register.
class Coin
{
public:
    // the denomination type
    enum Denomination denom;
    
    // the count of how many of these are in the cash register
    unsigned count;

    Coin(unsigned cents, unsigned amount);

};

#endif // COIN_H
