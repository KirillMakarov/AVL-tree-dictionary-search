#include "HashTable.h"

unsigned int HashTable::hash(const string & word){
	unsigned int h_val = 0;
	size_t size= word.length();
	for (int i = 0; i < size; i ++){
		h_val = 31* h_val + word[i];
	}
	return h_val % size_of_table;
}

void HashTable::insert(const string & word){
	unsigned int index_in_table = hash(word);
	for (auto it = hash_table[index_in_table].begin(); it != hash_table[index_in_table].end();it++)
	{
		if (*it == word) return; //проверка на уникальность
	}
	hash_table[index_in_table].push_front(word);
	average_length = average_length + (1.0/size_of_table);
}

bool HashTable::find(const string & word) {
	unsigned int index_in_table = hash(word);
	for (auto it = hash_table[index_in_table].begin(); it != hash_table[index_in_table].end();it++)
	{
		if (*it == word) return true; //проверка на уникальность
	}
	return false;
}


pair<size_t, size_t> HashTable::getMinMaxLengthOfChain(){
	//min, max
	pair<size_t, size_t> minmax(INT_MAX, 0);
	for (int i = 0; i < size_of_table; i++){
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

double HashTable::getAverage(){
	return average_length;
}