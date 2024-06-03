#include <iostream>
#include "Array.h"
using namespace std;

int CompareInts(const int& a, const int& b) {
    return a - b;
}

class IntComparator : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int* int1 = static_cast<int*>(e1);
        int* int2 = static_cast<int*>(e2);
        return *int1 - *int2;
    }
};

int main() {
    try {
        Array<int> arr(5); 
        arr += 10;
        arr += 20;
        arr += 30;
        arr += 40;
        arr += 50;

        cout << "Array elements after insertion within capacity: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Attempting to insert an element exceeding capacity..." << endl;
        arr += 60; // Linia de cod de aici ar trebui sa arunce o exceptie
    }
    catch (const InsufficientCapacityException& e) {
        cout << "InsufficientCapacityException: " << e.what() << endl;
    }
    catch (const IndexOutOfRangeException& e) {
        cout << "IndexOutOfRangeException: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        Array<int> arr(10);
        arr += 10;
        arr += 20;
        arr += 30;
        arr.Insert(1, 15);

        cout << "After insertion: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Test stergere
        arr.Delete(2);
        cout << "Array elements after deletion: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Test sortare
        arr.Sort();
        cout << "Array elements after sorting: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Test cautare binara
        int index = arr.BinarySearch(20);
        if (index != -1) {
            cout << "Element 20 found at index: " << index << endl;
        }
        else {
            cout << "Element 20 not found!" << endl;
        }

        // Test custom comparator
        IntComparator comparator;
        arr.Sort(&comparator);
        cout << "Array elements after sorting with custom comparator: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Test cautare binara cu comparator custom
        index = arr.BinarySearch(15, &comparator);
        if (index != -1) {
            cout << "Element 15 found at index: " << index << endl;
        }
        else {
            cout << "Element 15 not found!" << endl;
        }

        // Test find
        index = arr.Find(10);
        if (index != -1) {
            cout << "Element 10 found at index: " << index << endl;
        }
        else {
            cout << "Element 10 not found!" << endl;
        }

        cout << arr[10] << endl; // Linia de cod de aici ar trebui sa arunce o exceptie
    }
    catch (const InsufficientCapacityException& e) {
        cout << e.what() << endl;
    }
    catch (const IndexOutOfRangeException& e) {
        cout << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Exceptie: " << e.what() << endl;
    }

    return 0;
}