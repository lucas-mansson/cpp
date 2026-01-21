#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using namespace std;

//data structure to store all the words in the dictonary
vector<Word> words[26]; // words[i] = the words with i letters, ignore words longer than 25 letters
constexpr int maxlen{25};

int edit_distance(const string& from, const string& to);

Dictionary::Dictionary() {
	const string inputFile = "words.txt";
	ifstream input(inputFile); //read words.txt

	string line;
	while(getline(input, line)){ //for every line, insert the line in s
		vector<string> v = splitLineIntoVector(line); //split the current line into a vector of strings
		string word = v.front(); //the actual word is the first string in the line
		if(word.length() < maxlen){
			v.erase(v.begin() + 1, v.begin() + 2); //remove the first element (the word) and the second element (nbr of trigrams)
			Word newWord(word, v); //create a new Word, whats left of v is the trigrams
			words[word.length()].push_back(newWord);
		}
	}
	input.close();
}

bool Dictionary::contains(const string& word) const {
	
	vector<Word> v = words[word.length()];

	for(const auto& w : v){
		if(w.get_word() == word){
			return true;
		}
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const{
	vector<string> trigrams = getTrigrams(word); // Get trigrams

	for(size_t i = word.length()-1; i < word.length()+1; ++i){
		vector<Word> v = words[i];
		for (const Word& w : v) {
			if (w.get_matches(trigrams) >= trigrams.size() / 2) {
				suggestions.push_back(w.get_word());
			}
    	}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const{
	sort(suggestions.begin(), suggestions.end(), [&word](const string& a, const string& b){
		return edit_distance(word, a) < edit_distance(word, b);
	});
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const{
	if(suggestions.size() > 5){
		suggestions.resize(5);
	}
}

int edit_distance(const string& from, const string& to){
   	int m = from.length();
	int n = to.length();
 
    int d[maxlen-1][maxlen-1];
 
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
 
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (from[i - 1] == to[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                d[i][j] = 1 + std::min(d[i][j - 1], std::min(d[i - 1][j], d[i - 1][j - 1]));
            }
        }
    }

    return d[m][n];
}  

vector<string> Dictionary::splitLineIntoVector(const string& s){
	stringstream ss(s); //create a stringstream of the line
	vector<string> res; //vector to store each word in the line
	string trigram; //represents each word read in the line
	while(getline(ss, trigram, ' ')){
		res.push_back(trigram);
	}
	return res;
}

vector<string> Dictionary::getTrigrams(const string& word) const{
    vector<string> trigrams;

    for(size_t i = 0; i+2 < word.size(); ++i){
        trigrams.push_back(word.substr(i, 3)); //creates a new substring (starting at i and including 3 letters) and adds to back.
    }

    sort(trigrams.begin(), trigrams.end()); //sorts the vector trigrams in alphabetical order
    return trigrams;
}
