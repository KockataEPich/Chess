#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece {
public:
	Queen();
	Queen(shr_sqr position, PlayerSide playerSide);
	move_vec getLegalMoves(Board& board, PlayerSide pColor);
};

