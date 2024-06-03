#include "Map.h"
#include <iostream>
#include <cstring>

template<typename K, typename V>
Map<K, V>::Map() : capacity(10), size(0) {
	this->entries = new Entry[capacity];
}

template<typename K, typename V>
Map<K, V>::~Map() {
	delete[] entries;
}


template<typename K, typename V>
void Map<K, V>::resize() {
	int newCapacity = capacity * 2;
	Entry* newEntries = new Entry[capacity];

	for (int i = 0; i < size; ++i) {
		newEntries[i] = entries[i];
	}

	delete[] entries;
	entries = newEntries;
	capacity = newCapacity;
}

template<typename K, typename V>
int Map<K, V>::findIndex(const K& key) const {
	for (int i = 0; i < size; ++i) {
		if (entries[i].key == key) {
			return i;
		}
	}
	return -1;
}

template<typename K, typename V>
V& Map<K, V>::operator[](const K& key) {
	int index = findIndex(key);
	if (index != -1) {
		return entries[index].value;
	}

	if (size >= capacity) {
		resize();
	}

	entries[size].key = key;
	entries[size].value = V();
	++size;
	return entries[size - 1].value;
}

template<typename K, typename V>
void Map<K, V>::Set(const K& key, const V& value) {
	(*this)[key] = value;
}

template<typename K, typename V>
bool Map<K, V>::Get(const K& key, const V& value) {
	int index = findIndex(key);
	if (index != -1) {
		value = entries[index].value;
		return true;
	}
	return false;
}

template<typename K, typename V>
int Map<K, V>::Count() const {
	return size;
}

template<typename K, typename V>
void Map<K, V>::Clear() {
	delete[] entries;
	capacity = 10;
	size = 0;
	entries = new Entry[capacity];
}

template<typename K, typename V>
bool Map<K, V>::Delete(const K& key) {
	int index = findIndex(key);
	if (index != -1) {
		for (int i = index; i < size; ++i) {
			entries[i] = entries[i + 1];
		}
		--size;
		return true;
	}
	return false;
}

template<typename K, typename V>
bool Map<K, V>::Includes(const Map<K, V>& map) const {
	for (int i = 0; i < map.size; ++i) {
		if (findIndex(map.entries[i].key) == -1) {
			return false;
		}
	}
	return true;
}

template<typename K, typename V>
Map<K, V>::Iterator::Iterator(const Map<K, V>& map, int index) : map(map), index(index) {}

template<typename K, typename V>
void Map<K, V>::Iterator::operator++() {
	++index;
}

template<typename K, typename V>
std::tuple<K, V&, int> Map<K, V>::Iterator::operator*() const {
	return { map.entries[index].key, map.entries[index].value, index };
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::begin() const {
	return Iterator(*this, 0);
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::end() const {
	return Iterator(*this, size);
}

template class Map<int, const char*>;