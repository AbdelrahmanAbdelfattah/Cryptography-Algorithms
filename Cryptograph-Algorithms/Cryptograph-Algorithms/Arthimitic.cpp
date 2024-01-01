#include "Arthimitic.h"

int Arthimitic::gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int Arthimitic::expoModularInverse(int a, int m)
{
	// this is brute-force approach that take exponantial time (slow)
	// the range [0,m-1]

	for (int inv = 0; inv < m; inv++)
	{
		if ((a * inv) % m == 1)
			return inv;
	}

	return -1;

}

vector<int> Arthimitic::egcd(int a, int b)
{
	// a<b is must 

	// base-case
		// gcd(0,b)=b and a*x+b*y=b - so x=0 and y=1
	if (a == 0) {
		return vector<int> { b, 0, 1 };
	}

	// so we use the Euclidean algorithm for gcd()
	// b%a is always the smaller number - and 'a' is the smaller integer
	// always in this implementation
	vector<int> values = egcd(b % a, a);

	// and we update the parameters for x, y accordingly
	int gcd = values[0];
	int x1 = values[1];
	int y1 = values[2];

	int x = y1 - (b / a) * x1;
	int y = x1;

	return vector<int> {gcd, x, y};
}
