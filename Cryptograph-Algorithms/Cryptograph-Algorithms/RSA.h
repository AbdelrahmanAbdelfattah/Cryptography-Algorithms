#pragma once

#include<vector>
#include<string>
#include<iostream>

#include "bigint.h"

using namespace std;

class RSA
{
private:
	vector<long long> convertTextToNumber(string message);
	string convertNumberToText(bigInt plainCharacter);

public:
	bigInt* encrypt(bigInt e, bigInt n, string message);
	string decrypt(bigInt d, bigInt  n, bigInt* cipherText, int size);
};

