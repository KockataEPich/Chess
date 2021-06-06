#include "Knight.h"

Knight::Knight(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "Knight";
	this->position = position;
	this->owner = playerSide;
}
sqr_vec* Knight::getLegalMoves(Board* board, PlayerSide pColor)
{
	sqr_vec* legalMoves = new sqr_vec();

	auto pos = position.lock();

	addSquareIfPossible( 2,  1, legalMoves, board, pColor);
	addSquareIfPossible( 2, -1, legalMoves, board, pColor);
	addSquareIfPossible(-2,  1, legalMoves, board, pColor);
	addSquareIfPossible(-2, -1, legalMoves, board, pColor);
	addSquareIfPossible( 1,  2, legalMoves, board, pColor);
	addSquareIfPossible( 1, -2, legalMoves, board, pColor);
	addSquareIfPossible(-1,  2, legalMoves, board, pColor);
	addSquareIfPossible(-1, -2, legalMoves, board, pColor);

	return legalMoves;
}

void Knight::addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor) {
	auto pos = position.lock();
	if (!inRange(pos->getX() + xOff) || !inRange(pos->getY() + yOff))
		return;

	auto squareToMove = board->getBoard()[pos->getX() + xOff][pos->getY() + yOff];

	if (squareToMove->getPiece() == nullptr) {
		legalMoves->push_back(squareToMove);
		return;
	}

	if (squareToMove->getPiece()->getOwner() != pColor)
		legalMoves->push_back(squareToMove);
}
