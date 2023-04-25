#include <iostream>
#include "LinkedList.h"
#include "helper.h"
#include <fstream> 
#include <string>

#define TAB "   " 

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/

void print_main_menu(){

    cout<<"Main menu:"<<endl;
    cout<<TAB<<"1. Display Items"<<endl;
    cout<<TAB<<"2. Display Items"<<endl;
    cout<<TAB<<"3. Display Items"<<endl;
    cout<<"Administrator-Only Menu";
    cout<<TAB<<"4. Add Item"<<endl;
    cout<<TAB<<"5. Remove Item"<<endl;
    cout<<TAB<<"6. Display Coins"<<endl;
    cout<<TAB<<"7. Reset Stock"<<endl;
    cout<<TAB<<"8. Reset Coins"<<endl;
    cout<<TAB<<"9. Abort program"<<endl;
    cout<<"Select your option (1-9):"<<endl;

}   

int main_menu_input(){
    //main_menu_input will 
    int ret = -1;
    bool valid_input = false;
    while (!valid_input){
        print_main_menu();
        string input = Helper::readInput();
        try{
            if (ret >=1 && ret <=9){
                valid_input = true;
            }else{
                throw std::invalid_argument("Input was not between 1-9");
            }
        }
        catch(std::exception& e){
            cout << e.what() << "\n" << endl;
        }
    }
    return ret;
}



int main(int argc, char **argv)
{
    /* validating command line arguments */
    if (argc != 3) {throw std::invalid_argument("invalid number of arguments");}

    /* read stock file */
    string stock_data = string(argv[1]);
    ifstream stocks(stock_data);
    string line_stock;
    vector<string> output_stock;
    size_t counter = 0;
    while (getline(stocks, line_stock)){
        Helper::splitString(line_stock, output_stock, "|");
        cout << line_stock << endl;
        output_stock.at(counter);
        counter++;
    }
    stocks.close();
    
    /* read coin file*/
    string coins_data = string(argv[2]);
    ifstream coins(coins_data);
    string line_coins;
    vector<string> output_coins;
    
    while (getline(coins, line_coins)){
        Helper::splitString(line_coins, output_coins, ",");
        cout << line_coins << endl;
    }

    stocks.close();


    
    
    return EXIT_SUCCESS;
}
