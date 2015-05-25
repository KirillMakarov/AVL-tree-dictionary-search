#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

template <class Key, class HashFunction>
class HashTable{
private:
	static const unsigned int size_of_table = 255500;//N=10 Выделять паять нужно динамически, так у меня падает со stackoverflow
	forward_list<Key>* hash_table;
	unsigned int hash (const Key& key);

	double average_length;
	HashFunction hashFunction;
public:
	void insert(const Key& key);
	bool find(const Key& key);
	HashTable():average_length(0.0){ hash_table = new forward_list<Key> [size_of_table];}
	~HashTable(){
		for (int i = 0; i < size_of_table; i++)
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