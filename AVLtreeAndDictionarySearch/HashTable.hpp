#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "HashTable.h"

template <class Key, class HashFunction>
const float HashTable<Key, HashFunction>::load_factor = 1.0f;

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

	if (getAverage()>load_factor) resize(2*capacity);
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

template <class Key, class HashFunction>
void HashTable<Key, HashFunction>::resize(unsigned int new_capacity_value){
	forward_list<pair<unsigned int, Key> * >* temp_hashTable = new forward_list<pair<unsigned int, Key> * >  [new_capacity_value];

	for (int i = 0; i < capacity; i++)
		{
			for (auto it = hash_table[i].begin(); it != hash_table[i].end(); it++)
			{
				temp_hashTable[((*it)->first)%new_capacity_value].push_front((*it));
			}
		}

	//указатели на прежние элементы уже лежат в новой таблице.
	//удаляем старые листы.
	delete [] hash_table;
	//теперь hash_table указывает на temp_hashTable
	hash_table = temp_hashTable;
	capacity = new_capacity_value;

}

template <class Key, class HashFunction>
void HashTable<Key, HashFunction>::shrink_to_fit(){
	if (capacity != size && size >= DEFAULT_CAPACITY) 
	{
		resize (size);
	}
}

template <class Key, class HashFunction>
unsigned int HashTable<Key, HashFunction>::getSize(){
	return size;
}

template <class Key, class HashFunction>
unsigned int HashTable<Key, HashFunction>::getCapacity(){
	return capacity;
}

#endif