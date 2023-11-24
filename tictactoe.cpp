#include <iostream>
#include <vector>
using namespace std;

void display_board();
void player_move();
void switch_player();

// required global variables
char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
bool gamestat = true;
char currplayer = 'X';

// checking for the gamestat
void check_board()
{
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != '-') ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != '-') ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != '-'))
    {
        display_board();
        cout << "Player " << currplayer << " won the game.";
        gamestat = false;
    }
    else if ((board[0] == board[3] && board[3] == board[6] && board[0] != '-') ||
             (board[1] == board[4] && board[4] == board[7] && board[1] != '-') ||
             (board[2] == board[5] && board[5] == board[8] && board[2] != '-'))
    {
        display_board();
        cout << "Player " << currplayer << " won the game.";
        gamestat = false;
    }
    else if ((board[0] == board[4] && board[4] == board[8] && board[0] != '-') ||
             (board[2] == board[4] && board[4] == board[6] && board[2] != '-'))
    {
        display_board();
        cout << "Player " << currplayer << " won the game.";
        gamestat = false;
    }
    else if (board[0] != '-' && board[1] != '-' && board[2] != '-' &&
             board[3] != '-' && board[4] != '-' && board[5] != '-' &&
             board[6] != '-' && board[7] != '-' && board[8] != '-')
    {
        cout << "It's a tie!" << endl;
        display_board();
        gamestat = false;
    }
    else
    {
        switch_player();
    }
}

// displaying the gameboard
void display_board()
{
    cout << endl;
    cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
    cout << board[3] << "|" << board[4] << "|" << board[5] << endl;
    cout << board[6] << "|" << board[7] << "|" << board[8] << endl;
    cout << endl;
}

// function to get the player inputs
void player_move()
{
    int pos;
    cout << "Enter a number from 0-8 :";
    cin >> pos;
    if (board[pos] == '-')
    {
        board[pos] = currplayer;
    }
    else
    {
        cout << "Enter a pos which is not played!";
        player_move();
    }
}

// function to switch the player
void switch_player()
{
    if (currplayer == 'X')
    {
        currplayer = 'O';
    }
    else
    {
        currplayer = 'X';
    }
}

// main function
int main()
{
    while (gamestat)
    {
        display_board();
        player_move();
        check_board();
    }
    return 0;
}
