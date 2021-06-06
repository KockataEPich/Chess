#include "Rook.h"

Rook::Rook(shr_sqr position, PlayerSide playerSide){
	this->name = "Rook";
	this->position = position;
	this->owner = playerSide;
}

sqr_vec* Rook::getLegalMoves(Board* board, PlayerSide pColor){
	sqr_vec* legalMoves = new sqr_vec();

	addHorizontal(legalMoves, board, pColor);
	addVertical(legalMoves, board, pColor);

	return legalMoves;
}
