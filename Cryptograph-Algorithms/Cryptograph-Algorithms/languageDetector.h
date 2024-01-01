#include "FileProcessor.h"
class languageDetector
{
private:
	FileProcessor* file;
	vector<string>englishWords;
	void getEnglishWords(string path);
	vector<string> splitWords(string text);
	int matchingWordsPercentage(string text);
public:
	bool isEnglishText(string path, string txt);

};

