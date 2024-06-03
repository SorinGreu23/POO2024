#ifndef MAP_H
#define MAP_H

#include <tuple>

template<typename K, typename V>
class Map {
private:
	struct Entry {
		K key;
		V value;
	};

	Entry* entries;
	int capacity;
	int size;
	void resize();
	int findIndex(const K& key) const;
public:
	Map();
	~Map();
	V& operator[](const K& key);
	void Set(const K& key, const V& value);
	bool Get(const K& key, V& value) const;
	int Count() const;
	void Clear();
	bool Delete(const K& key);
	bool Includes(const Map<K, V>& map) const;

	class Iterator {
	private:
		const Map<K, V>& map;
		int index;

	public:
		Iterator(const Map<K, V>& map, int index);
		bool operator!=(const Iterator& other) const;
		void operator++();
		std::tuple<const K&, V&, int> operator*() const;
	};

	Iterator begin() const;
	Iterator end() const;
};

template<typename K, typename V>
Map<K, V>::Map() : capacity(10), size(0) {
	entries = new Entry[capacity];
}

template<typename K, typename V>
Map<K, V>::~Map() {
	delete[] entries;
}

template<typename K, typename V>
void Map<K, V>::resize() {
	int newCapacity = capacity * 2;
	Entry* newEntries = new Entry[newCapacity];

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
bool Map<K, V>::Get(const K& key, V& value) const {
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
		for (int i = index; i < size - 1; ++i) {
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
bool Map<K, V>::Iterator::operator!=(const Iterator& other) const {
	return index != other.index;
}

template<typename K, typename V>
void Map<K, V>::Iterator::operator++() {
	++index;
}

template<typename K, typename V>
std::tuple<const K&, V&, int> Map<K, V>::Iterator::operator*() const {
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

#endif // MAP_H
