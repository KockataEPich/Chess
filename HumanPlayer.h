#pragma once
#include "Player.h"
class HumanPlayer : public Player
{
public:
	HumanPlayer();
	Move getMove(Board *board);
};

