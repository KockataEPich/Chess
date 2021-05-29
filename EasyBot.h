#pragma once
#include "Player.h"


class EasyBot : public Player
{
public:
	EasyBot();
	Move getMove(Board *board);

};

