// Scrabble - Player.cc
// Contains Rack, Bag, Board and TotalPoints.
#include <iostream>
#include <vector>
#include <string>
#include "Rack.h"
#include "Board.h"
#include "Bag.h"
#include "Player.h"
#include "tile.h"

using namespace std;

bool Player::firsttrial = 0;

Player::Player(string name, Bag* b, Board* bo){
	Player::firsttrial = 0;
	Name = name;
	theBag = b;
	theRack = new Rack(*b);
	theBoard = bo;
	TotalScore = 0;
}
void Player::show(){ // Displays players details.
	cout<<"Player Name = "<<Name<<endl;
	cout<<"Player Score = "<<TotalScore<<endl;
	theRack->show();
}
int Player::Check(int no,int index, DIRECTION d){// Checks for invalid move
	int i=index/15, j = index%15,k=0,check=0, mid = 0;
	//cout<<no<<" Rack="<<theRack->rack_size()<<endl;
	if (theRack->rack_size()==0)
		return 5;
	if (theRack->rack_size() < no)
		return 6;
	
	if (Player::firsttrial)
	{
		check = !(theBoard->checkSquare(i-1,j));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j-1));
		if (check == 0)
			check = !(theBoard->checkSquare(i+1,j));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j+1));

	}
	
	for(int k=0;k<no;k++) {
		if (j>14 || i>14) {
			//cerr<<"Index Out Of Bound"<<endl;
			return 3;
		}
		
		else if (i==7 && j==7)
			mid = 1;
		while(Player::firsttrial && !theBoard->checkSquare(i,j)){
				if (i==7 && j==7)
					mid = 1;
				check = 1;
				if (!d)
					j++;
				else
					i++;
				if (j>14 || i>14) {
					return 3;
				}
				
			}
		if (check == 0)	
			check = !(theBoard->checkSquare(i-1,j));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j-1));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j+1));
		if (check == 0)
			check = !(theBoard->checkSquare(i+1,j));
		if (!d)
			j++;
		else
			i++;
		}
	if (!Player::firsttrial && !mid){
		//cout<<"One tile should be on the mid Square"<<endl;
		return 1;
	}
	if (Player::firsttrial && !check){
		return 1;
	}
	return 0;
}

int Player::RackSize() const{
	return 7- theRack->numTiles();
}
int Player::addToBoard(int no, int firstIndex, DIRECTION d){ //checks for the validity and performs moves
	int k = 0,check = 0, i = firstIndex/15, j = firstIndex%15;
	TotalScore = 0;
	int error = Check(no,firstIndex,d);
	if (error!=0){
		return error;
	}
	Tile *t;
	
	for (int k=0;k<no;k++) {
		t = theRack->getTile(0);
		if (t!= nullptr){
			while (!theBoard->placeTile(t, i*15 + j)){
				if (!d)
					j++;
				else
					i++;
				check = 1;
			}
		}
		else
			return 0;
		TotalScore += theBoard->calculateScore(i,j,d,0);
		if (!d)
			j++;
		else
			i++;
	}
	TotalScore += theBoard->calculateScore(firstIndex/15, firstIndex%15, !d,1);
	Player::firsttrial = 1;
	theRack->updateRack(*theBag);
	return 0;
}
bool Player::Check(string& s,int index, DIRECTION d){ // Checks for invalid move
	int i=index/15-1, j = index%15-1,k=0,check=0, mid = 0;
	if (!theRack->Check(s))
		return 0;
	if (Player::firsttrial)
	{
		check = !(theBoard->checkSquare(i-1,j));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j-1));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j+1));
		if (check == 0)
			check = !(theBoard->checkSquare(i+1,j-1));
	}
	
	while ( s[k]!='\0') {
		if (j>14 || i>14) {
			cerr<<"Index Out Of Bound"<<endl;
			return 0;
		}
		else if (i==7 && j==7)
			mid = 1;
		while(Player::firsttrial && !theBoard->checkSquare(i,j)){
				if (j>14 || i>14) {
					cerr<<"Index Out Of Bound"<<endl;
					return 0;
				}
				else if (i==7 && j==7)
					mid = 1;
				check = 1;
				if (!d)
					j++;
				else
					i++;
			}
		if (j>14 || i>14) {
			cerr<<"Index Out Of Bound"<<endl;
			return 0;
		}
		if (check == 0)	
			check = !(theBoard->checkSquare(i-1,j));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j-1));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j+1));
		if (check == 0)
			check = !(theBoard->checkSquare(i+1,j-1));
		if (!d)
			j++;
		else
			i++;
		k++;
	}
	if (Player::firsttrial && check == 0){
		
		check = !(theBoard->checkSquare(i-1,j));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j-1));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j+1));
		if (check == 0)
			check = !(theBoard->checkSquare(i+1,j-1));
		if (check == 0)
			check = !(theBoard->checkSquare(i,j));
	}
	if (!Player::firsttrial && !mid){
		cout<<"One tile should be on the mid Square"<<endl;
		return 0;
	}
	if (!Player::firsttrial)
		return 1;
	else if (!check)
		cout<<"The string is not linked"<<endl;
		
	return check;
}
bool Player::addToBoard(string str, int firstIndex, DIRECTION d){ //checks for the validity and performs moves
	int k = 0,check = 0, i = firstIndex/15-1, j = firstIndex%15-1;
	
	if (!Check(str,firstIndex,d)){
		return 0;
	}
	Tile *t;
	while ( str[k]!='\0') {
		t = theRack->getTile(str[k]);
		if (t!= nullptr){
			while (!theBoard->placeTile(t, i*15 + j)){
				if (!d)
					j++;
				else
					i++;
				check = 1;
			}
		}
		else
			return 0;
		TotalScore += theBoard->calculateScore(i,j,d,0);
		if (!d)
			j++;
		else
			i++;
		k++;
	}
	TotalScore += theBoard->calculateScore(firstIndex/15-1, firstIndex%15-1, !d,1);
	
	Player::firsttrial = 1;
	theRack->updateRack(*theBag);
	return 1;
}	

int Player::Score() const {
	return TotalScore;
}
