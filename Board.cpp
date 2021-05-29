#include "Board.h"
#include "Queen.h"


Board::Board(std::vector<std::vector<std::shared_ptr<Square>>> board)
{
	this->board = board;
}

Board::Board()
{
	for (int i = 0; i < 8; i++)
	{
		std::vector<std::shared_ptr<Square>> rowVector;

		board.push_back(rowVector);
		for (int j = 0; j < 8; j++) {
			std::shared_ptr<Square> newSquare(new Square(i, j, nullptr));
			board[i].push_back(newSquare);
		}
	}
		
	for (int i = 6; i < 8; i++)
		for(int j = 0; j < 8; j++)
			board[i][j]->setPiece(std::make_shared<Queen>(board[i][j], PlayerSide::BLACK));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 8; j++)
			board[i][j]->setPiece(std::make_shared<Queen>(board[i][j], PlayerSide::WHITE));

}

std::vector<std::vector<std::shared_ptr<Square>>> Board::getBoard()
{
	return board;
}

Board* Board::duplicateBoard()
{
	return new Board(this->board);
}

void Board::makeMove(Move move)
{
	auto newSquare = [](Move move, Board* board)
	{
		return board->getBoard()[move.getNewLocation()->getX()][move.getNewLocation()->getY()];
	};

	//if (newSquare(move, this)->getPiece() != nullptr)
		//Means we are overwriting a chesspieces

	newSquare(move, this)->setPiece(move.getOldLocation()->getPiece());

	newSquare(move, this)->getPiece()->setPosition(newSquare(move, this));

	move.getOldLocation()->setPiece(nullptr);
}

Board::~Board()
{
	for (int i = 0; i < board.size(); i++)
	{
		board[i].clear();
	}
	board.clear();
	
}



