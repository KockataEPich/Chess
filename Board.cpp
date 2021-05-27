#include "Board.h"
#include "Queen.h"

Board::Board(std::vector<std::vector<Square*>> board)
{
	this->board = board;
}

Board::Board()
{
	for (int i = 0; i < 8; i++)
	{
		std::vector<Square*> rowVector;

		board.push_back(rowVector);
		for (int j = 0; j < 8; j++) {
			Square* newSquare = new Square(i, j, nullptr);
			board[i].push_back(newSquare);
		}
	}
		

	for (int i = 6; i < 8; i++)
		for(int j = 0; j < 8; j++)
			board[i][j]->setPiece(new Queen(board[i][j]));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 8; j++)
			board[i][j]->setPiece(new Queen(board[i][j]));

}

std::vector<std::vector<Square*>> Board::getBoard()
{
	return board;
}

Board* Board::duplicateBoard()
{
	return new Board(this->board);
}

void makeMove()
{

}

Board::~Board()
{
	board.clear();
	board.shrink_to_fit();
}



