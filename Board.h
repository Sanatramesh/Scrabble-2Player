// Scrabble Board.h
#ifndef BOARD_H
#define BOARD_H

class Square;
class Tile;

const int num_Squares = 225;
const int boardSize = 15;

class Board{
	Square *board[num_Squares];
	int words;
public:
	Board();
	~Board();
	void show();
	bool checkSquare(int x, int y);
	int calculateScore(int x, int y, bool d, bool flag);
	bool placeTile(Tile *t,int pos);
	int getWords();
	
};

#endif
