#include "TagRemover.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

string text;

TagRemover::TagRemover(istream& in){

    string line;
    string result;
    while(getline(in, line)){
        result += line + "\n";
    }

    text = result;

    //cout << "Input before: " << text << endl;
}

void TagRemover::print(ostream& out){
    text = removeTags();
    text = replaceSpecialCharacters();
    out << text << endl;
}

string TagRemover::removeTags(){

    while(text.find("<") != string::npos){
        auto start = text.find("<");
        auto end = text.find(">") + 1;

        if (end != string::npos) {
            text.erase(start, end - start);
        }
    }

    cout << "Tags removed: " << text << endl;

    return text;
}

string TagRemover:: replaceSpecialCharacters(){

    text = regex_replace(text, regex("&lt;"), "<");
    text = regex_replace(text, regex("&gt;"), ">");
    text = regex_replace(text, regex("&nbsp;"), " ");
    text = regex_replace(text, regex("&amp;"), "&");

    cout << "Replaced special characters: " << text << endl;

    return text;
}
