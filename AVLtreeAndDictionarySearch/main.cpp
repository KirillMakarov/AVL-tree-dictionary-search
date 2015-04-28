#include <iostream>
#include "MySpellChecker.h"

using namespace std;

int main () {
	cout<<"==== Part I ====\n";
	MySpellChecker checker;
	checker.readDictionaryFile();

	system("pause");
	return 0;
}