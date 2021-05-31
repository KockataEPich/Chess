#pragma once
#include "ChessPiece.h"
class Pawn : public ChessPiece
{
public:
	Pawn();
	Pawn(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
};

