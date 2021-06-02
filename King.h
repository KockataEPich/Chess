#pragma once
#include "ChessPiece.h"
class King : public ChessPiece
{
public:
	King();
	King(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
};

