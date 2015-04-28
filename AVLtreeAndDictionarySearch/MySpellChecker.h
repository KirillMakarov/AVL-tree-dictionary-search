#ifndef MYSPELLCHECKER_H
#define MYSPELLCHECKER_H
#include "AVLtree.h"
#include <string>
using namespace std;

class MySpellChecker {
public:
	/*
		Чтение слов, содержащихся в словаре и построеник AVL-дерева
		с n узлами, где n -- число слов в словаре.
	*/
	void readDictionaryFile();

	/*
		Возвращается значение true, если построенное дерево 
		является AVL-деревом, 
		в противном случае, возвращается false
	*/
	bool isAVLTree();

	/*
		Получение(формирование) списка слов документа.
	*/
	void readDocumentationFile();

	/*
		Каждое слово документа, которое не обнаружено в словаре, выводится
		на печать (экран).
	*/
	void compare();

private:
	AVLtree<string> dictionary, word;
};

#endif