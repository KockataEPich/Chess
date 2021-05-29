#include "Queen.h"

Queen::Queen(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "Queen";
	this->position = std::make_shared<Square>(*position);
	this->owner = playerSide;
}

std::vector<std::shared_ptr<Square>> Queen::getLegalMoves(Board board, PlayerSide currentPlayerColor)
{
	std::vector<std::shared_ptr<Square>> legalMoves;
	
	addHorizontal(legalMoves, board, currentPlayerColor);
	addVertical(legalMoves, board, currentPlayerColor);
	addSideways(legalMoves, board, currentPlayerColor);
 
	return legalMoves;
}

