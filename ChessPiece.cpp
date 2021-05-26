#include "ChessPiece.h"

ChessPiece::ChessPiece()
{

};

std::string ChessPiece::getName()
{
	return name;
}

Square* ChessPiece::getPosition()
{
	return position;
}


