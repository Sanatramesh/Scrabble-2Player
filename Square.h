// Scrabble square class.

#ifndef SQUARE_H
#define SQUARE_H

class Tile;

class Square{
	int x;
	int y;
	int premium;
	int type;
	Tile *tptr;
public:
	Square(int i,int j,int p=1);
	void placeTile(Tile* t);
	bool check();
	int getPremium() const;
	Tile* getTile();
	void Used();
	void show();
	int getType() const;	
};
#endif
