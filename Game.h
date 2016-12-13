// Scrabble - Game.h
#ifndef GAME_H
#define GAME_H
#include <vector>

class Bag;
class Player;
class Board;

class Game{
	Bag* bag;
	Board* board;
	std::vector<Player*> players;
	int numPlayer;
public:
	Game(int numplayer);
	void start();
	void startTest(char *in,char *out);
	void Init();
	~Game();
};
#endif
