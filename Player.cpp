#include "Player.h"

PlayerSide Player::getColor()						{ return color;							}
shr_sqr Player::getFirstClicked()					{ return firstClickedSquare.lock();		}
void Player::setFirstClicked(shr_sqr square)		{ firstClickedSquare = square;			}
shr_sqr Player::getSecondClickedSquare()			{ return secondClickedSquare.lock();	}
void Player::setSecondClickedSquare(shr_sqr square) { secondClickedSquare = square;			}

void Player::clearPoints(){
	firstClickedSquare = wk_sqr();
	secondClickedSquare = wk_sqr();
}