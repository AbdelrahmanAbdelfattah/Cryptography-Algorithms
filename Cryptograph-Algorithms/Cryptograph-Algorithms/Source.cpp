#include "bigint.h"
#include "RSA.h"


int main() {

    bigInt n("391");
    bigInt e(21);
    bigInt d(285);

    RSA* rsa = new RSA();

    string message = "abd elrahman";

    bigInt* cipher = rsa->encrypt(e, n, message);

    //print the encrypted message
    for (int i = 0; i < message.size(); i++)
    {
        cout << cipher[i];
    }

    cout << endl;

    string plainText = rsa->decrypt(d, n, cipher, message.size());



    return 0;
}