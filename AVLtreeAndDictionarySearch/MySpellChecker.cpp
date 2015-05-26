#ifndef MYSPELLCHECKER_CPP
#define MYSPELLCHECKER_CPP

#include "MySpellChecker.h"
#include <fstream>
#include <algorithm>
#include <cctype>

void MySpellChecker::readCustomFile(string path, AVLtree<string, less<string>> &avl_tree){
	ifstream input_fstream(path);
	string word;
	while (input_fstream)
	{
		input_fstream >> word;
		word = trim_punct(word);
		if (word != "")
			avl_tree.insert(word);
	}
}

void MySpellChecker::readDictionaryFile(string path){
	readCustomFile(path, MySpellChecker::dictionary);
}

void MySpellChecker::readDocumentationFile (string path){
	readCustomFile(path, MySpellChecker::words);
}

void MySpellChecker::compare(){
	recursive_compare(words.getRoot());
}

void MySpellChecker::recursive_compare(AvlNode<string>* node){
	if (node)
	{
		recursive_compare(node->left);
		recursive_compare(node->right);

		string to_find_in_lower_case;
		to_find_in_lower_case = to_lower_case(node->key);
		if (!dictionary.find(to_find_in_lower_case))
		{
			cout<< node -> key<<endl;
		}
	}
}

string MySpellChecker::to_lower_case (const string s)
{
	string result= "";
	for (basic_string<char>::const_iterator i = s.begin(); i!=s.end(); i++)
	{
		result += tolower(*i);
	}
	return result;
}

string MySpellChecker::trim_punct(const string s){
	string result ="";
	for (basic_string<char>::const_iterator i = s.begin(); i!=s.end(); i++)
	{
		if (*i >= 0 && *i <= 255 && (!ispunct(*i) || *i == '-'|| *i=='\'' ))
			result += *i;
	}
	return result;
}

bool MySpellChecker::isAVLTree (){
	return dictionary.isAVLTree();
}

//methods from Part #2
void MySpellChecker::getRecommendations(){
	recursive_recommendations(words.getRoot());
}


//служебный метод меняющий позиции с индексами from и to местами в слове s.
string MySpellChecker::swap_letter (int from, int to, const string& s){
	if (from < 0 || to > s.length() - 1) return s;
	string result = s;
	result[from] = s[to];
	result[to] = s[from];
	return result;
}

//служебный метод, создающий новую строку с удаленным символом под индексом from в слове s.
string MySpellChecker::remove_letter(int from, string &s)
{
	if (from < 0 || from > s.length() - 1) return s;

	string result;
	for (int i = 0; i < s.length(); i++)
	{
		if ( i!= from)
			result+=s[i];
	}
	return result;
}

//служебный метод, вставляющий символ symb после индекса after в строку s.
//чтобы вставить перед нулевым символом, after = -1.
string MySpellChecker::insert_letter_after(int after, char symb, string &s)
{
	if (after < -1 || after > s.length() - 1) return s;

	string result = s.substr(0, after+1) + symb + s.substr(after+1, s.length() - after - 1);
	return result;
}

//Метод определяет, существует ли слово word в словаре. Если существует, то добавляет его в список
//для предложенных слов и выводит на экран, если оно не было добавлено ранее.
void MySpellChecker::check_to_suggest(set<string>& was_suggested, string word) {
	if (was_suggested.find(word)==was_suggested.end() && dictionary.find(word))
	{
		if (was_suggested.size() == 0)
			cout<<word;
		else
			cout<<", "<<word;
		was_suggested.insert(word);
	}
}

void MySpellChecker::recursive_recommendations(AvlNode<string>* node){
	if (node)
	{
		recursive_recommendations(node->left);
		recursive_recommendations(node->right);

		string to_find_in_lower_case;
		to_find_in_lower_case = to_lower_case(node->key);
		if (!dictionary.find(to_find_in_lower_case))
		{
			string& word = to_find_in_lower_case;
			string word_to_suggest = word; // чтобы не испортить слово в словаре
			cout<< word<<"\t\t";

			set<string> was_suggested;

			//#1 Transposing of adjacent letters
			for (int i = 0; i < word.length() - 1; i++)
			{
				string transp_word = swap_letter(i, i+1, word);
				check_to_suggest(was_suggested, transp_word);
			}

			//#2 Removal of each letter
			for (int i = 0; i < word.length(); i++)
			{
				string del_word = remove_letter(i, word);
				check_to_suggest(was_suggested, del_word);
			}

			//#3 Replacement of each letter
			for (char i ='a'; i <= 'z'; i++){
				for (int j = 0; j < word.length(); j++)
				{
					string new_word = word;
					new_word[j] = i;
					check_to_suggest(was_suggested, new_word);
				}
			}

			//#4 Inserting any letter at any position in a word
			for (char i ='a'; i <= 'z'; i++){
				for (int j = -1; j < word.length(); j++)
				{
					string new_word = insert_letter_after(j, i, word);
					check_to_suggest(was_suggested, new_word);
				}
			}
			cout<<endl;
		}
	}
}

//Part III
void MySpellChecker::readDictionaryFileAtHashTable(string path){
	ifstream input_fstream(path);
	string word;
	while (input_fstream)
	{
		input_fstream >> word;
		word = trim_punct(word);
		if (word != "")
			hashTable.insert(word);
	}
}


void MySpellChecker::compareHash(){
	recursive_compareHash(words.getRoot());
	pair<size_t, size_t> minmax = hashTable.getMinMaxLengthOfChain();
	cout<<"Minimum length of chain is " << minmax.first<<endl;
	cout<<"Maximum length of chain is " << minmax.second<<endl;
	cout<<"Average length of chain is " << hashTable.getAverage()<<endl;
	cout<<"Capacity of hashtable is " << hashTable.getCapacity()<<endl;
	cout<<"Size of hashtable is " << hashTable.getSize()<<endl;

}

void MySpellChecker::recursive_compareHash(AvlNode<string>* node){
	if (node)
	{
		recursive_compareHash(node->left);
		recursive_compareHash(node->right);

		string to_find_in_lower_case;
		to_find_in_lower_case = to_lower_case(node->key);
		if (!hashTable.find(to_find_in_lower_case))
		{
			cout<< node -> key<<endl;
		}
	}
}


#endif