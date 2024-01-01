
#include "oneTimePad.h"
using namespace std;


int main() {

	oneTimePad* onp = new oneTimePad();

	string str = "My name is abdelrahman mohamed abdelfattah aboeid";

	vector<int> key = onp->generateKey(str.length());

	string encrypted = onp->encrypt(str, key);
	cout << encrypted << endl;
	cout << onp->decrypt(encrypted, key);
}