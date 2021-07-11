#include "Rook.h"

Rook::Rook(shr_sqr position, PlayerSide playerSide){
	this->name = "Rook";
	this->position = position;
	this->owner = playerSide;
}

move_vec Rook::getLegalMoves(Board& board, PlayerSide pColor){
	sqr_vec legal_moves;

	addHorizontal(legal_moves, board, pColor);
	addVertical(legal_moves, board, pColor);

	return makeMovesOutOfEndPosition(legal_moves);
}
