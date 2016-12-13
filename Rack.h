// Rack.h
#include <string>
using namespace std;

#ifndef RACK_H
#define RACK_H

class Tile;
class Bag;

const int rackSize = 7;
class Rack{
	int tilesUsed;
	Tile *tiles[rackSize];
	Tile *temp;
public:
	Rack();
	Rack(Bag& bag);
	Tile* getTile(char c);
	Tile* getTile(int no);
	int numTiles() const;
	int rack_size() const;
	void updateRack(Bag& bag);
	void addTile(int i,Tile* tile);
	void show();
	bool Check(string& s);
	bool rack_empty();
	~Rack();
};
#endif
