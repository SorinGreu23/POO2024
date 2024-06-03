#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <algorithm>

class InsufficientCapacityException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Capacitate insuficienta!";
    }
};

class IndexOutOfRangeException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Index in afara domeniului!";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
class ArrayIterator;

template <class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

    void EnsureCapacity(int minCapacity) {
        if (minCapacity > Capacity) {
            throw InsufficientCapacityException();
        }
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size) {
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i) {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    ~Array() {
        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }
        delete[] List;
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfRangeException();
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        EnsureCapacity(Size + 1);
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElement) {
        if (index < 0 || index > Size) {
            throw IndexOutOfRangeException();
        }

        EnsureCapacity(Size + 1);
        for (int i = Size; i > index; --i) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElement);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T>& otherArray) {
        if (index < 0 || index > Size) {
            throw IndexOutOfRangeException();
        }

        EnsureCapacity(Size + otherArray.Size);
        for (int i = Size - 1; i >= index; --i) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; ++i) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) {
            return true;
        }

        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];

        for (int i = 0; i < Size; ++i) {
            List[i] = new T(*otherArray.List[i]);
        }
        return true;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfRangeException();
        }
        delete List[index];
        for (int i = index; i < Size - 1; ++i) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }

    void Sort() {
        std::sort(List, List + Size, [](const T* a, const T* b) {
            return *a < *b;
            });
    }

    void Sort(int(*compare)(const T&, const T&)) {
        std::sort(List, List + Size, [compare](const T* a, const T* b) {
            return compare(*a, *b) < 0;
            });
    }

    void Sort(Compare* comparator) {
        std::sort(List, List + Size, [comparator](const T* a, const T* b) {
            return comparator->CompareElements((void*)a, (void*)b) < 0;
            });
    }

    int BinarySearch(const T& element) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (*List[mid] == element)
                return mid;
            if (*List[mid] < element)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& element, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int compResult = compare(*List[mid], element);
            if (compResult == 0)
                return mid;
            if (compResult < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1; 
    }

    int BinarySearch(const T& element, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int compResult = comparator->CompareElements((void*)List[mid], (void*)&element);
            if (compResult == 0)
                return mid;
            if (compResult < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int Find(const T& element) {
        for (int i = 0; i < Size; ++i) {
            if (*List[i] == element) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& element, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; ++i) {
            if (compare(*List[i], element) == 0) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& element, Compare* comparator) {
        for (int i = 0; i < Size; ++i) {
            if (comparator->CompareElements((void*)List[i], (void*)&element) == 0) {
                return i;
            }
        }
        return -1;
    }

    int GetSize() const {
        return Size;
    }

    int GetCapacity() const {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(this, 0);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(this, Size);
    }
};

template <class T>
class ArrayIterator {
private:
    int Current;
    Array<T>* array;
public:
    ArrayIterator(Array<T>* arr, int current) : array(arr), Current(current) {}

    ArrayIterator& operator++() {
        Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        Current--;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return Current == other.Current;
    }

    bool operator!=(const ArrayIterator<T>& other) const {
        return Current != other.Current;
    }

    T& GetElement() {
        return (*array)[Current];
    }
};

#endif
