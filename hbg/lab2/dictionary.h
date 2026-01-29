#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

using namespace std;

class Dictionary {
public:
	Dictionary();
	bool contains(const string& word) const;
	vector<string> get_suggestions(const string& word) const;
private:
	vector<Word> words[26];
	int maxlen{25};

	vector<string> splitLineIntoVector(const string& s);
	vector<string> getTrigrams(const string& word) const;
	void add_trigram_suggestions(vector<string>& suggestions, const string& word) const;
	void rank_suggestions(vector<string>& suggestions, const string& word) const;
	void trim_suggestions(vector<string>& suggestions) const;
	
};

#endif
