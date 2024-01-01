#include "ECC.h"

ECC::ECC(double a, double b)
{
	this->a = a;
	this->b = b;

}

Point ECC::pointAddition(Point p, Point q)
{
	double x1 = p.getX();
	double y1 = p.getY();

	double x2 = q.getX();
	double y2 = q.getY();

	double m = 0;

	// calculating m 

	if (x1 == x2 && y1 == y2)
	{
		m = (3 * x1 * x1 + a) / (2 * y1);
	}
	else {
		m = (y2 - y1) / (x2 - x1);
	}

	double x3 = m * m - x2 - x1;
	double y3 = m * (x1 - x3) - y1;

	return  Point(x3, y3);
}

Point ECC::DoubleAndAdd(int n, Point p)
{
	Point temp = Point(p.getX(), p.getY());
	string nBinary = intToBinaryString(n);

	// we skip the first bit 

	cout << nBinary << endl;
	for (int i = nBinary.length() - 2; i >= 0; i--)
	{
		char c = nBinary[i];

		// point doubling operation
		temp = pointAddition(temp, temp);

		if (c == '1')
		{
			// point addition operation
			temp = pointAddition(temp, p);
		}

	}
	return temp;


}

string ECC::intToBinaryString(int number)
{
	// Convert to binary using bitwise operations
	std::bitset<sizeof(int) * 8> binaryRepresentation(number);

	// Convert the bitset to a string and remove leading zeros
	return binaryRepresentation.to_string().substr(binaryRepresentation.to_string().find('1'));
}
