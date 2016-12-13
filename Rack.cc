// rack.cc
#include <iostream>
#include <cstring>
#include <string>
#include "Rack.h"
#include "tile.h"
#include "Bag.h"

using namespace std;

Rack::Rack() {
	tilesUsed = rackSize;
	for(int i=0;i<rackSize;i++)
		tiles[i] = nullptr;
}

Rack::Rack(Bag& bag) {
	tilesUsed = 0;
	for(int i=0;i<rackSize;i++)
		tiles[i] = bag.getRandTile();
}
void Rack::updateRack(Bag& bag){ // updates rack with tiles from bag
	int count =0;
	for(int i=rackSize - tilesUsed;i<rackSize;i++){
		tiles[i] = bag.getRandTile();
		if (tiles[i]==nullptr){
			count ++;
		}
	}
	if (count == 0)
		tilesUsed = 0;
	else{
		tilesUsed = count;
	}
}
bool Rack::rack_empty(){ // checks for empty rack.
	if (rackSize - tilesUsed == 0){
		return 0;
	}
	return 1;
	
}
bool Rack::Check(string& s){ // checks for the letter in rack.
	char t;
	int i,j, flag = 1,left = tilesUsed;
	string r;
	for (i = 0;i<rackSize - left;i++)
		r += tiles[i]->getChar();
	for (char &c : s){
		c = toupper(c);
		for (j = 0;j<rackSize - left;j++)
		{
			if (r[j] == c)
			{
				if (j != rackSize-left-1){
					t = r[j];
					r[j] = r[rackSize-left-1];
					r[rackSize-left-1] = t;
				}
				break;
			}
		}
		if (j>= rackSize - left){
			return 0;
		}
		else
			left++;
	}
	return 1;
}
Tile* Rack::getTile(char c){
	c = toupper(c);
	for (int i = 0;i<rackSize - tilesUsed;i++)
		if (tiles[i]->getChar() == c){
			if (i != rackSize-tilesUsed-1){
				temp = tiles[i];
				tiles[i] = tiles[rackSize- tilesUsed-1];
				tiles[rackSize- tilesUsed-1] = temp;
			}
			tilesUsed++;
			return tiles[rackSize-tilesUsed];
		}
	return nullptr;
}
Tile* Rack::getTile(int no){
	int i=no;
		if (i != rackSize-tilesUsed-1){
			temp = tiles[i];
			tiles[i] = tiles[rackSize- tilesUsed-1];
			tiles[rackSize- tilesUsed-1] = temp;
		}
		tilesUsed++;
		return tiles[rackSize-tilesUsed];
	
	return nullptr;
}
void Rack::show(){ // Displays rack.
	for (int i=0;i<rackSize;i++){
		cout<<"|";
		if (tiles[i]!=nullptr)
			tiles[i]->show();
		cout<<" |";
	}
	cout<<endl;
}
int Rack::rack_size() const{ // returns no of tiles left in rack.
	return rackSize - tilesUsed;
}
int Rack::numTiles() const{ // returns no of tiles used in rack.
	return tilesUsed;
}
void Rack::addTile(int i,Tile* tile){
	tiles[i] = tile;
}
Rack::~Rack(){
	delete temp;
	for (int i=rackSize -1;i>-1;i--)
		delete tiles[i];
}
