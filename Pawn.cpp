#include "Pawn.h"

Pawn::Pawn(std::shared_ptr<Square> position, PlayerSide playerSide)
{
	this->name = "Pawn";
	this->position = position;
	this->owner = playerSide;
}

std::vector<std::shared_ptr<Square>>* Pawn::getLegalMoves(Board* board, PlayerSide currentPlayerColor)
{
	std::vector<std::shared_ptr<Square>>* legalMoves = new std::vector<std::shared_ptr<Square>>();
	
	auto sqrOff = [](int xOff, int yOff, std::weak_ptr<Square> position, Board* board)
	{
		return board->getBoard()[position.lock()->getX() + xOff][position.lock()->getY() + yOff];
	};

	if (currentPlayerColor == PlayerSide::WHITE) {
		if (position.lock()->getX() - 1 >= 0) {
			if (sqrOff(-1, 0, position, board)->getPiece() == nullptr)
				legalMoves->push_back(sqrOff(-1, 0, position, board));

			if (position.lock()->getY() + 1 < 8)
				if(sqrOff(-1, 1, position, board)->getPiece() != nullptr && 
					sqrOff(-1, 1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor)
					legalMoves->push_back(sqrOff(-1, 1, position, board));

			if (position.lock()->getY() - 1 >= 0)
				if (sqrOff(-1, -1, position, board)->getPiece() != nullptr && 
					sqrOff(-1, -1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor)
					legalMoves->push_back(sqrOff(-1, -1, position, board));
		}
	}
	else
	{
		if (position.lock()->getX() + 1 < 8) {
			if (sqrOff(1, 0, position, board)->getPiece() == nullptr)
				legalMoves->push_back(sqrOff(1, 0, position, board));

			if (position.lock()->getY() + 1 < 8)
				if (sqrOff(1, 1, position, board)->getPiece() != nullptr &&
					sqrOff(1, 1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor)
					legalMoves->push_back(sqrOff(1, 1, position, board));

			if (position.lock()->getY() - 1 >= 0)
				if (sqrOff(1, -1, position, board)->getPiece() != nullptr &&
					sqrOff(1, -1, position, board)->getPiece()->getOwnerOfChessPiece() != currentPlayerColor)
					legalMoves->push_back(sqrOff(1, -1, position, board));
		}

	}

	return legalMoves;
}

