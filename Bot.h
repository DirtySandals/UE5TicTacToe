#ifndef BOT_H
#define BOT_H

class Bot {
private:

public:
	void makeMove(Board* board);
	int minimax(Board* board, bool isMaximising);
};

#endif