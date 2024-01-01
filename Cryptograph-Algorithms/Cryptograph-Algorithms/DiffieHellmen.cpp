#include "DiffieHellmen.h"

void DiffieHellmen::generateKeys(int n, int g)
{
	// we use small rang because Big Integers
	randomGenerator* rd = new randomGenerator(7);

	// generate (x) random number for alice 
	int x = rd->generateRandomNumber();
	cout << "x is " << x << endl;
	// generate (y) random number for bob
	int y = rd->generateRandomNumber();
	cout << "y is " << y << endl;
	// calculate k1 of alice 
	long long  k1 = pow(g, x);
	k1 %= n;

	// calculate k2 of bob 
	long long k2 = pow(g, y);
	k2 %= n;

	// after exchange k1 and k2 we will calculate the private key 
	long long  aliceKey = pow(k2, x);
	aliceKey %= n;

	long long bobKey = pow(k1, y);
	bobKey %= n;

	cout << "Alice's key is : " << aliceKey << endl;
	cout << "Bob's key is   : " << bobKey << endl;



}
