#include "Square.h"
#include <iostream>
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

using namespace std;

void Square::placeTile(Tile* t){
	 tptr = t;
}

Square::Square(int i,int j,int p){
	x =i;
	y=j;
	premium = p;
	type = p;
	tptr = nullptr;
}
bool Square::check(){ 
	if (tptr == nullptr)
		return 1;
	else
		return 0;
}
int Square::getPremium() const{
	return premium;
}
Tile* Square::getTile(){
	return tptr;
}

void Square::Used(){
	premium = 0;
}

void Square::show(){ // displays contents of a square.
	
	if (tptr == nullptr){
		switch (premium){
			case 1:cout<<BOLDRED;break;
			case 2:cout<<BOLDBLUE;break;
			case 3:cout<<BOLDGREEN;break;
			case 4:cout<<BOLDYELLOW;break;
		}
		if (x <9)
			cout<<"0"<<x+1;
		else
			cout<<x+1;
		cout<<",";
		if (y <9)
			cout<<"0"<<y+1;
		else
			cout<<y+1;
		cout<<RESET;
		cout<<" | ";
	}
	else{
		cout<<" ";
		tptr->show();
		cout<<"   | ";
	}
}
int Square::getType() const{
	return type;
}
