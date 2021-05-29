#pragma once
#include "Square.h"
#include "Move.h"
#include <vector>
#include <memory>

class Square;
class Move;

class Board
{
private:
	std::vector<std::vector<std::shared_ptr<Square>>> board;
public:
	Board();
	~Board();
	Board(std::vector<std::vector<std::shared_ptr<Square>>> board);
	std::vector<std::vector<std::shared_ptr<Square>>>  getBoard();
	Board* duplicateBoard();
	void makeMove(Move move);
};

