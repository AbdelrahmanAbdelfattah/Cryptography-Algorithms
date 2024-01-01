#include "oneTimePad.h"

const string oneTimePad::ALPHABET = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";


vector<int> oneTimePad::generateKey(int range)
{
	randomGenerator* rg = new randomGenerator(range);
	vector<int> key;
	for (int i = 0; i < range; i++)
	{
		key.push_back(rg->generateRandomNumber());
	}
	return key;
}

string oneTimePad::encrypt(string plainText, vector<int> key)
{
	// convert the plainText to upperCase
	for (int i = 0; i < plainText.length(); ++i) {
		plainText[i] = toupper(plainText[i]);
	}

	string cipherText = "";

	for (int i = 0; i < plainText.length(); i++)
	{
		int indexOfCharacter = this->ALPHABET.find(plainText[i]);
		int newIndex = (indexOfCharacter + key[i]) % 27;
		cipherText += this->ALPHABET[newIndex];
	}

	return cipherText;
}

string oneTimePad::decrypt(string cipherText, vector<int> key)
{
	// convert the plainText to upperCase
	for (int i = 0; i < cipherText.length(); ++i) {
		cipherText[i] = toupper(cipherText[i]);
	}

	string plainText = "";

	for (int i = 0; i < cipherText.length(); i++)
	{
		int indexOfCharacter = this->ALPHABET.find(cipherText[i]);
		int newIndex = ((indexOfCharacter - key[i] % 27) + 27) % 27;
		plainText += this->ALPHABET[newIndex];

	}

	return plainText;
}
