
#include "randomGenerator.h"
using namespace std;


int main() {

	randomGenerator* rg = new randomGenerator(100);
	for (int i = 0; i < 10; i++)
		cout << rg->generateRandomNumber() << endl;

}