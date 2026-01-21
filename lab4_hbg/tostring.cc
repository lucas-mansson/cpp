#include "date.h"
#include <sstream>
#include <iostream>
#include <istream>
#include <ostream>


template <typename T>
std::string toString(const T& obj){
    std::ostringstream oss;
    oss << obj;
    return oss.str();
}

int main(){
    double d = 1.234;
    Date today;
    std::string sd = toString(d);
    std::string st = toString(today);
    std::cout << sd << std::endl;
    std::cout << st << std::endl;
}