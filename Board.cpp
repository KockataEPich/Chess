#include "Board.h"
#include "Queen.h"

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
		
	for (int i = 6; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			std::shared_ptr<ChessPiece> newPiece = std::make_shared<Queen>(board[i][j], PlayerSide::WHITE);

			board[i][j]->setPiece(newPiece);
			blackPieces.push_back(newPiece);
		}
			
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 8; j++)
		{
			std::shared_ptr<ChessPiece> newPiece = std::make_shared<Queen>(board[i][j], PlayerSide::BLACK);

			board[i][j]->setPiece(newPiece);
			whitePieces.push_back(newPiece);
		}

}

Board::Board(std::vector<std::vector<std::shared_ptr<Square>>> board,
	std::vector<std::shared_ptr<ChessPiece>> whitePieces,
	std::vector<std::shared_ptr<ChessPiece>> blackPieces) {

	this->board = board;
	this->whitePieces = whitePieces;
	this->blackPieces = blackPieces;
}

std::vector<std::vector<std::shared_ptr<Square>>> Board::getBoard()
{
	return board;
}

Board* Board::duplicateBoard()
{
	return new Board(this->board, this->whitePieces, this->blackPieces);
}

void Board::makeMove(Move move)
{
	auto newSquare = [](Move move, Board* board)
	{
		return board->getBoard()[move.getNewLocation()->getX()][move.getNewLocation()->getY()];
	};

	// Capture the piece
	if (newSquare(move, this)->getPiece() != nullptr)
		if (move.getSide() == PlayerSide::WHITE) {
			for (int i = 0; i < blackPieces.size(); i++)
				if (move.getOldLocation()->getPiece() == blackPieces[i])
					blackPieces.erase(blackPieces.begin() + i);
		}
		else {
			for (int i = 0; i < whitePieces.size(); i++)
				if (move.getOldLocation()->getPiece() == whitePieces[i])
					whitePieces.erase(whitePieces.begin() + i);
		}

	
	newSquare(move, this)->setPiece(move.getOldLocation()->getPiece());

	newSquare(move, this)->getPiece()->setPosition(newSquare(move, this));

	move.getOldLocation()->removePiece();
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
	if (side == PlayerSide::BLACK)
		return whitePieces;
	
	return blackPieces;
}

bool Board::isOver()
{
	if (whitePieces.size() == 0 || blackPieces.size() == 0)
		return true;

	return false;
}
