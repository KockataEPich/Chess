#include "Rook.h"

Rook::Rook(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "Rook";
	this->position = position;
	this->owner = playerSide;
}

std::vector<std::shared_ptr<Square>>* Rook::getLegalMoves(Board* board, PlayerSide currentPlayerColor)
{
	std::vector<std::shared_ptr<Square>>* legalMoves = new std::vector<std::shared_ptr<Square>>();


	addHorizontal(legalMoves, board, currentPlayerColor);
	addVertical(legalMoves, board, currentPlayerColor);

	return legalMoves;
}
