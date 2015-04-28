#ifndef MYSPELLCHECKER_CPP
#define MYSPELLCHECKER_CPP

#include "MySpellChecker.h"
#include <fstream>

void MySpellChecker::readCustomFile(string path, AVLtree<string> avl_tree){
	ifstream input_fstream(path);
	string word;
	while (input_fstream)
	{
		input_fstream >> word;
		avl_tree.insert(word);
	}
}

void MySpellChecker::readDictionaryFile(string path){
	readCustomFile(path, MySpellChecker::dictionary);
}

void MySpellChecker::readDocumentationFile (string path){
	readCustomFile(path, MySpellChecker::words);
}

#endif