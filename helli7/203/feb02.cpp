#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
public:
    double i, j;

    double length()
    {
        return sqrt(i * i + j * j);
    }

    double dot(Vector b)
    {
        return i * b.i + j * b.j;
    }

    Vector multiply(double c)
    {
        Vector k;
        k.i = c * i;
        k.j = c * j;
        return k;
    }
};

int main()
{
    Vector v, w;

    cin >> v.i >> v.j >> w.i >> w.j;

    cout << v.dot(w) << endl;

    int n;
    cin >> n;

    Vector p;
    p = v.multiply(n);

    cout << p.i << ", " << p.j << " -> " << p.length();

    return 0;
}

