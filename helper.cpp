//code taken from assignment 1 template
#include "helper.h"
#include "LinkedList.h"
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;

Helper::Helper(){
}

void Helper::printInvalidInput()
{
    std::cout << "Invalid input.\n" << std::endl;
}

bool Helper::isNumber(string s)
{
    string::const_iterator it = s.begin();
    char dot = '.';
    int nb_dots = 0;
    while (it != s.end()) 
    {
        if (*it == dot)
        {
            nb_dots++;
            if (nb_dots>1)
            {
                break;
            }
        }   
        else if (!isdigit(*it))
        {
            break;
        } 

        ++it;
    }
    return !s.empty() && s[0] != dot && it == s.end();
}

void Helper::splitString(string s, vector<string>& tokens, string delimeter)
{
    tokens.clear();
    char* _s = new char[s.length()+1];
    strcpy(_s, s.c_str());

    char * pch;
    pch = strtok (_s, delimeter.c_str());
    while (pch != NULL)
    {
        tokens.push_back(pch);
        pch = strtok (NULL, delimeter.c_str());
    }
    delete[] _s;
}

string Helper::strip(string s){
    //referenced from https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c 
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());

    return  s;
}

string Helper::readInput()
{
    string input;
    std::getline(std::cin, input);
    std::cout<<std::endl;
    return input;
}
int Helper::str_to_int(string s){
    return std::stoi(s);
}
bool Helper::is_int(string s){
    bool ret = true;   
    ret= Helper::isNumber(s);
    int num_decimal_points=0;
    for(size_t i = 0; i<s.size(); i++){
        //iterate through the entire string and check for a decimal 
        if(s[i] == '.'){
            num_decimal_points+=1;
        }
    }
    if(num_decimal_points > 0){
        ret =false;
    }
    return ret;
}

string Helper::strip_ID(string id){
    id = Helper::strip(id);
    //get rid of the I
    id = id.substr(1,id.size());
    //get rid of the 0;
    //referenced from: https://stackoverflow.com/questions/25726531/how-to-remove-leading-zeros-from-string-using-c 
    id.erase(0,id.find_first_not_of("0"));
    return id;
}

string Helper::generate_ID(int x){
    string id = "I";
    if (x< 10){
        id +="000"+std::to_string(x);
    }
    else if (x < 100 ){
        id +="00"+std::to_string(x);
    }else if (x < 1000){
        id+= "0"+std::to_string(x);
    }else{
        id+=std::to_string(x);
    }
    return id;
}

//