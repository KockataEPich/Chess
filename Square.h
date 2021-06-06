#pragma once
#include "ChessPiece.h"
#include <memory>


class ChessPiece;


class Square
{
private:
	std::shared_ptr<ChessPiece> chessPiece = nullptr;

	int x;
	int y;

public:
	Square(int x, int y, std::shared_ptr<ChessPiece> chessPiece);
	~Square();
	std::shared_ptr<ChessPiece> getPiece();
	int getX();
	int getY();
	void setPiece(std::shared_ptr<ChessPiece> chessPiece);
	void removePiece();
};

typedef std::vector<std::shared_ptr<Square>> sqr_vec;
typedef std::shared_ptr<ChessPiece> shr_piece;
typedef std::shared_ptr<Square> shr_sqr;
typedef std::weak_ptr<Square> wk_sqr;