#include "StartFrame.h"
#include "Player.h"
#include "EasyBot.h"
#include "HumanPlayer.h"
#include "Queen.h"

wxBEGIN_EVENT_TABLE(StartFrame, wxFrame)
	EVT_BUTTON(10001, onStartButtonClicked)
wxEND_EVENT_TABLE()

StartFrame::StartFrame() : wxFrame(nullptr, wxID_ANY, "Chess", wxPoint(30, 30), wxSize(1200, 800))
{

	
	startButton = new wxButton(this, 10001, "Start the game already", wxPoint(10, 10), wxSize(50, 50));
};

void StartFrame::onStartButtonClicked(wxCommandEvent& evt)
{
	startButton->Show(false);

	startGame();


}

void StartFrame::startGame()
{
	//initialise game
	Player* player1 = new HumanPlayer(PlayerSide::WHITE);
	Player* player2 = new EasyBot(PlayerSide::BLACK);


	Board* board = new Board();

	delete(board);

	delete(player1);
	delete(player2);
	

	// game);
	//
	//
}

//Player1 and PLayer2 as parameters
void StartFrame::playChessGame()
{
	// while(Game is over)
	// makeMove(Player1.getMove())
	// makeMove(Player2.getMove())

}





