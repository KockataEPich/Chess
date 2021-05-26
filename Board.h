#pragma once
#include "Square.h"
#include <vector>
class Square;

class Board
{
private:
	std::vector<std::vector<Square*>> board;
public:
	Board();
	Board(std::vector<std::vector<Square*>> board);
	std::vector<std::vector<Square*>>  getBoard();
	Board* duplicateBoard();
	void makeMove();
};

