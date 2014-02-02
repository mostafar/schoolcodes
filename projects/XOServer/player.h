#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

using namespace std;

class Player
{
public:
    string name;
    char symbol;

    virtual void play(char board[3][3], int &x, int &y) = 0;
};

#endif // PLAYER_H_INCLUDED
