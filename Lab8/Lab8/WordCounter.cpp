#include "WordCounter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

WordCounter::WordCounter(const string& fileName) {
	readFile(fileName);
}

void WordCounter::processWords() {
	splitString();
	countWords();
}

void WordCounter::printSortedWords() {
	sortWords();
	while (!pq.empty()) {
		const auto& entry = pq.top();
		cout << entry.first << " => " << entry.second << endl;
		pq.pop();
	}
}

void WordCounter::readFile(const string& fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Eroare - fisierul nu poate fi deschis";
		exit(1);
	}

	stringstream buffer;
	buffer << file.rdbuf();
	this->phrase = buffer.str();
	file.close();
}

void WordCounter::splitString() {
	string::size_type start = phrase.find_first_not_of(separators);
	string::size_type end = 0;

	while (start != string::npos) {
		end = phrase.find_first_of(separators, start);
		words.push_back(phrase.substr(start, end - start));
		start = phrase.find_first_not_of(separators, end);
	}
}

void WordCounter::countWords() {
	for (string& word : words) {
		string lowerWord = toLowerCase(word);
		if (!lowerWord.empty()) {
			++wordCount[lowerWord];
		}
	}
}

void WordCounter::sortWords() {
	for (const auto& entry : wordCount) {
		pq.push(entry);
	}
}

string WordCounter::toLowerCase(const string& str) {
	string result;
	for (char ch : str) {
		result += tolower(ch);
	}
	return result;
}

bool WordComparator::operator()(const pair<string, int> &a, const pair<string, int> &b) const {
	if (a.second == b.second) {
		return a.first > b.first; // comparatie lexicografica
	}
	return a.second < b.second; // comparatie bazata pe frecventa aparitiilor
}