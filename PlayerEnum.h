#pragma once

class PlayerSide{
public:
	enum Color {
		WHITE,
		BLACK
	};

	PlayerSide(Color color) {
		this->color = color;
	}

	PlayerSide() {};
private:
	Color color;

public:
	bool operator ==(PlayerSide side) { return color == side.color; }
	bool operator !=(PlayerSide side) { return color != side.color; }
	PlayerSide getOpposite()  { return (color == PlayerSide::WHITE) ? PlayerSide::BLACK : PlayerSide::WHITE;}
	std::string toString()    { return (color == PlayerSide::WHITE) ? "White" : "Black"; }

};

