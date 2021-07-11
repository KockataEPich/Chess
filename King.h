#pragma once
#include "ChessPiece.h"
class King : public ChessPiece{
public:
	King() {};
	King(shr_sqr position, PlayerSide playerSide);
	move_vec getLegalMoves(Board& board, PlayerSide currentPlayerColor);
	void addCastleUpIfPossible(sqr_vec& legalMoves, Board& board);
};

