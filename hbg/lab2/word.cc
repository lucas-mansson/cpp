#include <string>
#include <vector>
#include <algorithm>
#include "word.h"

using namespace std;
using std::vector;
using std::string;

string word;
vector<std::string> trigrams;

/* Creates a word w with the sorted trigrams t */
Word::Word(const string& w, const vector<string>& t) {
	trigrams = t;
	word = w;
	sort(trigrams.begin(), trigrams.end());
}

/* Returns the word */
string Word::get_word() const {
	return word;
}

/* Returns how many of the trigrams in t that are present
in this word’s trigram vector */
unsigned int Word::get_matches(const vector<string>& t) const {
	int matches = 0;
	size_t i = 0;
	size_t j = 0;
	
	while(i < trigrams.size() && j < t.size()){
		if (trigrams[i] == t[j]) {
            matches++;      
            i++;          
            j++;
        } else if (trigrams[i] < t[j]) {
            i++;          
        } else {
            j++;          
        }
	}
	return matches;
}
