#pragma once
#include <string>
#include <vector>
class ChessPiece
{
protected:
	Square position;

public:
	virtual std::string getName() = 0;
	virtual Square getPosition() = 0;
	virtual std::vector<Square> getLegalMoves() = 0;
};

