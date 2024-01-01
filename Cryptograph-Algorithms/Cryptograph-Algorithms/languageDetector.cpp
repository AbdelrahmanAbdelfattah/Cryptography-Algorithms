#include "languageDetector.h"

void languageDetector::getEnglishWords(string path)
{
    this->file = new FileProcessor();
    this->englishWords = this->file->readFile(path);

}

vector<string> languageDetector::splitWords(string text)
{
    // convert the string to uppercase 
    for (int i = 0; i < text.length(); ++i) {
        text[i] = toupper(text[i]);
    }

    vector<string> words;

    // algorithm to split the words 
    string word = "";
    for (auto x : text)
    {
        if (x == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    return words;
}


int languageDetector::matchingWordsPercentage(string text)
{
    vector<string> textWords = this->splitWords(text);

    float matchingNum = 0;

    for (int i = 0; i < textWords.size(); i++)
    {
        auto isFound = find(this->englishWords.begin(), this->englishWords.end(), textWords[i]);
        if (isFound != this->englishWords.end())
            matchingNum++;
    }

    return (matchingNum / textWords.size()) * 100;
}

bool languageDetector::isEnglishText(string path, string text)
{
    this->getEnglishWords(path);
    float percentageOfMatchingWords = this->matchingWordsPercentage(text) * 1.0;

    if (percentageOfMatchingWords >= 60)
        return true;
    return false;
}
