#pragma once
#include "GLobalHeader.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Board.h"
#include "Move.h";


class Move;
class Board;
class Player;
class HumanPlayer;

class StartFrame : public wxFrame
{
    

public:
    StartFrame();
    ~StartFrame();

    std::vector<std::vector<wxButton*>> chessBoard;
    int isHumanPlayer = 1;
    Board* board;
    HumanPlayer* player1;
    Player* player2;
    wxGridSizer* grid;
public:
    wxButton* startButton = nullptr;

    void onButtonClicked(wxCommandEvent& evt);

    void startGame();

    void playChessGame();

    void updateGameGUI();

    void changeButtonLegalMoves(int x, int y, bool remove);

    
};

