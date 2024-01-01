#include "randomGenerator.h"

randomGenerator::randomGenerator(int range)
{
	this->range = range;
	srand(time(0));
}

int randomGenerator::generateRandomNumber()
{
	return rand() % this->range;
}
