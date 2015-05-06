#ifndef MYSPELLCHECKER_CPP
#define MYSPELLCHECKER_CPP

#include "MySpellChecker.h"
#include <fstream>
#include <algorithm>
#include <cctype>

void MySpellChecker::readCustomFile(string path, AVLtree<string> &avl_tree){
	ifstream input_fstream(path);
	string word;
	while (input_fstream)
	{
		input_fstream >> word;
		word = trim_punct(word);
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
		if (*i >= 0 && *i <= 255 && (!ispunct(*i)|| *i == '-') && (*i<'0' || *i>'9'))
			result += *i;
	}
	return result;
}
#endif