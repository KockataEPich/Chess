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
sqr_vec* Pawn::getLegalMoves(Board* board, PlayerSide pColor)
{
	sqr_vec* legalMoves = new sqr_vec();
	
	auto pos = position.lock();

	// Starting at x = 6 would mean that the player is the bottom one
	if (startingPositionX == 6) {
		if (addSquareIfPossible(-1, 0, legalMoves, board, pColor) && firstMove)
			addSquareIfPossible(-2, 0, legalMoves, board, pColor);
		addSquareIfPossible(-1, 1, legalMoves, board, pColor);
		addSquareIfPossible(-1, -1, legalMoves, board, pColor);
	}
	else{
		if(addSquareIfPossible(1, 0, legalMoves, board, pColor) && firstMove)
			addSquareIfPossible(2, 0, legalMoves, board, pColor);
		addSquareIfPossible(1, 1, legalMoves, board, pColor);
		addSquareIfPossible(1, -1, legalMoves, board, pColor);
	}

	return legalMoves;
}

// Method checks if it is appropriate to add the move
bool Pawn::addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, 
																			PlayerSide pColor) {
	auto pos = position.lock();

	if (!inRange(pos->getX() + xOff) || !inRange(pos->getY() + yOff))
		return false;

	auto newSquare = board->getBoard()[pos->getX() + xOff][pos->getY() + yOff];

	// Going forward
	if (yOff == 0){	
		if (newSquare->getPiece() == nullptr) {
			legalMoves->push_back(newSquare);
			return true;
		}
		return false;
	}

	if (newSquare->getPiece() != nullptr && newSquare->getPiece()->getOwner() != pColor)
		legalMoves->push_back(newSquare);

	return false;
}

