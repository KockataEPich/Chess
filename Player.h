#pragma once
#include <utility>
#include "Move.h"
#include "Board.h"
#include "PlayerEnum.h"

class Move;
class Board;

class Player
{
protected:
	PlayerSide color;
	std::weak_ptr<Square> firstClickedSquare;
	std::weak_ptr<Square> secondClickedSquare;
	// Strategy strategy

public:
	std::vector<std::shared_ptr<ChessPiece>> getPieces(Board* board);
	PlayerSide getColor();
	virtual Move* getMove(Board* board) = 0;

	std::shared_ptr<Square> getFirstClicked();
	void setFirstClicked(std::shared_ptr<Square> square);

	std::shared_ptr<Square> getSecondClickedSquare();
	void setSecondClickedSquare(std::shared_ptr<Square> sqaure);

	void clearPoints();
};
