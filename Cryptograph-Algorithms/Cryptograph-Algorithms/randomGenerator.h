

// C++ program to generate random numbers 
#include <cstdlib> 
#include <iostream> 
#include <time.h> 
using namespace std;


class randomGenerator
{
private:
	int range;

public:
	randomGenerator(int range);
	int generateRandomNumber();
};

