#include "Des.h"

#include <iostream>
#include <string>
#include <des.h>


using namespace CryptoPP;
using namespace std;

int main() {
    try {


        AutoSeededRandomPool rng;

        // Generate a random IV
        byte iv[DES::BLOCKSIZE];
        rng.GenerateBlock(iv, sizeof(iv));

        Des* des = new Des();
        string plainText = "hi ya abooood !";
        string key = des->generateKey();
        string cipher = des->encrypt(key, plainText, iv);
        des->decrypt(key, cipher, iv);

    }
    catch (const Exception& e) {
        cerr << "Crypto++ Exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}
