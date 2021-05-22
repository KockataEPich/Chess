#pragma once
#include "Bot.h"
#include "Player.h"
#include<utility>
class EasyBot : public Player, public Bot
{
public:
	EasyBot();
	std::pair<char, int> getMove();
private:
	std::pair<char, int> generateBestMove();

};

