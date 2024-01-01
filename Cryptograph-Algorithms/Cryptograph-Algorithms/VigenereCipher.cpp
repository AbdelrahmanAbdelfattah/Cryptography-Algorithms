#include "VigenereCipher.h"

const string VigenereCipher::ALPHABET = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string VigenereCipher::encrypt(string plainText, string key)
{
    // convert plainText to UpperCase 
    for (int i = 0; i < plainText.length(); ++i) {
        plainText[i] = toupper(plainText[i]);
    }

    // convert key to UpperCase 
    for (int i = 0; i < key.length(); ++i) {
        key[i] = toupper(key[i]);
    }

    string cipherText = "";
    int keyIndex = 0;
    for (int i = 0; i < plainText.length(); i++)
    {
        int indexOfPlainText = ALPHABET.find(plainText[i]);
        int indexOfKey = ALPHABET.find(key[keyIndex]);
        int newIndex = (indexOfKey + indexOfPlainText) % 27;
        char character = ALPHABET[newIndex];
        cipherText += character;

        keyIndex++;

        if (keyIndex == key.length())
            keyIndex = 0;
    }
    return cipherText;
}

string VigenereCipher::deccrypt(string cipherText, string key)
{
    // convert CipherText to UpperCase 
    for (int i = 0; i < cipherText.length(); ++i) {
        cipherText[i] = toupper(cipherText[i]);
    }

    // convert key to UpperCase 
    for (int i = 0; i < key.length(); ++i) {
        key[i] = toupper(key[i]);
    }

    string plainText = "";
    int keyIndex = 0;
    for (int i = 0; i < cipherText.length(); i++)
    {
        int indexOfCipherText = ALPHABET.find(cipherText[i]);
        int indexOfKey = ALPHABET.find(key[keyIndex]);
        int newIndex = (indexOfCipherText - indexOfKey + 27) % 27;
        char character = ALPHABET[newIndex];
        plainText += character;

        keyIndex++;

        if (keyIndex == key.length())
            keyIndex = 0;
    }
    return plainText;
}
