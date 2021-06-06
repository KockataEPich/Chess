#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece
{
public:
	Queen();
	Queen(shr_sqr position, PlayerSide playerSide);
	sqr_vec* getLegalMoves(Board* board, PlayerSide pColor);
};

