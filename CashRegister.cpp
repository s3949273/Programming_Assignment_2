#include "CashRegister.h"
#include <iostream>
#include <fstream> 

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

CashRegister::CashRegister(){
    this->coins.resize(8);
    this->max_coin_value = 0;
}
CashRegister::CashRegister(string filepath){
    this->coins.resize(8);
    this->parse_coin_file(filepath);
    this->max_coin_value = this->get_max_coin_value();
}
int CashRegister::get_index_for_denom(unsigned x){
    int ret = 0;
    if(x == 10){
        ret = 1;
    }else if(x == 20){
        ret = 2;
    }else if(x == 50){
        ret = 3;
    }else if(x == 100){
        ret = 4;
    }else if(x == 200){
        ret = 5;
    }else if(x == 500){
        ret = 6;
    }else if(x == 1000){
        ret = 7;
    }  
    return ret;
};
void CashRegister::parse_coin_file(std::string filepath){
    ifstream coins(filepath);
    std::string line_coins;
    vector<string> output_coins;
    std::vector<Coin*> ret(8);
    try{
        cout<<"trying to open: "<<filepath<<endl;
        int counter = 0;
        while (getline(coins, line_coins)){
            Helper::splitString(line_coins, output_coins, ",");
            if (output_coins.size() > 2){
                string error_message = "too many attributes given to build coin object at line: "+std::to_string(counter+1);
                throw std::invalid_argument(error_message);
            }else{
                output_coins[0] = Helper::strip(output_coins.at(0));
                output_coins[1] = Helper::strip(output_coins.at(1));
                if(Helper::is_int(output_coins.at(0)) && Helper::is_int(output_coins.at(1))){
                    int i_denom = stoi(output_coins.at(0));
                    if(Helper::is_valid_denom(i_denom)){
                        Denomination denom = Coin::unit_to_Denomination(i_denom);
                        this->coins.at(this->get_index_for_denom(denom)) = (new Coin(denom, stoi(output_coins.at(1))));
                    }else{
                        string error_message = "denomination given was not valid at line: "+std::to_string(counter+1);
                        throw std::invalid_argument(error_message);
                    }
                }else{
                    string error_message = "one of the argument of the coin object being built had either a decimal or a letter in it at line: "+std::to_string(counter+1);
                    throw std::invalid_argument(error_message);
                }
            }
            counter ++;
        }
        coins.close();
    }
    catch(std::invalid_argument& e){
        cout<<e.what()<<endl;
    }



}

void CashRegister::write_to_coin_file(){
 //TOD
}
int CashRegister::get_max_coin_value(){
    int ret = 0;
    for(size_t x =0; x<this->coins.size(); x++){
        ret+= this->coins.at(x)->denom*this->coins.at(x)->count;
    }
    return ret;
}

void CashRegister::reset_coin_count(){
    for(size_t x = 0; x<this->coins.size(); x++){
        this->coins.at(x)->count = DEFAULT_COIN_COUNT;
    }
    this->max_coin_value = this->get_max_coin_value();
}

bool CashRegister::do_change(int cents){
    bool ret = false;
    //we may not want to change incoming value of cents incase something goes wrong
    int change = cents;
    if(cents <= this->max_coin_value){
        //there are enough coins in the register to be able to accomodate the change
        size_t counter = 7;
        while(change > 0 && counter >0){
            while((double(change)/this->coins.at(counter)->denom) >= 1 && this->coins.at(counter)->count> 0){
                change -= this->coins.at(counter)->denom;
                cout<<"denom is: "<<this->coins.at(counter)->denom<<endl;
                cout<<"change is: "<<change<<" ";
                this->coins.at(counter)->count --;
            }
            counter--;
        }
        cout<<endl;
        if(change ==0){
            ret = true;
        }
    }
    
    return ret;
}


void CashRegister::display_coins(){
    for(size_t x = 0; x<this->coins.size(); x++){
        cout<<this->coins.at(x)->denom<<" ";
        cout<<this->coins.at(x)->count<<endl;
    }
}