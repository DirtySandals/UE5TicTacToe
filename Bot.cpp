#include "Bot.h"
using namespace std;
void Bot::makeMove(Board* board)
{
	int eval = minimax(board, board->isXMove, 0);
	board->MakeMove(moveIndex);
	return;
}

int Bot::minimax(Board* board, bool isMaximising, int depth)
{
	// Terminating condition
	char result = board->GameResult();
	switch (result) {
		case '-':
			break;
		case 'x':
			return 1 * (9 - depth);
		case 'o':
			return -1  * (9 - depth);
		case 0:
			return 0;
	}
	// If board is filled and no win, it's a draw
	if (board->moves == 9) {
		return 0;
	}

	int bestScore = isMaximising ? -200 : 200;

	for (int index = 0; index < 9; index++) {
		// Don't move on taken square
		if (board->grid[index] != '-') {
			continue;
		}
		// If MakeMove returns false dont explore
		if (!(board->MakeMove(index))) {
			continue;
		}

		// Recursively call subproblems (simulate more moves)
		int score = minimax(board, !isMaximising, depth + 1);

		if (isMaximising && score > bestScore) {
			bestScore = score;
			if (depth == 0) {
				moveIndex = index;
			}
		} else if (!isMaximising && score < bestScore) {
			bestScore = score;
			if (depth == 0) {
				moveIndex = index;
			}
		}

		board->UnmakeMove(index);
	}
	
	return bestScore;
}
