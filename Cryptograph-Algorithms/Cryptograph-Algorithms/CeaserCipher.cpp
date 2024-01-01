// CeaserCipher.cpp
#include "CeaserCipher.h"
#include <algorithm>
#include<string>
#include<iostream>
using namespace std;

const std::string CeaserCipher::ALPHABET = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
