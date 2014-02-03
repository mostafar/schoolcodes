#include <iostream>

using namespace std;

int itemPrice[4]= {1, 2, 2, 5};

class VendingMachine
{
public:
    int money;
    int profit;

    VendingMachine()
    {
        profit = 0;
    }

    void newcustomer()
    {
        money = 0;
    }

    void insertCoin(int coin)
    {
        if (coin == 1 || coin == 2 || coin==5)
            money += coin;
        else
            cout << "Bad coin inserted!";
    }

    void buyItem(int item)
    {
        if (item >= 1 && item <=4)
        {
            int request = itemPrice[item - 1];

            if(request > money)
                cout<<"Not enough coins inserted!";
            else
            {
                cout<< "Pick up your item!";
                money -= request;
                profit += request;
            }
        }
        else
            cout << "Bad item chose!";
    }

    void returnChanges()
    {
        cout << money / 5 << "*5$ - coin" << endl;
        money %= 5;
        cout << money / 2 << "*2$ - coin" << endl;
        money %= 2;
        cout << money << "*1$ - coin" << endl;

        cout<<"Thanks for your shopping! <3" << endl;
    }

    int netProfit()
    {
        return sood;
    }
};


int main()
{
    VendingMachine vm;

    for (int i=0; i < 3; i++)
    {
        cout << "Welcome to Helli7's Vending machine!" << endl;

        vm.newcustomer();

        while(1)
        {
            int coin;
            cout << "Please enter a 1, 2 or 5 dollar coin: ";
            cin >> coin;

            if (coin == 0)
                break;

            vm.insertCoin(coin);
        }

        while(1)
        {
            int item;
            cout<< "1. Water         1$" << endl;
            cout<< "2. Coca          2$" << endl;
            cout<< "3. Biscuit       2$" << endl;
            cout<< "4. Snickers      5$" << endl;
            cout<< "0. End of shopping" << endl;
            cin>>item;

            if(item==0)
                break;

            vm.buyItem(item);
        }

        vm.returnChanges();
    }

    cout << "The Vending machine's net profit is: "
         << vm.netProfit() << "$" << endl;

    return 0;
}
