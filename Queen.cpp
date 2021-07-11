#include "Queen.h"

Queen::Queen(shr_sqr position, PlayerSide playerSide) {
	this->name = "Queen";
	this->position = position;
	this->owner = playerSide;
}

move_vec Queen::getLegalMoves(Board& board, PlayerSide pColor) {
	sqr_vec legalMoves;

	addHorizontal(legalMoves, board, pColor);
	addVertical(legalMoves, board, pColor);
	addSideways(legalMoves, board, pColor);

	return makeMovesOutOfEndPosition(legalMoves);
}

