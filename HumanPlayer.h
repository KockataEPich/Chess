#pragma once
#include "Player.h"
#include <utility>
class HumanPlayer : public Player
{
public:
	HumanPlayer();
	std::pair<char, int> getMove();
};

