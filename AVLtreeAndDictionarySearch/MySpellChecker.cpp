#ifndef MYSPELLCHECKER_CPP
#define MYSPELLCHECKER_CPP

#include "MySpellChecker.h"
#include <fstream>
#include <algorithm>

void MySpellChecker::readCustomFile(string path, AVLtree<string> &avl_tree){
	ifstream input_fstream(path);
	string word;
	while (input_fstream)
	{
		input_fstream >> word;

		//word = word.to
	//	remove_if(word.begin(), word.end(), ispunct);
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
		if (!dictionary.find(node -> key))
		{
			cout<< node -> key<<endl;
		}
	}
}
#endif