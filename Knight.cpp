#include "Knight.h"

Knight::Knight(shr_sqr position, PlayerSide playerSide) {
	this->name = "Knight";
	this->position = position;
	this->owner = playerSide;
}
sqr_vec Knight::getLegalMoves(Board& board, PlayerSide pColor) {
	sqr_vec legalMoves;

	addSquareIfPossible(2, 1, legalMoves, board, pColor);
	addSquareIfPossible(2, -1, legalMoves, board, pColor);
	addSquareIfPossible(-2, 1, legalMoves, board, pColor);
	addSquareIfPossible(-2, -1, legalMoves, board, pColor);
	addSquareIfPossible(1, 2, legalMoves, board, pColor);
	addSquareIfPossible(1, -2, legalMoves, board, pColor);
	addSquareIfPossible(-1, 2, legalMoves, board, pColor);
	addSquareIfPossible(-1, -2, legalMoves, board, pColor);

	return legalMoves;
}
