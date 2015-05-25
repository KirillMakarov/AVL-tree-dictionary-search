#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

class HashTable{
private:
	static const unsigned int size_of_table = 19162;//N=10 Выделять паять нужно динамически, так у меня падает со stackoverflow
	forward_list<string> hash_table[size_of_table];
	unsigned int hash (const string& key);

	double average_length;

public:
	void insert(const string& key);
	bool find(const string& key);
	HashTable():average_length(0.0){}
	~HashTable(){}
	pair<size_t, size_t> getMinMaxLengthOfChain();
	double getAverage();
};