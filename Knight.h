#pragma once
#include "ChessPiece.h"
class Knight : public ChessPiece
{
public:
	Knight();
	Knight(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
	void addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor);
};

