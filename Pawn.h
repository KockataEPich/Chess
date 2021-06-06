#pragma once
#include "ChessPiece.h"
class Pawn : public ChessPiece
{
private:
	int startingPositionX;
public:
	Pawn();
	Pawn(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
	void addMoveIfNecessary(int xOff, int yOff, std::vector<std::shared_ptr<Square>>*
		legalMoves, Board* board, PlayerSide pColor);
};

