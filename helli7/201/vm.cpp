#include <iostream>

using namespace std;

class VendingMachine
{
public:
    int goods;
    int balance;

public:
    int m;

    void daryaft(int money)
    {
        m += money;
    }

    void sefaresh(int count)
    {
        if (count <= m)
        {
            balance += count;
            m -= count;
            cout << "Please take your goods." << endl;
        }
        else
        {
            cout << "Not enough money inserted." << endl;
        }
    }

    int baghimande()
    {
        int help = m;
        m = 0;
        return help;
    }

    void tasvieh()
    {
        balance = 0;
    }

    void porKardan(int count)
    {
        goods += count;        
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

