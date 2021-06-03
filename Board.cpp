#include "Board.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"

Board::Board()
{
	for (int i = 0; i < 8; i++)
	{
		std::vector<std::shared_ptr<Square>> rowVector;

		board.push_back(rowVector);
		for (int j = 0; j < 8; j++) {
			std::shared_ptr<Square> newSquare = std::make_shared<Square>(i, j, nullptr);
			board[i].push_back(newSquare);
		}
	}
	
	/////////////////////////////////////////////// WHITE INIT ///////////////////////////////

	for (int y = 0; y < 8; y++)
	{
		std::shared_ptr<ChessPiece> newPiece = std::make_shared<Pawn>(board[6][y], PlayerSide::WHITE);

		board[6][y]->setPiece(newPiece);
		whitePieces.push_back(newPiece);
	}

	std::shared_ptr<ChessPiece> newPiece1 = std::make_shared<Rook>(board[7][0], PlayerSide::WHITE);

	board[7][0]->setPiece(newPiece1);
	whitePieces.push_back(newPiece1);

	std::shared_ptr<ChessPiece> newPiece2 = std::make_shared<Knight>(board[7][1], PlayerSide::WHITE);

	board[7][1]->setPiece(newPiece2);
	whitePieces.push_back(newPiece2);

	std::shared_ptr<ChessPiece> newPiece3 = std::make_shared<Bishop>(board[7][2], PlayerSide::WHITE);

	board[7][2]->setPiece(newPiece3);
	whitePieces.push_back(newPiece3);

	std::shared_ptr<ChessPiece> newPiece4 = std::make_shared<Queen>(board[7][3], PlayerSide::WHITE);

	board[7][3]->setPiece(newPiece4);
	whitePieces.push_back(newPiece4);

	std::shared_ptr<ChessPiece> newPiece5 = std::make_shared<King>(board[7][4], PlayerSide::WHITE);

	board[7][4]->setPiece(newPiece5);
	whitePieces.push_back(newPiece5);

	std::shared_ptr<ChessPiece> newPiece6 = std::make_shared<Bishop>(board[7][5], PlayerSide::WHITE);

	board[7][5]->setPiece(newPiece6);
	whitePieces.push_back(newPiece6);


	std::shared_ptr<ChessPiece> newPiece7 = std::make_shared<Knight>(board[7][6], PlayerSide::WHITE);

	board[7][6]->setPiece(newPiece7);
	whitePieces.push_back(newPiece7);

	std::shared_ptr<ChessPiece> newPiece8 = std::make_shared<Rook>(board[7][7], PlayerSide::WHITE);

	board[7][7]->setPiece(newPiece8);
	whitePieces.push_back(newPiece8);

	


	//////////////////////////////////////////////////// BLACK INIT /////////////////////////////
	for (int y = 0; y < 8; y++)
	{
		std::shared_ptr<ChessPiece> newPiece = std::make_shared<Pawn>(board[1][y], PlayerSide::BLACK);

		board[1][y]->setPiece(newPiece);
		blackPieces.push_back(newPiece);
	}

	std::shared_ptr<ChessPiece> newPiece9 = std::make_shared<Rook>(board[0][0], PlayerSide::BLACK);

	board[0][0]->setPiece(newPiece9);
	blackPieces.push_back(newPiece9);

	std::shared_ptr<ChessPiece> newPiece10 = std::make_shared<Knight>(board[0][1], PlayerSide::BLACK);

	board[0][1]->setPiece(newPiece10);
	blackPieces.push_back(newPiece10);

	std::shared_ptr<ChessPiece> newPiece11 = std::make_shared<Bishop>(board[0][2], PlayerSide::BLACK);

	board[0][2]->setPiece(newPiece11);
	blackPieces.push_back(newPiece11);

	std::shared_ptr<ChessPiece> newPiece12 = std::make_shared<Queen>(board[0][3], PlayerSide::BLACK);

	board[0][3]->setPiece(newPiece12);
	blackPieces.push_back(newPiece12);

	std::shared_ptr<ChessPiece> newPiece13 = std::make_shared<King>(board[0][4], PlayerSide::BLACK);

	board[0][4]->setPiece(newPiece13);
	blackPieces.push_back(newPiece13);

	std::shared_ptr<ChessPiece> newPiece14 = std::make_shared<Bishop>(board[0][5], PlayerSide::BLACK);

	board[0][5]->setPiece(newPiece14);
	blackPieces.push_back(newPiece14);


	std::shared_ptr<ChessPiece> newPiece15 = std::make_shared<Knight>(board[0][6], PlayerSide::BLACK);

	board[0][6]->setPiece(newPiece15);
	blackPieces.push_back(newPiece15);

	std::shared_ptr<ChessPiece> newPiece16 = std::make_shared<Rook>(board[0][7], PlayerSide::BLACK);

	board[0][7]->setPiece(newPiece16);
	blackPieces.push_back(newPiece16);

}

Board::Board(std::vector<std::vector<std::shared_ptr<Square>>> givenBoard,
	std::vector<std::shared_ptr<ChessPiece>> givenWhitePieces,
	std::vector<std::shared_ptr<ChessPiece>> givenBlackPieces) {

	for (int i = 0; i < 8; i++)
	{
		std::vector<std::shared_ptr<Square>> rowVector;

		board.push_back(rowVector);
		for (int j = 0; j < 8; j++) {
			std::shared_ptr<Square> newSquare = std::make_shared<Square>(i, j, nullptr);
			board[i].push_back(newSquare);
		}
	}

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {

			if (givenBoard[i][j]->getPiece() != nullptr){
				std::shared_ptr<ChessPiece> piece = givenBoard[i][j]->getPiece()->clonePiece(
					givenBoard[i][j]->getPiece(), board[i][j]);
				
				board[i][j]->setPiece(piece);
				if (piece->getOwnerOfChessPiece() == PlayerSide::WHITE)
					this->whitePieces.push_back(piece);
				else
					this->blackPieces.push_back(piece);
			}
				
		}
	}

}

std::vector<std::vector<std::shared_ptr<Square>>> Board::getBoard()
{
	return board;
}

Board* Board::duplicateBoard()
{
	return new Board(this->board, this->whitePieces, this->blackPieces);
}

void Board::makeMove(Move* move)
{

	auto newSquare = [](Move* move, Board* board)
	{
		return board->getBoard()[move->getNewLocation()->getX()]
			[move->getNewLocation()->getY()];
	};

	// Capture the piece
	if (newSquare(move, this)->getPiece() != nullptr)
		if (move->getSide() == PlayerSide::WHITE) {
			if (newSquare(move, this)->getPiece()->getName() == "King"){
				gameIsOver = true;
				winner = "Whites Win";
			}
			for (int i = 0; i < blackPieces.size(); i++)
				if (newSquare(move, this)->getPiece() == blackPieces[i])
					blackPieces.erase(blackPieces.begin() + i);
		}
		else {
			if (newSquare(move, this)->getPiece()->getName() == "King") {
				gameIsOver = true;
				winner = "Blacks Win";
			}

			for (int i = 0; i < whitePieces.size(); i++)
				if (newSquare(move, this)->getPiece() == whitePieces[i])
					whitePieces.erase(whitePieces.begin() + i);
		}

	if (move->getOldLocation()->getPiece()->hasMoved() == false &&
		move->getOldLocation()->getPiece()->getName() == "King")
	{
		if (move->getOldLocation()->getY() - newSquare(move, this)->getY() == -2)
			this->makeMove(new Move(board[move->getOldLocation()->getX()][7], 
						board[move->getOldLocation()->getX()][5], move->getSide()));

		if (move->getOldLocation()->getY() - newSquare(move, this)->getY() == 3)
			this->makeMove(new Move(board[move->getOldLocation()->getX()][0],
				board[move->getOldLocation()->getX()][2], move->getSide()));
	}

	newSquare(move, this)->setPiece(move->getOldLocation()->getPiece());

	newSquare(move, this)->getPiece()->setPosition(newSquare(move, this));

	move->getOldLocation()->removePiece();

	//Promotion
	if (newSquare(move, this)->getPiece()->getName() == "Pawn")
	{
		if (newSquare(move, this)->getX() == 0) {
			
			for (int i = 0; i < whitePieces.size(); i++)
			{
				if (whitePieces[i] == newSquare(move, this)->getPiece())
					whitePieces.erase(whitePieces.begin() + i);

			}

			std::shared_ptr<ChessPiece> promotedPiece = std::make_shared<Queen>(newSquare(move, this), move->getSide());
			newSquare(move, this)->setPiece(promotedPiece);

			whitePieces.push_back(promotedPiece);
		}

		if (newSquare(move, this)->getX() == 7) {

			for (int i = 0; i < blackPieces.size(); i++)
			{
				if (blackPieces[i] == newSquare(move, this)->getPiece())
					blackPieces.erase(blackPieces.begin() + i);

			}

			std::shared_ptr<ChessPiece> promotedPiece = std::make_shared<Queen>(newSquare(move, this), move->getSide());
			newSquare(move, this)->setPiece(promotedPiece);
			blackPieces.push_back(promotedPiece);
		}


	}

	delete(move);
}

Board::~Board()
{
	for (int i = 0; i < board.size(); i++)
	{
		board[i].clear();
	}
	board.clear();
	
}


std::vector<std::shared_ptr<ChessPiece>> Board::getPieceList(PlayerSide side) {
	if (side == PlayerSide::WHITE)
		return whitePieces;
	
	return blackPieces;
}

bool Board::isOver()
{
	return gameIsOver;
}

std::string Board::getWinner() {
	return winner;
}