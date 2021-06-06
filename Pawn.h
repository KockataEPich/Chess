#pragma once
#include "ChessPiece.h"
class Pawn : public ChessPiece
{
private:
	int startingPositionX;
public:
	Pawn() {};
	Pawn(std::shared_ptr<Square> position, PlayerSide playerSide);
	sqr_vec* getLegalMoves(Board* board, PlayerSide pColor);
	bool addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor);
};

