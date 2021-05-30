#pragma once
#include <string>
#include <vector>
#include "Square.h"
#include "Board.h"
#include <memory>
#include "PlayerEnum.h"

class Board;
class Square;

class ChessPiece
{
protected:
	std::weak_ptr<Square> position;
	std::string name;
	PlayerSide owner;

public:
	std::string getName();
	std::shared_ptr<Square> getPosition();
	void setPosition(std::shared_ptr<Square> newPosition);

	bool endSquare(std::shared_ptr<Square> newSquare, std::vector<std::shared_ptr<Square>>* legalMoves, 
		PlayerSide currentPlayerColor);

	PlayerSide getOwnerOfChessPiece();

	void addHorizontal(std::vector<std::shared_ptr<Square>>* legalMoves, Board* board, PlayerSide currentPlayerColor);
	void addVertical(std::vector<std::shared_ptr<Square>>* legalMoves, Board* board, PlayerSide currentPlayerColor);
	void addSideways(std::vector<std::shared_ptr<Square>>* legalMoves, Board* board, PlayerSide currentPlayerColor);

	virtual std::vector<std::shared_ptr<Square>>* getLegalMoves(Board* board, PlayerSide currentPlayerColor) = 0;
};

