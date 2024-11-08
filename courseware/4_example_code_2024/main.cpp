#include <iostream>
#include "Point.h"
#include "Line.h"
using namespace std;

int main()
{
    Point p;
    cout << "p@" << &p << endl;
    p.init(2, 3);
    p.print();
    p.move(4, 4);
    p.print();

    Line L;
    L.print();
}