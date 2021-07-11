#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece
{
public:
	Bishop();
	Bishop(shr_sqr position, PlayerSide pColor);
	move_vec getLegalMoves(Board& board, PlayerSide pColor);
};

