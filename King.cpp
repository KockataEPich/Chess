#include "King.h"

King::King(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "King";
	this->position = position;
	this->owner = playerSide;
}

std::vector<std::shared_ptr<Square>>* King::getLegalMoves(Board* board, PlayerSide currentPlayerColor)
{
	std::vector<std::shared_ptr<Square>>* legalMoves = new std::vector<std::shared_ptr<Square>>();


	auto currentPosition = position.lock();

	if (currentPosition->getY() + 1 < 8) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX()][currentPosition->getY() + 1];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}

	if (currentPosition->getY() - 1 >= 0) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX()][currentPosition->getY() - 1];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}

	if (currentPosition->getX() + 1 < 8) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX() + 1][currentPosition->getY()];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}

	if (currentPosition->getX() - 1 >= 0) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX() - 1][currentPosition->getY()];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}


	for (int i = currentPosition->getX() + 1, j = currentPosition->getY() - 1; i < 8 && j >= 0; i++, j--)

	if (currentPosition->getX() + 1 < 8 && currentPosition->getY() - 1 >= 0) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX() + 1][currentPosition->getY() - 1];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}

	if (currentPosition->getX() - 1 >= 0 && currentPosition->getY() + 1 < 8) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX() - 1][currentPosition->getY() + 1];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}

	if (currentPosition->getX() - 1 >= 0 && currentPosition->getY() - 1 >= 0) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX() - 1][currentPosition->getY() - 1];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}

	if (currentPosition->getX() + 1 < 8 && currentPosition->getY() + 1 < 8) {
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX() + 1][currentPosition->getY() + 1];
		endSquare(newSquare, legalMoves, currentPlayerColor);
	}

	if (firstMove) {
		int rightMoves = 0;
		for (int i = currentPosition->getY() + 1; i < 7; i++)
		{
			std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX()][i];

			if (newSquare->getPiece() == nullptr)
				rightMoves++;
		}

		if (rightMoves == 2 && board->getBoard()[currentPosition->getX()][7]->getPiece() != nullptr && 
										board->getBoard()[currentPosition->getX()][7]->getPiece()->hasMoved() == false)
			legalMoves->push_back(board->getBoard()[currentPosition->getX()][6]);

		int leftMoves = 0;
		for (int i = currentPosition->getY() - 1; i >= 0; i--)
		{
			std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX()][i];

			if (newSquare->getPiece() == nullptr)
				leftMoves++;
		}

		if (leftMoves == 3 && board->getBoard()[currentPosition->getX()][0]->getPiece() != nullptr &&
			board->getBoard()[currentPosition->getX()][0]->getPiece()->hasMoved() == false)
			legalMoves->push_back(board->getBoard()[currentPosition->getX()][1]);


	}

	return legalMoves;
}