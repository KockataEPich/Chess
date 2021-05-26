#pragma once
#include "Square.h"
#include <vector>
class Board
{
private:
	std::vector<std::vector<Square*>> board;
public:
	Board();
	std::vector<std::vector<Square*>>  getBoard()
	Square duplicateBoard();
};

