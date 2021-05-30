#include "StartFrame.h"
#include "Player.h"
#include "EasyBot.h"
#include "HumanPlayer.h"
#include "Queen.h"


StartFrame::StartFrame() : wxFrame(nullptr, wxID_ANY, "Chess", wxPoint(30, 30), wxSize(1200, 800))
{
	grid = new wxGridSizer(8, 8, 0, 0);

	for (int x = 0; x < 8; x++)
	{
		std::vector<wxButton*> newVector;
		chessBoard.push_back(newVector);
		for (int y = 0; y < 8; y++)
		{
			chessBoard[x].push_back(new wxButton(this, 10000 + (y * 8 + x)));
			grid->Add(chessBoard[x][y], 1, wxEXPAND | wxALL);

			chessBoard[x][y]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &StartFrame::onButtonClicked, this);
		}
	}
	this->SetSizer(grid);
	grid->Layout();
	//startButton = new wxButton(this, 10001, "Start the game already", wxPoint(10, 10), wxSize(50, 50));

	board = new Board();

	player1 = new HumanPlayer(PlayerSide::WHITE);
	player2 = new EasyBot(PlayerSide::BLACK);

	updateGameGUI();
	//startGame();
};

void StartFrame::onButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % 8;
	int y = (evt.GetId() - 10000) / 8;

	
	if((board->getBoard()[x][y]->getPiece() == nullptr ||
	   board->getBoard()[x][y]->getPiece()->getOwnerOfChessPiece() != player1->getColor())){

		if(player1->getFirstClicked() == nullptr)
			return;

	}
		

	if (player1->getFirstClicked() == nullptr){
		player1->setFirstClicked(board->getBoard()[x][y]);
		return;
	}

	player1->setSecondClickedSquare(board->getBoard()[x][y]);

	board->makeMove(player1->getMove(board));

	updateGameGUI();

	player1->clearPoints();



	board->makeMove(player2->getMove(board));

	updateGameGUI();
}

void StartFrame::startGame()
{
	playChessGame();
}

//Player1 and PLayer2 as parameters
void StartFrame::playChessGame()
{

	//while (true)
	//{

	//}

	//while (!board->isOver())
	//{
	//	board->makeMove(player1->getMove(board));
	//	updateGameGUI(board);

	//}
	
	//updateGameGUI(board);

	//	if (board->isOver())
		//	break;

	//	board->makeMove(player2->getMove(board));
	

}

StartFrame::~StartFrame()
{
	for (auto& i : chessBoard)
		i.clear();

	delete(board);

	delete(player1);
	delete(player2);


	chessBoard.clear();
}


void StartFrame::updateGameGUI()
{
	for(int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (board->getBoard()[i][j]->getPiece() == nullptr)
				chessBoard[i][j]->SetLabel("");
			else if (board->getBoard()[i][j]->getPiece()->getOwnerOfChessPiece() == PlayerSide::WHITE)
				chessBoard[i][j]->SetLabel("W_" + board->getBoard()[i][j]->getPiece()->getName());
			else
				chessBoard[i][j]->SetLabel("B_" + board->getBoard()[i][j]->getPiece()->getName());
		}
}








