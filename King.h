#pragma once
#include "ChessPiece.h"
class King : public ChessPiece
{
public:
	King() {};
	King(std::shared_ptr<Square> position, PlayerSide playerSide);
	sqr_vec* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
	void addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	void addCastleUpIfPossible(sqr_vec* legalMoves, Board* board, std::shared_ptr<Square> pos);
};

