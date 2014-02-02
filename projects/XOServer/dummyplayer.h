#ifndef DUMMYPLAYER_H_INCLUDED
#define DUMMYPLAYER_H_INCLUDED

#include "player.h"

class DummyPlayer: public Player
{
public:
    DummyPlayer()
    {
        name = "DummyPlayer";
    }

    void play(char board[3][3], int &x, int &y);
};

#endif // DUMMYPLAYER_H_INCLUDED
