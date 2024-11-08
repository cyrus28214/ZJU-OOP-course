// Basic implementation of a point

#include <iostream>
using namespace std;

int px, py;

int main()
{
    px = 2, py = 3;
    cout << "point at (" << px << ", " << py << ")" << endl;

    px += 4, py += 4;
    cout << "point at (" << px << ", " << py << ")" << endl;
}