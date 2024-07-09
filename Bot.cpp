#include "Bot.h"

void Bot::makeMove(Board* board)
{
	int moveIndex = minimax(board, board->isXMove);

	board->MakeMove(moveIndex);

	return;
}

int Bot::minimax(Board* board, bool isMaximising)
{
	// Terminating condition
	char result = board->GetResult();
	switch (result) {
		case 'x':
			return 1;
		case 'o':
			return -1;
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
		bestScore = isMaximising ? max(bestScore, minimax(board, !isMaximising)) : min(bestScore, minimax(board, !isMaximising));
		board->UnmakeMove(index);
	}

	return bestScore;
}
