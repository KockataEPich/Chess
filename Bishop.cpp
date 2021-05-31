#include "Bishop.h"

Bishop::Bishop(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "Bishop";
	this->position = position;
	this->owner = playerSide;
}

std::vector<std::shared_ptr<Square>>* Bishop::getLegalMoves(Board* board, PlayerSide currentPlayerColor)
{
	std::vector<std::shared_ptr<Square>>* legalMoves = new std::vector<std::shared_ptr<Square>>();

	addSideways(legalMoves, board, currentPlayerColor);

	return legalMoves;
}
