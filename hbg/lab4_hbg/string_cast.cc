#include <iostream>
#include <sstream>
#include <string>
#include "date.h"

using namespace std;

template <typename T>
T string_cast(std::string s){
    stringstream in(s);
    T out;
    in >> out;
    
    if(in.fail() || !in.eof()){
        throw(std::invalid_argument("wrong input " + s));
    }
    return out;
}

int main(){
    try {
        int i = string_cast<int>("123");
        cout << i << endl;
        double d = string_cast<double>("12.34");
        cout << d << endl;
        Date date = string_cast<Date>("2015-01-10");
        cout << date << endl;
        int a = string_cast<int>("123abc");
        cout << a << endl;
    } catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}