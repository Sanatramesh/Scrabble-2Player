// Scrabble tile.cc

#include <iostream>
using namespace std;
#include "Square.h"
#include "tile.h"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

void Tile::linkSquare(Square* sq){
	square = sq;
}
Tile::Tile(char c, int cost){
		ch = c;
		points = cost;
		square = nullptr;
}
void Tile::show(){
	cout<<" ";
	if (square !=nullptr)
	switch (square->getType()){
		case 1:cout<<BOLDRED;break;
		case 2:cout<<BOLDBLUE;break;
		case 3:cout<<BOLDGREEN;break;
		case 4:cout<<BOLDYELLOW;break;
	}
	cout<<ch;
	cout<<RESET;
}
void Tile::set(char c, int cost){
	ch = c;
	points = cost;
}
int Tile::getPoints() const { 
	return points;
}
char Tile::getChar() const {
	return ch;
}
