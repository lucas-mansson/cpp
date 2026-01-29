#include <iostream>
#include <string>
#include <fstream>
#include "coding.h"

unsigned char decode(unsigned char c);

int main(int argc, const char** argv)
{
    std::string filename;

    std::cout << "Enter file name: ";
    std::cin >> filename;

    std::ifstream in(filename);
    std::ofstream out(filename + ".dec");

    char ch;
    while (in.get(ch)) {
        out.put(decode(ch));
    } 

    return 0;
}

unsigned char decode(unsigned char c) {
    return c - 1; 
}