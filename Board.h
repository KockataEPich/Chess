#pragma once
#include "Square.h"
#include "Move.h"
#include "Player.h"
#include "PlayerEnum.h"
#include <vector>
#include <memory>

class Square;
class Move;

typedef std::shared_ptr<Square> shr_sqr;
typedef std::vector<shr_sqr> sqr_vec;
typedef std::vector<sqr_vec*> board_vec;

typedef std::vector<std::shared_ptr<ChessPiece>> piece_vec;
typedef std::shared_ptr<ChessPiece> shr_piece;


class Board{
private:
	board_vec* board;
	piece_vec* whitePieces;
	piece_vec* blackPieces;
	bool gameIsOver = false;
	std::string winner;

public:
	Board();
	Board(board_vec* board);
	~Board();

	board_vec*  getBoard();
	std::string getWinner();
	bool isOver();
	piece_vec* getPieceList(PlayerSide side);
	shr_sqr operator()(int x, int y);
	
	void makeMove(Move* move);

	void removePiece(shr_piece pieceToDelete);
	void checkPieceAndDeleteIfNecessary(shr_piece newPiece, Move* move);
	void checkForCastleUp(Move* move, shr_sqr newSquare);
	void handlePiecePromotion(shr_sqr newSquare, Move* move);
};
