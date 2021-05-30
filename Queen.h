#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece
{
public:
	Queen();
	Queen(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor);
};

