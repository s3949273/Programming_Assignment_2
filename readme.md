# What are the files which weren't given in the skeleton code:
There are some files which we deemed necessary to help make the code a bit easier
to read. These files include:
**CashRegister.cpp and Cashregister.h**



# What to run for the automated test
As required by the specs, the ppd file contains the actual functioning code.
The make file should be sufficient to make the the ppd exectuable.


# What is the RunTestCase.cpp file?
The RunTestCase.cpp file is used to run a particular test case which is inputted by the user, the following instructions provide more details.

## Running the RunTestCase.cpp file
g++ -Wall -Werror -std=c++14 -O -o test Coin.cpp LinkedList.cpp Node.cpp Helper.cpp CashRegister.cpp RunTestCase.cpp 
