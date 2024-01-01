#pragma once

#include <string>
#include <iostream>

using namespace std;

// point in Elliptic curve 
class Point
{
private:
	double x;
	double y;

public:
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);
	string toString();
	Point(double x, double y);

};

