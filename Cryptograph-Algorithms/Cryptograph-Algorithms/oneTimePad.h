#include "randomGenerator.h"
#include <vector>
class oneTimePad
{
private:
	static const string ALPHABET;

public:
	vector<int> generateKey(int range);
	string encrypt(string plainText, vector<int> key);
	string decrypt(string cipherText, vector<int> key);

};

