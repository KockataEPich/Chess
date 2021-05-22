#pragma once
#include <utility>
class Bot
{
private:
	virtual std::pair<char, int> generateBestMove() = 0;

};

