#include "Move.h"


Move::Move(std::shared_ptr<ChessPiece> chessPiece, std::shared_ptr<Square> newLocation)
{
	this->chessPiece = chessPiece;
	this->newLocation = newLocation;
}
