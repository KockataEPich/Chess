#include "Pawn.h"

// Constructor
Pawn::Pawn(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "Pawn";
	this->position = position;
	this->owner = playerSide;
	this->startingPositionX = position->getX();
}

// Returns the legal moves for the pawn
std::vector<std::shared_ptr<Square>>* Pawn::getLegalMoves(Board* board, PlayerSide pColor)
{
	std::vector<std::shared_ptr<Square>>* legalMoves = new std::vector<std::shared_ptr<Square>>();
	
	auto pos = position.lock();

	// Starting at x = 6 would mean that the player is the bottom one
	if (startingPositionX == 6) {
		addMoveIfNecessary(-1, 0, legalMoves, board, pColor);
		if (firstMove)
			addMoveIfNecessary(-2, 0, legalMoves, board, pColor);
		addMoveIfNecessary(-1, 1, legalMoves, board, pColor);
		addMoveIfNecessary(-1, -1, legalMoves, board, pColor);
	}
	else{
		addMoveIfNecessary(1, 0, legalMoves, board, pColor);
		if(firstMove)
			addMoveIfNecessary(2, 0, legalMoves, board, pColor);
		addMoveIfNecessary(1, 1, legalMoves, board, pColor);
		addMoveIfNecessary(1, -1, legalMoves, board, pColor);
	}

	return legalMoves;
}

void Pawn::addMoveIfNecessary(int xOff, int yOff, std::vector<std::shared_ptr<Square>>* legalMoves,
	Board* board, PlayerSide pColor) {

	auto pos = position.lock();

	if (!inRange(pos->getX() + xOff) || !inRange(pos->getY() + yOff))
		return;

	auto sqrOff = [](int xOff, int yOff, std::shared_ptr<Square> position, Board* board)
	{
		return board->getBoard()[position->getX() + xOff][position->getY() + yOff];
	};

	if (yOff == 0){
		if (sqrOff(xOff, yOff, pos, board)->getPiece() == nullptr) 
			legalMoves->push_back(sqrOff(xOff, yOff, pos, board));
		return;
	}

	if (sqrOff(xOff, yOff, pos, board)->getPiece() != nullptr &&
				sqrOff(xOff, yOff, pos, board)->getPiece()->getOwnerOfChessPiece() != pColor)
		legalMoves->push_back(sqrOff(xOff, yOff, pos, board));
}

