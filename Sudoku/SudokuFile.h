#ifndef SUDOKUFILE_H
#define SUDOKUFILE_H

#include <iostream>
#include <string>

#include "Odometer.h"

using namespace std;

class SudokuFile
{
	/**
	* p, q, N represent the dimensions of a game board.
	* Assuming a game board has values p = 3, q = 4, N = 12,
	* an empty board will look like this.
	*
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* ---------------------------------------
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* ---------------------------------------
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* ---------------------------------------
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	* [] [] [] [] | [] [] [] [] | [] [] [] []
	*
	*/
private:
	int p;//number of rows in a block && number of blocks per row
	int q;//number of columns in a block && number of blocks per column
	int N;//number of cells in a block && edge length of a NxN puzzle
	int ** board;

	SudokuFile() {}
	~SudokuFile();
	void setP(int p);
	void setQ(int q);
	void setN(int n);
	

public:
	SudokuFile(int N, int p, int q, int ** board);
	SudokuFile(int N, int p, int q);
	static int ** allocateBoard(int N);
	int getP() const;
	int getQ() const;
	int getN() const;
	int ** getBoard() const;
	string toString() const;
	void setBoard(int ** board);
};

#endif