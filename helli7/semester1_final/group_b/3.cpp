#include <iostream>

using namespace std;

int main()
{
    int a[10] = {5, 6, 4, 1, 8, 9, 4, 0, 10, 3};

    int n;
    cin >> n;

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            int x = a[i] - n;
            int y = a[j] - n;

            if (x < 0)
                x *= -1;

            if (y < 0)
                y *= -1;

            if (x > y)
            {
                int c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        cout << a[i] << ", ";
    cout << endl;

    return 0;
}
