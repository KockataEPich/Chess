#pragma once
#include "Square.h"
#include "Move.h"
#include "Player.h"
#include "PlayerEnum.h"
#include <vector>
#include <memory>

class Square;
class Move;

class Board
{
private:
	std::vector<std::vector<std::shared_ptr<Square>>> board;
	std::vector<std::shared_ptr<ChessPiece>> whitePieces;
	std::vector<std::shared_ptr<ChessPiece>> blackPieces;
	bool gameIsOver = false;
	std::string winner;

public:
	Board();
	~Board();
	Board(std::vector<std::vector<std::shared_ptr<Square>>> board,
		std::vector<std::shared_ptr<ChessPiece>> whitePieces,
		std::vector<std::shared_ptr<ChessPiece>> blackPieces);

	std::vector<std::vector<std::shared_ptr<Square>>>  getBoard();
	Board* duplicateBoard();

	bool isOver();

	std::vector<std::shared_ptr<ChessPiece>> getPieceList(PlayerSide side);
	void makeMove(Move* move);

	std::string getWinner();

	void eraseElement(std::shared_ptr<ChessPiece> pieceToDelete, PlayerSide color);
	void checkPieceAndDeleteIfNecessary(std::shared_ptr<ChessPiece> newPiece, Move* move);
	void checkForCastleUp(Move* move, std::shared_ptr<Square> newSquare);
	void handlePiecePromotion(std::shared_ptr<Square> newSquare, Move* move);
};
