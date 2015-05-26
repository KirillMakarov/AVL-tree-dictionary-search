#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "HashTable.h"

template <class Key, class HashFunction>
const float HashTable<Key, HashFunction>::load_factor = 0.75f;

template <class Key, class HashFunction>
unsigned int HashTable<Key, HashFunction>::hash(const Key& word){
	unsigned int h_val = hashFunction(word);
	return h_val;
}

template <class Key, class HashFunction>
void HashTable<Key, HashFunction>::insert(const Key & word){
	unsigned int hash_of_word = hash(word);
	unsigned int index_in_table = hash_of_word%capacity;
	for (auto it = hash_table[index_in_table].begin(); it != hash_table[index_in_table].end();it++)
	{
		if ((*it)->second == word) return; //проверка на уникальность
	}
	
	hash_table[index_in_table].push_front(new pair<unsigned int, Key>(hash_of_word, word));
	size++;
}

template <class Key, class HashFunction>
bool HashTable<Key, HashFunction>::find(const Key & word) {
	unsigned int hash_of_word = hash(word);
	unsigned int index_in_table = hash_of_word%capacity;
	for (auto it = hash_table[index_in_table].begin(); it != hash_table[index_in_table].end();it++)
	{
		if ((*it)->second == word) return true; //проверка на уникальность
	}
	return false;
}


template <class Key, class HashFunction>
pair<size_t, size_t> HashTable<Key, HashFunction>::getMinMaxLengthOfChain(){
	//min, max
	pair<size_t, size_t> minmax(INT_MAX, 0);
	for (int i = 0; i < capacity; i++){
		size_t length = 0;
		for (auto it = hash_table[i].begin(); it != hash_table[i].end();it++)
		{
			length++;
		}
		if (length > minmax.second) minmax.second=length;
		if (length < minmax.first) minmax.first = length;
	}
	return minmax;
}

template <class Key, class HashFunction>
double HashTable<Key, HashFunction>::getAverage(){
	return (double)size/capacity;
}
#endif