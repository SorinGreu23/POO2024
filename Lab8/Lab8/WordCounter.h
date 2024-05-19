#pragma once
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct WordComparator {
	bool operator()(const pair<string, int> &a, const pair<string, int> &b) const;
};

class WordCounter
{
public:
	WordCounter(const string&);
	void processWords();
	void printSortedWords();

private:
	string phrase;
	vector<string> words;
	map<string, int> wordCount;
	priority_queue<pair<string, int>, vector<pair<string, int>>, WordComparator> pq;
	string separators = " ,?!.";

	void readFile(const string& fileName);
	void splitString();
	void countWords();
	void sortWords();
	string toLowerCase(const string& str);
};

