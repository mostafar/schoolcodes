#include <cstdlib>

#include "dummyplayer.h"

void DummyPlayer::play(char board[3][3], int &x, int &y)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                x = i;
                y = j;

                return;
            }
        }
    }
}
