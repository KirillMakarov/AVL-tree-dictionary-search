#include <iostream>
#include <string>

using namespace std;
/*
DJB hash function
*/
class StringHash {
public:
	unsigned int operator()(const string& word) const
	{	
		unsigned int hash = 5381;
		size_t size= word.length();
		for (int i = 0; i < size; i ++){ 
			hash = ((hash << 5) + hash) + (unsigned char)(word[i]);
		}

		return hash;
	}
};