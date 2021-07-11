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
typedef std::weak_ptr<Square> wk_sqr;

class Player{
protected:
	PlayerSide color;
	wk_sqr firstClickedSquare;
	wk_sqr secondClickedSquare;
	// Strategy strategy
public:
	PlayerSide getColor();
	void clearPoints();

	shr_sqr getFirstClicked();
	void setFirstClicked(shr_sqr  square);
	shr_sqr getSecondClickedSquare();
	void setSecondClickedSquare(shr_sqr  sqaure);

	virtual Move getMove(Board& board) = 0;
	virtual ~Player() {};
};
