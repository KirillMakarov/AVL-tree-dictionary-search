#include <iostream>
#include "MySpellChecker.h"

using namespace std;

int main () {
	setlocale(LC_ALL, "Russian");
	MySpellChecker* checker;
	checker = new MySpellChecker();
	//интерактив с пользователем
	string full_path;// = "input_dictionary_full.txt";
	string document_path;// = "input.txt";
	
	cout<<"Введите имя файла, в котором содержится словарь: ";
	cin>>full_path;
	cout<<"==== Part I ====\n";
	cout<<"Считывание словаря...\n";
	checker->readDictionaryFile(full_path);

	
	cout<<"Введите имя файла, в котором содержится документ: ";
	cin>>document_path;

	cout<<"Считывание документа...\n";
	checker->readDocumentationFile(document_path);
	cout<<"Обработка документа...\n";
	checker->compare();
	system("pause");

	cout<<"==== Part II ====\n";
	checker->getRecommendations();
	system("pause");

	cout<<"==== Part III ====\n";
	cout<<"Считывание словаря в хеш-таблицу...\n";
	checker->readDictionaryFileAtHashTable(full_path);
	cout<<"Обработка документа...\n";
	checker->compareHash();
	system("pause");
	delete checker;

	return EXIT_SUCCESS;
}
