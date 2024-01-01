#include "analyzeText.h"
#include <iostream>
using namespace std;

map<char, int> analyzeText::analyzeString(string text)
{
    for (int i = 0; i < text.length(); ++i) {
        text[i] = toupper(text[i]);
    }

    map<char, int> frequencies;

    for (char c = 'A'; c <= 'Z'; c++)
    {
        frequencies[c] = 0;
    }

    for (int i = 0; i < text.size(); i++)
    {
        char c = text[i];
        int index = ALPHABET.find(c);
        if (index != -1)
        {
            frequencies[c]++;
        }

    }
    return frequencies;
}

void analyzeText::showAnalysis(string text)
{
    map<char, int> frequenies = analyzeString(text);
    for (auto it : frequenies)
    {
        cout << "Character " << it.first << " has frequency : " << it.second << " " << endl;
    }
}
