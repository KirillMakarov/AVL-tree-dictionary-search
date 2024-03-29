﻿#ifndef MYSPELLCHECKER_H
#define MYSPELLCHECKER_H
#include "AVLtree.h"
#include "HashTable.h"
#include "StringHash.h"
#include <string>
#include <set>
using namespace std;

class MySpellChecker {
public:
	/*
		Чтение слов, содержащихся в словаре и построение AVL-дерева
		с n узлами, где n -- число слов в словаре.
	*/
	void readDictionaryFile(string path);

	/*
		Возвращается значение true, если построенное дерево словаря
		является AVL-деревом, 
		в противном случае, возвращается false
	*/
	bool isAVLTree();

	/*
		Получение(формирование) списка слов документа.
	*/
	void readDocumentationFile(string path);

	/*
		Каждое слово документа, которое не обнаружено в словаре, выводится
		на печать (экран).
	*/
	void compare();

	/*
		Выводит на экран рекомендации по исправлению ошибок в формате:
		1\t\t2, 3, 4 ... n
		где 1 -- слово не найденное в словаре
		2, 3, 4...n -- слова, содержащиеся в словаре, рекомендации к исправлению ошибки. Это множество может быть пустым.
	*/
	void getRecommendations();

	/*
		Читает словарь в хеш таблицу.
	*/
	void readDictionaryFileAtHashTable(string path);

	/*
		Вывод слов, не содержащихся в словаре, используя hashTable в качестве словаря.
	*/
	void compareHash();

	MySpellChecker(){};

	MySpellChecker(unsigned int initial_capacity_of_dictionary):hashTable(initial_capacity_of_dictionary){};

private:
//Part I
	AVLtree<string, less<string> > dictionary, words;
	void readCustomFile(string path, AVLtree<string, less<string> > &avl_tree);
	void recursive_compare(AvlNode<string>* node);

//Part II
	void recursive_recommendations(AvlNode<string>* node);
	string to_lower_case (const string s);
	string trim_punct (const string s);
	string swap_letter (int from, int to, const string& s);
	string remove_letter(int from, string &s);
	string insert_letter_after(int after, char symb, string &s);
	void check_to_suggest(set<string>& was_suggested, string word);

//Part III
	HashTable<string, StringHash>  hashTable;
	void recursive_compareHash(AvlNode<string>* node);
};

#endif