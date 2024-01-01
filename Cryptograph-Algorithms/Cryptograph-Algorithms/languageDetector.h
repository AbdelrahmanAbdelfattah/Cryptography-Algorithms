#include "FileProcessor.h"
class languageDetector
{
private:
	string path = "words_alpha.txt";
	FileProcessor* file;
	vector<string>englishWords;
	void getEnglishWords(string path);
	vector<string> splitWords(string text);
	int matchingWordsPercentage(string text);

public:
	languageDetector();
	bool isEnglishText(string txt);

};

