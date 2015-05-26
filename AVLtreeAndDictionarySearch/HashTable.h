#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

template <class Key, class HashFunction>
class HashTable{
private:
	static const unsigned int DEFAULT_CAPACITY = 16;//N=10 Выделять паять нужно динамически, так у меня падает со stackoverflow
	static const float load_factor;
	unsigned int capacity;
	forward_list<pair<unsigned int, Key> * >* hash_table;
	unsigned int hash (const Key& key);
	/*
		количество элементов типа Key в хеш-таблице.
	*/
	unsigned int size;
	HashFunction hashFunction;
	void resize(unsigned int new_capacity_value);
public:
	void insert(const Key& key);
	bool find(const Key& key);
	HashTable(): size(0){ 
		capacity = DEFAULT_CAPACITY;
		hash_table = new forward_list<pair<unsigned int, Key>* > [capacity];
	}

	HashTable(unsigned int initial_capacity):size(0) { 
		capacity = initial_capacity;
		hash_table = new forward_list<pair <unsigned int, Key>* > [capacity];
	}
	~HashTable(){
		cout<<"In dest";
		for (int i = 0; i < capacity; i++)
		{
			for (auto it = hash_table[i].begin(); it != hash_table[i].end(); it++)
			{
				delete *it;
			}
		}
		delete [] hash_table;
	}
	pair<size_t, size_t> getMinMaxLengthOfChain();
	double getAverage();
};

#include "HashTable.hpp"
#endif