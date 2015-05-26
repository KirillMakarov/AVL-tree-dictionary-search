#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

template <class Key, class HashFunction>
class HashTable{
private:
	static const unsigned int DEFAULT_CAPACITY = 191625;//N=10 Выделять паять нужно динамически, так у меня падает со stackoverflow
	unsigned int capacity;
	forward_list<Key>* hash_table;
	unsigned int hash (const Key& key);
	/*
		количество элементов типа Key в хеш-таблице.
	*/
	unsigned int size;
	HashFunction hashFunction;
public:
	void insert(const Key& key);
	bool find(const Key& key);
	HashTable(): size(0){ 
		capacity = DEFAULT_CAPACITY;
		hash_table = new forward_list<Key> [capacity];
	}

	HashTable(unsigned int initial_capacity):size(0) { 
		capacity = initial_capacity;
		hash_table = new forward_list<Key> [capacity];
	}
	~HashTable(){
		for (int i = 0; i < capacity; i++)
		{
			for (auto it = hash_table[i].begin(); it != hash_table[i].end(); it++)
			{
				(*it) .clear();
			}
		}
		delete [] hash_table;
	}
	pair<size_t, size_t> getMinMaxLengthOfChain();
	double getAverage();
};

#include "HashTable.hpp"
#endif