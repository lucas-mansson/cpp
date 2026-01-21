#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> getTrigrams(string& word){
    vector<string> trigrams;

    for(size_t i = 0; i+2 < word.size(); ++i){
        trigrams.push_back(word.substr(i, 3)); //creates a new substring (starting at i and including 3 letters) and adds to back.
    }

    sort(trigrams.begin(), trigrams.end()); //sorts the vector trigrams in alphabetical order
    return trigrams;
}

int main() {
    const string inputFile = "/usr/share/dict/words";
    const string outputFile = "words.txt";

    ifstream input(inputFile);
    ofstream output(outputFile);

    string word;

    while(getline(input, word)){ //standard library function that reads each line from file input and assigns the line to "word"
        transform(word.begin(), word.end(), word.begin(), ::tolower); //converts string to lower case

        vector<string> trigrams = getTrigrams(word); //get a vector containing all the trigrams

        output << word << " " << trigrams.size(); // writes the word and number of trigrams to the output file

        for(string& trigram: trigrams){
            output << " " << trigram; //for-each-loop that writes all the strings in our vector to the output file
        }

        output << endl; //ends the line
    }
    return 0;
}