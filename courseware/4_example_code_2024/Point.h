#pragma once
//#ifndef __POINT_H__
//#define __POINT_H__

struct Point {
    //   int px, py;
private:
    int px, py;

public:
    void init(int ix, int iy);
    void print();
    void move(int dx, int dy);
};

//#endif
