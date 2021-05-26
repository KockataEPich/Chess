#include "Queen.h"

Queen::Queen(Square position)
{
	this->position = position;
}
std::string Queen::getName() {
	return "Queen";
}

Square Queen::getPosition()
{
	return position;
}

std::vector<Square> Queen::getLegalMoves(Board board)
{
	std::vector<Square> legalMovesList;
	return legalMovesList;
}