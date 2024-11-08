// C++ style for Point

#include <iostream>
using namespace std;

struct Point {

 //   int px, py;
    private:
        int px, py;

    public:
        void init(int ix, int iy)
        {
            px = ix;
            py = iy;
        }

        void print()
        {
            cout << "point at (" << px << ", " << py << ")" << endl;
        }

        void move(int dx, int dy)
        {
            px += dx;
            py += dy;
        }

};





int main()
{
    Point p;
    p.init(2, 3);
    p.print();
    p.move(4, 4);
    p.print();

}