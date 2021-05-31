#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece
{
public:
	Rook();
	Rook(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
};
