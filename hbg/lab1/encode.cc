#include <iostream>
#include <string>
#include <fstream>
#include "coding.h"

unsigned char encode(unsigned char c);

int main(int argc, const char** argv)
{
    std::string filename;

    std::cout << "Enter file name: ";
    std::cin >> filename;

    std::ifstream in(filename);
    std::ofstream out(filename + ".enc");

    char ch;
    while (in.get(ch)) {
        out.put(encode(ch));
    } 

    return 0;
}

unsigned char encode(unsigned char c) {
    return c + 1; 
}