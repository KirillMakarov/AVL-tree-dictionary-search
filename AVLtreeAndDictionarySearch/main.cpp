#include <iostream>
#include "MySpellChecker.h"

using namespace std;

//int main () {
//	setlocale(LC_ALL, "Russian");
//	cout<<"==== Part I ====\n";
//	MySpellChecker* checker;
//	checker = new MySpellChecker();
//	//todo: интерактив с пользователем
//	string full_path = "input_dictionary_full.txt";
//	string document_path = "input.txt";
//	cout<<"Считывание словаря...\n";
//	checker->readDictionaryFile(full_path);
//	cout<<"Считывание документа...\n";
//	checker->readDocumentationFile(document_path);
//	cout<<"Обработка документа...\n";
//	checker->compare();
//	system("pause");
//
//	cout<<"==== Part II ====\n";
//	checker->getRecommendations();
//	system("pause");
//
//	cout<<"==== Part III ====\n";
//	cout<<"Считывание словаря в хеш-таблицу...\n";
//	checker->readDictionaryFileAtHashTable(full_path);
//	cout<<"Обработка документа...\n";
//	checker->compareHash();
//	system("pause");
//	delete checker;
//
//	return EXIT_SUCCESS;
//}


int main () {

	string full_path = "input_dictionary_full.txt";
	string document_path = "input.txt";
	setlocale(LC_ALL, "Russian");

	while (true) {

		MySpellChecker* checker;
		checker = new MySpellChecker();
		//todo: интерактив с пользователем
		cout<<"==== Part III ====\n";
		cout<<"Считывание словаря в хеш-таблицу...\n";
		checker->readDictionaryFileAtHashTable(full_path);
		delete checker;

	}
	return EXIT_SUCCESS;
}