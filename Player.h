#pragma once
#include <utility>
#include "Move.h"
#include "Board.h"
#include "PlayerEnum.h"

class Move;
class Board;

class Player
{
private:
	std::vector<std::shared_ptr<ChessPiece>> pieces;
	PlayerSide color;
	// Strategy strategy

public:
	void setPieces(std::vector<std::shared_ptr<ChessPiece>> pieces);
	void setColor(PlayerSide color);
	std::vector<std::shared_ptr<ChessPiece>> getPieces();
	PlayerSide getColor();
	virtual Move getMove(Board* board) = 0;

};
