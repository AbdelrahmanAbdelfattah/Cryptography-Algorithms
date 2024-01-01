#include "RSA.h"

vector<long long> RSA::convertTextToNumber(string message)
{
    vector<long long> str;


    for (int i = 0; i < message.size(); i++)
    {
        long long num = (long long)message[i];
        str.push_back(num);
    }

    return str;
}

string RSA::convertNumberToText(bigInt plainCharacter)
{

    string s = getStringValue(plainCharacter);
    string num = "";

    for (int i = 0; i < s.size(); i++)
    {
        num += s[i];
    }

    return num;
}


bigInt* RSA::encrypt(bigInt e, bigInt n, string textMessage)
{

    // first convert the message to number
    vector<long long > numericalRepresentationOfMessage = convertTextToNumber(textMessage);

    // encrypt the message
    // cipher_block = plainText_block ^ e mod n
    bigInt* cipher = new bigInt[numericalRepresentationOfMessage.size()];

    bigInt num;
    for (int i = 0; i < numericalRepresentationOfMessage.size(); i++)
    {
        num = numericalRepresentationOfMessage[i];
        num = (num ^ e) % n;
        cipher[i] = num;
    }


    return cipher;
}


string RSA::decrypt(bigInt d, bigInt n, bigInt* cipherText, int size)
{
    // get the original plainText
    string plainText = "";

    bigInt num;
    for (int i = 0; i < size; i++)
    {
        num = cipherText[i];
        num = (num ^ d) % n;
        plainText += (char)stoi(convertNumberToText(num));
    }
    cout << plainText << endl;
    return plainText;
}
