#include "ECC.h"
#include "randomGenerator.h"


int main() {

    // these are  all public : the ECC and generator point 
    ECC* ecc = new ECC(3, 7);
    Point generator = Point(-2, 1);

    randomGenerator rd = randomGenerator(10000);

    // Elliptic Curve Diffie-Hellmen Algorithm
    // random number for alice 
    int a = rd.generateRandomNumber();
    //random number for bob
    int b = rd.generateRandomNumber();

    // public keys with double and add algorithm 
    // these are points on Elliptic curve 
    Point alicePublicKey = ecc->DoubleAndAdd(a, generator);
    Point bobPublicKey = ecc->DoubleAndAdd(b, generator);

    //they can generate the same private key  they can use for symmetric encryption
    Point aliceSecretKey = ecc->DoubleAndAdd(a, bobPublicKey);
    Point bobSecretKey = ecc->DoubleAndAdd(b, alicePublicKey);

    cout << aliceSecretKey.toString() << endl;
    cout << bobSecretKey.toString() << endl;


    return 0;
}