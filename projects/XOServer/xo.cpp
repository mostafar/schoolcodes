#include <iostream>
#include <cstring>

#include "xo.h"

using namespace std;

XO::XO()
{
    turn = 0;
    players_count = 0;
    result = "not finished";

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void XO::regist(Player *player)
{
    players[players_count] = player;
    players[players_count]->symbol = players_count == 0 ? 'X' : 'O';

    players_count++;
}

bool XO::play()
{
    char boardCopy[3][3];
    memcpy(boardCopy, board, sizeof board);

    int x = -1, y = -1;
    players[turn]->play(board, x, y);

    if (x == -1 || y == -1 || board[x][y] != ' ')
    {
        cout << "Bad action from " << players[turn]->name << "!" << endl;
        return false;
    }

    board[x][y] = turn == 0 ? 'X' : 'O';

    turn ++;
    turn %= 2;
    return true;
}

void XO::show()
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j != 2)
                cout << "|";
        }
        cout << endl;
        if (i != 2)
            cout << "-----------" << endl;
    }
    cout << endl << "==============" << endl;
}

bool XO::isFinished()
{
    return (result != "not finished");
}

bool XO::checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'X')
                result = players[0]->name;
            else
                result = players[1]->name;
            return true;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            if (board[0][j] == 'X')
                result = players[0]->name;
            else
                result = players[1]->name;
            return true;
        }
    }

    if (board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[1][1] == 'X')
            result = players[0]->name;
        else
            result = players[1]->name;
        return true;
    }

    if (board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[1][1] == 'X')
            result = players[0]->name;
        else
            result = players[1]->name;
        return true;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;

    result = "draw";
    return true;
}
