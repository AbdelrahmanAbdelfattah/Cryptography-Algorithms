#include "analyzeText.h"
#include <string>
#include<map>
using namespace std;

class CeaserCipher {
private:
    static const std::string ALPHABET;

public:
    string encrypt(string plainText, int key);
    string decrypt(string cipherText, int key);
    void brute_force_crack(string cipherText);
    void frequency_analysis_crack(string cipherText);
};

