
#include "CeaserCipher.h"
#include "FileProcessor.h"
#include <iostream>
#include<string>
using namespace std;


int main() {

	FileProcessor* file = new FileProcessor();
	vector <string> words = file->readFile("words_alpha.txt");
	cout << words.size();

}