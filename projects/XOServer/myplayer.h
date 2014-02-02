#ifndef MYPLAYER_H_INCLUDED
#define MYPLAYER_H_INCLUDED

#include "player.h"

class MyPlayer : public Player
{
public:
    MyPlayer()
    {
        name = "MyPlayer";
    }

    void play(char board[3][3], int &x, int &y);
};

#endif // MYPLAYER_H_INCLUDED
