#ifndef BOT_H
#define BOT_H

class Bot {
private:

public:
	void makeMove(Board board, char grid[9]);
	int minimax(char grid[9], bool isMaximising);
};

#endif