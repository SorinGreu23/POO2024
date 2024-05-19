#include "WordCounter.h"

int main() {
	WordCounter wc("input.txt");
	wc.processWords();
	wc.printSortedWords();
	return 0;
}