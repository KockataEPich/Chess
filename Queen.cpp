#include "Queen.h"

Queen::Queen(shr_sqr position, PlayerSide playerSide){
	this->name = "Queen";
	this->position = position;
	this->owner = playerSide;
}

sqr_vec* Queen::getLegalMoves(Board* board, PlayerSide pColor){
	sqr_vec* legalMoves = new sqr_vec();

	addHorizontal(legalMoves, board, pColor);
	addVertical(legalMoves, board, pColor);
	addSideways(legalMoves, board, pColor);
 
	return legalMoves;
}

