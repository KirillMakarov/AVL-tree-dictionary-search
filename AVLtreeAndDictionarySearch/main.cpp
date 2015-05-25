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

	cout<<"==== Part II ====\n";
	checker.getRecommendations();
	system("pause");

	cout<<"==== Part III ====\n";
	cout<<"Считывание словаря в хеш-таблицу...\n";
	checker.readDictionaryFileAtHashTable(full_path);
	cout<<"Обработка документа...\n";
	checker.compareHash();
	system("pause");
	return EXIT_SUCCESS;
}