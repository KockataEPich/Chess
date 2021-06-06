#pragma once
#include <string>
#include <vector>
#include "Square.h"
#include "Board.h"
#include <memory>
#include "PlayerEnum.h"

class Board;
class Square;



class ChessPiece
{
protected:
	wk_sqr position;
	std::string name;
	PlayerSide owner;
	bool firstMove = true;


public:
	std::string getName();
	shr_sqr getPosition();
	void setPosition(shr_sqr newPosition);

	bool endSquare(shr_sqr newSquare, sqr_vec* legalMoves, PlayerSide pColor);

	PlayerSide getOwner();

	void addHorizontal(sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	void addVertical(sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	void addSideways(sqr_vec* legalMoves, Board* board, PlayerSide pColor);

	virtual sqr_vec* getLegalMoves(Board* board, PlayerSide pColor) = 0;

	bool hasMoved();

	shr_piece clonePiece(shr_piece piece, shr_sqr newPosition);

	void addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	
	bool inRange(int x)
	{
		return x < 8 && x >= 0;
	}
};

