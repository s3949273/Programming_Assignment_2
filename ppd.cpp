#include <iostream>
#include <dirent.h>
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
    cout<<"Administrator-Only Menu"<<endl;
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
            if (cin.eof()){
                throw std::invalid_argument("Input was EOF character");
                
            }
            try{
                ret = stoi(input);
                if (ret >=1 && ret <=9){
                valid_input = true;
                }else{
                    throw std::out_of_range("");
                }
            }catch(std::invalid_argument& e){
                cout<<"you tried to enter a letter"<<endl;
            }
            catch(std::out_of_range& e){
                cout<<"Input was not between 1-9"<<endl;
            }
        }
        catch(std::invalid_argument& e){
            cout << e.what() << "\n" << endl;
            ret = 9;
            valid_input = true;
        }
    
    }
    return ret;
}


int main(int argc, char **argv)
{
    /* validating command line arguments */
    if (argc != 3) {throw std::invalid_argument("invalid number of arguments");}
    LinkedList* all_stock = new LinkedList();
    /* read stock file */
    try{
        string stock_data = string(argv[1]);
        ifstream stocks(stock_data);
        string line_stock;
        vector<string> output_stock;
        while (getline(stocks, line_stock)){
            Helper::splitString(line_stock, output_stock, "|");
            if(output_stock.size() >5){
                throw std::invalid_argument("too many attributes given to build a stock object");
            }else{
                vector<string> given_price;
                Helper::splitString(output_stock[3],given_price, ".");
                if(given_price.size()>2){
                    throw std::invalid_argument("Price had too many values when split");
                }else{
                    try{
                        Price* p = new Price(stoi(given_price[0]), stoi(given_price[1]));
                        Stock* stock = new Stock(output_stock[0],output_stock[1],output_stock[2],*p,std::make_unsigned_t<int>(stoi(output_stock[4])));
                        Node* new_node = new Node(stock);
                        all_stock->Append(new_node);
                    }catch(std::exception& e){
                        cout<<e.what()<<endl;
                    }
                }
            }

            output_stock.clear();
        }
        stocks.close();
    }catch(std::exception& e){
        cout<<e.what()<<endl;
    }
    int user_input =  main_menu_input();
    // cout<<user_input<<endl;
    //user input 9 is quit, and user input -1 is eof char
    while (user_input !=9){
        //main thingy here
        cout<<"well done"<<endl;
        return 0;
    }
    
    


    /* read coin file*/
    // try{
    //     string coins_data = string(argv[2]);
    //     ifstream coins(coins_data);
    //     string line_coins;
    //     unsigned line_counter = 0;
    //     vector<string> output_coins;
    //     while (getline(coins, line_coins)){
    //         vector<string> temp;
    //         Helper::splitString(line_coins, temp, ",");
    //         line_counter +=1;
    //         if (line_counter > 7){
    //             string exception_string = "the lines in the coins file were more than expected, expected 8, got: "+std::to_string(line_counter+1);
    //             throw std::invalid_argument(exception_string);
    //         }
    //         // cout<<output_coins.at(output_coins.size()-2)<<endl;
    //         if(temp.size() > 2){
    //             string exception_string = "the number of items in the line was not 2\n the line was: "+line_coins;
    //             throw std::invalid_argument(exception_string);
    //         }
            
    //     }
    //     coins.close();
        
        
    // }catch(std::exception& e){
    //     cout<<e.what()<<endl;
    // }
    
    // cout<<"finished reading files"<<endl;
    
    // return EXIT_SUCCESS;

}
