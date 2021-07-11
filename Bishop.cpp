#include "Bishop.h"
Bishop::Bishop(shr_sqr position, PlayerSide playerSide) {
	this->name = "Bishop";
	this->position = position;
	this->owner = playerSide;
}

sqr_vec Bishop::getLegalMoves(Board& board, PlayerSide pColor) {
	sqr_vec legalMoves;
	addSideways(legalMoves, board, pColor);
	return legalMoves;
}
