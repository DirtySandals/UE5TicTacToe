#ifndef BOARD_H
#define BOARD_H

class Board {
	friend class Bot;
private:
	char grid[9];
	bool isXMove = true;
	bool gameEnded = false;
	char gameResult = '-';
	unsigned short int moves = 0;
public:
	Board();
	bool MakeMove(int index);
	bool UnmakeMove(int index);
	bool equals3(char a, char b, char c);
	char GameResult();
};

#endif