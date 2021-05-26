#include "Queen.h"

Queen::Queen(Square* position)
{
	this->name = "Queen";
	this->position = position;
}

std::vector<Square*> Queen::getLegalMoves(Board board)
{
	std::vector<Square*> legalMovesList;
	return legalMovesList;
}