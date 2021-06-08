#pragma once
#include <utility>
#include "Move.h"
#include "Board.h"
#include "PlayerEnum.h"

class Move;
class Board;

typedef std::vector<std::shared_ptr<Square>> sqr_vec;
typedef std::vector<std::shared_ptr<ChessPiece>> piece_vec;
typedef std::shared_ptr<Square> shr_sqr;


class Player
{
protected:
	PlayerSide color;
	std::weak_ptr<Square> firstClickedSquare;
	std::weak_ptr<Square> secondClickedSquare;
	// Strategy strategy

public:
	PlayerSide getColor();
	virtual Move* getMove(Board* board) = 0;

	shr_sqr getFirstClicked();
	void setFirstClicked(shr_sqr square);

	shr_sqr getSecondClickedSquare();
	void setSecondClickedSquare(shr_sqr sqaure);

	void clearPoints();
};
