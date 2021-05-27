#include "Square.h"

Square::Square(int x, int y, ChessPiece* chessPiece)
{
	this->x = x;
	this->y = y;
	this->chessPiece = chessPiece;
}
Square::~Square()
{
	delete(this);
}
int Square::getX()
{
	return x;
}

int Square::getY()
{
	return y;
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

