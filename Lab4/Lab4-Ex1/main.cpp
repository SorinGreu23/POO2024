#include "Sort.h"
#include <iostream>

int main()
{
    Sort sortRandom(10, 1, 100);
    cout << "Vector random: ";
    sortRandom.Print();
    sortRandom.BubbleSort(true);
    cout << "Bubble Sort aplicat pe sortRandom (ascendent): ";
    sortRandom.Print();

    Sort sortList({ 5, 1, 4, 2, 8 });
    cout << "\nVector din lista de initializare: ";
    sortList.Print();
    cout<<"Indexul nr. 2 din lista: "<< sortList.GetElementFromIndex(2)<<endl;
    cout << "Total elemente: " << sortList.GetElementsCount() << endl;
    cout << "QuickSort aplicat pe sortList (ascendent): ";
    sortList.QuickSort(true);
    sortList.Print();

    vector<int> vec = { 50, 20, 60, 10, 30 };
    Sort sortVector(vec, 5);
    cout << "\nVector din vector<int>: ";
    sortVector.Print();
    sortVector.InsertSort(true);
    cout << "Insert Sort aplicat pe sortVector (ascendent): ";
    sortVector.Print();

    Sort sortVariadic(5, 55, 22, 88, 66, 44);
    cout << "\nVector din parametri variadici: ";
    sortVariadic.Print();
    sortVariadic.BubbleSort(); // sortare descending, aplicata in mod implicit
    cout << "Bubble Sort aplicat pe sortVariadic (descendent): ";
    sortVariadic.Print();
    cout << endl;

    Sort sortString("10,40,100,5,70");
    cout << "Vector din string: ";
    sortString.Print();
    cout << "Quick Sort aplicat pe vector creat din string (descendent): ";
    sortString.QuickSort(false);
    sortString.Print();
}
