//Scrabble tile.h
#ifndef TILE_H
#define TILE_H

class Square;

class Tile{
	char ch;
	int points;
	Square *square;
public:
	Tile(char c, int cost);
	void linkSquare(Square* s);
	void show();
	void set(char c, int cost);
	int getPoints() const;
	char getChar() const;
};
#endif
