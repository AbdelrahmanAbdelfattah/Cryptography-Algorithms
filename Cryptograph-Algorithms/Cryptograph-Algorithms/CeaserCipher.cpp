// CeaserCipher.cpp
#include "CeaserCipher.h"
#include <algorithm>
#include<string>
#include<iostream>
using namespace std;

const string CeaserCipher::ALPHABET = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string CeaserCipher::encrypt(string plainText, int key) {
    std::string cipherText = "";

    key = key % 27;

    for (int i = 0; i < plainText.length(); ++i) {
        plainText[i] = toupper(plainText[i]);
    }

    for (char character : plainText) {
        int index = ALPHABET.find(character);
        int encryptIndex = (index + key + 27) % 27;
        cipherText += ALPHABET[encryptIndex];
    }
    return cipherText;
}


std::string CeaserCipher::decrypt(string cipherText, int key) {
    std::string plainText = "";

    key = key % 27;

    for (int i = 0; i < cipherText.length(); ++i) {
        cipherText[i] = toupper(cipherText[i]);
    }

    for (char character : cipherText) {
        int index = ALPHABET.find(character);
        int decryptIndex = (index - key + 27) % 27;
        plainText += ALPHABET[decryptIndex];
    }
    return plainText;
}

void CeaserCipher::brute_force_crack(string cipherText)
{
    for (int key = 0; key < 27; key++)
    {
        cout << "The plain text could be : " << decrypt(cipherText, key)
            << " with " << key << " as a key " << endl;
    }
}

void CeaserCipher::frequency_analysis_crack(string cipherText)
{
    analyzeText* analysis = new analyzeText();
    map<char, int> frequencies = analysis->analyzeString(cipherText);
    char mostFrequentChar = ' ';
    int mx = INT_MIN;
    for (auto it : frequencies)
    {
        if (it.second > mx)
        {
            mostFrequentChar = it.first;
            mx = it.second;
        }
    }
    cout << "The approximate key is : " << (ALPHABET.find(mostFrequentChar) - ALPHABET.find(' '));
}

void CeaserCipher::language_detector_crack(string cipherText)
{
    languageDetector* ld = new languageDetector();
    for (int key = 0; key < 27; key++)
    {
        string could_be_the_plain_text = decrypt(cipherText, key);
        bool isEnglish = ld->isEnglishText(could_be_the_plain_text);
        if (isEnglish)
        {
            cout << could_be_the_plain_text << endl;
        }

    }
}
