#pragma once

#include "Point.h"

#include <bitset>

class ECC
{

private:
	// y^2 = x^3 + ax + b
	// Bitcoin a =0 , b = 7   
	double a;
	double b;

	string intToBinaryString(int number);

public:
	ECC(double a, double b);
	Point pointAddition(Point p, Point q);
	Point DoubleAndAdd(int n, Point p);


};

