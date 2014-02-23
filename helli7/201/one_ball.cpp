#include <iostream>
#include <graphics.h>
#include <cmath>
#include<ctime>
using namespace std;

class Vector
{
public:
    double i, j;

    double length()
    {
        return sqrt(i * i + j * j);
    }

    Vector multiply(double n)
    {
        Vector x;
        x.i = n * i;
        x.j = n * j;
        return x;
    }

    Vector add(Vector b)
    {
        Vector y;
        y.i = b.i + i;
        y.j = b.j + j;
        return y;
    }
};

class Ball
{
public:

    Vector pos;
    Vector speed;

    int radius;

    void show()
    {
        setcolor(WHITE);
        circle(pos.i, pos.j, radius);
    }
    void clear()
    {
        setcolor(BLACK);
        circle(pos.i, pos.j, radius);
    }
    void checkCollisions()
    {
        if ( pos.i <= 0 || pos.i >= 650 )
            speed.i*= -1;
        if ( pos.j <= 0 || pos.j >= 480 )
            speed.j*= -1;
    }
};

int main()
{
    int gd, gm;
    initgraph(&gd, &gm, "");

    Ball b;

    b.pos.i = 300;
    b.pos.j = 300;
    b.speed.i = 5;
    b.speed.j = 7;
    b.radius = 10;

    for (int t = 0; true/*t < 1000*/; t++)
    {
        b.show();
        delay(10);
        b.clear();

        b.pos = b.pos.add(b.speed);

        b.checkCollisions();
    }

    return 0;
}
