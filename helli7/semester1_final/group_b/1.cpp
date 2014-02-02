#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 20 == 0)
        cout << n/20 + 1;
    else
        cout << n/20 + 2;

    return 0;
}
