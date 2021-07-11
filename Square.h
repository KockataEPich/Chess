#pragma once
#include "ChessPiece.h"
#include <memory>


class ChessPiece;
typedef std::shared_ptr<ChessPiece> shr_piece;

class Square {
private:
	shr_piece chessPiece = nullptr;
	int x;
	int y;

public:
	Square(int x, int y, shr_piece chessPiece);
	~Square();
	shr_piece getPiece();
	int getX();
	int getY();
	void setPiece(shr_piece chessPiece);
	void removePiece();
};

