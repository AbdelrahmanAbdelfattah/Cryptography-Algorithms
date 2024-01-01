#include <string>
#include<iostream>
using namespace std;

class VigenereCipher
{
private:
	static const std::string ALPHABET;

public:
	string encrypt(string plainText, string key);
	string deccrypt(string cipherText, string key);


};

