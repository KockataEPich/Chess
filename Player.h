#pragma once
#include <utility>
class Player
{
public:
	virtual std::pair<char, int> getMove() = 0;

private:
	//virtual Piece pieces*;
};

