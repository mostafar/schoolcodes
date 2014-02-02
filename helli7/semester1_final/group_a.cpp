#include <iostream>
#include <cstdlib>

using namespace std;

class AdvancedInt
{
public:
    int n;

    AdvancedInt()
    {
        n = 0;
    }

    AdvancedInt(int x)
    {
        n = x;
    }

    bool isPrime(int x)
    {
        for(int i = 2; i < x; i++)
            if(x % i == 0)
                return false ;

        return true;
    }

    int gp()
    {
        for (int i = n; i >= 1; i--)
            if (n % i == 0 && isPrime(i))
                return i;
    }

    int d()
    {
        int s = 1, m = n;
        while (m >= 10)
        {
            m /= 10;
            s++;
        }
        return s;
    }

    int dr()
    {
        int m = n;
        int p = 0;

        while ( m >= 10)
        {
            p = m % 10;
            m /= 10;
            m += p;
        }
        return m;
    }

    int digitsSum(int x)
    {
        if (x < 10)
            return x;

        return x % 10 + digitsSum(x / 10)
    }
};

int main()
{
    AdvancedInt a[100];

    int avg = 0;
    for (int i = 0; i < 100; i++)
    {
        a[i].n = rand() % 100000;
        avg += a[i].gp();
    }
    avg /= 100;

    for (int i = 0; i < 100; i++)
    {
        if (a[i].dr() == 9 ||
                a[i].gp() > avg ||
                a[i].d() == a[i].dr())
            cout << a[i].n << endl;
    }

    return 0;
}
