#include "ECC.h"

#include <bitset>


int main() {

    ECC* ecc = new ECC(0, 7);

    Point generator = Point(1, 1);

    Point p = ecc->DoubleAndAdd(100, generator);



    cout << p.toString();

    return 0;
}