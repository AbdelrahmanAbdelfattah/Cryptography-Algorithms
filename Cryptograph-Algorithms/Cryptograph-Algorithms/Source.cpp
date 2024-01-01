
#include "CeaserCipher.h"
#include <iostream>
#include<string>

using namespace std;


int main() {

	string s = "Hello world My name is abdelrahman i am a student at faculty of engineering at al azhar university in cairo in computer and system engineering department and i hope to work as a software engineer in a big tech company and travel abroad";

	CeaserCipher* cc = new CeaserCipher();

	string encrypted = cc->encrypt(s, 15);

	cc->frequency_analysis_crack(encrypted);

}