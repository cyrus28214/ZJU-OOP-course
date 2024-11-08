// C style for Point

#include <iostream>
using namespace std;

typedef struct point {
    int px, py;
}Point;

void point_init(Point *p, int ix, int iy)
{
    p->px = ix;
    p->py = iy;
}

void point_print(Point *p)
{
    cout << "point at (" << p->px << ", " << p->py << ")" << endl;
}

void point_move(Point *p, int dx, int dy)
{
    p->px += dx;
    p->py += dy;
}


int main()
{
    Point p; // point p;
    point_init(&p, 2, 3);
    point_print(&p);
    point_move(&p, 4, 4);
    point_print(&p);

    point_init(&p, 4, 8);
    point_print(&p);
    point_move(&p, -4, -10);
    point_print(&p);
}