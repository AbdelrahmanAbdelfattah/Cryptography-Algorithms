#include "Des.h"
#include <des.h>




string Des::generateKey()
{

    // Generate a random key
    AutoSeededRandomPool rng;
    SecByteBlock keyBytes(DES::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(keyBytes, keyBytes.size());

    // Convert key  to hex-encoded string
    string key;
    StringSource(keyBytes, keyBytes.size(), true,
        new HexEncoder(
            new StringSink(key)
        )
    );

    // Print the encoded key
    cout << "Generated and HEX-encoded key: " << key << endl;

    return key;
}

string Des::encrypt(string key, string plainText, byte iv[])
{

    // Convert hex-encoded key string to byte array
    SecByteBlock keyBytes(DES::DEFAULT_KEYLENGTH);
    StringSource(key, true,
        new HexDecoder(
            new ArraySink(keyBytes, keyBytes.size())
        )
    );


    // Convert plaintext to Crypto++ byte array
    SecByteBlock textBytes((const byte*)plainText.data(), plainText.size());

    // Print original plaintext
    cout << "Original Text: " << plainText << endl;

    // Encrypt using DES in CBC mode with PKCS7 padding
    CBC_Mode<DES>::Encryption desEncryptor;
    desEncryptor.SetKeyWithIV(keyBytes, keyBytes.size(), iv);

    // Create a string to hold the ciphertext
    string ciphertext;
    StringSource(textBytes, textBytes.size(), true,
        new StreamTransformationFilter(desEncryptor,
            new StringSink(ciphertext),
            StreamTransformationFilter::PKCS_PADDING
        )
    );


    // Print ciphertext
    cout << "Ciphertext: " << ciphertext << endl;


    return ciphertext;
}

string Des::decrypt(string key, string cipherText, byte iv[])
{

    // Convert hex-encoded key string to byte array
    SecByteBlock keyBytes(DES::DEFAULT_KEYLENGTH);
    StringSource(key, true,
        new HexDecoder(
            new ArraySink(keyBytes, keyBytes.size())
        )
    );

    // Decrypt using DES in CBC mode with PKCS7 padding
    CBC_Mode<DES>::Decryption desDecryptor;
    desDecryptor.SetKeyWithIV(keyBytes, keyBytes.size(), iv);

    // Create a string to hold the decrypted text
    string decryptedText;
    StringSource(cipherText, true,
        new StreamTransformationFilter(desDecryptor,
            new StringSink(decryptedText),
            StreamTransformationFilter::PKCS_PADDING
        )
    );

    // Print decrypted text
    cout << "Decrypted Text: " << decryptedText << endl;

    return decryptedText;
}


