#include "Sort.h"
#include <iostream>
#pragma warning (disable : 4996)

Sort::Sort(const char* numbers) {
	char* numbersCopy = new char[strlen(numbers) + 1];
	strcpy(numbersCopy, numbers);

	char* token = strtok(numbersCopy, ",");
	while (token != nullptr) {
		elements.push_back(atoi(token));
		token = strtok(nullptr, ",");
	}

	delete[] numbersCopy;
}

Sort::Sort(int count, int min, int max) : elements(count) {
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int& element : elements) {
		element = min + rand() % (max - min + 1);
	}
}

Sort::Sort(initializer_list<int> list) : elements(list) {}

Sort::Sort(const vector<int>& v, int count) {
	for (int i = 0; i < count && i < v.size(); ++i) {
		elements.push_back(v[i]);
	}
}

Sort::Sort(int count, ...) {
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		elements.push_back(va_arg(args, int));
	}
	va_end(args);
}

void Sort::Print() {
	for (auto& element : elements) {
		cout << element << " ";
	}
	cout << endl;
}

int Sort::GetElementsCount() const {
	return elements.size();
}

int Sort::GetElementFromIndex(int index) const {
	if (index >= 0 && index <= elements.size()) {
		return elements[index];
	}
	return -1;
}

void Sort::insertSortImpl(bool ascendent) {
	int key, j;
	for (int i = 1; i < elements.size(); i++) {
		key = elements[i];
		j = i - 1;

		// Move elements that are greater than key to one position ahead of their current position
		while (j >= 0 && ((ascendent && elements[j] > key) || (!ascendent && elements[j] < key))) {
			elements[j + 1] = elements[j];
			j = j - 1;
		}
		elements[j + 1] = key;
	}
}

void Sort::quickSortImpl(int low, int high, bool ascendent) {
	if (low < high) {
		int pi = partitionare(low, high, ascendent);

		quickSortImpl(low, pi - 1, ascendent);
		quickSortImpl(pi + 1, high, ascendent);
	}
}

int Sort::partitionare(int low, int high, bool ascendent) {
	int pivot = elements[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if ((ascendent && elements[j] < pivot) || (!ascendent && elements[j] > pivot)) {
			i++;
			swap(elements[i], elements[j]);
		}
	}
	swap(elements[i + 1], elements[high]);
	return (i + 1);
}

void Sort::bubbleSortImpl(bool ascendent) {
	int i, j;
	bool schimb;
	for (i = 0; i < elements.size() - 1; i++) {
		schimb = false;
		for (j = 0; j < elements.size() - i - 1; j++) {
			if ((ascendent && elements[j] > elements[j + 1]) || (!ascendent && elements[j] < elements[j + 1])) {
				swap(elements[j], elements[j + 1]);
				schimb = true;
			}
		}

		if (!schimb)
			break;
	}
}

void Sort::InsertSort(bool ascendent) {
	insertSortImpl(ascendent);
}

void Sort::QuickSort(bool ascendent) {
	quickSortImpl(0, elements.size() - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
	bubbleSortImpl(ascendent);
}