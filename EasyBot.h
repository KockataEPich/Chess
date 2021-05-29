#pragma once
#include "Player.h"

#include<utility>
class EasyBot : public Player
{
public:
	EasyBot();
	Move getMove(Board board);

};

