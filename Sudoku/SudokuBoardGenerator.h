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
	

public:
	static bool checkConstraints(int row, int col, int value, SudokuFile * sf, int ** board);
	static SudokuFile * generateBoard(int N, int p, int q, int numAssignments);
	static SudokuFile * generateBoard(int N, int p, int q, int numAssignments, long timeout);
	static bool checkRow(int row, int value, int N, int ** board);
	static bool checkColumn(int column, int value, int N, int ** board);
	static bool checkBox(int row, int column, int value, int p, int q, int ** board);
};

#endif