#pragma once
#include "ChessPiece.h"
class Knight : public ChessPiece{
public:
	Knight() {};
	Knight(shr_sqr position, PlayerSide playerSide);
	move_vec getLegalMoves(Board& board, PlayerSide pColor);
};

