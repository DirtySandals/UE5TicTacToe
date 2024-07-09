#ifndef BOARD_H
#define BOARD_H
#include <iostream>

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
	bool isEnded() { return gameEnded; }
	char winner() { return gameResult; }
	unsigned short int getmoves() { return moves; }
	void printBoard() {
		for (int i = 0; i < 9; i += 3) {
			std::cout << grid[i] << " | " << grid[i + 1] << " | " << grid[i + 2] << std::endl;
		}
		std::cout << "---------------" << std::endl;
	}
};

#endif