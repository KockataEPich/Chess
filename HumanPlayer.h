#pragma once
#include "Player.h"
class HumanPlayer : public Player
{
private:
	std::weak_ptr<Square> firstClickedSquare;
	std::weak_ptr<Square> secondClickedSquare;
public:
	std::shared_ptr<Square> getFirstClicked();
	void setFirstClicked(std::shared_ptr<Square> square);

	std::shared_ptr<Square> getSecondClickedSquare();
	void setSecondClickedSquare(std::shared_ptr<Square> sqaure);

	void clearPoints();

	HumanPlayer(PlayerSide color);
	Move* getMove(Board *board);
};

