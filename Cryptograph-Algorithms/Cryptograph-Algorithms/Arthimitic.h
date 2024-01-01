#pragma once

#include <vector>
using namespace std;

class Arthimitic
{

public:
    int gcd(int a, int b);
    int expoModularInverse(int a, int m);
    vector<int> egcd(int a, int b);
};

