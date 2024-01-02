#include "CeaserCipher.h"
#include "VigenereCipher.h"
#include "oneTimePad.h"
#include "Des.h"
#include "Aes.h"
#include "RSA.h"
#include "DiffieHellmen.h"
#include "ECC.h"


#include <des.h>

int main() {
    
    // The original text that we are going to encrypt.
    string plainText = "My Name is Abdelrahman Abdelfattah I am a Computer Engineering student"; 
    cout << "The original text that we are going to encrypt : " << plainText << endl << endl;

    /*
    
    // CeaserCipher sec

    cout << "/////////////////////////////////////////(1) CEASERCIPHER SECTION///////////////////////////////////////////////////// " << endl<<endl;
    CeaserCipher  cs = CeaserCipher();
    int key = 23;
    string csEncrypted = cs.encrypt(plainText, key);
    string csDecrypted = cs.decrypt(csEncrypted, key);
    cout <<"The encrypted text using (CeaserCipher) is : " << csEncrypted << endl;
    cout << "The decrypted text using (CeaserCipher) is : " << csDecrypted << endl; 
    cout << endl << endl;
    cout << "Crack CeaserCipher using brute Force : " << endl<< endl;
    cs.brute_force_crack(csEncrypted);
    cout << endl << endl;
    cout << "Crack CeaserCipher using Frecuency Analysis : " << endl << endl;
    cs.frequency_analysis_crack(csEncrypted);
    cout << endl << endl;
    cout << "Crack CeaserCipher using Language Detector : " << endl << endl;
    cs.language_detector_crack(csEncrypted);
    cout << endl << endl;
  
   
    */

    /*
    // VegenereCipher sec

    cout << "/////////////////////////////////////////(2) VIGENERECIPHERE SECTION//////////////////////////////////////////////////// " << endl << endl;

    VigenereCipher vc = VigenereCipher();
    string vigenereCipher_key = "secrtKey";
    string vcEncrypted = vc.encrypt(plainText, vigenereCipher_key);
    string vcDecrypted = vc.deccrypt(vcEncrypted, vigenereCipher_key);
    cout << "The encrypted text using (VigenereCipher) is : " << vcEncrypted << endl;
    cout << "The decrypted text using (VigenereCipher) is : " << vcDecrypted << endl;

    cout << endl << endl;
    
    */

    
    /*

    // oneTimePad sec

    cout << "/////////////////////////////////////////(3) ONETIMEPAD SECTION//////////////////////////////////////////////////// " << endl << endl;

    oneTimePad otp = oneTimePad();
    vector<int> otp_key = otp.generateKey(30);
    string otpEncrypted = otp.encrypt(plainText, otp_key);
    string otpDecrypted = otp.decrypt(otpEncrypted, otp_key);
    cout << "The encrypted text using (oneTimePad) is : " << otpEncrypted << endl;
    cout << "The decrypted text using (oneTimePad) is : " << otpDecrypted << endl;
    cout << endl << endl;
    

    */

    
    /*

    // DES sec

    cout << "/////////////////////////////////////////(4) DES SECTION//////////////////////////////////////////////////// " << endl << endl;

    try {

        AutoSeededRandomPool rng;
        // Generate a random IV
        byte iv[DES::BLOCKSIZE];
        rng.GenerateBlock(iv, sizeof(iv));
        Des des = Des();
        string des_key = des.generateKey();
        string cipher = des.encrypt(des_key, plainText, iv);
        des.decrypt(des_key, cipher, iv);
    }
    catch (const Exception& e) {
        cerr << "Crypto++ Exception: " << e.what() << endl;
        return 1;
    }

    */
    

    /*

    // AES sec

    cout << "/////////////////////////////////////////(5) AES SECTION//////////////////////////////////////////////////// " << endl << endl;

    try {
    CryptoPP::AutoSeededRandomPool prng;
    CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);
    prng.GenerateBlock(iv, iv.size());
    Aes aes =  Aes();
    string aes_key = aes.generateKey();
    string encrypted = aes.encrypt(aes_key, plainText, iv);
    string decreypted = aes.decrypt(aes_key,encrypted , iv);
    }
    catch (const Exception& e) {

        cerr << "Crypto++ Exception: " << e.what() << endl;
        return 1;
    }
    
    */

    /*
    

    // RSA sec

    cout << "/////////////////////////////////////////(6) RSA SECTION//////////////////////////////////////////////////// " << endl << endl;

    bigInt n("391");
    bigInt e(21);
    bigInt d(285);

    RSA rsa =  RSA();


    bigInt* cipher = rsa.encrypt(e, n, plainText);

    
    //print the encrypted message
    cout << "The encrypted text using (RSA) is : "  << endl;
    for (int i = 0; i < plainText.size(); i++)
    {
        cout << cipher[i];
    }

    cout << endl;
    cout << "The decrypted text using (RSA) is : "   ;
    string originalText = rsa.decrypt(d, n, cipher, plainText.size());

    
    */

    /*

    // DiffieHellmen  sec

    cout << "/////////////////////////////////////////(6) DiffieHellmen SECTION//////////////////////////////////////////////////// " << endl << endl;
    DiffieHellmen dfh =  DiffieHellmen();
    // the n should be prime number and g must be primitive root of n 
    dfh.generateKeys(37, 13);

    */

    
    
    // DiffieHellmen with Elliptic curve  sec

    cout << "///////////////////////////////(6) DiffieHellmen with Elliptic curve  SECTION/////////////////////////////////////////// " << endl << endl;

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
