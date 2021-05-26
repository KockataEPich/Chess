#include "Square.h"

Square::Square(int x, int y, ChessPiece* chessPiece)
{
	this->position = std::make_pair(x, y);
	this->chessPiece = chessPiece;
}

std::pair<char, int> Square::getPosition()
{
	return position;
}

ChessPiece* Square::getPiece()
{
	return chessPiece;
}

void Square::setPiece(ChessPiece* chessPiece)
{
	this->chessPiece = chessPiece;
}

void Square::removePiece()
{
	this->chessPiece = nullptr;
}

