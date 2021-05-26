#include "StartFrame.h"
#include "Player.h"
#include "EasyBot.h"
#include "HumanPlayer.h"

wxBEGIN_EVENT_TABLE(StartFrame, wxFrame)
	EVT_BUTTON(10001, onStartButtonClicked)
wxEND_EVENT_TABLE()

StartFrame::StartFrame() : wxFrame(nullptr, wxID_ANY, "Chess", wxPoint(30, 30), wxSize(1200, 800))
{
	startButton = new wxButton(this, 10001, "Start the game already!", wxPoint(10, 10), wxSize(50, 50)); 
};

void StartFrame::onStartButtonClicked(wxCommandEvent& evt)
{
	startButton->Show(false);

	startGame();


}

void StartFrame::startGame()
{
	//initialise game
	Player* player2 = new HumanPlayer();
	Player* player1 = new EasyBot();
	
	// Board board* = new Board();
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





