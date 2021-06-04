#include "StartFrame.h"
#include "Player.h"
#include "EasyBot.h"
#include "HumanPlayer.h"
#include "Queen.h"
#include "MediumBot.h"


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
	player2 = new MediumBot(PlayerSide::BLACK);

	isHumanPlayer = 1;

	updateGameGUI();

	
	//startGame();
};

void StartFrame::onButtonClicked(wxCommandEvent& evt)
{
	if (isHumanPlayer == 0)
		playChessGame();

	int x = (evt.GetId() - 10000) % 8;
	int y = (evt.GetId() - 10000) / 8;

	
	if((board->getBoard()[x][y]->getPiece() == nullptr ||
	   board->getBoard()[x][y]->getPiece()->getOwnerOfChessPiece() != player1->getColor())){

		if(player1->getFirstClicked() == nullptr)
			return;
	}
		

	if (player1->getFirstClicked() == nullptr){
		player1->setFirstClicked(board->getBoard()[x][y]);
		changeButtonLegalMoves(x, y, false);
		return;
	}

	std::vector<std::shared_ptr<Square>>* legalMoves = player1->getFirstClicked()->
		getPiece()->getLegalMoves(board, player1->getColor());

	bool isMoveLegal = false;

	for (int i = 0; i < legalMoves->size(); i++)
		if (board->getBoard()[x][y] == legalMoves->at(i))
			isMoveLegal = true;

	delete(legalMoves);

	if (isMoveLegal)
	{
		player1->setSecondClickedSquare(board->getBoard()[x][y]);

		board->makeMove(player1->getMove(board));

		updateGameGUI();

		changeButtonLegalMoves(x, y, true);

		player1->clearPoints();

		if (board->isOver())
			gameOver();

		board->makeMove(player2->getMove(board));

		updateGameGUI();

		if (board->isOver())
			gameOver();

		return;
	}

	player1->clearPoints();
	changeButtonLegalMoves(x, y, true);
	
}

void StartFrame::startGame()
{
	playChessGame();
}

//Player1 and PLayer2 as parameters
void StartFrame::playChessGame()
{
	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++) {
			chessBoard[x][y]->Disable();
		}
	while (!board->isOver()) {
		auto newMove = player1->getMove(board);
		board->makeMove(newMove);
		updateGameGUI();
		if (board->isOver())
			break;

		wxMilliSleep(2000);
		board->makeMove(player2->getMove(board));
		updateGameGUI();
		wxMilliSleep(2000);
	}

	gameOver();

}

void StartFrame::gameOver()
{
	this->SetLabel(board->getWinner());
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


void StartFrame::updateGameGUI(){
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


void StartFrame::changeButtonLegalMoves(int x, int y, bool remove) {
	if (!remove) {
		std::vector<std::shared_ptr<Square>>* legalMoves = board->getBoard()[x][y]->
			getPiece()->getLegalMoves(board, player1->getColor());
		for (int i = 0; i < legalMoves->size(); i++) {
			chessBoard[legalMoves->at(i)->getX()][legalMoves->at(i)->getY()]->SetBackgroundColour(wxColour(0,120,10));
		}
		delete(legalMoves);
		return;
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			chessBoard[i][j]->SetBackgroundColour(wxNullColour);
		}
}





