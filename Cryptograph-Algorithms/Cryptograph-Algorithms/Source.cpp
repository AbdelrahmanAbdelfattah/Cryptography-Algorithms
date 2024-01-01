#include "Aes.h"


using namespace CryptoPP;
using namespace std;

int main() {
    try {

        CryptoPP::AutoSeededRandomPool prng;


        CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);
        prng.GenerateBlock(iv, iv.size());

        Aes* aes = new Aes();
        string genkey = aes->generateKey();
        string text = "hi ya abood";
        string encrypted = aes->encrypt(genkey, text, iv);
        string decreypted = aes->decrypt(genkey, encrypted, iv);


    }
    catch (const Exception& e) {

        cerr << "Crypto++ Exception: " << e.what() << endl;
        return 1;

    }

    return 0;
}
