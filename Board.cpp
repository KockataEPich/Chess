#include "Board.h"

Board::Board(std::vector<std::vector<Square*>> board)
{
	this->board = board;
}

Board::Board()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = new Square(i, j, nullptr);

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



