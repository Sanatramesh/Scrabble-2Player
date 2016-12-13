// scrabble - bag.cc
#include <iostream>
#include "tile.h"
#include "Rack.h"
#include "Bag.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Bag::Bag(){
	tilesLeft = 99;
	bag_tiles[0] = nullptr;
	Bag_Create();
	srand(time(nullptr));
}
Bag::~Bag(){
	for (int i=25;i>-1;i--)
		delete bag_tiles[i];
	delete temp;
}
Tile* Bag::getRandTile(){ // returns a tile at random.
	int index = 0;
	if (tilesLeft == 0){
		tilesLeft = -1;
		return bag_tiles[0];
	}
	if (tilesLeft<0){
		return nullptr;
	}
	index = rand()%(tilesLeft+1);
	if (index != tilesLeft)
	{
		temp = bag_tiles[index];
		bag_tiles[index] = bag_tiles[tilesLeft];
		bag_tiles[tilesLeft] = temp;
	}
	tilesLeft--;
	return bag_tiles[tilesLeft+1];
}

void Bag::Bag_Create(){ // creates a bag of tiles with letters and their points.
	int Cost[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
	int freq[]={9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
	int count = 0;
	if (bag_tiles[0] == nullptr){
		for (char i = 'A'; i<='Z';i++)
			for (int j=0;j<freq[i-65];j++){	
				bag_tiles[count] = new Tile(i, 1);
				count++;
			}
		bag_tiles[98] = new Tile(' ', 1);
		bag_tiles[99] = new Tile(' ', 1);
	}
	else{
		for (char i = 'A'; i<= 'Z';i++)
			for (int j=0;j<freq[i-65];j++){	
				bag_tiles[count]->set(i,Cost[i-65]);
				count++;
			}
		bag_tiles[98]->set(' ', 0);
		bag_tiles[99]->set(' ', 0);
	}
}
void Bag::Reset(){
	Bag_Create();
}
void Bag::show(){// displayes all the tiles left in the bag.
	for(int i=0;i<=tilesLeft;i++){
		if (i+1 < 10)
			cout << "Tile 0"<<i+1;
		else
			cout << "Tile "<<i+1;
		bag_tiles[i]->show();
		cout<<endl;
	}
}
int Bag::tileNum() const { // returns no of tiles left.
	return tilesLeft+1;
}
