#include "DiffieHellmen.h"

int main() {

    DiffieHellmen* dfh = new DiffieHellmen();

    // the n should be prime number and g must be primitive root of n 
    dfh->generateKeys(37, 13);



    return 0;
}
