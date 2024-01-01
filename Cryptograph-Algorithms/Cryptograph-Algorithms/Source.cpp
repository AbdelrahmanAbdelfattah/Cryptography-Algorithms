
#include "CeaserCipher.h"
#include <iostream>
#include<string>
using namespace std;


int main() {

	CeaserCipher* cc = new CeaserCipher();

	string englishText = "Hi  i am abdelrahman  i am a student at faculty of engineering at al azhar university in cairo deaprtment of computer and system engineering";
	string decryptedText = cc->encrypt(englishText, 4);

	cc->language_detector_crack(decryptedText);


}