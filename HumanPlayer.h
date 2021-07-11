#pragma once
#include "Player.h"
class HumanPlayer : public Player
{

public:
	HumanPlayer(PlayerSide color);
	Move getMove(Board& board);
};

