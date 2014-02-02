#pragma once

#include <string>

#include "player.h"

using namespace std;

class XO
{
private:
    int turn;
    char board[3][3];
    int players_count;

public:
    Player *players[2];
    string result;

    XO();

    void regist(Player *player);
    bool play();
    void show();
    bool isFinished();
    bool checkWinner();
};
