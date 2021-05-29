#pragma once
#include "Player.h"
#include <utility>
class HumanPlayer : public Player
{
public:
	HumanPlayer();
	Move getMove(Board board);
};

