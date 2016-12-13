// Scrabble - board.cc
#include <iostream>
#include "Board.h"
#include "Square.h"
#include "tile.h"

using namespace std;

int Board::getWords(){
	int no = words;
	words = 0;
	return no;
}
Board::Board(){ // creates a board with all types of square.
	words = 0;
	for (int row=0;row<boardSize;row++)
		for(int col=0;col<boardSize;col++)
			if((row==0 && col==0)||(row==0 && col==7)||(row==0 && col==14)||(row==7 && col==0)||(row==7 && col==14)||(row==14 && col==0)||(row==14 && col==7)||(row==14 && col==14))
			{
				board[row*boardSize+col]=new Square(row,col,1);
			}
			else if((row==col || row+col==14)&&(row!=0 && row!=5 && row!=6 && row!=8 && row!=9 && row!=14))
			{
				board[row*boardSize+col]=new Square(row,col,2);
			}
			else if((row==0 && col==3)||(row==0 && col==11)||(row==2 && col==8)||(row==2 && col==6)||(row==3 && col==0)||(row==3 && col==7)||(row==3 && col==14)||(row==6 && (col==2 || col == 12))||(row==6 && col==6)||(row==6 && col==8)||(row==7 && col==3)||(row==7 && col==11)||(row==8 && col==2)|(row==8 && col==6)||(row==8 && col==8)||(row==8 && col==12)||(row==11 && col==0)||(row==11 && col==7)||(row==11 && col==14)||(row==12 && col==6)||(row==12 && col==8)||(row==14 && col==3)||(row==14 && col==11))
			{
				board[row*boardSize+col]=new Square(row,col,4);
			}
			else if((row==1 && col==5)||(row==1 && col==9)||(row==5 && col==1)||(row==5 && col==5)||(row==5 && col==9)||(row==5 && col==13)||(row==9 && col==1)||(row==9 && (col==5 || col==9))||(row==9 && col==13)||(row==13 && col==5)||(row==13 && col==9))
			{
				board[row*boardSize+col]=new Square(row,col,3);
			}
			else
			{
				board[row*boardSize+col]=new Square(row,col,0);
			}
}

void Board::show(){ // displayes all the squares on the board and their contents.
	cout<<"\t\t\t\t\t\t\tThe Board"<<endl;
	cout<<endl;
	int i,j;
	for (j=0;j<119;j++)
		cout<<"-";
	cout<<endl;
	for (i=0;i<boardSize;i++)
	{
		for (j=0;j<boardSize;j++)
			board[i*boardSize + j]->show();
		cout<<endl;
		for (j=0;j<119;j++)
			cout<<"-";
		cout<<endl;
	}
}
Board::~Board(){
	for (int i=num_Squares-1;i>-1;i--)
		delete board[i];
}
bool Board::checkSquare(int x, int y){ // checks the square if it contains a tile
	if (x<0 || y<0 || x>14 || y>14)
			return 1;
	return board[x*15+y]->check();
}
int Board::calculateScore(int x, int y, bool d, bool flag){ // Extracts words and calculates scores.
	short score=0,i=x,j=y,prem = 0, mult = 1;
	string word="";
	while(1)
	{
		if (i<0 || j<0)
			break;
		if (board[i*15+j]->check())
			break;
		prem = board[i*15+j]->getPremium();
		score += board[i*15+j]->getTile()->getPoints();
		switch (prem){
			case 0:;break;
			case 1:mult *= 3;break;
			case 2:mult *= 2;break;
			case 3:score += board[i*15+j]->getTile()->getPoints()*2;break;
			case 4:score += board[i*15+j]->getTile()->getPoints();break;
		}
		word = board[i*15+j]->getTile()->getChar() + word;
		if (flag)
			board[i*15+j]->Used();
		if (!d)
			i--;
		else
			j--;
	}
	if (!d)
		i=x+1;
	else
		j=y+1;
	while(1)
	{
		if (i>14 || j>14)
			break;
		if (board[i*15+j]->check())
			break;
		prem = board[i*15+j]->getPremium();
		score += board[i*15+j]->getTile()->getPoints();
		switch (prem){
			case 0:break;
			case 1:mult *= 3;break;
			case 2:mult *= 2;break;
			case 3:score += board[i*15+j]->getTile()->getPoints()*2;break;
			case 4:score += board[i*15+j]->getTile()->getPoints();break;
		}
		word += board[i*15+j]->getTile()->getChar();
		if (flag)
			board[i*15+j]->Used();
		if (!d)
			i++;
		else
			j++;
	}
	if (word.size() == 1)
		return 0;
	words++;
	return score*mult;
}
bool Board::placeTile(Tile *t, int pos){ // places a tile on the board.
	if (t !=nullptr){
		if (board[pos]->check()){
			board[pos]->placeTile(t);
			t->linkSquare(board[pos]);
		}
		else{
			return 0;
		}
	}
	return 1;
}
