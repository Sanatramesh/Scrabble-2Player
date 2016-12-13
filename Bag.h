// Bag.h

#ifndef BAG_H
#define BAG_H

const int bagSize = 100;

class Tile;
class Rack;
class Bag{
	int tilesLeft;
	Tile *temp;
	Tile *bag_tiles[bagSize];
public:
	Bag();
	~Bag();
	Tile* getRandTile();
	void Bag_Create();
	void show();
	void Reset();
	int tileNum() const;
};
#endif
