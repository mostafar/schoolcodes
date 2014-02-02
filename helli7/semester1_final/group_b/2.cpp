#include <iostream>

using namespace std;

int main()
{
    int n, digits[100], l = 0;
    cin>>n;

    if (n == 0)
    {
        digits[0] = 0;
        l = 1;
        cout<< 0 << endl;
    }
    else
    {
        while(n>0)
        {
            cout << n % 10 << endl;
            digits[l] = n % 10;
            n /= 10;
            l++;
        }
    }

    int m;
    cin >> m;

    for (int i = l - 1; i >= 0; i--)
        cout << (digits[i] + m) % 10;
    cout << endl;

    return 0;
}
