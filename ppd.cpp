#include <iostream>
#include <dirent.h>
#include "LinkedList.h"
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
#define DEFAULT_STOCK_LEVEL 20
#define DEFAULT_COINS 5

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

void menu_option_2(LinkedList* stock) {
    if (!cin.eof()) {
        try{
            cout << "Purchase Item" << endl;
            cout << "-------------" << endl;
            cout << "Please enter the id of the item you wish to purchase: ";
            string ID = Helper::readInput();
            //Checks if user pressed ENTER or Ctrl+d
            if (ID.length() == 0 || cin.eof()) {
                throw std::runtime_error("User pressed ENTER/Ctrl+d");
            }
            cout << "Please hand over the money - type in the value of each note/coin in cents" << endl;
            cout << "Press enter or ctrl-d on a new line to cancel this purchase" << endl;
            //Put this in a while loop
            /* 
            cout << "You still need to give us: ";
            string cash_input = Helper::readInput();
            //Checks if user pressed ENTER or Ctrl+d
            if (cash_input.length() == 0 || cin.eof()) {menu_option_2();}
            */
        }
        catch (std::runtime_error& e){
            menu_option_2(stock);
        }
        catch (std::exception& e){
            cout << e.what() << "\n" << endl;
            menu_option_2(stock);
        }
    }
}

int main(int argc, char **argv)
{
    //Input and output files
    FILE * stdin;
    FILE * stdout;
    //Validating command line arguments
    if (argc != 3){throw std::invalid_argument("Invalid number of arguments");}
    LinkedList* all_stock = new LinkedList();
    //Read stock file 
    all_stock->open_stock_file(string(argv[1]));
    bool valid_input = true;
    while (valid_input){
        try{
            if (!cin.eof()){print_main_menu();}
            string input = Helper::readInput();
            //User options
            if (input == OPTION_1){
                all_stock->display();
            }
            else if (input == OPTION_2){
                menu_option_2(all_stock);
            }
            else if (input == OPTION_3){
                //Update files here
                valid_input = false;
            }
            //Admin options
            else if (input == OPTION_4){}
            else if (input == OPTION_5){}
            else if (input == OPTION_6){}
            else if (input == OPTION_7){}
            else if (input == OPTION_8){}
            else if (input == OPTION_9){
                valid_input = false;
            }
            //Checks if user has terminated the program
            else if (cin.eof()){
                //Update files and save data before clearing memory
                valid_input = false;
            }
            //Checks if user pressed ENTER. If not true, throw an exception.
            else if (input.length() != 0) {
                throw std::runtime_error("invalid input");
            }
        }
        catch(std::exception& e){
            cout << e.what() << "\n" << endl;
        }
        //Clear memory here
        // delete all_stock;
    }

    list<Coin> cash_register;
    /* read coin file*/

    try{
        string coins_data = string(argv[2]);
        ifstream input_coins(coins_data);
        string line_coins;
        vector<string> coins;
        while (getline(input_coins, line_coins)){
            Helper::splitString(line_coins, coins, DELIM);
            cash_register.push_back(Coin(static_cast<Denomination>(stoi(coins[0])), stoi(coins[1])));
        }
        input_coins.close();
        for (list<Coin>::iterator it=cash_register.begin(); it != cash_register.end(); it++){
            it->print();
        }
        
        
    }catch(std::exception& e){
        cout<<e.what()<<endl;
    }
    
    cout<<"finished reading files"<<endl;
    
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
