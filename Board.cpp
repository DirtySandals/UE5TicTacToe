#include "Board.h"
using namespace std;

Board::Board()
{
	for (int i = 0; i < 9; i++) {
		grid[i] = '-';
	}
}

bool Board::MakeMove(int index) {
	if (gameEnded) return false;
	if (index < 0 || index > 8) return false;
	if (grid[index] != '-') return false;
	grid[index] = isXMove ? 'x' : 'o';

	moves++;
	isXMove = !isXMove;

	gameResult = GameResult();
	gameEnded = gameResult != '-';

	return true;
}

bool Board::UnmakeMove(int index) {
	if (index < 0 || index > 8) return false;
	if (grid[index] == '-') return false;

	grid[index] = '-';

	moves--;
	gameEnded = false;
	gameResult = '-';
	isXMove = !isXMove;

	return true;
}

bool Board::equals3(char a, char b, char c)
{
	return a == b && b == c && a != '-';
}

char Board::GameResult()
{
	if (gameEnded) return gameResult;
	// Checking rows
	for (int i = 0; i < 9; i += 3) {
		if (equals3(grid[i], grid[i + 1], grid[i + 2])) return grid[i];
	}
	// Checking columns
	for (int i = 0; i < 3; i++) {
		if (equals3(grid[i], grid[3 + i], grid[6 + i])) return grid[i];
	}
	// Checking Diagonals
	if (equals3(grid[0], grid[4], grid[8])) return grid[0];
	if (equals3(grid[2], grid[4], grid[6])) return grid[2];

	return moves == 9 ? '0' : '-';
}
