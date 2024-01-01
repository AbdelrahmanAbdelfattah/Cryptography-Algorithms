
#include <string>
using namespace std;

class CeaserCipher {
private:
    static const std::string ALPHABET;

public:
    std::string encrypt(string plainText, int key);
    std::string decrypt(string cipherText, int key);
};

