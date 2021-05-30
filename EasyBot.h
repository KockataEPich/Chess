#pragma once
#include "Player.h"


class EasyBot : public Player
{
public:
	EasyBot(PlayerSide color);
	Move getMove(Board *board);

};

