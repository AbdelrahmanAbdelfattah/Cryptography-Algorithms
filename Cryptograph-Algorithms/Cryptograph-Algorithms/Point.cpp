#include "Point.h"

double Point::getX()
{
    return this->x;
}

void Point::setX(double x)
{
    this->x = x;
}

double Point::getY()
{
    return this->y;
}

void Point::setY(double y)
{
    this->y = y;
}

string Point::toString()
{
    return "Point [X = " + to_string(x) + " , Y = " + to_string(y) + " ]";
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
