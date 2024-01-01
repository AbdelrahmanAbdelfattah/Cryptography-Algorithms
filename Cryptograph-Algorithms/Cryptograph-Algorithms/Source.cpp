
#include "VigenereCipher.h"
using namespace std;


int main() {

	VigenereCipher* vc = new VigenereCipher();
	string key = "SECREtrtrtrtrtrtrtrtr";
	string plainText = "abdelrahman";

	string cipherText = vc->encrypt(plainText, key);
	cout << cipherText << endl;
	string decryptedText = vc->deccrypt(cipherText, key);
	cout << decryptedText;

}