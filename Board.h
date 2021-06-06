#pragma once
#include "Square.h"
#include "Move.h"
#include "Player.h"
#include "PlayerEnum.h"
#include <vector>
#include <memory>

class Square;
class Move;

typedef std::vector<std::vector<std::shared_ptr<Square>>> board_vec;
typedef std::vector<std::shared_ptr<ChessPiece>> piece_vec;
typedef std::shared_ptr<ChessPiece> shr_piece;
typedef std::shared_ptr<Square> shr_sqr;
typedef std::vector <std::shared_ptr<Square>> sqr_vec;

class Board
{
private:
	board_vec board;
	piece_vec whitePieces;
	piece_vec blackPieces;
	bool gameIsOver = false;
	std::string winner;

public:
	Board();
	Board(board_vec board);
	~Board();

	board_vec  getBoard();
	std::string getWinner();
	bool isOver();
	piece_vec getPieceList(PlayerSide side);
	
	void makeMove(Move* move);

	void eraseElement(shr_piece pieceToDelete, PlayerSide color);
	void checkPieceAndDeleteIfNecessary(shr_piece newPiece, Move* move);
	void checkForCastleUp(Move* move, shr_sqr newSquare);
	void handlePiecePromotion(shr_sqr newSquare, Move* move);
};
