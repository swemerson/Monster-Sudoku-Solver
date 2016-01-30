#ifndef SUDOKUBOARDGENERATOR_H
#define SUDOKUBOARDGENERATOR_H

#include <random>
#include <stdlib.h>
#include <ctime>
#include <stdexcept>

#include "SudokuFile.h"

using namespace std;

class SudokuBoardGenerator
{
private:
	bool checkConstraints(int row, int col, int value, SudokuFile * sf, int ** board);

public:
	SudokuFile * generateBoard(int N, int p, int q, int numAssignments);
	SudokuFile * generateBoard(int N, int p, int q, int numAssignments, long timeout);
	bool checkRow(int row, int value, int N, int ** board);
	bool checkColumn(int column, int value, int N, int ** board);
	bool checkBox(int row, int column, int value, int p, int q, int ** board);
};

#endif