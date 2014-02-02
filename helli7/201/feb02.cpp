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

int main()
{
    double n;
    Vector v, w, s;

    cin >> v.i >> v.j >> w.i >> w.j;
    s = v.add(w);

    cout << s.length() << endl;
    cout << s.i << " , " << s.j << endl;

    return 0;
}
