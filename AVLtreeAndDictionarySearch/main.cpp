#include <iostream>
#include "MySpellChecker.h"

using namespace std;

int main () {
	setlocale(LC_ALL, "Russian");
	cout<<"==== Part I ====\n";
	MySpellChecker checker;

	//todo: интерактив с пользователем
	string full_path = "input_dictionary_full.txt";
	string document_path = "input.txt";
	cout<<"Считывание словаря...\n";
	checker.readDictionaryFile(full_path);
	cout<<"Считывание документа...\n";
	checker.readDocumentationFile(document_path);
	cout<<"Обработка документа...\n";
	checker.compare();
	system("pause");
	return EXIT_SUCCESS;
}

//int main () {
//	AVLtree<int>* test_tree = new AVLtree<int>();
//	for (int i =127; i > 0; i--)
//		test_tree->insert(i);
//	
//	for (int i =127; i > 0; i--)
//		test_tree->insert(i);
//	
//	for (int i =1; i < 128; i++)
//		test_tree->insert(i);
//	test_tree->print_tree();
//	cout<<"ROOT: "<<test_tree->root->key <<"\tHeight: "<< (int)test_tree->root -> height<<" "<<test_tree->getSize()<<endl;
//
//	delete test_tree;
//	
//	system("pause");
//	return EXIT_SUCCESS;
//}