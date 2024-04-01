#pragma once
#include <vector>
#include <initializer_list>
#include <string>
#include <time.h>
#include <cstdarg>
using namespace std;

class Sort
{
private:
    vector<int> elements;

    void insertSortImpl(bool ascendent);
    void quickSortImpl(int low, int high, bool ascendent);
    int partitionare(int low, int high, bool ascendent);
    void bubbleSortImpl(bool ascendent);
public:
    Sort(int count, int minimum, int maximum);
    Sort(initializer_list<int> list);
    Sort(const vector<int> &v, int count);
    Sort(int count, ...);
    Sort(const char* numbers);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount() const;
    int GetElementFromIndex(int index) const;
};

