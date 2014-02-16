#include <iostream>
#include <graphics.h>

using namespace std;

const int X = 400, Y = 300;

class Vector
{
public:
    int x, y;

    void add(Vector a)
    {
        x += a.x;
        y += a.y;
    }
};

class Ball
{
public:
    int radius;
    Vector pos;
    Vector speed;

    Ball()
    {
        pos.x = 100;
        pos.y = 100;
        radius = 25;
        speed.x = 3;
        speed.y = 4;
    }

    void draw()
    {
        setcolor(15);
        circle(pos.x, pos.y, radius);
    }

    void clear ()
    {
        setcolor(0);
        circle(pos.x, pos.y, radius);
    }

    void checkCollisions()
    {
        if (pos.x + radius >= X || pos.x - radius <= 0)
            speed.x *= -1;
        if (pos.y + radius >= Y || pos.y - radius <= 0)
            speed.y *= -1;
    }
};

int main()
{
    int gd, gm;
    initgraph(&gd, &gm, NULL);

    const int N = 10;
    Ball b[N];

    for (int i = 0; i < N; i++)
    {
        b[i].pos.x = i * 5 + 50;
        b[i].pos.y = i * 5 + 50;
        b[i].speed.x = i - N / 2;
        b[i].speed.y = i - N / 2;
    }

    rectangle(0, 0, X, Y);
    for(int t = 0; t < 1000; t++)
    {
        for (int i = 0; i < N; i++)
            b[i].draw();

        delay(20);

        for (int i = 0; i < N; i++)
        {
            b[i].clear();

            b[i].pos.add(b[i].speed);
            b[i].checkCollisions();
        }
    }

    getch();
    return 0;
}
