#pragma once
#include <string>
#include <vector>
#include "Square.h"
#include "Board.h"
#include <memory>
#include "PlayerEnum.h"

class Board;
class Square;

typedef std::vector<std::shared_ptr<Square>>	sqr_vec;
typedef std::shared_ptr<Square>					shr_sqr;
class ChessPiece{
protected:
	std::weak_ptr<Square> position;
	std::string name;
	PlayerSide owner;
	bool firstMove = true;
public:
	std::string getName();
	shr_sqr getPosition();
	PlayerSide getOwner();
	bool hasMoved();
	bool inRange(int x);
	void setPosition(shr_sqr newPosition);
	void addVertical(sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	void addHorizontal(sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	void addSideways(sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	bool endSquare(int x, int y, sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	void addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor);
	std::shared_ptr<ChessPiece> clonePiece(std::shared_ptr<ChessPiece> piece, shr_sqr newPosition);
	
	virtual sqr_vec* getLegalMoves(Board* board, PlayerSide pColor) = 0;
};
typedef std::shared_ptr<ChessPiece> shr_piece;
