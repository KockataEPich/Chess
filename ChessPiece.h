#pragma once
#include <string>
#include <vector>
#include "Square.h"
#include "Board.h"

class Board;
class Square;

class ChessPiece
{
protected:
	Square* position = nullptr;
	std::string name;

public:
	ChessPiece();
	std::string getName();
	Square* getPosition();
	virtual std::vector<Square*> getLegalMoves(Board board) = 0;
};

