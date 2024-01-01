#pragma once.
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>



#include "des.h"
#include "modes.h"
#include "filters.h"
#include "osrng.h"
#include "secblock.h"
#include <hex.h>
#include <base64.h>

using namespace CryptoPP;
using namespace std;


class Des
{

public:
	string generateKey();
	string encrypt(string key, string plainText, byte iv[]);
	string decrypt(string key, string cipherText, byte iv[]);


};

