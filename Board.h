#pragma once
#include "Square.h"
#include "Move.h"
#include "Player.h"
#include <vector>
#include <memory>

class Square;
class Move;
class Player;

class Board
{
private:
	std::vector<std::vector<std::shared_ptr<Square>>> board;
	Player player1;
	Player player2;
public:
	Board() {};
	Board(Player* player1, Player* player2);
	~Board();
	Board(std::vector<std::vector<std::shared_ptr<Square>>> board);
	std::vector<std::vector<std::shared_ptr<Square>>>  getBoard();
	Board* duplicateBoard();
	void makeMove(Move move);
};

