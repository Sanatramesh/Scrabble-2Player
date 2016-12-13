#include <iostream>
using namespace std;

#include "Game.h"
#include <cstdlib>

int main(int argc,char* argv[])
{
	int num;
	Game game(1);
	if (argc!=3){
		cout<<"Invalid command"<<endl;
		cout<<"Usage : "<<"./scrabble <input_filename> <output_filename>"<<endl;
		return 0;
	}
	game.startTest(argv[1],argv[2]);
	return 0;
}
