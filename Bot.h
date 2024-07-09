#ifndef BOT_H
#define BOT_H
#include "Board.h"
#include <iostream>

class Bot {
private:
	int moveIndex = -1;
public:
	void makeMove(Board* board);
	int minimax(Board* board, bool isMaximising, int depth);
};

#endif