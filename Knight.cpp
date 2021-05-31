#include "Knight.h"

Knight::Knight(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "Knight";
	this->position = position;
	this->owner = playerSide;
}

std::vector<std::shared_ptr<Square>>* Knight::getLegalMoves(Board* board, PlayerSide currentPlayerColor)
{
	std::vector<std::shared_ptr<Square>>* legalMoves = new std::vector<std::shared_ptr<Square>>();

	auto sqrOff = [](int xOff, int yOff, std::weak_ptr<Square> position, Board* board)
	{
		return board->getBoard()[position.lock()->getX() + xOff][position.lock()->getY() + yOff];
	};

	////////////// UP
	if (position.lock()->getX() + 2 < 8) {
		if (position.lock()->getY() + 1 < 8) {

			if (sqrOff(2, 1, position, board)->getPiece() == nullptr || 
				sqrOff(2, 1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(2, 1, position, board));
			}
			
		}
			 
		if (position.lock()->getY() - 1 >= 0) {

			if (sqrOff(2, -1, position, board)->getPiece() == nullptr ||
				sqrOff(2, -1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(2, -1, position, board));
			}

		}
	}
	
	////////////// DOWN

	if (position.lock()->getX() - 2 >= 0) {
		if (position.lock()->getY() + 1 < 8) {

			if (sqrOff(-2, 1, position, board)->getPiece() == nullptr ||
				sqrOff(-2, 1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(-2, 1, position, board));
			}

		}

		if (position.lock()->getY() - 1 >= 0) {

			if (sqrOff(-2, -1, position, board)->getPiece() == nullptr ||
				sqrOff(-2, -1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(-2, -1, position, board));
			}

		}
	}

	////////// LEFT
	if (position.lock()->getY() - 2 >= 0) {
		if (position.lock()->getX() + 1 < 8) {

			if (sqrOff(1, -2, position, board)->getPiece() == nullptr ||
				sqrOff(1, -2, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(1, -2, position, board));
			}

		}

		if (position.lock()->getX() - 1 >= 0) {

			if (sqrOff(-1, -2, position, board)->getPiece() == nullptr ||
				sqrOff(-1, -2, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(-1, -2, position, board));
			}

		}
	}


	/////////// RIGHT 

	if (position.lock()->getY() + 2 < 8) {
		if (position.lock()->getX() + 1 < 8) {

			if (sqrOff(1, 2, position, board)->getPiece() == nullptr ||
				sqrOff(1, 2, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(1, 2, position, board));
			}

		}

		if (position.lock()->getX() - 1 >= 0) {

			if (sqrOff(-1, 2, position, board)->getPiece() == nullptr ||
				sqrOff(-1, 2, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor) {
				legalMoves->push_back(sqrOff(-1, 2, position, board));
			}

		}
	}

	return legalMoves;
}
