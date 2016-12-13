all:
	 g++ Bag.cc -c -std=c++0x
	 g++ Board.cc -c -std=c++0x
	 g++ Square.cc -c -std=c++0x
	 g++ tile.cc -c -std=c++0x
	 g++ Rack.cc -c -std=c++0x
	 g++ Player.cc -c -std=c++0x
	 g++ Game.cc -c -std=c++0x
	 g++ test.cc -c -std=c++0x
	 g++ -std=c++0x test.o Bag.o Board.o Square.o tile.o Rack.o Player.o Game.o -o scrabble
clear:
	 rm scrabble
	 rm *.o
