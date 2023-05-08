#include <iostream>
#include <dirent.h>
#include "LinkedList.h"
#include "CashRegister.h"
#include "helper.h"
#include <fstream> 
#include <string>
#include <list>

#define TAB "   "
#define OPTION_1 "1"
#define OPTION_2 "2"
#define OPTION_3 "3" 
#define OPTION_4 "4" 
#define OPTION_5 "5" 
#define OPTION_6 "6" 
#define OPTION_7 "7" 
#define OPTION_8 "8" 
#define OPTION_9 "9" 

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::list;

/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/

void print_main_menu();

int main(int argc, char **argv)
{
    //Input and output files
    FILE * stdin;
    FILE * stdout;
    //Validating command line arguments
    if (argc != 3){
        throw std::invalid_argument("Invalid number of arguments");
    }
    //Get stock file name
    string stock_file_name = string(argv[1]); 
    //Get coins file name
    string coins_file_name = string(argv[2]); 
    //Create new linked list for stock
    LinkedList* all_stock = new LinkedList();
    //Read stock file
    all_stock->open_stock_file(stock_file_name);
    //Create Cash Register object
    CashRegister* CR = new CashRegister(coins_file_name);
    bool valid_input = true;
    while (valid_input){
        try{
            if (!cin.eof()){print_main_menu();}
            string input = Helper::readInput();
            //User options
            if (input == OPTION_1){
                all_stock->display_stock();
            }
            else if (input == OPTION_2){
                all_stock->purchaseItem(CR);
            }
            //Checks if user has exited the program or user pressed ctrl+d
            else if (input == OPTION_3 || cin.eof()){
                //Update files and save data before clearing memory
                // CR->write_to_coin_file(coins_file_name);
                // all_stock->write_to_stock_file(stock_file_name);
                valid_input = false;
            }
            //Admin options
            else if (input == OPTION_4){
                all_stock->add_item();
            }
            else if (input == OPTION_5){
                all_stock->remove_item();
            }
            else if (input == OPTION_6){
                CR->display_coins();
            }
            else if (input == OPTION_7){
                all_stock->reset_stock_count();
            }
            else if (input == OPTION_8){
                CR->reset_coin_count();
            }
            else if (input == OPTION_9){
                valid_input = false;
            }
            //Checks if user pressed ENTER. If not true, throw an exception.
            else if (!input.empty()) {
                throw std::runtime_error("invalid input");
            }
        }
        catch(std::exception& e){
            cout << e.what() << "\n" << endl;
        }
    }
    //Clear memory here
    delete all_stock;
    delete CR;
    
    return EXIT_SUCCESS;
}


void print_main_menu() {
    cout<<"Main menu:"<<endl;
    cout<<TAB<<"1. Display Items"<<endl;
    cout<<TAB<<"2. Purchase Items"<<endl;
    cout<<TAB<<"3. Save and Exit"<<endl;
    cout<<"Administrator-Only Menu"<<endl;
    cout<<TAB<<"4. Add Item"<<endl;
    cout<<TAB<<"5. Remove Item"<<endl;
    cout<<TAB<<"6. Display Coins"<<endl;
    cout<<TAB<<"7. Reset Stock"<<endl;
    cout<<TAB<<"8. Reset Coins"<<endl;
    cout<<TAB<<"9. Abort program"<<endl;
    cout<<"Select your option (1-9): ";
}