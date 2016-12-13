// Scrabble - Game.cc
#include <iostream>
#include <cstdlib>
#include "Bag.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Game::Game(int numplayer){
	numPlayer = numplayer;
	Init();
}
void Game::Init(){ // Initialises the Game with players.
	string name;
	bag = new Bag();
	board = new Board();
	numPlayer = numPlayer;
	for (int i=0;i<numPlayer;i++){
		players.push_back(new Player("sanat", bag, board));
	}
}

void Game::startTest(char *input, char*output){ // takes input from user and performs action
	ifstream in;
	ofstream fp;
	in.open(input);
	fp.open(output);
	int check, pos= 0,turn =0,size = 0, player = 0;
	int score, total=0; 
	char dir;
	while (1){
		if (in.eof())
			break;
		
		in>>turn>>pos>>size>>dir;
		if (in.eof())
			break;
		
		if (pos<0 || pos>224){
			check = 2;
			goto checkst;
		}
		
		if (size == 0){
			check = 6;
			goto checkst;
		}
		if (dir=='V')
			check = players[0]->addToBoard(size,pos,VERTICAL);
		else if (dir=='H')
			check = players[0]->addToBoard(size,pos,HORIZONTAL);
		else
			check = 7;
		checkst:
		switch(check){
			case 0: score = players[0]->Score();
					total +=score;
					fp<<turn<<" "<<board->getWords()<<" "<<players[0]->Score()<<endl;break;
			case 1:fp<<turn<<" "<<"INVALID-TILE-POSITION"<<endl;break;
			case 2:fp<<turn<<" "<<"INVALID-SQUARE-INDEX"<<endl;break;
			case 3:fp<<turn<<" "<<"NO-ROOM-FOR-TILES"<<endl;break;
			case 4:fp<<turn<<" "<<"NO-ROOM-FOR-TILES"<<endl;break;
			case 5:fp<<turn<<" "<<"NO-MORE-TILES"<<endl;break;
			case 6:fp<<turn<<" "<<"LETTER-NOT-IN-RACK"<<endl;break;
			case 7:fp<<turn<<" "<<"INVALID-DIRECTION"<<endl;break;
		}
		//board->show();
	}
	fp<<"tiles_left="<<bag->tileNum()<<endl;
	fp<<"total_points="<<total<<endl;
	in.close();
	fp.close();
}
void Game::start(){ // takes input from user and performs action live.
	int check, row, col, player = 0;
	string name;
	char dir;
	while (1){
		board->show();
		for (auto &p: players)
			p->show();
		cout<<"Player "<<player+1<<":Enter word, position and direction:";
		cin>>name>>row>>col>>dir;
			system("clear");
		if (dir=='v')
			check = players[player]->addToBoard(name,row*15 + col,VERTICAL);
		else if (dir=='h')
			check = players[player]->addToBoard(name,row*15 + col,HORIZONTAL);
		else
			cout<<"Invalid Input:"<<dir<<endl;
		if (check)	
			player++;
		player %= numPlayer;
	}
}
Game::~Game(){
	delete bag;
	delete board;
	for (auto &p : players)
		delete p;
}
