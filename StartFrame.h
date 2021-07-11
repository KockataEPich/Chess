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

typedef Move mov;

class StartFrame : public wxFrame{
public:
    StartFrame();
    ~StartFrame();

    std::vector<std::vector<wxBitmapButton*>> chessBoard;
    int isHumanPlayer = 1;
    Board board;
    Player* player1 = nullptr;
    Player* player2 = nullptr;
    wxGridSizer* grid;

    wxBitmap m_blackKing;
    wxBitmap m_blackQueen;
    wxBitmap m_blackBishop;
    wxBitmap m_blackKnight;
    wxBitmap m_blackRook;
    wxBitmap m_blackPawn;

    wxBitmap m_whiteKing;
    wxBitmap m_whiteQueen;
    wxBitmap m_whiteBishop;
    wxBitmap m_whiteKnight;
    wxBitmap m_whiteRook;
    wxBitmap m_whitePawn;
public:
    wxBitmapButton* startButton = nullptr;

    void onButtonClicked(wxCommandEvent& evt);
    void startGame();
    void playChessGame();
    void updateGameGUI();
    void changeButtonLegalMoves(int x, int y, bool remove);
    void gameOver();
    void updateGameGUI(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation);


    
};

