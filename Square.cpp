#include "Square.h"

Square::Square(int x, int y, std::shared_ptr<ChessPiece> chessPiece)
{
	this->x = x;
	this->y = y;
	this->chessPiece = chessPiece;
}
Square::~Square()
{
	
}
int Square::getX()
{
	return x;
}

int Square::getY()
{
	return y;
}

std::shared_ptr<ChessPiece> Square::getPiece()
{
	return chessPiece;
}

void Square::setPiece(std::shared_ptr<ChessPiece> chessPiece)
{
	this->chessPiece = chessPiece;
}

void Square::removePiece()
{
	this->chessPiece = nullptr;
}

