#pragma once
#include <iostream>
#include<string>
#include<vector>

using namespace std;

class bigInt {
    string digits;
public:

    //Constructors:
    bigInt(unsigned long long n = 0);
    bigInt(string&);
    bigInt(const char*);
    bigInt(bigInt&);

    //Helper Functions:
    friend void divide_by_2(bigInt& a);
    friend bool Null(const bigInt&);
    friend int Length(const bigInt&);
    int operator[](const int)const;

    /* * * * Operator Overloading * * * */

//Direct assignment
    bigInt& operator=(const bigInt&);

    //Post/Pre - Incrementation
    bigInt& operator++();
    bigInt operator++(int temp);
    bigInt& operator--();
    bigInt operator--(int temp);

    //Addition and Subtraction
    friend bigInt& operator+=(bigInt&, const bigInt&);
    friend bigInt operator+(const bigInt&, const bigInt&);
    friend bigInt operator-(const bigInt&, const bigInt&);
    friend bigInt& operator-=(bigInt&, const bigInt&);

    //Comparison operators
    friend bool operator==(const bigInt&, const bigInt&);
    friend bool operator!=(const bigInt&, const bigInt&);

    friend bool operator>(const bigInt&, const bigInt&);
    friend bool operator>=(const bigInt&, const bigInt&);
    friend bool operator<(const bigInt&, const bigInt&);
    friend bool operator<=(const bigInt&, const bigInt&);

    //Multiplication and Division
    friend bigInt& operator*=(bigInt&, const bigInt&);
    friend bigInt operator*(const bigInt&, const bigInt&);
    friend bigInt& operator/=(bigInt&, const bigInt&);
    friend bigInt operator/(const bigInt&, const bigInt&);

    //Modulo
    friend bigInt operator%(const bigInt&, const bigInt&);
    friend bigInt& operator%=(bigInt&, const bigInt&);

    //Power Function
    friend bigInt& operator^=(bigInt& a, const bigInt& b) {
        bigInt Exponent, Base(a);
        Exponent = b;
        a = 1;
        while (!Null(Exponent)) {
            if (Exponent[0] & 1)
                a *= Base;
            Base *= Base;
            divide_by_2(Exponent);
        }
        return a;
    }

    friend bigInt operator^(bigInt& a, bigInt& b) {
        bigInt temp(a);
        temp ^= b;
        return temp;
    }

    //Square Root Function
    friend bigInt sqrt(bigInt& a);

    //Read and Write
    friend ostream& operator<<(ostream&, const bigInt&);
    friend istream& operator>>(istream&, bigInt&);

    //Others
    friend bigInt NthCatalan(int n);
    friend bigInt NthFibonacci(int n);
    friend bigInt Factorial(int n);
};