#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece
{
public:
	Bishop();
	Bishop(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
};

