// Player.h
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

enum DIRECTION {HORIZONTAL=0, VERTICAL};
using std::string;

class Rack;
class Bag;
class Board;

class Player{
	int TotalScore;
	string Name;
	Bag *theBag;
	Board *theBoard;
	Rack *theRack;
public:
	static bool firsttrial;
	Player(string name, Bag* b, Board* bo);
	void show();
	bool Check(string& s,int index,DIRECTION d);
	int Check(int s,int index,DIRECTION d);
	bool addToBoard(string str, int firstIndex, DIRECTION d);
	int addToBoard(int no, int firstIndex, DIRECTION d);
	int RackSize() const;
	int Score() const ;
};
#endif
