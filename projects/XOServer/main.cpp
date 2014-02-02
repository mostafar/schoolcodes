#include <iostream>
#include <unistd.h>

#include "xo.h"
#include "dummyplayer.h"
#include "myplayer.h"

using namespace std;

int main()
{
    cout << "Welcome to F3's XO game ..." << endl;

    XO xo;

    xo.regist(new DummyPlayer());
    xo.regist(new MyPlayer());

    cout << "The game is between:" << endl << "          " << xo.players[0]->name << "    vs    " << xo.players[1]->name << endl;

    while (true)
    {
        if (!xo.play())
            break;

        xo.show();

        if (xo.checkWinner())
            break;
        usleep(1000000);
    }

    if (xo.result == "draw")
        cout << "Result is a draw!" << endl;
    else
        cout << xo.result << " won the game :)" << endl;
    return 0;
}
