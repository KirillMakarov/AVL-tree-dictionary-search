#include <iostream>
#include "MySpellChecker.h"

using namespace std;

int main () {
	cout<<"==== Part I ====\n";
	MySpellChecker checker;
	
	//todo: интерактив с пользователем
	string full_path = "input_dictionary.txt";
	checker.readDictionaryFile(full_path);

	system("pause");
	return EXIT_SUCCESS;
}