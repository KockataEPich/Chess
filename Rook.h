#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece {
public:
	Rook();
	Rook(shr_sqr position, PlayerSide playerSide);
	sqr_vec getLegalMoves(Board& board, PlayerSide pColor);
};
