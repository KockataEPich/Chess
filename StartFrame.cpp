#include "StartFrame.h"
#include "Player.h"
#include "EasyBot.h"
#include "HumanPlayer.h"
#include "Queen.h"
#include "MediumBot.h"


StartFrame::StartFrame() : wxFrame(nullptr, wxID_ANY, "Chess", wxPoint(30, 30), wxSize(1200, 800))
{
	grid = new wxGridSizer(8, 8, 0, 0);

	wxImage image;

	wxPNGHandler* handler = new wxPNGHandler();

	image.AddHandler(handler);
	//bitmap.
	image.LoadFile("640px-Chess_Pieces_Sprite.svg.png");
	// Extract the images of the pieces from the larger image.
	wxBitmap b(image);

	m_blackKing = b.GetSubBitmap(wxRect(5, 113, 100, 100));
	m_blackQueen = b.GetSubBitmap(wxRect(110, 113, 100, 100));
	m_blackBishop = b.GetSubBitmap(wxRect(215, 113, 100, 100));
	m_blackKnight = b.GetSubBitmap(wxRect(323, 113, 100, 100));
	m_blackRook = b.GetSubBitmap(wxRect(433, 113, 100, 100));
	m_blackPawn = b.GetSubBitmap(wxRect(535, 113, 100, 100));

	m_whiteKing = b.GetSubBitmap(wxRect(5, 5, 100, 100));
	m_whiteQueen = b.GetSubBitmap(wxRect(110, 5, 100, 100));
	m_whiteBishop = b.GetSubBitmap(wxRect(215, 5, 100, 100));
	m_whiteKnight = b.GetSubBitmap(wxRect(323, 5, 100, 100));
	m_whiteRook = b.GetSubBitmap(wxRect(433, 5, 100, 100));
	m_whitePawn = b.GetSubBitmap(wxRect(535, 5, 100, 100));

	for (int x = 0; x < 8; x++)
	{
		std::vector<wxBitmapButton*> newVector;
		chessBoard.push_back(newVector);
		for (int y = 0; y < 8; y++)
		{
			chessBoard[x].push_back(new wxBitmapButton(this, 10000 + (y * 8 + x), wxBitmap()));
			grid->Add(chessBoard[x][y], 1, wxEXPAND | wxALL);

			chessBoard[x][y]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &StartFrame::onButtonClicked, this);
		}
	}

	this->SetSizer(grid);
	grid->Layout();



	//	startButton = new wxBitmapButton(this, 10001, m_blackKing, wxPoint(10, 10), wxSize(50, 50));

	board = new Board();

	player1 = new HumanPlayer(PlayerSide::WHITE);
	player2 = new EasyBot(PlayerSide::BLACK);

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


	if ((board->getBoard()[x][y]->getPiece() == nullptr ||
		board->getBoard()[x][y]->getPiece()->getOwner() != player1->getColor())) {

		if (player1->getFirstClicked() == nullptr)
			return;
	}


	if (player1->getFirstClicked() == nullptr) {
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


		auto newMove = player1->getMove(board);
		board->makeMove(newMove);
		updateGameGUI(newMove->getOldLocation(), newMove->getNewLocation());

		changeButtonLegalMoves(x, y, true);

		player1->clearPoints();

		if (board->isOver())
			gameOver();

		delete(newMove);
		newMove = player2->getMove(board);
		board->makeMove(newMove);


		updateGameGUI(newMove->getOldLocation(), newMove->getNewLocation());
		delete(newMove);

		if (board->isOver())
			gameOver();
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
		updateGameGUI(newMove->getOldLocation(), newMove->getNewLocation());

		if (board->isOver())
			break;

		wxMilliSleep(2000);

		delete(newMove);
		newMove = player2->getMove(board);
		board->makeMove(newMove);


		updateGameGUI(newMove->getOldLocation(), newMove->getNewLocation());
		wxMilliSleep(2000);
		delete(newMove);
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


void StartFrame::updateGameGUI() {



	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			chessBoard[i][j]->Disable();
			chessBoard[i][j]->SetBitmap(wxBitmap());
			chessBoard[i][j]->Enable();

			if (board->getBoard()[i][j]->getPiece() == nullptr) {

				if (isHumanPlayer == 0)
					chessBoard[i][j]->Disable();
			}

			else if (board->getBoard()[i][j]->getPiece()->getOwner() == PlayerSide::WHITE) {
				if (board->getBoard()[i][j]->getPiece()->getName() == "Pawn") {
					chessBoard[i][j]->SetBitmap(m_whitePawn);
				}
				//chessBoard[i][j]->SetBitmap(m_whitePawn);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Rook")
					chessBoard[i][j]->SetBitmap(m_whiteRook);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Knight")
					chessBoard[i][j]->SetBitmap(m_whiteKnight);
				if (board->getBoard()[i][j]->getPiece()->getName() == "King")
					chessBoard[i][j]->SetBitmap(m_whiteKing);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Bishop")
					chessBoard[i][j]->SetBitmap(m_whiteBishop);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Queen")
					chessBoard[i][j]->SetBitmap(m_whiteQueen);
			}

			else {
				if (board->getBoard()[i][j]->getPiece()->getName() == "Pawn")
					chessBoard[i][j]->SetBitmap(m_blackPawn);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Rook")
					chessBoard[i][j]->SetBitmap(m_blackRook);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Knight")
					chessBoard[i][j]->SetBitmap(m_blackKnight);
				if (board->getBoard()[i][j]->getPiece()->getName() == "King")
					chessBoard[i][j]->SetBitmap(m_blackKing);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Bishop")
					chessBoard[i][j]->SetBitmap(m_blackBishop);
				if (board->getBoard()[i][j]->getPiece()->getName() == "Queen")
					chessBoard[i][j]->SetBitmap(m_blackQueen);
			}

		}

	this->Update();
}


void StartFrame::updateGameGUI(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation) {

	auto button = [](std::vector<std::vector<wxBitmapButton*>> chessBoard, std::shared_ptr<Square> location) {
		return chessBoard[location->getX()][location->getY()];
	};

	button(chessBoard, oldLocation)->Disable();
	button(chessBoard, oldLocation)->SetBitmap(wxBitmap());
	button(chessBoard, oldLocation)->Enable();

	if (isHumanPlayer == 0)
		button(chessBoard, oldLocation)->Disable();


	button(chessBoard, newLocation)->Disable();
	button(chessBoard, newLocation)->SetBitmap(wxBitmap());
	button(chessBoard, newLocation)->Enable();

	if (isHumanPlayer == 0)
		button(chessBoard, newLocation)->Disable();

	auto square = [](Board* board, std::shared_ptr<Square> location) {
		return board->getBoard()[location->getX()][location->getY()];
	};

	auto chessPiece = square(board, newLocation)->getPiece();

	if (chessPiece->getOwner() == PlayerSide::WHITE) {
		if (chessPiece->getName() == "Pawn")
			button(chessBoard, newLocation)->SetBitmap(m_whitePawn);

		if (chessPiece->getName() == "Rook")
			button(chessBoard, newLocation)->SetBitmap(m_whiteRook);

		if (chessPiece->getName() == "Knight")
			button(chessBoard, newLocation)->SetBitmap(m_whiteKnight);

		if (chessPiece->getName() == "King")
			button(chessBoard, newLocation)->SetBitmap(m_whiteKing);

		if (chessPiece->getName() == "Bishop")
			button(chessBoard, newLocation)->SetBitmap(m_whiteBishop);

		if (chessPiece->getName() == "Queen")
			button(chessBoard, newLocation)->SetBitmap(m_whiteQueen);
	}

	else {
		if (chessPiece->getName() == "Pawn")
			button(chessBoard, newLocation)->SetBitmap(m_blackPawn);

		if (chessPiece->getName() == "Rook")
			button(chessBoard, newLocation)->SetBitmap(m_blackRook);

		if (chessPiece->getName() == "Knight")
			button(chessBoard, newLocation)->SetBitmap(m_blackKnight);

		if (chessPiece->getName() == "King")
			button(chessBoard, newLocation)->SetBitmap(m_blackKing);

		if (chessPiece->getName() == "Bishop")
			button(chessBoard, newLocation)->SetBitmap(m_blackBishop);

		if (chessPiece->getName() == "Queen")
			button(chessBoard, newLocation)->SetBitmap(m_blackQueen);
	}

	this->Update();
}


void StartFrame::changeButtonLegalMoves(int x, int y, bool remove) {
	if (!remove) {
		std::vector<std::shared_ptr<Square>>* legalMoves = board->getBoard()[x][y]->
			getPiece()->getLegalMoves(board, player1->getColor());
		for (int i = 0; i < legalMoves->size(); i++) {
			chessBoard[legalMoves->at(i)->getX()][legalMoves->at(i)->getY()]->SetBackgroundColour(wxColour(0, 120, 10));
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





