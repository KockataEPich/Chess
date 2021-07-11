#pragma once
#include <memory>
#include "ChessPiece.h"
#include "Square.h"
#include "PlayerEnum.h"

class ChessPiece;
class Square;

class Move
{
private:
	bool castle_up = false;
	std::weak_ptr<Square> oldLocation;
	std::weak_ptr<Square> newLocation;
	std::shared_ptr<ChessPiece> captured_piece;
	PlayerSide side;
public:
	Move() {};
	Move(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation, PlayerSide side);
	~Move();
	std::shared_ptr<Square> getOldLocation();
	std::shared_ptr<Square> getNewLocation();
	PlayerSide getSide();
	void set_captured_piece(std::shared_ptr<ChessPiece> piece);
	std::shared_ptr<ChessPiece> get_captured_piece();
	void setCastleUpTrue();
	bool isCastleUp();
};

